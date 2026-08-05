// =============================================================================
// DES_EncryptBlock8
// -----------------------------------------------------------------------------
// Stable ID: aa_0071c1b0
// Address:   0x0071c1b0  (autoassault.exe, image base 0x400000)
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

void DES_EncryptBlock8(void)

{
  int iVar1;
  uint8_t local_90;
  uint8_t local_8f;
  uint8_t local_8e;
  uint8_t local_8d;
  uint8_t local_8c;
  uint8_t local_8b;
  uint8_t local_8a;
  uint8_t local_89;
  uint8_t local_8;
  uint8_t local_7;
  uint8_t local_6;
  uint8_t local_5;
  uint32_t /* width from decompiler */ local_4;
  
                    /* Performs standard DES 64-bit block encryption on an 8-byte block. First
                       applies Initial Permutation (IP), then runs 16 Feistel rounds using the round
                       keys at 0x00d16e90, then swaps the halves of the result, and finally applies
                       the Final Permutation (FP / IP^-1) using the table at 0x00d12690. */
  DES_PermuteBlock();
  iVar1 = 0;
  do {
    DES_FeistelRound(iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x10);
  local_90 = (uint8_t)local_4;
  local_8f = (uint8_t)((uint)local_4 >> 8);
  local_8e = (uint8_t)((uint)local_4 >> 0x10);
  local_8d = (uint8_t)((uint)local_4 >> 0x18);
  local_8c = local_8;
  local_8b = local_7;
  local_8a = local_6;
  local_89 = local_5;
  DES_PermuteBlock(&local_90);
  return;
}
