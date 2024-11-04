#include "ImageLable.h"

void ImageLable::initLable()
{
	bg.setTexture(&this->texture ,true);
}

ImageLable::ImageLable(Gui* gui, std::string name, std::string ImagePath)
{
	setPath(ImagePath);
	this->setName(name);
	initLable();
	initUI(gui);
	this->setName(name);
	ImagePos = sf::Vector2i(0, 0);
	scale = sf::Vector2i(texture.getSize().x , texture.getSize().y);
	this->texture.setSrgb(true);
}

void ImageLable::setPath(std::string ImagePath)
{
	if (!texture.loadFromFile("Texture/"+ ImagePath))
	{
		std::cout << "error" << this->getName() << " can't load " << ImagePath;
	}
	
}

void ImageLable::setSmooth(bool smooth)
{
	texture.setSmooth(smooth);
}

void ImageLable::setRepeated(bool repeated)
{
	texture.setRepeated(repeated);
}

void ImageLable::setImageScale(int x, int y)
{
	this->scale = sf::Vector2i(x,y);
}

void ImageLable::setImagePos(int x, int y)
{
	this->ImagePos = sf::Vector2i(x, y);
}

sf::Vector2u ImageLable::getImageSize()
{
	return this->texture.getSize();
}

void ImageLable::ab()
{
	std::cout << this->getName() << "\n";
}

void ImageLable::update()
{
	this->Bupdate();
	bg.setSize(this->getBgSize());
	bg.setPosition(getPosition());
	bg.setTextureRect(sf::IntRect(ImagePos.x, ImagePos.y, scale.x, scale.y));
}

void ImageLable::render(sf::RenderTarget* target)
{
	target->draw(this->bg);
}


