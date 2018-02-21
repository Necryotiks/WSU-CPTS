fun inList (x,L1) = if (null L1)  then false else if (hd L1) = x then true
                                                       else inList(x,tl L1)
                                                       
fun removeDuplicates [] = [] | removeDuplicates (x::rest) = if inList(x,rest) =
  true then removeDuplicates(rest) else x::(removeDuplicates(rest))

fun len [] acc = acc
  | len(x::rest) acc = len rest (acc+1)

 fun countInList [] y = 0 
  | countInList (x::rest) y = len(List.filter(fn x => x=y) (x::rest)) 0 

(*fun zipTail [] (x::rest) = []
  | zipTail (x::rest) [] =[]
  | zipTail (x::rest1) (y::rest2) = (x,y)::(zipTail rest1 rest2) (*Not tail
  recursive*)*)
fun zipTail [] (y::rest2)  =[]
| zipTail (x::rest1) [] =[]
| zipTail (x::rest1) (y::rest2) =
let
    fun tuplePair (x::rest1) (y::rest2) [] = tuplePair rest1 rest2 ((x,y)::[])
    | tuplePair (x::rest1) [] [] = []
    | tuplePair [] [] [] = []
    | tuplePair [] (y::rest) [] = []
    in
     zipTail (x::rest1) (y:: rest2) = tuplePair rest1 rest2 ((x,y)::[])
end
(* Need to fix this*)

fun removeDupTuples ((x,y)::rest) = hd (List.filter(fn z => #1 z
  =x)rest)

fun histogram [] = []
  | histogram (x::rest) = (x,countInList (x::rest) x)::(histogram rest) (*need
  to remove extra values*)

fun tsum [] acc =acc
  | tsum (x::rest) acc = tsum rest (acc+x)  
fun deepSum [] = 0 
  | deepSum (x::rest) = (tsum x 0) + (deepSum rest)
 (*fun deepSumOption *)
fun xzip (x,y) =x
fun yzip (x,y) =y

fun unzip ((x,y)::rest) = (map xzip ((x,y)::rest))::(map yzip ((x,y)::rest))
  | unzip [] = []
(*RET: Types are wrong*)

datatype either= ImAString of string | ImAnInt of int
datatype eitherTree = eLEAF of either | eINTERIOR of
     (either*eitherTree*eitherTree)
fun eitherSearch eLEAF(v) = v
  |eitherSearch eLEAF (ImAString(v)) = v
  |eitherSearch eINTERIOR (ImAnInt(v),t1,t2) = eINTERIOR(v,eitherSearch
  t1,eitherSearch t2)
  |eitherSearch eINTERIOR (ImAString(v),t1,t2)= eINTERIOR(v,eitherSearch
  t1,eitherSearch t2)
  (*HOW TO TREE*)

datatype 'a Tree = LEAF of 'a | NODE of ('a Tree) * ('a Tree)
datatype 'a myTree = myLEAF of 'a | myNODE of 'a*'a*('a myTree)*('a myTree)

fun findMin (LEAF v) = v
  | findMin (NODE (l, r)) = Int.min (findMin l, findMin r)
 fun findMax (LEAF v) = v
   | findMax (NODE (l,r)) = Int.max(findMax l,findMax r)
