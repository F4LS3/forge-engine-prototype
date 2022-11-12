//
// Created by f4ls3 on 06.11.2022.
//

#pragma once

#include <functional>
#include <string>
#include <queue>
#include <set>
#include <utility>
#include "core.h"

namespace Forge {
    enum class EventType {
        WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyRelease,
        MouseButtonPressed, MouseButtonRelease, MouseMoved, MouseScrolled,
        ControllerAxisChange, ControllerButtonPressed, ControllerConnected, ControllerDisconnected
    };

    class IEvent {
    public:
        IEvent(EventType event_type) {
            this->event_type = event_type;
        }

        EventType get_event_type() {
            return event_type;
        }

    private:
        EventType event_type;
    };

    class IEventSubscriber {
    public:
        /**
         * @param event The event that is passed to the subscriber by the publisher; should be cast to specific event
         * */
        virtual void on_event(IEvent *event) = 0;

        EventType get_event_type() {
            return event_type;
        }

    protected:
        explicit IEventSubscriber(EventType event_type) {
            this->event_type = event_type;
        }

    private:
        EventType event_type;
    };

    class FORGE_API EventPublisher {
    public:
        static void subscribe(IEventSubscriber *subscriber);
        static void queue_event(IEvent *event);
        static void dispatch_queue();

    private:
        static std::queue<IEvent*> event_queue;
        static std::set<IEventSubscriber*> event_subscribers;
    };

    /*enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyRelease,
        MouseButtonPressed, MouseButtonRelease, MouseMoved, MouseScrolled,
        ControllerAxisChange, ControllerButtonPressed, ControllerConnected, ControllerDisconnected
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication        = BIT(0),
        EventCategoryInput              = BIT(1),
        EventCategoryKeyboard           = BIT(2),
        EventCategoryMouse              = BIT(3),
        EventCategoryMouseButton        = BIT(4),
        EventCategoryControllerAxis     = BIT(5),
        EventCategoryControllerButton   = BIT(6)
    };

    class FORGE_API Event {
        friend class EventDispatcher;
    public:
        virtual EventType get_event_type() const = 0;
        virtual const char* get_name() const = 0;
        virtual int get_category_flags() const = 0;
        virtual std::string to_str() const { return get_name(); }

        inline bool is_in_category(EventCategory category) { return get_category_flags() & category; }

    protected:
        bool event_handled = false;
    };*/
}