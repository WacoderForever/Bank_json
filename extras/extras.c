

void add_json_to_resource_and_delete_json(DtwResource *resource, cJSON *generated){
    char *generated_json  = cJSON_Print(generated);
    dtw.resource.set_string(resource,generated_json);
    free(generated_json);
    cJSON_Delete(generated);
}