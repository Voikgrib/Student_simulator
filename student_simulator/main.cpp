//
//	This is my super game!
//
//	Author: Vladimir Gribanov
//
//	Implement isPressed!!!!
//
//	version 0.0.0.2
//
//  0.0.0.2 added test shit & character class & isPressed class & stats

#define TRY( _command_ )											\
			if(! _command_ )										\
			{														\
				printf("Error in ");								\
				printf(#_command_);									\
				printf("!\n");										\
				exit(0);											\
			}														\

// Library declaration

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

// Global constants

sf::Clock MainClock;
sf::RenderWindow *MainWindow;

// Custom libs

#include "resourses/lib/isPressed.hpp"
#include "resourses/lib/stats.hpp"
#include "resourses/lib/character.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Student simulator pre-pre-pre-alpha 0.0.0.1", sf::Style::Fullscreen);
	MainWindow = &window;
	sf::Texture backgroundTexture;
	//sf::Texture characterTexture; //
	sf::Sprite backgroundSprite;
	//sf::Sprite characterSprite; //
	sf::Vector2u sizeOfScreen;
	sf::Vector2u sizeOfBackground;
	sf::Vector2f vectorOfScale;
	

	TRY(backgroundTexture.loadFromFile("resourses/images/concept_room.png"));
	//TRY(characterTexture.loadFromFile("resourses/images/character_beta.png")); //
	backgroundSprite.setTexture(backgroundTexture);
	//characterSprite.setTexture(characterTexture); //
	sizeOfScreen = window.getSize();
	sizeOfBackground = backgroundTexture.getSize();	
	// s = w / b
	vectorOfScale.x = ((float) sizeOfScreen.x) / ((float) sizeOfBackground.x);
	vectorOfScale.y = ((float) sizeOfScreen.y) / ((float) sizeOfBackground.y);
	backgroundSprite.setScale (vectorOfScale);
	character mainHero("resourses/images/character_beta.png", vectorOfScale);
	//characterSprite.setScale (vectorOfScale); //

	sf::Vector2f tmpSpeed(0, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type != sf::Event::KeyPressed || event.type != sf::Event::KeyReleased)
				WhatIsPressed.update(event);
				
        }

		if (WhatIsPressed.isKeyPressed(sf::Keyboard::Q))
			window.close();

		// TEST SHIT

		if (WhatIsPressed.isKeyPressed(sf::Keyboard::D))
		{
			tmpSpeed.x = 0.3;
			tmpSpeed.y = 0;
		}
		else if (WhatIsPressed.isKeyPressed(sf::Keyboard::A))
		{
			tmpSpeed.x = -0.3;
			tmpSpeed.y = 0;
		}
		else if (WhatIsPressed.isKeyPressed(sf::Keyboard::W))
		{
			tmpSpeed.x = 0;
			tmpSpeed.y = -0.3;
		}
		else if (WhatIsPressed.isKeyPressed(sf::Keyboard::S))
		{
			tmpSpeed.x = 0;
			tmpSpeed.y = 0.3;
		}	
		else
		{
			tmpSpeed.x = 0;
			tmpSpeed.y = 0;
		}

		// END OF TEST SHIT

		mainHero.setSpeed(tmpSpeed);

		mainHero.update();		
		mainHero.move();

        window.clear();
		window.draw(backgroundSprite);
		//window.draw(characterSprite);
		mainHero.draw();
        window.display();
    }

    return 0;
}
