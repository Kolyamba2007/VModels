#pragma once
#include <vector>

#ifdef VMODELS_EXPORTS
#define API __declspec(dllexport)
#else 
#define API __declspec(dllimport)
#endif