#include "Reactor.h"

#include "../asset/GameObject.h"

using namespace std;

Reactor::Reactor(shared_ptr< GameObject > gameObject) : _gameObject{gameObject} {}
