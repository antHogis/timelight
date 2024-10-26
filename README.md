# TimeLight
An app for controlling lights with day/night cycles, with dynamic configurable effects.

## Get started
First copy the app config

    cp ./timelight.example.toml ./timelight.toml

Then build and run

    ./scripts/build.sh && ./build/TimeLight

Alternatively build with hot reload

    ./scripts/hotbuild.sh

## Tooling (Clang + NeoVim)

Create cmake build first. Then install the `compiledb` for generating the clangd
JSON compilation database.

    pipx install compiledb

Then do this

    cd build
    compiledb -n make
    cd ..
    link ./build/compile_commands.json ./compile_commands.json

If you don't do this, the neovim lsp will not have all info it needs on how to compile project,
and might not recognize newer C++ language features
