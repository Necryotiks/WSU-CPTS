import re
# help from Dr.Shakire
#Name: Elliott Villars
#Num:11463956
#Date:4-15-2018
#Platform:Gentoo Linux
#global variables
opstack = []  #assuming top of the stack is the end of the list
dictstack = []  #assuming top of the stack is the end of the list


#------- Operand Stack Operators --------------
#Pop a value from opStack.
def opPop():
    if len(opstack) > 0:
        x = opstack[len(opstack) - 1]
        opstack.pop(len(opstack) - 1)
        return x
    else:
        print("Error: opPop - Operand stack is empty")

#Push a value to opStack.
def opPush(value):
    opstack.append(value)

#Pop a value from dictStack.
def dictPop():
    if len(dictstack) > 0:
        dictstack.pop()
    else:
        print("Error: Pop - Operand stack is empty")

#------- Dict Stack Operators --------------
#pop the empty dictionary off the operand stack and push it on the dictStack
def dictPush(d):
    if isinstance(d,dict) or isinstance(d,tuple):
        dictstack.append(d)
    else:
        opPush(d)
        print("Error : DictPush - Expecting a dictionary on the top of the operand stack")
    
    
#add a variable definition to the top of the stack. Adds a new dictionary if the stack is empty. 
def define(name, value):
    if len(dictstack) > 0:
        dictstack[len(dictstack) - 1][name] = value
    else:
        newDict = {}
        newDict[name]= value
        dictPush(newDict)
def statDefine(name, value):
        newDict = {}
        newDict[name]= value
        return(newDict)

#search the dictStack for a variable or function (start searhing at the top of the stack)
def dynLookup(name):
    for d in reversed(dictstack):
        if(d.get("/" + name, 0)): ##append '/' to name
            return d["/" + name]
    return None
def statLookup(name):
    for d in dictstack:
        if(d[1].get("/" + name, 0)): ##append '/' to name
            return d[1]["/" + name]
     
def staticLink(name):
    if len(dictstack) == 0:
        return 0;
    for index, tuplePair in enumerate(reversed(dictstack)):
        try:
            tuplePair[1][name]#find index of 
            return (len(dictstack)-index)-1#flips index
        except:
            pass
    return (len(dictstack)-1)#element not found link to self
def staticPsDef():
    if len(opstack) > 1:
        value = opPop()
        name = opPop()
        if(isinstance(name,str)):
            x = statDefine(name, value)#make static define, return dict and add tuple metadata
            tup = (staticLink(name),x)
            dictPush(tup)
        else:
            print("Error: psDef - invalid name argument")
    else:
        print("Error: psDef - not enough arguments")
#------- Arithmetic Operators --------------
##pop 2 values from stack; check if they are numerical (int or float); add them; push the result back to stack. 
def add():
    if len(opstack) > 1:
        op1 = opPop()
        op2 = opPop()
        if((isinstance(op1,int) or isinstance(op1, float))
           and (isinstance(op2,int) or isinstance(op2,float))):
            opPush(op1+op2)
        else:
            print("Error: add - one of the operands is not a numberical value")
            opPush(op1)
            opPush(op2)             
    else:
        print("Error: add expects 2 operands")

##pop 2 values from stack; check if they are numerical (int or float); subtract them; push the result back to stack. 
def sub():
    if len(opstack) > 1:
        op1 = opPop()
        op2 = opPop()
        if((isinstance(op1,int) or isinstance(op1, float))
           and (isinstance(op2,int) or isinstance(op2,float))):
            opPush(op2-op1)
        else:
            print("Error: sub - one of the operands is not a numberical value")
            opPush(op1)
            opPush(op2)             
    else:
        print("Error: sub expects 2 operands")

##pop 2 values from stack; check if they are numerical (int or float); multiply them; push the result back to stack. 
def mul():
    if len(opstack) > 1:
        op1 = opPop()
        op2 = opPop()
        if((isinstance(op1,int) or isinstance(op1, float))
           and (isinstance(op2,int) or isinstance(op2,float))):
            opPush(op1*op2)
        else:
            print("Error: mul - one of the operands is not a numberical value")
            opPush(op1)
            opPush(op2)             
    else:
        print("Error: mul expects 2 operands")

