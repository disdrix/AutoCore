// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00419390
// -----------------------------------------------------------------------------
// Stable ID: aa_00419390
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x00419390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00419390.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00419390(int param_1)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  

  if (*(int *)(param_1 + 0x74) == 0) {

    uVar2 = 0;

  }

  else {

    uVar1 = *(uint *)(param_1 + 0x70) >> 2;

    iVar3 = uVar1 * -4;

    if (*(uint *)(param_1 + 0x6c) <= uVar1) {

      uVar1 = uVar1 - *(uint *)(param_1 + 0x6c);

    }

    uVar2 = *(uint32_t /* width from decompiler */ *)

             (*(int *)(*(int *)(param_1 + 0x68) + uVar1 * 4) +

             (*(uint *)(param_1 + 0x70) + iVar3) * 4);

  }

  if (*(int *)(param_1 + 0x74) != 0) {

    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;

    if ((uint)(*(int *)(param_1 + 0x6c) * 4) <= *(uint *)(param_1 + 0x70)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

    }

    iVar3 = *(int *)(param_1 + 0x74) + -1;

    *(int *)(param_1 + 0x74) = iVar3;

    if (iVar3 == 0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

    }

  }

  return uVar2;

}
