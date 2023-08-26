

bool add_categorie(DtwResource *database,CliEntry *entry){

    char *name = get_interface_name(entry);
    char *possible_id = find_categorie_id_by_name(database,name);
    if(possible_id){
        printf("categorie '%s' already exist\n",name);
        free(possible_id);
        return true;
    }
    create_categorie(database,name);
    printf("categorie '%s' added\n",name);
    free(name);
    return false;
}