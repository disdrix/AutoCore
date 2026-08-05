// =============================================================================
// FUN_005857a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005857a0
// Address:   0x005857a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005857a0 @ 0x005857a0
// Stable ID: aa_005857a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×1, while×1.
//  - Notable callees: FUN_00583f10, FUN_005857a0, FUN_0058fc60, FUN_0074ecf0, __RTDynamicCast.
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

void __thiscall FUN_005857a0(int *param_1,int param_2)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  

  if (param_1[2] != 0) {

    FUN_00583f10(0,param_1[2],0,0xffffffff);

    FUN_0058fc60(param_1);

    (**(code **)(*param_1 + 0x18))(0);

    if (*(short *)(*(int *)(*(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1) + 0x3c) + 0x3f4

                  ) == 3) {

      iVar2 = __RTDynamicCast(param_1[2],0,&gfxBody::RTTI_Type_Descriptor,

                              &CVOGTreegfxBody::RTTI_Type_Descriptor,0);

      if (iVar2 != 0) {

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0x154) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8d4);

      }

    }

    param_1[2] = 0;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x20) = 0;

    if ((param_1[9] != 0) && (param_1[10] != 0)) {

      *(int *)(param_2 + 0x1c) = param_1[10];

      *(int *)(param_2 + 0x18) = param_1[9];

      if (((char)param_1[3] == '\0') || ((iVar2 = param_1[0x1e], iVar2 < 0 || (0x12 < iVar2)))) {

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x24) = 0;

      }

      else {

        *(int *)(param_2 + 0x24) = param_1[iVar2 + 0xb];

        param_1[param_1[0x1e] + 0xb] = 0;

      }

    }

    piVar3 = param_1 + 0xb;

    iVar2 = 0x13;

    do {

      if (*piVar3 != 0) {

        if ((int *)param_1[9] != (int *)0x0) {

          (**(code **)(*(int *)param_1[9] + 0x10))(*piVar3);

        }

        pvVar1 = (void *)*piVar3;

        if (pvVar1 != (void *)0x0) {

          FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        *piVar3 = 0;

      }

      piVar3 = piVar3 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    param_1[10] = 0;

    param_1[9] = 0;

  }

  return;

}
