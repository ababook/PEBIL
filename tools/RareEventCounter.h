/* 
 * This file is part of the pebil project.
 * 
 * Copyright (c) 2010, University of California Regents
 * All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _RareEventCounter_h_
#define _RareEventCounter_h_

#include <InstrumentationTool.h>

class RareEventCounter : public InstrumentationTool {
private:
    InstrumentationFunction* entryFunc;
    InstrumentationFunction* exitFunc;

    InstrumentationFunction* loopEntry;
    InstrumentationFunction* loopExit;
public:
    RareEventCounter(ElfFile* elf);
    ~RareEventCounter() {}

    void declare();
    void instrument();

    const char* briefName() { return "RareEventCounter"; }
    const char* defaultExtension() { return "recinst"; }
    uint32_t allowsArgs() { return PEBIL_OPT_NON; }
    uint32_t requiresArgs() { return PEBIL_OPT_NON; }
};


#endif /* _RareEventCounter_h_ */
