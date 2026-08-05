// =============================================================================
// FUN_0042a3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042a3d0
// Address:   0x0042a3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042a3d0 @ 0x0042a3d0
// Stable ID: aa_0042a3d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00429f60, FUN_0042a1a0, FUN_0042a3d0.
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

void __thiscall FUN_0042a3d0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint8_t *unaff_retaddr;

  

  (**(code **)(*param_1 + 0x38))(param_3);

  iVar1 = FUN_00429f60(&stack0xfffffff4);

  if (iVar1 == 0) {

    iVar1 = FUN_0042a1a0(&stack0x0000000c);

    if (iVar1 == 0) {

      *unaff_retaddr = 0;

      return;

    }

  }

  *unaff_retaddr = 1;

  return;

}
