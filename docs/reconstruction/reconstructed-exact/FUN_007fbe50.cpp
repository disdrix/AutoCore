// =============================================================================
// FUN_007fbe50
// -----------------------------------------------------------------------------
// Stable ID: aa_007fbe50
// Address:   0x007fbe50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fbe50 @ 0x007fbe50
// Stable ID: aa_007fbe50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007fbe50.
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

void FUN_007fbe50(void)



{

  int *in_EAX;

  int iVar1;

  int iVar2;

  int *unaff_ESI;

  

  if ((in_EAX != (int *)0x0) && (unaff_ESI != (int *)0x0)) {

    iVar1 = (**(code **)(*in_EAX + 0x490))();

    iVar2 = (**(code **)(*in_EAX + 0x494))();

    (**(code **)(*unaff_ESI + 0x454))(0,1);

    if (iVar1 <= iVar2) {

      (**(code **)(*unaff_ESI + 0x460))(0x3f800000);

    }

    else {

      (**(code **)(*unaff_ESI + 0x460))(g_flOne / (float)(iVar1 - iVar2));

    }

    (**(code **)(*unaff_ESI + 0xd4))(iVar1 > iVar2);

                    /* WARNING: Could not recover jumptable at 0x007fbecb. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*unaff_ESI + 0x34c))();

    return;

  }

  return;

}
