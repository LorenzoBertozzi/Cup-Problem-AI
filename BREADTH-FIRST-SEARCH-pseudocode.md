function BREADTH-FIRST-SEARCH(problem) returns a solution, or failure
 if problem's initial state is a goal then return empty path to initial state
 frontier ← a FIFO queue initially containing one path, for the problem's initial state
 reached ← a set of states; initially empty
 solution ← failure
 while frontier is not empty do
   parent ← the first node in frontier
   for child in successors(parent) do
     s ← child.state
     if s is a goal then
       return child
     if s is not in reached then
       add s to reached
       add child to the end of frontier
 return solution
