// =============================================================================
// DES_FeistelRound
// -----------------------------------------------------------------------------
// Stable ID: aa_0071c080
// Address:   0x0071c080  (autoassault.exe, image base 0x400000)
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

void DES_FeistelRound(void)

{
  byte *unaff_EBX;
  byte *unaff_EDI;
  uint32_t /* width from decompiler */ local_4;
  
  DES_RoundFunctionF(&local_4);
  *unaff_EBX = unaff_EDI[4];
  unaff_EBX[1] = unaff_EDI[5];
  unaff_EBX[2] = unaff_EDI[6];
  unaff_EBX[3] = unaff_EDI[7];
  unaff_EBX[4] = *unaff_EDI ^ (byte)local_4;
  unaff_EBX[5] = unaff_EDI[1] ^ (byte)((uint)local_4 >> 8);
  unaff_EBX[6] = unaff_EDI[2] ^ (byte)((uint)local_4 >> 0x10);
  unaff_EBX[7] = unaff_EDI[3] ^ (byte)((uint)local_4 >> 0x18);
  return;
}
