#include "graphics.h"
#include "circle.h"
#include "rect.h"
#include "triangle.h"
#include "Button.h"
#include <iostream>
#include <memory>
#include <vector>
#include <time.h>

typedef std::chrono::high_resolution_clock Clock;
using namespace std;

GLdouble width, height;
int wd;
// color references: CS 120 Lecture & https://community.khronos.org/t/color-tables/22518/6
const color skyBlue(77/255.0, 213/255.0, 240/255.0);
const color grassGreen(26/255.0, 176/255.0, 56/255.0);
const color white(1, 1, 1);
const color brickRed(201/255.0, 20/255.0, 20/255.0);
const color darkBlue(1/255.0, 110/255.0, 214/255.0);
const color purple(119/255.0, 11/255.0, 224/255.0);
const color black(0, 0, 0);
const color gold(221/255.0, 175/255.0, 55/255.0);
const color magenta(1, 0, 1);
const color lightPink(1, 0, .5);
const color orange(1, 163/255.0, 22/255.0);
const color cyan (0, 1, 1);
const color lightgrey (.8,.8,.8);
const color huntergreen (.13,.37,.31);
const color copper(.85,.53,.1);
const color yelloGreen(.6,.8,.196078);
const color darkOrchid(.6,.196708,.8);
const color navy(0.137255, 0.137255, 0.556863);
const color inRed(.309804,0.184314,0.184314);
const color otherRed(.809804,0.484314,0.184314);
const color orangeRed(1, .25, 0);
const color orchid(0.858824,0.4392160,.158824);

// initialize unique pointers and user
Rect grass;
vector<unique_ptr<Shape>> cloudsEasy;
vector<unique_ptr<Shape>> cloudsMed;
vector<unique_ptr<Shape>> cloudsHard;
vector<unique_ptr<Shape>> heartsEasy;
vector<unique_ptr<Shape>> heartsMed;
vector<unique_ptr<Shape>> heartsHard;
vector<unique_ptr<Shape>> obstaclesEasy;
vector<unique_ptr<Shape>> obstaclesMed;
vector<unique_ptr<Shape>> obstaclesHard;
vector<unique_ptr<Shape>> triangles;
vector<unique_ptr<Shape>> treasureEasy;
vector<unique_ptr<Shape>> treasureMed;
vector<unique_ptr<Shape>> treasureHard;
vector<unique_ptr<Shape>> pointsEasy;
vector<unique_ptr<Shape>> pointsMed;
vector<unique_ptr<Shape>> pointsHard;
Rect user;

// create enum for each screen and set variable to startScreen
enum {startScreen = 1, gameScreen = 2, loseScreen = 3, winScreen = 4};
int screenDisp = startScreen;
clock_t startTime;
clock_t endTime;
double gameTime;

// init buttons for selecting difficulty at start screen
dimensions buttonSize(100, 50);

int difficulty;
Button easy(grassGreen, {100, 460}, buttonSize, "Easy");
Button medium(gold, {250, 460}, buttonSize, "Medium");
Button hard(brickRed, {400, 460}, buttonSize, "Hard");

// inits for clouds easy, medium, and hard
void initCloudsEasy() {
    cloudsEasy.clear();
    dimensions cloudBottom(30, 30);
    // First cloud
    cloudsEasy.push_back(make_unique<Circle>(white, 300, 100, 20));
    cloudsEasy.push_back(make_unique<Circle>(white, 330, 100, 20));
    cloudsEasy.push_back(make_unique<Circle>(white, 320, 90, 20));
    cloudsEasy.push_back(make_unique<Rect>(white, 315, 105, cloudBottom));
    // Second cloud
    cloudsEasy.push_back(make_unique<Circle>(white, 100, 80, 20));
    cloudsEasy.push_back(make_unique<Circle>(white, 130, 80, 20));
    cloudsEasy.push_back(make_unique<Circle>(white, 120, 70, 20));
    cloudsEasy.push_back(make_unique<Rect>(white, 115, 85, cloudBottom));
    // Third cloud
    cloudsEasy.push_back(make_unique<Circle>(white, 450, 50, 20));
    cloudsEasy.push_back(make_unique<Circle>(white, 480, 50, 20));
    cloudsEasy.push_back(make_unique<Circle>(white, 470, 40, 20));
    cloudsEasy.push_back(make_unique<Rect>(white, 465, 55, cloudBottom));

}
void initCloudsMed() {
    cloudsMed.clear();
    dimensions cloudBottom(30, 30);
    // First cloud
    cloudsMed.push_back(make_unique<Circle>(lightgrey, 300, 100, 20));
    cloudsMed.push_back(make_unique<Circle>(lightgrey, 330, 100, 20));
    cloudsMed.push_back(make_unique<Circle>(lightgrey, 320, 90, 20));
    cloudsMed.push_back(make_unique<Rect>(lightgrey, 315, 105, cloudBottom));
    // Second cloud
    cloudsMed.push_back(make_unique<Circle>(lightgrey, 100, 80, 20));
    cloudsMed.push_back(make_unique<Circle>(lightgrey, 130, 80, 20));
    cloudsMed.push_back(make_unique<Circle>(lightgrey, 120, 70, 20));
    cloudsMed.push_back(make_unique<Rect>(lightgrey, 115, 85, cloudBottom));
    // Third cloud
    cloudsMed.push_back(make_unique<Circle>(lightgrey, 450, 50, 20));
    cloudsMed.push_back(make_unique<Circle>(lightgrey, 480, 50, 20));
    cloudsMed.push_back(make_unique<Circle>(lightgrey, 470, 40, 20));
    cloudsMed.push_back(make_unique<Rect>(lightgrey, 465, 55, cloudBottom));
}

