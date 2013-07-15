#
# READ LEVEL WITH PYTHON
# Jeff Thompson | 2013 | www.jeffreythompson.org
#
# Launches a simple Python app that reads the nearby
# tiles as a debugging/cheating GUI :)
#
# Arguments:
# 1. serial port (to get, type "ls /dev/tty.*" into the Terminal)
# 2. port speed (default 9600)
#
# Based code by:
# Neil Gershenfeld
#
# Via this tutorial:
# http://web.media.mit.edu/~liningy/sub_work/lining.yao/design%20about/Tutorial_2.html

import serial, sys

# read arguments,
if (len(sys.argv) != 3):
   print "Arguments: ReadLevelWithPython.py serial_port port_speed"
   sys.exit()
port = sys.argv[1]
speed = int(sys.argv[2])

# setup serial connection
ser = serial.Serial(port,speed)
ser.setDTR()
ser.flushInput()

# read incoming serial data!
while True:							# run forever
   x = ser.readline()		# read line from Arduino
   print x							# print (easy)!