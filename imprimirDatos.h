void imprimirDatos(char[], char[]);

char *datos;

//Esta funcion se encarga de igualar la variable global 'datos', con el texto requerido a imprimir 
void imprimirDatos(char archivo[], char seccion[]){

    FILE *fp = NULL;
    char buffer[8000] = "";
    size_t bytes_read;
    char *match;
    char data_found[64] = "";

    //Abro el archivo, lo leo y lo guardo en el buffer
    fp = fopen(archivo, "rb");
    bytes_read = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    if(bytes_read == 0 || bytes_read == sizeof(buffer)){
        printf("buffer problem");
    }

    //le agrego un caracter de finalizacion al ultimo
    buffer[bytes_read] = '\0';

    //busco la linea de la seccion requerida
    match = strstr(buffer, seccion);

    if(match == NULL){
        printf("match = null");
    }

    char linea[90] = "";
    strcat(linea, seccion);
    strcat(linea, " %[^\n]");

    sscanf(match, linea, data_found);

    datos = data_found;

    return;
}