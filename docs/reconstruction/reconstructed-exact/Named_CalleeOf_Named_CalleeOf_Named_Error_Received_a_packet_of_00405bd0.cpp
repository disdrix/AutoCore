// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00405bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00405bd0
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x00405bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1, goto×1.
//  - Notable callees: FUN_00405bd0, FUN_004069f0, FUN_00409820.
//  - Return sites: 2.

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

void Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00405bd0(void)



{

  bool bVar1;

  uint *in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ *local_4;

  

  local_4 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 4);

  bVar1 = true;

  local_8 = 1;

  if (*(char *)((int)local_4[1] + 0x29) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)local_4[1];

    do {

      local_4 = puVar2;

      if (((int)local_4[5] < (int)in_EAX[1]) ||

         (((int)local_4[5] <= (int)in_EAX[1] && ((uint)local_4[4] <= *in_EAX)))) {

        puVar2 = (uint32_t /* width from decompiler */ *)local_4[2];

        bVar1 = false;

        local_8 = 0;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*local_4;

        bVar1 = true;

        local_8 = 1;

      }

    } while (*(char *)((int)puVar2 + 0x29) == '\0');

  }

  if (bVar1) {

    if (local_4 == (uint32_t /* width from decompiler */ *)**(int **)(unaff_EBX + 4)) {

      local_8 = 1;

      goto LAB_00405c53;

    }

    FUN_00409820();

  }

  if (((int)in_EAX[1] < (int)local_4[5]) ||

     (((int)in_EAX[1] <= (int)local_4[5] && (*in_EAX <= (uint)local_4[4])))) {

    *unaff_ESI = local_4;

    *(uint8_t *)(unaff_ESI + 1) = 0;

    return;

  }

LAB_00405c53:

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_004069f0(&local_4,local_8,in_EAX);

  *unaff_ESI = *puVar2;

  *(uint8_t *)(unaff_ESI + 1) = 1;

  return;

}
