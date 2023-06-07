#!/bin/sh

if [[ ! $(black . --check -q) ]];
then
    echo "build ko"
    exit 1
else
    echo "build ok"
fi
