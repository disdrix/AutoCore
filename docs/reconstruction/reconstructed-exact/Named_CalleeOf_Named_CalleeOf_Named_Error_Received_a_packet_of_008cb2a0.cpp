// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_008cb2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008cb2a0
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x008cb2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_008ca6c0, FUN_008caf50, FUN_008cb2a0.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_008cb2a0(uint32_t /* width from decompiler */ param_1)



{

  byte bVar1;

  char cVar2;

  int in_EAX;

  char *pcVar3;

  int *piVar4;

  uint16_t *puVar5;

  char *pcVar6;

  int *unaff_ESI;

  uint64_t uVar7;

  int iVar8;

  

  if (in_EAX == 0) {

    FUN_008caf50(param_1);

  }

  else {

    bVar1 = *(byte *)(in_EAX + 4);

    unaff_ESI[0x156] = (uint)bVar1;

    iVar8 = 0;

    if (bVar1 != 0) {

      puVar5 = (uint16_t *)(in_EAX + 0x148);

      pcVar6 = (char *)(in_EAX + 0x48);

      piVar4 = unaff_ESI + 0x15d;

      do {

        piVar4[-4] = *(int *)(puVar5 + -0xa0);

        pcVar3 = pcVar6;

        do {

          cVar2 = *pcVar3;

          pcVar3[(int)piVar4 - (int)pcVar6] = cVar2;

          pcVar3 = pcVar3 + 1;

        } while (cVar2 != '\0');

        *(uint16_t *)(piVar4 + -2) = *puVar5;

        iVar8 = iVar8 + 1;

        puVar5 = puVar5 + 2;

        pcVar6 = pcVar6 + 0x10;

        piVar4 = piVar4 + 0xf;

      } while (iVar8 < unaff_ESI[0x156]);

    }

  }

  if ((int *)unaff_ESI[0x252] != (int *)0x0) {

    uVar7 = (**(code **)(*(int *)unaff_ESI[0x252] + 0x44c))();

    *(uint64_t *)(unaff_ESI + 0x154) = uVar7;

  }

  FUN_008ca6c0();

  if ((int *)unaff_ESI[0x252] != (int *)0x0) {

    (**(code **)(*(int *)unaff_ESI[0x252] + 0x448))(unaff_ESI[0x154],unaff_ESI[0x155]);

    uVar7 = (**(code **)(*(int *)unaff_ESI[0x252] + 0x44c))();

    *(uint64_t *)(unaff_ESI + 0x154) = uVar7;

  }

                    /* WARNING: Could not recover jumptable at 0x008cb37c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_ESI + 0x34c))();

  return;

}
