#include "../include/heli.hpp"
void heli::set_heliSpeed()
{
    heliSpeed += 1;
}
int heli::get_heliSpeed()
{
    return heliSpeed;
}
void heli::reset_heliSpeed()
{
    heliSpeed = 10;
}



