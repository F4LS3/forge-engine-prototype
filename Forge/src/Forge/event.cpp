//
// Created by f4ls3 on 06.11.2022.
//

#include "event.h"
#include "logger.h"



namespace Forge {
    std::queue<IEvent*> EventPublisher::event_queue;
    std::set<IEventSubscriber*> EventPublisher::event_subscribers;

    void EventPublisher::subscribe(IEventSubscriber *subscriber) {
        Forge::EventPublisher::event_subscribers.insert(subscriber);
    }

    void EventPublisher::queue_event(IEvent *event) {
        Forge::EventPublisher::event_queue.push(event);
    }

    void EventPublisher::dispatch_queue() {
        FORGE_CORE_TRACE("Dispatching queue");
        while(!Forge::EventPublisher::event_queue.empty()) {
            for (auto subscriber : event_subscribers) {
                FORGE_CORE_TRACE("Subscriber iteration");
                if(subscriber->get_event_type() == event_queue.front()->get_event_type()) {
                    FORGE_CORE_TRACE("Event subscriber found, will execute");
                    subscriber->on_event(event_queue.front());
                }
            }
            event_queue.pop();
        }
    }
}