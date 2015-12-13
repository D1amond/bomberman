#include "View.h"
#include <src/level/Level.h>

using namespace std;

View::View() {}

const vector<shared_ptr<sf::Drawable>>& View::getDrawables()
{
	return drawables;
}

void View::addDrawable(shared_ptr<sf::Drawable> drawable)
{
	drawables.push_back(drawable);
}
