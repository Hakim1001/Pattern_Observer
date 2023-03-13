#include "editor.h"

Editor::Editor()
{

}
struct FileDate                                                       //Структура обозреваемого файла, с полями размера и его существоания
{
    bool operator!=( const FileDate& other )
    {
        if( this == &other )
        {
            return false;
        }
        return exists != other.exists || size != other.size;
    }

    bool exists;
    size_t size;
};
