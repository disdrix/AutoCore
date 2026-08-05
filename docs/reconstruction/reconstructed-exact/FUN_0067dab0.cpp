// =============================================================================
// FUN_0067dab0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067dab0
// Address:   0x0067dab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067dab0 @ 0x0067dab0
// Stable ID: aa_0067dab0
// Embedded strings (evidence for future rename):
//   - "Session %lu: Packet on out queue is destined for internal channel"
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~168 non-empty decompiler lines.
//  - Control keywords: if×17, return×7, while×1, for×1.
//  - Notable callees: FUN_0067ffb0×3, FUN_0067c590×2, FUN_0067cef0, FUN_0067dab0, FUN_0067f930, FUN_0076cec0, memmove, vog_LogMessage.
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ __thiscall FUN_0067dab0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  byte bVar2;

  uint32_t /* width from decompiler */ *_Dst;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  

  if (*(byte *)(param_1 + 6) <= (byte)param_2) {

    return 0;

  }

  bVar2 = *(byte *)(((uint)param_2 & 0xff) + 7 + param_1);

  if (bVar2 == 0) {

    uVar6 = FUN_0067cef0();

    return uVar6;

  }

  if (bVar2 == 0xfe) {

    iVar7 = 0;

    while (((*(int *)(param_1 + 0x2918) != 0 &&

            (param_2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x291c) - *(int *)(param_1 + 0x2918) >> 2),

            param_2 != (uint32_t /* width from decompiler */ *)0x0)) && (iVar7 < 0x32))) {

      _Dst = *(uint32_t /* width from decompiler */ **)(param_1 + 0x2918);

      uVar6 = *_Dst;

      param_2 = operator_new(0x10);

      if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

        param_2 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        iVar3 = *(int *)(param_1 + 0x2a00);

        *(int *)(param_1 + 0x2a00) = iVar3 + 1;

        *param_2 = uVar6;

        param_2[1] = iVar3;

        param_2[2] = 0;

        *(uint8_t *)(param_2 + 3) = 0xfe;

        *(uint8_t *)((int)param_2 + 0xd) = 0;

      }

      iVar3 = *(int *)(param_1 + 0x2968);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(param_1 + 0x2970) - iVar3 >> 2) <=

          (uint)(*(int *)(param_1 + 0x296c) - iVar3 >> 2))) {

        FUN_0067f930(*(uint32_t /* width from decompiler */ *)(param_1 + 0x296c),1,&param_2);

      }

      else {

        puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x296c);

        *puVar4 = param_2;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x296c) = puVar4 + 1;

      }

      memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x291c) - (int)(_Dst + 1) >> 2) * 4);

      *(int *)(param_1 + 0x291c) = *(int *)(param_1 + 0x291c) + -4;

      iVar7 = iVar7 + 1;

    }

  }

  else {

    if (bVar2 == 0xff) {

      uVar6 = FUN_0076cec0(&param_2,

                           "Session %lu: Packet on out queue is destined for internal channel",

                           *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20));

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                     ,0x710,3,uVar6);

      FUN_0067c590(0xff);

      return 0;

    }

    iVar3 = *(int *)(param_1 + 0x124 + (uint)bVar2 * 0x28);

    iVar7 = param_1 + 0x114 + (uint)bVar2 * 0x28;

    if (iVar3 == 0) {

      param_2 = operator_new(0x10);

      if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

        param_2 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        iVar3 = *(int *)(iVar7 + 0xc);

        uVar6 = *(uint32_t /* width from decompiler */ *)(iVar7 + 8);

        *param_2 = 0;

        param_2[1] = iVar3 + -1;

        param_2[2] = uVar6;

        *(byte *)(param_2 + 3) = bVar2;

        *(uint8_t *)((int)param_2 + 0xd) = 0;

      }

      if (*(int *)(param_1 + 0x2a3c) != 0) {

        piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x68);

        *piVar1 = *piVar1 + 1;

      }

      *(uint8_t *)(iVar7 + 0x21) = 0;

      *(uint8_t *)(iVar7 + 0x22) = 0;

      FUN_0067ffb0(&param_2);

      FUN_0067c590(bVar2);

      return 0;

    }

    if (*(char *)(iVar7 + 0x18) == '\0') {

      *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + 1;

      param_2 = operator_new(0x10);

      if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

        param_2 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        uVar6 = *(uint32_t /* width from decompiler */ *)(iVar7 + 8);

        uVar5 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc);

        *param_2 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x10);

        param_2[1] = uVar5;

        param_2[2] = uVar6;

        *(byte *)(param_2 + 3) = bVar2;

        *(uint8_t *)((int)param_2 + 0xd) = 0;

      }

      *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + 1;

      *(uint32_t /* width from decompiler */ *)(iVar7 + 0x14) = param_2[1];

      *(uint8_t *)(iVar7 + 0x18) = 1;

      *(int *)(iVar7 + 0x1c) = (int)*(float *)(param_1 + 0x29bc);

      *(int *)(iVar7 + 0x24) = (int)*(float *)(param_1 + 0x29bc);

      *(uint8_t *)(iVar7 + 0x20) = 1;

      *(uint8_t *)(iVar7 + 0x21) = 0;

      *(uint8_t *)(iVar7 + 0x22) = 0;

    }

    else {

      if ((float)*(double *)(param_1 + 0x29f8) <

          *(float *)(param_1 + 0x29bc) - (float)*(int *)(iVar7 + 0x1c)) {

        *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + 1;

        param_2 = operator_new(0x10);

        if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

          param_2 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          uVar6 = *(uint32_t /* width from decompiler */ *)(iVar7 + 8);

          uVar5 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x14);

          *param_2 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x10);

          param_2[1] = uVar5;

          param_2[2] = uVar6;

          *(byte *)(param_2 + 3) = bVar2;

          *(uint8_t *)((int)param_2 + 0xd) = 0;

        }

        *(int *)(iVar7 + 0x1c) = (int)*(float *)(param_1 + 0x29bc);

        *(uint8_t *)(iVar7 + 0x21) = 0;

        *(uint8_t *)(iVar7 + 0x22) = 0;

        if (*(int *)(param_1 + 0x2a3c) != 0) {

          piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x60);

          *piVar1 = *piVar1 + 1;

        }

        FUN_0067ffb0(&param_2);

        return 1;

      }

      if (*(char *)(iVar7 + 0x21) == '\0') {

        return 1;

      }

      param_2 = operator_new(0x10);

      if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

        param_2 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        iVar3 = *(int *)(iVar7 + 0xc);

        uVar6 = *(uint32_t /* width from decompiler */ *)(iVar7 + 8);

        *param_2 = 0;

        param_2[1] = iVar3 + -1;

        param_2[2] = uVar6;

        *(byte *)(param_2 + 3) = bVar2;

        *(uint8_t *)((int)param_2 + 0xd) = 0;

      }

      *(uint8_t *)(iVar7 + 0x21) = 0;

      *(uint8_t *)(iVar7 + 0x22) = 0;

      if (*(int *)(param_1 + 0x2a3c) != 0) {

        piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x68);

        *piVar1 = *piVar1 + 1;

      }

    }

    FUN_0067ffb0(&param_2);

  }

  return 1;

}
