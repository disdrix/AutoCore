// =============================================================================
// FUN_007b35e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b35e0
// Address:   0x007b35e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b35e0 @ 0x007b35e0
// Stable ID: aa_007b35e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00755a50×2, FUN_007b35e0.
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

int FUN_007b35e0(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint8_t local_18 [8];

  uint8_t local_10 [12];

  

  if (param_1 == 0) {

    return 0;

  }

  iVar2 = *(int *)(param_1 + 0x84);

  iVar4 = 0;

  if (iVar2 != *(int *)(param_1 + 0x88)) {

    iVar3 = iVar2 + 0x10;

    do {

      if (((*(int *)(iVar3 + 0x18) != 0) && (*(int *)(iVar3 + 0x10) != 0)) &&

         (piVar1 = (int *)FUN_00755a50(local_18), iVar4 < *piVar1)) {

        piVar1 = (int *)FUN_00755a50(local_10);

        iVar4 = *piVar1;

      }

      iVar2 = iVar2 + 0x80;

      iVar3 = iVar3 + 0x80;

    } while (iVar2 != *(int *)(param_1 + 0x88));

  }

  return iVar4;

}
