
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
	
	// if (this->_mouse_click(MOUSE_BUTTON_LEFT)) {
	//     // this->_color = BUTTON_PRESS_COLOR;
	//     this->_checked = !this->_checked;
	//     std::cout << this->_checked << std::endl;
	// }
	// else {
	//     if (this->_checked == false) {
	// 	if (this->_mouse_over()) {
	// 	    this->_color = BUTTON_HOVER_COLOR;
	// 	}
	// 	else {
	// 	    this->_color = BUTTON_BASE_COLOR;
	// 	}
	//     }
	//     else {
	// 	if (this->_mouse_over()) {
	// 	    this->_color = (Color){150, 50, 50, 255};
	// 	}
	// 	else {
	// 	    this->_color = (Color){100, 24, 24, 255};
	// 	}
	//     }
	// }
    }
}
