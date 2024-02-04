#pragma once
#include <SFML/Graphics.hpp>
#include "../include/enemy.hpp"
#include "../include/heli.hpp"
#include "../include/shoot.hpp"
#include "../include/barrier.hpp"

#define row 12
#define column 9
#define x_SIZE 800
#define y_SIZE 600
#include <cctype>
#include <exception>
#include <string>
#include <array>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
#include <fstream>

#include <conio.h>

class Game
{
private:
    int score = 0;
    std::string set_score();
    void tryAgain(sf::RenderWindow &window, sf::Text point);
    //----------- handle screen window ------------
    bool enemy_2 = false;
    bool shoot_2 = false;
    bool barrier_2 = false;
    //----------------- set sound -----------------

    sf::SoundBuffer shoot_sound;
    sf::SoundBuffer gameover_sound;
    sf::SoundBuffer barrier_sound;
    sf::SoundBuffer gun_sound;
    //---------------------------------------------
    //------------------- set font ----------------
    sf::Font font;
    //---------------------------------------------

    //------------------ set photo ----------------
    sf::Texture texture;
    sf::Texture heli_image;
    sf::Texture shoot_image;
    sf::Texture shoot2_image;
    sf::Texture enemy_image;
    sf::Texture enemy2_image;
    sf::Texture barrier_image;
    sf::Texture barrier2_image;
    //---------------------------------------------

public:
    enemy enemy1;
    enemy enemy2;
    heli heli;
    shoot shoot1;
    shoot shoot2;
    barrier barrier1;
    barrier barrier2;
    void runGame(sf::RenderWindow &window);
};