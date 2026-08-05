// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_00890710
// -----------------------------------------------------------------------------
// Stable ID: aa_00890710
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x00890710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, while×1.
//  - Notable callees: FUN_004113b0×2, FUN_00411c60, FUN_00427d20, FUN_004294f0, FUN_00890710, LeaveCriticalSection.
//  - Return sites: 2.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_00890710(void)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *unaff_EBX;

  int iVar5;

  int *piStack_34;

  int local_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t auStack_10 [12];

  

  if (unaff_EBX[0x14c] == 0) {

    if (unaff_EBX[0x14e] != 0) {

      (**(code **)(*(int *)unaff_EBX[0x14e] + 4))(0);

      return;

    }

  }

  else {

    cVar1 = FUN_00411c60();

    if ((cVar1 != '\0') || (cVar1 = FUN_00427d20(0,&DAT_00d17910), cVar1 != '\0')) {

      if (unaff_EBX[0x14e] != 0) {

        (**(code **)(*(int *)unaff_EBX[0x14e] + 4))(1);

      }

      iVar5 = 0;

      local_28 = 0;

      local_24 = 0;

      local_30 = 0;

      FUN_004294f0();

      iVar2 = FUN_004113b0(unaff_EBX + 0x143,&piStack_34);

      piVar4 = piStack_34;

      while (piStack_34 = piVar4, iVar2 == 0) {

        if ((piVar4 != (int *)0x0) && (cVar1 = (**(code **)(*piVar4 + 0x3d8))(), cVar1 != '\0')) {

          if ((DAT_00d1790c == '\0') || (piVar4 == DAT_00d17910)) {

            (**(code **)(*piVar4 + 4))(1);

            (**(code **)(*piVar4 + 0x114))(&uStack_2c);

            iVar2 = (**(code **)(*piVar4 + 0x140))(&local_28,1);

            piStack_34 = (int *)((int)piStack_34 + *(int *)(iVar2 + 4));

            piVar3 = (int *)(**(code **)(*piVar4 + 0x140))(&local_28,1);

            if (iVar5 < *piVar3) {

              piVar4 = (int *)(**(code **)(*piVar4 + 0x140))(auStack_10,1);

              iVar5 = *piVar4;

            }

          }

          else {

            (**(code **)(*piVar4 + 4))(0);

          }

        }

        iVar2 = FUN_004113b0(unaff_EBX + 0x143,&piStack_34);

        piVar4 = piStack_34;

      }

      if ((char)unaff_EBX[0x14d] != '\0') {

        *(uint8_t *)(unaff_EBX + 0x14d) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EBX + 0x144));

      }

      uStack_2c = local_24;

      local_30 = iVar5;

      (**(code **)(*unaff_EBX + 8))(&local_30);

      if (unaff_EBX[0x14e] != 0) {

        (**(code **)(*(int *)unaff_EBX[0x14e] + 0x94))();

      }

    }

  }

  return;

}
