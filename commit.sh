#!/bin/bash
git add src/*.c
git add src/*.h
git add *.sh
git add config
git add configure.ac
git commit -m "$1"
