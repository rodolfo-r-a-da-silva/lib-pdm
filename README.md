# Lib PDM

Lib PDM is a library with common functionalities for PDMs.

## Description

A Power Distribution Module (PDM) is tipically a microcontrolled module that switches outputs based on inputs using transistors. The main advantages compared to traditional relay boxes are the configurability, output current sensing and e-fuse setting.

The main purpose of this library is to prioide a set of common functions that can be used in PDMs, so that outputs can be configured with logic functions with integers and binaries as inputs, with their sources being,for example:

- Internal data:
  - Output current;
  - Input voltage;
- External data:
  - Analog/digital input pins;
  - CAN bus data.

## Developing

A Docker image is used for development, so, it's needed to install either Docker Desktop or Docker Engine.

### Starting the Docker container

To build the image on Linux, run the following script:

```sh
./tools/docker_build.sh
```

and then the following script to run the container:

```sh
./tools/docker_run.sh
```

### Running the unit tests

Run the following script to run the unit tests:

```sh
./tools/run_unit_tests.sh
```
