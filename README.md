# Embedded Template

Plantilla base para proyectos de firmware con arquitectura limpia,
orientada a calidad profesional, testabilidad y mantenimiento.

## Arquitectura

Estructura en capas:

- `domain/`  
  Lógica de negocio pura.  
  - No depende de hardware  
  - No conoce RTOS ni sistema operativo

- `hal/`  
  Abstracción de hardware.  
  - Define interfaces  
  - No contiene lógica de negocio

- `app/`  
  Capa de composición.  
  - Conecta dominio con HAL
  - Punto de entrada del sistema

- `tests/`  
  Tests unitarios del dominio y lógica.

## Reglas de diseño

- El dominio **no puede incluir headers de HAL**
- El dominio **no conoce FreeRTOS, Linux ni ESP32**
- HAL expone interfaces, no decisiones
- `main()` solo orquesta, no piensa

Este repositorio es una base reutilizable para proyectos embebidos profesionales.
