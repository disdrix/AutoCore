// =============================================================================
// Named_CalleeOf_Client_PlayNamedInterfaceSound_00726390
// -----------------------------------------------------------------------------
// Stable ID: aa_00726390
// Callee of Client_PlayNamedInterfaceSound
// Address:   0x00726390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PlayNamedInterfaceSound: presentation helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~189 non-empty decompiler lines.
//  - Control keywords: if×17, do×7, while×7, return×6, goto×2.
//  - Notable callees: FUN_00724870×2, FUN_007a69d0×2, FUN_004801a0, FUN_0071f810, FUN_0071f870, FUN_00723290, FUN_007238c0, FUN_00726070.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Client_PlayNamedInterfaceSound
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

uint32_t /* width from decompiler */

Named_CalleeOf_Client_PlayNamedInterfaceSound_00726390(int param_1,char *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint8_t param_5,

            uint32_t /* width from decompiler */ *param_6,int param_7,char param_8,char param_9,int param_10,float param_11,

            uint32_t /* width from decompiler */ param_12,uint32_t /* width from decompiler */ param_13,uint32_t /* width from decompiler */ param_14,uint32_t /* width from decompiler */ param_15)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  char cVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ local_224;

  uint32_t /* width from decompiler */ local_220;

  uint32_t /* width from decompiler */ local_21c;

  uint32_t /* width from decompiler */ local_218;

  uint32_t /* width from decompiler */ local_214;

  uint32_t /* width from decompiler */ local_210;

  uint8_t local_20c [4];

  char local_208 [260];

  uint8_t local_104 [260];

  

  local_218 = DAT_00aa9110;

  local_224 = 0;

  local_214 = DAT_00aa9114;

  local_210 = DAT_00aa9118;

  local_20c = (uint8_t  [4])DAT_00aa911c;

  local_220 = 1;

  if (*(char *)(param_1 + 600) == '\0') {

    return 0;

  }

  local_21c = 2;

  iVar5 = FUN_007a69d0();

  if (*(int *)(iVar5 + 0x2c) != 0) {

    pcVar6 = param_2;

    do {

      cVar4 = *pcVar6;

      pcVar6[(int)(local_208 + -(int)param_2)] = cVar4;

      pcVar6 = pcVar6 + 1;

    } while (cVar4 != '\0');

    iVar5 = FUN_007a69d0();

    iVar5 = *(int *)(iVar5 + 0x2c);

    if (iVar5 == 1) {

      puVar10 = (uint32_t /* width from decompiler */ *)(local_20c + 3);

      do {

        pcVar6 = (char *)((int)puVar10 + 1);

        puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

      } while (*pcVar6 != '\0');

      *puVar10 = DAT_00a96c64;

    }

    else if (iVar5 == 2) {

      puVar10 = (uint32_t /* width from decompiler */ *)(local_20c + 3);

      do {

        pcVar6 = (char *)((int)puVar10 + 1);

        puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

      } while (*pcVar6 != '\0');

      *puVar10 = DAT_00a96c60;

    }

    else if (iVar5 == 3) {

      puVar10 = (uint32_t /* width from decompiler */ *)(local_20c + 3);

      do {

        pcVar6 = (char *)((int)puVar10 + 1);

        puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

      } while (*pcVar6 != '\0');

      *puVar10 = DAT_00a96c68;

    }

    cVar4 = FUN_00724870(param_1,local_104,&local_21c);

    if (cVar4 != '\0') goto LAB_007264b9;

  }

  cVar4 = FUN_00724870(param_1,local_104,&local_21c);

  if (cVar4 == '\0') {

    return 0x80004005;

  }

