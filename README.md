# yeetify
Yeetify is a humorous utility meant to turn the entirety of your C or C++ code into permutations of the word 'yeet'.

Inspired by [this reddit post](https://www.reddit.com/r/ProgrammerHumor/comments/bgdxwn/yeet/).

## Installation
First, the executable must be built, which can be done by simply calling `g++ yeetify.cpp -o yeetify`. Once you compile, make sure to move the executable to your PATH.

## Usage
To use yeetify, simply call `yeetify file_path`, as long as the path is to a .c, .cc, or.cpp file. This will work best if the file has spaces between each individual token (e.g. brackets, operators, keywords, etc.), but will still work as long as there are no multiple-word quotes. 

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
