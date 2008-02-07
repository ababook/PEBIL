#ifndef _SectionHeader_h_
#define _SectionHeader_h_

#include <Base.h>
#include <defines/SectionHeader.d>

class ElfFile;

class SectionHeader : public Base {
protected:
    char* rawDataPtr;
    char* relocationPtr;
    char* lineInfoPointer;
    uint32_t numOfRelocations;
    uint32_t numOfLineInfo;

    char* sectionNamePtr;
    ElfClassTypes sectionType;

    uint16_t index;
//    RawSection* rawSectionPtr;

protected:
    SectionHeader() : Base(ElfClassTypes_sect_header),
                   rawDataPtr(NULL), relocationPtr(NULL), lineInfoPointer(NULL),
                   numOfRelocations(0),numOfLineInfo(0),
                   index(0),sectionNamePtr(NULL),sectionType(ElfClassTypes_no_type) {}
    ~SectionHeader() {}
    bool verify();

public:

    SECTIONHEADER_MACROS_BASIS("For the get_X field macros check the defines directory");

    void print() { __SHOULD_NOT_ARRIVE; }
    void initFilePointers(BinaryInputFile* b);

    bool hasWriteBit();
    bool hasAllocBit();
    bool hasExecInstrBit();

    ElfClassTypes setSectionType();
    ElfClassTypes getSectionType() { return sectionType; }

    void setSectionNamePtr(char* namePtr) { sectionNamePtr = namePtr; }
    char* getSectionNamePtr() { return sectionNamePtr; }
    const char* getTypeName();

    char* getRawDataPtr() { return rawDataPtr; }
    uint64_t getRawDataSize() { return GET(sh_size); }

    uint16_t getIndex() { return index; }

    bool inRange(uint64_t address);

    const char* briefName() { return "SectionHeader"; }
};

class SectionHeader32 : public SectionHeader {
protected:
    Elf32_Shdr entry;

public:

    SECTIONHEADER_MACROS_CLASS("For the get_X field macros check the defines directory");

    SectionHeader32(uint16_t idx) { sizeInBytes = Size__32_bit_Section_Header; index = idx; }
    ~SectionHeader32() {}
    uint32_t read(BinaryInputFile* b);
    void print();
//    uint32_t instrument(char* buffer,ElfFileGen* xCoffGen,BaseGen* gen);
};

class SectionHeader64 : public SectionHeader {
protected:
    Elf64_Shdr entry;

public:

    SECTIONHEADER_MACROS_CLASS("For the get_X field macros check the defines directory");

    SectionHeader64(uint16_t idx) { sizeInBytes = Size__64_bit_Section_Header; index = idx; }
    ~SectionHeader64() {}
    uint32_t read(BinaryInputFile* b);
    void print();
//    uint32_t instrument(char* buffer,XCoffFileGen* xCoffGen,BaseGen* gen);
};

#endif /* _SectionHeader_h_ */
