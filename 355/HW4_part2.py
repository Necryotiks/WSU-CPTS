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
           return d[name]
    return None
def get():
    string = opPop()
    ind = opPop()
    try:
        return(string[ind])
    except:
        print("element net parsed")
def length():
    string = opPop()
    opPush(len(string))
def psDef():
    def define(name,value): #protect against int keys
        d = {}
        d[name]=value
        dictPush(d)
    val = opPop()
    nam = opPop()
    if isinstance(nam,str):
        if nam[0] == '/':
             define(nam[1:], val)
    else:
        print("not str")
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
#==================================================================================================================
#part2
#==================================================================================================================
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
#creates code array
def parse(s):
    it = iter(s)
    parsedTokens = []
    for i in it:
        if i=='{':
            parsedTokens.append(groupMatching(it))
        elif i=='}':
            False
        else:
            parsedTokens.append(i)
    for i in parsedTokens:
        cArr.append(castToken(i))
#casts each token
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
        # helper
        it = iter(token)
        token = castList(it)
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
#loops through list making the necessary casts
def castList(it):
    res=[]
    for c in it:
        if isinstance(c,list):
           res.append( castList(c))
        else:
            try:   
                res.append(int(c))
            except:
                try:
                    res.append(float(c))
                except:
                    res.append(c)
    return res
def psFor():
    if len(opStack)< 4:
        print("insufficient elements")
        return
    cmd = opPop()
    end = opPop()
    step = opPop()
    start = opPop()
    if step > 0:
        end = end +1
    else:
        end =end -1
    for i in range(start,end,step):
        opPush(i)
        if i == 'add':
            if (isinstance(opStack[-1],int) == True and isinstance(opStack[-2],int) == True): 
                add()
            else: 
                print("command unable to be fufilled") #after ops flip and append command stack
                break
                
        elif i == 'sub': 
            if (isinstance(opStack[-1],int) == True and isinstance(opStack[-2],int) == True): 
                sub()
            else: 
                 #after ops flip and append command stack
                print("command unable to be fufilled") #after ops flip and append command stack
                break
        elif i== 'mul':
            if (isinstance(opStack[-1],int) == True and isinstance(opStack[-2],int) == True): 
                mul()
            else: 
                print("command unable to be fufilled") #after ops flip and append command stack
                break
                 #after ops flip and append command stack
        elif i== 'div':
            if (isinstance(opStack[-1],int) == True and isinstance(opStack[-2],int) == True): 
                div()
            else: 
                print("command unable to be fufilled") #after ops flip and append command stack
                break
                 #after ops flip and append command stack
        elif i == 'mod':
            if (isinstance(opStack[-1],int) == True and isinstance(opStack[-2],int) == True): 
                mod()
            else: 
                print("command unable to be fufilled") #after ops flip and append command stack
                break
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
            if (isinstance(opStack[-1],int) == True):
                square()     
            else: 
                print("command unable to be fufilled") #after ops flip and append command stack
                break
        elif i == 'dup':
            dup()
        elif i == 'get':
            get()
        elif i == 'length':
            length()
        elif i == 'for':
            psFor()
        else:
            print("Invalid command")
#moves elements from code array onto stack
def interpret():
    if len(cArr) != 0:
        opStack.append(cArr.pop(0))
        interpret()
#loop through stack trying to executu commands
def runLoop(cmd_buf):
    for j in range(len(opStack)-1):
     if len(opStack) != 0:
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
            if (isinstance(opStack[-1],int) == True and isinstance(opStack[-2],int) == True): 
                mod()
            else: 
                cmd_buf.append(i) #after ops flip and append command stack
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
            if (isinstance(opStack[-1],int) == True):
                square()     
            else: 
                cmd_buf.append(i) #after ops flip and append command stack
        elif i == 'dup':
            dup()
        elif i == 'get':
            get()
        elif i == 'length':
            length()
        elif i == 'for':
            psFor()
        else:
            if isinstance(i,int) == True:
                cmd_buf.append(i)
           #elif: #list go somewhere
            else:
                if isinstance(i,str) == True:
                     try:
                         x=lookup(i)
                         print(x)
                         for j in x:
                            opPush(x)
                     except:
                        cmd_buf.append(i)
                else:
                    cmd_buf.append(i)
    for x in reversed(cmd_buf):
        opPush(x)
    cmd_buf.clear()
#takes a raw string and parses it
def interpreter(rawStr):
    tokens = tokenize(rawStr)
    parse(tokens)
    interpret()
    cmd_buf =[]
    failsafe = 0
    while(len(opStack) >= 0):
        runLoop(cmd_buf)
        if failsafe > 61:
            break
        failsafe = failsafe +1
    print('\n')
    print(opStack)
    print(cmd_buf)
    print(dictStack)
# interpreter( 
        # """ 
# /square {dup mul} def 1 square 2 square 3 square add add 
# """)
# interpreter( #debug
        # """     
    # /fact{
    # 0 dict  
            # begin 
                    # /n exch def 
                    # 1
                    # n -1 1 {mul} for 
            # end 
    # }def 
    # [1 2 3 4 5] dup 4 get pop     
    # length
    # fact 
    # stack 
    # """ )
def testSix():
    interpreter(""" /x 3 def x""")
def testFive():
     parse(tokenize(""" /x 3 def x"""))
     print(cArr)
testSix()    
def testFour():
    parse(tokenize( #debug
        """     
    /fact{
    0 dict  
            begin 
                    /n exch def 
                    1
                    n -1 1 {mul} for 
            end 
    }def 
    [1 2 3 4 5] dup 4 get pop     
    length
    fact 
    stack 
    """ ))
    print(cArr)
def testThree():
    parse(tokenize("""      
    /sum { -1 0 {add} for} def  
    0
    [1 2 3 4] length 
    sum 
    2 mul     
    [1 2 3 4] 2 get 
    add add  
    stack 
    """))
    print(cArr)
    print(dictStack)
def testTwo():
    parse(tokenize("""     
/n  5 def 1 n -1 1 {mul} for      
""" ))
    print(cArr)
def testOne():
    parse(tokenize("""     
 /square {dup mul} def 1 square 2 square 3 square add add 
""" ))
    print(cArr)
#testOne()
testFour()
