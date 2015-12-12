#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

struct View
{
	void addDrawable(std::shared_ptr<sf::Drawable> drawable);
	const std::vector< std::shared_ptr< sf::Drawable > >& getDrawables();
private:
	std::vector<std::shared_ptr<sf::Drawable>> drawables;
};
