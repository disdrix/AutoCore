// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_00445dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00445dc0
// Callee of Named_effDeviceEffect
// Address:   0x00445dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: FUN_00445880, FUN_00445dc0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect
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

void Named_CalleeOf_Named_effDeviceEffect_00445dc0(void)



{

  int iVar1;

  int unaff_EBX;

  int iVar2;

  

  iVar2 = *(int *)(unaff_EBX + 4);

  if (iVar2 == 0) {

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc) = 0;

    return;

  }

  iVar1 = *(int *)(unaff_EBX + 8);

  for (; iVar2 != iVar1; iVar2 = iVar2 + 0xc) {

    FUN_00445880();

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(unaff_EBX + 4));

}
