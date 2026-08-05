// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_00809e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00809e30
// Callee of Client_PacketDispatch
// Address:   0x00809e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00531960, FUN_00809e30, FUN_008a05a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
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

void Named_CalleeOf_Client_PacketDispatch_00809e30(void)



{

  char cVar1;

  int in_EAX;

  int unaff_ESI;

  

  FUN_00531960(*(uint16_t *)(in_EAX + 4));

  if (*(int *)(unaff_ESI + 0x10b0) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x10b0) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_008a05a0();

    }

  }

  cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1030) + 0xd0))();

  if (cVar1 != '\0') {

                    /* WARNING: Could not recover jumptable at 0x00809e82. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x1030) + 0x448))();

    return;

  }

  return;

}
