#pragma once

#include <map>
#include "Layer.h"

struct Level
{
	void addLayer(Layer layer);
	const std::map<float, Layer>& getLayers() const;
private:
	std::map<float, Layer> layers;
};
