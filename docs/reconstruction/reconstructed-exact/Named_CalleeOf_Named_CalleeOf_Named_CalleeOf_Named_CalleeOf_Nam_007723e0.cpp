// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007723e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007723e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x007723e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×12, do×6, while×6, return×3, for×2.
//  - Notable callees: CARRY4×3, FUN_00770490, FUN_00770710, FUN_00770ea0, FUN_007723e0, __allmul.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007723e0(int *param_1,int *param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint uVar4;

  uint *puVar5;

  int iVar6;

  uint uVar7;

  uint *puVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint uVar11;

  uint64_t uVar12;

  int local_101c;

  int local_1018;

  uint local_1000 [1023];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x7723ea;

  iVar9 = *param_1;

  if ((param_1[1] < *param_2 + 1) && (iVar3 = FUN_00770490(), iVar3 != 0)) {

    return iVar3;

  }

  puVar5 = (uint *)param_1[3];

  iVar3 = 0;

  puVar8 = local_1000;

  if (0 < *param_1) {

    iVar3 = *param_1;

    iVar6 = iVar3;

    do {

      *puVar8 = *puVar5;

      puVar8[1] = 0;

      puVar8 = puVar8 + 2;

      puVar5 = puVar5 + 1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

  }

  iVar1 = *param_2;

  iVar6 = iVar1 * 2 + 1;

  if (iVar3 < iVar6) {

    *puVar8 = 0;

    puVar8[1] = 0;

    puVar5 = puVar8 + 2;

    for (uVar7 = (iVar6 - iVar3) * 8 - 5U >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *puVar5 = *puVar8;

      puVar8 = puVar8 + 1;

      puVar5 = puVar5 + 1;

    }

  }

  iVar3 = 0;

  if (0 < iVar1) {

    puVar2 = (uint32_t /* width from decompiler */ *)param_2[3];

    puVar8 = local_1000;

    local_1018 = iVar1;

    do {

      uVar7 = *puVar8;

      puVar10 = puVar2;

      puVar5 = puVar8;

      local_101c = iVar1;

      if (0 < iVar1) {

        do {

          uVar12 = __allmul(*puVar10,0,uVar7 * param_3 & 0xfffffff,0);

          uVar4 = *puVar5;

          *puVar5 = *puVar5 + (uint)uVar12;

          puVar5[1] = puVar5[1] + (int)((ulonglong)uVar12 >> 0x20) +

                      (uint)CARRY4(uVar4,(uint)uVar12);

          local_101c = local_101c + -1;

          puVar10 = puVar10 + 1;

          puVar5 = puVar5 + 2;

        } while (local_101c != 0);

      }

      uVar4 = *puVar8 >> 0x1c | puVar8[1] << 4;

      puVar5 = puVar8 + 2;

      uVar7 = *puVar5;

      *puVar5 = *puVar5 + uVar4;

      puVar8[3] = puVar8[3] + (puVar8[1] >> 0x1c) + (uint)CARRY4(uVar7,uVar4);

      puVar8 = puVar8 + 2;

      local_1018 = local_1018 + -1;

      iVar3 = iVar1;

    } while (local_1018 != 0);

  }

  puVar8 = local_1000 + iVar3 * 2;

  iVar3 = iVar3 + 1;

  puVar5 = local_1000 + iVar3 * 2;

  if (iVar3 <= iVar6) {

    iVar3 = (iVar6 - iVar3) + 1;

    do {

      uVar4 = puVar8[1];

      uVar11 = *puVar8 >> 0x1c | uVar4 << 4;

      uVar7 = *puVar5;

      *puVar5 = *puVar5 + uVar11;

      puVar5[1] = puVar5[1] + (uVar4 >> 0x1c) + (uint)CARRY4(uVar7,uVar11);

      puVar8 = puVar8 + 2;

      puVar5 = puVar5 + 2;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  puVar5 = (uint *)param_1[3];

  puVar8 = local_1000 + iVar1 * 2;

  iVar3 = 0;

  if (iVar1 != -1 && -1 < iVar1 + 1) {

    do {

      *puVar5 = *puVar8 & 0xfffffff;

      iVar3 = iVar3 + 1;

      puVar5 = puVar5 + 1;

      puVar8 = puVar8 + 2;

    } while (iVar3 < *param_2 + 1);

  }

  if (iVar3 < iVar9) {

    for (iVar9 = iVar9 - iVar3; iVar9 != 0; iVar9 = iVar9 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

  }

  iVar9 = *param_2;

  *param_1 = iVar9 + 1;

  if (0 < iVar9 + 1) {

    do {

      if (*(int *)(param_1[3] + -4 + *param_1 * 4) != 0) break;

      iVar9 = *param_1 + -1;

      *param_1 = iVar9;

    } while (0 < iVar9);

  }

  if (*param_1 == 0) {

    param_1[2] = 0;

  }

  iVar9 = FUN_00770710();

  if (iVar9 == -1) {

    return 0;

  }

  iVar9 = FUN_00770ea0();

  return iVar9;

}
