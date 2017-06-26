#include "core\utils\TimeManager.hpp"
#include "graphics\VKBasicRenderer.hpp"
#include <iostream>

int main() {
	VKBasicRenderer renderer;
	renderer.Init();
	std::cin.get();
}