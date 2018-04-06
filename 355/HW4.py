#Elliott Villars
#help from Zaid,Stack Overflow
#3/26/18
import time
import re
opStack = []
dictStack = []
cArr = []
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
            result  = op2- op1
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
            result  = op2 / op1
            opPush(result)  
        except ZeroDivisionError:
            print("Division by zero is not allowed!")
        except TypeError:
            print("Operand type mimatch")
def mod():
        op1 = opPop() 
        op2 = opPop() 
        try:
            result  = op2 % op1
            opPush(result)  
        except TypeError:
            print("Operand type mimatch")
def lookup(name):
    for d in dictStack:
        #Help from Zaid;;
        if (name in d)== True:
           return d.get(name)
    return None
def get():
    string = opPop()
    ind = opPop()
    return(string[ind])
def length():
    string = opPop()
    opPush(len(string))
def psDef():
    def define(name,value):
        d = {}
        d[name]=value
        dictPush(d)
    val = opPop()
    nam = opPop()
    if nam[0] == '/':
        define(nam, val)
def testPsDef():
    opPush("/x")
    opPush(10)
    psDef()
    print(dictStack)

def roll():
    x=opPop()
    opstack.insert(0,x)
def square():
    op1 = opPop() 
    try:
        result  = op1 * op1
        opPush(result)  
    except TypeError:
        print("Operand type mimatch")
def fact():
    op1 = opPop()
    try:
        result = math.factorial(op1)
        opPush(result)
    except TypeError:
        print("Operand type mimatch")
def dup():
    op1 = opPop() 
    opPush(op1)  
    opPush(op1)  
def exch():
    op1 = opPop() 
    op2 = opPop() 
    opPush(op1)  
    opPush(op2)  
def pop():
    print(opPop())
def stack():
    for i in reversed(opStack):
        print(i)
def clear():
    opStack.clear()
def end():
    dictPop()
def begin():
    x = opPop()
    if  isinstance(x, dict) == True:
        dictPush(x)
    else:
        print("Not a Dict")
def psDict():
    myDict={}
    opPop()
    opPush(myDict)   

def copy(n): #fix
    tempStack = []
    i = 0
    while(i < n):
        x = opPop()
        tempStack.append(x)
        ++i
    opStack.extend(tempStack)
    opStack.extend(tempStack)
def testPsDef2():
    opPush("/x")
    opPush(10)
    psDef()
    opPush(1)
    psDict()
    begin()
    end()
    print(dictStack)
def testAdd():   
    opPush(1)   
    opPush(2)   
    add()   
    if opPop() != 3: 
        return False      
    return True   
def testLookup():
    opPush("/n1")
    opPush(3)
    psDef()
    if lookup("n1") != 3:
        return False
    return True
def testSub():
    opPush(10)   
    opPush(4.6)   
    sub()   
    if opPop() != 5.4: 
        return False      
    return True   
def testMul():
    opPush(2)   
    opPush(4.5)   
    mul()  
    if opPop() != 9: 
        return False      
    return True   
def testDiv():
    opPush(15)   
    opPush(5)   
    div()  
    if opPop() != 3: 
        return False      
    return True   
def testMod():
    opPush(10)   
    opPush(3)   
    mod()  
    if opPop() != 1: 
        return False      
    return True   
def testGet():
    opPush(0)
    opPush("cat")
    if get() != "c": 
        return False      
    return True   

def testLength():
    opPush("cat")
    length()
    if opPop() != 3: 
        return False      
    return True   
def testDup():   
    opPush(6)  
    dup()
    opPop()
    if opPop() != 6: 
        return False      
    return True   

def testExch():   
    opPush(6)  
    opPush(3)  
    exch()
    if opPop() != 6: 
        return False      
    return True   
def testRoll():
    opPush(1)
    opPush(2)
    opPush(3)
    if(opStack[1] == 1):
        return True
    return False
def testStack():
    stack()
def tokenize(s):  
    retValue = re.findall("/?[a-zA-Z][a-zA-Z0-9_]*|[[][a-zA-Z0-9_\s!][a-zA-Z0-9_\s!]*[]]|[-]?[0-9]+|[}{]+|%.*|[^ \t\n]", s)
    return retValue
def groupMatching(it):
    res=[]
    for c in it:
        if c=='}':
            return res
        elif c == '{':
            res.append(groupMatching(it))
        else:
            res.append(c)

def group(s):
    it = iter(s)
    parsedTokens = []
    for i in it:
        if i=='{':
            parsedTokens.append(groupMatching(it))
        elif i=='}':
            False
        else:
            parsedTokens.append(i)
    return parsedTokens

def castToken(token):
    # if token[0] == '[':
        # token = token[1:]
        # tmp =[]
        # for index in range(0, len(token)):
             # item = castToken(token[index])
             # tmp.append(item)
        # return tmp
    #ugly duct tape solution from stack overflow
    if isinstance(token,list):
        return token
    if token[0]== '[':
        it = iter(token[1:])
        temp =[]
        for i in it:
            if i == ']':
                temp = [i for i in temp if i != ' ']
                temp = list(map(int,temp))
                return temp
            else:
               temp.append(i)

    try:
        return(int(token))
    except ValueError:
        try:
            return(float(token))
        except:
            return(token)
tokens=( ['/fact', '{',    '0'  , 'dict','begin','/n', 'exch', 'def', '1',    'n'  ,  '(' ,'−1', '1',  '{',    'mul    ', '}', 'for','end','}', 'def' , '[1 2 3 4 5]', 'dup', '4', 'get', 'pop', ')' ,'length', 'fact', 'stack'])

def psFor():
    print()
def parse(tokens):
    for i in tokens:
        #temp = tokenize(i)
        # temp=tokenize(i)
        # if temp[0]== '{':
            # temp[0]= '['
        # elif temp[0]== '}':
            # temp[0]= ']'
        # #cArr.append(temp.pop())
        cArr.append(castToken(i))
    return cArr
def interpret(cArr):
    if len(cArr) != 0:
        opStack.append(cArr.pop(0))
        interpret(cArr)
def interpreter(rawStr):
    tokens = tokenize(rawStr)
    tokens = group(tokens)
    parse(tokens)
    interpret(cArr)
    cmd_buf =[]
    while(len(opStack) > 2):
        i= opPop()
        if i == 'add':
            if (isinstance(opStack[-1],int) == True and isinstance(opStack[-2],int) == True): 
                add()
            else: 
                cmd_buf.append(i)
        elif i == 'sub': 
            if (isinstance(opStack[-1],int) == True and isinstance(opStack[-2],int) == True): 
                sub()
            else: 
                cmd_buf.append(i) #after ops flip and append command stack
        elif i== 'mul':
            if (isinstance(opStack[-1],int) == True and isinstance(opStack[-2],int) == True): 
                mul()
            else: 
                cmd_buf.append(i) #after ops flip and append command stack
        elif i== 'div':
            if (isinstance(opStack[-1],int) == True and isinstance(opStack[-2],int) == True): 
                div()
            else: 
                cmd_buf.append(i) #after ops flip and append command stack
        elif i == 'mod':
            mod()
        elif i == 'stack':
            stack()
        elif i == 'length':
            length()
        elif i == 'dict':
            psDict()
        elif i == 'def':
            psDef() 
        elif i == 'begin':
            begin()
        elif i == 'end':
            end()
        elif i == 'exch':
            exch()
        elif i == 'roll':
            roll()
        elif i == 'pop':
            pop()
        elif i == 'square':
            square()     

interpreter( 
    """ 
/square {dup mul} def 1 square 2 square 3 square add add 
""")
stack()
