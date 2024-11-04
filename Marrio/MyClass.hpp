
#ifndef MYCLASS_H
#define MYCLASS_H

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include <iostream>
#include <cmath>

class HoverEvent {
public:
	using listener = std::function<void()>;
	void Hover(listener Listener);
	void HoverLeave(listener Listener);

	void HoverLeaveAction();
	void HoverAction();
private:
	std::vector<listener>	hoverListeners;
	std::vector<listener>	hoverLeaveListeners;

};



class Button1Event {
public:
	using listener = std::function<void()>;
	void Click(listener Listener);
	void Pressed(listener Listener);

	void ClickAction();
	void PressedAction();
private:
	std::vector<listener>	ClickLiseners;
	std::vector<listener>	PressedListeners;

};


class Gui;

namespace MyClass {
	class GlobalStruct {
	public:
		virtual ~GlobalStruct() = default;
		virtual void  render(sf::RenderTarget* target)=0;
		virtual void update()=0;

	};
	class GlobalObject: public MyClass::GlobalStruct
	{
	public:
		//variables
		int uniqueId;
		bool canCollide;

		// setters
		void setParent(MyClass::GlobalObject* parent);
		void setName(const std::string newName);
		void setSize(const sf::Vector2f newBgSize);
		void setPosition(const sf::Vector2f newPosition);
		void setColor(const sf::Color newBgColor);
		void setTransparency(int value);

		void TextureRep(bool value);
		//Getters
		std::string getName() const;
		sf::Vector2f getSize() const;
		sf::Vector2f getPosition() const;
		sf::Color getColor() const;
		int getTransparency() const;

		// Functions
		bool const LoadTexture(sf::String &path);

		//Updates
		void BUpdate();
		void Events();

		//init
		void initObject();
	private:
		std::string name;
		int transparency;
		sf::Vector2f position;
		sf::Vector2f size;
		sf::Color color;
		MyClass::GlobalObject* parent;

		//sf::IntRect rect;
	protected:
		sf::Texture texture;
		sf::Sprite sprite;
	};

	class GlobalUI : public MyClass::GlobalStruct {

	private:
		std::string name;
		sf::Vector2f bgSize;
		sf::Vector2f position;
		sf::Color bgColor;
		int transparency;
		sf::Color strokeColor;
		int strokeThickness;
		int strokeTransparency;
		bool isClicked;
		bool isHover;
		bool hoverIsLeave;
	public:
		Gui* gui; 
		sf::RectangleShape bg;
		virtual ~GlobalUI() = default;
		virtual void ab() = 0;
		// setters
		void setName(const std::string& newName);
		void setBgSize(const sf::Vector2f& newBgSize);
		void setPosition(const sf::Vector2f& newPosition);
		void setBgColor(const sf::Color& newBgColor);
		void setTransparency(int value);
		void setStrokeTransparency(int value);
		void setStrokeThickness(int value);
		void setStrokeColor(const sf::Color& newColor);

		//getters
		std::string getName() const;
		sf::Vector2f getBgSize() const;
		sf::Vector2f getPosition() const;
		sf::Color getBgColor() const;
		int getTransparency() const;
		int getStrokeThickness() const;
		int getStrokeTransparency() const;
		sf::Color getStrokeColor() const;
		//Events
		HoverEvent hover;
		Button1Event Button1;
		//Update

		void Bupdate();
		void Events();
		
		//init
		void initUI(Gui*gui);
	};
	template<typename T>
	T Random(T min ,T max){
		if (min > max)
			return 0;
		return min + (static_cast<T>(rand()) * (max - min) / static_cast<T>(RAND_MAX));
	}

	sf::Color RandomColor(int min, int max);

	enum TextVerticalAligne
	{
		top,
		verticalCenter,
		bottom,
	};
	enum TextHorizonalAligne
	{
		horizonalCenter,
		left,
		right,
	};

}

#endif // !MYCLASS_H