// =============================================================================
// Class_00a9bbe8_CompleteDtor_Inferred  (aa_00416110)
// -----------------------------------------------------------------------------
// Address:   0x00416110 – 0x00416146 inclusive (55 B / 0x37)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9I-G OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory + disassemble_function. Complete dtor: SEH frame then
//            install PTR_LAB_00a9bbe8 as *obj; no free of this.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       Stack obj* (not ECX thiscall); SEH; ADD ESP,0xC; RET 4
// =============================================================================

#include <cstdint>

// Retail vtbl symbol (Ghidra PTR_LAB_00a9bbe8).
extern "C" void* PTR_LAB_00a9bbe8;

// Stack = this. SEH. RET 4. Complete dtor — does not free this.
// Sole caller: FUN_004160f0 (scalar-deleting) does push this; call.
extern "C" void Class_00a9bbe8_CompleteDtor_Inferred(void* obj)
{
  // SEH: push -1; push 0x009bc0a8; link FS:[0] (omitted as runtime frame)
  *reinterpret_cast<void**>(obj) = &PTR_LAB_00a9bbe8;
  // restore FS:[0]; ADD ESP,0xC; RET 4
}

// Scaffold / Ghidra alias
extern "C" void FUN_00416110(void* obj)
{
  Class_00a9bbe8_CompleteDtor_Inferred(obj);
}
