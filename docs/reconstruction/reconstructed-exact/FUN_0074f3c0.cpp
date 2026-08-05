// =============================================================================
// FUN_0074f3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074f3c0
// Address:   0x0074f3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074f3c0 @ 0x0074f3c0
// Stable ID: aa_0074f3c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0074f3c0.
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

int __fastcall FUN_0074f3c0(uint32_t /* width from decompiler */ param_1,uint8_t param_2)



{

  int iVar1;

  int in_EAX;

  int iVar2;

  int unaff_EDI;

  

  if ((in_EAX != 0) && (*(int *)(unaff_EDI + 0xc) != 0)) {

    iVar1 = DAT_00d1f044[0x1df];

    if (iVar1 == 1) {

      (**(code **)(*(int *)*DAT_00d1f044 + 0x134))((int *)*DAT_00d1f044,param_2);

    }

    iVar2 = (**(code **)(**(int **)(unaff_EDI + 0xc) + 0xf0))(*(int **)(unaff_EDI + 0xc));

    if (iVar1 == 1) {

      (**(code **)(*(int *)*DAT_00d1f044 + 0x134))((int *)*DAT_00d1f044,0);

    }

    return (-1 < iVar2) - 1;

  }

  return -1;

}
