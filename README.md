# Embedded Template

Plantilla base para proyectos de firmware en C con **arquitectura limpia**, **tests unitarios** y **CI integrada**.

Pensada como punto de partida reutilizable para proyectos embebidos (bare-metal, RTOS o Linux embebido), con foco en **calidad profesional**, **testabilidad** y **mantenibilidad**.

---

## Objetivos

- Separar claramente **lógica de dominio** de **hardware**.
- Facilitar **TDD en C** mediante Unity + CMock.
- Disponer de un **build reproducible** (CMake + Docker).
- Integrar **CI desde el primer día** (GitHub Actions + CTest).
- Servir como plantilla realista para repositorios de firmware profesionales.

---

## Arquitectura

Estructura en capas:

### `domain/`
Lógica de negocio pura.
- No depende de hardware  
- No conoce RTOS ni sistema operativo

### `hal/`
Abstracción de hardware.
- Define interfaces (por ejemplo, `gpio_set`)
- No contiene lógica de negocio

### `app/`
Capa de composición.
- Conecta dominio con la HAL real
- Punto de entrada del sistema (`main()`)

### `tests/`
Tests unitarios del dominio y la lógica.
- Unity como framework de test
- CMock para aislamiento del hardware

### Diagrama de arquitectura (simplificado)

```text
           +---------------------+
           |        app/         |
           |   (composition)     |
           +----------+----------+
                      |
                      v
           +---------------------+
           |       domain/       |
           |  (business logic)   |
           +----------+----------+
                      |
              uses HAL interface
                      |
                      v
           +---------------------+
           |        hal/         |
           | (hardware API only) |
           +---------------------+

           +---------------------+
           |       tests/        |
           |  Unity + CMock      |
           +---------------------+
```

---

## Reglas de diseño

- El dominio **no puede incluir headers de HAL** (salvo a través de interfaces explícitas y controladas).
- El dominio **no conoce FreeRTOS, Linux, ESP32, etc.**
- La HAL expone **interfaces**, no decisiones de negocio.
- `main()` solo **orquesta**, **no piensa**.

Este repositorio sirve como base reutilizable para proyectos embebidos profesionales.

---

## Flujo de build y tests

### 1. Local (desarrollo)

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

- `cmake` genera el proyecto.
- `cmake --build` compila aplicación y tests.
- `ctest` ejecuta todos los tests registrados (Unity + CMock).

---

### 2. Docker (entorno reproducible)

```bash
docker build -t embedded-template .
docker run --rm embedded-template
```

La imagen Docker:
- Instala `build-essential` y `cmake`.
- Configura el proyecto.
- Compila el código.
- Ejecuta los tests con `ctest`.

Esto garantiza que el proyecto se construye y pasa los tests en un entorno controlado e independiente de la máquina de desarrollo.

---

### 3. CI (GitHub Actions)

Workflow en:

```
.github/workflows/ci.yml
```

Ejecuta en cada `push` y `pull_request`:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

---

## Tecnologías utilizadas

- Lenguaje: C (C99)
- Arquitectura: domain / HAL / app
- Tests unitarios: Unity
- Mocks: CMock
- Build system: CMake + CTest
- Entorno reproducible: Docker
- CI: GitHub Actions

---

## Problemas que resuelve este template

- **Lógica de negocio mezclada con drivers**  
  → El dominio vive en `domain/` y no conoce registros ni pines.

- **Tests inexistentes o difíciles de ejecutar**  
  → Tests ejecutables con `ctest`, usando Unity + CMock.

- **“En mi máquina funciona”**  
  → Docker y CI garantizan reproducibilidad.

- **Repositorios sin estructura clara**  
  → Arquitectura y pipeline definidos desde el primer commit.

---

## Cómo extender el template

### Añadir un nuevo módulo de dominio
- Código en `domain/`
- Tests en `tests/` usando `add_unity_test(...)`

### Añadir una nueva HAL o implementación de hardware
- Interfaces en `hal/`
- Implementación concreta en `app/` o en un módulo HAL específico

### Añadir más tests
- Crear ficheros `test_*.c` en `tests/`
- Registrar los tests en `tests/CMakeLists.txt`

---
