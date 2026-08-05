// =============================================================================
// FUN_0043cec0 / GuardedVector_GrowAssignRange
// -----------------------------------------------------------------------------
// Stable ID: aa_0043cec0
// Address:   0x0043cec0–0x0043ceef  (autoassault.exe, image base 0x400000)
// System:    STL / guarded ring-vector container
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W27-C)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Thin stdcall trampoline: 7 stack args → FUN_0043cf40(..., param_1) 8th.
 * - RET 0x1c. Sole caller: GuardedVector_CopyAssign grow path (0x0043c730).
 * - Real grow/insert work is unowned FUN_0043cf40.
 * - Name GuardedVector_GrowAssignRange is structural (Inferred).
 */

#include <cstdint>

extern "C" void FUN_0043cf40(uint32_t a, uint32_t b, uint32_t c, uint32_t d,
                             uint32_t e, uint32_t f, uint32_t g, uint32_t h);

extern "C" void FUN_0043cec0(uint32_t param_1, uint32_t param_2, uint32_t param_3,
                             uint32_t param_4, uint32_t param_5, uint32_t param_6,
                             uint32_t param_7)
{
  FUN_0043cf40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_1);
}
