#ifndef FILE_OBSERVER_H
#define FILE_OBSERVER_H
#include <ifile_observer.h>
#include <iostream>
#include <string>
#include <file.h>
using namespace std;
class File_observer : public IFile_observer {
public:
    ~File_observer();
    void onFileChanged( const File& state );
    void File_Info(const File& state);
    void File_not_exist();

};

void File_observer::onFileChanged( const File& state ) {
    std::cout << "*****************" << std::endl;
    std::cout << "file was changed: "<< std::endl;
    std::cout << " File Exists "     << std::endl;
    std::cout << " Size: "<<state.size<< std::endl;
    std::cout << std::endl;
}
void File_observer::File_Info(const File& state)
{
    std::cout << "****************" << std::endl;
    std::cout << " File Exists "    << std::endl;
    std::cout << "  Size: " << state.size << std::endl;
    std::cout << std::endl;
}
void File_observer::File_not_exist()
{
    std::cout << "****************" << std::endl;
    std::cout << "File not exist " << std::endl;
    std::cout << std::endl;
}

File_observer::~File_observer() {
}
#endif // CONSOLEFILEOBSERVER_H
