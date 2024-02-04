#include "../include/barrier.hpp"

int barrier::barrierStartpos()
{
    int random = 0;
    while (random < 100 || random > x_SIZE - 100)
    {
        random = rand() % x_SIZE;
        random += 100;
    }
    return random;
}
void barrier::barrier_setSpeed()
{
    barrierSpeed += 0.3;
}
float barrier::barrier_getSpeed()
{
    return barrierSpeed;
}
void barrier::barrier_speed_reset()
{
    barrierSpeed = 1;
}