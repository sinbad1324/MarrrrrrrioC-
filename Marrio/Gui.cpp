#include "Gui.h"
#include "Game.h"
//void Gui::initTextLable()
//{
//}



TextLable* const Gui::addTextLable(std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName)
{
	TextLable *Lable = nullptr;
	Lable =  new  TextLable(this,name, _text, size, _bgSize, fontName);
	this->Elements.push_back(Lable);	
	return Lable;
}

TextBox* const Gui::addTextBox(std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName)
{
	TextBox* Lable = nullptr;
	Lable = new  TextBox(this, name, _text, size, _bgSize, fontName);
	this->Elements.push_back(Lable);
	return Lable;
}

ImageLable* const Gui::addImageLable(std::string name, std::string ImagePath)
{
	ImageLable* Lable = nullptr;
	Lable = new  ImageLable(this, name, ImagePath);
	this->Elements.push_back(Lable);
	return Lable;
}


void Gui::update()
{
	for (int i = 0; i < this->Elements.size(); i++)
	{
		this->Elements[i]->update();
	}

}

void Gui::render(sf::RenderTarget* target)
{
	for (int i = 0; i < this->Elements.size(); i++)
	{
		this->Elements[i]->render(target);
	}
}




Gui::Gui(Game* game)
{
//	this->initTextLable();
	this->game = game;

}

Gui::~Gui()
{
	/*for (int i = 0; i < this->Elements.size(); i++)
	{
		delete this->Elements[i];
	}*/
}