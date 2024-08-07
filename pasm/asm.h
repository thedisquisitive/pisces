#ifndef ASM_H_
#define ASM_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "tokenizer.h"

using namespace std;

// Define a few opcodes and pieces to make
// implementation simpler

/*
            00E0 - CLS
            00EE - RET
            0nnn - SYS addr
            1nnn - JP addr
            2nnn - CALL addr
            3xkk - SE Vx, byte
            4xkk - SNE Vx, byte
            5xy0 - SE Vx, Vy
            6xkk - LD Vx, byte
            7xkk - ADD Vx, byte
            8xy0 - LD Vx, Vy
            8xy1 - OR Vx, Vy
            8xy2 - AND Vx, Vy
            8xy3 - XOR Vx, Vy
            8xy4 - ADD Vx, Vy
            8xy5 - SUB Vx, Vy
            8xy6 - SHR Vx {, Vy}
            8xy7 - SUBN Vx, Vy
            8xyE - SHL Vx {, Vy}
            9xy0 - SNE Vx, Vy
            Annn - LD I, addr
            Bnnn - JP V0, addr
            Cxkk - RND Vx, byte
            Dxyn - DRW Vx, Vy, nibble
            Ex9E - SKP Vx
            ExA1 - SKNP Vx
            Fx07 - LD Vx, DT
            Fx0A - LD Vx, K
            Fx15 - LD DT, Vx
            Fx18 - LD ST, Vx
            Fx1E - ADD I, Vx
            Fx29 - LD F, Vx
            Fx33 - LD B, Vx
            Fx55 - LD [I], Vx
            Fx65 - LD Vx, [I]
*/

#define OPCODE_CLEARSCREEN	0x00E0
#define OPCODE_RETURN		0x00EE

class PiscesAssembler {
private:
    string srcFile;
    string outFile;

    ifstream fin;
    ofstream fout;

public:
    PiscesAssembler() {
        srcFile = "main.asm"; outFile = "pisce.o";
        fout.open(outFile, ios::out | ios::binary);
        if (!fout.is_open()) {
            cout << "PiscesAssembler: Error - could not open output stream!\n";
        }
        fin.open(srcFile);
        if (!fin.is_open()) {
            cout << "PiscesAssembler: Error - could not open source file!\n";
        }
    }
    PiscesAssembler(string ifile, string ofile) {
        srcFile = ifile;
        outFile = ofile;
        fout.open(outFile, ios::out | ios::binary);
        if (!fout.is_open()) {
            cout << "PiscesAssembler: Error - could not open output stream!\n";
        }
        fin.open(srcFile);
        if (!fin.is_open()) {
            cout << "PiscesAssembler: Error - could not open source file!\n";
        }
    }
    ~PiscesAssembler() {
        if (fin.is_open()) {
            fin.close();
        }
        if (fout.is_open()) {
            fout.close();
        }
        return;
    }

    void setSourceFile(string f) { srcFile = f; }
    string getSourceFile() { return srcFile; }

    vector<string> getNextLine();
    unsigned short getByteCode(vector<string> src);


};


#endif // ASM_H_