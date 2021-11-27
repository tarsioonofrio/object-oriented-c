//https://home.cs.colorado.edu/~kena/classes/5448/f12/presentation-materials/gatchell.pdf
//https://www.codementor.io/@michaelsafyan/object-oriented-programming-in-c-du1081gw2
//https://stackoverflow.com/questions/351733/how-would-one-write-object-oriented-code-in-c

#include <stdio.h>
#include <stdlib.h>

// Source file
struct Point {
    int x;
    int y;
    int (get_x)(struct Point* self);
};

// Constructor (without allocation)
void Point__init(struct Point* self, int x, int y) {
    self->x = x;
    self->y = y;
}

// Allocation + initialization (equivalent to "new Point(x, y)")
struct Point* Point__create(int x, int y) {
    struct Point* result = (struct Point*) malloc(sizeof(Point));
    Point__init(result, x, y);
    return result;
}

// Destructor (without deallocation)
void Point__reset(struct Point* self) {
}

// Destructor + deallocation (equivalent to "delete point")
void Point__destroy(struct Point* point) {
    if (point) {
        Point__reset(point);
        free(point);
    }
}

// Equivalent to "Point::x()" in C++ version
int get_x(struct Point* self) {
    return self->x;
}

// Equivalent to "Point::y()" in C++ version
int get_y(struct Point* self) {
    return self->y;
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
