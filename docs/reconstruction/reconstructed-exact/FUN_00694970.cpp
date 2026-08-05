// =============================================================================
// FUN_00694970
// -----------------------------------------------------------------------------
// Stable ID: aa_00694970
// Address:   0x00694970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00694970 @ 0x00694970
// Stable ID: aa_00694970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, do×1, return×1.
//  - Notable callees: FUN_006937d0, FUN_00694970.
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

void FUN_00694970(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar1 = param_1;

  if (param_1 != param_2) {

    while (iVar2 = iVar1, iVar1 = iVar2 + 0x30, iVar1 != param_2) {

      iVar3 = iVar1;

      iVar4 = param_1;

      if (*(float *)(iVar2 + 0x54) <= *(float *)(param_1 + 0x24)) {

        do {

          iVar4 = iVar3;

          iVar3 = iVar4 + -0x30;

        } while (*(float *)(iVar4 + -0xc) < *(float *)(iVar2 + 0x54));

      }

      if ((iVar4 != iVar1) && (iVar1 != iVar2 + 0x60)) {

        FUN_006937d0(iVar4,iVar1,iVar2 + 0x60,0,0);

      }

    }

  }

  return;

}
