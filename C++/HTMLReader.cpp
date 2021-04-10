#include "HTMLReader.h"

HTMLReader::HTMLReader(const char* filename)
{
	setFileName(filename);
}

void HTMLReader::setFileName(const char* filename)
{
	this->filename = filename;
}

void HTMLReader::setFileURL(const char* url)
{
	this->url = url;
}	

bool HTMLReader::FetchSite()
{
  CURL *curl;
  CURLcode res;
  FILE *fp;
  
  fp = fopen(this->filename, "wb");
  
  curl = curl_easy_init();
  if(curl)
  {
    curl_easy_setopt(curl, CURLOPT_URL, this->url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
    {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
              return 0;
    }
 
    curl_easy_cleanup(curl);
  }
  fclose(fp);
  return 1;
}

void HTMLReader::RemoveHeader()
{
  fstream input(this->filename, ios::in);
 
  string temp;
  for(string line; getline( input, line);)
  {
	WorkOnFile(line);
	temp.append(line);
  }
  input.close();
  fstream output(this->filename, ios::out);
  cout << temp << endl;
  output << temp;
  
  output.close();
}

void HTMLReader::WorkOnFile(string &html)
{
    while (html.find("<") != std::string::npos)
    {
        auto startpos = html.find("<");
        auto endpos = html.find(">") + 1;

        if (endpos != std::string::npos)
        {
            html.erase(startpos, endpos - startpos);
        }
    }
 
}

void HTMLReader::ProcHTML(const char* url)
{
	setFileURL(url);
	FetchSite();
	RemoveHeader();
}
