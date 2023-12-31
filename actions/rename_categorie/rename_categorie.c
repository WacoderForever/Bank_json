bool rename_categorie(struct DtwResource *database,CliEntry *entry){
    char *name=get_interface_name(entry);
    if(!name){
        return true;
    }
    char *categorie_id=find_categorie_id_by_name(database,name);
    if(categorie_id==NULL){
        printf("categorie '%s' does not exist\n",name);
        free(categorie_id);
        return true;
    }

    char *new_name=get_new_name(entry);
    int k=rename_categorie_by_id(database,categorie_id,new_name);
    if(k!=1){
    printf("Categorie %s renamed to %s\n",name,new_name);
    return false;
    }
    printf("A category  with the name '%s' already exists\n",new_name);
    return false;
}