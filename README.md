# Codility-Python-Framework

Given the prevalence of automated logic puzzle driven evaluation systems, I thought it useful to put together a simple straight-forward interface to simplift the parts that really don't matter to the evaluators and generally help to test takers.

Unless you are forced to code in C++11, I will highly recommend using [Python-based version](Gazoo101/Codility-Python-Framework). In many cases it will be a more efficient use of your time.

## How To Use

The included [main.cpp](Codility-Cpp11-Framework/main.cpp) file demonstrates basic usage. By default, the framework will print the output of your test results (and input parameters) into Visual Studio's Output window. But adding a different output function is very straight-forward, as demonstrated in the excerpt from [main.cpp](Codility-Cpp11-Framework/main.cpp) below:

```C++
// Init Helper!
auto helper = std::make_unique<TestHelper>();

helper->execute( ex1, 1 );
helper->execute( ex2, std::vector<int> { 1, 2, 3, 4, 5 }, 1 );
helper->execute( ex3, std::vector<int> { 1, 2, 3, 4, 5 } );
helper->execute( ex4, 1, 2, 3 );
helper->execute( ex5, "Foobar", std::vector<int> { 1, 2, 3, 4, 5 }, std::vector<int> { 6, 7, 8, 9, 0 } );
helper->execute( ex6, 101, std::vector<int> { 1, 2, 3, 4, 5 }, std::vector<int> { 6, 7, 8, 9, 0 } );
helper->execute( ex7, "Foobar" );

// Instantiate a helper with a different output function (to std::cout)
auto helper2 = std::make_unique<TestHelper>( []( std::string const& str ) {
	std::cout << str;
} );

helper2->execute( ex1, 1 );
helper2->execute( ex2, std::vector<int> { 1, 2, 3, 4, 5 }, 1 );
```

## Version History


### 0.2

* Added link to simpler [Python version](Gazoo101/Codility-Python-Framework)

### 0.1

* Everything