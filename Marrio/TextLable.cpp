#include "TextLable.h"
#include "Gui.h"
//void TextLable::initalizeVariables()
//{
//	this->text << "";
//
//}

void TextLable::initLable()
{
	this->Lable.setString(this->text.str());
	this->Lable.setCharacterSize(this->textSize);
	this->Lable.setFillColor(this->color);
	this->Lable.setFont(this->font);
	this->Lable.setStyle(sf::Text::Regular);
	this->Lable.setOutlineColor(this->getTextStrokeColor());
	this->Lable.setOutlineThickness(this->getTextStrokeThickness());

	sf::Vector2f alignement = this->getAlignement();

	this->Lable.setPosition(this->getPosition() + alignement);

	
	sf::FloatRect textBounds = this->Lable.getLocalBounds();
	this->bg.setSize(sf::Vector2f(textBounds.width, textBounds.height) + this->getBgSize() );
	this->bg.setPosition(sf::Vector2f(this->Lable.getPosition().x + textBounds.left, this->Lable.getPosition().y + textBounds.top)- alignement);
	


}

const sf::Vector2f TextLable::getAlignement()
{
	sf::Vector2f aligne = sf::Vector2f(0, 0);

	if (this->horizonalAligne == MyClass::TextHorizonalAligne::left)
	{
		aligne = sf::Vector2f(0, aligne.y);
	}
	if (this->horizonalAligne == MyClass::TextHorizonalAligne::horizonalCenter)
	{
		aligne = sf::Vector2f(this->getBgSize().x / 2.f, aligne.y);
	}
	if (this->horizonalAligne == MyClass::TextHorizonalAligne::right)
	{
		aligne = sf::Vector2f(this->getBgSize().x, aligne.y);
	}

	if (this->verticalAligne == MyClass::TextVerticalAligne::top)
	{
		aligne = sf::Vector2f(aligne.x, 0);

	}
	if (this->verticalAligne == MyClass::TextVerticalAligne::verticalCenter) {
		aligne = sf::Vector2f(aligne.x, this->getBgSize().y / 2);
	}
	if (this->verticalAligne == MyClass::TextVerticalAligne::bottom) {
		aligne = sf::Vector2f(aligne.x, this->getBgSize().y);
	}
	return aligne;
}

TextLable::TextLable(Gui* gui, std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName)
{
	this->text << _text;
	if (!this->font.loadFromFile("Fonts/" + fontName + ".ttf")) {
		std::cout << "Le fon n'a pas pu etre charger\n";
	}
	this->font.setSmooth(true);
	this->color = sf::Color::White;
	this->textSize = size;

	this->initUI(gui);
	this->setName("TextLable");
	this->verticalAligne = MyClass::TextVerticalAligne::verticalCenter;
	this->horizonalAligne = MyClass::TextHorizonalAligne::left;
	this->textStrokeColor = sf::Color::Black;
	this->textStrokeThickness = 0;
	this->textStrokeTransparency = 0;
	this->textTransparency = 0;
}



void TextLable::setText(std::string _text)
{
	this->text.clear();
	this->text.str("");
	this->text << _text;
}

void TextLable::setTextColor(sf::Color Color)
{
	this->color = Color;
}

void TextLable::setCharSize(int size)
{
	this->textSize = size;
}

void TextLable::setVerticalAlignement(MyClass::TextVerticalAligne VerticalAligne)
{
	this->verticalAligne = VerticalAligne;
}

void TextLable::setHorizonalAligne(MyClass::TextHorizonalAligne horizonalAligne)
{
	this->horizonalAligne = horizonalAligne;
}

void TextLable::setTextTransparency(int value)
{
	textTransparency = value;
	this->color = sf::Color(color.r, color.g, color.b, textTransparency);
}

void TextLable::setTextStrokeTransparency(int value)
{
	if (value < 0) value = 0;
	if (value > 255) value = 255;

	textStrokeTransparency = value;
	textStrokeColor = sf::Color(textStrokeColor.r, textStrokeColor.g, textStrokeColor.b, textStrokeTransparency);

}

void TextLable::setTextStrokeThickness(int value)
{
	textStrokeThickness = value;
}

void TextLable::setTextStrokeColor(const sf::Color& newColor)
{
	textStrokeColor = newColor;
}

std::string TextLable::getText()
{
	return this->Lable.getString();
}

int TextLable::getTextStrokeThickness() const
{
	return textStrokeThickness;
}

int TextLable::getTextStrokeTransparency() const
{
	return textStrokeTransparency;
}

sf::Color TextLable::getTextStrokeColor() const
{
	return textStrokeColor;
}

void TextLable::ab()
{
	std::cout << "ab" << "\n";
}



void TextLable::update()
{
	this->initLable();
	this->Bupdate();
}

void TextLable::render(sf::RenderTarget* target)
{
	target->draw(this->bg);
	target->draw(this->Lable);
}
