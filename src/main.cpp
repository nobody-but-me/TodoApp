
#include <iostream>
#include <raylib.h>

#include <objects.h>

#define INITIAL_NUMBER_OF_ROWS 10
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

int _number_of_rows = 0;

int main(int argv, char **argc) {
    std::cout << "Hello, World" << std::endl;
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "C++ To-do Application");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    
    Font _font = LoadFont("./assets/Iosevka.ttf");
    
    // OBJECT::CheckerButton _checker_button((Vector2){400 - BUTTON_SIZE.x / 2, 300 - BUTTON_SIZE.y / 2});
    
    Vector2 _list_position = (Vector2){20, 20};
    _number_of_rows = INITIAL_NUMBER_OF_ROWS;
    
    OBJECT::CheckerButton *_checker_button[_number_of_rows];
    Vector2 _text_position[_number_of_rows];
    
    for (int i = 0; i < _number_of_rows; i++) {
	_checker_button[i] = new OBJECT::CheckerButton((Vector2){WINDOW_WIDTH - BUTTON_SIZE.x - 20, _list_position.y + 30 * i});
	_text_position[i] = (Vector2){_list_position.x, _list_position.y + 30 * i};
    }
    
    SetTargetFPS(60);
    while(!WindowShouldClose()) {
	BeginDrawing();
	
	ClearBackground((Color){7, 7, 7, 255});
	
	for (int i = 0; i < _number_of_rows; i++) {
	    DrawTextEx(_font, "Text", _text_position[i], _font.baseSize * 0.9f, 0.5f, RAYWHITE);
	    _checker_button[i]->_render();
	}
	
	EndDrawing();
	
	if (IsKeyPressed(KEY_END)) {
	    CloseWindow();
	}
    }
    UnloadFont(_font);
    CloseWindow();
    return 0;
}
