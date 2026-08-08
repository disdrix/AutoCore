// =============================================================================
// FUN_004bae00  (scaffold twin — prefer Host_DualCNDHash_TraverseNextObject_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bae00
// Address:   0x004bae00  (autoassault.exe, image base 0x400000)
// Range:     0x004bae00–0x004bae63 inclusive (100 B / 0x64)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-011 (refreshed from live re-verify; was 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Named clean: Host_DualCNDHash_TraverseNextObject_Inferred.cpp
// Retired scaffold: Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00.cpp
//
// ABI: ECX=host; stack char listSelect, int* cursor; EAX=object*|0; RET 8
// =============================================================================

#include <cstdint>

extern void __fastcall FUN_00402c40(int hash /* ECX */);
extern std::uint32_t __thiscall FUN_004bc530(int hash /* ECX */, int* cursor);

std::uint32_t __thiscall FUN_004bae00(int param_1, char param_2, int* param_3)
{
  std::uint32_t uVar1;

  if (param_2 == '\0') {
    if ((*(char*)(param_1 + 0xd) != '\0') && (*(int*)(param_1 + 8) != 0)) {
      FUN_00402c40(*(int*)(param_1 + 8));
      uVar1 = FUN_004bc530(*(int*)(param_1 + 8), param_3);
      *(std::uint8_t*)(*(int*)(param_1 + 8) + 0x1d) = 0;
      return uVar1;
    }
  }
  else if ((*(char*)(param_1 + 0xc) != '\0') && (*(int*)(param_1 + 4) != 0)) {
    FUN_00402c40(*(int*)(param_1 + 4));
    uVar1 = FUN_004bc530(*(int*)(param_1 + 4), param_3);
    *(std::uint8_t*)(*(int*)(param_1 + 4) + 0x1d) = 0;
    return uVar1;
  }
  return 0;
}
