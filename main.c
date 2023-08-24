
#include "dependencies/DoTheWord.h"
#include "dependencies/clinput.h"
#include "dependencies/CTextEngine.h"

DtwNamespace dtw;
CTextNamespace ctext;
CliInterface cli;

#include "declaration.h"
#include "definition.h"


int main(){

    dtw = newDtwNamespace();
    ctext = newCTextNamespace();
    cli = newCliInterface();
    DtwResource *database = dtw.resource.newResource("database");

    int option = cli.ask_option(&cli,"type the action","add-categorie | remove categorie");
    bool error = false;
    if(option == ADD_CATEGORIE){
        error = add_categorie(database);
    }


    if(!error){
        dtw.resource.commit(database);
    }
    
    dtw.resource.free(database);
}