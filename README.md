# 42-Filler
The goal of this project is to create an AI capable of beating other students in a game in which you need to be the last to put a piece on a board.  

Subject : [English](https://github.com/ssfar/42-Subjects.pdf/blob/master/filler.en.pdf) - [Français](https://github.com/ssfar/42-Subjects.pdf/blob/master/filler.fr.pdf)

Grade 100/100  
Bonus 25/25 :  
 :heavy_check_mark: Graphic interface (SDL2) | :heavy_check_mark: Bonus player

#### Objectives :
• Basic algorithm  
• Input/Output

#### Skills :
• Algorithms & AI  
• Unix  
• Rigor  

## How to use

#### pre-required : Make, GCC, SDL2 and SDL2_ttf

First of all, open a terminal, go into the project and build it :   
```  
make
```
### Input

The champion is now created but you need another one to compete with him, a map to place them and, a VM to run the game and distribute the pieces.
Luckily I included everything that is needed and given by 42 inside the ressources/ folder :
```  
./ressources/filler_vm -f the_map_file -p1 ./a_champion.filler -p2 ./a_champion.filler
```
The visu can be found inside the visualiser folder, he interprets the output of the given VM, to launch it just pipe it to the command :
```  
./ressources/filler_vm -f the_map_file -p1 ./a_champion.filler -p2 ./a_champion.filler | ./visu
```
#### Visu Controls : 
• Press ENTER to display the next step.  
• Maintain ENTER to watch the game unfold.  
• Click on the top left cross or press ESCAPE to quit.

### Output

#### Each turn, the VM displays the map followed by a randomly generated piece that the following champion to play will have to place :  
![Capture d’écran 2020-07-04 à 14 48 37](https://user-images.githubusercontent.com/45463065/86513616-f86c8280-be0b-11ea-8e1f-e097eac95fc9.png)

#### At the end the winner is the one who has the higher score :  

#### Here is a video showcasing the visualiser (speed x2 recommended):
[![Visu](https://user-images.githubusercontent.com/45463065/86514436-687e0700-be12-11ea-9a09-a82451b35aac.png)](https://www.youtube.com/watch?v=6d6l6l2jIoQ)

## How it works

### Rules  
The strategy behind my champion (ssfar.filler) is simple but effective, each time he receives a new piece, he gives a score to every empty block of the map (heatmap).  
The more the enemy's blocks surround an empty block, the higher his score will be.  
On the opposite, the more the friendly's blocks surround an empty block, the lower his score will be.  
I balanced the scoring to make sure to reward more than punish, I also limited the scope not too far from the empty blocks, which I will explain the reasons in a moment.  
Then, the program calculates a result score for each placing possibilities by adding up all the values of the empty blocks that the piece will fill out.  
Each time I try a new possibility, I compare the result with the previous best solution, if the new result is better, I update my variable containing the best solution score and the one containing the position of it.  

### Behavior  

In a game, my champion not seeing his ennemy (too far) will first place the pieces away from the one he already placed resulting in him to expand in all directions, forming vines like structures.
This behaviour makes him hard to circle.
By the time he reaches the enemy with one of his "vines" he will then be driven by two rules, go toward the enemy and expand from himself which will have the consequense of naturaly surrounding the enemy.
If the enemy tries to escape the trap he usally ges quickly caught by many other "vines".  

This life-like behaviors, which are the products of simple rules, are reminiscent of [the game of live](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).  

#### It also reminds me the blob : 
![blob](https://user-images.githubusercontent.com/45463065/86517105-6de54c80-be26-11ea-93a2-0b075904229c.jpg)







