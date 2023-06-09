##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## Color
##

HEADER = "\033[95m"
OKBLUE = "\033[94m"
OKCYAN = "\033[96m"
OKGREEN = "\033[92m"
WARNING = "\033[91m"
FAIL = "\033[93m"
ENDC = "\033[0m"
BOLD = "\033[1m"
UNDERLINE = "\033[4m"


def coloredPrint(response: str):
    """
    Print the response with a color depending on the response
    """
    if "ok" in response:
        print(OKGREEN, "| Receive: " + response, end=ENDC)
    elif "ko" in response:
        print(WARNING, "| Receive: " + response, end=ENDC)
    else:
        print(OKCYAN, "| Receive: " + response, end=ENDC)
