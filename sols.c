#include "shell.h"
 
void lista( char dirs[] ) {

    DIR* directory;

    struct dirent* current;

    if( ( directory = opendir( dirs ) ) == NULL ){
        perror( "Ocorreu um erro ao executar a operação!" );
        exit( -1 );
    }else {
        while( ( current = readdir( directory ) ) != NULL ) {
            printf( "> %s\n", current->d_name );
        }
     }
}