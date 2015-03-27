# Single String
C++ library that only creates a single copy of a given string.

Pretty simple, there is a string table that keeps a single copy of every string. This greatly reduces memory when you have LOTS of copies of the same string floating around.

Because of the use of a "global" string table, you need to ensure you call single_string::free_all() at the end of your program to free all the memory... or not, you're exiting anyway!
