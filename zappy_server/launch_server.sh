#!/bin/bash

# Set the command and arguments
command="./zappy_server"
args="-p $1 -x 10 -y 10 -n test -c 4 -f 1000"

# Launch the zappy_server
$command $args
