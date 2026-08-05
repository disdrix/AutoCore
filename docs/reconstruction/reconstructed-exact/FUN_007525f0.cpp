// =============================================================================
// FUN_007525f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007525f0
// Address:   0x007525f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007525f0 @ 0x007525f0
// Stable ID: aa_007525f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_007525f0.
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

uint32_t /* width from decompiler */ FUN_007525f0(void)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  int unaff_EDI;

  

  iVar1 = *(int *)(*(int *)(unaff_EDI + 8) + 0x18);

  for (iVar5 = *(int *)(*(int *)(unaff_EDI + 8) + 0x14); iVar5 < iVar1; iVar5 = iVar5 + 1) {

    piVar4 = (int *)((uint)*(ushort *)(*(int *)(*(int *)(unaff_EDI + 8) + 0x10) + 4 + iVar5 * 8) +

                    *(int *)(unaff_EDI + 0xc));

    iVar2 = piVar4[1];

    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x30) == 0)) {

      piVar3 = *(int **)(iVar2 + 0x10);

      *piVar4 = (int)piVar3;

      if (piVar3 != (int *)0x0) {

        (**(code **)(*piVar3 + 4))(piVar3);

      }

    }

  }

  return 0;

}
