// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00514390
// -----------------------------------------------------------------------------
// Stable ID: aa_00514390
// Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
// Address:   0x00514390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, while×1.
//  - Notable callees: FUN_00411900×2, Character_GetTechForPoolCalcs, FUN_00402c40, FUN_004c4070, FUN_004c4140, FUN_004c41c0, FUN_00514390, FUN_0052ada0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+3 other named callers)
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_00514390(int param_1,void *param_2,uint32_t /* width from decompiler */ param_3)



{

  byte bVar1;

  short sVar2;

  bool bVar3;

  short sVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  

  if ((0 < *(int *)((int)param_2 + 0x6b4)) || (*(int *)(*(int *)(param_1 + 0xa8) + 0x38) == 0x1a)) {

    return 1;

  }

  iVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x14))();

  if (((iVar5 == -1) ||

      (bVar1 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 0xac +

                                          (int)param_2) + 0x3c) + 0x532),

      uVar6 = (**(code **)(**(int **)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x14))(), uVar6 == bVar1))

     && ((uVar6 = *(uint *)(*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x3e0), uVar6 == 0xffffffff

         || (uVar6 == *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 0xac +

                                                 (int)param_2) + 0x3c) + 0x531))))) {

    iVar7 = (int)*(short *)(param_1 + 0xe8) + (int)*(short *)(param_1 + 0xea);

    iVar5 = 0x50;

    if (iVar7 < 0x51) {

      iVar5 = iVar7;

    }

    iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 4 + (int)param_2) +

                        0x27c))();

    if ((((((short)iVar5 <= iVar7) &&

          (sVar2 = *(short *)(param_1 + 0xec), sVar4 = FUN_004c4070(), sVar2 <= sVar4)) &&

         (sVar2 = *(short *)(param_1 + 0xee), sVar4 = FUN_004c41c0(), sVar2 <= sVar4)) &&

        ((sVar2 = *(short *)(param_1 + 0xf2), sVar4 = FUN_004c4140(), sVar2 <= sVar4 &&

         (sVar2 = *(short *)(param_1 + 0xf0), iVar5 = Character_GetTechForPoolCalcs(param_2),

         sVar2 <= (short)iVar5)))) &&

       ((((*(uint *)(param_1 + 0x17c) >> 0x13 & 1) == 0 ||

         ((iVar5 = *(int *)(*(int *)(param_1 + 0xa8) + 0x3c), iVar5 == 0 ||

          (*(int *)(iVar5 + 0x4ac) < 0)))) ||

        (iVar5 = *(int *)(*(int *)(param_1 + 0xa8) + 0x3c), iVar7 = *(int *)(iVar5 + 0x4b0),

        iVar5 = FUN_0052ada0(*(uint32_t /* width from decompiler */ *)(iVar5 + 0x4ac)), iVar7 <= iVar5)))) {

      if ((((char)param_3 != '\0') &&

          ((*(byte *)(*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x3f2) & 0x80) != 0)) &&

         ((iVar5 = *(int *)(*(int *)(*(int *)((int)param_2 + 4) + 4) + 0xa8 + (int)param_2),

          *(char *)(iVar5 + 0xf5) != '\0' || (*(char *)(iVar5 + 0xf6) != '\0')))) {

        param_3 = 0;

        FUN_00402c40();

        bVar3 = false;

        iVar5 = FUN_00411900(&param_3);

        while (iVar5 != 0) {

          if (*(int *)(iVar5 + 0x62c) == 0x26) {

            bVar3 = true;

            break;

          }

          iVar5 = FUN_00411900(&param_3);

        }

        *(uint8_t *)(*(int *)(param_1 + 0x70) + 0x1d) = 0;

        if (!bVar3) {

          return 0;

        }

      }

      return 1;

    }

  }

  return 0;

}
