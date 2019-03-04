# filler
Logical PvP game, a.k.a. modified Tetris

Purpose of the project is to create a filler player that can beat 
given list of default players (can be found in "./players" directory).

This player is named as "rsharipo.filler".

1st player's tetriminos are represented with "O" characters.
2nd player's tetriminos are represented with "X" characters.

```
Usage: ./filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]

   -t  | --timeset        timeout in seconds
   -q  | --quiet          quiet mode
   -i  | --interactive    interactive mode(default)
   -p1 | --player1        use filler binary as a first player
   -p2 | --player2        use filler binary as a second player
   -f  | --file           use a map file (required)
   -s  | --seed           use the seed number (initialization random) (man srand)
   
Usage example: ./filler_vm -f maps/map02 -p1 ./rsharipo.filler -p2 players/hcao.filler
```
