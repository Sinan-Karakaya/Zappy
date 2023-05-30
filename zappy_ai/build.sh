#!/bin/sh

if [[ $(black . --check) = 0 ]];
then
    echo "black check failed"
    exit 1
else
    echo "build ok"
fi
