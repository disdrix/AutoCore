// =============================================================================
// FUN_007760c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007760c0
// Address:   0x007760c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007760c0 @ 0x007760c0
// Stable ID: aa_007760c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_00773470, FUN_007760c0.
//  - Return sites: 3.

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

int __fastcall FUN_007760c0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar2;

  

  *unaff_EBX = 0;

  puVar2 = &DAT_00a23cd0;

  while( true ) {

    iVar1 = FUN_00773470();

    if (iVar1 != 0) {

      return iVar1;

    }

    if (param_1 == 0) break;

    puVar2 = puVar2 + 1;

    if (0xa240cf < (int)puVar2) {

      return 0;

    }

  }

  *unaff_EBX = 1;

  return 0;

}
