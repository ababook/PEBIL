#ifndef _StringTable_h_
#define _StringTable_h_

#include <Base.h>
#include <ElfFile.h>
#include <SectionHeader.h>
#include <RawSection.h>

class ElfFile;

class StringTable : public RawSection {
protected:
    uint32_t index;
    char* strings;

public:
    StringTable(char* rawPtr, uint32_t size, uint16_t scnIdx, uint32_t idx, ElfFile* elf)
        : RawSection(ElfClassTypes_string_table,rawPtr,size,scnIdx,elf),index(idx) {};

    ~StringTable();

    void print();
    uint32_t read(BinaryInputFile* b);
    void dump(BinaryOutputFile* binaryOutputFile, uint32_t offset);

    char* getString(uint32_t offset);
    uint32_t addString(const char* name);
    uint32_t getIndex() { return index; }

    const char* briefName() { return "StringTable"; }
};

#endif /* _StringTable_h_ */