void initCloudsHard() {
    cloudsHard.clear();
    dimensions cloudBottom(30, 30);
    // First cloud
    cloudsHard.push_back(make_unique<Circle>(orangeRed, 300, 100, 20));
    cloudsHard.push_back(make_unique<Circle>(orangeRed, 330, 100, 20));
    cloudsHard.push_back(make_unique<Circle>(orangeRed, 320, 90, 20));
    cloudsHard.push_back(make_unique<Rect>(orangeRed, 315, 105, cloudBottom));
    // Second cloud
    cloudsHard.push_back(make_unique<Circle>(orangeRed, 100, 80, 20));
    cloudsHard.push_back(make_unique<Circle>(orangeRed, 130, 80, 20));
    cloudsHard.push_back(make_unique<Circle>(orangeRed, 120, 70, 20));
    cloudsHard.push_back(make_unique<Rect>(orangeRed, 115, 85, cloudBottom));
    // Third cloud
    cloudsHard.push_back(make_unique<Circle>(orangeRed, 450, 50, 20));
    cloudsHard.push_back(make_unique<Circle>(orangeRed, 480, 50, 20));
    cloudsHard.push_back(make_unique<Circle>(orangeRed, 470, 40, 20));
    cloudsHard.push_back(make_unique<Rect>(orangeRed, 465, 55, cloudBottom));
}

// init grass/lava, kills user instantly when they land on grass
void initGrass() {
    grass.setCenter(250, 450);
    grass.setSize(width, height/3);
    grass.setColor(brickRed);
}

// init hearts for easy, medium, and hard
void initHeartsEasy(){
    heartsEasy.clear();
    dimensions heart(20, 20);
    heartsEasy.push_back(make_unique<Rect>(brickRed, 400, 50, heart));
    heartsEasy.push_back(make_unique<Rect>(brickRed, 430, 50, heart));
    heartsEasy.push_back(make_unique<Rect>(brickRed, 460, 50, heart));
}

void initHeartsMed(){
    heartsMed.clear();
    dimensions heartMed(20, 20);
    heartsMed.push_back(make_unique<Rect>(cyan, 400, 50, heartMed));
    heartsMed.push_back(make_unique<Rect>(cyan, 430, 50, heartMed));
    heartsMed.push_back(make_unique<Rect>(cyan, 460, 50, heartMed));
}

void initHeartsHard(){
    heartsHard.clear();
    dimensions heartHard(20, 20);
    heartsHard.push_back(make_unique<Rect>(otherRed, 400, 50, heartHard));
    heartsHard.push_back(make_unique<Rect>(otherRed, 430, 50, heartHard));
    heartsHard.push_back(make_unique<Rect>(otherRed, 460, 50, heartHard));
}

