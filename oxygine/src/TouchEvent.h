#pragma once
#include "oxygine-include.h"
#include "Event.h"
#undef OUT
namespace oxygine
{
    class TouchEvent : public Event
    {
    public:
        enum
        {
            __FIRST = sysEventID('T', 'O', 0),

            CLICK,
            OVER,
            OUT,
            MOVE,
            TOUCH_DOWN,
            TOUCH_UP,
            WHEEL_UP,
            WHEEL_DOWN,

            __LAST//system
        };


        TouchEvent(eventType type, bool Bubbles = true, const Vector2& locPosition = Vector2(0, 0)) : Event(type, Bubbles), localPosition(locPosition), position(locPosition), mouseButton(MouseButton_Touch), pressure(1.0f), index(1), __clickDispatched(false) {}

        /**position in local space for Event::currentTarget Actor*/
        Vector2 localPosition;
        /**position in local space for Event::target actor*/
        Vector2 position;

        float pressure;

        MouseButton mouseButton;
        pointer_index index;

        const PointerState* getPointer() const;

        static bool isTouchEvent(int eventID) { return eventID > __FIRST && eventID < __LAST; }
        bool __clickDispatched;
    };
}