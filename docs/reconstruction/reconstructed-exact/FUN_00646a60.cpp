// =============================================================================
// FUN_00646a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00646a60
// Address:   0x00646a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00646a60 @ 0x00646a60
// Stable ID: aa_00646a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00646a60.
//  - Return sites: 1.

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

int FUN_00646a60(uint param_1)



{

  int iVar1;

  byte bVar2;

  byte bVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  

  uVar5 = param_1 >> 0x17 & 0xff;

  iVar6 = uVar5 - 0x7f;

  iVar1 = uVar5 - 0x97;

  uVar5 = param_1 & ~((int)((param_1 & 0x7fffffff) - 1) >> 0x1f);

  bVar3 = (byte)(iVar1 >> 0x1f);

  bVar2 = 0x17U - (char)iVar6 & bVar3;

  uVar7 = ~(iVar1 >> 0x1f);

  uVar4 = (uVar5 & 0x7fffff | 0x800000) & (-0x800000 >> ((bVar3 & 0x17) - bVar2 & 0x1f) | uVar7);

  return ((int)(((uVar4 * 2 - 1 | (int)uVar5 >> 0x1f) - uVar4) + 1 & ~(iVar6 >> 0x1f)) >>

         (bVar2 & 0x1f)) << ((char)(param_1 >> 0x17) + 0x6aU & (byte)uVar7 & 0x1f);

}
