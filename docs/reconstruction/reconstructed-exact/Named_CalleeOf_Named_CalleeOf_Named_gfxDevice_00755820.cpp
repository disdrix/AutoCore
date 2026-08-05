// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_00755820
// -----------------------------------------------------------------------------
// Stable ID: aa_00755820
// Callee of Named_CalleeOf_Named_gfxDevice
// Address:   0x00755820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004439d0, FUN_00449a90, FUN_00755100, FUN_00755820.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDevice
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

void Named_CalleeOf_Named_CalleeOf_Named_gfxDevice_00755820(void)



{

  uint uVar1;

  int unaff_ESI;

  uint uVar2;

  

  if (*(int *)(unaff_ESI + 0xc) == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(int *)(unaff_ESI + 0x10) - *(int *)(unaff_ESI + 0xc) >> 1;

  }

  FUN_004439d0();

  FUN_00449a90(9);

  uVar2 = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 100) = 1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x68) = 1;

  if (uVar1 != 0) {

    do {

      FUN_00755100(*(uint16_t *)(*(int *)(unaff_ESI + 0xc) + uVar2 * 2));

      uVar2 = uVar2 + 1;

    } while (uVar2 < uVar1);

  }

  return;

}
