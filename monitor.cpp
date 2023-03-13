#include "monitor.h"

Monitor::Monitor(const char* fileName):     //
monitor_fileName( fileName ),  prevFile( Check_file( monitor_fileName ) )
{

}


void Monitor::checkFile()
{
    File tmp_file = Check_file( monitor_fileName );
    if( tmp_file != prevFile )
    {
        notifyObservers( &File_observer::onFileChanged,tmp_file);
        prevFile =  tmp_file;
    }
}

File Monitor::Check_file( const std::string& fileName )
{
    File fileState;
    struct stat statBuf;
    fileState.exists = stat( fileName.c_str(), &statBuf ) == 0;
    fileState.size = fileState.exists ? statBuf.st_size : 0;
    return fileState;
}
