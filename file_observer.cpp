#include "file_observer.h"
#include "iostream"

void File_observer::onFileChanged( const File& state )           //Функция уведомления о произошедших изменениях в файле на вход поступает объект обозревамого файла
{
    std::cout << "********************" << std::endl;
    std::cout << "FILE STATE CHANGED: " << std::endl;
    std::cout << "  Exists: " << state.exists << std::endl;
    std::cout << "  Size: " << state.size << std::endl;
    std::cout << std::endl << std::endl;
}
