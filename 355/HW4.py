opStack = []
dictStack = []
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
            result = (op1 * op2)
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
        try:
            result  = op1 % op2
            opPush(result)  
        except TypeError:
            print("Operand type mimatch")
def lookup(name):
    try:
        temp = dictPop()#fix
        print(temp[name])
    except:
        print("Key not found")
def psDef():
    def define(name,value):
        d= {name:value}
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
def copy(n):
    tempStack = []
    i = 0
    while(i < n):
        x = opPop()
        tempStack.append(x)
        ++i
    opStack.extend(tempStack)
    opStack.extend(tempStack)
def testAdd():   
    opPush(1)   
    opPush(2)   
    add()   
    if opPop() != 3: 
        return False      
    return True   
def testLookup():
    opPush("\n1")
    opPush(3)
    psDef()
    if lookup("n1") != 3:
        return False
    return True
def testSub():
    opPush(1)   
    opPush(2)   
    sub()   
    if opPop() != 1: 
        return False      
    return True   
def testMul():
    opPush(2)   
    opPush(2)   
    mul()  
    if opPop() != 4: 
        return False      
    return True   
def testDiv():
    opPush(3)   
    opPush(6)   
    div()  
    if opPop() != 2: 
        return False      
    return True   
def testMod():
    opPush(3)   
    opPush(6)   
    mod()  
    if opPop() != 0: 
        return False      
    return True   
print(testAdd())
print(testSub())
print(testMul())
print(testDiv())
print(testMod())
#print(testLookup()) #broke

