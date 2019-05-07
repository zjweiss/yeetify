# yeetify
Yeetify is a humorous utility meant to turn the entirety of your C++ code into permutations of the word 'yeet'.

Inspired by [this reddit post](https://www.reddit.com/r/ProgrammerHumor/comments/bgdxwn/yeet/).

## Usage
First, the executable must be built, which can be done either by simply calling `make yeetify` if Make is installed, or `g++ yeetify.cpp -o yeetify` if it isn't. To use yeetify, simply call`yeetify path_to_file_without_extension`, assuming your file is a .cpp file. This works best if the file has spaces between each indivual token, but will work as long as there are no multiple-word quotes.

## How it works
The program iterates line-by-line, ignoring all `using`, `#define` or `#include` macros. It takes in each unique word/token and pairs it with a randomly generated permutation of the word 'yeet'. It then makes a copy of the original file and replaces each word with its counterpart (again, ignoring all directives).

## Sample Usage
Just like the inspiration, assume a file called `foo.cpp` that contains the following code:

```
#include <iostream>
int main ( )  
{
	std :: cout << "Yeet!" ;
	return 0 ;
}
```

Running `./yeetify foo`, we generate the file `foo_yeetified.cpp`:

```
#include  <iostream>

#define yE "Yeet!"
#define yEET (
#define yEEe )
#define yEEt 0
#define yET ::
#define yEe ;
#define yEtt <<
#define ye cout
#define yeE main
#define yeEe return
#define yee std
#define yetT {
#define yett }

yeE yEET yEEe 
yetT 
yee yET ye yEtt yE yEe 
yeEe yEEt yEe 
yett 
```
