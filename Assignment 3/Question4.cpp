#include<iostream>
#include <cmath>
using namespace std;

class Drone{
protected:
    float Latitude,Longitude,altitude,speed;
public:
    Drone(float Latitude,float Longitude,float altitude,float speed):Latitude(Latitude),Longitude(Longitude),altitude(altitude),speed(speed){}

    float adjustAltitude(float alt){
        altitude = alt;
        return altitude;
    }

    float setSpeed(int spd){
        speed = spd;
        return speed;
    }
};  

class Flyable {
public:
    virtual void takeoff() = 0;

    virtual void land() = 0;

    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable {
    float cameraResolution, maxFlightTime;
public:
    ReconDrone(float lat, float lon, float alt, float spd, float camRes, float maxTime)
        : Drone(lat, lon, alt, spd), cameraResolution(camRes), maxFlightTime(maxTime) {}
    
    void takeoff() override {
        cout << "Taking off" <<endl;
    }

    void land() override {
        cout << "Landing" <<endl;
    }

    void navigateTo(float lat, float lon, float alt){
        float x = (lat - Longitude) * cos((Latitude + lat) / 2);
        float y = lat - Latitude;
        float distance = sqrt(x * x + y * y) * 111.0f;
        float time = distance / speed;

        cout << "Estimated time to destination: " << time << " hours" <<endl;

        Latitude = lat;
        Longitude = lon;
        altitude = alt;
    }

    void scanArea(float radius){
        // Simulate scanning the environment
        int objectsDetected = rand() % 10; // Random number of objects detected
        cout << "Detected " << objectsDetected << " objects:" << endl;

        for (int i = 0; i < objectsDetected; ++i) {
            float objectLat = Latitude + static_cast<float>(rand() % 100) / 1000.0f;
            float objectLon = Longitude + static_cast<float>(rand() % 100) / 1000.0f;
            cout << "Object " << i + 1 << " at (" << objectLat << ", " << objectLon << ")" <<endl;
        }
    }
};

int main(){
    ReconDrone drone(0, 0, 100, 50, 4, 8);
    drone.takeoff();
    drone.navigateTo(1, 1, 150);
    drone.scanArea(500);
    drone.land();
}
