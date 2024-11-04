#ifndef _TEXTBOX_
#define _TEXTBOX_
#include "TextLable.h"




class TextBox :public TextLable
{
private:
	sf::Keyboard::Key key;
	bool shift;
	bool clicked;
	void initEvents();
public:
	TextBox(Gui*gui, std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName);

	
	
};
#endif // !_TEXTBOX_


