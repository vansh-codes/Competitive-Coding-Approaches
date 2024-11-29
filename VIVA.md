## Segmented Sieve: TC: $O(N)$ SC: $O(N)$
## Sieve of Eratosthenes: $O(N*log(log(N)))$
## Sieve of Atkin: $(N / (log (log N)))$
#### Conditions for Sieve of Atkin
1. $4x^2+y^2 <= limit$ && $(n \% 12 == 1 || n \% 12 == 5)$
2. $3x^2+y^2 <= limit$ && $(n \% 12 == 7)$
3. $3x^2-y^2 <= limit$ && $(n \% 12 == 11)$


### Backtracking:
- Backtracking is a problem-solving algorithmic technique that involves finding a solution incrementally by trying different options and undoing them if they lead to a dead end. It is commonly used in situations where you need to explore multiple possibilities to solve a problem, like searching for a path in a maze or solving puzzles like Sudoku
  
##### Time Complexity of Backtracking algo's: 
- $O(K^N)$ (Exponential) or $O(N!)$ (Factorial)

### Memoization
- Memoization is an optimization technique primarily used to enhance the performance of algorithms by storing the results of expensive function calls and reusing them when the same inputs occur again
- Memoization is a top-down approach
- Caches the results of function calls
- Recursive implementation


### Tabulation
- Tabulation is a bottom-up approach where we store the results of the subproblems in a table and use these results to solve larger subproblems until we solve the entire problem
- Stores the results of subproblems in a table
- Iterative implementation