#DEPTH-LIMITED-SEARCH

##AIMA4e

function DEPTH-LIMITED-SEARCH(problem, l) returns a solution, or failure, or cutoff
     frontier ← a FIFO queue initially containing one path, for the problem's initial state
     solution ← failure
     while frontier is not empty do
           parent ← pop(frontier)
           if depth(parent) > l then
                solution ← cutoff
           else
                for child in successors(parent) do
                    if child is a goal then
                        return child
                    add child to frontier
 return solution