#!/bin/bash

# Basic case: small numbers
echo "0 1 2 3 3 3 4 5" | ./histo

# Case: input requiring expansion
echo "1 2 15 16 17 50" | ./histo

# Large jump, forces multiple doublings
echo "150" | ./histo

# Mixed numbers and negatives
echo "-5 0 3 7 12 19 44 240" | ./histo

# Sequence 1..16 and 150
echo {1..16} 150 | ./histo
