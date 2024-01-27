#pragma once
#include <SFML/Graphics.hpp>
#include "../include/enemy.hpp"
#include "../include/heli.hpp"

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
    //----------------- set sound -----------------
    sf::SoundBuffer back_sound;
    sf::SoundBuffer eat_sound;
    sf::SoundBuffer gameover_sound;
    //---------------------------------------------
    //------------------- set font ----------------
    sf::Font font;
    //---------------------------------------------

    //------------------ set photo ----------------
    sf::Texture texture;
    sf::Texture heli_image;
    sf::Texture enemy_image;
    sf::Texture enemy2_image;
    //---------------------------------------------

public:
    
    enemy enemy1;
    enemy enemy2;
    heli heli;
    void runGame(sf::RenderWindow &window);
};