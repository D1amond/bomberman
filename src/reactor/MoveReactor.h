#pragma once

#include "Reactor.h"

struct MoveReactor : Reactor
{
    MoveReactor(std::shared_ptr<GameObject> gameObject);
    std::vector<sf::Event::EventType> getEventTypes() override;
    void react(sf::Event event) override;
};
