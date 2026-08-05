// READABILITY (auto CF):
//  - Body size: ~270 non-empty decompiler lines.
//  - Control keywords: if×24, return×5, do×2, while×2.
//  - Notable callees: FUN_0067ffb0×6, FUN_0067f930×2, FUN_006812b0×2, FUN_0067c590, FUN_0067cef0, FUN_00680cf0, FUN_0076c330, FUN_0076cec0.
//  - Return sites: 5.

// =============================================================================
// Named_netSession_0067cef0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067cef0
// Address:   0x0067cef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "netSession"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint8_t __fastcall Named_netSession_0067cef0(int param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint8_t uVar8;

  float10 fVar9;

  uint local_24;

  int *local_20;

  int *local_1c;

  int *local_18;

  int *local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a970d;

  local_c = ExceptionList;

  uVar8 = 1;

  ExceptionList = &local_c;

  fVar9 = (float10)FUN_0076c330();

  local_1c = (int *)(float)fVar9;

  piVar5 = *(int **)(param_1 + 0x2958);

  if ((piVar5 != (int *)0x0) &&

     (local_10 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x295c) - (int)piVar5 >> 2),

     local_10 != (uint32_t /* width from decompiler */ *)0x0)) {

    iVar7 = 0;

    do {

      if (piVar5 == *(int **)(param_1 + 0x295c)) break;

      piVar1 = (int *)*piVar5;

      if ((float)*(double *)(param_1 + 0x29f8) < (float)local_1c - (float)piVar1[2]) {

        local_1c = operator_new(0x10);

        if (local_1c == (int *)0x0) {

          local_1c = (int *)0x0;

        }

        else {

          iVar7 = *(int *)(param_1 + 0x2a04);

          uVar8 = *(uint8_t *)((int)piVar1 + 0x11);

          iVar3 = piVar1[1];

          *local_1c = *piVar1;

          local_1c[1] = iVar3;

          local_1c[2] = iVar7 + -1;

          *(uint8_t *)(local_1c + 3) = 0;

          *(uint8_t *)((int)local_1c + 0xd) = uVar8;

        }

        *(int *)(*piVar1 + 0x14) = *(int *)(*piVar1 + 0x14) + 1;

        *(char *)(piVar1 + 4) = (char)piVar1[4] + '\x01';

        piVar1[2] = (int)*(float *)(param_1 + 0x2a40);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x29c0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a40);

        if ((char)piVar1[4] == '\x01') {

          piVar1[3] = (int)*(float *)(param_1 + 0x2a40);

        }

        FUN_0067ffb0(&local_1c);

        if (*(int *)(param_1 + 0x2a3c) != 0) {

          piVar5 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x60);

          *piVar5 = *piVar5 + 1;

        }

        ExceptionList = local_c;

        return 1;

      }

      iVar7 = iVar7 + 1;

      piVar5 = piVar5 + 1;

    } while (iVar7 < 4);

  }

  if ((*(int *)(param_1 + 0x2948) == 0) ||

     (local_10 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x294c) - *(int *)(param_1 + 0x2948) >> 2),

     local_10 == (uint32_t /* width from decompiler */ *)0x0)) {

    if (((*(char *)(param_1 + 0x2a10) != '\0') &&

        (*(float *)(param_1 + 0x29c0) <= *(float *)(param_1 + 0x2a40) &&

         *(float *)(param_1 + 0x2a40) != *(float *)(param_1 + 0x29c0))) &&

       ((*(char *)(param_1 + 0x2a11) != '\0' ||

        (*(double *)(param_1 + 0x29f8) * _DAT_009e90e8 <=

         (double)*(float *)(param_1 + 0x2a40) - (double)*(float *)(param_1 + 0x29c0))))) {

      local_10 = operator_new(0x10);

      if (local_10 == (uint32_t /* width from decompiler */ *)0x0) {

        local_10 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        iVar7 = *(int *)(param_1 + 0x2a04);

        iVar3 = *(int *)(param_1 + 0x2a0c);

        *local_10 = 0;

        local_10[1] = iVar3 + -1;

        local_10[2] = iVar7 + -1;

        *(uint8_t *)(local_10 + 3) = 0;

        *(uint8_t *)((int)local_10 + 0xd) = 0;

      }

      FUN_0067ffb0(&local_10);

      *(uint8_t *)(param_1 + 0x2a10) = 0;

      *(uint8_t *)(param_1 + 0x2a11) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x29c0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a40);

      if (*(int *)(param_1 + 0x2a3c) != 0) {

        piVar5 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x68);

        *piVar5 = *piVar5 + 1;

      }

      if ((*(int *)(param_1 + 0x2958) == 0) ||

         (local_10 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x295c) - *(int *)(param_1 + 0x2958) >> 2),

         local_10 == (uint32_t /* width from decompiler */ *)0x0)) {

        FUN_0067c590(0);

        uVar8 = 0;

      }

    }

    ExceptionList = local_c;

    return uVar8;

  }

  iVar7 = *(int *)(param_1 + 0x2a08);

  if (0x3f < (uint)(*(int *)(param_1 + 0x2a0c) - iVar7)) {

    if (iVar7 != *(int *)(param_1 + 0x2a38)) {

      uVar6 = FUN_0076cec0(&local_10,

                           "Session %lu: Sequential channel: remote has only acknowledged sequence %lu - holding queue since our next sequence would be %lu"

                           ,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20),iVar7,*(int *)(param_1 + 0x2a0c));

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                     ,0x7b8,1,uVar6);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a38) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a08);

    }

    ExceptionList = local_c;

    return 1;

  }

  piVar5 = *(int **)(param_1 + 0x2948);

  puVar2 = (uint32_t /* width from decompiler */ *)*piVar5;

  local_10 = puVar2;

  memmove(piVar5,piVar5 + 1,(*(int *)(param_1 + 0x294c) - (int)(piVar5 + 1) >> 2) * 4);

  *(int *)(param_1 + 0x294c) = *(int *)(param_1 + 0x294c) + -4;

  if (*(uint *)(param_1 + 0x2a2c) < (uint)puVar2[3]) {

    if (*(int *)(param_1 + 0x2a3c) != 0) {

      piVar5 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x4c);

      *piVar5 = *piVar5 + 1;

    }

    local_24 = FUN_00680cf0(&local_1c);

    local_20 = local_1c;

    if (*(uint *)(param_1 + 0x2a2c) < local_24) {

      do {

        piVar5 = operator_new(0x14);

        local_14 = piVar5;

        local_18 = operator_new(0x1c);

        iVar7 = 0;

        local_4 = 0;

        if (local_18 != (int *)0x0) {

          iVar7 = FUN_006812b0(&local_20,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2a2c),0);

        }

        iVar3 = *(int *)(param_1 + 0x2a2c);

        local_20 = (int *)((int)local_20 + iVar3);

        *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;

        local_24 = local_24 - iVar3;

        *piVar5 = iVar7;

        *(uint8_t *)((int)piVar5 + 0x11) = 0x80;

        piVar5[3] = (int)*(float *)(param_1 + 0x2a40);

        piVar5[2] = (int)*(float *)(param_1 + 0x2a40);

        *(uint8_t *)(piVar5 + 4) = 0;

        piVar5[1] = *(int *)(param_1 + 0x2a0c);

        *(int *)(param_1 + 0x2a0c) = *(int *)(param_1 + 0x2a0c) + 1;

        *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;

        local_4 = 0xffffffff;

        local_18 = operator_new(0x10);

        if (local_18 == (int *)0x0) {

          local_18 = (int *)0x0;

        }

        else {

          iVar3 = *(int *)(param_1 + 0x2a04);

          iVar4 = piVar5[1];

          *local_18 = iVar7;

          local_18[1] = iVar4;

          local_18[2] = iVar3 + -1;

          *(uint8_t *)(local_18 + 3) = 0;

          *(uint8_t *)((int)local_18 + 0xd) = 0x80;

        }

        iVar7 = *(int *)(param_1 + 0x2968);

        if ((iVar7 == 0) ||

           ((uint)(*(int *)(param_1 + 0x2970) - iVar7 >> 2) <=

            (uint)(*(int *)(param_1 + 0x296c) - iVar7 >> 2))) {

          FUN_0067f930(*(uint32_t /* width from decompiler */ *)(param_1 + 0x296c),1,&local_18);

        }

        else {

          puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x296c);

          *puVar2 = local_18;

          *(uint32_t /* width from decompiler */ **)(param_1 + 0x296c) = puVar2 + 1;

        }

        iVar7 = *(int *)(param_1 + 0x2958);

        if ((iVar7 == 0) ||

           ((uint)(*(int *)(param_1 + 0x2960) - iVar7 >> 2) <=

            (uint)(*(int *)(param_1 + 0x295c) - iVar7 >> 2))) {

          FUN_0067f930(*(uint32_t /* width from decompiler */ *)(param_1 + 0x295c),1,&local_14);

        }

        else {

          puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x295c);

          *puVar2 = piVar5;

          *(uint32_t /* width from decompiler */ **)(param_1 + 0x295c) = puVar2 + 1;

        }

        if (*(int *)(param_1 + 0x2a3c) != 0) {

          piVar5 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x44);

          *piVar5 = *piVar5 + 1;

        }

      } while (*(uint *)(param_1 + 0x2a2c) < local_24);

    }

    piVar5 = operator_new(0x14);

    local_18 = piVar5;

    local_14 = operator_new(0x1c);

    local_4 = 1;

    if (local_14 == (int *)0x0) {

      iVar7 = 0;

    }

    else {

      iVar7 = FUN_006812b0(&local_20,local_24,0);

    }

    *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;

    *piVar5 = iVar7;

    *(uint8_t *)((int)piVar5 + 0x11) = 0xa0;

    piVar5[3] = (int)*(float *)(param_1 + 0x2a40);

    piVar5[2] = (int)*(float *)(param_1 + 0x2a40);

    *(uint8_t *)(piVar5 + 4) = 0;

    piVar5[1] = *(int *)(param_1 + 0x2a0c);

    *(int *)(param_1 + 0x2a0c) = *(int *)(param_1 + 0x2a0c) + 1;

    *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;

    local_4 = 0xffffffff;

    local_14 = operator_new(0x10);

    if (local_14 == (int *)0x0) {

      local_14 = (int *)0x0;

    }

    else {

      iVar3 = *(int *)(param_1 + 0x2a04);

      iVar4 = piVar5[1];

      *local_14 = iVar7;

      local_14[1] = iVar4;

      local_14[2] = iVar3 + -1;

      *(uint8_t *)(local_14 + 3) = 0;

      *(uint8_t *)((int)local_14 + 0xd) = 0xa0;

    }

    FUN_0067ffb0(&local_14);

    FUN_0067ffb0(&local_18);

    operator_delete__(local_1c);

    (**(code **)*local_10)(1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x29c0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a40);

    ExceptionList = local_10;

    return 1;

  }

  piVar5 = operator_new(0x14);

  puVar2[5] = puVar2[5] + 1;

  *piVar5 = (int)puVar2;

  *(uint8_t *)((int)piVar5 + 0x11) = 0;

  piVar5[3] = (int)*(float *)(param_1 + 0x2a40);

  piVar5[2] = (int)*(float *)(param_1 + 0x2a40);

  *(uint8_t *)(piVar5 + 4) = 0;

  piVar5[1] = *(int *)(param_1 + 0x2a0c);

  *(int *)(param_1 + 0x2a0c) = *(int *)(param_1 + 0x2a0c) + 1;

  local_20 = piVar5;

  local_1c = operator_new(0x10);

  if (local_1c == (int *)0x0) {

    local_1c = (int *)0x0;

  }

  else {

    iVar7 = *(int *)(param_1 + 0x2a04);

    iVar3 = piVar5[1];

    *local_1c = (int)puVar2;

    local_1c[1] = iVar3;

    local_1c[2] = iVar7 + -1;

    *(uint8_t *)(local_1c + 3) = 0;

    *(uint8_t *)((int)local_1c + 0xd) = 0;

  }

  puVar2[5] = puVar2[5] + 1;

  FUN_0067ffb0(&local_1c);

  FUN_0067ffb0(&local_20);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x29c0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a40);

  ExceptionList = local_c;

  return 1;

}
