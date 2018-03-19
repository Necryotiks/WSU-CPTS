(*Name: Elliott Villars
  Date: 2/21/2018
  SID: 11463956
  OS: Gentoo Linux
  Environment: SML

  Collaborated with: Edgar Perez,Zaid,Sanskar*)
fun fold f base [] = base  
| fold f base (x::rest) = f x (fold f base rest)
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
fun zipTail [] (y::rest2)  = []
| zipTail (x::rest1) [] = []
| zipTail L1 L2 =
let
    fun tuplePair [] [] acc = acc
    | tuplePair (x::rest1) (y::rest2) acc = tuplePair rest1 rest2
    ((x,y)::acc)(*help from Edgar Perez and Zaid*) 
    | tuplePair x [] acc = acc
    | tuplePair [] y acc = acc
  fun rAppend ([],L1) = L1
    | rAppend (x::rest,L1) = rAppend(rest,x::L1)
  fun rev L1 = rAppend(L1,[])
    in
      rev (tuplePair L1 L2 [])
end

fun histogram [] = []
  | histogram (x::rest) = (x,countInList (x::rest) x)::(histogram rest) 
  (*need to remove extra values*)

fun deepSum [] = 0 
  | deepSum (x::rest) = 
  let fun tsum [] acc =acc
  | tsum (x::rest) acc = tsum rest (acc+x)in   
  (tsum x 0) + (deepSum rest)
  end

fun deepSumOption L1 = let fun optSum (NONE)(NONE) =(NONE)
  |optSum (SOME n) (NONE) = (SOME n)
  |optSum (SOME n) (SOME m) = SOME(n+m)
  |optSum (NONE) (SOME m) = (SOME m)
in fold optSum NONE (map (fold optSum NONE) L1)
end
(* help from Edgar Perez*)
fun unzip [] = [] 
  | unzip L1 = let 
    fun xzip (x,y) =x 
    fun yzip (x,y) = y 
  in
  (map xzip L1)::(map yzip L1)::[]
 end

datatype either= ImAString of string | ImAnInt of int
datatype eitherTree = eLEAF of either | eINTERIOR of
     (either*eitherTree*eitherTree)
     
fun eitherSearch (eLEAF(ImAnInt v)) n = (v=n)
  |eitherSearch (eLEAF (ImAString v))  n = false 
  |eitherSearch (eINTERIOR(v,l,r)) n = (eitherSearch l n) orelse (eitherSearch r
  n)
  (*HOW TO TREE*)
fun eitherTest () =
let 
  val test1 = eINTERIOR ((ImAString "cat"),(eLEAF (ImAnInt 11)),(eLEAF(ImAnInt
  11)));
  val test2 = eINTERIOR ((ImAString "dog"),(eLEAF (ImAnInt 77)),(eLEAF(ImAnInt
  77)));
  val test3 =  eINTERIOR ((ImAString "test"),(eLEAF (ImAnInt 11)),(eLEAF(ImAnInt 11)));
  val test4 = eINTERIOR ((ImAString "Hello_World"),test1,test2);
  val roottest = eINTERIOR((ImAString "I am root"),test3,test4);
in
  eitherSearch roottest 9
end


datatype 'a Tree = LEAF of 'a | NODE of ('a Tree) * ('a Tree)
datatype 'a myTree = myLEAF of 'a | myNODE of 'a*'a*('a myTree)*('a myTree)

fun findMin (LEAF v) = v
  | findMin (NODE (l, r)) = Int.min (findMin l, findMin r)
 fun findMax (LEAF v) = v 
   | findMax (NODE (l,r)) = Int.max(findMax l,findMax r)
   (*credit to
   https://stackoverflow.com/questions/48778265/how-to-find-the-min-and-max-values-of-a-tree-in-sml*)
fun minmaxTree (NODE(l,r)) = (myNODE(findMin
  (NODE(l,r)),findMax(NODE(l,r)),minmaxTree l, minmaxTree r))
  | minmaxTree (LEAF x) = (myLEAF x)
