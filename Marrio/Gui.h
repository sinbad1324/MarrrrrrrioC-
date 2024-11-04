#include <string>
#include <iostream>
#include <vector>

#include "TextLable.h"
#include "TextBox.h"
#include "ImageLable.h"
#ifndef _GUI_
#define _GUI_

class Game;

class Gui : public MyClass::GlobalStruct
{
private:
	std::vector<MyClass::GlobalUI*> Elements;
//	void initTextLable();
public:
	Gui(Game *game);
	~Gui();
	Game* game;
	//Setters
	TextLable* const  addTextLable(std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName);
	TextBox* const  addTextBox(std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName);
	ImageLable* const  addImageLable(std::string name, std::string ImagePath);


	//Update
	void update() override;
	//render
	void render(sf::RenderTarget* target) override;
	//accessor and generic
	template<typename T>
	T* FindWithName(std::string name) {
		T* element = nullptr;

		for (int i = 0; i < this->Elements.size(); i++) {
			if (this->Elements[i]->getName() == name) {
				element = this->Elements[i];
				break;
			}
		}

		return element;
	}
};
#endif // !_GUI_

