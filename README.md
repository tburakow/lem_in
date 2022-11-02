# lem_in

a Hive (42 school) project.

Algorithm project to calculate maximum flow in minimum time.

"Your ant colony must move from one point to another. How do you do it in the shortest time possible? This project will get you acquainted with graph traversal algorithms: your program will have to intelligently select paths and precise movements used by the ants."

## What I learned

- Theory and application of Ford-Fulkerson and Edmonds-Karp algorithms.
- Hash table creation and usage.
- Optimization of code for faster execution.
- Team-work.

## How to use

Make the executable:
```
make
```

run the executable with a .map -file of your choosing, for example:
```
./lem-in < augment0.map
```

The output will first show the number of ants, the rooms and the connections between the rooms, and (in the case of the augment0.map) a visual representation of the map.

the room after ## start is the starting position of the ants.

The room after ## end is the end (sink).

The next lines represent the moves made by the ants. The number before the dash is the identifier of the ant, and whatever comess after is the name of the room it moved into.

