#include "LevelLoader.h"

#include <SFML/Graphics.hpp>

#include "../level/Level.h"
#include "../level/Layer.h"

using namespace std;
using namespace sf;

LevelLoader::~LevelLoader() = default;

LevelLoader::LevelLoader(CollisionManager& collisionManager) : _collisionManager(collisionManager) {}

unique_ptr<Level> LevelLoader::load(string name)
{
	if (tileset.loadFromFile("res/texture/tile/tileset.png"))
	{
		//first layer
		Layer layer;
		for (int i=0;i<15;i++) {
			for (int j=0;j<15;j++) {
				auto sprite = make_shared<sf::Sprite>();
				sprite->setTexture(tileset);
				
				if (i==0 || i==14 || j==0 || j==14 || (i%2 == 0 && j%2 == 0)) {
					_collisionManager.addTile({{i*32.f, j*32.f}, 32, 32});
					sprite->setTextureRect(sf::IntRect(32, 0, 32, 32));
				} else
					sprite->setTextureRect(sf::IntRect(0, 0, 32, 32));
				
				sprite->setPosition(sf::Vector2f(i*32, j*32));
				
				layer.addTile(sprite);
			}
		}
		unique_ptr<Level> level(new Level);
		level->addLayer(layer);
		
		return move(level);
	}
	return nullptr;
}
