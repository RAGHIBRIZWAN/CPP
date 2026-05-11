// TILING

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 5
#define HEIGHT 10
#define GENERATIONS 100
#define TILE_WIDTH 2
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

void nextGenerationTile(int startY, int endY, int startX, int endX) {
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

void nextGeneration() {
    for (int ty = 0; ty < HEIGHT; ty += TILE_HEIGHT) {
        for (int tx = 0; tx < WIDTH; tx += TILE_WIDTH) {
            int endY = (ty + TILE_HEIGHT > HEIGHT) ? HEIGHT : ty + TILE_HEIGHT;
            int endX = (tx + TILE_WIDTH > WIDTH) ? WIDTH : tx + TILE_WIDTH;
            
            nextGenerationTile(ty, endY, tx, endX);
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = newGrid[y][x];
        }
    }
}

void readGridFromCsv(const char *path) {
    FILE *file = fopen(path, "r");
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int value;
            fscanf(file, "%d", &value);
            grid[y][x] = (value > 0) ? 1 : 0;
        }
    }
    
    fclose(file);
}

int main(int argc, char **argv) {
    const char *path = (argc > 1) ? argv[1] : "file.csv";
    
    readGridFromCsv(path);

    for (int gen = 0; gen < GENERATIONS; gen++) {
        display(gen);
        nextGeneration();
        usleep(100000);
    }

    return 0;
}


// NO TILING

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void nextGeneration() {
    for (int y = 0; y < HEIGHT; y++) {
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
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = newGrid[y][x];
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

int main() {
    initializeRandom();
    
    for (int gen = 0; gen < GENERATIONS; gen++) {
        display(gen);
        nextGeneration();
        usleep(100000);
    }
    
    return 0;
}
