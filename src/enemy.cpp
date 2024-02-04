#include "../include/enemy.hpp"
// row random
int enemy::enemyStartpos()
{
    int random = 0;
    while (random < 100 || random > x_SIZE - 100)
    {
        random = rand() % x_SIZE;
    }
    return random;
}
void enemy::enemy_setSpeed()
{
    enemySpeed += 0.3;
}
float enemy::enemy_getSpeed()
{
    return enemySpeed;
}
void enemy::enemy_speed_reset()
{
    enemySpeed = 1;
}
