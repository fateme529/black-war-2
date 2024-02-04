#include "../include/shoot.hpp"
// row random
// int enemy::enemyStartpos()
// {
//     int random = 0;
//     while (random < 50 || random > x_SIZE - 50)
//     {
//         random = rand() % x_SIZE;
//     }
//     return random;
// }
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