#include "Game.h"
#include "MyClass.hpp"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600),"MyGame", sf::Style::Close | sf::Style::Titlebar);
	
}

void Game::initScreenGui()
{
	ScreenGui = new Gui(this);
	ImageLable* background = this->ScreenGui->addImageLable("etoile", "mario.png");
	background->setBgSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));
	background->setPosition(sf::Vector2f(0, 0));
	background->setBgColor(sf::Color::White);
	background->setSmooth(true);
	background->setRepeated(false);



	ImageLable* nuage = this->ScreenGui->addImageLable("nuage", "Cloud.png");
	nuage->setBgSize(sf::Vector2f(80,80));
	nuage->setPosition(sf::Vector2f(100, 100));
	nuage->setBgColor(sf::Color::White);
	nuage->setSmooth(true);
	nuage->setRepeated(false);
	nuage->setImageScale(100,100);


	TextLable* pointsText = this->ScreenGui->addTextLable("pointsText", "Points : 0", 20, sf::Vector2f(.2, .2), "Rubik");
	pointsText->setTextColor(sf::Color::White);
	pointsText->setHorizonalAligne(MyClass::TextHorizonalAligne::horizonalCenter);
	pointsText->setVerticalAlignement(MyClass::TextVerticalAligne::verticalCenter);
	pointsText->setBgSize(sf::Vector2f(20.f, 10.f));
	pointsText->setBgColor(sf::Color::Red);
	pointsText->setTransparency(100);
	pointsText->setPosition(sf::Vector2f(10.f, 5.f));
	pointsText->setStrokeThickness(1);
	pointsText->setStrokeColor(sf::Color::Blue);
	pointsText->setTextStrokeThickness(1);

	TextLable*	nameText = this->ScreenGui->addTextLable("nameText", "Name: yo", 20, sf::Vector2f(.2, .2), "Rubik");
	nameText->setHorizonalAligne(MyClass::TextHorizonalAligne::horizonalCenter);
	nameText->setVerticalAlignement(MyClass::TextVerticalAligne::verticalCenter);
	nameText->setTransparency(0);
	nameText->setTextColor(sf::Color::White);
	nameText->setTextStrokeThickness(1);
	nameText->setTextStrokeColor(sf::Color::White);
	nameText->setPosition(sf::Vector2f(120.f + nameText->bg.getSize().x , 5.f));
	nameText->setBgSize(sf::Vector2f(20.f, 10.f));

	for (int i = 0; i <= 5; i++)
	{
		ImageLable* coeur = this->ScreenGui->addImageLable("coeur"+i, "coeur.png");
		coeur->setBgSize(sf::Vector2f(35.0,35.0));
		coeur->setPosition(sf::Vector2f((window->getSize().x - coeur->getBgSize().x*i), 5.f));
		coeur->setBgColor(sf::Color::White);
		coeur->setSmooth(true);
		coeur->setRepeated(false);
	}


}

void Game::initWorkspace()
{
	workspace = new Workspace(this);
	object obj=	workspace->addObject("Yoyo", workspace);
}


bool const Game::isOpen() const
{
	return this->window->isOpen();
}

 sf::Vector2i Game::getPosition()
{
	return this->window->getPosition();
}

 sf::Vector2u Game::getSize()
 {
	 return window->getSize();
 }

 bool Game::getPollEvent(sf::Event& ev)
 {
	 return this->window->pollEvent(ev);
 }


void Game::update()
{

	this->updateEvent();
	this->ScreenGui->update();
	this->workspace->update();

}

void Game::updateEvent()
{
	sf::Event event;
 	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		gameEvent.LuncheEvent(event);
	}
}


void Game::render()
{
	this->window->clear();
	// DRAW CODE
	this->ScreenGui->render(window);
	//Workspace
	this->workspace->render(window);
	// DRAW CODE
	this->window->display();

}

Game::Game()
{
	window = nullptr;
	this->ScreenGui = nullptr;
	this->workspace = nullptr;
	this->initWindow();
	this->initScreenGui();
	this->initWorkspace();
}

Game::~Game()
{
	delete window;
}




