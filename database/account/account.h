DtwResource *get_account_resource(struct DtwResource *database);

cJSON *get_account_json(struct DtwResource *database);

char *find_account_id_by_name(struct DtwResource *database,const char *name);

void rename_account_name(struct DtwResource *database,const char *id,const char *new_name);

void create_account(struct DtwResource *database,const char *name);

void remove_account_by_id(struct DtwResource *database,const char *name);