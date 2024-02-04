#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <time.h>
#include <iomanip>
#define x_SIZE 800
#define y_SIZE 600

class shoot
{
public:
    //int shootStartpos();
    void shoot_setSpeed();
    float shoot_getSpeed();
    void shoot_speed_reset();

private:
    float shootSpeed = 1;
};