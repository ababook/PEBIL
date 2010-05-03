#ifndef _CallReplace_h_
#define _CallReplace_h_

#include <InstrumentationTool.h>

class Symbol;

class CallReplace : public InstrumentationTool {
private:
    InstrumentationFunction* programEntry;
    InstrumentationFunction* programExit;
    Vector<InstrumentationFunction*> functionWrappers;

    Vector<char*>* functionList;
public:
    CallReplace(ElfFile* elf, char* traceFile);
    ~CallReplace();

    void declare();
    void instrument();

    char* getWrapperName(uint32_t idx);
    char* getFunctionName(uint32_t idx);
};


#endif /* _CallReplace_h_ */
