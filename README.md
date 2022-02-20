# 3D-Snake-Game-Final-Project

This project was written as the final project of 3D Animation course.

Game Description:
The game itself is built on a level system, there are 5 levels in total that you must pass to win the game. The purpose of the player is to collect as much money as he can possibly  without dying, dying is possible if you collide with an moving obstacle. Each level is unique in several aspects and that includes : amount of obstacles that are present and moving (increasment in each level), the tick that is reponsible for the object actions is decreased (For e.x if the score object has a tick of 500, then every 500 ticks it will change it's location to a random spot in the screen), making it a lot more challenging for the player.


----

This is a 3D snake game with the following features:

1.**skinning** - The movement of the snake is done by skinning. The logic starts by creating the 16 joints, each is seperated by 0.1 in the Z axis, we proceeded by calculating the weights for each vertice. Each joint is added to the data_list structure. On each step of the movement we calculate our new position for each joint according to the direction vector that is decided by the keyboard presses. The actual skinning is done by igl::dqs that is provided by the library. We defined the vT and vQ whereas vT is the positions of the joints and vQ is always the identity. igl::dqs gave us "U" which is a matrix that has the position of all the vertices after the dqs and utilized deform::skelton to find the new position of our joints and set their entries at data_list accordingly.

2.**camera** - by pressing shift+{ buttons the player can change the camera view to be on top of the head of the snake.
We utilized 3 core.camera_.. params, that includes : Camera_eye, camera_translate and camera_up. The camera_translation is the position of the camera which is also the 16th joint. The camera_eye is where the camera is looking at, we have decided to use the "direction" vector as the vector that decides which direction the camera looks at. This is the same vector that is defined upon pressing the movement buttons. (Right,left ... etc.)


3.**Collision detection** - we started by creating an AlignedBox3d for each of the joints (Defined by m, M in the code).  In total there are 16 boxes. We applied exactly the same logic as in assignment 2 but there is a small difference : Instead of generating a tree for the snake, we simply check our 16 generated boxes against the other object tree.  (Every other object besides the snake has it's own tree that is generated upon loading)

4.**Objects in the game** - There are 3 different type of objects in our game:
 
- **Health** - The helath object has a predefined tick that upon reaching it (modulo) changes it's location on the screen, location is also changed if the object is collided with the snake. The health object gives health to the snake(+10) and +5 money.

-**Score** - The score object has a predefined tick that upon reaching it (mudlo) changes it's location on the screen, location is also change dif the object is collided with the snake. This object gives score (+10)  +5 money.

- **Movable obstacles** - The movable obstacles are from the type cube.obj, They are moving according to a randomly generated **bezier curve**.  It starts by generating 4 points in the world, randomly, calculates it's curve in the same way that was taught in the class, proceeds by moving according to it. Whenever our moving obstacle reaches the 4th point it will go back to the first point and vice versa. Movable obstacles are meant to be challenging and upon collision they are decreasing health! so you must avoid them to win the game!


5.**Menu**-The game has 7 states (PLAY, PAUSED, MENU,LOST,NEXTLEVEL,STORE,WIN) - each state has it own menu. Each menu is fully interactive and allows the best user interaction that is possible. Each menu has it's own predefined purpose.
The game starts at the **"MENU"** menu which shows the high scores,tutorial and where the player can prcoeed and play the game by pressing the play button.

The **"PLAY"** menu has all the information the player needs during the game including : progress bar,health bar,total money collected at this level,total money until now ,snake speed and maximum health. It also have the option to pause the game ,start over ,go to the store or get back the the main menu . 

 The **PAUSED** menu appears when the user press pause during the game and its stopes all the objects movments .From the pause menu the player can continu the game,go to the store or go back to the main menu.
 
  The **NEXTLEVEL** menu appears when the user passes the level. The menu contains information about how much money the player collected in this level and the total amout.
  from this menu the player can continue to the next level,play again (replay the current level) or go back the main menu.
  
  The **LOST** menu appears when the user loses the level, from this menu the player can play again (replay the current level) or go back the main menu.
  
  The **WIN** menu appears when the user passes all the levels. The menu contains information about how much money the player collected in total.
  from this menu the player can replay the final level ,start a new game or go back the main menu.
  
  The **STORE** menu appears when the user presses the store button.The player can buy in the store with the money he colleted in previous levels (not including the current level he is on ). In the store the player can buy - speed for the snake,refilling of health and increasing max health.
  
------
  Additional Points:
  
  1. Moving the objects or the snake according to **Bezier curve** - Instead of using a simple/boring "velocity vector" we have decide to generate unique curves for each moving obstacle. There are 4 points in total that are generted for each moving obstacle. With those 4 points we calculate the curve move according to it.
  Whenever the curve is finished the object returns by the curve to the starting point and vice versa giving us a unique feeling in the game.
  2. **Cubemap** - We have added a cube map into the game and added mouse control to it, the cube map gives us an "unlimited" map feeling, the actual code is based on the opengl tutorial and utilizes 2 extra libraries that includes : glm and learnopengl.
  3.  **High score system** - A fully working highscore system that is based on JSON, each score upon level finish is saved into a .ini file in the same directory, any new record is saved and displayed at the menu. The highscore is based on the money that the player collects during the levels, and the amount he spents in the game store.
  4.  **Game Store** - The game store is in the game menu and is described above, allows you to buy stuff throughout the game levels to acheive an advantage. Each payment deducts money.
  5.  **Music** - For each action in the game we have predefined a music file that is played, for e.x: upon collision, upon failure of a level, upon game finish. We also have a main game tune. Music is achieved via utilization of a third party library and requires 3 dll's to be present.
  6.   **Interactive Menu**- that is described above and allows easy interaction with the game while maintaining simplicity.

