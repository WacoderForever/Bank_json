
#include "dependencies/DoTheWord.h"
#include "dependencies/clinput.h"
#include "dependencies/CTextEngine.h"

DtwNamespace dtw;
CTextNamespace ctext;

#include "declaration.h"
#include "definition.h"


int main(){

    dtw = newDtwNamespace();
    ctext = newCTextNamespace();

    DtwResource *database = dtw.resource.newResource("database");

    create_categorie(database,"aaaaaaaaaaaaa");

    dtw.resource.commit(database);
    dtw.resource.free(database);
}