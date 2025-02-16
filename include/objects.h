#pragma once

#ifndef OBJECTS_H
#define OBJECTS_H

#include <raylib.h>

#define BUTTON_PRESS_COLOR       (Color){10, 10, 10, 255}
#define BUTTON_HOVER_COLOR       (Color){50, 50, 50, 255}
#define BUTTON_BASE_COLOR        (Color){24, 24, 24, 255}
#define BUTTON_SIZE              (Vector2){25, 25}
#define BUTTON_ROUNDNESS         0.2
#define BUTTON_SEGMENTS          3

namespace OBJECT {
    class Object {
	public:
	    Vector2 _position;
	    Vector2 _size;
	    Color _color;
    };
    
    class Button: public Object {
	public:
	    
	    Button(Vector2 _position);
	    bool _mouse_click(int _mouse_button);
	    bool _mouse_over();
	    void _render();
    };

    class CheckerButton: public Button {
	public:
	    bool _checked = false;
	    
	    CheckerButton(Vector2 _position, bool _checked = false);
	    
	    void _render();
    } 
}

#endif//OBJECTS_H
