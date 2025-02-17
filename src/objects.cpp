
#include <objects.h>
#include <raylib.h>
#include <iostream>


namespace OBJECT {
    
    bool Object::_mouse_click(int _mouse_button) {
	if (this->_mouse_over()) {
	    if (IsMouseButtonDown(_mouse_button)) {
		return true;
	    }
	}
	return false;
    }

    bool Object::_mouse_over() {
	Rectangle _button_bounds = (Rectangle){
	    this->_position.x, 
	    this->_position.y, 
	    this->_size.x, 
	    this->_size.y
	};
	Vector2 _mouse_position = GetMousePosition();
	
	if (CheckCollisionPointRec(_mouse_position, _button_bounds)) {
	    return true;
	}
	return false;
    }
    
    Button::Button(Vector2 _position) {
	this->_position = _position;
	this->_size     = BUTTON_SIZE;
	this->_color    = BUTTON_BASE_COLOR;
	return;
    }

    void Button::_render() {
	Rectangle _button_rect = (Rectangle){
	    this->_position.x, 
	    this->_position.y, 
	    this->_size.x, 
	    this->_size.y
	};
	DrawRectangleRounded(_button_rect, BUTTON_ROUNDNESS, BUTTON_SEGMENTS, this->_color);
	
	if (this->_mouse_click(MOUSE_BUTTON_LEFT)) {
	    this->_color = BUTTON_PRESS_COLOR;
	}
	else {
	    if (this->_mouse_over()) {
		this->_color = BUTTON_HOVER_COLOR;
	    }
	    else {
		this->_color = BUTTON_BASE_COLOR;
	    }
	}
    }
    
    CheckerButton::CheckerButton(Vector2 _position) {
	this->_position = _position;
	this->_size     = BUTTON_SIZE;
	this->_color    = BUTTON_BASE_COLOR;
	return;
    }
    
    void CheckerButton::_render() {
	
	Rectangle _button_rect = (Rectangle){
	    this->_position.x, 
	    this->_position.y, 
	    this->_size.x, 
	    this->_size.y
	};
	DrawRectangleRounded(_button_rect, BUTTON_ROUNDNESS, BUTTON_SEGMENTS, this->_color);
	
	if (this->_mouse_over()) {
	    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		this->_checked = !this->_checked;
		printf("[INFO] Clicked. \n");
	    }
	}
	
	if (this->_checked == false) {
	    if (this->_mouse_over()) {
		this->_color = BUTTON_HOVER_COLOR;
	    }
	    else {
		this->_color = BUTTON_BASE_COLOR;
	    }
	}
	else {
	    if (this->_mouse_over()) {
		this->_color = (Color){150, 50, 50, 255};
	    }
	    else {
		this->_color = (Color){100, 50, 50, 255};
	    }
	}
    }
    
    // ButtonList::ButtonList(Vector2 _position, int _initial_number_rows) {
    // 	this->_position = _position;
    // 	this->_size     = BUTTON_SIZE;
    // 	this->_color    = BUTTON_BASE_COLOR;
    // 	this->_number_rows = _initial_number_rows;
    // 	return;
    // }
    // void ButtonList::_update_rows() {
	
    // }
    // void ButtonList::_render(Font _font, CheckerButton& _checker_button) {
	
    // 	for (int i = 0; i < this->_number_rows; i++) {
	    
    // 	    Vector2 _text_position = (Vector2){this->_position.x, this->_position.y + 30 * i};
    // 	    DrawTextEx(_font, "Text", _text_position, _font.baseSize * 2.0f, 0.5f, RAYWHITE);
	    
    // 	    // CheckerButton _button((Vector2){this->_position.x + 300, this->_position.y + 30 * i});
    // 	    // _button._checked = false;
    // 	    // _button.position.x = this->_position.x + 300;
	    
    // 	    // this->_base_button.position = (Vector2){this->_position.x + 300, this->_position.y + 30 * i};
    // 	    // _checker_button._position = (Vector2){this->_position.x + 300, this->_position.y + 30 * i};
    // 	    // _checker_button._render();
	    
    // 	    // _button._render();
    // 	}
    // }
}
