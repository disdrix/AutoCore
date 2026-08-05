// =============================================================================
// FUN_0093a330
// -----------------------------------------------------------------------------
// Stable ID: aa_0093a330
// Address:   0x0093a330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093a330 @ 0x0093a330
// Stable ID: aa_0093a330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_008e5990×2, FUN_007fef20, FUN_0089c6c0, FUN_0093a330.
//  - Return sites: 4.

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

void FUN_0093a330(int param_1)



{

  int *piVar1;

  char cVar2;

  int unaff_EBX;

  

  piVar1 = *(int **)(unaff_EBX + 0x1054);

  if (((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0x3d8))(), cVar2 != '\0')) &&

     (cVar2 = (**(code **)(*piVar1 + 0xd0))(), cVar2 != '\0')) {

    piVar1[0x14b] = 7;

    piVar1[0x14c] = param_1;

    FUN_0089c6c0(1);

    return;

  }

  piVar1 = *(int **)(unaff_EBX + 0x1068);

  if (((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0x3d8))(), cVar2 != '\0')) &&

     (cVar2 = (**(code **)(*piVar1 + 0xd0))(), cVar2 != '\0')) {

    if (piVar1[499] == param_1) {

      return;

    }

    FUN_008e5990(param_1);

    return;

  }

  FUN_007fef20(0xe,1,0);

  FUN_008e5990(param_1);

  return;

}
