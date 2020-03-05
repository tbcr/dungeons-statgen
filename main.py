#Statgen: A statistics generator for Tabletop Roleplaying Challenges.
#By tbcr version 1.5
#Changelog:
#1.0) Original application writter in ANSI C
#1.0.1-1.4) Multiple changes to code to get it to work right.
#1.5) Rewrite to python to allow ability to create Qt application.

#Intended OS's are *nix, Win32, BSD and BeOS type OS

import time
import os
import math
import random
import random as rand

#Pre-processor Directive Hell

if os.name == 'posix':
    os.system("clear")
elif os.name == 'nt':
    os.system("cls")


#Main application

step = 1

for b in range(0,4):
    temp = b + step
    print("PLAYER " + str(temp))   
    print("STR: " + str(rand.randint(3,18))  )
    print("CON: " + str(rand.randint(3,18))  )
    print("CHA: " + str(rand.randint(3,18))  )
    print("WIS: " + str(rand.randint(3,18))  )
    print("INT: " + str(rand.randint(3,18))  )
    print("DEX: " + str(rand.randint(3,18)) + "\n")

