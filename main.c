
#include "dependencies/DoTheWord.h"
#include "dependencies/clinput.h"
#include "dependencies/CTextEngine.h"

DtwNamespace dtw;
CTextNamespace ctext;

#include "categories/categories.h"
#include "categories/categories.c"

int main(){

    dtw = newDtwNamespace();
    ctext = newCTextNamespace();

    DtwResource *database = dtw.resource.newResource("database");

    char *categorie_id = find_categorie_id_by_name(database,"Food");
    if(categorie_id){
        rename_categorie_by_id(database,categorie_id,"Test");
    }


    printf("id: %s",categorie_id);

    free(categorie_id);
    dtw.resource.commit(database);
    dtw.resource.free(database);
}