#ifndef TESTHELPER_H_INCLUDED
#define TESTHELPER_H_INCLUDED

#include <vector>
#include <sstream>
#include <functional>

class TestHelper {
public:
	TestHelper();
	TestHelper( std::function<void( std::string const& str )>& printFunc );
	~TestHelper();

	template <typename Functor, typename... Ts>
	void execute( Functor&& f, Ts&& ... args );

private:

	std::ostringstream streamInputParams;
	std::ostringstream streamOutput;

	/* ---------- Printing Helper Functions ---------- */
	std::function<void( std::string const& str )> mPrintFunc;

	// Base case
	template <typename T>
	void printToStream( std::ostringstream& out, T t );

	// Specialization: Vector Input!
	template <typename T>
	void printToStream( std::ostringstream& out, std::vector<T> t );

	// Generic
	template <typename T, typename U, typename... Args>
	void printToStream( std::ostringstream& out, T t, U u, Args... args );

	// Vector specialization
	template <typename T, typename U, typename... Args>
	void printToStream( std::ostringstream& out, std::vector<T> t, U u, Args... args );

};

template <typename Functor, typename... Ts>
void TestHelper::execute( Functor&& f, Ts&& ... args )
{
	streamInputParams.clear();
	streamInputParams.str("");

	streamOutput.clear();
	streamOutput.str("");

	// Args
	printToStream( streamInputParams, args... );

	// Result
	printToStream( streamOutput, f( std::forward<Ts>( args )... ) );

	std::string completeOutput = "Input: " + streamInputParams.str() + " | Output: " + streamOutput.str();

	mPrintFunc( completeOutput );
}


/* ---------- Printing Helper Functions ---------- */
template <typename T>
void TestHelper::printToStream( std::ostringstream& out, T t )
{
	out << t;
}

template <typename T>
void TestHelper::printToStream( std::ostringstream& out, std::vector<T> t )
{
	out << "[";

	if ( t.size() ) {
		auto iter = std::ostream_iterator<T>( out, ", " );
		std::copy( t.begin(), t.end() - 1, iter );
		out << t.back();
	}

	out << "]";
}

template <typename T, typename U, typename... Args>
void TestHelper::printToStream( std::ostringstream& out, T t, U u, Args... args )
{
	out << t << ", ";
	printToStream( out, u, args... );
}

// Vector specialization
template <typename T, typename U, typename... Args>
void TestHelper::printToStream( std::ostringstream& out, std::vector<T> t, U u, Args... args )
{
	out << "[";

	if ( t.size() ) {
		auto iter = std::ostream_iterator<T>( out, ", " );
		std::copy( t.begin(), t.end() - 1, iter );
		out << t.back();
	}

	out << "], ";

	printToStream( out, u, args... );
}

#endif // TESTHELPER_H_INCLUDED