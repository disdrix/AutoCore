// =============================================================================
// FUN_005a27f0  (scaffold twin of StdTree_Rrotate_Isnil21_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005a27f0
// Address:   0x005a27f0  (autoassault.exe, image base 0x400000)
// Body:      0x005a27f0–0x005a2841 inclusive (82 B / 0x52)
// System:    MSVC std::_Tree right-rotate (isnil@+0x21 / color@+0x20)
// Generated: 2026-08-05 R11-007 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: StdTree_Rrotate_Isnil21_Inferred
// =============================================================================

// PURPOSE: MSVC _Tree right-rotate for isnil@+0x21 family. Leaf pointer surgery.
// Twin Lrotate: FUN_0050e9f0. Parent dual: 0x00407200 InsertAndRebalance isnil21.

#include <cstdint>

// __thiscall: ECX = tree*, stack = node* x; void; RET 4
void __thiscall FUN_005a27f0(std::int32_t param_1, std::int32_t *param_2)
{
  std::int32_t iVar1;
  std::int32_t *piVar2;

  iVar1 = *param_2;
  *param_2 = *reinterpret_cast<std::int32_t *>(iVar1 + 8);
  if (*reinterpret_cast<char *>(
          *reinterpret_cast<std::int32_t *>(iVar1 + 8) + 0x21) == '\0') {
    *reinterpret_cast<std::int32_t **>(
        *reinterpret_cast<std::int32_t *>(iVar1 + 8) + 4) = param_2;
  }
  *reinterpret_cast<std::int32_t *>(iVar1 + 4) = param_2[1];
  if (param_2 == *reinterpret_cast<std::int32_t **>(
                     *reinterpret_cast<std::int32_t *>(param_1 + 4) + 4)) {
    *reinterpret_cast<std::int32_t *>(
        *reinterpret_cast<std::int32_t *>(param_1 + 4) + 4) = iVar1;
    *reinterpret_cast<std::int32_t **>(iVar1 + 8) = param_2;
    param_2[1] = iVar1;
    return;
  }
  piVar2 = reinterpret_cast<std::int32_t *>(param_2[1]);
  if (param_2 == reinterpret_cast<std::int32_t *>(piVar2[2])) {
    piVar2[2] = iVar1;
    *reinterpret_cast<std::int32_t **>(iVar1 + 8) = param_2;
    param_2[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *reinterpret_cast<std::int32_t **>(iVar1 + 8) = param_2;
  param_2[1] = iVar1;
  return;
}
