(*Name: Elliott Villars
  Date: 1/31/2018
  SID: 11463956
  OS: Gentoo Linux
  Environment: SML
  
  Collaborated with: Edgar Perez, Alexis, Samra, Parth and Sam Chen*)
val mlist = [1,2,3,4,5]
val duplist = [1,1,2,2,5,5,5,5,0,1,10]

(*#1*)
fun inList (x,L1) = if (null L1)  then false else if (hd L1) = x then true
                                                       else inList(x,tl L1)
(*a' specifies any input where a'' means the types must be comaprable i.e. not real numbers*)

(*#2*)
fun removeDuplicates [] = [] | removeDuplicates (x::rest) = if inList(x,rest) =
  true then removeDuplicates(rest) else x::(removeDuplicates(rest))
 

fun rev1 [] = [] | rev1(x::rest) = rev1(rest)@x

(*#3*)
fun listIntersect ([],[]) = [] | listIntersect([],L2) = [] | listIntersect(L1,[]) = [] |
  listIntersect(x::rest,L2) = if(inList(x,L2) = true) then 
    removeDuplicates(x::listIntersect(rest,L2)) else listIntersect(rest,L2)

(*#4*)
(* Help from Parth and Edgar*)
fun range min 0 max = []|range min step max = if min = max then [] else if min >
  max andalso step >0 then [] else if min < max andalso step >0 orelse min > max
  andalso step < 0 then min::(range(min+step) step max) else []

(*#5*)  
(*Help from Samra*)
fun numbersToSum sum [] = [] | numbersToSum sum (x::rest) = if x < sum then
  x::(numbersToSum(sum-x) rest) else numbersToSum(sum-x) rest 

(*#6*)  
(*Help from Alexis*)
fun replace index target [] = [] | replace index target (x::rest) = if index = 0 then target::rest else replace(index-1) target rest

(*#7*)
fun  groupRight gsize (x::rest) buf = if length buf = gsize then
 rev(buf)::groupRight gsize rest [x] else 
groupRight gsize rest (x::buf) | groupRight
gsize [] buf = [buf] 

fun groupNright x [] = [] | groupNright x L1 = groupRight x L1 []

(*Help from Edgar*)
fun reverse [] = []
|reverse (x::rest) = reverse (rest)@[x]
fun groupLeft v [] buf = [buf]
  | groupLeft v (x::rest) buf = if (length buf) = v 
                                then buf::(groupLeft v rest [x]) 
                                else groupLeft v rest ([x]@buf)
                                
fun groupNleft v [] = [[]]
| groupNleft v x = reverse(groupLeft v (reverse x) [])




