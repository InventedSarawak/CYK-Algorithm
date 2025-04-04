FROM debian:bullseye-slim

# Install required packages
RUN apt-get update && apt-get install -y \
    gcc \
    make \
    libc6-dev \
    && rm -rf /var/lib/apt/lists/*

# Create and set working directory
WORKDIR /app

# Copy source code, headers, and makefile
COPY src/ /app/src/
COPY include/ /app/include/
COPY Makefile /app/

# Build the application
RUN make

# Run the application
CMD ["./bin/cyk_algorithm.exe"]

# Note: This container expects input via stdin
# To run with input from a file use:
# docker run -i cyk-algorithm < input_file.txt
#
# To run interactively:
# docker run -it cyk-algorithm