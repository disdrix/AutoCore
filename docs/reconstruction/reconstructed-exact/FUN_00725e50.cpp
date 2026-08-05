// =============================================================================
// FUN_00725e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00725e50
// Address:   0x00725e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00725e50 @ 0x00725e50
// Stable ID: aa_00725e50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×13, goto×3, return×2, for×1.
//  - Notable callees: FUN_0071eec0×2, FUN_0071f2e0×2, FUN_0071ee60, FUN_0071f010, FUN_007231a0, FUN_00725e50.
//  - Return sites: 2.

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

uint * __fastcall

FUN_00725e50(int param_1,char param_2,int param_3,uint *param_4,uint32_t /* width from decompiler */ param_5,uint param_6,

            char param_7,uint32_t /* width from decompiler */ param_8)



{

  char cVar1;

  int in_EAX;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint *puVar5;

  uint *puVar6;

  uint local_24 [9];

  

  local_24[0] = 0;

  local_24[1] = 0;

  local_24[2] = 0;

  local_24[3] = 0;

  local_24[4] = 0;

  local_24[5] = 0;

  local_24[6] = 0;

  local_24[7] = 0;

  local_24[8] = 0;

  if (((param_2 == '\0') || (iVar4 = *(int *)(param_3 + 0x70 + param_1 * 4), iVar4 == 0)) ||

     (*(int *)(iVar4 + 0x104) == 0)) {

    if (in_EAX == 0) goto LAB_00726055;

    if (param_7 == '\0') {

      if (param_2 == '\0') {

        cVar1 = FUN_0071f2e0(param_8);

        if (cVar1 == '\0') goto LAB_00726055;

      }

    }

    else if (param_2 == '\0') {

      iVar4 = *(int *)(param_3 + 0x70 + *(int *)(param_3 + 0x414) * 4);

      if ((iVar4 != 0) && (*(int *)(iVar4 + 0x104) != 0)) {

        FUN_007231a0();

      }

      if (*(int *)(param_3 + 0x70 + *(int *)(param_3 + 0x414) * 4) != 0) {

        pvVar2 = operator_new(0x58);

        if (pvVar2 == (void *)0x0) {

          uVar3 = 0;

        }

        else {

          uVar3 = FUN_0071ee60();

        }

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_3 + 0x70 + *(int *)(param_3 + 0x414) * 4) + 0x104) = uVar3;

        cVar1 = FUN_0071f2e0(0);

        if (cVar1 == '\0') {

          pvVar2 = *(void **)(*(int *)(param_3 + 0x70 + *(int *)(param_3 + 0x414) * 4) + 0x104);

          if (pvVar2 != (void *)0x0) {

            FUN_0071f010();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar2);

          }

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_3 + 0x70 + *(int *)(param_3 + 0x414) * 4) + 0x104) = 0;

          goto LAB_00726055;

        }

      }

      if (*(int *)(param_3 + 0x70 + *(int *)(param_3 + 0x414) * 4) != 0) {

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_3 + 0x70 + *(int *)(param_3 + 0x414) * 4) + 0x108) = 2;

        FUN_0071eec0();

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_3 + 0x70 + *(int *)(param_3 + 0x414) * 4) + 0x10c) = 1;

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_3 + 0x70 + *(int *)(param_3 + 0x414) * 4) + 0x110) =

             *(uint32_t /* width from decompiler */ *)(param_3 + 0x3dc);

      }

    }

  }

  else {

    FUN_0071eec0();

  }

  local_24[2] = *(uint *)(in_EAX + 0x1c);

  if ((uint)(*(int *)(in_EAX + 0x10) * 2) < local_24[2]) {

    local_24[2] = *(int *)(in_EAX + 0x10) * 2;

  }

  local_24[0] = 0x24;

  local_24[1] = param_6 | 0x10000;

  local_24[4] = 0;

LAB_00726055:

  puVar5 = local_24;

  puVar6 = param_4;

  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar6 = puVar6 + 1;

  }

  return param_4;

}
