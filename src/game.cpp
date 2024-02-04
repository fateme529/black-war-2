#include "../include/game.hpp"
using namespace std;
#include <ctype.h>

void Game::runGame(sf::RenderWindow &window)
{
    srand((unsigned)time(NULL));
    window.setFramerateLimit(60);

    // --------------- handle input from file -----
    try
    {
        font.loadFromFile("font/font.ttf");

        shoot_sound.loadFromFile("sound/shoot_sound.wav");
        gameover_sound.loadFromFile("sound/gameover_sound.wav");
        barrier_sound.loadFromFile("sound/barrier_sound.wav");
        gun_sound.loadFromFile("sound/gun_sound.wav");
        texture.loadFromFile("picture/back.jpg");
        enemy_image.loadFromFile("picture/enemy.png");
        enemy2_image.loadFromFile("picture/enemy.png");
        heli_image.loadFromFile("picture/heli.png");
        shoot_image.loadFromFile("picture/shoot.png");
        shoot2_image.loadFromFile("picture/shoot.png");
        barrier_image.loadFromFile("picture/barrier.png");
        barrier2_image.loadFromFile("picture/barrier.png");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    //---------------------------------------------

    //------------ handle font --------------------

    sf::Text point("0", font);
    sf::Text text("Score : ", font);
    text.setPosition(sf::Vector2f(5, 5));
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Black);
    point.setPosition(sf::Vector2f(90, 5));
    point.setCharacterSize(25);
    point.setFillColor(sf::Color::Black);
    //---------------------------------------------

    // --------------- handle sound ---------------
    // sf::Sound back(back_sound);
    // back.setLoop(true);
    sf::Sound shoot(shoot_sound);
    sf::Sound gameover(gameover_sound);
    sf::Sound barrier(barrier_sound);
    sf::Sound gun(gun_sound);
    // back.play();
    //---------------------------------------------

    //----------------- handle photo --------------
    sf::RectangleShape rectengle(sf::Vector2f(800, 600)); // safhe
    sf::RectangleShape enemy_shape(sf::Vector2f(50, 50)); // enemy
    sf::RectangleShape enemy2_shape(sf::Vector2f(50, 50));
    sf::RectangleShape heli_shape(sf::Vector2f(130, 120));
    sf::RectangleShape shoot_shape(sf::Vector2f(30, 30));
    sf::RectangleShape shoot2_shape(sf::Vector2f(30, 30));
    sf::RectangleShape barrier_shape(sf::Vector2f(50, 50)); // enemy
    sf::RectangleShape barrier2_shape(sf::Vector2f(50, 50));

    //---------------------------------------------
    rectengle.setTexture(&texture);
    heli_shape.setTexture(&heli_image);
    enemy_shape.setTexture(&enemy_image);
    enemy2_shape.setTexture(&enemy2_image);
    shoot_shape.setTexture(&shoot_image);
    shoot2_shape.setTexture(&shoot2_image);
    barrier_shape.setTexture(&barrier_image);
    barrier2_shape.setTexture(&barrier2_image);
    //---------------------------------------------

    //---- set start positin for frog and snake ---
    heli_shape.setPosition(sf::Vector2f(x_SIZE - 800, y_SIZE - 400));
    enemy_shape.setPosition(sf::Vector2f(800, enemy1.enemyStartpos()));
    enemy2_shape.setPosition(sf::Vector2f(800, enemy1.enemyStartpos())); // felan dorest she
    shoot_shape.setPosition(sf::Vector2f(heli_shape.getPosition().x + 110, -50));
    shoot2_shape.setPosition(sf::Vector2f(heli_shape.getPosition().x + 110, -50));
    barrier_shape.setPosition(sf::Vector2f(800, enemy1.enemyStartpos()));
    barrier2_shape.setPosition(sf::Vector2f(800, enemy1.enemyStartpos())); // felan dorest she

    //---------------------------------------------

    while (window.isOpen())
    {

        //------ poll and check event from mouse and keyboard -------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
            {
                window.close();
            }
            // DOWN
            else if (event.key.code == sf::Keyboard::Key::D) // down
            {
                if (heli_shape.getPosition().y < 500)
                {
                    heli_shape.move(sf::Vector2f(0, heli.get_heliSpeed()));
                }

                //---------------------------------------------
            }
            // UP
            else if (event.key.code == sf::Keyboard::Key::A) // up
            {
                if (heli_shape.getPosition().y > -40)
                {
                    heli_shape.move(sf::Vector2f(0, -heli.get_heliSpeed()));
                }
            }
            // SHOOT
            else if (event.key.code == sf::Keyboard::Key::W) // shoot
            {
               
                if (shoot_shape.getPosition().y == -50)
                {
                     gun.play();
                    shoot_shape.setPosition(sf::Vector2f(heli_shape.getPosition().x + 110, heli_shape.getPosition().y + 60));
                    
                }
                else if (shoot2_shape.getPosition().y == -50 && shoot_shape.getPosition().x > 600)
                {
                    gun.play();
                    shoot2_shape.setPosition(sf::Vector2f(heli_shape.getPosition().x + 110, heli_shape.getPosition().y + 60));
                    shoot_2 = true;
                }
            }
        }

        
        //--------- left to right shoot from line  ---------------
        shoot_shape.move(sf::Vector2f(+shoot1.shoot_getSpeed(), 0));
        // ---------------------------------------------

        if (shoot_2 = true)
        {
            shoot2_shape.move(sf::Vector2f(+shoot1.shoot_getSpeed(), 0));
        }
        if (enemy_shape.getPosition().x < 200)
        {
            enemy_2 = true;
        }
        if (enemy_2)
        {
            //--------- right to left enemy2 from line  ---------------
            enemy2_shape.move(sf::Vector2f(-enemy1.enemy_getSpeed(), 0));
        }

        if (barrier_shape.getPosition().x < 200)
        {
            barrier_2 = true;
        }
        if (barrier_2)
        {
            //--------- right to left enemy2 from line  ---------------
            barrier2_shape.move(sf::Vector2f(-barrier1.barrier_getSpeed(), 0));
        }

        //--------- right to left enemy1 from line  ---------------
        enemy_shape.move(sf::Vector2f(-enemy1.enemy_getSpeed(), 0));

        //--------- right to left barrier1 from line  ---------------
        barrier_shape.move(sf::Vector2f(-barrier1.barrier_getSpeed(), 0));

        //------ check hit between heli and enemy1------>gameover
        if (enemy_shape.getGlobalBounds().intersects(heli_shape.getGlobalBounds()))
        {

            gameover.play(); // sound game over
            enemy_shape.setPosition(sf::Vector2f(enemy1.enemyStartpos(), -50));
            tryAgain(window, point);
        }
        //------ check hit between heli and enemy2------>gameover
        if (enemy2_shape.getGlobalBounds().intersects(heli_shape.getGlobalBounds()))
        {
            gameover.play(); // sound game over
            enemy2_shape.setPosition(sf::Vector2f(enemy1.enemyStartpos(), -50));
            tryAgain(window, point);
        }
        //------ check hit between heli and barrier1------>gameover
        if (barrier_shape.getGlobalBounds().intersects(heli_shape.getGlobalBounds()))
        {

            gameover.play(); // sound game over
            barrier_shape.setPosition(sf::Vector2f(barrier1.barrierStartpos(), -50));
            tryAgain(window, point);
        }
        //------ check hit between heli and barrier2------>gameover
        if (barrier2_shape.getGlobalBounds().intersects(heli_shape.getGlobalBounds()))
        {
            gameover.play(); // sound game over
            barrier2_shape.setPosition(sf::Vector2f(barrier1.barrierStartpos(), -50));
            tryAgain(window, point);
        }
        //---------------------------------------------
        //------ check hit between shoot1 and enemy1------>score
        if (shoot_shape.getGlobalBounds().intersects(enemy_shape.getGlobalBounds()))
        {
            shoot.play();
            enemy_shape.setPosition(sf::Vector2f(800, enemy1.enemyStartpos()));
            shoot_shape.setPosition(sf::Vector2f(-50, -50));
             enemy1.enemy_setSpeed();
            //  ---- update player point-----
            score++;
            point.setString(set_score());
            // -----------------------------
             heli.set_heliSpeed();
             barrier1.barrier_setSpeed();
             shoot1.shoot_setSpeed();
        }
        else if (shoot_shape.getGlobalBounds().intersects(enemy2_shape.getGlobalBounds()))
        {
            shoot.play();
            enemy2_shape.setPosition(sf::Vector2f(800, enemy2.enemyStartpos()));
            shoot_shape.setPosition(sf::Vector2f(-50, -50));
             enemy2.enemy_setSpeed();
            // ---- update player point-----
            score++;
            point.setString(set_score());
            // -----------------------------
             heli.set_heliSpeed();
             barrier2.barrier_setSpeed();
             shoot2.shoot_setSpeed();
        }
        //------ check hit between shoot2 and enemy2------>score
        if (shoot2_shape.getGlobalBounds().intersects(enemy_shape.getGlobalBounds()))
        {
            shoot.play();
            enemy_shape.setPosition(sf::Vector2f(800, enemy1.enemyStartpos()));
            shoot2_shape.setPosition(sf::Vector2f(-50, -50));
            // enemy1.enemy_setSpeed();
            // ---- update player point-----
            score++;
            point.setString(set_score());
            // -----------------------------
            // heli.set_heliSpeed();
        }
        else if (shoot2_shape.getGlobalBounds().intersects(enemy2_shape.getGlobalBounds()))
        {
            shoot.play();
            enemy2_shape.setPosition(sf::Vector2f(800, enemy2.enemyStartpos()));
            shoot2_shape.setPosition(sf::Vector2f(-50, -50));
            // enemy2.enemy_setSpeed();
            //  ---- update player point-----
            score++;
            point.setString(set_score());
            // -----------------------------
            // heli.set_heliSpeed();
        }

        //------ check hit between shoot1 and barrier1------>hide shoot
        if (shoot_shape.getGlobalBounds().intersects(barrier_shape.getGlobalBounds()))
        {
            barrier.play();
            shoot_shape.setPosition(sf::Vector2f(-50, -50));
        }
        else if (shoot_shape.getGlobalBounds().intersects(barrier2_shape.getGlobalBounds()))
        {
            barrier.play();
            shoot2_shape.setPosition(sf::Vector2f(-50, -50));
        }
        //------ check hit between shoot2 and barrier2------>score
        if (shoot2_shape.getGlobalBounds().intersects(barrier_shape.getGlobalBounds()))
        {
            barrier.play();
            shoot_shape.setPosition(sf::Vector2f(-50, -50));
        }
        else if (shoot2_shape.getGlobalBounds().intersects(barrier2_shape.getGlobalBounds()))
        {
            barrier.play();
            shoot2_shape.setPosition(sf::Vector2f(-50, -50));
        }
        //------ check hit between enemy and floor -----
        if (enemy_shape.getPosition().x < 10)
        {
            enemy_shape.setPosition(sf::Vector2f(800, enemy1.enemyStartpos())); // vaghti  be mar bokhore ghorbaghe az bin mire
                                                                                // enemy1.enemy_setSpeed();
                                                                                // heli.set_heliSpeed();
        }
        if (enemy2_shape.getPosition().x < 10)
        {

            enemy2_shape.setPosition(sf::Vector2f(800, enemy1.enemyStartpos()));

            heli.set_heliSpeed();
        }

        //------ check hit between shoot and floor -----
        if (shoot_shape.getPosition().x > 790)
        {
            shoot_shape.setPosition(sf::Vector2f(heli_shape.getPosition().x + 110, -50)); // vaghti  be mar bokhore ghorbaghe az bin mire
            shoot1.shoot_setSpeed();
        }
        if (shoot2_shape.getPosition().x > 790)
        {

            shoot2_shape.setPosition(sf::Vector2f(heli_shape.getPosition().x + 110, -50));
        }
        //------ check hit between barrier and floor -----
        if (barrier_shape.getPosition().x < 10)
        {
            barrier_shape.setPosition(sf::Vector2f(800, barrier1.barrierStartpos())); // vaghti  be mar bokhore ghorbaghe az bin mire
        }
        if (barrier2_shape.getPosition().x < 10)
        {

            barrier2_shape.setPosition(sf::Vector2f(800, barrier1.barrierStartpos()));
        }

        //----------- handle rendering ----------------
        window.clear();
        window.draw(rectengle);
        window.draw(shoot_shape);
        window.draw(shoot2_shape);
        window.draw(barrier_shape);
        window.draw(barrier2_shape);
        window.draw(enemy_shape);
        window.draw(enemy2_shape);
        window.draw(heli_shape);
        window.draw(point);
        window.draw(text);
        window.display();
        //---------------------------------------------
    }
    //---------------------------------------------
}
// --------------------------------------------------------------------------------------------------
string Game::set_score()
{

    stringstream temp;
    temp << score;
    string point;
    temp >> point;
    return point;
}
void Game::tryAgain(sf::RenderWindow &window, sf::Text point)
{
    // ----------- write score in file ---------
    std::ofstream myFile("record_status.txt", ios::app);
    myFile << set_score() << std::endl;
    myFile.close();
    //------------------------------------------

    // ----------------- set photo -----------
    sf::Texture back_blur;
    sf::Texture tryAgain_icon;
    sf::Texture exit_icon;
    // -----------------------------------------

    // ----------- handle input ----------------
    try
    {
        font.loadFromFile("font/font.ttf");
        back_blur.loadFromFile("picture/back_blur.png");
        tryAgain_icon.loadFromFile("picture/tryagain.png");
        exit_icon.loadFromFile("picture/exit_icon.png");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    // -----------------------------------------

    // ---------- photo to shape ---------------

    sf::RectangleShape back_blur_shape(sf::Vector2f(x_SIZE, y_SIZE));
    sf::RectangleShape tryAgainIcon_shape(sf::Vector2f(200, 100));
    sf::RectangleShape exitIcon_shape(sf::Vector2f(100, 50));

    back_blur_shape.setTexture(&back_blur);
    tryAgainIcon_shape.setTexture(&tryAgain_icon);
    exitIcon_shape.setTexture(&exit_icon);
    // -----------------------------------------

    // ----- handel text and set pos shape  ----

    sf::Text score_text("your score is : ", font);
    sf::Text record_text("high score is : ", font);
    sf::Text High_Score("High_score", font);
    High_Score.setPosition(sf::Vector2f(610, 220));
    High_Score.setCharacterSize(15);
    High_Score.setFillColor(sf::Color::Black);

    record_text.setPosition(sf::Vector2f(500, 220));
    score_text.setPosition(sf::Vector2f(250, 200));
    record_text.setCharacterSize(15);
    record_text.setFillColor(sf::Color::Black);
    point.setPosition(sf::Vector2f(450, 205));
    point.setFillColor(sf::Color::White);
    tryAgainIcon_shape.setPosition(sf::Vector2f(300, 280));
    exitIcon_shape.setPosition(sf::Vector2f(350, 400));
    // -----------------------------------------

    // -------- read high score from file ------
    int high_score = 0;
    fstream my_file;
    my_file.open("record_status.txt", ios::in);
    if (!my_file)
    {
        cout << "No such file";
    }
    else
    {
        string s;
        int str = 0;

        while (getline(my_file, s))
        {
            str = stoi(s);
            if (my_file.eof())
            {
                break;
            }
            if (str > high_score)
            {
                high_score = str;
            }
        }
        stringstream temp;
        temp << high_score;
        string High_score;
        temp >> High_score;
        High_Score.setString(High_score);
    }
    my_file.close();

    // -----------------------------------------

    while (window.isOpen())
    {
        sf ::Event event;
        sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
        if (tryAgainIcon_shape.getGlobalBounds().contains(mouse))
        {
            score = 0;
            enemy1.enemy_speed_reset();
            shoot1.shoot_speed_reset();
            shoot2.shoot_speed_reset();
            heli.reset_heliSpeed();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                runGame(window);
            }
        }
        else if (exitIcon_shape.getGlobalBounds().contains(mouse))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                window.close();
            }
        }
        // ----------------- handle rendering ------------
        window.clear();
        window.draw(back_blur_shape);
        window.draw(score_text);
        window.draw(record_text);
        window.draw(tryAgainIcon_shape);
        window.draw(exitIcon_shape);
        window.draw(point);
        window.draw(High_Score);
        window.display();
        // -----------------------------------------------
    }
}