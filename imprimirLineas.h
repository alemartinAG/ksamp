void imprimirLineas(char[]);

//Esta funcion se encarga de imprimir la cantidad de lineas de texto que tiene un archivo
void imprimirLineas(char archivo[]){

    FILE *fp = NULL;
    int ch = 0;
    int lines = 0;

    //abro el archivo
    fp = fopen(archivo, "rb");

    //incremento una variable 'lines' hasta el 'end of file'
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            lines++;
        }
    }

    //cierro el archivo
    fclose(fp);

    printf("Cantidad de archivos soportados: %d\n", lines);

    return;
}