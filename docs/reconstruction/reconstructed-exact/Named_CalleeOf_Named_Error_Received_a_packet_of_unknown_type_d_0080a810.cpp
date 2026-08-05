// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080a810
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a810
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0080a810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_0080a810, FUN_00899300, FUN_008b1430.
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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080a810(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = 0;

  DAT_00d1b4a8 = 0;

  if (DAT_00d1b4ac != (void *)0x0) {

    operator_delete__(DAT_00d1b4ac);

  }

  DAT_00d1b4ac = (void *)0x0;

  DAT_00d1b4a8 = *(int *)(param_1 + 4);

  if (0 < DAT_00d1b4a8) {

    DAT_00d1b4ac = operator_new__(DAT_00d1b4a8 * 0x18);

    iVar4 = 0;

    if (0 < DAT_00d1b4a8) {

      do {

        puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + iVar3);

        puVar1 = (uint32_t /* width from decompiler */ *)(iVar3 + (int)DAT_00d1b4ac);

        *puVar1 = *puVar2;

        puVar1[1] = puVar2[1];

        puVar1[2] = puVar2[2];

        puVar1[3] = puVar2[3];

        puVar1[4] = puVar2[4];

        puVar1[5] = puVar2[5];

        if (DAT_00d1b8e8 != 0) {

          FUN_008b1430();

        }

        if (DAT_00d1b8c4 != 0) {

          FUN_00899300(DAT_00d1b8c4);

        }

        iVar4 = iVar4 + 1;

        iVar3 = iVar3 + 0x18;

      } while (iVar4 < DAT_00d1b4a8);

    }

    if (*(void **)(param_1 + 8) != (void *)0x0) {

      operator_delete__(*(void **)(param_1 + 8));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  }

  return;

}
