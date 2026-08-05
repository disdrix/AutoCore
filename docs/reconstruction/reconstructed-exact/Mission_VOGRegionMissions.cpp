// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×16, do×3, while×3, return×2.
//  - Notable callees: CoTaskMemFree×4, FUN_0053b0b0×3, FUN_0060c010×2, FUN_007a4480×2, FUN_0053b1b0, FUN_0053c360, FUN_0053c460, FUN_005480d0.
//  - Strings: "VOG_DEBUG_STOP"; "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGRegionMissions.cpp"; "Out-o-memory... missions!".
//  - Return sites: 2.

// =============================================================================
// Mission_VOGRegionMissions
// -----------------------------------------------------------------------------
// Stable ID: aa_0060b870
// Address:   0x0060b870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOGRegionMissions"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * __fastcall Mission_VOGRegionMissions(int *param_1)



{

  int iVar1;

  bool bVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  LPVOID local_18;

  int local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a8327;

  pvStack_c = ExceptionList;

  local_14 = 0;

  local_18 = (LPVOID)0x0;

  bVar2 = false;

  if ((DAT_00b0434c == 0) || (iVar3 = DAT_00b04350 - DAT_00b0434c >> 2, iVar3 == 0)) {

    ExceptionList = &pvStack_c;

    local_10 = (uint32_t /* width from decompiler */ *)FUN_007e1d80();

    if ((int)local_10 < 0) {

      FUN_007a4480(0,"VOG_DEBUG_STOP");

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(&local_10,(ThrowInfo *)&DAT_00acc430);

    }

    FUN_007c0350(&local_14,&local_18);

    FUN_007b7df0();

  }

  else {

    bVar2 = true;

    ExceptionList = &pvStack_c;

    local_14 = iVar3;

  }

  local_10 = operator_new(0x34);

  uStack_4 = 0;

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0053b0b0(8);

  }

  uStack_4 = 0xffffffff;

  *param_1 = iVar3;

  local_10 = operator_new(0x34);

  uStack_4 = 1;

  if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0053b1b0(8);

  }

  uStack_4 = 0xffffffff;

  param_1[1] = iVar3;

  puVar4 = operator_new(0x38);

  uStack_4 = 2;

  local_10 = puVar4;

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0053b0b0(8);

    *puVar4 = &PTR_FUN_009df688;

    puVar4[0xd] = 0;

  }

  uStack_4 = 0xffffffff;

  param_1[2] = (int)puVar4;

  puVar4 = operator_new(0x38);

  uStack_4 = 3;

  local_10 = puVar4;

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_0053b0b0(8);

    *puVar4 = &PTR_FUN_009df688;

    puVar4[0xd] = 0;

  }

  uStack_4 = 0xffffffff;

  param_1[3] = (int)puVar4;

  if ((((*param_1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) || (puVar4 == (uint32_t /* width from decompiler */ *)0x0)

     ) {

    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGRegionMissions.cpp",0x33,3,

                   "Out-o-memory... missions!");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  if (local_14 != 0) {

    iVar3 = 0;

    if (0 < local_14) {

      do {

        iVar5 = 0;

        if (bVar2) {

          puVar4 = *(uint32_t /* width from decompiler */ **)(DAT_00b0434c + iVar3 * 4);

        }

        else {

          local_10 = operator_new(0x170);

          uStack_4 = 4;

          if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

            uStack_4 = 0xffffffff;

            puVar4 = (uint32_t /* width from decompiler */ *)0x0;

          }

          else {

            puVar4 = (uint32_t /* width from decompiler */ *)FUN_005480d0(*(uint32_t /* width from decompiler */ *)((int)local_18 + iVar3 * 4),1);

            uStack_4 = 0xffffffff;

          }

        }

        FUN_0053c360(*puVar4,puVar4,0);

        if (puVar4[0x22] != -1) {

          FUN_0060c010(puVar4[0x22],puVar4);

        }

        FUN_0060c010(*(uint8_t *)((int)puVar4 + 0x86),puVar4);

        if (*(char *)(puVar4 + 0x4c) != '\0') {

          do {

            iVar1 = *(int *)(puVar4[0x4f] + iVar5 * 4);

            FUN_0053c460(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x10),iVar1,0);

            iVar5 = iVar5 + 1;

          } while (iVar5 < (int)(uint)*(byte *)(puVar4 + 0x4c));

        }

        if (!bVar2) {

          iVar5 = 0;

          if (*(char *)(puVar4 + 0x4c) != '\0') {

            do {

              CoTaskMemFree(*(LPVOID *)

                             (*(int *)(*(int *)((int)local_18 + iVar3 * 4) + 0x134) + iVar5 * 4));

              iVar5 = iVar5 + 1;

            } while (iVar5 < (int)(uint)*(byte *)(puVar4 + 0x4c));

          }

          CoTaskMemFree(*(LPVOID *)(*(int *)((int)local_18 + iVar3 * 4) + 0x134));

          CoTaskMemFree(*(LPVOID *)((int)local_18 + iVar3 * 4));

        }

        iVar3 = iVar3 + 1;

      } while (iVar3 < local_14);

    }

    if (!bVar2) {

      CoTaskMemFree(local_18);

    }

  }

  ExceptionList = pvStack_c;

  return param_1;

}
