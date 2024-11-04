#include "MyClass.hpp"
#include <sstream>
#include <string>
#include <iostream>
#ifndef _IMAGELABLE_
#define _IMAGELABLE_

class Gui;

class ImageLable :public MyClass::GlobalUI
{
private:
	sf::Texture texture;
	sf::Color color;
	sf::Vector2i scale;
	sf::Vector2i ImagePos;
	//void initalizeVariables();
	void initLable();
public:
	ImageLable(Gui* gui, std::string name, std::string ImagePath);

	//setters
	void setPath(std::string ImagePath);
	void setSmooth(bool smooth);
	void setRepeated(bool repeated);
	void setImageScale(int x, int y);
	void setImagePos(int x, int y);
	//geter
	sf::Vector2u getImageSize();
	void ab() override;
	//update
	void update() override;
	//render
	void render(sf::RenderTarget* target) override;

};

#endif // !_IMAGELABLE_