// int obstacles for easy, medium, and hard
void initObstaclesEasy() {
    obstaclesEasy.clear();
    // gives min and max parameters for obstacle size/location
    int minSize = 15;
    int maxSize = 30;
    int randSize;

    int maxX = 700;
    int randX = 0;

    int maxY = 400;
    int minY = 100;
    int randY = 0;

    // randomly places and sizes obstacles based on min and max parameters
    srand(std::time(nullptr));
    for (int i = 0; i < 15; i++) {
        randSize = minSize + rand() % (maxSize - minSize + 1);
        dimensions size(randSize, randSize);

        randX = rand() % maxX;
        randY = minY + rand() % (minY - maxY + 1);

        obstaclesEasy.push_back(make_unique<Rect>(black, randX, randY, size));
    }
}

void initObstaclesMed() {
    obstaclesMed.clear();
    // gives min and max parameters for obstacle size/location
    int minSize = 15;
    int maxSize = 30;
    int randSize;

    int maxX = 700;
    int randX = 0;

    int maxY = 400;
    int minY = 100;
    int randY = 0;

    // randomly places and sizes obstacles based on min and max parameters
    srand(std::time(nullptr));
    for (int i = 0; i < 30; i++) {
            randSize = minSize + rand() % (maxSize - minSize + 1);
            dimensions size(randSize, randSize);

            randX = rand() % maxX;
            randY = minY + rand() % (minY - maxY + 1);

            obstaclesMed.push_back(make_unique<Rect>(orchid, randX, randY, size));
    }
}

void initObstaclesHard() {
    obstaclesHard.clear();
    // gives min and max parameters for obstacle size/location
    int minSize = 15;
    int maxSize = 30;
    int randSize;

    int maxX = 700;
    int randX = 0;

    int maxY = 400;
    int minY = 100;
    int randY = 0;

    // randomly places and sizes obstacles based on min and max parameters
    srand(std::time(nullptr));
    for (int i = 0; i < 35; i++) {
        randSize = minSize + rand() % (maxSize - minSize + 1);
        dimensions size(randSize, randSize);

        randX = rand() % maxX;
        randY = minY + rand() % (minY - maxY + 1);

        obstaclesHard.push_back(make_unique<Rect>(brickRed, randX, randY, size));
    }
}

// init triangles, exclusive to just the hard difficulty setting
void initTriangles() {
    obstaclesHard.clear();
    // gives min and max parameters for obstacle size/location
    int maxX = 700;
    int randX = 0;
    int maxY = 400;
    int minY = 100;
    int randY = 0;
    // randomly places and sizes obstacles based on min and max parameters
    srand(std::time(nullptr));
    for (int i = 0; i < 20; i++) {
        dimensions2 size(20, 20);
        randX = rand() % maxX;
        randY = minY + rand() % (minY - maxY + 1);
        triangles.push_back(make_unique<Triangle>(black, randX, randY, size));
    }
}

// init for easy, medium, and hard points
void initPointsEasy(){
    pointsEasy.clear();
    dimensions size(15, 15);

    pointsEasy.push_back(make_unique<Rect>(copper, 50, 50, size));
    pointsEasy.push_back(make_unique<Rect>(copper, 70, 50, size));
    pointsEasy.push_back(make_unique<Rect>(copper, 90, 50, size));
    pointsEasy.push_back(make_unique<Rect>(copper, 110, 50, size));
    pointsEasy.push_back(make_unique<Rect>(copper, 130, 50, size));
}

void initPointsMed(){
    pointsMed.clear();
   dimensions size(15, 15);

    pointsMed.push_back(make_unique<Rect>(lightPink, 50, 50, size));
    pointsMed.push_back(make_unique<Rect>(lightPink, 70, 50, size));
    pointsMed.push_back(make_unique<Rect>(lightPink, 90, 50, size));
    pointsMed.push_back(make_unique<Rect>(lightPink, 110, 50, size));
    pointsMed.push_back(make_unique<Rect>(lightPink, 130, 50, size));
    pointsMed.push_back(make_unique<Rect>(lightPink, 50, 75, size));
    pointsMed.push_back(make_unique<Rect>(lightPink, 70, 75, size));
    pointsMed.push_back(make_unique<Rect>(lightPink, 90, 75, size));
    pointsMed.push_back(make_unique<Rect>(lightPink, 110, 75, size));
    pointsMed.push_back(make_unique<Rect>(lightPink, 130, 75, size));
}

