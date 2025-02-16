
#include <iostream>
#include <raylib.h>

#include <objects.h>

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

int main(int argv, char **argc) {
    std::cout << "Hello, World" << std::endl;
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "C++ To-do Application");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    
    OBJECT::CheckerButton _checker_button((Vector2){400 - BUTTON_SIZE.x / 2, 300 - BUTTON_SIZE.y / 2});
    OBJECT::Button _button((Vector2){100, 100});
    _checker_button._checked = true;
    
    SetTargetFPS(60);
    while(!WindowShouldClose()) {
	BeginDrawing();
	
	ClearBackground((Color){7, 7, 7, 255});
	_checker_button._render();
	_button._render();
	
	EndDrawing();
	
	if (IsKeyPressed(KEY_END)) {
	    CloseWindow();
	}
    }
    CloseWindow();
    return 0;
}
