/*
Programmer: Raghib Rizwan Rabani
NU_ID: 23K-0012
Date: 20/3/2024
*/

#include<iostream>
#include <cstdlib>
using namespace std;

class Image{
    int width;
    int height;
    int* data;

public:
    Image(const int &width, const int &height,int* imgdata): width(width),height(height){
        data = new int[width * height];
        for (int i = 0; i < width * height; i++)
        {
            data[i] = imgdata[i];
        }
        
    }

    Image(Image &img){
        width = img.width;
        height = img.height;
        data = new int[width * height];
        for (int i = 0; i < width * height; i++)
        {
            data[i] = img.data[i];
        }
    }

    ~Image(){
        delete[] data;
    }

    void display(){
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << data[i * width + j] << " ";
            }
            cout << endl;
        }
    }

    void UpdateData(){
        for (int i = 0; i < width * height; ++i) {
            if (data[i] <= 0) {
                data[i] = rand() % 255 + 1; 
            }
        }
    }
};

int main(){
     int sampleData[] = {0, 2, 3, 4, 5, 6};
    Image original(2, 3, sampleData);

    Image copy(original);

    cout << "Original Image:" <<endl;
    original.display();
    cout <<endl;

    cout << "Copied Image:" <<endl;
    copy.display();
    cout <<endl;

    original.UpdateData();
    copy.UpdateData();

    cout << "Updated Original Image:" <<endl;
    original.display();
    cout <<endl;

    cout << "Updated Copied Image:" <<endl;
    copy.display();
    cout <<endl;

    return 0;
}
