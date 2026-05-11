# TILING

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

#define WIDTH 50
#define HEIGHT 20
#define GENERATIONS 100
#define TILE_WIDTH 5
#define TILE_HEIGHT 2

int grid[HEIGHT][WIDTH];
int newGrid[HEIGHT][WIDTH];

void display(int gen) {
    printf("\033[2J\033[H");
    printf("Generation: %d\n", gen);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[y][x] ? '#' : '.');
        }
        printf("\n");
    }
}

int countNeighbors(int x, int y) {
    int count = 0;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;

            int nx = (x + dx + WIDTH) % WIDTH;
            int ny = (y + dy + HEIGHT) % HEIGHT;

            count += grid[ny][nx];
        }
    }

    return count;
}

void processTile(int startY, int endY, int startX, int endX) {
    for (int y = startY; y < endY; y++) {
        for (int x = startX; x < endX; x++) {
            int neighbors = countNeighbors(x, y);
            int alive = grid[y][x];

            if (alive && (neighbors == 2 || neighbors == 3)) {
                newGrid[y][x] = 1;
            } else if (!alive && neighbors == 3) {
                newGrid[y][x] = 1;
            } else {
                newGrid[y][x] = 0;
            }
        }
    }
}

void nextGeneration(int startRow, int localRows) {
    for (int ty = startRow; ty < startRow + localRows; ty += TILE_HEIGHT) {
        for (int tx = 0; tx < WIDTH; tx += TILE_WIDTH) {
            int endY = (ty + TILE_HEIGHT > startRow + localRows) ? startRow + localRows : ty + TILE_HEIGHT;
            int endX = (tx + TILE_WIDTH > WIDTH) ? WIDTH : tx + TILE_WIDTH;
            
            processTile(ty, endY, tx, endX);
        }
    }
}

void initializeRandom() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = rand() % 2;
        }
    }
}

int main(int argc, char **argv) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Initialize grid on rank 0 only
    if (rank == 0) {
        initializeRandom();
    }

    // Broadcast entire grid to all processes
    MPI_Bcast(&grid[0][0], WIDTH * HEIGHT, MPI_INT, 0, MPI_COMM_WORLD);

    // Calculate equal rows per process
    int localRows = HEIGHT / size;
    int startRow = rank * localRows;

    for (int gen = 0; gen < GENERATIONS; gen++) {
        // Display on rank 0 only
        if (rank == 0) {
            display(gen);
        }

        // Each process computes its assigned rows using tiles
        nextGeneration(startRow, localRows);

        // Gather all results with equal data from each process
        MPI_Allgather(&newGrid[startRow][0], localRows * WIDTH, MPI_INT,
                      &grid[0][0], localRows * WIDTH, MPI_INT, MPI_COMM_WORLD);

        if (rank == 0) {
            usleep(100000);
        }
    }

    MPI_Finalize();
    return 0;
}


# NO TILING

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

#define WIDTH 50
#define HEIGHT 20
#define GENERATIONS 100

int grid[HEIGHT][WIDTH];
int newGrid[HEIGHT][WIDTH];

void display(int gen) {
    printf("\033[2J\033[H");
    printf("Generation: %d\n", gen);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[y][x] ? '#' : '.');
        }
        printf("\n");
    }
}

int countNeighbors(int x, int y) {
    int count = 0;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;

            int nx = (x + dx + WIDTH) % WIDTH;
            int ny = (y + dy + HEIGHT) % HEIGHT;

            count += grid[ny][nx];
        }
    }

    return count;
}

void nextGeneration(int startRow, int localRows) {
    for (int y = startRow; y < startRow + localRows; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = countNeighbors(x, y);
            int alive = grid[y][x];

            if (alive && (neighbors == 2 || neighbors == 3)) {
                newGrid[y][x] = 1;
            } else if (!alive && neighbors == 3) {
                newGrid[y][x] = 1;
            } else {
                newGrid[y][x] = 0;
            }
        }
    }
}

void initializeRandom() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = rand() % 2;
        }
    }
}

int main(int argc, char **argv) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Initialize grid on rank 0 only
    if (rank == 0) {
        initializeRandom();
    }

    // Broadcast entire grid to all processes
    MPI_Bcast(&grid[0][0], WIDTH * HEIGHT, MPI_INT, 0, MPI_COMM_WORLD);

    // Calculate equal rows per process
    int localRows = HEIGHT / size;
    int startRow = rank * localRows;

    for (int gen = 0; gen < GENERATIONS; gen++) {
        // Display on rank 0 only
        if (rank == 0) {
            display(gen);
        }

        // Each process computes its assigned rows
        nextGeneration(startRow, localRows);

        // Gather all results with equal data from each process
        MPI_Allgather(&newGrid[startRow][0], localRows * WIDTH, MPI_INT,
                      &grid[0][0], localRows * WIDTH, MPI_INT, MPI_COMM_WORLD);

        if (rank == 0) {
            usleep(100000);
        }
    }

    MPI_Finalize();
    return 0;
}
