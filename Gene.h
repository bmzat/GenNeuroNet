#ifndef __GENESTRUCT_H
#define __GENESTRUCT_H

#include <System.hpp>

#pragma pack(1)

typedef enum GeneCodeFlags{
			CODE_AXON = 1,
			CODE_INPUT = 2,
			CODE_OUTPUT = 4,
			CODE_FEATURE = 8,
			CODE_PARAM = 16,
			CODE_VALUE = 32,
			CODE_RESERVED1 = 64,
            CODE_RESERVED2 = 129

}GeneCodeFlags_e;


typedef struct {
	UInt8 vFlags;
	UInt8 from;
	UInt8 dest;
	UInt8 reserved;
	float value;
}Gene_t;


#pragma pack(0)

#endif
