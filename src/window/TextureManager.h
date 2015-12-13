#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

struct TextureManager
{
	sf::Texture get(std::string path);
private:
	std::map<std::string, sf::Texture>;
};
