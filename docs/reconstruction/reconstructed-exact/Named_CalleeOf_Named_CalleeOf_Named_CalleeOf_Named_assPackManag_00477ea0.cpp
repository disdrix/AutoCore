// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_00477ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00477ea0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
// Address:   0x00477ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_00477ea0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
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

uint Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_00477ea0(void)



{

  int iVar1;

  int iVar2;

  int unaff_ESI;

  

  if ((unaff_ESI == 0) || (iVar1 = *(int *)(unaff_ESI + 0x1c), iVar1 == 0)) {

    return 0xfffffffe;

  }

  iVar2 = *(int *)(iVar1 + 4);

  if (((iVar2 != 0x2a) && (iVar2 != 0x71)) && (iVar2 != 0x29a)) {

    return 0xfffffffe;

  }

  if (*(int *)(iVar1 + 8) != 0) {

    (**(code **)(unaff_ESI + 0x24))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28),*(int *)(iVar1 + 8));

  }

  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1c) + 0x3c);

  if (iVar1 != 0) {

    (**(code **)(unaff_ESI + 0x24))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28),iVar1);

  }

  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1c) + 0x38);

  if (iVar1 != 0) {

    (**(code **)(unaff_ESI + 0x24))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28),iVar1);

  }

  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x1c) + 0x30);

  if (iVar1 != 0) {

    (**(code **)(unaff_ESI + 0x24))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28),iVar1);

  }

  (**(code **)(unaff_ESI + 0x24))

            (*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x28),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c));

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

  return (iVar2 != 0x71) - 1 & 0xfffffffd;

}