void initPointsHard(){
    pointsHard.clear();
    dimensions size(15, 15);

    pointsHard.push_back(make_unique<Rect>(inRed, 50, 50, size));
    pointsHard.push_back(make_unique<Rect>(inRed, 70, 50, size));
    pointsHard.push_back(make_unique<Rect>(inRed, 90, 50, size));
    pointsHard.push_back(make_unique<Rect>(inRed, 110, 50, size));
    pointsHard.push_back(make_unique<Rect>(inRed, 130, 50, size));
    pointsHard.push_back(make_unique<Rect>(inRed, 50, 75, size));
    pointsHard.push_back(make_unique<Rect>(inRed, 70, 75, size));
    pointsHard.push_back(make_unique<Rect>(inRed, 90, 75, size));
    pointsHard.push_back(make_unique<Rect>(inRed, 110, 75, size));
    pointsHard.push_back(make_unique<Rect>(inRed, 130, 75, size));
}

// init easy, medium, and hard treasures
void initTreasureEasy() {
    treasureEasy.clear();
    // gives min and max parameters for treasure size/location
    int minX = 200;
    int maxX = 700;
    int randX = 0;

    int minY = 100;
    int maxY = 300;
    int randY = 0;

    // randomly places and sizes treasures based on min and max parameters
    srand(std::time(nullptr));
    for (int i = 0; i < 5; i++) {
        dimensions size(20, 20);

        randX = rand() % (maxX - minX + 1);
        randY = minY + rand() % (minY - maxY + 1);
        treasureEasy.push_back(make_unique<Rect>(copper, randX, randY, size));
    }
}

void initTreasureMed() {
    treasureMed.clear();
    // gives min and max parameters for treasure size/location
    int minX = 200;
    int maxX = 700;
    int randX = 0;

    int minY = 100;
    int maxY = 300;
    int randY = 0;

    // randomly places and sizes treasures based on min and max parameters
    srand(std::time(nullptr));
    for (int i = 0; i < 10; i++) {
        dimensions size(20, 20);

        randX = rand() % (maxX - minX + 1);
        randY = minY + rand() % (minY - maxY + 1);
        treasureMed.push_back(make_unique<Rect>(lightPink, randX, randY, size));
    }
}


void initTreasureHard() {
    treasureHard.clear();
    // gives min and max parameters for treasure size/location
    int minX = 200;
    int maxX = 700;
    int randX = 0;

    int minY = 100;
    int maxY = 300;
    int randY = 0;

    // randomly places and sizes treasures based on min and max parameters
    srand(std::time(nullptr));
    for (int i = 0; i < 10; i++) {
        dimensions size(20, 20);

        randX = rand() % (maxX - minX + 1);
        randY = minY + rand() % (minY - maxY + 1);
        treasureHard.push_back(make_unique<Rect>(inRed, randX, randY, size));
    }
}

// init user (same for all difficulties)
void initUser() {
    // Initialize the user to be a 20x20 magenta block
    user.setColor(magenta);
    user.setCenter(250, 50);
    user.setSize(20, 20);
}

// call all initializers
void init() {
    width = 500;
    height = 500;
    srand(time(0));
    initCloudsEasy();
    initCloudsMed();
    initCloudsHard();
    initHeartsEasy();
    initHeartsMed();
    initHeartsHard();
    initGrass();
    initTriangles();
    initObstaclesEasy();
    initObstaclesMed();
    initObstaclesHard();
    initTreasureEasy();
    initTreasureMed();
    initTreasureHard();
    initUser();
    initPointsEasy();
    initPointsMed();
    initPointsHard();
}


