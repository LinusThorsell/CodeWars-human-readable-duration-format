{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.cmake
    pkgs.gcc
    pkgs.gtest

    pkgs.entr
  ];
}

