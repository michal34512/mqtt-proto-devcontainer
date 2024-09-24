# mqtt-proto-devcontainer
Devcontainer with sample c++ project with Protobuf, PahoMqtt and Mosquitto MQTT broker installed 

## Installation Steps

1. **Clone the repo**
   ```sh
   git clone https://github.com/michal34512/mqtt-proto-devcontainer.git
   ```
3. **Navigate to the project directory**
   ```sh
   cd mqtt-proto-devcontainer
   ```
4. **Open the project in Visual Studio Code**
   ```sh
   code .
   ```
4. **Reopen in Devcontainer**  
   Once VS Code is open, press `F1`, type `Reopen in Container`, and select the command to launch the devcontainer environment.
5. **Wait for the Devcontainer to build**  
   After the devcontainer is set up, open the terminal within VS Code.
6. Build and run the project
   ```sh
   make all
   ```

## Makefile Targets

| Target   | Description              |
|----------|--------------------------|
| `all`    | Builds and runs the project. |
| `build`  | Compiles the project in the `build/` directory. |
| `run`    | Runs the compiled binary. |
| `clean`  | Removes the `build/` directory and cleans the project. |
| `help`   | Displays help and usage instructions. |