void printMessage(string message){
    for (char letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // if in game screen, prompt user to press button difficulty, then press start
    if (screenDisp == startScreen) {
        startTime = clock();
        glColor3f(1, 1, 1);
        glRasterPos2i(2, 200);
        printMessage("PLEASE SELECT DIFFICULTY THEN PRESS S TO START");

        easy.draw();
        medium.draw();
        hard.draw();
    }
    // if in game screen, display treasure remaining message
    else if (screenDisp == gameScreen) {
        endTime = clock();
        glColor3f(1, 1, 1);
        glRasterPos2i(10, 30);
        printMessage("Treasure Remaining");

        // if selected difficulty easy
        // user, clouds, half treasure, hearts, half points, half obstacles
        // draw all displayed items
        if (difficulty == 1) {
            for (unique_ptr<Shape> &s : cloudsEasy) {
                s->draw();
            }
            //
            for (unique_ptr<Shape> &d : obstaclesEasy) {
                d->draw();
            }

            for (int i = 0; i < treasureEasy.size(); i++) {
                treasureEasy[i]->draw();
            }
            for (unique_ptr<Shape> &s : heartsEasy) {
                s->draw();
            }
            for (int i = 0; i < pointsEasy.size(); i++) {
                pointsEasy[i]->draw();
            }
            user.draw();
        }
        // if selected difficulty medium
        // draw all displayed items
        else if (difficulty == 2) {
            for (unique_ptr<Shape> &s : cloudsMed) {
                s->draw();
            }
            for (unique_ptr<Shape> &s : obstaclesMed) {
                s->draw();
            }
            for (unique_ptr<Shape> &s : treasureMed) {
                s->draw();
            }
            for (unique_ptr<Shape> &s : heartsMed) {
                s->draw();
            }
            for (unique_ptr<Shape> &s : pointsMed) {
                s->draw();
            }
            grass.draw();
            user.draw();
        }
        // if selected difficulty hard
        // user, clouds, treasure, hearts, points, obstacles, triangles
        // draw all displayed items
        else if (difficulty == 3) {
            for (unique_ptr<Shape> &s : cloudsHard) {
                s->draw();
            }
            for (unique_ptr<Shape> &s : obstaclesHard) {
                s->draw();
            }
            for (unique_ptr<Shape> &s : triangles) {
                s->draw();
            }
            for (unique_ptr<Shape> &s : treasureHard) {
                s->draw();
            }
            for (unique_ptr<Shape> &s : heartsHard) {
                s->draw();
            }
            for (unique_ptr<Shape> &s : pointsHard) {
                s->draw();
            }
            grass.draw();
            user.draw();
        }

    }
    // if player dies/loses, display message and time it took them
    else if (screenDisp == loseScreen) {
        // clear all drawn objects
        obstaclesEasy.clear();
        obstaclesMed.clear();
        obstaclesHard.clear();
        triangles.clear();

        // calculate total gameTime
        gameTime = endTime - startTime;
        string message = "You Lose";
        glColor3f(1, 1, 1);
        glRasterPos2i(200, 200);
        printMessage(message);
        string timeMessage = "Your time was ";
        timeMessage.append(to_string(gameTime*10 / (double) CLOCKS_PER_SEC) + " seconds");
        glRasterPos2i(115, 220);
        for (char letter : timeMessage) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
        }
        // prompt user to play again by pressing "p" key
        string message1 = "Press P to play again";
        glRasterPos2i(150, 240);
        printMessage(message1);
    }
    // if player collects all treasure/wins, display message and time it took them
    else if (screenDisp == winScreen) {
        // clear all drawn objects
        obstaclesEasy.clear();
        obstaclesMed.clear();
        obstaclesHard.clear();
        triangles.clear();

        // calculate total gameTime
        gameTime = endTime - startTime;
        string winMessage = "You Win!";
        glColor3f(1, 1, 1);
        glRasterPos2i(200, 200);
        printMessage(winMessage);

        string timeMessage = "Your time was ";
        timeMessage.append(to_string(gameTime*10 / (double) CLOCKS_PER_SEC) + " seconds");
        glRasterPos2i(150, 220);
        for (char letter : timeMessage) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
        }
        // prompt user to play again by pressing "p" key
        string message = "Press P to play again";
        glRasterPos2i(150, 240);
        printMessage(message);
    }

    // check if in game screen
    if (screenDisp != startScreen) {
        // implement overlapping logic for easy difficulty
        if (difficulty == 1)
        {
            for (int i = 0; i < obstaclesEasy.size(); i += 1) {
                if (dynamic_cast<Rect &>(*obstaclesEasy[i]).isOverlapping(user)) {
                    obstaclesEasy.erase(obstaclesEasy.begin() + i);
                    heartsEasy.pop_back();
                }
            }
            for (int i = 0; i < treasureEasy.size(); i += 1) {
                if (dynamic_cast<Rect &>(*treasureEasy[i]).isOverlapping(user)) {
                    treasureEasy.erase(treasureEasy.begin() + i);
                    pointsEasy.pop_back();
                }
            }
        }
        // implement overlapping logic for medium difficulty
        if (difficulty == 2){
            for (int i = 0; i < obstaclesMed.size(); i += 1) {
                if (dynamic_cast<Rect &>(*obstaclesMed[i]).isOverlapping(user)) {
                    obstaclesMed.erase(obstaclesMed.begin() + i);
                    heartsMed.pop_back();
                }
            }
            for (int i = 0; i < treasureMed.size(); i += 1) {
                if (dynamic_cast<Rect &>(*treasureMed[i]).isOverlapping(user)) {
                    treasureMed.erase(treasureMed.begin() + i);
                    pointsMed.pop_back();
                }
            }
        }
        // implement overlapping logic for hard difficulty
        if (difficulty == 3) {
            for (int i = 0; i < obstaclesHard.size(); i += 1) {
                if (dynamic_cast<Rect &>(*obstaclesHard[i]).isOverlapping(user)) {
                    obstaclesHard.erase(obstaclesHard.begin() + i);
                    heartsHard.pop_back();
                }
            }
            for (int i = 0; i < treasureHard.size(); i += 1) {
                if (dynamic_cast<Rect &>(*treasureHard[i]).isOverlapping(user)) {
                    treasureHard.erase(treasureHard.begin() + i);
                    pointsHard.pop_back();
                }
            }
            for (int i = 0; i < triangles.size(); i += 1) {
                if (dynamic_cast<Shape &>(*triangles[i]).isOverlapping(user)) {
                    screenDisp = loseScreen;
                }
            }
        }
    // if user wins or loses, send to winScreen or loseScreen respectively
    if (heartsEasy.empty()) {
        screenDisp = loseScreen;
    }
    else if (heartsMed.empty()) {
        screenDisp = loseScreen;
    }
   else if (heartsHard.empty()) {
       screenDisp = loseScreen;
   }
   if (treasureEasy.empty()) {
       screenDisp = winScreen;
   }

   if (treasureMed.empty()) {
       screenDisp = winScreen;
   }
   if (treasureHard.empty()) {
       screenDisp = winScreen;
   }
    if (user.isOverlapping(grass) && difficulty != 1) {
        screenDisp = loseScreen;
    }

}
    glFlush();  // Render now
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(skyBlue.red, skyBlue.green, skyBlue.blue, 1.0f);

}

