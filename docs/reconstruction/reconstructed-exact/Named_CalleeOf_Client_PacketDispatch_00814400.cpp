// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_00814400
// -----------------------------------------------------------------------------
// Stable ID: aa_00814400
// Callee of Client_PacketDispatch
// Address:   0x00814400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0056a260, FUN_0056d160, FUN_00811e00, FUN_008120d0, FUN_00814400.
//  - Return sites: 1.

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

void Named_CalleeOf_Client_PacketDispatch_00814400(void)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ unaff_EBX;

  int unaff_EDI;

  

  piVar1 = (int *)CVOGReaction_ResolveObjectTarget

                            (*(uint8_t *)(unaff_EDI + 0x98),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x90),

                             *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x94));

  if (piVar1 == (int *)0x0) {

    piVar1 = (int *)FUN_008120d0(unaff_EBX,unaff_EDI);

  }

  else {

    FUN_00811e00(unaff_EBX);

  }

  if (piVar1 != (int *)0x0) {

    iVar2 = (**(code **)(*piVar1 + 0x1e0))();

    if (iVar2 != 0) {

      FUN_0056a260(0);

      FUN_0056d160(&DAT_00d1a680,1);

    }

  }

  return;

}
