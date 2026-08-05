// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_008089a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008089a0
// Callee of Client_PacketDispatch
// Address:   0x008089a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00525cc0, FUN_008089a0.
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

void Named_CalleeOf_Client_PacketDispatch_008089a0(int param_1)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  int in_EAX;

  

  if (*(char *)(in_EAX + 0x11) != '\0') {

    iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    if ((*(int *)(iVar1 + 0x164 + DAT_00d1b6d8) == *(int *)(in_EAX + 8)) &&

       (*(int *)(iVar1 + 0x168 + DAT_00d1b6d8) == *(int *)(in_EAX + 0xc))) {

      FUN_00525cc0((int)*(char *)(in_EAX + 0x10),0);

    }

    piVar2 = *(int **)(param_1 + 0x10f0);

    if ((piVar2 != (int *)0x0) && (cVar3 = (**(code **)(*piVar2 + 0x3d8))(), cVar3 != '\0')) {

      (**(code **)(*piVar2 + 0x448))();

      (**(code **)(*piVar2 + 0x34c))();

    }

  }

  return;

}
