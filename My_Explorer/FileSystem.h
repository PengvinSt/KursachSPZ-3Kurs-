#pragma once
#include "windows.h"
#include <vector>
#include <string>

using namespace std;

namespace FileSystem
{
	/*
	*	Class used for getting info about files in directories
	*/
	class File
	{
	public:
		string name;
		string extension;
		string size;


		SYSTEMTIME time;

	private:
		File();

	public:
		File(const WIN32_FIND_DATA& data);
	};


	/*
	*	Class used for interaction with directories
	*/
	class Directory
	{
	private:
		string name = ""; // name of Directory

		Directory* parent = nullptr; // pointer to Parent directory

		vector<string> subDirectories; // list of subdirectories of current directory

		vector<File> files; // list of files of current directory

	private:

		Directory();

		void find_files();

	public:

		Directory(string name, Directory* parent);

		void Update();

		// Getters declaration

		vector<string> getDirs() const;
		vector<File> getFiles() const;

		File getFileInfo(string filename) const;

		string getName() const;
		string getPath() const;

		// End of getters declaration
	};

	/*
	* Namespace with helper methods
	*/
	namespace Utilities
	{
		// Returns a vector of names of logical drives on current machine
		vector<string> listDrives();


		void rectTransform(
			RECT& cRect,
			double left_scale,
			double top_scale,
			double right_scale,
			double bottom_scale
		);

		bool endWith(string str, string subStr);

		//--- Methods below returns non-zero value if falure acquired ---//

		bool openFile(string fileName);

		bool copyFile(string existingFileName, string newFileName);

		bool deleteFile(string fileName);

		bool changeFileName(string fileName, string newFileName);

		// Recursive deleting of directory
		bool deleteDirectory(Directory* pDir);

		// Recursive copying of directory
		bool copyDirectory(Directory* pDir, string newPath);

		// Uses copy and delete methods for replacing directory
		bool moveDirectory(Directory* pDir, string newPath);
	}
}
