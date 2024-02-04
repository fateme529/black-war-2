#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <time.h>
#include <iomanip>
#define x_SIZE 800
#define y_SIZE 600
class barrier 
{
public:
    int barrierStartpos();
    void barrier_setSpeed();
    float barrier_getSpeed();
    void barrier_speed_reset();

private:
    float barrierSpeed = 1;
};