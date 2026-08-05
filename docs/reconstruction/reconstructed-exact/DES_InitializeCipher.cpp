// =============================================================================
// DES_InitializeCipher
// -----------------------------------------------------------------------------
// Stable ID: aa_0071c000
// Address:   0x0071c000  (autoassault.exe, image base 0x400000)
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

void DES_InitializeCipher(void)

{
  byte bVar1;
  byte *in_EAX;
  uint uVar2;
  uint uVar3;
  uint32_t /* width from decompiler */ local_8;
  uint32_t /* width from decompiler */ local_4;
  
  local_8 = 0;
  local_4 = 0;
  bVar1 = *in_EAX;
  for (uVar3 = 0; (bVar1 != 0 && ((int)uVar3 < 0x28)); uVar3 = uVar3 + 1) {
    uVar2 = uVar3 & 0x80000007;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
    }
    *(byte *)((int)&local_8 + uVar2) = *(byte *)((int)&local_8 + uVar2) ^ bVar1;
    bVar1 = in_EAX[1];
    in_EAX = in_EAX + 1;
  }
  FUN_0071b430(&DAT_00d16ef0,&DAT_00afca50);
  FUN_0071b430(&DAT_00d12690,&DAT_00afca90);
  DES_KeySchedule();
  FUN_0071bdd0();
  FUN_0071b5a0();
  return;
}
