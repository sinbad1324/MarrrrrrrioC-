#include "MyClass.hpp"
#include <sstream>
#include <string>
#include <iostream>
#ifndef _TEXTLABLE_
#define _TEXTLABLE_

class Gui;

class TextLable : public MyClass::GlobalUI
{
private:
	//text
	sf::Text Lable;
	std::stringstream text;
	sf::Font font;
	sf::Color color;
	int textSize;
	int textTransparency;
	sf::Color textStrokeColor;
	int textStrokeThickness;
	int textStrokeTransparency;

	//bg
	MyClass::TextHorizonalAligne horizonalAligne;
	MyClass::TextVerticalAligne verticalAligne;



	//void initalizeVariables();
	void initLable();
	const sf::Vector2f getAlignement();
public:
	//variables
	TextLable(Gui* gui, std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName);

	//setters
	void setText(std::string _text);
	void setTextColor(sf::Color Color);
	void setCharSize(int size);
	void setVerticalAlignement(MyClass::TextVerticalAligne VerticalAligne);
	void setHorizonalAligne(MyClass::TextHorizonalAligne horizonalAligne);
	void setTextTransparency(int value);
	void setTextStrokeTransparency(int value);
	void setTextStrokeThickness(int value);
	void setTextStrokeColor(const sf::Color& newColor);

	//getters
	std::string  getText();
	int getTextStrokeThickness() const;
	int getTextStrokeTransparency() const;
	sf::Color getTextStrokeColor() const;
	
	void ab() override;

	//update
	void update() override;
	//render
	void render(sf::RenderTarget* target) override;
};

#endif // !_TEXTLABLE_



