#pragma once
#include <windows.h>
#include "sdk.hpp"

class cheat
{
public:
	static cheat* get_instance();

	void init();

	void render(UGameViewportClient* viewport, UCanvas* canvas);
private:

	static cheat* instance_;
};
