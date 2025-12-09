FROM ubuntu:24.04

# 1. Dependencias de compilación
RUN apt-get update && \
    apt-get install -y \
        build-essential \
        cmake \
    && rm -rf /var/lib/apt/lists/*

# 2. Carpeta de trabajo
WORKDIR /app

# 3. Copiamos el proyecto (sin build gracias a .dockerignore)
COPY . .

# 4. Configuración y build LIMPIOS
RUN rm -rf build && cmake -S . -B build
RUN cmake --build build --config Release

# 5. Comando por defecto: ejecutar tests
CMD ["ctest", "--test-dir", "build", "--output-on-failure"]
