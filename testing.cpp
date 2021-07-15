/* Please uncomment this testing file to run testing on functions */


//#include "graphics.h"
//#include "rect.h"
//#include "triangle.h"
//#include <iostream>
//#include <memory>
//#include <time.h>
//
//using namespace std;
//
//bool rectTesting();
//bool triTesting();
//
//int main() {
//    srand(time(NULL));
//    if (rectTesting()) {
//        cout << "Passed all Rectangle class test cases" << endl;
//    }
//    if (triTesting()) {
//        cout << "Passed all Triangle class test cases" << endl;
//    }
//    return 0;
//}
//
//bool rectTesting() {
//    bool passed = true;
//
//    // Rect: isOverlapping
//    dimensions size(10,10);
//    Rect rectangle1(100, 100, size);
//    Rect rectangle2(105, 100, size);
//
//    if(!rectangle1.isOverlapping(rectangle2)){
//        passed = false;
//        cout << "Rectangle failed isOverlapping function testing" << endl;
//    }
//    return passed;
//}
//
//bool triTesting() {
//    bool passed = true;
//
//    //triangle: is overlapping
//    //          Rotate
//    dimensions2 sizeTri(10, 10);
//    Triangle triangle1(100, 100, sizeTri);
//    Triangle triangle2(105, 100, sizeTri);
//
//    if(!triangle1.isOverlapping(triangle2)){
//        passed = false;
//        cout << "Triangle failed isOverlapping function testing" << endl;
//    }
//    return passed;
//}