#!/bin/bash

make re
make clean

# ------------------------------------ERRORS----------------------------------- 
printf "\033[1;32m----------------------------ERROR TEST----------------------------\n\n\033[1;0m"

printf "\033[1;33m--------------RUNNING A MAP WITH NO EXTENSION .BER --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./so_long ./maps/map.bra \n\033[1;0m"
./so_long ./maps/map.bra

printf "\n\033[1;33m--------------RUNNING A MAP WITH LINES THAT ARE NOT SAME LENGTH --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./so_long ./maps/map_wrong_length.ber \n\033[1;0m"
./so_long ./maps/map_wrong_length.ber


printf "\n\033[1;33m--------------RUNNING A MAP WITH MISSING SURRONDING WALLS --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./so_long ./maps/map_no_walls.ber \n\033[1;0m"
./so_long ./maps/map_no_walls.ber

printf "\n\033[1;33m--------------RUNNING A MAP WITH MISSING COLLECTIBLES (C) item --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./so_long ./maps/map_no_collectibles.ber \n\033[1;0m"
./so_long ./maps/map_no_collectibles.ber

printf "\n\033[1;33m--------------RUNNING A MAP WITH MISSING EXIT (E) item --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./so_long ./maps/map_no_exit.ber \n\033[1;0m"
./so_long ./maps/map_no_exit.ber

printf "\n\033[1;33m--------------RUNNING A MAP WITH MISSING DEPARTURE POSITION (P) item --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./so_long ./maps/map_no_position.ber \n\033[1;0m"
./so_long ./maps/map_no_position.ber

printf "\n\033[1;33m--------------RUNNING A MAP TOO BIG FOR SCREEN RESOLUTION --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./so_long ./maps/map_no_position.ber \n\033[1;0m"
./so_long ./maps/map_xlarge.ber

# ------------------------------------VERIFICATIONS----------------------------------- 
printf "\033[1;32m----------------------------FD STILL OPEN TEST----------------------------\n\n\033[1;0m"

printf "\033[1;33m--------------MAKING SURE THAT NO FD IS STILL OPEN --------------\n\033[1;0m"
printf "\033[1;31m--------------FD OPEN SHOULD BE 3 (STD)--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH valgrind --track-fds=yes ./so_long ./maps/map_small.ber \n\033[1;0m"
valgrind --track-fds=yes ./so_long ./maps/map_small.ber || grep 'FILE DESCRIPTORS'


printf "\033[1;32m----------------------------LEAKS----------------------------\n\n\033[1;0m"

printf "\033[1;33m--------------MAKING SURE THAT NO FD IS STILL OPEN --------------\n\033[1;0m"
printf "\033[1;31m--------------FD OPEN SHOULD BE 3 (STD)--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH valgrind --track-fds=yes ./so_long ./maps/map_small.ber \n\033[1;0m"




# ------------------------------------REGULAR TESTS----------------------------------- 
printf "\033[1;32m----------------------------REGULAR TESTS GAME RESPECTING REQUIREMENTS----------------------------\n\n\033[1;0m"

printf "\033[1;33m--------------RUNNING A SMALL HORIZONTAL MAP WITH CORRECT REQUIREMENTS --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./so_long ./maps/map_small.ber \n\033[1;0m"
./so_long ./maps/map_small.ber

sleep 2
printf "\033[1;33m--------------RUNNING A SMALL VERTICAL MAP WITH CORRECT REQUIREMENTS --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./so_long ./maps/map_small.ber \n\033[1;0m"
./so_long ./maps/map_vertical.ber

sleep 2
printf "\033[1;33m--------------RUNNING A LARGE MAP WITH CORRECT REQUIREMENTS --------------\n\033[1;0m"
printf "\033[1;31m--------------SHOULD BE AN ERROR--------------\n\033[1;33m"
printf "\033[1;34mSCRIPT TEST IS DONE WITH ./so_long ./maps/map_large.ber \n\033[1;0m"
./so_long ./maps/map_large.ber

make fclean