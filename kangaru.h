#pragma once

#include "kangaru/kangaru.hpp"

#define METHOD(...) decltype(__VA_ARGS__), __VA_ARGS__
#define INVOKE(...) ::kgr::Method<decltype(__VA_ARGS__), __VA_ARGS__>

template<typename>
struct ServiceMap;
