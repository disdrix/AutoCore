// =============================================================================
// FUN_0089ff30
// -----------------------------------------------------------------------------
// Stable ID: aa_0089ff30
// Address:   0x0089ff30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0089ff30 @ 0x0089ff30
// Stable ID: aa_0089ff30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, while×1, if×1.
//  - Notable callees: FUN_0089ff30.
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

uint32_t /* width from decompiler */ FUN_0089ff30(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int unaff_EBX;

  

  iVar2 = 0;

  piVar3 = (int *)(unaff_EBX + 0x63c);

  while (((iVar1 = *piVar3, iVar1 == 0 || (*(int *)(iVar1 + 0x550) != param_1)) ||

         (*(int *)(iVar1 + 0x554) != param_2))) {

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 1;

    if (9 < iVar2) {

      return 0;

    }

  }

  return *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x63c + iVar2 * 4);

}
