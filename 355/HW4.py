global opStack =[]
global dictStack = []
def opPop():
    return opStack.pop()
def opPush(value):
    opStack.append(value)  
def dictPop():
    return dictStack.pop()
def dictPush(d):
    dictStack.append(d)  
def add():
        op1 = opPop() 
        op2 = opPop() 
        try:
            result  = op1 + op2
            opPush(result)  
        except TypeError:
            print("Operand type mimatch")
def sub():
        op1 = opPop() 
        op2 = opPop() 
        try:
            result  = op1 - op2
            opPush(result)  
        except TypeError:
            print("Operand type mimatch")
def mul():
        op1 = opPop() 
        op2 = opPop()
        try:
            result  = op1 * op2
            opPush(result)  
        except TypeError:
            print("Operand type mimatch")
def div():
        op1 = opPop() 
        op2 = opPop()
        try:
        result  = op1 / op2
        opPush(result)  
        except ZeroDivisionError:
            print("Division by zero is not allowed!")
        except TypeError:
            print("Operand type mimatch")
def mod():
        op1 = opPop() 
        op2 = opPop() 
        result  = op1 % op2
        opPush(result)  
def lookup(name):
    try:
        temp = dictPop()
        print(temp[name])
    except:
        print("key not found")
def psDef():
    def define(name,value):
        d= dict(name,value)
        dictPush(d)
    nam = opPop()
    val = opPop()
    define(nam,val)
def dup():
    op1 = opPop() 
    opPush(op1)  
    opPush(op1)  
def exch():
    op1 = opPop() 
    op2 = opPop() 
    opPush(op2)  
    opPush(op1)  
def pop():
    print(opPop())
def stack():
    for i in reversed(opStack):
        print(i)
def clear():
    for i in opStack:
        opPop()
