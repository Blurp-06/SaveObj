#ifndef SaveObj
#define SaveObj

#include <fstream>

namespace SaveObj
{

	/// <summary>
	///	This function will write the bytes of the object into a file.
	/// </summary>
	/// <typeparam name="T">A struct or class.</typeparam>
	/// <param name="object">The struct or class.</param>
	/// <param name="fileName">Name of the file to save to.</param>
	template<class T >
	void writeObject(T object, const char* fileName)
	{
		// Going to use it alot so I make it a variable.
		const int SIZE_OF_T = sizeof(T);

		// Making an array of bytes to write to file.
		char bytes[SIZE_OF_T];
		memcpy(bytes, &object, SIZE_OF_T);

		// Creating a file to write the bytes to.
		std::ofstream oFile;
		oFile.open(fileName, std::ios::binary);
		
		// Writing the bytes.
		for (int i = 0; i < SIZE_OF_T; i++)
		{
			oFile << bytes[i];
		}

		// Cleaning up because I am nice.
		oFile.close();
	}

	template<class T>
	T readObject(const char* fileName)
	{
		// Going to use it alot so I make it a variable.
		const int SIZE_OF_T = sizeof(T);

		// Creating the temporary variable for the struct and opening the file.
		T tmp;
		std::ifstream iFile;
		iFile.open(fileName, std::ios::binary);
		
		// Getting bytes from file.
		char* bytesBuffer = new char[SIZE_OF_T];
		iFile.read(bytesBuffer, SIZE_OF_T);
		memcpy(&tmp, bytesBuffer, SIZE_OF_T);

		// Cleaning up because I am nice.
		delete[] bytesBuffer;
		iFile.close();

		return tmp;
	}
}


#endif // !SaveObj
