#pragma once

#include "Reactor.h"
#include <map>

struct MoveAction;

struct MoveReactor : Reactor
{
    MoveReactor(std::shared_ptr<GameObject> gameObject);
    std::vector<sf::Event::EventType> getEventTypes() override;
    void react(sf::Event event) override;
	
private:
	void keyPressed(std::shared_ptr<GameObject> object, sf::Keyboard::Key key);
	void keyReleased(std::shared_ptr<GameObject> object, sf::Keyboard::Key key);
	std::shared_ptr<MoveAction> _lastAction;
	std::vector<sf::Keyboard::Key> _keysPressed;
	std::map<sf::Keyboard::Key, std::string> _directions;
	std::map<sf::Keyboard::Key, sf::Vector2f> _positions;
};
