
#include <objects.h>
#include <raylib.h>
#include <iostream>


OBJECT::Button::Button(Vector2 _position) {
    this->_position = _position;
    this->_size     = BUTTON_SIZE;
    this->_color    = BUTTON_BASE_COLOR;
    return;
}

bool OBJECT::Button::_mouse_click(int _mouse_button) {
    if (this->_mouse_over()) {
	if (IsMouseButtonDown(_mouse_button)) {
	    return true;
	}
    }
    return false;
}

bool OBJECT::Button::_mouse_over() {
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

void OBJECT::Button::_render() {
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

OBJECT::CheckerButton::CheckerButton(Vector2 _position, bool _checked = false) {
    this->_position = _position;
    this->_size     = BUTTON_SIZE;
    this->_color    = BUTTON_BASE_COLOR;
    this->_checked  = _checked;
    return;
}

void OBJECT::CheckerButton::_render() {
    
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

