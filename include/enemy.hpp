#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <time.h>
#include <iomanip>
#define x_SIZE 800
#define y_SIZE 600

class enemy
{
public:
    int enemyStartpos();
    void enemy_setSpeed();
    float enemy_getSpeed();
    void enemy_speed_reset();

private:
    float enemySpeed = 1;
};