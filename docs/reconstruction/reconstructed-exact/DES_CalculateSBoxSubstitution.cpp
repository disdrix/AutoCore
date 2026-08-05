// =============================================================================
// DES_CalculateSBoxSubstitution
// -----------------------------------------------------------------------------
// Stable ID: aa_0071ba90
// Address:   0x0071ba90  (autoassault.exe, image base 0x400000)
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

void DES_CalculateSBoxSubstitution(uint8_t *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte *in_EAX;
  
  bVar1 = in_EAX[2];
  bVar2 = in_EAX[1];
  bVar3 = in_EAX[3];
  bVar4 = in_EAX[4];
  bVar5 = in_EAX[5];
  *param_1 = (&DAT_00d12e90)[(int)(char)bVar2 >> 4 & 0xfU | (uint)*in_EAX << 4];
  param_1[1] = (&DAT_00d13e90)[(int)CONCAT11(bVar2,bVar1) & 0xfff];
  param_1[2] = (&DAT_00d14e90)[(int)(char)bVar4 >> 4 & 0xfU | (uint)bVar3 << 4];
  param_1[3] = (&DAT_00d15e90)[(int)CONCAT11(bVar4,bVar5) & 0xfff];
  return;
}
