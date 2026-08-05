// =============================================================================
// FUN_0078b310
// -----------------------------------------------------------------------------
// Stable ID: aa_0078b310
// Address:   0x0078b310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078b310 @ 0x0078b310
// Stable ID: aa_0078b310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×10, return×2, do×1, while×1.
//  - Notable callees: FUN_0041c7e0×3, FUN_0078b310, FUN_0079c860, FUN_007b5dd0.
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

void __fastcall FUN_0078b310(int *param_1)



{

  bool bVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  int unaff_EBX;

  int unaff_EDI;

  float fVar7;

  uint8_t *puStack_58;

  int *local_50;

  uint local_4c;

  int local_48;

  void *local_44;

  int local_1c;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_58 = &stack0xfffffffc;

  local_c = 0xffffffff;

  puStack_10 = &LAB_009b7f0e;

  local_14 = ExceptionList;

  local_4c = 0;

  ExceptionList = &local_14;

  if (0 < param_1[0x15b]) {

    do {

      uVar3 = local_4c & 0x80000001;

      if ((int)uVar3 < 0) {

        uVar3 = (uVar3 - 1 | 0xfffffffe) + 1;

      }

      if ((uVar3 != 1) || (local_50 = param_1 + 0x21f, (char)param_1[0x21f] == '\0')) {

        local_50 = param_1 + 0x1de;

      }

      fVar7 = (float)DAT_00d1e818 * (float)(int)(param_1[0x262] * local_4c + param_1[0x260]) *

              DAT_00aaa67c;

      iVar4 = (int)((float)DAT_00d1e81c * (float)(int)(param_1[0x263] * local_4c + param_1[0x261]) *

                   DAT_00aaa678);

      local_1c = iVar4;

      puVar5 = operator_new(0x10);

      local_48 = DAT_00afa278;

      DAT_00afa278 = DAT_00afa278 + 1;

      bVar1 = false;

      *puVar5 = 0xffffffff;

      puVar5[1] = 0xffffffff;

      if ((char)*local_50 != '\0') {

        local_44 = operator_new(0x4cc);

        uVar6 = 0;

        local_c = 0;

        if (local_44 != (void *)0x0) {

          uVar6 = FUN_0079c860();

          iVar4 = local_1c;

        }

        local_c = 0xffffffff;

        puVar5[3] = uVar6;

        (**(code **)(*param_1 + 0xa8))(uVar6);

        (**(code **)(*(int *)puVar5[3] + 0x28))(unaff_EBX);

        (**(code **)(*(int *)puVar5[3] + 0x74))(local_50);

        (**(code **)(*(int *)puVar5[3] + 0xd4))(*(char *)((int)param_1 + 0x565) == '\0');

        cVar2 = (**(code **)(*param_1 + 0xd0))();

        if (cVar2 == '\0') {

          (**(code **)(*(int *)puVar5[3] + 0xcc))(0);

        }

        else {

          (**(code **)(*(int *)puVar5[3] + 0xfc))(1,0x3f000000);

        }

        (**(code **)(*(int *)puVar5[3] + 0x120))(&puStack_58,1,0);

        puStack_58 = (uint8_t *)(unaff_EDI + iVar4);

        (**(code **)(*(int *)puVar5[3] + 0x118))(&stack0xffffffa4);

        bVar1 = true;

      }

      if ((char)param_1[0x19d] == '\0') {

        if (!bVar1) {

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar5);

        }

        FUN_0041c7e0(param_1 + 0x14e,puVar5);

      }

      else {

        local_44 = operator_new(0x488);

        local_c = 1;

        if (local_44 == (void *)0x0) {

          uVar6 = 0;

        }

        else {

          uVar6 = FUN_007b5dd0(local_44,0);

        }

        local_c = 0xffffffff;

        puVar5[2] = uVar6;

        (**(code **)(*param_1 + 0xa8))(uVar6);

        (**(code **)(*(int *)puVar5[2] + 0x28))(param_1 + 0x19d);

        (**(code **)(*(int *)puVar5[2] + 0x74))(local_50);

        (**(code **)(*(int *)puVar5[2] + 0x1d8))(0,1,1);

        (**(code **)(*(int *)puVar5[2] + 0x24))((char)param_1[0x159]);

        (**(code **)(*(int *)puVar5[2] + 0x120))(&local_4c,1,0);

        local_50 = (int *)(puStack_58 + (int)fVar7);

        local_4c = unaff_EBX + iVar4;

        (**(code **)(*(int *)puVar5[2] + 0x118))(&local_50);

        iVar4 = (**(code **)(*(int *)puVar5[2] + 0x1b8))();

        param_1[0x13f] = iVar4;

        iVar4 = puVar5[2];

        param_1[0x140] = *(int *)(iVar4 + 0x228);

        param_1[0x141] = *(int *)(iVar4 + 0x22c);

        param_1[0x142] = *(int *)(iVar4 + 0x230);

        cVar2 = (**(code **)(*param_1 + 0xd0))();

        if (cVar2 == '\0') {

          (**(code **)(*(int *)puVar5[2] + 0xcc))(0);

          FUN_0041c7e0(param_1 + 0x14e,puVar5);

        }

        else {

          (**(code **)(*(int *)puVar5[2] + 0xfc))(1,0x3f000000);

          FUN_0041c7e0(param_1 + 0x14e,puVar5);

        }

      }

      local_4c = local_4c + 1;

    } while ((int)local_4c < param_1[0x15b]);

  }

  ExceptionList = local_14;

  return;

}
