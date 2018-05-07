#Name: Elliott Villars
#Date: 3/12/2018 
#SID: 11463956
#OS: Gentoo Linux
#Collaborated with: Zaid,Ryle(?)

from functools import reduce          
import math
import sys
from collections import Counter
debug = True
def addDict(d):
    tempDict = {}
    for key in d.values():
        for x in key:
            tempDict[x] = key[x] + tempDict.get(x,0)
    return(tempDict)
def addDictN(L):    
    tempDict = {}
    for key in L:
        for key2 in key.values():
            for x in key2:
                tempDict[x] = key2[x] + tempDict.get(x,0)
    return(tempDict)
def testAddDict():
    dict1={'Mon':{'355':2,'451':1,'360':2},'Tue':{'451':2,'360':3},
    'Thu':{'355':3,'451':2,'360':3}, 'Fri':{'355':2},
    'Sun':{'355':1,'451':3,'360':1}}
    dict2 = [{'Mon':{'355':2,'360':2},'Tue':{'451':2,'360':3},'Thu':{'360':3}, 
    'Fri':{'355':2}, 'Sun':{'355':1}},
    {'Tue':{'360':2},'Wed':{'355':2},'Fri':{'360':3, '355':1}},
    {'Mon':{'360':5},'Wed':{'451':4},'Thu':{'355':3},'Fri':{'360':6}, 
    'Sun':{'355':5}}]
    print(addDict(dict1))
    print(addDictN(dict2))
def charCount2(my_str):
    result =[]
    result=(Counter(my_str).items())
    result = [i for i in result if i[0] != ' ']
    result = sorted(result,key=lambda tupl: tupl[1]) #from stack overflow
    return(result)
def charCount(my_str):
    result = []
    result =list((Counter(my_str).items()))
    for tup in result:
        if (tup[0] == ' '):
            result.remove(tup)
    result = sorted(result,key=lambda tupl: tupl[1]) #from stack overflow
    return(result)
def testCharCount():
    print(charCount('Cpts355---Assign1'))
    print(charCount('Cpts355 --- Assign1'))
    print(charCount('test')) 
def lookupVal(L,k):
    for item in reversed(L):
        try:
            return(item[k]) #hacky as all shit
            return
        except:
            pass
    return(None)
def lookupVal2(tL,k):
    for index,tupleDict in enumerate(reversed(tL)):
        try:
            return( tupleDict[1][k]) #hacky as all shit
            return
        except:
            pass
    return(None)
def testLookupVal():
    L1=[{"x":1,"y":True,"z":"found"},{"x":2},{"y":False}]
    L2=[(0,{"x":0,"y":True,"z":"zero"}),(0,{"x":1}),(1,{"y":False}),(1,{"x":3,"z":"three"}),(2,{})]
    print(lookupVal(L1,"x"))
    print(lookupVal(L1,"y"))
    print(lookupVal(L1,"z"))
    print(lookupVal(L1,"t"))
    print(lookupVal2(L2,"x"))
    print(lookupVal2(L2,"y"))
    print(lookupVal2(L2,"z"))
    print(lookupVal2(L2,"t"))
def funRun(d,name,args):
    try:
        command = d[name]
        return(command(*args)) #dereference array
    except TypeError:
        return("Wrong type")
    except:
        return("Exception caught!")
def testFunRun():
    functDict = {"add": lambda x,y: (x+y), 
            "concat3": lambda a,b,c:(a+","+b+","+c),
            "mod2": lambda n: (n % 2)}
    print(funRun(functDict, "concat3", ["one","two","three"])  )
    print(funRun(functDict, "mod2", [40])  )
    print(funRun(functDict, "add", [1,2])  )
    print(funRun(functDict, "add", [1]))
    print(funRun(functDict, "add", "cat"))
def numPaths(m,n):
    def factorial(n):
        if n <1:   
            return 1
        else:
            return n * factorial( n - 1 )  # recursive call
    check = (factorial(m-1 + n-1)/(factorial(m-1)*factorial(n-1))) #factorial is recursive
    return(check)
def testNumPaths():
    print( numPaths(3,3))
    print(numPaths(2,2))
    print(numPaths(1,2))
class iterSquares():#off stack overflow
    def __init__(self):
        self.current = 1
    def __next__(self):
        result = self.current
        self.current += 1
        result = result *result
        return result
    def __back__(self):
        result = self.current
        self.current -= 1
        result = result *result
        return result
    def __iter__(self):
        return self
def numbersToSum(iNumbers,acc):
    currentVal = []
    nextVal = 0
    if(acc <= 0):
        return currentVal
    while(True):
        if (sum(currentVal) >= acc):
            del currentVal[-1]
            iNumbers.__back__()
            return(currentVal)
        else:
            currentVal.append(iNumbers.__next__())
def testNumberToSum():
    squares = iterSquares()
    print(numbersToSum(squares,55) )
    print(numbersToSum(squares,100) )
class Stream(object):
    def __init__(self,first,compute_rest,empty=False):
        self.first = first
        self._compute_rest =compute_rest 
        self.empty= empty
        self._rest = None
        self._computed=False
    def __iter__(self):
        return self
    def rest(self):
        assert not self.empty,"Empty Stream"
        if not self._computed:
            self._rest = self._compute_rest()
            self._computed=True
        return self._rest
def streamSquares(f):
    def sqr():
        myList = range(10000000)
        for i in myList:
            yield i*i
    temp = sqr()
    L2 = [i for i in temp if i >=f]
    L2.append(f)
    L2.sort()
    return iter(L2)
def testStreamSquares(start,end):
    x = streamSquares(start)
    temp = x.__next__()
    while temp < end:
        print(temp)
        temp = x.__next__()
def evenSquares(f):
    def sqr():
        myList = range(10000000)
        for i in myList:
            yield i*i
    temp = sqr()
    L2 = [i for i in temp if i >=f]
    L2 = [i for i in L2 if i % 2 ==0]
    L2.append(f)
    L2.sort()
    return iter(L2)
def testEvenSquares(start,end):
    x = evenSquares(start)
    temp = x.__next__()
    while temp < end:
        print(temp)
        temp = x.__next__()

def main():
    print("********************")
    testAddDict()
    print("********************")
    testCharCount()
    print("********************")
    testLookupVal()
    print("********************")
    testFunRun()
    print("********************")
    testNumPaths()
    print("********************")
    testNumberToSum() 
    print("********************")
    testStreamSquares(1,1000)
    print("********************")
    testEvenSquares(1,1000)
if(debug):
    main()