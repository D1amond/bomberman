#pragma once

#include "kangaru.h"

#include "../../window/service/ViewService.h"

#include "../KeyboardListener.h"

struct KeyboardListenerService : kgr::SharedService<KeyboardListener, kgr::Dependency<ViewService>> {};

template<> struct ServiceMap<std::shared_ptr<KeyboardListener>> { using Service = KeyboardListenerService; };