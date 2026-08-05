// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_00809070
// -----------------------------------------------------------------------------
// Stable ID: aa_00809070
// Callee of Client_PacketDispatch
// Address:   0x00809070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_004e23d0, FUN_00809070, Object_ResolveFromTFID.
//  - Return sites: 3.

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

void Named_CalleeOf_Client_PacketDispatch_00809070(void)



{

  int *piVar1;

  int iVar2;

  int unaff_EBX;

  uint8_t local_4 [4];

  

  piVar1 = Object_ResolveFromTFID((TFID_16 *)(unaff_EBX + 8));

  if (piVar1 == (int *)0x0) {

    if (*(char *)(unaff_EBX + 0x10) != '\0') {

      return;

    }

    iVar2 = FUN_004e23d0(((TFID_16 *)(unaff_EBX + 8))->dwCoidLo,*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc),

                         local_4);

    piVar1 = (int *)0x0;

    if (iVar2 != 0) {

      piVar1 = *(int **)(iVar2 + 0xc);

    }

    if (piVar1 == (int *)0x0) {

      return;

    }

  }

  (**(code **)(*piVar1 + 0x220))(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x18),0);

  return;

}
