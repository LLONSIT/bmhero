#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2024 ZeldaRET
# SPDX-License-Identifier: CC0-1.0

# IDO symbol table parser for BSS ordering debugging. The compiler will assign
# "block numbers" or "dense numbers" to symbols in order as it encounters them
# in the source file, and the BSS section is sorted by this block number mod 256.
# This script dumps the compiler-generated symbol table so you can see which
# block numbers are assigned to each symbol.
#
# Resources:
#   https://hackmd.io/@Roman971/BJ2DOyhBa
#   https://github.com/decompals/ultralib/blob/main/tools/mdebug.py
#   https://www.cs.unibo.it/~solmi/teaching/arch_2002-2003/AssemblyLanguageProgDoc.pdf
#   https://github.com/decompals/IDO/blob/main/IDO_7.1/dist/compiler_eoe/usr/include/sym.h

import argparse
import itertools
from pathlib import Path
import platform
import struct
import subprocess
import sys


class Header:
    SIZE = 0x60

    def __init__(self, data):
        (
            self.magic,
            self.vstamp,
            self.ilineMax,
            self.cbLine,
            self.cbLineOffset,
            self.idnMax,
            self.cbDnOffset,
            self.ipdMax,
            self.cbPdOffset,
            self.isymMax,
            self.cbSymOffset,
            self.ioptMax,
            self.cbOptOffset,
            self.iauxMax,
            self.cbAuxOffset,
            self.issMax,
            self.cbSsOffset,
            self.issExtMax,
            self.cbSsExtOffset,
            self.ifdMax,
            self.cbFdOffset,
            self.crfd,
            self.cbRfdOffset,
            self.iextMax,
            self.cbExtOffset,
        ) = struct.unpack(">2H23I", data)


class FileDescriptor:
    SIZE = 0x48

    def __init__(self, data):
        (
            self.adr,
            self.rss,
            self.issBase,
            self.cbSs,
            self.isymBase,
            self.csym,
            self.ilineBase,
            self.cline,
            self.ioptBase,
            self.copt,
            self.ipdFirst,
            self.cpd,
            self.iauxBase,
            self.caux,
            self.rfdBase,
            self.crfd,
            self.flags,
            self.cbLineOffset,
            self.cbLine,
        ) = struct.unpack(">10I2H7I", data)


class Symbol:
    SIZE = 0xC

    def __init__(self, data):
        (
            self.iss,
            self.value,
            self.flags,
        ) = struct.unpack(">3I", data)

    def symbol_type(self):
        symbol_types = {
            0: "nil",
            1: "global",
            2: "static",
            3: "param",
            4: "local",
            5: "label",
            6: "proc",
            7: "block",
            8: "end",
            9: "member",
            10: "typedef",
            11: "file",
            14: "staticproc",
            15: "constant",
            26: "struct",
            27: "union",
            28: "enum",
            34: "indirect",
        }
        return symbol_types[self.flags >> 26]

    def symbol_storage_class(self):
        symbol_storage_classes = {
            0: "nil",
            1: "text",
            2: "data",
            3: "bss",
            4: "register",
            5: "abs",
            6: "undefined",
            8: "bits",
            9: "dbx",
            10: "regimage",
            11: "info",
        }
        return symbol_storage_classes[(self.flags >> 21) & 0x1F]


class ExternalSymbol:
    SIZE = 0x10

    def __init__(self, data):
        (
            self.flags,
            self.ifd,
        ) = struct.unpack(">2H", data[0:4])
        self.asym = Symbol(data[4:])


def read_entry(data, base, offset, size):
    start = base + offset * size
    return data[start : start + size]


def read_string(data, start):
    size = 0
    while data[start + size] != 0:
        size += 1
    return data[start : start + size].decode("ascii")


def print_symbol_table(data):
    header = Header(data[0 : Header.SIZE])

    print(f"block [mod 256]: linkage  type        class      name")

    # File descriptors
    fds = []
    for i in range(header.ifdMax):
        fds.append(
            FileDescriptor(read_entry(data, header.cbFdOffset, i, FileDescriptor.SIZE))
        )

    # Symbol identifiers ("dense numbers")
    for i in range(header.idnMax):
        ifd, isym = struct.unpack(">II", read_entry(data, header.cbDnOffset, i, 8))

        if isym == 0xFFFFF:
            # TODO: is this always a string?
            extern = False
            sym_name = ""
            st = "string"
            sc = ""
        else:
            extern = ifd == 0x7FFFFFFF
            if extern:
                ext = ExternalSymbol(
                    read_entry(data, header.cbExtOffset, isym, ExternalSymbol.SIZE)
                )
                sym = ext.asym
                sym_name = read_string(data, header.cbSsExtOffset + sym.iss)
            else:
                fd = fds[ifd]
                sym = Symbol(
                    read_entry(
                        data, header.cbSymOffset, fd.isymBase + isym, Symbol.SIZE
                    )
                )
                sym_name = read_string(data, header.cbSsOffset + fd.issBase + sym.iss)
            st = sym.symbol_type()
            sc = sym.symbol_storage_class()

        print(
            f'{i:>9} [{i%256:>3}]: {"extern" if extern else "":<7}  {st:<10}  {sc:<9}  {sym_name:<40}'
        )


def generate_symbol_table(command_line):
    # Assume command line is of the form:
    # python3 tools/preprocess.py [COMPILER] [COMPILER_ARGS] [INPUT_FILE]
    input_file = Path(command_line[-1])
    rest = command_line[:-1]

    stem = input_file.stem
    symbol_table_file = Path(f"{stem}.T")
    ucode_file = Path(f"{stem}.B")

    try:
        # Invoke compiler
        # -Hf stops compilation after cfe so we can inspect the symbol table
        subprocess.run(rest + ["-Hf", input_file], check=True)

        # Read symbol table
        return symbol_table_file.read_bytes()
    finally:
        # Cleanup
        symbol_table_file.unlink(missing_ok=True)
        ucode_file.unlink(missing_ok=True)


def main():
    parser = argparse.ArgumentParser(
        description="Dump IDO symbol table for debugging BSS ordering"
    )

    command_line = sys.argv[1:]
    data = generate_symbol_table(command_line)
    print_symbol_table(data)


if __name__ == "__main__":
    main()
