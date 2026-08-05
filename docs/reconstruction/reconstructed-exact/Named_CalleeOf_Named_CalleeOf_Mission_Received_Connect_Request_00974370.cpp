// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Received_Connect_Request_00974370
// -----------------------------------------------------------------------------
// Stable ID: aa_00974370
// Callee of Named_CalleeOf_Mission_Received_Connect_Request_8x
// Address:   0x00974370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Received_Connect_Request_8x: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, return×2, while×2.
//  - Notable callees: CONCAT31×3, CONCAT11×2, CONCAT21×2, FUN_00974370, __aullrem.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Received_Connect_Request_8x
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

uint Named_CalleeOf_Named_CalleeOf_Mission_Received_Connect_Request_00974370(int *param_1)



{

  int iVar1;

  int *piVar2;

  void *pvVar3;

  int iVar4;

  int *unaff_EBX;

  int *piVar5;

  int *piVar6;

  bool bVar7;

  

  iVar1 = __aullrem(CONCAT31(CONCAT21(CONCAT11((char)unaff_EBX[1],

                                               *(uint8_t *)((int)unaff_EBX + 5)),

                                      *(uint8_t *)((int)unaff_EBX + 6)),

                             *(uint8_t *)((int)unaff_EBX + 7)),

                    CONCAT31(CONCAT21(CONCAT11((char)*unaff_EBX,*(uint8_t *)((int)unaff_EBX + 1))

                                      ,*(uint8_t *)((int)unaff_EBX + 2)),

                             *(uint8_t *)((int)unaff_EBX + 3)),param_1[1],0);

  piVar2 = *(int **)(*param_1 + iVar1 * 4);

  do {

    if (piVar2 == (int *)0x0) {

      if ((param_1[2] == 0) || (param_1[3] < *(int *)(param_1[2] + 8) + 0xc)) {

        piVar2 = operator_new(0xc);

        if (piVar2 == (int *)0x0) {

          piVar2 = (int *)0x0;

        }

        else {

          pvVar3 = operator_new__(param_1[3]);

          piVar2[1] = (int)pvVar3;

        }

        *piVar2 = param_1[2];

        piVar2[2] = 0;

        param_1[2] = (int)piVar2;

      }

      iVar4 = param_1[2];

      piVar2 = (int *)(*(int *)(iVar4 + 4) + *(int *)(iVar4 + 8));

      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0xc;

      *piVar2 = *unaff_EBX;

      piVar2[1] = unaff_EBX[1];

      piVar2[2] = *(int *)(*param_1 + iVar1 * 4);

      *(int **)(*param_1 + iVar1 * 4) = piVar2;

      return CONCAT31((int3)((uint)piVar2 >> 8),1);

    }

    iVar4 = 2;

    bVar7 = true;

    piVar5 = piVar2;

    piVar6 = unaff_EBX;

    do {

      if (iVar4 == 0) break;

      iVar4 = iVar4 + -1;

      bVar7 = *piVar5 == *piVar6;

      piVar5 = piVar5 + 1;

      piVar6 = piVar6 + 1;

    } while (bVar7);

    if (bVar7) {

      return (uint)piVar2 & 0xffffff00;

    }

    piVar2 = (int *)piVar2[2];

  } while( true );

}
