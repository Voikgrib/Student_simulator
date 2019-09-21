
//
// This lib realise characters
//

#define RIGHT 1
#define LEFT  2

class character
{	
	private:

	sf::Texture  texture;
	sf::Sprite   sprite; // rework to animation
	sf::Vector2f position;
	sf::Vector2f speed;
	class stats statsInfo;
	sf::Time lastMoveTime;
	sf::Vector2f curScale;	
	sf::Vector2f size;

	public:

	character (const char* textureFileName, sf::Vector2f vectorOfScale); 	//
	void addSpeed (sf::Vector2f addSpeed);									//
	void setSpeed (sf::Vector2f newSpeed);									//
	sf::Vector2f getSpeed (void);											//
	void setPosition (sf::Vector2f positionVector);							//
	sf::Vector2f getPosition (void);										//
	

	void update (void);														//
	void move (void);														//
	void draw (void);														//
};


character::character (const char* textureFileName, sf::Vector2f vectorOfScale)
{
	TRY(texture.loadFromFile(textureFileName));
	sprite.setTexture(texture);
	sprite.setScale(vectorOfScale);
	lastMoveTime = MainClock.getElapsedTime();
	position.x = 0;
	position.y = 0;
	speed.x = 0;
	speed.y = 0;
	curScale = vectorOfScale;
	sf::Vector2u sizeTmp;	
	sizeTmp = texture.getSize();
	size.x = ((float) sizeTmp.x) * curScale.x;
	size.y = ((float) sizeTmp.y) * curScale.y;
}

void character::addSpeed (sf::Vector2f addSpeed)
{
	speed += addSpeed;
}

void character::setSpeed (sf::Vector2f newSpeed)
{
	speed = newSpeed;

	if (speed.x < 0 && curScale.x > 0)
	{
		curScale.x = curScale.x * (-1);
		position.x += size.x;
	}
	else if (speed.x > 0 && curScale.x < 0)
	{
		curScale.x = curScale.x * (-1);
		position.x -= size.x;
	}
}

sf::Vector2f character::getSpeed (void)
{
	return speed;
}

void character::setPosition (sf::Vector2f positionVector)
{
	position = positionVector;
}

sf::Vector2f character::getPosition (void)
{
	return position;
}

void character::move (void)
{
	sf::Time curTime = MainClock.getElapsedTime();
	position.x += speed.x * (curTime.asMilliseconds() - lastMoveTime.asMilliseconds());
	position.y += speed.y * (curTime.asMilliseconds() - lastMoveTime.asMilliseconds());
	lastMoveTime = curTime;
}

void character::update (void)
{
	sprite.setPosition(position);
	sprite.setScale(curScale);
}

void character::draw (void)
{
	MainWindow->draw(sprite);	
}
