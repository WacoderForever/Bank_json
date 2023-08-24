

bool add_categorie(DtwResource *database){
    char *name = cli.ask_string(&cli,"type the name",CLI_TRIM);
    char *possible_id = find_categorie_id_by_name(database,name);
    if(possible_id){
        cli.warning(&cli,"categorie '%s' already exist\n",name);
        free(possible_id);
        return true;
    }
    create_categorie(database,name);
    cli.print(&cli,"categorie '%s' added\n",name);
    free(name);
    return false;
}