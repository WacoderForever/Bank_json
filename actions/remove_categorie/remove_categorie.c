bool remove_categorie(struct DtwResource *database,const char *name){
    char  *categorie_id = find_categorie_id_by_name(database,name);
    
    if(!categorie_id){
        cli.warning(&cli,"categorie '%s' not exist\n",name);
        free(categorie_id);
        return true;
    }
    
    remove_categorie_by_id(database,categorie_id);
    free(categorie_id);
    
    return true;
}