#include "../include/shoot.hpp"

void shoot::shoot_setSpeed()
{
    shootSpeed += 0.3;
}
float shoot::shoot_getSpeed()
{
    return shootSpeed;
}
void shoot::shoot_speed_reset()
{
    shootSpeed = 1;
}