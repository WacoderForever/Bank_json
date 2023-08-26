
#include "dependencies/DoTheWord.h"
#include "dependencies/cli_entry.h"

DtwNamespace dtw;
CTextNamespace ctext;
CliNamespace cli;

#include "declaration.h"
#include "definition.h"


int main(int argc , char **argv){

    dtw = newDtwNamespace();
    ctext = newCTextNamespace();
    cli = newCliNamespace();
    
    DtwResource *database = dtw.resource.newResource("database");
    CliEntry *entry = newCliEntry(argc,argv);

    char * option = cli.entry.get_str(entry,1,CLI_NOT_CASE_SENSITIVE);

    
    bool error = false;
    if(strcmp(option,"add-categorie") ==0){
        error = add_categorie(database,entry);
    }

    else if(strcmp(option,"remove-categorie") ==0){        
        error==remove_categorie(database,entry);
    }


    else{
        printf("option not in ('add-categorie','remove-categorie')\n");
    }

    if(!error){
        dtw.resource.commit(database);
    }
    cli.entry.free(entry);
    dtw.resource.free(database);
}