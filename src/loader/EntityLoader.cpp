#include "EntityLoader.h"

using namespace std;
using namespace sf;

EntityLoader::EntityLoader() {}

EntityLoader::~EntityLoader() = default;

Entity EntityLoader::load(string name)
{
	if (tileset.loadFromFile("res/texture/tile/tileset.png")) {
		Entity entity;
		Sprite sprite;
		sprite.setTexture(tileset);
		
		if (name == "bomb") {
			sprite->setTextureRect(sf::IntRect(96, 0, 32, 32));
		}
		
		entity.setSprite(sprite);
		entity.setCharset(tileset);
		
		return entity;
	}
}
