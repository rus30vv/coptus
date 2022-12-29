//proto code
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include<random>


//#include "Entity.h"

using namespace sf;
using namespace std;

enum state {MAIN_MENU, LEVEL_WORK, EXIT_APP};//add loader level

//struct Map_structure_s
//{
//    int size_x;
//    int size_y;
//    bool collide;
//    int size_tile;
//};
//class Map_structure
//{
//    int size_x;
//    int size_y;
//    bool collide;
//    int size_tile;
//    Map_structure()
//    {
//
//
//    }
//};


class Tile//Tile = enemy
//destructor...?
{
	//value
	public:
	Image tileimage;
	Texture tiletexture;
	Sprite tilesprite;


	float positionx,positiony;


	Tile(float positionx, float positiony)
	{

	if (!tileimage.loadFromFile("data/earth_tile_set.jpg")){

		cout<<" tile Imgage: not load !\n";
	}
	else {
        //tileimage.loadFromFile("data/earth_tile_set.jpg")
        cout<<" tile Imgage:true, use link!";

	}

	if (!tiletexture.loadFromImage(tileimage))
	{
		cout<<"not_LOAD_FROM_IMAGE\n";
	}


		tilesprite.setTexture(tiletexture);
		tilesprite.setTextureRect(IntRect(0, 80, 80, 80));
		//tilesprite.setScale(sf::Vector2f(2.f, 2.f));
		tilesprite.setPosition(positionx, positiony);


	};

	void update(){//float time
		if (Keyboard::isKeyPressed(Keyboard::W)) {
            //float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            //float g = r * 10.f;

            //tilesprite.setPosition(positionx = positionx + g, positiony = positionx - g);
        }
		/*
		if (Keyboard::isKeyPressed(Keyboard::A)) { tilesprite.setPosition(positionx = positionx + time, positiony = positionx + time);}
		if (Keyboard::isKeyPressed(Keyboard::D)) { tilesprite.setPosition(positionx = positionx + time, positiony = positionx + time);}
	    if (Keyboard::isKeyPressed(Keyboard::S)) { tilesprite.setPosition(positionx = positionx + time, positiony = positionx + time);}
	    if (Keyboard::isKeyPressed(Keyboard::E)) { tilesprite.setPosition(positionx = positionx + time, positiony = positionx + time);}
        */


	}

};

class Test_Tile//
{
    public:
	Texture tiletexture;
	Sprite tilesprite;
	float positionx,positiony;

	Test_Tile(float positionx, float positiony, Image &_tileimage)
	{

	    tiletexture.loadFromImage(_tileimage);
        tilesprite.setTexture(tiletexture);
		tilesprite.setTextureRect(IntRect(0, 80, 80, 80));
        tilesprite.setPosition(positionx, positiony);

	};

};



int main()
{

    //test-map-create

    //char* tileChar = "1111111111s1000000001s1000000001s1111100000s1111100000s1111111111s";

    //load tile set

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1360,760), "SF2-ML04 window COPTUS 0.0.1");

	//float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	Clock clock;

	//start init value
        //start load tile set.
            //world
        	Image _tileimage;
            _tileimage.loadFromFile("data/earth_tile_set.jpg");
            //actors


        //end load tile set.

//    int max_tile_rom = 19;

    float py,px;
    py = 0.f;
    px = 0.f;


    list <Tile*> list_enemy;
    list <Tile*>::iterator it;

    //end init value
    Test_Tile a(py, px, _tileimage);
//    for (auto j = 0; j != max_tile_rom; ++j)
//    {
//        cout <<"****new interation****"<<endl;
//        for (auto i= 0; i != max_tile_rom; ++i)
//        {
//                px = i * 80;
//                py = j * 80;
//                cout << i;
//                cout << ":";
//                cout << j <<endl;
//
//
//                list_enemy.push_back(new Tile(px, py));
//        }
//    }
 	window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {

		float time = clock.getElapsedTime().asMicroseconds();

		clock.restart();
		time = time / 800;

        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();

//        for (it = list_enemy.begin(); it != list_enemy.end(); it++){
//            (*it)->update();
//            window.draw((*it)->tilesprite);
//        };

        window.draw(a.tilesprite);

        window.display();
        window.setFramerateLimit(5);
        //window.close();//debugger automaitic get perfomance code (codeblocks).
    }
      return 0;
}
