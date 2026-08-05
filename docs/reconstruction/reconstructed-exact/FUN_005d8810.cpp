// =============================================================================
// FUN_005d8810
// -----------------------------------------------------------------------------
// Stable ID: aa_005d8810
// Address:   0x005d8810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d8810 @ 0x005d8810
// Stable ID: aa_005d8810
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×10, do×1, while×1, return×1.
//  - Notable callees: CARRY4×3, FUN_0063f610×3, ABS, FUN_005d8810, FUN_0063f600, FUN_0063f620, FUN_006404a0, FUN_006413d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_005d8810(int param_1,float param_2)



{

  uint *puVar1;

  int *piVar2;

  uint uVar3;

  char *pcVar4;

  uint uVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  bool bVar9;

  float10 fVar10;

  uint64_t uVar11;

  uint8_t uStack_9;

  float local_8;

  int iStack_4;

  

  if (*(char *)(param_1 + 0x34) != '\0') {

    *(uint8_t *)(param_1 + 0x58) = 0;

    uVar11 = FUN_0063f610();

    iVar6 = (int)((ulonglong)uVar11 >> 0x20);

    uVar3 = (uint)uVar11;

    uVar5 = uVar3 - *(uint *)(param_1 + 0x38);

    puVar1 = (uint *)(param_1 + 0x40);

    uVar7 = *puVar1;

    *puVar1 = *puVar1 + uVar5;

    *(int *)(param_1 + 0x44) =

         *(int *)(param_1 + 0x44) +

         ((iVar6 - *(int *)(param_1 + 0x3c)) - (uint)(uVar3 < *(uint *)(param_1 + 0x38))) +

         (uint)CARRY4(uVar7,uVar5);

    uVar5 = uVar3 - *(uint *)(param_1 + 0x48);

    puVar1 = (uint *)(param_1 + 0x50);

    uVar7 = *puVar1;

    *puVar1 = *puVar1 + uVar5;

    *(int *)(param_1 + 0x54) =

         *(int *)(param_1 + 0x54) +

         ((iVar6 - *(int *)(param_1 + 0x4c)) - (uint)(uVar3 < *(uint *)(param_1 + 0x48))) +

         (uint)CARRY4(uVar7,uVar5);

    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;

  }

  local_8 = DAT_00a0f6d0;

  if (*(char *)(param_1 + 0x34) != '\0') {

    uVar7 = *(uint *)(param_1 + 0x40);

    iVar6 = *(int *)(param_1 + 0x44);

    if (*(char *)(param_1 + 0x58) != '\0') {

      uVar11 = FUN_0063f610();

      uVar3 = (uint)uVar11 - *(uint *)(param_1 + 0x38);

      bVar9 = CARRY4(uVar7,uVar3);

      uVar7 = uVar7 + uVar3;

      iVar6 = iVar6 + (((int)((ulonglong)uVar11 >> 0x20) - *(int *)(param_1 + 0x3c)) -

                      (uint)((uint)uVar11 < *(uint *)(param_1 + 0x38))) + (uint)bVar9;

    }

    uVar11 = FUN_0063f620();

    fVar10 = (float10)FUN_0063f600(uVar7,iVar6,uVar11);

    local_8 = (float)(fVar10 * (float10)DAT_00a0f520);

  }

  *(uint8_t *)(param_1 + 0x34) = 1;

  if (_DAT_009db1cc < ABS(param_2)) {

    local_8 = param_2;

  }

  iStack_4 = 0;

  if (0 < *(int *)(param_1 + 0x18)) {

    iVar6 = 0;

    do {

      piVar2 = *(int **)(*(int *)(param_1 + 0x14) + iVar6);

      iVar8 = *(int *)(param_1 + 0x14) + iVar6;

      if (piVar2 != (int *)0x0) {

        pcVar4 = (char *)(**(code **)(*piVar2 + 4))(&param_2);

        if (*pcVar4 != '\0') {

          (**(code **)(**(int **)(iVar8 + 4) + 0x34))(local_8);

          if (*(int *)(iVar8 + 0xc) != 0) {

            FUN_006413d0(&uStack_9);

          }

          if (*(int *)(iVar8 + 0x10) != 0) {

            FUN_006404a0();

          }

        }

      }

      iStack_4 = iStack_4 + 1;

      iVar6 = iVar6 + 0x14;

    } while (iStack_4 < *(int *)(param_1 + 0x18));

  }

  if (*(char *)(param_1 + 0x34) != '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

    *(uint8_t *)(param_1 + 0x58) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

    *(uint8_t *)(param_1 + 0x58) = 1;

    uVar11 = FUN_0063f610();

    *(uint64_t *)(param_1 + 0x38) = uVar11;

    *(uint64_t *)(param_1 + 0x48) = uVar11;

  }

  return;

}
