#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>


using namespace sf;
using namespace std;

class Actor
//destructor...
{
	//value
	public:
	Image heroimage;
	Texture herotexture;
	Sprite herosprite;
	//value specific
	float positionx,positiony;

	int health, mana, bonusMana, bonusHealth, BonusForceAttack;
	float speed, bonusSpeed, speedAttack, bonusSpeedAttack;



	Actor(float positionx, float positiony)
	{
		//positionx = 300.f;positiony = 300.f;
	if (!heroimage.loadFromFile("Winged_Ape_Sprites.png"))
	{
		cout<<"not_Load_FILE_IMAGE\n";
	}

	if (!herotexture.loadFromImage(heroimage))
	{
		cout<<"not_LOAD_FROM_IMAGE\n";
	}


		herosprite.setTexture(herotexture);
		herosprite.setTextureRect(IntRect(0, 0, 60, 60));
		herosprite.setScale(sf::Vector2f(2.f, 2.f));
		herosprite.setPosition(positionx, positiony);

	}

	void update(float time){
		if (Keyboard::isKeyPressed(Keyboard::W)) { herosprite.setPosition(positionx = positionx + 0.3f, positiony = positionx + time);}
/*		if (Keyboard::isKeyPressed(Keyboard::A)) { herosprite.setPosition(positionx = positionx + time, positiony = positionx + time);}
		if (Keyboard::isKeyPressed(Keyboard::D)) { herosprite.setPosition(positionx = positionx + time, positiony = positionx + time);}
	    if (Keyboard::isKeyPressed(Keyboard::S)) { herosprite.setPosition(positionx = positionx + time, positiony = positionx + time);}
	    if (Keyboard::isKeyPressed(Keyboard::E)) { herosprite.setPosition(positionx = positionx + time, positiony = positionx + time);}*/

	};

};



int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(600,600), "SF2-ML04 window");

	//time
	Clock clock;
    Actor bm1(100, 100);

 	window.setVerticalSyncEnabled(true);

	//end testing
    while (window.isOpen())
    {

		float time = clock.getElapsedTime().asMicroseconds();

		clock.restart();
		time = time / 800;
        // Process events

        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
		//
        window.clear();
        bm1.update(time);
		window.draw(bm1.herosprite);
		//for draw

		//
        window.display();
        window.setFramerateLimit(30);
    }
      return 0;
}
