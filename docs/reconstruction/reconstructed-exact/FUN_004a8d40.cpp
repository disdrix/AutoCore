// =============================================================================
// FUN_004a8d40
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8d40
// Address:   0x004a8d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a8d40 @ 0x004a8d40
// Stable ID: aa_004a8d40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, return×1.
//  - Notable callees: FUN_004a8d40, FUN_005be7f0, FUN_005be840.
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

void __thiscall FUN_004a8d40(int param_1,uint param_2,uint param_3,int param_4,int param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  void **ppvVar6;

  int iVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a120b;

  ppvVar6 = &local_c;

  param_2 = param_2 & ((int)param_2 < 1) - 1;

  param_3 = ((int)param_3 < 1) - 1 & param_3;

  if (*(int *)(param_1 + 0x10) + -1 <= param_4) {

    param_4 = *(int *)(param_1 + 0x10) + -1;

  }

  if (*(int *)(param_1 + 0x14) + -1 <= param_5) {

    param_5 = *(int *)(param_1 + 0x14) + -1;

  }

  iVar4 = *(int *)(param_1 + 900) + -1;

  param_4 = (int)(param_4 + (param_4 >> 0x1f & 0xfU)) >> 4;

  iVar7 = (int)(param_2 + ((int)param_2 >> 0x1f & 0xfU)) >> 4;

  if (iVar4 <= param_4) {

    param_4 = iVar4;

  }

  iVar4 = *(int *)(param_1 + 0x388) + -1;

  iVar2 = (int)(param_5 + (param_5 >> 0x1f & 0xfU)) >> 4;

  local_c = ExceptionList;

  if (iVar2 < iVar4) {

    iVar4 = iVar2;

  }

  for (; iVar2 = (int)(param_3 + ((int)param_3 >> 0x1f & 0xfU)) >> 4, ExceptionList = ppvVar6,

      iVar7 <= param_4; iVar7 = iVar7 + 1) {

    for (; iVar2 <= iVar4; iVar2 = iVar2 + 1) {

      puVar1 = *(uint32_t /* width from decompiler */ **)

                (*(int *)(param_1 + 0x38c) + (*(int *)(param_1 + 900) * iVar2 + iVar7) * 4);

      if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)*puVar1)(1);

        pvVar3 = operator_new(0x180d8);

        uVar5 = 0;

        uStack_4 = 0;

        if (pvVar3 != (void *)0x0) {

          uVar5 = FUN_005be7f0();

        }

        uStack_4 = 0xffffffff;

        FUN_005be840(iVar7,iVar2,param_1);

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x38c) + (*(int *)(param_1 + 900) * iVar2 + iVar7) * 4) =

             uVar5;

      }

    }

    ppvVar6 = ExceptionList;

  }

  ExceptionList = local_c;

  return;

}
