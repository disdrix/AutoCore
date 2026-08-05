// =============================================================================
// FUN_00433d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00433d70
// Address:   0x00433d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00433d70 @ 0x00433d70
// Stable ID: aa_00433d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00433d70.
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

int __fastcall FUN_00433d70(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  int unaff_ESI;

  

  if ((-1 < unaff_ESI) && (iVar1 = *(int *)(param_2 + 0x14), unaff_ESI <= *(int *)(iVar1 + 0x10))) {

    *(int *)(param_2 + 4) = unaff_ESI;

    if (*(int *)(iVar1 + 4) != 0) {

      iVar1 = (int)*(int **)(iVar1 + 4) +

              *(int *)(iVar1 + 0x30) * unaff_ESI +

              **(int **)(iVar1 + 4) + *(int *)(iVar1 + 0x28) * 4;

      *(int *)(param_2 + 0x10) = iVar1;

      return iVar1;

    }

    *(int *)(param_2 + 0x10) = *(int *)(iVar1 + 0x30) * unaff_ESI;

  }

  return *(int *)(param_2 + 0x10);

}
