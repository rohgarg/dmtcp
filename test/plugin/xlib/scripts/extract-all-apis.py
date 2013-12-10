#!/bin/python

FILE = "/usr/include/X11/Xlib.h" #change the name of file here
API_SIGNATURE = "extern"  # change the signature; GLAPI in case of gl.h
SEMI_COLON = ";"
OPEN_PAREN = "("
CLOSE_PAREN = ")"
PRE_PROCESSOR_MACRO = "#"

def load_lines():
  print("Loading lines from file: " + FILE)
  inFile = open(FILE)
  lines = inFile.readlines()
  numOfApis, numOfMultiLineAPI = 0, 0
  linesList = []
  for j in range(len(lines)):
    if (API_SIGNATURE in lines[j]) and not(PRE_PROCESSOR_MACRO in lines[j]) and (OPEN_PAREN in lines[j]):
      linesList.append(lines[j])
      numOfApis += 1
      addedOnce = False
      while j < len(lines) and not(SEMI_COLON in lines[j]):
        linesList[numOfApis-1] = linesList[numOfApis-1].strip() + lines[j+1].strip() # Put everything in a single line
        if not addedOnce:
          numOfMultiLineAPI += 1
          addedOnce = True
        j += 1
  print("Read " + str(numOfApis) + " APIs from the file.")
  print("#APIs split in multiple lines: " + str(numOfMultiLineAPI))
  return linesList

def prune_lines(linesList):
  return linesList

def print_list(apiList):
  for line in apiList:
    print(line.strip())

def main():
  print_list(prune_lines(load_lines()))

main()
