#include "GameObjectLoader.h"

#include "../asset/GameObject.h"
#include "../asset/GameSprite.h"
#include "../asset/GameTexture.h"
#include <src/animation/SimpleAnimation.h>
#include <src/reactor/MoveReactor.h>

using namespace std;
using namespace sf;

GameObjectLoader::GameObjectLoader(
	EventManager& eventManager,
	GameObjectManager& objectManager
) : _eventManager{eventManager}, _objectManager{objectManager} {}

shared_ptr<GameObject> GameObjectLoader::load(string type)
{
	if (type == "hero") {
		auto texture = make_shared<GameTexture>("res/texture/hero/hero.png");
		auto gameSprite = make_shared<GameSprite>();
		auto sprite = make_shared<Sprite>();
		sprite->setTexture(*texture->getTexture().lock());
		sprite->setTextureRect(IntRect(32, 0, 32, 32));
		sprite->setPosition(Vector2f(32.f, 32.f));
		
		gameSprite->setSprite(sprite);
		gameSprite->setTexture(texture);
		
		//create and set animations
		auto animation1 = make_shared<SimpleAnimation>(gameSprite);
		auto animation2 = make_shared<SimpleAnimation>(gameSprite);
		auto animation3 = make_shared<SimpleAnimation>(gameSprite);
		auto animation4 = make_shared<SimpleAnimation>(gameSprite);
		
		animation1->addState(IntRect(32, 32, 32, 32));
		animation1->addState(IntRect(0, 32, 32, 32));
		animation1->addState(IntRect(32, 32, 32, 32));
		animation1->addState(IntRect(64, 32, 32, 32));
		animation1->addState(IntRect(32, 32, 32, 32));
		animation2->addState(IntRect(32, 0, 32, 32));
		animation2->addState(IntRect(0, 0, 32, 32));
		animation2->addState(IntRect(32, 0, 32, 32));
		animation2->addState(IntRect(64, 0, 32, 32));
		animation2->addState(IntRect(32, 0, 32, 32));
		animation3->addState(IntRect(32, 96, 32, 32));
		animation3->addState(IntRect(0, 96, 32, 32));
		animation3->addState(IntRect(32, 96, 32, 32));
		animation3->addState(IntRect(64, 96, 32, 32));
		animation3->addState(IntRect(32, 96, 32, 32));
		animation4->addState(IntRect(32, 64, 32, 32));
		animation4->addState(IntRect(0, 64, 32, 32));
		animation4->addState(IntRect(32, 64, 32, 32));
		animation4->addState(IntRect(64, 64, 32, 32));
		animation4->addState(IntRect(32, 64, 32, 32));
		
		gameSprite->addAnimation("MoveUp", animation1);
		gameSprite->addAnimation("MoveDown", animation2);
		gameSprite->addAnimation("MoveLeft", animation3);
		gameSprite->addAnimation("MoveRight", animation4);
		
		shared_ptr<GameObject> object = make_shared<GameObject>(type, gameSprite);
		auto moveReactor = make_shared<MoveReactor>(object);
		for (sf::Event::EventType type : moveReactor->getEventTypes()) {
			_eventManager.subscribe(type, moveReactor);
		}
		
		_objectManager.addObject(object);
		
		return object;
	}
	return nullptr;
}
