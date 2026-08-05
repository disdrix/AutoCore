// =============================================================================
// FUN_00574810
// -----------------------------------------------------------------------------
// Stable ID: aa_00574810
// Address:   0x00574810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00574810 @ 0x00574810
// Stable ID: aa_00574810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: CONCAT31, FUN_00574810.
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

int __thiscall FUN_00574810(int param_1,int param_2,int param_3)



{

  int iVar1;

  uint3 uVar2;

  byte bVar3;

  

  bVar3 = 0;

  while( true ) {

    iVar1 = (uint)bVar3 * 0x10;

    uVar2 = (uint3)((uint)iVar1 >> 8);

    if ((param_2 == *(int *)(iVar1 + 0x198 + param_1)) &&

       (param_3 == *(int *)(iVar1 + 0x19c + param_1))) break;

    bVar3 = bVar3 + 1;

    if (3 < bVar3) {

      return (uint)uVar2 << 8;

    }

  }

  return CONCAT31(uVar2,1);

}
