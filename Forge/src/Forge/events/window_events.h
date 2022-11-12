//
// Created by f4ls3 on 06.11.2022.
//

#pragma once

#include <iostream>
#include "../event.h"
#include "../logger.h"

namespace Forge::Events {
    class WindowCloseEvent : public IEvent {
    public:
        WindowCloseEvent();
    };

    class WindowResizedEvent : public IEvent {
    public:
        WindowResizedEvent(int width, int height);
        int get_width() const;
        int get_height() const;
    private:
        int width, height;
    };

    class WindowFocusEvent : public IEvent {
    public:
        WindowFocusEvent();
    };

    class WindowLostFocusEvent : public IEvent {
    public:
        WindowLostFocusEvent();
    };

    class WindowMovedEvent : public IEvent {
    public:
        WindowMovedEvent(int x, int y);
        int get_x() const;
        int get_y() const;

    private:
        int x, y;
    };

    /*class WindowResizedSubscriber : public Forge::IEventSubscriber {
    public:
        WindowResizedSubscriber() : Forge::IEventSubscriber(Forge::EventType::WindowResized) {}

        void on_event(Forge::IEvent *event) override {
            auto *win_event = (WindowResizedEvent *) event;

            FORGE_CORE_TRACE("width: " + std::to_string(win_event->get_width()));
            FORGE_CORE_TRACE("height: " + std::to_string(win_event->get_height()));
        }
    };*/
}