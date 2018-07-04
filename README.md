# BOMBERMAN
c program for bomberman game.
This program uses the library conio.h . so better use it in any onine c compiler.
The direct link is https://onlinegdb.com/H1bjvL5fX
Input format:
First enter the size of the board(size<=26)
Then enter the player location and key location (eg:GH && HI The player will be located on the board on G row and H column)
Enter the villain count and the villain's location
Enter the bricks count and thr brick's location
After that use the direction  keys to move . press enter after each key
W-move up
Q-left diagonal upward
E-right diagonal upward
A-move left
S-move down
D-move right
Z-left diagonal downward
X-Plant bomb or detonate bomb
C-right diagonal downward

Rules
1.you must move accordingly to take the key.Once the player reaches the key the player is considered to be the winner.
2.If the player reaches the location of the villain the player dies and loses the game.
3.If there is bricks the player cannot move to that location and the code prompts the user to enter the input again.
4.If the key is sorrounded by bricks or villains,the user can plant the bomb and detonate the bomb to break the bricks or kill the villains.
5.The code an plant only one bomb at a time and the blast radius is one unit on all the four directions.
