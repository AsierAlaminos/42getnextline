![42 Madrid](https://www.42madrid.com/wp-content/uploads/2019/11/logo-header@2x.png)

# 42getnextline ![Static Badge](https://img.shields.io/badge/status-finish-green)

Este es mi proyecto get_next_line de 42Madrid

### Descripción

El proyecto get_next_line trata sobre crear una función la cual reciba un file descriptor y devuelva una linea del archivo por cada vez que es llamada la función.  
Tiene que recibir o no una variable llamada BUFFER_SIZE al compilar, la lectura tendrá que ser de esa longitud, pero no deberá de dejar de leer si no ha encontrado un salto de linea o se haya acabado el archivo.

Mi planteamiento del proyecto fue llenar el buffer e ir vaciando hasta que no pudiese devolver otra linea, en ese caso que leyese otra vez.

Para ir vaciando el buffer se coge la primera linea del buffer que es la que hay que devolver, y despues se reduce el tamaño del buffer quitando esa linea y dejando el resto de lo leido en el puntero.
