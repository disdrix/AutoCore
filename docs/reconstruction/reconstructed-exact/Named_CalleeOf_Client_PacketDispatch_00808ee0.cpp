// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_00808ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00808ee0
// Callee of Client_PacketDispatch
// Address:   0x00808ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×11, return×1.
//  - Notable callees: CONCAT22, FUN_00808ee0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
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

void Named_CalleeOf_Client_PacketDispatch_00808ee0(int param_1)



{

  byte *pbVar1;

  uint16_t uVar2;

  int iVar3;

  char cVar4;

  int *piVar5;

  int iVar6;

  uint16_t extraout_var;

  int iVar7;

  int iVar8;

  int unaff_EDI;

  

  piVar5 = (int *)CVOGReaction_ResolveObjectTarget

                            (*(uint8_t *)(unaff_EDI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),

                             *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc));

  if (piVar5 != (int *)0x0) {

    (**(code **)(*piVar5 + 0x240))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18));

    (**(code **)(*piVar5 + 0x248))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c));

    iVar6 = (**(code **)(*piVar5 + 0x1d4))();

    if (iVar6 != 0) {

      iVar3 = *(int *)(unaff_EDI + 0x20);

      iVar7 = *(int *)(iVar6 + 0x148);

      iVar8 = iVar3;

      if (iVar7 <= iVar3) {

        iVar8 = iVar7;

      }

      if (iVar8 < 1) {

        iVar7 = 0;

      }

      else if (iVar3 < iVar7) {

        iVar7 = iVar3;

      }

      *(int *)(iVar6 + 0x144) = iVar7;

      iVar3 = *(int *)(unaff_EDI + 0x24);

      *(int *)(iVar6 + 0x148) = iVar3;

      if (iVar3 < iVar7) {

        *(int *)(iVar6 + 0x144) = iVar3;

      }

    }

    (**(code **)(*piVar5 + 0x18c))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x30));

    piVar5 = (int *)(**(code **)(*piVar5 + 0x1d8))();

    if (piVar5 != (int *)0x0) {

      (**(code **)(*piVar5 + 0xac))(CONCAT22(extraout_var,*(uint16_t *)(unaff_EDI + 0x28)));

      uVar2 = *(uint16_t *)(unaff_EDI + 0x2a);

      pbVar1 = (byte *)(*(int *)(piVar5[1] + 4) + 0x180 + (int)piVar5);

      *pbVar1 = *pbVar1 | 0x80;

      *(uint16_t *)((int)piVar5 + 0x12e) = uVar2;

      iVar6 = (**(code **)(*(int *)(*(int *)(piVar5[1] + 4) + 4 + (int)piVar5) + 0x1dc))();

      if (iVar6 != 0) {

        *(uint32_t /* width from decompiler */ *)(iVar6 + 0x730) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c);

      }

    }

    if (*(int *)(param_1 + 0xe98) != 0) {

      iVar3 = *(int *)(param_1 + 0xe98);

      iVar7 = *(int *)(*(int *)(iVar3 + 4) + 4);

      iVar6 = iVar7 + 0x164 + iVar3;

      if ((((*(int *)(unaff_EDI + 8) == *(int *)(iVar7 + 0x164 + iVar3)) &&

           (*(int *)(unaff_EDI + 0xc) == *(int *)(iVar6 + 4))) &&

          (*(char *)(unaff_EDI + 0x10) == *(char *)(iVar6 + 8))) &&

         (*(int *)(param_1 + 0x1034) != 0)) {

        cVar4 = (**(code **)(**(int **)(param_1 + 0x1034) + 0x3d8))();

        if (cVar4 != '\0') {

          piVar5 = *(int **)(param_1 + 0x1034);

          (**(code **)(*piVar5 + 0x448))();

          (**(code **)(*piVar5 + 0x34c))();

        }

      }

    }

  }

  return;

}
