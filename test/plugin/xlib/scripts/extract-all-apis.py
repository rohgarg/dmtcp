#!/bin/python

import re

FILE = "/usr/include/X11/Xlib.h" #change the name of file here
FILE = "/usr/include/GL/glx.h" #change the name of file here
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

# Assumption: Each line is of the form 'extern returnType funcName(type1 /* var1 */, type2 /* var2 */...)
def prune_lines(linesList):
  apiList = []
  for line in linesList:
    line = re.sub(r'extern\s{1,}', r'', line) # remove the extern keyword
    line = re.sub(r'/\*', r'', line) # remove the start of a C comment /*
    line = re.sub(r'\*/', r'', line) # remove the end of a C comment */
    line = re.sub(r'\s{2,}', r' ', line)  # remove multiple spaces
    if not ("ARB" in line and "PROC" in line):
      apiList.append(line)
  return apiList

# Assumption: Each line is of the form 'extern returnType funcName(type1 /* var1 */, type2 /* var2 */...)
def tokenize_func_prototype(line):
  def getIdentifier(line):
    res = re.findall(r'\w+', line)
    if not res or len(res) < 2:
      return ("", None)
    tmp = re.search(res[-1]+'$', line) # FIXME: This is terrible.
    if not tmp:
      return ("", None)
    startPos = tmp.start()
    return (res[-1], startPos)

  funcName = ""
  returnType = ""
  args = []
  argTypes = []

  tokens = line.split(')')[0].split('(')
  (funcName, funcNameStart) = getIdentifier(tokens[0].strip())
  returnType = tokens[0][:funcNameStart].strip()
  argsList = tokens[1].split(',')
  for arg in argsList:
    (argName, argStart) = getIdentifier(arg.strip())
    argType = arg.strip()[:argStart]
    if not argType:
      assert(False)
    args.append(argName.strip())
    argTypes.append(argType.strip())

  return (returnType, funcName, argTypes, args)

def print_generated_code(apiList):
  # We cannot handle variable arguments, pre-processor macros, and func pointers
  #  for now.
  def is_special_case(argTypes):
    if ("..." in argTypes):
      return True
    return False

  def post_process(funcPrototype):
    funcPrototype = re.sub(r'#if NeedWidePrototypes', r'\n#if NeedWidePrototypes\n', funcPrototype)
    funcPrototype = re.sub(r'#ifdef ISC', r'\n#ifdef ISC\n', funcPrototype)
    funcPrototype = re.sub(r'#else', r'\n#else\n', funcPrototype)
    funcPrototype = re.sub(r'#endif', r'\n#endif\n', funcPrototype)
    return funcPrototype

  for line in apiList:
    funcPrototype = line.strip().split(';')[0]
    (returnType, funcName, argTypes, args) = tokenize_func_prototype(funcPrototype)
    print("#define _real_" + funcName + "    NEXT_FNC(" + funcName + ")")
  for line in apiList:
    funcPrototype = line.strip().split('_X_SENTINEL')[0].split(';')[0]
    (returnType, funcName, argTypes, args) = tokenize_func_prototype(funcPrototype)
    funcCallLine = "  "
    if not ("void" == returnType):
      funcCallLine += "return "
    if is_special_case(argTypes):
      funcCallLine += "_real_" + funcName + "(" + ",".join(args) + "NULL);"
    else:
      funcCallLine += "_real_" + funcName + "(" + ",".join(args) + ");"
    funcPrototype = post_process(funcPrototype)
    print("\n" + funcPrototype + " {");
    print("  DPRINTF(\""+ funcName +"()\\n\");");
    print(funcCallLine)
    print("}")


def main():
  print_generated_code(prune_lines(load_lines()))

main()
