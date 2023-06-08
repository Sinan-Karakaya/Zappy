#!/bin/sh

echo -e "\e[1;35m### ZABUILD ###\e[0m"

echo -e "\n\e[1;33m  Norm checker:\n\e[0m"

black . --check

if [[ $? -eq 1 ]];
then
    echo -e "\n\e[1;31mZABUILD KO\e[0m"
    exit 1
fi

echo -e "\n\e[1;32m  Unit Tests:\n\e[0m"

./tests/zappy_server -f 200 & > /dev/null

coverage run -m unittest -vb tests/*Test.py

if [[ $? -eq 1 ]]
then
    echo -e "\n\e[1;31mZABUILD KO\e[0m"
    kill $(pgrep zappy_server)
    exit 1
fi

echo -e "\n\e[1;34m Coverage Tests:\e[0m\n"

coverage report -m

echo -e "\n\e[1;34mZABUILD OK!\e[0m\n"

rm -f .coverage

kill $(pgrep zappy_server)

exit 0
    