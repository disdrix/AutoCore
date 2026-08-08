// =============================================================================
// FUN_00573a90  (scaffold twin of IgnoreList_FindEntryByTfid_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00573a90
// Address:   0x00573a90–0x00573ae7 exclusive (87 B / 0x57)
// Module:    autoassault.exe (image base 0x400000)
// System:    social / ignore list
// Agent:     R12-025 OWN-ONLY dual 2026-08-05 (scaffold kept; prefer named clean)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED (Terminal false).
// =============================================================================
// Prefer: docs/reconstruction/reconstructed-exact/IgnoreList_FindEntryByTfid_Inferred.cpp

#include <cstdint>

void* __thiscall FUN_00573a90(void* param_1, int param_2, int param_3)
{
  auto* host = reinterpret_cast<std::uint8_t*>(param_1);
  int iVar2 = 0;

  for (;;) {
    int iVar1;
    if (*reinterpret_cast<int*>(host + 0x38) == 0) {
      iVar1 = 0;
    } else {
      iVar1 = (*reinterpret_cast<int*>(host + 0x3c) -
               *reinterpret_cast<int*>(host + 0x38)) >> 2;
    }
    if (iVar1 <= iVar2) {
      break;
    }
    iVar1 = *reinterpret_cast<int*>(
        *reinterpret_cast<int*>(host + 0x38) + iVar2 * 4);
    if ((*reinterpret_cast<int*>(iVar1 + 8) == param_2) &&
        (*reinterpret_cast<int*>(iVar1 + 0xc) == param_3)) {
      return *reinterpret_cast<void**>(
          *reinterpret_cast<int*>(host + 0x38) + iVar2 * 4);
    }
    iVar2 = iVar2 + 1;
  }
  return nullptr;
}