LAB_007264b9:

  if (param_10 == 0x50) {

    local_224 = 0;

    iVar5 = -1;

    local_220 = 0;

  }

  else {

    iVar5 = 0;

    puVar10 = (uint32_t /* width from decompiler */ *)(param_1 + 0x70);

    do {

      if ((*(char *)*puVar10 == *param_2) &&

         (iVar8 = _stricmp((char *)*puVar10,param_2), iVar8 == 0)) {

        piVar1 = (int *)(*(int *)(param_1 + 0x70 + iVar5 * 4) + 0x10c);

        *piVar1 = *piVar1 + 1;

        local_224 = 1;

        local_220 = 0;

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x70 + iVar5 * 4) + 0x110) =

             *(uint32_t /* width from decompiler */ *)(param_1 + 0x3dc);

        goto LAB_0072653e;

      }

      iVar5 = iVar5 + 1;

      puVar10 = puVar10 + 1;

    } while (iVar5 < 100);

    iVar5 = FUN_007238c0(param_1);

    *(int *)(param_1 + 0x414) = iVar5;

    if (iVar5 < 0) {

      return 0x80004005;

    }

    pcVar6 = *(char **)(param_1 + 0x70 + iVar5 * 4);

    pcVar9 = param_2;

    do {

      cVar4 = *pcVar9;

      *pcVar6 = cVar4;

      pcVar9 = pcVar9 + 1;

      pcVar6 = pcVar6 + 1;

    } while (cVar4 != '\0');

  }

LAB_0072653e:

  uVar3 = local_21c;

  uVar7 = 0xa0;

  if ((*(char *)(param_1 + 0x259) != '\0') && (param_9 == '\0')) {

    local_218 = DAT_00a0d014;

    local_214 = DAT_00a0d018;

    uVar7 = 0x90;

    local_210 = DAT_00a0d01c;

    local_20c = (uint8_t  [4])DAT_00a0d020;

  }

  piVar1 = (int *)(param_1 + 0x31c + param_7 * 4);

  iVar8 = FUN_00726070(piVar1,uVar7,local_218,local_214,local_210,local_20c,15000,param_10,local_224

                       ,iVar5,local_220,local_21c);

  if (-1 < iVar8) {

    if (((*piVar1 != 0) && (*(char *)(param_1 + 0x259) != '\0')) && (param_9 == '\0')) {

      FUN_0071f870();

      if (*(int *)(*piVar1 + 0x1c8) == 0) {

        return 0x80004005;

      }

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x1cc) = 0x40;

      piVar2 = *(int **)(*piVar1 + 0x1c8);

      (**(code **)(*piVar2 + 0xc))(piVar2,*piVar1 + 0x1cc);

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x208) = 0;

      *(float *)(*piVar1 + 0x200) = param_11;

      *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x204) = param_13;

      piVar2 = *(int **)(*piVar1 + 0x1c8);

      (**(code **)(*piVar2 + 0x30))(piVar2,*piVar1 + 0x1cc,0);

      FUN_004801a0(param_6);

    }

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x14c) = uVar3;

    *(char *)(*piVar1 + 0x36) = param_8;

    *(uint8_t *)(*piVar1 + 0x34) = 0;

    pcVar6 = (char *)(*piVar1 + 0x48);

    do {

      cVar4 = *param_2;

      *pcVar6 = cVar4;

      param_2 = param_2 + 1;

      pcVar6 = pcVar6 + 1;

    } while (cVar4 != '\0');

    *(int *)(*piVar1 + 0x30) = iVar5;

    iVar5 = *piVar1;

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x40) = param_3;

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x44) = param_4;

    *(uint8_t *)(*piVar1 + 0x35) = param_5;

    iVar5 = *piVar1;

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x150) = *param_6;

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x154) = param_6[1];

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x158) = param_6[2];

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x15c) = param_6[3];

    *(char *)(*piVar1 + 0x37) = param_9;

    *(char *)(*piVar1 + 0x39) = param_9;

    if ((param_8 != '\0') && (param_11 <= 0.0)) {

      param_11 = DAT_00b031c8;

    }

    *(float *)(*piVar1 + 0x1b8) = param_11;

    uVar3 = DAT_00aaa5d8;

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x1a4) = DAT_00aaa5d8;

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x1b0) = uVar3;

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x18c) = param_12;

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x180) = param_13;

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 0x184) = param_15;

    *(int *)(*piVar1 + 0x2c) = param_10;

    *(uint32_t /* width from decompiler */ *)(*piVar1 + 400) = param_14;

    *(uint8_t *)(*piVar1 + 0x3a) = 1;

    *(uint8_t *)(*piVar1 + 0x1c4) = 1;

    return 0;

  }

  if (*piVar1 != 0) {

    FUN_0071f810();

    if ((uint32_t /* width from decompiler */ *)*piVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar1)(1);

    }

    *piVar1 = 0;

    FUN_00723290(param_1);

  }

  return 0x80004005;

}
