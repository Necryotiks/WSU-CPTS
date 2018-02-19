fun inList (x,L1) = if (null L1)  then false else if (hd L1) = x then true
                                                       else inList(x,tl L1)
                                                       
fun removeDuplicates [] = [] | removeDuplicates (x::rest) = if inList(x,rest) =
  true then removeDuplicates(rest) else x::(removeDuplicates(rest))

 fun countInList [] y = 0 
  | countInList L1 y = List.length(List.filter(fn x => x=y) L1) (* Not tail
  recursive*)

fun zipTail [] (x::rest) = []
  | zipTail (x::rest) [] =[]
  | zipTail (x::rest1) (y::rest2) = (x,y)::(zipTail rest1 rest2) (*Not tail
  recursive*)
  
fun histogram [] = [] 
  | histogram (x::rest) = (x,(countInList (x::rest) x))::histogram
  rest(*UNFINISHED*)

fun deepSum [] =[] 
  | deepSum (x::rest) = (map (fn z => z+y) x) + deepSum rest
