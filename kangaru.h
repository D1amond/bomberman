#pragma once

#include "kangaru/kangaru.hpp"

#define METHOD(...) ::kgr::Method<decltype(__VA_ARGS__), __VA_ARGS__>

template<typename>
struct ServiceMap;

template<>
struct ServiceMap<kgr::Container&> : kgr::Map<kgr::ContainerService> {};

template<>
struct ServiceMap<kgr::Container> : kgr::Map<kgr::ForkService> {};
