#include <stdio.h>
#define MAX 100

int dq[MAX], f = -1, r = -1, sz = 0;

int empty() { return sz == 0; }
int size() { return sz; }

void push_front(int x){
    if(sz == MAX) return;
    if(empty()) f = r = 0;
    else f = (f - 1 + MAX) % MAX;
    dq[f] = x; sz++;
}

void push_back(int x){
    if(sz == MAX) return;
    if(empty()) f = r = 0;
    else r = (r + 1) % MAX;
    dq[r] = x; sz++;
}

void pop_front(){
    if(empty()) return;
    if(sz == 1) f = r = -1;
    else f = (f + 1) % MAX;
    sz--;
}

void pop_back(){
    if(empty()) return;
    if(sz == 1) f = r = -1;
    else r = (r - 1 + MAX) % MAX;
    sz--;
}

int front(){
    return empty() ? -1 : dq[f];
}

int back(){
    return empty() ? -1 : dq[r];
}

void display(){
    for(int i = 0; i < sz; i++)
        printf("%d ", dq[(f + i) % MAX]);
    printf("\n");
}
