// Twin of StdTree_InsertAndRebalance_Val8_Isnil15_Inferred — see that file for sealed port.
// Stable ID: aa_00438140  VA: 0x00438140  Wave: W38-L
//
// Scaffold CF preserved; structural rename lives in named clean.
// EDI = map; stack (out*, addLeft, where*, value*); RET 0x10.
// Node 0x18: color@+0x14 isnil@+0x15; max size 0x1ffffffd.

#include <cstdint>

// Prefer named clean for port notes. This twin keeps Ghidra symbol for tooling glue.

extern "C" void StdTree_InsertAndRebalance_Val8_Isnil15_Inferred(
    void** out, char addLeft, void* where, void* value);

extern "C" void FUN_00438140(void** out, char addLeft, void* where, void* value)
{
  StdTree_InsertAndRebalance_Val8_Isnil15_Inferred(out, addLeft, where, value);
}
