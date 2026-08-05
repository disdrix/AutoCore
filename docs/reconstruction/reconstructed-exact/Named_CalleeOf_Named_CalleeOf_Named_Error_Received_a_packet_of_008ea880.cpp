// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_008ea880
// -----------------------------------------------------------------------------
// Stable ID: aa_008ea880
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x008ea880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: Client_MaybeShowFirstTimeTip, FUN_008ea880.
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

void Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_008ea880(void)



{

  int iVar1;

  int in_EAX;

  int iVar2;

  int *piVar3;

  int *unaff_EDI;

  float10 fVar4;

  

  unaff_EDI[0x151] = in_EAX;

  (**(code **)(*unaff_EDI + 0x448))();

  if (unaff_EDI[0x151] != 0) {

    piVar3 = unaff_EDI + 0x186;

    iVar2 = 4;

    do {

      if (piVar3[-4] != 0) {

        iVar1 = *(int *)piVar3[-4];

        fVar4 = (float10)(**(code **)(*(int *)piVar3[-4] + 0x3c8))();

        (**(code **)(iVar1 + 0x3b0))((float)fVar4);

      }

      if (*piVar3 != 0) {

        iVar1 = *(int *)*piVar3;

        fVar4 = (float10)(**(code **)(*(int *)*piVar3 + 0x3c8))();

        (**(code **)(iVar1 + 0x3b0))((float)fVar4);

      }

      piVar3 = piVar3 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    Client_MaybeShowFirstTimeTip(0xe);

  }

                    /* WARNING: Could not recover jumptable at 0x008ea903. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_EDI + 0x34c))();

  return;

}
