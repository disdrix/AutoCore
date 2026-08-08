// =============================================================================
// FUN_0050e9f0  (scaffold twin of StdTree_Lrotate_Isnil21_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0050e9f0
// Address:   0x0050e9f0  (autoassault.exe, image base 0x400000)
// Body:      0x0050e9f0–0x0050ea3d inclusive (78 B / 0x4E)
// System:    MSVC std::_Tree left-rotate (isnil@+0x21 / color@+0x20)
// Generated: 2026-08-05 R10-030 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: StdTree_Lrotate_Isnil21_Inferred
// =============================================================================

// PURPOSE: MSVC _Tree left-rotate for isnil@+0x21 family. Leaf pointer surgery.
// Twin Rrotate: FUN_005a27f0. Parent dual: 0x00407200 InsertAndRebalance isnil21.

#include <cstdint>

// __thiscall: ECX = tree*, stack = node* x; void; RET 4
void __thiscall FUN_0050e9f0(std::int32_t param_1, std::int32_t param_2)
{
  std::int32_t *piVar1;
  std::int32_t *piVar2;

  piVar1 = *reinterpret_cast<std::int32_t **>(param_2 + 8);
  *reinterpret_cast<std::int32_t *>(param_2 + 8) = *piVar1;
  if (*reinterpret_cast<char *>(*piVar1 + 0x21) == '\0') {
    *reinterpret_cast<std::int32_t *>(*piVar1 + 4) = param_2;
  }
  piVar1[1] = *reinterpret_cast<std::int32_t *>(param_2 + 4);
  if (param_2 == *reinterpret_cast<std::int32_t *>(
                     *reinterpret_cast<std::int32_t *>(param_1 + 4) + 4)) {
    *reinterpret_cast<std::int32_t **>(
        *reinterpret_cast<std::int32_t *>(param_1 + 4) + 4) = piVar1;
    *piVar1 = param_2;
    *reinterpret_cast<std::int32_t **>(param_2 + 4) = piVar1;
    return;
  }
  piVar2 = *reinterpret_cast<std::int32_t **>(param_2 + 4);
  if (param_2 == *piVar2) {
    *piVar2 = reinterpret_cast<std::int32_t>(piVar1);
    *piVar1 = param_2;
    *reinterpret_cast<std::int32_t **>(param_2 + 4) = piVar1;
    return;
  }
  piVar2[2] = reinterpret_cast<std::int32_t>(piVar1);
  *piVar1 = param_2;
  *reinterpret_cast<std::int32_t **>(param_2 + 4) = piVar1;
  return;
}
