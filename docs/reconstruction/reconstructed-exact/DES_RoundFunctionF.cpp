// =============================================================================
// DES_RoundFunctionF
// -----------------------------------------------------------------------------
// Stable ID: aa_0071bf70
// Address:   0x0071bf70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void DES_RoundFunctionF(void)

{
  int iVar1;
  int in_EAX;
  byte local_10;
  byte local_f;
  uint32_t /* width from decompiler */ local_e;
  byte local_8;
  byte local_7;
  byte local_6;
  byte local_5;
  byte local_4;
  byte local_3;
  
  iVar1 = in_EAX * 6;
  DES_CalculateExpansion();
  local_8 = (&DAT_00d16e90)[iVar1] ^ local_10;
  local_7 = (&DAT_00d16e91)[iVar1] ^ local_f;
  local_6 = (&DAT_00d16e92)[iVar1] ^ (byte)local_e;
  local_5 = (&DAT_00d16e93)[iVar1] ^ (byte)((uint)local_e >> 8);
  local_4 = *(byte *)((int)&DAT_00d16e94 + iVar1) ^ (byte)((uint)local_e >> 0x10);
  local_3 = *(byte *)((int)&DAT_00d16e94 + iVar1 + 1) ^ (byte)((uint)local_e >> 0x18);
  DES_CalculateSBoxSubstitution(&local_10);
  DES_CalculatePermutationP(&local_10);
  return;
}
