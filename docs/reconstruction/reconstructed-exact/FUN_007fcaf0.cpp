// =============================================================================
// FUN_007fcaf0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fcaf0
// Address:   0x007fcaf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fcaf0 @ 0x007fcaf0
// Stable ID: aa_007fcaf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×6, goto×3, do×1, return×1, while×1.
//  - Notable callees: FUN_007fca10, FUN_007fcaf0.
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

void FUN_007fcaf0(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  int *piVar4;

  int unaff_EDI;

  

  piVar4 = (int *)(param_1 + 0x1030);

  param_1 = 0x3a;

  do {

    piVar1 = (int *)*piVar4;

    if ((piVar1 == (int *)0x0) || (cVar3 = (**(code **)(*piVar1 + 0x3d8))(), cVar3 == '\0'))

    goto LAB_007fcb64;

    iVar2 = piVar1[0x13f];

    if (((iVar2 == unaff_EDI) || ((unaff_EDI == 0 || (iVar2 == 0x10)))) &&

       ((piVar1[0x140] == param_2 || (param_2 == 0)))) {

LAB_007fcb5d:

      FUN_007fca10();

    }

    else if (unaff_EDI == 0xf) {

      if ((iVar2 == 0xc) || (iVar2 == 0xd)) goto LAB_007fcb5d;

    }

    else if (((unaff_EDI == 0xc) || (unaff_EDI == 0xd)) && (iVar2 == 0xf)) goto LAB_007fcb5d;

LAB_007fcb64:

    piVar4 = piVar4 + 1;

    param_1 = param_1 + -1;

    if (param_1 == 0) {

      return;

    }

  } while( true );

}
