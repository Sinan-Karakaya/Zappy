# Markdown Documentation AI

![ZAPPY !](../Zappy.webp "Zappy")

AI :robot: will be the the population of **Trantor**, called **Trantorians**

The AI :robot: of this project will be compose of one in multiple choices of **[Agent](#agent)**

## Summary

- **[Definition](#definition)**

- **[Classes](#classes)**

  - **[Agent :alien:](#agent)**
  - **[Parameters :gear:](#parameters)**
  - **[Server :information_source:](#server)**

## Definition

All the AI, no matter what Agent they have, will share these features/commands, here is a list of them:

| Action                       | Command          | Time Limit | Response                                       |
| ---------------------------- | ---------------- | ---------- | ---------------------------------------------- |
| Move up one tile             | Forward          | 7/*f*      | ok                                             |
| Turn 90° right               | Right            | 7/*f*      | ok                                             |
| Turn 90° left                | Left             | 7/*f*      | ok                                             |
| Look around                  | Look             | 7/*f*      | [tile1, tile2, ...]                            |
| Inventory                    | Inventory        | 1/*f*      | [linemate *n*, sibur *n*, ...]                 |
| Broadcast text               | Broadcast *text* | 7/*f*      | ok                                             |
| Number of team unused slots  | Connect_nbr      | -          | value                                          |
| Fork a player                | Fork             | 42/*f*     | ok                                             |
| Eject players from this tile | Eject            | 7/*f*      | ok/ko                                          |
| Death of a player            | -                | -          | dead                                           |
| Take object                  | Take *object*    | 7/*f*      | ok/ko                                          |
| Set object down              | Set *object*     | 7/*f*      | ok/ko                                          |
| Start incantation            | Incantation      | 300/*f*    | Elevation underway </br> Current level: k / ko |

</br>

## Classes

- ### Agent

  - **Description**

    This class manage the type and the nature of the AI :robot:, which will decide how they would act on the map.

    </br>

  - **List**

    | Name               | Description                                                                            |
    | ------------------ | -------------------------------------------------------------------------------------- |
    | Trantorian :alien: | Live a life of a basic *Trantorian* without particularities.                           |
    | Blocker 🧱          | Gather with other *Blockers* to block the access of places.                            |
    | Répétoile :star:   | Repeat **"Broadcast Hi!"** command to block the communications to other *Trantorians*. |
    | Pusher :fist:      | His unique goal is to push anyone who is on his way.                                   |

  - **Attributes**

        self.actions -> list of actions to send to the server
        self.inventory -> dictionnary that contains all the inventory of the *Trantorian*
        self.isDead -> boolean to see if the *Trantorian* is dead

</br>

- ### Parameters
  
  - **Description**
  
    This class manage if the parameters are in the good type and if there is no problem to launch the program.

    </br>

  - **Attributes**
  
        self.port -> the port use to communicate with the server
        self.host -> the ip address use to host to communicate with the server
        self.name -> the name of the team

    </br>

- ### Server

  - **Description**

    This class manage to send *messages / actions / commands* to the server and get the response from him.

    </br>

  - **Attributes**

        self.ip -> the ip address of the server
        self.port -> the port of the server
        self.socket -> the socket of the client

        def connect(self)
        // connect to the server with creating a socket

        def printResponse(self)
        // get and print the response from the server

        def getResponse(self)
        // get the response from the server

    </br>
