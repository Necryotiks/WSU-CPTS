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
        result  = op1 + op2
        opPush(result)  
def sub():
        op1 = opPop() 
        op2 = opPop() 
        result  = op1 - op2
        opPush(result)  
def mul():
        op1 = opPop() 
        op2 = opPop()
        result  = op1 * op2
        opPush(result)  
def div():
        op1 = opPop() 
        op2 = opPop() 
        result  = op1 / op2
        opPush(result)  
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
