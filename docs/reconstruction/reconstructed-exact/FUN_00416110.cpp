// =============================================================================
// FUN_00416110 — Ghidra alias twin of Class_00a9bbe8_CompleteDtor_Inferred
// VA 0x00416110; see Class_00a9bbe8_CompleteDtor_Inferred.cpp for sealed body.
// Wave: WQ9I-G 2026-08-05
// =============================================================================

#include <cstdint>

extern "C" void* PTR_LAB_00a9bbe8;

// Stack obj*; ret 4. SEH elided. Installs class vftable only.
extern "C" void FUN_00416110(uint32_t* param_1)
{
  *param_1 = reinterpret_cast<uint32_t>(&PTR_LAB_00a9bbe8);
}
