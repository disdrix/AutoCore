// =============================================================================
// FUN_0040b6d0 — scaffold twin of StdVector_InsertOne_RebindIt_Via419880_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b6d0
// Address:   0x0040b6d0  (autoassault.exe, image base 0x400000)
// Prefer named clean: StdVector_InsertOne_RebindIt_Via419880_Inferred.cpp
// WQ7R-E dual seal 2026-08-04.
//
// NOTE: Decompiler drops EDI/EBX customcc. Real ABI:
//   EDI=vector*, EBX=outIt**, stack(where*, value*), ret 8, EAX=EBX.
//   Callee FUN_00419880 with ECX=1.
// =============================================================================

#include <cstdint>

extern "C" void FUN_00419880(void* vec, int where, const void* value);

// Scaffold: mirrors Ghidra unaff_* form (not a portable entry).
extern "C" void FUN_0040b6d0(int param_1, uint32_t param_2)
{
  int* unaff_EBX = nullptr; // real: EBX
  int unaff_EDI = 0;        // real: EDI = vector*
  int iVar1;

  iVar1 = *reinterpret_cast<int*>(unaff_EDI + 4);
  if ((iVar1 == 0) || ((*reinterpret_cast<int*>(unaff_EDI + 8) - iVar1) >> 2) == 0) {
    iVar1 = 0;
  } else {
    iVar1 = (param_1 - iVar1) >> 2;
  }
  // Bytes: ECX=1; push value, where, vec
  FUN_00419880(reinterpret_cast<void*>(unaff_EDI), param_1,
               reinterpret_cast<const void*>(static_cast<uintptr_t>(param_2)));
  *unaff_EBX = *reinterpret_cast<int*>(unaff_EDI + 4) + iVar1 * 4;
  return; // ret 8
}
