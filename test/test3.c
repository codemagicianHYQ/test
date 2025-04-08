#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 1000

typedef struct {
    int time;
    int delta;
} Event;

int compare(const void *a, const void *b) {
    return ((Event *)a)->time - ((Event *)b)->time;
}

typedef struct {
    Event events[MAX_EVENTS];
    int eventCount;
} MyCalendarThree;

MyCalendarThree* myCalendarThreeCreate() {
    MyCalendarThree* obj = (MyCalendarThree*)malloc(sizeof(MyCalendarThree));
    obj->eventCount = 0;
    return obj;
}

int myCalendarThreeBook(MyCalendarThree* obj, int start, int end) {
    obj->events[obj->eventCount++] = (Event){start, 1};
    obj->events[obj->eventCount++] = (Event){end, -1};

    qsort(obj->events, obj->eventCount, sizeof(Event), compare);

    int maxK = 0, ongoing = 0;
    for (int i = 0; i < obj->eventCount; i++) {
        ongoing += obj->events[i].delta;
        if (ongoing > maxK) {
            maxK = ongoing;
        }
    }

    return maxK;
}

void myCalendarThreeFree(MyCalendarThree* obj) {
    free(obj);
}

int main() {
    MyCalendarThree* myCalendarThree = myCalendarThreeCreate();
    printf("%d\n", myCalendarThreeBook(myCalendarThree, 10, 20)); // 返回 1
    printf("%d\n", myCalendarThreeBook(myCalendarThree, 50, 60)); // 返回 1
    printf("%d\n", myCalendarThreeBook(myCalendarThree, 10, 40)); // 返回 2
    printf("%d\n", myCalendarThreeBook(myCalendarThree, 5, 15));  // 返回 3
    printf("%d\n", myCalendarThreeBook(myCalendarThree, 5, 10));  // 返回 3
    printf("%d\n", myCalendarThreeBook(myCalendarThree, 25, 55)); // 返回 3
    myCalendarThreeFree(myCalendarThree);
    return 0;
}
