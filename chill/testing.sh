#!/bin/bash
# testing.sh - test script for chill program
# Usage: bash -v testing.sh >& testing.out

# --- Normal cases ---
#0 args: should show usage/help
./chill

#1 argum (temp): should prompt error
./chill 32

#2 args: typical case
./chill 32 10

#2 args with float input
./chill 32.5 12.3

#negative temperature with valid wind speed
./chill -10 15

#edge of valid temperature (-99F)
./chill -99 20

#edge of valid temperature (49.9F)
./chill 49.9 5

# --- Error cases ---
#too many args
./chill 30 10 5

#Temp out of range (>= 50)
./chill 55 10

#Temp out of range (< -99)
./chill -120 5

#Wind speed = 0 (invalid for formula)
./chill 30 0

#Negative wind speed
./chill 30 -5

#Non-numeric temperature
./chill abc 10

#non-numeric wind speed
./chill 32 def

#mixed non-numeric input
./chill hello world

