// =============================================================================
// Named_CalleeOf_Named_SkyBoxParticles_004b55e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b55e0
// Callee of Named_SkyBoxParticles
// Address:   0x004b55e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_004b4e70, FUN_004b55e0, free.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_SkyBoxParticles
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_SkyBoxParticles_004b55e0(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a14c5;

  local_c = ExceptionList;

  local_4 = 0;

  if (*(char *)(param_1 + 0x60) != '\0') {

    if (*(void **)(param_1 + 0x50) != (void *)0x0) {

      ExceptionList = &local_c;

      free(*(void **)(param_1 + 0x50));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  FUN_004b4e70();

  if (*(void **)(param_1 + 0x30) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x30));

  }

  operator_delete__(*(void **)(param_1 + 0x44));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x40));

}
