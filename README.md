# 42-Filler
This project consist of creating an AI capable of beating other student in a game where you need to be the last to place a piece on a board.

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

The champion is now created but you need an other one to compete whit him, a map to place them and a vm to run the game and distribute the pieces.
Luckily I included everything needed and given by 42 inside the ressources/ folder :
```  
./ressources/filler_vm -f the_map_file -p1 ./a_champion.filler -p2 ./a_champion.filler
```
The visu can be found inside the visualiser folder, he interpret the output of the given vm, to launch it just pipe it to the command :
```  
./ressources/filler_vm -f the_map_file -p1 ./a_champion.filler -p2 ./a_champion.filler | ./visu
```
#### Visu Controls : 
• Press ENTER to display the next step.  
• Maintain ENTER to watch the game unfold.  
• Click on the top left cross or press ESCAPE to quit.

### Output

#### The VM display each turn the map folowed by a randomly generated piece that the next champion to play will have to place :  
![Capture d’écran 2020-07-04 à 14 48 37](https://user-images.githubusercontent.com/45463065/86513616-f86c8280-be0b-11ea-8e1f-e097eac95fc9.png)

#### At the end the winner is the one who have the higher score :  

#### Here is a video showcasing the visualiser (speed x2 recommended):
[![Visu](https://user-images.githubusercontent.com/45463065/86514436-687e0700-be12-11ea-9a09-a82451b35aac.png)](https://www.youtube.com/watch?v=6d6l6l2jIoQ)

## How it works

### Rules  
The strategy behind my champion (ssfar.filler) is simple but effective, each turn when he receive a new piece, he give a score to every empty blocks of the map (heatmap).  
The more enemy's blocks surround an empty block, the higher his score will be,  
as opposite the more friendly's blocks surround an empty block, the lower his score will be.  
I have balanced this to make sure to reward more than I punish, I also have limited the scope of it not to far around the empty block, wich I will explain why in a moment.  
I then calculate one by one a result score for each placing possibilitys by adding up all the values of the empty blocks that the piece will fill.  
Each time i try a new possibility, I compare the result whit the previous best solution, if the new result is better, I update my variable containing the best solution score and the one containing the position of it.  

### Behavior  

In a game my champion not seeing his ennemy (too far) will first place the pieces away from the one he already placed resulting in him to expand in all directions, forming vines like structures.
This behaviour make him hard to circle.
By the time he reach the enemy whit one of his "vines" he will then be driven by two rule, go toward the enemy and exepend from himself wich will have the consequense of naturaly surrounding the enemy.
If the enemy try to escape the trap he usally get quickly caught by many others "vines".  

This life like comportment out of simple rules reminds me a lot [the game of live](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).  

#### It also make me think of the blob : 
![blob](https://user-images.githubusercontent.com/45463065/86517105-6de54c80-be26-11ea-93a2-0b075904229c.jpg)







