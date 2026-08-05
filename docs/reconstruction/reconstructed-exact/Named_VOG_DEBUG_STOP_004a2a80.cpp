// READABILITY (auto CF):
//  - Body size: ~163 non-empty decompiler lines.
//  - Control keywords: if×18, goto×9, for×2, return×2, do×1, while×1.
//  - Notable callees: _wcsicmp×8, SysFreeString×3, FUN_007a4480×2, FUN_00403450, FUN_0049cfe0, FUN_0049d070, FUN_0049d2a0, FUN_0049d510.
//  - Strings: "VOG_DEBUG_STOP"; "duration"; "playSound"; "initiateDamage".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_004a2a80
// -----------------------------------------------------------------------------
// Stable ID: aa_004a2a80
// Address:   0x004a2a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_004a2a80(int param_1,int *param_2,char param_3)



{

  char cVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  BSTR unaff_EDI;

  uint32_t /* width from decompiler */ *puVar6;

  BSTR local_2c0;

  byte bStack_2b9;

  int *piStack_2b8;

  int local_2b4;

  int *apiStack_2b0 [2];

  uint8_t auStack_2a8 [4];

  char *pcStack_2a4;

  char acStack_2a0 [128];

  uint32_t /* width from decompiler */ uStack_220;

  uint32_t /* width from decompiler */ auStack_21c [126];

  void *pvStack_24;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_10 = &LAB_009a10b6;

  pvStack_14 = ExceptionList;

  local_2c0 = (BSTR)0x0;

  local_c = 0;

  ExceptionList = &pvStack_14;

  if (((param_2 == (int *)0x0) ||

      (ExceptionList = &pvStack_14, iVar2 = (**(code **)(*param_2 + 0x44))(param_2,&local_2b4),

      iVar2 != 0)) || (local_2b4 == 0)) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  else {

    if (param_3 == '\0') {

      pvVar3 = operator_new(0x3e4);

      if (pvVar3 == (void *)0x0) {

        puVar5 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar5 = (uint32_t /* width from decompiler */ *)FUN_004a6c80();

      }

    }

    else {

      puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x14);

    }

    puVar6 = puVar5;

    for (iVar2 = 0xf9; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    puVar6 = puVar5 + 2;

    puVar5[3] = puVar6;

    *puVar6 = puVar6;

    FUN_00799200(local_2b4,L"duration",puVar5,puVar5 + 1,&bStack_2b9);

    *(uint8_t *)((int)puVar5 + 0x1ea) = 0;

    *(byte *)(puVar5 + 0x79) =

         *(byte *)(puVar5 + 0x79) ^ (bStack_2b9 << 2 ^ *(byte *)(puVar5 + 0x79)) & 4;

    uStack_220 = 0;

    puVar6 = auStack_21c;

    for (iVar2 = 0x81; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

    }

    FUN_00798bb0(local_2b4,L"playSound",&uStack_220);

    pcStack_2a4 = acStack_2a0;

    uVar4 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(&uStack_220,uVar4);

    strncpy((char *)((int)puVar5 + 0x1ea),pcStack_2a4,0x103);

    if (pcStack_2a4 != acStack_2a0) {

      free(pcStack_2a4);

    }

    FUN_007996d0(local_2b4,L"initiateDamage",&bStack_2b9);

    *(byte *)((int)puVar5 + 0x2ef) =

         *(byte *)((int)puVar5 + 0x2ef) ^ (*(byte *)((int)puVar5 + 0x2ef) ^ bStack_2b9) & 1;

    if (bStack_2b9 != 0) {

      *(uint8_t *)(*(int *)(param_1 + 4) + 0xc) = 1;

    }

    apiStack_2b0[0] = (int *)0x0;

    (**(code **)(*param_2 + 0x30))(param_2,apiStack_2b0);

    if (apiStack_2b0[0] != (int *)0x0) {

      (**(code **)(*apiStack_2b0[0] + 0x20))(apiStack_2b0[0],auStack_2a8);

      local_2b4 = 0;

      if (0 < (int)apiStack_2b0[0]) {

        do {

          iVar2 = (**(code **)(*piStack_2b8 + 0x1c))(piStack_2b8,local_2b4,&local_2c0);

          if ((iVar2 < 0) || (piStack_2b8 == (int *)0x0)) {

            FUN_007a4480(0,"VOG_DEBUG_STOP");

            goto LAB_004a2ea6;

          }

          SysFreeString(local_2c0);

          local_2c0 = (wchar_t *)0x0;

          (**(code **)(*piStack_2b8 + 0x1c))(piStack_2b8,&local_2c0);

          iVar2 = _wcsicmp(L"Ray",local_2c0);

          if (iVar2 == 0) {

            cVar1 = FUN_0049d070(puVar5,piStack_2b8);

joined_r0x004a2d8a:

            if (cVar1 == '\0') goto LAB_004a2ea6;

          }

          else {

            iVar2 = _wcsicmp(L"Pursue",local_2c0);

            if (iVar2 == 0) {

              cVar1 = FUN_0049d2a0(puVar5,piStack_2b8);

              goto joined_r0x004a2d8a;

            }

            iVar2 = _wcsicmp(L"Environment",local_2c0);

            if (iVar2 == 0) {

              cVar1 = FUN_004a18b0(puVar5,piStack_2b8);

              goto joined_r0x004a2d8a;

            }

            iVar2 = _wcsicmp(L"Circle",local_2c0);

            if (iVar2 == 0) {

              cVar1 = FUN_0049d510(puVar5,piStack_2b8);

              goto joined_r0x004a2d8a;

            }

            iVar2 = _wcsicmp(L"Orbit",local_2c0);

            if (iVar2 == 0) {

              cVar1 = FUN_0049d6f0(puVar5,piStack_2b8);

              goto joined_r0x004a2d8a;

            }

            iVar2 = _wcsicmp(L"ParticleInfo",local_2c0);

            if (iVar2 == 0) {

              cVar1 = FUN_0049db10(puVar5,piStack_2b8);

              goto joined_r0x004a2d8a;

            }

            iVar2 = _wcsicmp(L"ParticleInfoEnd",local_2c0);

            if (iVar2 == 0) {

              cVar1 = FUN_0049e0a0(puVar5,piStack_2b8);

              goto joined_r0x004a2d8a;

            }

            iVar2 = _wcsicmp(L"MoveToVertexTarget",local_2c0);

            if (iVar2 == 0) {

              *(byte *)(param_1 + 0x98c) = *(byte *)(param_1 + 0x98c) | 0x80;

              cVar1 = FUN_0049cfe0(puVar5,piStack_2b8);

              goto joined_r0x004a2d8a;

            }

          }

          (**(code **)(*piStack_2b8 + 8))(piStack_2b8);

          local_2b4 = local_2b4 + 1;

        } while (local_2b4 < (int)apiStack_2b0[0]);

      }

      (**(code **)(*piStack_2b8 + 8))(piStack_2b8);

      if (param_3 == '\0') {

        puVar5[0xbd] = param_1 + 0x14;

        puVar5[0xbc] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x304);

        *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x304) + 0x2f4) = puVar5;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x304) = puVar5;

      }

      else {

        puVar5[0xbd] = puVar5;

        puVar5[0xbc] = puVar5;

      }

      (**(code **)(*(int *)local_2c0 + 8))(local_2c0);

      SysFreeString(unaff_EDI);

      ExceptionList = pvStack_24;

      return 1;

    }

  }

LAB_004a2ea6:

  SysFreeString(local_2c0);

  ExceptionList = pvStack_14;

  return 0;

}
