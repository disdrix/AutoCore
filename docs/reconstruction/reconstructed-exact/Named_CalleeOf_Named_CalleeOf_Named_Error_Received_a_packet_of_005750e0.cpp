// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_005750e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005750e0
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x005750e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, while×3, return×3, do×1.
//  - Notable callees: FUN_00520330, FUN_005750e0, memmove.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_005750e0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  uint *puVar3;

  int iVar4;

  

  iVar4 = 0;

  piVar2 = (int *)(param_1 + 0x198);

  while ((*piVar2 != param_2 || (piVar2[1] != param_3))) {

    iVar4 = iVar4 + 1;

    piVar2 = piVar2 + 4;

    if (3 < iVar4) {

      return 0;

    }

  }

  iVar1 = (iVar4 + 0x1a) * 0x10;

  piVar2 = (int *)(iVar1 + param_1);

  if (*(int *)(iVar1 + param_1) != 0) {

    FUN_00520330(0);

    *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x6ec) = 0xffffffff;

  }

  *(uint32_t /* width from decompiler */ *)(iVar4 * 0x10 + 0x198 + param_1) = 0xffffffff;

  *piVar2 = 0;

  *(uint32_t /* width from decompiler */ *)(iVar4 * 0x10 + 0x19c + param_1) = 0xffffffff;

  piVar2 = *(int **)(param_1 + 0x1f8);

  *(char *)(param_1 + 0x1d8) = *(char *)(param_1 + 0x1d8) + -1;

  if (piVar2 != *(int **)(param_1 + 0x1fc)) {

    do {

      if ((*piVar2 == param_2) && (piVar2[1] == param_3)) {

        memmove(piVar2,piVar2 + 2,(*(int *)(param_1 + 0x1fc) - (int)(piVar2 + 2) >> 3) * 8);

        *(int *)(param_1 + 0x1fc) = *(int *)(param_1 + 0x1fc) + -8;

        break;

      }

      piVar2 = piVar2 + 2;

    } while (piVar2 != *(int **)(param_1 + 0x1fc));

  }

  if (*(int *)(param_1 + 0x194) == iVar4) {

    iVar4 = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x194) = 0;

    puVar3 = (uint *)(param_1 + 0x198);

    while ((*puVar3 & puVar3[1]) == 0xffffffff) {

      iVar4 = iVar4 + 1;

      puVar3 = puVar3 + 4;

      if (3 < iVar4) {

        return 1;

      }

    }

    *(int *)(param_1 + 0x194) = iVar4;

  }

  return 1;

}
