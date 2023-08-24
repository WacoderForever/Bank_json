
#include "dependencies/DoTheWord.h"
#include "dependencies/clinput.h"
#include "dependencies/CTextEngine.h"

DtwNamespace dtw;

#include "categories/categories.h"
#include "categories/categories.c"

int main(){

    dtw = newDtwNamespace();

    DtwResource *database = dtw.resource.newResource("database");

    char *categorie_id = find_categorie_id_by_name(database,"Food");
    
    printf("id: %s",categorie_id);

    dtw.resource.commit(database);
    dtw.resource.free(database);
}