// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00590800
// -----------------------------------------------------------------------------
// Stable ID: aa_00590800
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00590800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, do×3, while×3, for×2.
//  - Notable callees: FUN_005b8500×3, FUN_004a6d00, FUN_004b8890, FUN_0055a5f0, FUN_0058f780, FUN_00590800, FUN_00597720, FUN_005be2f0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00590800(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  int iVar4;

  float *pfVar5;

  uint32_t /* width from decompiler */ uVar6;

  int *piVar7;

  void *pvVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint32_t /* width from decompiler */ *local_8;

  

  if ((*(int *)(param_1 + 0xdc) != 0) && (*(char *)(DAT_00b037f0 + 0x14) != '\0')) {

    return 0;

  }

  iVar4 = FUN_005be400();

  FUN_00597720(param_1);

  *(uint32_t /* width from decompiler */ *)(iVar4 + 0x14) = param_2;

  if (*(int *)(param_1 + 0xe0) != 0) {

    pfVar5 = operator_new(4);

    if (pfVar5 == (float *)0x0) {

      pfVar5 = (float *)0x0;

    }

    else {

      *pfVar5 = g_flOne;

    }

    *(float **)(iVar4 + 0xe0) = pfVar5;

    *pfVar5 = **(float **)(param_1 + 0xe0);

  }

  if (*(int *)(param_1 + 0xdc) != 0) {

    uVar6 = FUN_0055a5f0();

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xdc) = uVar6;

  }

  piVar1 = (int *)(iVar4 + 0x34);

  *(int **)(iVar4 + 0x38) = piVar1;

  *piVar1 = (int)piVar1;

  iVar10 = *(int *)(param_1 + 0x38);

  if (iVar10 != param_1 + 0x34) {

    do {

      piVar7 = (int *)FUN_005b8500(param_2,iVar4);

      if (piVar7 != (int *)0x0) {

        piVar7[1] = (int)piVar1;

        *piVar7 = *piVar1;

        *(int **)(*piVar1 + 4) = piVar7;

        *piVar1 = (int)piVar7;

      }

      iVar10 = *(int *)(iVar10 + 4);

    } while (iVar10 != param_1 + 0x34);

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(iVar4 + 0x3bc);

  *(uint32_t /* width from decompiler */ **)(iVar4 + 0x6b0) = puVar2;

  *(uint32_t /* width from decompiler */ **)(iVar4 + 0x6ac) = puVar2;

  *(uint32_t /* width from decompiler */ **)(iVar4 + 0x28) = puVar2;

  piVar1 = (int *)(iVar4 + 0x3c4);

  *(int **)(iVar4 + 0x3c8) = piVar1;

  *piVar1 = (int)piVar1;

  for (iVar10 = *(int *)(param_1 + 0x3c8); iVar10 != param_1 + 0x3c4; iVar10 = *(int *)(iVar10 + 4))

  {

    piVar7 = (int *)FUN_005b8500(param_2,puVar2);

    if (piVar7 != (int *)0x0) {

      piVar7[1] = (int)piVar1;

      *piVar7 = *piVar1;

      *(int **)(*piVar1 + 4) = piVar7;

      *piVar1 = (int)piVar7;

    }

  }

  puVar11 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x6b0);

  local_8 = puVar2;

  if (puVar11 != (uint32_t /* width from decompiler */ *)(param_1 + 0x3bc)) {

    do {

      pvVar8 = operator_new(0x3cc);

      if (pvVar8 == (void *)0x0) {

        puVar9 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar9 = (uint32_t /* width from decompiler */ *)FUN_004a6d00();

      }

      puVar12 = puVar11;

      puVar13 = puVar9;

      for (iVar10 = 0xf3; iVar10 != 0; iVar10 = iVar10 + -1) {

        *puVar13 = *puVar12;

        puVar12 = puVar12 + 1;

        puVar13 = puVar13 + 1;

      }

      piVar1 = puVar9 + 2;

      puVar9[3] = piVar1;

      *piVar1 = (int)piVar1;

      local_8[0xbd] = puVar9;

      puVar9[0xbc] = local_8;

      puVar9[0xbd] = puVar2;

      *(uint32_t /* width from decompiler */ **)(iVar4 + 0x6ac) = puVar9;

      puVar12 = (uint32_t /* width from decompiler */ *)puVar11[3];

      if (puVar12 != puVar11 + 2) {

        do {

          piVar7 = (int *)FUN_005b8500(param_2,puVar9);

          if (piVar7 != (int *)0x0) {

            piVar7[1] = (int)piVar1;

            *piVar7 = *piVar1;

            *(int **)(*piVar1 + 4) = piVar7;

            *piVar1 = (int)piVar7;

          }

          puVar12 = (uint32_t /* width from decompiler */ *)puVar12[1];

        } while (puVar12 != puVar11 + 2);

      }

      puVar11 = (uint32_t /* width from decompiler */ *)puVar11[0xbd];

      local_8 = puVar9;

    } while (puVar11 != (uint32_t /* width from decompiler */ *)(param_1 + 0x3bc));

  }

  if (((((*(byte *)(param_1 + 0x90e) & 0x40) == 0) ||

       (*(uint32_t /* width from decompiler */ *)(iVar4 + 0x914) = 0, (*(byte *)(param_1 + 0x90e) & 0x40) == 0)) &&

      ((*(byte *)(iVar4 + 0x90e) & 0x20) == 0)) && (cVar3 = FUN_0058f780(0), cVar3 == '\0')) {

    FUN_005be2f0(iVar4);

    return 0;

  }

  FUN_004b8890(iVar4);

  return iVar4;

}
