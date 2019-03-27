#!/bin/bash
cat pipe1.txt | sed 's/peeps/pipes/g' pipe1.txt > pipenew.txt
