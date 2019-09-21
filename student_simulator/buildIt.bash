#!/bin/bash

gcc main.cpp -c
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
