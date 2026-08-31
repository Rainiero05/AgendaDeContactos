Calculadora de consola con funciones de suma, resta, multiplicación y división.

Intrucciones de uso en Windows:


En caso de no tener wsl, gcc o make instalados:

1. Abre PowerShell como administrador y ejecuta:
   wsl --install

2. Sigue los pasos de instalación de wsl

3. Abre nuevamente PowerShell como administrador y ejecuta:
   wsl
   sudo apt update
   sudo apt install build-essential


Al tener wsl, gcc y make instalados:

1. Entra a PowerShell como administrador y ejecuta el comando
wsl

2. Entra en la carpeta del proyecto, por ejemplo: 
cd /mnt/c/Users/nombre/Downloads/AgendaDeContactos

3. Compila con el comando:
make

4. Ejecuta el programa con el comando: 
./agenda

5. Si quieres borrar el ejecutable para compilar desde cero, usa el comando:
make clean
