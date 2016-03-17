#pragma once

#include <memory>
#include <vector>
#include "../action/Action.h"

struct GameSprite;
struct Reactor;

struct GameObject
{
	GameObject(std::string type, std::shared_ptr<GameSprite> gameSprite);
	std::shared_ptr<GameSprite> getGameSprite();
	const std::string getType();
	const bool hasAction();
	std::shared_ptr<Action> getAction();
	void stopAction();
	void setAction(std::shared_ptr<Action> action);
	void addReactor(std::shared_ptr<Reactor> reactor);
private:
	std::string _type;
	std::shared_ptr<GameSprite> _gameSprite;
	std::shared_ptr<Action> _action;
	std::vector<std::shared_ptr<Reactor>> _reactors;
};
