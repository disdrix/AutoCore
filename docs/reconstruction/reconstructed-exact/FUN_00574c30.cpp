// =============================================================================
// FUN_00574c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00574c30
// Address:   0x00574c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00574c30 @ 0x00574c30
// Stable ID: aa_00574c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: do×2, if×2, while×2, for×1, return×1.
//  - Notable callees: strncpy×3, FUN_0051ffd0, FUN_00574c30.
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

void __thiscall FUN_00574c30(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *_Source;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  size_t _Count;

  int local_4;

  

  *param_2 = 0x800d;

  *(uint8_t *)(param_2 + 0xc) = *(uint8_t *)(param_1 + 0x194);

  param_2[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x160);

  param_2[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x164);

  *(uint8_t *)((int)param_2 + 0x31) = *(uint8_t *)(param_1 + 400);

  puVar6 = param_2 + 0x12;

  piVar5 = (int *)(param_1 + 0x1a0);

  piVar2 = param_2 + 4;

  local_4 = 4;

  do {

    *piVar2 = piVar5[-2];

    piVar2[1] = piVar5[-1];

    iVar1 = *piVar5;

    puVar7 = puVar6 + -5;

    for (iVar4 = 0x31; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar7 = 0;

      puVar7 = puVar7 + 1;

    }

    if (iVar1 == 0) {

      puVar6[-4] = 0xffffffff;

    }

    else {

      puVar6[-4] = *(uint32_t /* width from decompiler */ *)

                    (*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x34);

      *puVar6 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x708);

      puVar6[1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x70c);

      puVar6[-3] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x6f8);

      puVar6[-1] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x700);

      puVar6[-2] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x6fc);

      puVar6[2] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x704);

      puVar6[3] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x714);

      puVar6[4] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x710);

      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x27c))();

      puVar6[5] = uVar3;

      iVar4 = 0;

      puVar7 = puVar6 + 6;

      do {

        uVar3 = FUN_0051ffd0(iVar4);

        *puVar7 = uVar3;

        iVar4 = iVar4 + 1;

        puVar7 = puVar7 + 1;

      } while (iVar4 < 6);

      _Count = 0x40;

      _Source = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x160

                                    ))();

      strncpy((char *)(puVar6 + 0xc),_Source,_Count);

      iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1);

      if (iVar1 == 0) {

        strncpy((char *)(puVar6 + 0x1c),"",1);

      }

      else {

        strncpy((char *)(puVar6 + 0x1c),(char *)(iVar1 + 0xb4),0x40);

      }

    }

    piVar2 = piVar2 + 2;

    piVar5 = piVar5 + 4;

    puVar6 = puVar6 + 0x31;

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  return;

}
