#include "data_file.h"

ata_File::Dta_File()
{

}
void ata_File::onFileChanged()
{
    if(this->exist)
    {
        if(this->file_size>0)
        {
            qDebug() <<file_size;
        }
    qDebug() <<"file changes";
    }
    else
    {
        qDebug()<<"File does not exist";
    }
    qDebug() <<;
    qDebug() <<;
}
