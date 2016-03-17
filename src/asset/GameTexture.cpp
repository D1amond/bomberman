#include "GameTexture.h"

#include <iostream>

using namespace std;
using namespace sf;

GameTexture::GameTexture(string path)
{
	_texture = make_shared<Texture>();
	if (!_texture->loadFromFile(path)) {
		cout << "unable to load texture from file '" << path << "'" << endl;
	} else {
		cout << "Loaded texture from file '" << path << "'" << endl;
	}
}

shared_ptr<Texture> GameTexture::getTexture()
{
	return _texture;
}