// reference: http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // check if in game screen for this, and mouse as well, timer
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    // PRESS S TO START
    if (key == 115) {
        screenDisp = gameScreen;
        startTime = clock();
        // change screen color based on difficulty
        // If easy, set color to skyBlue.  If medium, set to purple. If hard, set to red
        if (difficulty == 2)
        {
            glClearColor(purple.red, purple.green, purple.blue, 1.0f);
        }
        else if (difficulty == 3)
        {

            glClearColor(.556863, 0.137255, 0.219608, 1.0f);
        }
        else
        {
            glClearColor(skyBlue.red, skyBlue.green, skyBlue.blue, 1.0f);;
        }
    }
    // p allows user to play again
    if (key == 112) {
        clock_t startTime;
        screenDisp = startScreen;
        // call init function again to reset everything
        init();
    }
    glutPostRedisplay();
}

// controls key arrow functions
void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            user.move(0,25);

            break;
        case GLUT_KEY_LEFT:
            user.move(-25,0);
            break;
        case GLUT_KEY_RIGHT:
            user.move(25,0);

            break;
        case GLUT_KEY_UP:
            user.move(0,-25);
            break;
    }

    glutPostRedisplay();
}

// cursor function, used for pressing buttons
void cursor(int x, int y) {
    if(easy.isOverlapping(x, y)) {
        easy.hover();
    }
    else if(medium.isOverlapping(x, y)){
        medium.hover();
    }
    else if(hard.isOverlapping(x, y)) {
        hard.hover();
    }
    else{
        easy.release();
        medium.release();
        hard.release();
    }
    glutPostRedisplay();
}


// mouse function used for mouse clicks
void mouse(int button, int state, int x, int y) {
    switch(button) {
        case GLUT_LEFT_BUTTON:
            switch (state) {
                case GLUT_DOWN:
                    easy.pressDown();
                    medium.pressDown();
                    hard.pressDown();
                    break;
            }
            easy.release();
            medium.release();
            hard.release();
            break;
    }

    // set difficulty based on which button was pressed
    switch(button) {
        case GLUT_LEFT_BUTTON:
            switch (state) {
                case GLUT_UP:
                    if(easy.isOverlapping(x, y)) {
                        difficulty = 1;
                    }
                    else if(medium.isOverlapping(x, y)){
                        difficulty = 2;
                    }
                    else if(hard.isOverlapping(x, y)) {
                        difficulty = 3;
                    }
                    break;
            }
            break;
    }
    glutPostRedisplay();
}