##pop 2 values from stack; check if they are numerical (int or float); divide the top value with the other; push the result back to stack. 
def div():
    if len(opstack) > 1:
        op1 = opPop()
        op2 = opPop()
        if((isinstance(op1,int) or isinstance(op1, float))
           and (isinstance(op2,int) or isinstance(op2,float))):
            opPush(op2/op1)
        else:
            print("Error: div - one of the operands is not a numberical value")
            opPush(op1)
            opPush(op2)             
    else:
        print("Error: div expects 2 operands")
            
##pop 2 values from stack; check if they are numerical (int or float); calculate the mod; push the result back to stack.         
def mod():
    if len(opstack) > 1:
        op1 = opPop()
        op2 = opPop()
        if((isinstance(op1,int) or isinstance(op1, float))
           and (isinstance(op2,int) or isinstance(op2,float))):
            opPush(op2 % op1)
        else:
            print("Error: div - one of the operands is not a numberical value")
            opPush(op1)
            opPush(op2)             
    else:
        print("Error: div expects 2 operands")


#------- Array Operators --------------
#Pops an array value from the operand stack and calculates the length of it. Pushes the length back to the stack.
def length():
    if len(opstack) > 0:
        aInput = opPop()
        if(isinstance(aInput, list)):
            opPush(len(aInput))
        else:
           print("Error: length expects an array/list argument")
           opPush(aInput)
    else:
        print("Error: length - not enough arguments")
        
#Pops a array value and an index from the operand stack and pushes the value at the index position of the array onto the opStack
def get():
    if len(opstack) > 1:
        ind = opPop()
        aInput = opPop()
        if(isinstance(aInput,list) and isinstance(ind, int)):
            opPush(aInput[ind])
        else:
            print("Error: get expects a string and an integer argument")
            opPush(aInput)
            opPush(ind)
    else:
        print("Error: get - not enough arguments")

#not required for Spring2018
def forall():
    if len(opstack) > 1:
        fbody = opPop()
        aInput = opPop()
        if (isinstance(aInput, list) and isinstance(fbody, list)):
            for x in aInput:
                opPush(x)  # push the array element onto the stack
                interpretSPS(fbody)
        else:
            print("Error: forall expects an array and a codearray")
            opPush(aInput)
            opPush(fbody)
    else:
        print("Error: get - not enough arguments")




#------- Stack Manipulation and Print Operators --------------

#copies top element in opStack
def dup():
    if len(opstack) > 0:
        op1 = opPop()
        opPush(op1)
        opPush(op1)
    else:
        print("Error: dup - not enough arguments")

#pops an integer count from stack, copies count characters and pushes them back to stack. 
def copy():
    if(len(opstack) > 0):
        count = opPop()
        copyList = []
        for  x in range(0,count):
            copyList.append(opPop())
        for item in reversed(copyList):
            opPush(item)
        for item in reversed(copyList):
            opPush(item)
    else:
        print("Error: copy - not enough arguments")

#pops the top value from the operand stack
#the Postscript pop; doesn't return the popped value
def pop ():
    if (len(opstack) > 0):
        opPop()
    else:
        print("Error: copy - not enough arguments")

#clears the stack
def clear():
    del opstack[:]


#prints the stack
def stack():
    for item in reversed(opstack):
        print(item)
        
#swaps the top two elements in opStack
def exch():
    if len(opstack) > 1:
        op1 = opPop()
        op2 = opPop()
        opPush(op1)
        opPush(op2)
    else:
        print("Error: exch - not enough arguments")

#Pops 2 integer values m and n from stack, rolls the top m values n times (if n is positive roll clockwise, otherwise roll countercloackwise)
def roll():
    if len(opstack) > 1:
        n = opPop()
        m = opPop()
        copyList = []
        for x in range(0,m):
            copyList.append(opPop())
        if (n>0): 
            copyList[len(copyList):] = copyList[0:n]
            copyList[0:n]=[]
        else:
            copyList[:0]=copyList[n:]
            copyList[n:]=[]
       
        for x in reversed(copyList[0:]):
            opPush(x)
        del copyList[:]
          
    else:
       print("Error: roll - not enough arguments")



