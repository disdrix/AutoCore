// =============================================================================
// FUN_00582570
// -----------------------------------------------------------------------------
// Stable ID: aa_00582570
// Address:   0x00582570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00582570 @ 0x00582570
// Stable ID: aa_00582570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004910e0, FUN_00496190, FUN_00582570.
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

void __fastcall FUN_00582570(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  iVar2 = *(int *)(iVar1 + 0xa8 + param_1);

  if ((iVar2 != 0) && (*(int *)(iVar2 + 0xe894) != 0)) {

    iVar1 = *(int *)(*(int *)(iVar1 + param_1 + 0xac) + 0x3c);

    if ((iVar1 != 0) && (*(short *)(iVar1 + 0x3f4) == 0xc)) {

      FUN_004910e0(param_1);

      return;

    }

    if (*(int *)(iVar2 + 0xe898) != 0) {

      FUN_00496190(param_1);

    }

  }

  return;

}
