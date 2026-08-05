// =============================================================================
// FUN_004bb010  (scaffold alias → Object_ResolveTfIdVtbl1d4_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bb010
// Address:   0x004bb010–0x004bb039  (autoassault.exe, image base 0x400000)
// System:    object-resolve / TFID
// Generated: 2026-07-23 scaffold; dual A/B sealed 2026-07-29
// Prefer:    Object_ResolveTfIdVtbl1d4_Inferred.cpp (named clean; ECX passthrough)
// Dual:      accept-with-gaps
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bb010 @ 0x004bb010
// Stable ID: aa_004bb010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_004bb010.
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

uint32_t /* width from decompiler */ FUN_004bb010(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(*(uint8_t *)(param_1 + 2),*param_1,param_1[1])

  ;

  if (piVar1 != (int *)0x0) {

    uVar2 = (**(code **)(*piVar1 + 0x1d4))();

    return uVar2;

  }

  return 0;

}
