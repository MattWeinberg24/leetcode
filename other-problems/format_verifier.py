"""
A file is formatted correctly if each opening parenthesis:
(,{,[ is closed out with it's respective "closing" parenthesis: ),},].
The open bracket character ( matches ) on the same line,
however, { and [ may match over multiple lines. Incorrect data could look like:
"""

import sys
# import numpy as np
# import pandas as pd
# from sklearn import ...

stack = []
closing = [')', '}', ']']
brackets = {
    '(': ')',
    '{': '}',
    '[': ']'
}

success = True
for line in sys.stdin:
    if not success:
        break
    for c in line:
        # if opening bracket, add to stack
        if c in brackets:
            stack.append(c)
        # if closing bracket, test against top of stack
        elif c in closing:
            if c != brackets[stack.pop()]:
                success = False
                break
    # assuming '(' and ')' MUST match on the same line,
    # there must not be any '(' in the stack at this point.
    # if this is an incorrect interpretation, remove the below condition:
    if '(' in stack:
        success = False
        break


# if lingering open brackets
if len(stack) > 0:
    success = False

# evaluate result
if success:
    print("valid", end="")
else:
    print("invalid", end="")
