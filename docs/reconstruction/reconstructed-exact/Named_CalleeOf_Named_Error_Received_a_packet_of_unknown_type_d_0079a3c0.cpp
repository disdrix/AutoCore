// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0079a3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a3c0
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0079a3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0079a3c0.
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

void __fastcall Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0079a3c0(int param_1,int param_2,int param_3,int param_4)



{

  int *piVar1;

  

  if ((param_2 < *(int *)(param_1 + 0x1c)) && (-1 < param_2)) {

    param_2 = param_2 * 0x2c;

    piVar1 = (int *)(*(int *)(param_1 + 0x18) + 4 + param_2);

    *piVar1 = *piVar1 + param_3;

    piVar1 = (int *)(*(int *)(param_1 + 0x18) + 8 + param_2);

    *piVar1 = *piVar1 + param_4;

    if (*(uint *)(*(int *)(param_1 + 0x18) + param_2 + 0x14) <

        *(uint *)(*(int *)(param_1 + 0x18) + 4 + param_2)) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + param_2 + 0x14) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + 4 + param_2);

    }

    if (*(uint *)(*(int *)(param_1 + 0x18) + 4 + param_2) <

        *(uint *)(*(int *)(param_1 + 0x18) + param_2 + 0x24)) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + param_2 + 0x24) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + 4 + param_2);

    }

    if (*(uint *)(*(int *)(param_1 + 0x18) + param_2 + 0x18) <

        *(uint *)(*(int *)(param_1 + 0x18) + 8 + param_2)) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + param_2 + 0x18) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + 8 + param_2);

    }

    if (*(uint *)(*(int *)(param_1 + 0x18) + 8 + param_2) <

        *(uint *)(*(int *)(param_1 + 0x18) + param_2 + 0x28)) {

      *(uint32_t /* width from decompiler */ *)(param_2 + *(int *)(param_1 + 0x18) + 0x28) =

           *(uint32_t /* width from decompiler */ *)(param_2 + 8 + *(int *)(param_1 + 0x18));

    }

  }

  return;

}
