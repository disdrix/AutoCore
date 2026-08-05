// =============================================================================
// FUN_00421362  (alias → OleDb_AllocBindingsBuf_EnterBuild_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00421362
// Address:   0x00421362–0x00421391  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB accessor setup
// Generated: 2026-07-29 W24-F (twin of named clean)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical: reconstructed-exact/OleDb_AllocBindingsBuf_EnterBuild_Inferred.cpp

#include <cstdint>

#ifndef E_OUTOFMEMORY
#define E_OUTOFMEMORY ((int)0x8007000E)
#endif

extern "C" void* operator_new__(unsigned size);
extern "C" int FUN_0042139b(void);
extern "C" void* ExceptionList;

// Ghidra-faithful surface (shared frame phantoms).
uint32_t FUN_00421362(void)
{
  int* piVar1;
  void* pvVar2;
  uint32_t uVar3;
  int unaff_EBX;   // ctx*
  int unaff_EBP;   // parent frame

  *(uint32_t*)(unaff_EBP + -4) = 0;
  if (*(int*)(unaff_EBP + -0x1c) == 0) {
    *(uint32_t*)(unaff_EBP + -4) = 0xffffffff;
    piVar1 = *(int**)(unaff_EBP + -0x18);
    if (piVar1 != (int*)0x0) {
      (**(void(**)(int*))(*(int*)piVar1 + 8))(piVar1);
    }
    ExceptionList = *(void**)(unaff_EBP + -0xc);
    return 0x8007000e;
  }
  *(uint8_t*)(unaff_EBP + -4) = 4;
  pvVar2 = operator_new__(*(uint32_t*)(unaff_EBX + 0xc));
  *(void**)(unaff_EBX + 0x10) = pvVar2;
  // machine: jmp FUN_0042139b
  uVar3 = (uint32_t)FUN_0042139b();
  return uVar3;
}
