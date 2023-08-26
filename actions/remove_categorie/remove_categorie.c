bool remove_categorie(struct DtwResource *database,CliEntry *entry){
    
    char *name = get_interface_name(entry);
    if(!name){
        return true;
    }
    char  *categorie_id = find_categorie_id_by_name(database,name);
    
    if(!categorie_id){
        printf("categorie '%s' not exist\n",name);
        free(categorie_id);
        return true;
    }
    
    remove_categorie_by_id(database,categorie_id);
    printf("categorie '%s' removed\n",name);
    free(categorie_id);
    
    return false;
}