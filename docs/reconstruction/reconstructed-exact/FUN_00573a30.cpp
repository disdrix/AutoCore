// =============================================================================
// FUN_00573a30  (scaffold twin of FriendsList_FindEntryByNameI_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00573a30
// Address:   0x00573a30  (autoassault.exe, image base 0x400000)
// System:    social / friends list
// Generated: 2026-07-23 scaffold; refined R11-005 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Canonical named clean: FriendsList_FindEntryByNameI_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" int __cdecl _stricmp(const char* a, const char* b);

std::uint32_t __thiscall FUN_00573a30(int param_1, char* param_2)
{
  int iVar1;
  int iVar2;

  iVar2 = 0;
  while (true) {
    if (*(int*)(param_1 + 8) == 0) {
      iVar1 = 0;
    } else {
      iVar1 = *(int*)(param_1 + 0xc) - *(int*)(param_1 + 8) >> 2;
    }
    if (iVar1 <= iVar2) break;
    iVar1 = _stricmp(
        (char*)(*(int*)(*(int*)(param_1 + 8) + iVar2 * 4) + 0x1a),
        param_2);
    if (iVar1 == 0) {
      return *(std::uint32_t*)(*(int*)(param_1 + 8) + iVar2 * 4);
    }
    iVar2 = iVar2 + 1;
  }
  return 0;
}
