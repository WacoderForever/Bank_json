
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
    
    CliEntry *entry = newCliEntry(argc,argv);


    if(entry->size <= 1){
        printf("option not provided\n");
        cli.entry.free(entry);
        return 1;
    }
    DtwResource *database = dtw.resource.newResource("data");

    char * option = cli.entry.get_str(entry,1,CLI_NOT_CASE_SENSITIVE);

    
    bool error = false;
    if(strcmp(option,"add-categorie") ==0){
        error = add_categorie(database,entry);
    }

    else if(strcmp(option,"remove-categorie") ==0){        
        error=remove_categorie(database,entry);
    }
    else if(strcmp(option,"rename-categorie")==0){
        error=rename_categorie(database,entry);
    }

    else{
        printf("option not in ('add-categorie','remove-categorie','rename-categorie')\n");
        error = true;
    }

    if(error == false){
        dtw.resource.commit(database);
        cli.entry.free(entry);
        dtw.resource.free(database);   
        return 0;
    }
    cli.entry.free(entry);
    dtw.resource.free(database);
    return 1;
}