//
// Created by f4ls3 on 06.11.2022.
//

#include "window_events.h"

namespace Forge::Events {
    WindowCloseEvent::WindowCloseEvent() : IEvent(Forge::EventType::WindowClosed) {}

    WindowResizedEvent::WindowResizedEvent(int width, int height) : IEvent(Forge::EventType::WindowResized) {
        this->width = width;
        this->height = height;
    }
    int WindowResizedEvent::get_width() const { return width; }
    int WindowResizedEvent::get_height() const { return height; }

    WindowFocusEvent::WindowFocusEvent() : IEvent(Forge::EventType::WindowFocused) {}

    WindowLostFocusEvent::WindowLostFocusEvent() : IEvent(Forge::EventType::WindowLostFocus) {}

    WindowMovedEvent::WindowMovedEvent(int x, int y) : IEvent(Forge::EventType::WindowMoved) {
        this->x = x;
        this->y = y;
    }

    int WindowMovedEvent::get_x() const {
        return x;
    }

    int WindowMovedEvent::get_y() const {
        return y;
    }
}