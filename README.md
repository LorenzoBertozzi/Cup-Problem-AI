# Cup-Problem-AI
This is a resolucion of a class exercicie about BREADTH_FIRST_SEARCH and DEPTH-LIMITED-SEARCH

## The problens say

You have 3 gallons – A, B and C. Gallon A has 8 liters of capacity and is completely full of water. Gallon B has a capacity of 5 liters and is empty. Gallon C has 3 liters of capacity and is also empty. Without throwing away water, would you be able to ensure that, in the end, there would be exactly 4 liters of water left in gallon A and exactly 4 liters of water in gallon B?

-My inicial state is 
  i have my 3 cup, were the first with 8L of water capacity is full.
  (8,0,0)
  
![image](https://github.com/ReiDaBatata/Cup-Problem-AI/assets/37419347/ea6fcd14-d491-43a8-ae39-1b4392c5794a)

-From now on I need to change the water between the glasses until I get the desired state

![image](https://github.com/ReiDaBatata/Cup-Problem-AI/assets/37419347/ddc3ee2c-0617-44df-8c0f-9a89938c152c)

  to this, i create my function "GerarProxEstado", which means Generate-Next-State

-My goal state
  After make all transitions, we have
  (4,4,0)

![image](https://github.com/ReiDaBatata/Cup-Problem-AI/assets/37419347/824279f1-79f3-4e43-b0cf-a346d0237e04)
