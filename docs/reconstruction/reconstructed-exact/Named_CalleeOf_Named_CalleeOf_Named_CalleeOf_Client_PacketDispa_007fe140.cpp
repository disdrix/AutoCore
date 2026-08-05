// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_007fe140
// -----------------------------------------------------------------------------
// Stable ID: aa_007fe140
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x007fe140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004010f0, FUN_00401430, FUN_007fe140.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_007fe140(int param_1)



{

  int *piVar1;

  int in_EAX;

  int unaff_retaddr;

  int local_c;

  uint32_t /* width from decompiler */ local_4;

  

  if (in_EAX != 0) {

    local_4 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x164);

    FUN_00401430();

    if ((local_c != *(int *)(param_1 + 0x3094)) &&

       (piVar1 = *(int **)(local_c + 0x18), piVar1 != (int *)0x0)) {

      (**(code **)(*piVar1 + 4))(0);

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_retaddr + 0xf40) + 0xb0))(piVar1);

      FUN_004010f0(param_1 + 0x3090,&local_4,local_c);

      (**(code **)*piVar1)(1);

    }

  }

  return;

}
