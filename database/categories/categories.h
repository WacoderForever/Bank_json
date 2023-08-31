
DtwResource * get_categories_resource(struct DtwResource *database);

cJSON * get_categorie_json(struct DtwResource *database);

char * find_categorie_id_by_name(DtwResource *database,const char *name);


int rename_categorie_by_id(DtwResource *database, const char *id, const char *new_name);

void remove_categorie_by_id(DtwResource *database, const char *id);


void create_categorie(DtwResource *database,const char *name);
