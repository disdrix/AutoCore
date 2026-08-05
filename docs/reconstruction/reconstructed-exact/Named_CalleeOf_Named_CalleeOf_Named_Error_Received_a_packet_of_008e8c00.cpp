// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_008e8c00
// -----------------------------------------------------------------------------
// Stable ID: aa_008e8c00
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x008e8c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×1.
//  - Notable callees: FUN_008e8c00.
//  - Return sites: 1.

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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_008e8c00(int param_1)



{

  char cVar1;

  int iVar2;

  int in_EAX;

  void *pvVar3;

  char *pcVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint *puVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int local_4;

  

  piVar8 = (int *)(param_1 + 0x52c);

  puVar9 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x48);

  puVar7 = (uint *)(in_EAX + 0x10);

  puVar6 = (uint32_t /* width from decompiler */ *)(in_EAX + 100);

  local_4 = 4;

  do {

    if ((*puVar7 & puVar7[1]) != 0xffffffff) {

      if (*piVar8 == 0) {

        pvVar3 = operator_new(0xd0);

        *piVar8 = (int)pvVar3;

      }

      *(uint32_t /* width from decompiler */ *)*piVar8 = puVar9[-4];

      iVar2 = *piVar8;

      *(uint *)(iVar2 + 8) = *puVar7;

      *(uint *)(iVar2 + 0xc) = puVar7[1];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x1c) = *puVar9;

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x10) = puVar9[-3];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x18) = puVar9[-1];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x14) = puVar9[-2];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x24) = puVar9[2];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x28) = puVar9[3];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x2c) = puVar9[4];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x30) = puVar9[5];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x34) = puVar6[-1];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x38) = *puVar6;

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x3c) = puVar6[1];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x40) = puVar6[2];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x44) = puVar6[3];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + 0x48) = puVar6[4];

      pcVar5 = (char *)(puVar9 + 0xc);

      pcVar4 = (char *)(*piVar8 + 0x4c);

      do {

        cVar1 = *pcVar5;

        *pcVar4 = cVar1;

        pcVar5 = pcVar5 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      pcVar5 = (char *)(puVar9 + 0x1c);

      pcVar4 = (char *)(*piVar8 + 0x8c);

      do {

        cVar1 = *pcVar5;

        *pcVar4 = cVar1;

        pcVar5 = pcVar5 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

    }

    puVar7 = puVar7 + 2;

    piVar8 = piVar8 + 1;

    puVar6 = puVar6 + 0x31;

    puVar9 = puVar9 + 0x31;

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  return;

}
