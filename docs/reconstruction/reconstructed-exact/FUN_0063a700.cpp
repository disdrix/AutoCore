// =============================================================================
// FUN_0063a700 (scaffold alias of CVOGHBAIBase_SetFloat0x2c)
// -----------------------------------------------------------------------------
// Stable ID: aa_0063a700
// Address:   0x0063a700  (autoassault.exe, image base 0x400000)
// System:    hbai
// Generated: 2026-07-29 dual A/B seal (W19-P); keeps Ghidra name as alias
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: reconstructed-exact/CVOGHBAIBase_SetFloat0x2c.cpp
// =============================================================================

void __thiscall FUN_0063a700(int param_1, uint32_t param_2)
{
  /* retail: movss store; param_2 bits are IEEE float */
  *(uint32_t *)(param_1 + 0x2c) = param_2;
  return;
}
