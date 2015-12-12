#include "View.h"

using namespace std;

vector<shared_ptr<sf::Drawable>> View::getDrawables()
{
	return drawables;
}

void View::addDrawable(shared_ptr<sf::Drawable> drawable)
{
	drawables.push_back(drawable);
}
