#ifndef HTMLREADER_H
#define HTMLREADER_H
#include <string>
#include <curl/curl.h>
#include <iostream>
#include <fstream>

using namespace std;

class HTMLReader
{
public:
	HTMLReader(const char* filename);
	
	void ProcHTML(const char* url);
	
private:
	const char* filename;
	const char* url;
	
	void setFileName(const char* filename);
	void setFileURL(const char* url);
	const char* getFileURL() { return url; }
	const char* getFileName() { return filename; }

	bool FetchSite();
	void RemoveHeader();
	void WorkOnFile(string &html);
	//void SaveFile();
};

#endif
