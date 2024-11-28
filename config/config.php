<?php


// Configuración de la base de datos desde el archivo .env
$servername = $_ENV['DB_HOST'] ?? 'localhost';
$username = $_ENV['DB_USER'] ?? 'root';
$password = $_ENV['DB_PASSWORD'] ?? '';
$dbname = $_ENV['DB_NAME'] ?? 'emuladorgba';

// Crear conexión a la base de datos
$mysqli = new mysqli($servername, $username, $password, $dbname);

// Verificar la conexión
if ($mysqli->connect_error) {
    die("Error de conexión a la base de datos: " . $mysqli->connect_error);
}

// Función para obtener la conexión (opcional)
function getDBConnection() {
    global $mysqli;
    return $mysqli;
}
?>