#creates a new empty dictionary  pushes it on the opStack
def psDict():
    if len(opstack) > 0:
        n = opPop() # n is the initial size of the dictionary ; discard      
        opPush({})
    else:
        print("Error: psDict - not enough arguments")

def begin():
    dictPush(opPop())

def end():
    dictPop()

    
#pops a name and a value from stack, adds the definition to the dictStack. 
def psDef():
    if len(opstack) > 1:
        value = opPop()
        name = opPop()
        if(isinstance(name,str)):
            define(name, value)
        else:
            print("Error: psDef - invalid name argument")
    else:
        print("Error: psDef - not enough arguments")
        
#------- Loop Operators --------------
#Part 2 - requirement
#for loop
def psFor():
    forBody = opPop()
    end = opPop()
    inc = opPop()
    begin = opPop()

    for x in range(begin,end,inc):
        opPush(x) #push the loop index onto stack at each iteration
        interpretSPS(forBody)
        
    
#------- Parsing Functions --------------        

def isInt(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

def constantArray(L):
    for i in L:
        if not isinstance(i,int):
            return False
    return True

def tokenize(s):
    retValue = re.findall("/?[a-zA-Z][a-zA-Z0-9_]*|[[][a-zA-Z0-9_\s!][a-zA-Z0-9_\s!]*[]]|[-]?[0-9]+|[}{]+|%.*|[^ \t\n]", s)
    return retValue


def groupMatching(it):
    res = []
    for c in it:
        if c=='}':
            return res
        elif c=='{':
            res.append(groupMatching(it))
        else:
            if isInt(c):
                res.append(int(c))
            elif isinstance(c, str):
                if c[0] == '[':  # token is an array constant ; remove () before pushing onto the stack
                    aList = c[1:-1].split(' ')
                    res.append([int(x) for x in aList])
                else:
                    res.append(c)
            else:
                res.append(c)
    return False


def parse(s):
    res = []
    it = iter(s)
    for c in it:
        if c=='}':  #non matching closing paranthesis
            return False
        elif  c=='{':
            res.append(groupMatching(it))
        else:
            if isInt(c):  
                res.append(int(c))
                #print(res)
            elif isinstance(c, str):
                if c[0] == '[':     #token is an array constant ; remove () before pushing onto the stack
                    aList = c[1:-1].split(' ')
                    res.append([int(x) for x in aList])
                else:
                    res.append(c)
            else:
                res.append(c)
    return res

#the main recursive interpreter function
def interpretSPS(tokenList,scope):
    #this dictionary holds all functions the user can call
    if scope == 'static':
        builtinFunctions = {
                "add":add,
                "sub":sub,
                "mul":mul,
                "div":div,
                "mod":mod,
                "length":length,
                "get":get,
                "dup":dup,
                "exch":exch,
                "pop":pop,
                "roll":roll,
                "copy":copy,
                "clear":clear,
                "stack":stack,
                "dict":psDict,
                "begin":begin,
                "end":end,
                "def":staticPsDef,
                "for":psFor}
    else:
        builtinFunctions = {
                "add":add,
                "sub":sub,
                "mul":mul,
                "div":div,
                "mod":mod,
                "length":length,
                "get":get,
                "dup":dup,
                "exch":exch,
                "pop":pop,
                "roll":roll,
                "copy":copy,
                "clear":clear,
                "stack":stack,
                "def":psDef,
                "for":psFor}
        #"forall":forall}

    for token in tokenList:
        if isinstance(token, int): #token is an integer constant
            opPush(token)
        elif isinstance(token, str): 
            if token[0] == '/' :  #token is a name
                opPush(token)
            else:
                func = builtinFunctions.get(token,None)  #token is a built-in function

                if func != None :
                        if scope != 'static':
                            func()
                        else:
                            func()
                else:       # token is not a fucntion, should be a variable lookup.
                    if scope =='static':
                        val = statLookup(token)
                    else:
                        val = dynLookup(token)
                    if isinstance(val,list):   #check if val is a code array, if so interpret the code array body.
                        if constantArray(val):
                            opPush(val)
                        else:
                            interpretSPS(val,scope)
                    elif val != None:           # the returned value is not a code array, should be a variable value; push it on the operand stack
                        opPush(val)
                    else:       #neither variable or function; couldn't find a value in dictStack. Give an error!
                        print("Error: Couldn't find " + token + " in the dictStack!")
        elif isinstance(token, list): #code array or constant array
            opPush(token)
        else:      #if none of the above give an error.
            print("Error: Undefined token  in input!")

#parses the input string and calls the recursive interpreter to interpret the program
def interpreter(s,scope):
    tokenL = parse(tokenize(s))
    interpretSPS(tokenL,scope)

#-- COPY FROM HERE------

def clearDictStack():
    global dictstack;
    dictstack = []

def main_part2():

    #---------Test Case 1 -------
    print('---------Test Case-1 (15%)-------')
    testcase1= """
    /x 4 def
    /g { x stack } def
    /f {/x 7 def g } def
    f
    """
    interpreter(testcase1,"static")
    stack()
    print(dictstack)
# 
# #---------Test Case 2a -------
    # print('---------Test Case-2a (15%)-------')
    # testcase2a = """
    # /L [4 3 2 1] def
    # /lengthL {L length 1 sub} def
    # /getL {L exch get} def
    # 0 1 lengthL {getL dup mul} for 
    # stack
    # """
    # interpreter(testcase2a)
    # #should print : 1 4 9 16
    # clear() #clear the stack for next test case
    # clearDictStack()
# 
# #---------Test Case 2b -------
    # print('---------Test Case-2b (5%)-------')
    # testcase2b = """
    # /L [4 3 2 1] def
    # /lengthL { [4 3 2 1] length 1 sub} def
    # /getL { [4 3 2 1] exch get} def
    # 0 1 lengthL {getL dup mul} for 
    # stack
    # """
    # interpreter(testcase2b)
    # #should print : 1 4 9 16
    # clear() #clear the stack for next test case
    # clearDictStack()
# 
# 
# #---------Test Case 3 -------
    # print('---------Test Case-3 (20%) -------')
    # testcase3 = """
     # /x 10 def 
     # /y 5 def
     # /f1 { x y 1 dict begin
                # /y /z y def x def
                # /x z def
                # x y sub
         # end} def 
     # f1 3 1 roll sub     
     # stack
    # """
    # interpreter(testcase3)
    # #should print 5  -5
    # clear() #clear the stack for next test case
    # clearDictStack()
# 
# #---------Test Case 4 -------
    # print('---------Test Case-4 (15%)-------')
    # testcase4 = """
        # /sum { -1 0 {add} for} def 
        # 0 
        # [1 2 3 4] length 
        # sum 
        # 2 mul 
        # [1 2 3 4] 2 get 
        # add  
        # stack 
    # """
    # interpreter(testcase4)
    # # should print 23
    # clear() #clear the stack for next test case
    # clearDictStack()
# 
# #---------Test Case 5 -------
    # print('---------Test Case-5 (15%) -------')
    # testcase5 = """
        # /a 2 def
        # /b 3 def
        # /f1 { 1 dict begin 
                # a 1 add /a exch def 
                # 2 dict begin 
                # a 1 sub /a exch def 
                # b 1 add /b exch def 
             # end
             # a b mul
             # end } def
        # f1
        # stack
    # """
    # interpreter(testcase5)
    # # should print 9
    # clear() #clear the stack for next test case
    # clearDictStack()
# 
    # print('---------Test Case-6 (15%) -------')
    # testcase6 = """
        # /x 2 def
        # /y 3 def
        # /fn { x y add
              # x y mul
        # } def
        # fn add 
        # stack
    # """
    # interpreter(testcase6)
    # print("---------------------------")
    # # should print 11
    # clear() #clear the stack for next test case
    # clearDictStack()

if __name__ == '__main__':
    main_part2()



