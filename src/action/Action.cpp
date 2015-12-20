#include "Action.h"

#include "../asset/GameObject.h"

using namespace std;

Action::Action(weak_ptr<GameObject> gameObject) : _gameObject{gameObject} {}
