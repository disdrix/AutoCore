// =============================================================================
// FUN_004a8b20
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8b20
// Address:   0x004a8b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a8b20 @ 0x004a8b20
// Stable ID: aa_004a8b20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_004a8b20.
//  - Return sites: 2.

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

uint __thiscall FUN_004a8b20(int param_1,float param_2,float param_3)



{

  uint in_EAX;

  int iVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  

  fVar3 = *(float *)(param_1 + 0x18) * DAT_00a0f298;

  fVar4 = g_flOne / *(float *)(param_1 + 0x18);

  iVar2 = (int)((param_2 - fVar3) * fVar4);

  iVar1 = (int)((param_3 - fVar3) * fVar4);

  if ((((-1 < iVar2) && (iVar2 < *(int *)(param_1 + 0x10))) && (-1 < iVar1)) &&

     (in_EAX = *(uint *)(param_1 + 0x14), iVar1 < (int)in_EAX)) {

    iVar2 = in_EAX * iVar2 + *(int *)(param_1 + 0x3dc);

    return CONCAT31((int3)((uint)iVar2 >> 8),*(uint8_t *)(iVar2 + iVar1)) & 0xffffff07;

  }

  return in_EAX & 0xffffff00;

}
