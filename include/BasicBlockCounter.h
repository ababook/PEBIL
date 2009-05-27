#ifndef _BasicBlockCounter_h_
#define _BasicBlockCounter_h_

#include <ElfFileInst.h>

class BasicBlockCounter : public ElfFileInst {
private:
    void printStaticFile(Vector<BasicBlock*>* allBlocks, Vector<LineInfo*>* allLineInfos);

    InstrumentationFunction* entryFunc;
    InstrumentationFunction* exitFunc;
public:
    BasicBlockCounter(ElfFile* elf, char* inputFuncList);
    ~BasicBlockCounter() {}

    void declare();
    void instrument();

    const char* briefName() { return "BasicBlockCounter"; }
};


#endif /* _BasicBlockCounter_h_ */
