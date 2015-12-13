#include "Level.h"

void Level::addLayer(Layer layer)
{
	layers.emplace(0, layer);
}

const std::map<float, Layer>& Level::getLayers() const
{
	return layers;
}