// timers to display movement for objects
void triangleTimer(int dummy){
    for (int i = 0; i < triangles.size(); i+=1) {
        dynamic_cast<Triangle &>(*triangles[i]).rotate(0,0, PI/100);
    }
    glutPostRedisplay();
    glutTimerFunc(50, triangleTimer, dummy);
}

void cloudEasyTimer(int dummy) {
    for (unique_ptr<Shape> &s : cloudsEasy) {
        // Move all the clouds to the left
        s->moveX(-1);
        // If a shape has moved off the screen
        if (s->getCenterX() < -20) {
            // Set it to the right of the screen so that it passes through again
            s->setCenterX(520);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, cloudEasyTimer, dummy);
}

void cloudMedTimer(int dummy) {
    for (unique_ptr<Shape> &s : cloudsMed) {
        // Move all the clouds to the left
        s->moveX(-1);
        // If a shape has moved off the screen
        if (s->getCenterX() < -20) {
            // Set it to the right of the screen so that it passes through again
            s->setCenterX(520);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, cloudMedTimer, dummy);
}
void cloudHardTimer(int dummy) {
    for (unique_ptr<Shape> &s : cloudsHard) {
        // Move all the clouds to the left
        s->moveX(-1);
        // If a shape has moved off the screen
        if (s->getCenterX() < -20) {
            // Set it to the right of the screen so that it passes through again
            s->setCenterX(520);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, cloudHardTimer, dummy);
}

void obstacleEasyTimer(int dummy) {
    int speed = pointsEasy.size() - 11;
    for (unique_ptr<Shape> &s : obstaclesEasy) {
        // Move all the obstacles to the left
        s->moveX(speed);
        // If a shape has moved off the screen
        if (s->getCenterX() < -20) {
            // Set it to the right of the screen so that it passes through again
            s->setCenterX(520);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, obstacleEasyTimer, dummy);
}

void obstacleMedTimer(int dummy) {
    int speed = pointsMed.size() - 11;
    for (unique_ptr<Shape> &s : obstaclesMed) {
        // Move all the obstacles to the left
        s->moveX(speed);
        // If a shape has moved off the screen
        if (s->getCenterX() < -20) {
            // Set it to the right of the screen so that it passes through again
            s->setCenterX(520);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, obstacleMedTimer, dummy);
}
void obstacleHardTimer(int dummy) {
    int speed = pointsHard.size() - 11;
    for (unique_ptr<Shape> &s : obstaclesHard) {
        // Move all the obstacles to the left
        s->moveX(speed);
        // If a shape has moved off the screen
        if (s->getCenterX() < -20) {
            // Set it to the right of the screen so that it passes through again
            s->setCenterX(520);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, obstacleHardTimer, dummy);
}

void treasureEasyTimer(int dummy) {

    int speed = pointsEasy.size() - 11;
    for (unique_ptr<Shape> &s : treasureEasy) {
        s->moveX(-speed);
        if (s->getCenterX() > 520) {
            s->setCenterX(-20);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, treasureEasyTimer, dummy);
}

void treasureMedTimer(int dummy) {

        int speed = pointsMed.size() - 11;
        for (unique_ptr<Shape> &s : treasureMed) {
            s->moveX(-speed);
            if (s->getCenterX() > 520) {
                s->setCenterX(-20);
            }
        }
        glutPostRedisplay();
        glutTimerFunc(50, treasureMedTimer, dummy);
}

void treasureHardTimer(int dummy) {

    int speed = pointsHard.size() - 11;
    for (unique_ptr<Shape> &s : treasureHard) {
        s->moveX(-speed);
        if (s->getCenterX() > 520) {
            s->setCenterX(-20);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, treasureHardTimer, dummy);
}

static void Timer(int value){
    glutPostRedisplay();
    // 100 milliseconds
    glutTimerFunc(100, Timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    //screenDisp = startScreen;
    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Game" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);


    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, triangleTimer, 0);
    glutTimerFunc(0, cloudEasyTimer, 0);
    glutTimerFunc(0, cloudMedTimer, 0);
    glutTimerFunc(0, cloudHardTimer, 0);
    glutTimerFunc(0, obstacleEasyTimer,0);
    glutTimerFunc(0, obstacleMedTimer, 0);
    glutTimerFunc(0, obstacleHardTimer, 0);
    glutTimerFunc(0,treasureEasyTimer,0);
    glutTimerFunc(0, treasureMedTimer, 0);
    glutTimerFunc(0, treasureHardTimer, 0);


    Timer(0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
