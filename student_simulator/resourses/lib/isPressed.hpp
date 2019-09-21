
//
//	This lib realise how to detect what key is pressed
//

#define MAX_KEY 255

class isPressed
{
	private:
	bool keyPress[MAX_KEY];	
	bool keyRelease[MAX_KEY];
	bool keyClick[MAX_KEY]; // not implemented

	public:

	isPressed (void);
	bool isKeyPressed (unsigned int num);
	bool isKeyReleased (unsigned int num, bool untap); //if(untap true) keyRelease[i] = false
	void update (sf::Event event);
};


isPressed::isPressed (void)
{
	int i = 0;

	while (i != MAX_KEY)
	{
		keyPress[i] = false;	
		keyRelease[i] = false;
		keyClick[i] = false;
		i++;
	}
}


bool isPressed::isKeyPressed (unsigned int num)
{
	if (num > MAX_KEY)
		return false;

	return keyPress[num];
}


void isPressed::update (sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		keyPress[event.key.code] = true;		
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		keyPress[event.key.code] = false;
		keyRelease[event.key.code] = true;
	}
}


bool isPressed::isKeyReleased (unsigned int num, bool untap)
{
	if (num > MAX_KEY)
		return false;

	if (untap == true && keyRelease[num] == true)
	{
		keyRelease[num] = false;
		return true;
	}
	else if (keyRelease[num] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}


#undef MAX_KEY

// Global constant from this lib

class isPressed WhatIsPressed;




