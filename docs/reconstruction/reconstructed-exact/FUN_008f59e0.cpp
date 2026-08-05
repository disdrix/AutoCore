// =============================================================================
// FUN_008f59e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f59e0
// Address:   0x008f59e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f59e0 @ 0x008f59e0
// Stable ID: aa_008f59e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×2, return×1.
//  - Notable callees: FUN_007a69d0×2, FUN_008f59e0.
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

void FUN_008f59e0(void)



{

  uint uVar1;

  byte bVar2;

  int iVar3;

  

  DAT_00af9218 = 0;

  iVar3 = 0;

  do {

    bVar2 = (byte)iVar3;

    iVar3 = iVar3 + 1;

    DAT_00af9218 = DAT_00af9218 | 1 << (bVar2 & 0x1f);

  } while (iVar3 < 0x20);

  iVar3 = FUN_007a69d0();

  if (*(int *)(iVar3 + 0x2c) != 1) {

    DAT_00af9218 = DAT_00af9218 & 0xffffbfff;

  }

  iVar3 = FUN_007a69d0();

  if (*(int *)(iVar3 + 0x2c) != 2) {

    DAT_00af9218 = DAT_00af9218 & 0xffff7fff;

  }

  uVar1 = 0;

  iVar3 = 0;

  do {

    bVar2 = (byte)iVar3;

    iVar3 = iVar3 + 1;

    uVar1 = uVar1 | 1 << (bVar2 & 0x1f);

  } while (iVar3 < 0x20);

  DAT_00af921c = uVar1 & 0xfffffff1;

  return;

}
