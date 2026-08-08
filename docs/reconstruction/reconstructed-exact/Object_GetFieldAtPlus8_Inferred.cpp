// =============================================================================
// Object_GetFieldAtPlus8_Inferred  (aa_0044f660)
// -----------------------------------------------------------------------------
// Address:   0x0044f660 – 0x0044f663 inclusive (4 B / 0x4)
//            autoassault.exe, image base 0x400000
// Wave:      R10-027 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + read_memory +
//            disassemble_function. Leaf thiscall getter of dword at this+8.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX = this; plain RET; return EAX = *(this+8)
// =============================================================================

#include <cstdint>

// Retail: MOV EAX, [ECX+8] ; RET
// Shared virtual/thiscall leaf — embedded in ≥10 vtables including 0x00a9bbe8+4.
// Call sites treat the dword as an object pointer; product field English open.
extern "C" uint32_t __fastcall Object_GetFieldAtPlus8_Inferred(void* self)
{
  return *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 8);
}

// Scaffold / Ghidra alias
extern "C" uint32_t __fastcall FUN_0044f660(void* self)
{
  return Object_GetFieldAtPlus8_Inferred(self);
}
