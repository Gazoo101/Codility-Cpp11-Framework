# Codility-Python-Framework

Given the prevalence of automated logic puzzle driven evaluation systems, I put together a simple C++ framework designed to run and test small functions.

Unless you are forced to code in C++, I highly recommend using the [Python-based version](https://github.com/Gazoo101/Codility-Python-Framework) instead. In most cases it's a more efficient use of your time.

## How To Use

The included [main.cpp](Codility-Cpp11-Framework/main.cpp) file demonstrates basic usage. By default, the framework will print the output of your test results (and input parameters) into Visual Studio's Output window. But adding a different output function is very straight-forward, as demonstrated in the excerpt from [main.cpp](Codility-Cpp11-Framework/main.cpp) below:

```C++
typedef std::vector<int> VectorInt;

auto helper = std::make_unique<TestHelper>();

helper->execute( ex1, 1 );
helper->execute( ex2, VectorInt{ 1, 2, 3, 4, 5 }, 1 );
helper->execute( ex2, VectorInt{ 1, 2, 3, 4, 5 }, 1 );
helper->execute( ex4, 1, 2, 3 );
helper->execute( ex5, "Foobar", VectorInt{ 1, 2, 3, 4, 5 }, VectorInt{ 6, 7, 8, 9, 0 } );
helper->execute( ex6, 101, VectorInt{ 1, 2, 3, 4, 5 }, VectorInt{ 6, 7, 8, 9, 0 } );
helper->execute( ex7, "Foobar" );

// Instantiate a helper with a different output function (to std::cout)
auto helperWithStdout = std::make_unique<TestHelper>( []( std::string const& str ) {
	std::cout << str << std::endl;
} );

helperWithStdout->execute( ex1, 1 );
helperWithStdout->execute( ex2, VectorInt{ 1, 2, 3, 4, 5 }, 1 );
```

## Version History

### 0.3

* Transitioned to CMake
* Simplified README.md
* Removed superflous comments
* Improved variable naming
* Removed superflous header
* Changed header-guards to pragma once

### 0.2

* Added link to simpler [Python version](Gazoo101/Codility-Python-Framework)

### 0.1

* Everything
