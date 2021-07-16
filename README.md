
<h2><b>ReadMe </b></h2>

Demo Video: https://youtu.be/5XdlVWGj1rw

This program uses GLUT and OpenGL, which should be installed prior to running. 
I have been running this program on Mac OS, however CMakeLists.txt should allow it to be run on Windows as well. 

This program is a graphical game involving a player object that is moved by the user via the arrow keyboard keys.
The goal of this game is to collect the treasure boxes while avoiding the obstacles. 

Upon running the program, a graphics window will appear prompting the user to choose a difficulty level.
The user selects either easy, medium, or hard, and then presses "s" to start the game. 

As stated before, the goal is to move the player and collect treasure while avoiding the obstacles.
The obstacles move across the screen to the left, while the treasure moves to the right.
The user has three lives, and each time they collide into an obstacle a life is lost.
The user loses the game if all three lives are lost. 
On easy, there are only five pieces of treasure to collect, while on medium and hard there are 10.
There are also only 15 obstacles on easy, while medium and hard have 30 and 35, respectively. 
The medium and hard difficulties also display "lava" on the bottom third of the screen.  If the user collides with this, they will lose the game instantly.
Hard also includes additional triangle obstacles, which will result in an instant loss if collided with.  
As the user collects treasure, the speed of both the treasure and the obstacles increases, making the game progressively more difficult.
Once the round is over, whether that be by collecting all the treasure and winning or losing all three lives and losing, the screen will 
display the time it took to complete the game and the option to press p and play again, which will take the user back to the initial screen where they can again choose a difficulty level.
They can also press esc to exit the game and close the window at this point or any point throughout the game.

