// =============================================================================
// FUN_004192a0  →  StdTree_Lrotate_Isnil29
// -----------------------------------------------------------------------------
// Stable ID: aa_004192a0
// Address:   0x004192a0  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree left-rotate (isnil@+0x29)
// Generated: 2026-07-23 scaffold; 2026-08-04 WQ9D-C seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Prefer named clean: StdTree_Lrotate_Isnil29.cpp

#include <cstdint>

void __thiscall StdTree_Lrotate_Isnil29(std::int32_t tree, std::int32_t x);

void __thiscall FUN_004192a0(std::int32_t param_1, std::int32_t param_2)
{
  std::int32_t *piVar1;
  std::int32_t *piVar2;

  piVar1 = *reinterpret_cast<std::int32_t **>(param_2 + 8);
  *reinterpret_cast<std::int32_t *>(param_2 + 8) = *piVar1;
  if (*reinterpret_cast<char *>(*piVar1 + 0x29) == '\0') {
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
