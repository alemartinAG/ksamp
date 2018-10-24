void paramError();

//Esta funcion se encarga de devolver la forma correcta en que se deben ingresar los parametros
//y terminar el programa, en caso de que estos se hayan introducido en alguna forma no valida
void paramError(){

    printf("Las opciones son: \n -s \n -l a b \n \n");
    exit(6);

}