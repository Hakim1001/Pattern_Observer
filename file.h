#ifndef FILE_H
#define FILE_H


struct File {
    bool operator!=( const File& other )
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
#endif // FILE_H
