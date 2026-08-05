// =============================================================================
// FUN_00925820  (canonical structural: Client_InteractWorldClickHub)
// -----------------------------------------------------------------------------
// Stable ID: aa_00925820
// Address:   0x00925820  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-07-23 scaffold; dual A/B 2026-07-29 (W17-C)
// Prefer named clean: reconstructed-exact/Client_InteractWorldClickHub.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Client virtual world-click hub (see named clean + dual A/B).
// Stable ID: aa_00925820
// Embedded strings:
//   - "Dropping this item will permanently destroy it. Are you sure?!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~182 non-empty decompiler lines.
//  - Control keywords: if×21, return×4, do×1, goto×1, while×1.
//  - Notable callees: FUN_0093e120×3, Client_SendUseObject_IfInteractable, FUN_0040afb0, FUN_0040c410, FUN_0040c510, FUN_0048a060, FUN_005081d0, FUN_00524520.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_00925820(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  float fVar8;

  int iStack_28c;

  uint32_t /* width from decompiler */ uStack_288;

  uint32_t /* width from decompiler */ uStack_284;

  float fStack_280;

  float fStack_27c;

  float fStack_278;

  float fStack_274;

  float fStack_270;

  float fStack_26c;

  float fStack_268;

  float fStack_264;

  uint8_t uStack_260;

  uint32_t /* width from decompiler */ uStack_25c;

  float fStack_248;

  float fStack_244;

  float fStack_240;

  float fStack_23c;

  float fStack_238;

  float fStack_234;

  float fStack_230;

  float fStack_22c;

  float fStack_228;

  float fStack_224;

  uint uStack_220;

  uint uStack_21c;

  uint8_t auStack_1f0 [20];

  float fStack_1dc;

  int iStack_1d0;

  uint8_t auStack_1c0 [16];

  int iStack_1b0;

  int iStack_1ac;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009bbd61;

  local_1c = ExceptionList;

  if (((param_1[0x331] != 6) || (*(char *)((int)param_1 + 0x493) != '\0')) ||

     (*(char *)(DAT_00d1b644 + 0xf5) != '\0')) {

    iVar7 = (int)(short)((uint)param_3 >> 0x10);

    ExceptionList = &local_1c;

    (**(code **)(*param_1 + 0x430))(param_1[0x12e],(int)(short)param_3,iVar7);

    (**(code **)(*param_1 + 0x428))(param_1[0x12e],(int)(short)param_3,iVar7);

    iVar7 = 0;

    if ((DAT_00d1a860 != '\0') && (param_1[0x31c] != 0)) {

      *(uint8_t *)((int)param_1 + 0xa35) = 0;

      FUN_005081d0();

      if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0x250) != 0)) {

        VehicleEntity_SetLongitudinalInput(0);

      }

    }

    if (((int *)param_1[0x12e] != (int *)0x0) &&

       (cVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x37c))(param_2,param_3), cVar2 != '\0')) {

      ExceptionList = local_1c;

      return 1;

    }

    if ((((DAT_00d1b6d8 != 0) &&

         (cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8)

                              + 0x194))(), cVar2 == '\0')) &&

        (cVar2 = (**(code **)(*DAT_00d1b958 + 0x3d8))(), cVar2 == '\0')) &&

       (cVar2 = (**(code **)(*DAT_00d1b95c + 0x3d8))(), cVar2 == '\0')) {

      if (DAT_00d1a860 == '\0') {

        uVar3 = FUN_0091a350();

        ExceptionList = local_1c;

        return uVar3;

      }

      if (*(int *)(DAT_00d1b6d8 + 0xcd0) != 0) {

        FUN_00914c20();

        DAT_00d1a859 = 0;

        *(uint8_t *)(DAT_00d1b6d8 + 0x304) = 0;

        FUN_007fdfb0(&DAT_00d1a840,"Dropping this item will permanently destroy it. Are you sure?!",

                     0x4e4b,1,0);

        ExceptionList = local_1c;

        return 1;

      }

      uStack_284 = DAT_00d1d870;

      uStack_220 = 0xffffffff;

      uStack_21c = 0xffffffff;

      uStack_288 = DAT_00d1d86c;

      FUN_0075c340(&uStack_288,&fStack_248,&fStack_23c);

      fStack_270 = fStack_23c * DAT_00aaa7ac + fStack_248;

      fStack_26c = fStack_238 * DAT_00aaa7ac + fStack_244;

      fStack_268 = fStack_234 * DAT_00aaa7ac + fStack_240;

      fStack_280 = fStack_248;

      fStack_27c = fStack_244;

      fStack_278 = fStack_240;

      fStack_274 = 0.0;

      uStack_260 = 1;

      uStack_25c = 5;

      fStack_264 = 0.0;

      fStack_1dc = g_flOne;

      iStack_1d0 = 0;

      if (*(int *)(DAT_00d1b644 + 0xe4a4) != 0) {

        FUN_0055e530(&fStack_280,auStack_1f0);

        if (iStack_1d0 != 0) {

          fVar8 = g_flOne - fStack_1dc;

          fStack_230 = fVar8 * fStack_280 + fStack_270 * fStack_1dc;

          fStack_22c = fStack_27c * fVar8 + fStack_26c * fStack_1dc;

          fStack_228 = fStack_278 * fVar8 + fStack_268 * fStack_1dc;

          fStack_224 = fStack_274 * fVar8 + fStack_264 * fStack_1dc;

          if (DAT_00d1b6d8 == 0) {

            iVar6 = 0;

          }

          else {

            iVar6 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;

          }

          FUN_0058cd60(&uStack_220,0,

                       *(uint32_t /* width from decompiler */ *)

                        (*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xa8 + DAT_00d1b6d8),iVar6,

                       &fStack_230,0x41a00000,1,6,0,0,1);

        }

        if ((uStack_220 & uStack_21c) == 0xffffffff) {

          FUN_0040c410(auStack_1c0);

          uStack_14 = 0;

          uStack_25c = 1;

          FUN_0055e1e0(&fStack_280,auStack_1c0);

          FUN_0048a060();

          if ((iStack_1ac != 0) && (iStack_28c = 0, iVar6 = DAT_00d1b6d8, 0 < iStack_1ac)) {

            do {

              if (*(int *)(iVar7 + 0x20 + iStack_1b0) != 0) {

                piVar4 = (int *)FUN_0040afb0(&uStack_288,1);

                iVar1 = *piVar4;

                if (iVar1 != 0) {

                  if (DAT_00d1b205 == '\0') {

                    if (iVar6 == 0) {

                      iVar5 = 0;

                    }

                    else {

                      iVar5 = *(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6;

                    }

                    if (iVar1 != iVar5) {

                      iVar5 = *(int *)(iVar6 + 0x250);

                      if (iVar5 != 0) {

                        iVar5 = *(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5;

                      }

                      if (iVar1 != iVar5) goto LAB_00925cd1;

                    }

                  }

                  else {

LAB_00925cd1:

                    iVar6 = FUN_005245d0(iVar1);

                    if (iVar6 != 0) {

                      FUN_0093e120(iVar1);

                    }

                    iVar5 = FUN_00524520(iVar1);

                    iVar6 = DAT_00d1b6d8;

                    if (iVar5 != 0) {

                      FUN_0093e120(iVar1);

                      Client_SendUseObject_IfInteractable();

                      iVar6 = DAT_00d1b6d8;

                    }

                  }

                }

              }

              iStack_28c = iStack_28c + 1;

              iVar7 = iVar7 + 0x30;

            } while (iStack_28c < iStack_1ac);

          }

          uStack_14 = 0xffffffff;

          FUN_0040c510();

        }

        else {

          FUN_00925580();

          param_1[0x1d6] = 0;

          FUN_0093e120(0);

        }

      }

    }

  }

  ExceptionList = local_1c;

  return 0;

}
