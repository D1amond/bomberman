#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

struct GameTexture
{
	GameTexture(std::string path);
	std::weak_ptr<sf::Texture> getTexture();
private:
	std::shared_ptr<sf::Texture> _texture;
};
