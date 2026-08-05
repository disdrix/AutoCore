// =============================================================================
// FUN_00545db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00545db0
// Address:   0x00545db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00545db0 @ 0x00545db0
// Stable ID: aa_00545db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00545500, FUN_00545db0.
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

void __fastcall FUN_00545db0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  pvVar2 = (void *)*puVar1;

  *puVar1 = puVar1;

  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  if (pvVar2 != *(void **)(param_1 + 4)) {

    FUN_00545500();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  return;

}
