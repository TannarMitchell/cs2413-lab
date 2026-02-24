#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj = malloc(sizeof(MyCircularQueue));
    obj->data = malloc(sizeof(int)*k);
    obj->capacity = k;
    obj->size = 0;
    obj->head = 0;
    obj->tail = 0;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->size == obj->capacity){
	return false;
    }
    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->size++;

    return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->size == 0){
    return false;
    }
    obj -> head = (obj->head+1) % obj->capacity;
    obj -> size--;
    return true;


}

int myCircularQueueFront(MyCircularQueue* obj) {
	if(obj->size == 0){
		return -1;
	}
	return obj->data[obj->head];

}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj-> size == 0){
	return -1;
    }
    int index = (obj->tail - 1 + obj->capacity) % obj -> capacity;
    return obj -> data[index];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0; //this will return either 1 or 0 which is true or false since 1 is true and 0 is false

}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
 
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
  
}
