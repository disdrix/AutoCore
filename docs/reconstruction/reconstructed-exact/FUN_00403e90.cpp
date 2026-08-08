// =============================================================================
// FUN_00403e90  — Ghidra twin of StdTree_Lrotate_Isnil31_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00403e90
// Address:   0x00403e90  (autoassault.exe, image base 0x400000)
// Body:      0x00403e90–0x00403edb inclusive (76 B)
// System:    MSVC std _Tree left-rotate (isnil@+0x31)
// Generated: 2026-08-05 WQ9L-B dual seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Named reconstruction: StdTree_Lrotate_Isnil31_Inferred.cpp
// Purpose: left-rotate node X; isnil@+0x31; ECX=node; stack=map; RET 4.

#include <cstdint>

// Ghidra-shaped formals (param_1 = ECX node; param_2 = stack map)
extern "C" void __thiscall FUN_00403e90(std::int32_t param_1, std::int32_t param_2)
{
  std::int32_t *piVar1;
  std::int32_t *piVar2;

  piVar1 = *reinterpret_cast<std::int32_t **>(param_1 + 8);
  *reinterpret_cast<std::int32_t *>(param_1 + 8) = *piVar1;
  if (*reinterpret_cast<char *>(*piVar1 + 0x31) == '\0') {
    *reinterpret_cast<std::int32_t *>(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *reinterpret_cast<std::int32_t *>(param_1 + 4);
  if (param_1 == *reinterpret_cast<std::int32_t *>(
                     *reinterpret_cast<std::int32_t *>(param_2 + 4) + 4)) {
    *reinterpret_cast<std::int32_t **>(
        *reinterpret_cast<std::int32_t *>(param_2 + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *reinterpret_cast<std::int32_t **>(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *reinterpret_cast<std::int32_t **>(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = reinterpret_cast<std::int32_t>(piVar1);
    *piVar1 = param_1;
    *reinterpret_cast<std::int32_t **>(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = reinterpret_cast<std::int32_t>(piVar1);
  *piVar1 = param_1;
  *reinterpret_cast<std::int32_t **>(param_1 + 4) = piVar1;
  return;
}
