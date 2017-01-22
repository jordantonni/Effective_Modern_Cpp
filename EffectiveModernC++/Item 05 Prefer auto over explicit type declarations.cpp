/*
 * Prefer auto to explicit type declarations
 * 
 * Auto avoids accidently uninitialized variables, such as int, by forcing you to initialize at declaration.
 * Good for iterator types that are long.
 * Can hold closures, lambda expressions that are stored in variables, callable functions really!
 *      - std::function can hold a function object, function or closure also, but:
 *      - it uses more memory to do that and has it's own type, std::function
 *      
 *      - using auto to store a closure has the same type of the closure itself, and uses less memory!
 *      
 * Avoid type shortcuts: e.g.
 *  - Calling the size() method within vector<int> returns a nested ::size_type type, not an int or unsigned
 *      - Yet without auto you would just declare it like: unsigned int size = vec.size(). 
 *          - Bad if the width is not the same of both, also not portable!
 *          
 * - unordered_map<string, int>, iterating though each pair you might forget that the key in a hashmap is stored as const
 *  -> pair<const string, int>
 *  - auto does this for you
 *
 *
 * SUMMARY:
 *  - auto variables must be initialized at declaration
 *  - auto avoids type mismatches such as nested types and forgetting const in std data structures
 */
