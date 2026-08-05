// READABILITY (auto CF):
//  - Body size: ~305 non-empty decompiler lines.
//  - Control keywords: if×48, return×21, goto×7, switch×5.
//  - Notable callees: FUN_0092cfd0×6, FUN_009458d0×4, ReleaseCapture×3, SetCapture×3, DefWindowProcA×2, ValidateRect×2, FUN_00754090, FUN_007a4480.
//  - Strings: "Are you sure you want to quit the game?"; "\n\n************ Starting ShutDown on Client\n\n".
//  - Return sites: 21.

// =============================================================================
// Named_Starting_ShutDown_on_Client_009458d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009458d0
// Address:   0x009458d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "

************ Starting ShutDown on Client

"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

LRESULT __thiscall Named_Starting_ShutDown_on_Client_009458d0(int param_1,HWND param_2,uint param_3,uint param_4,uint param_5)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  LRESULT LVar4;

  BOOL BVar5;

  bool bVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  int local_18;

  uint local_14;

  tagRECT tStack_10;

  

  if (param_3 < 0x204) {

    if (param_3 != 0x203) {

      if (param_3 < 0x106) {

        if (param_3 < 0x104) {

          switch(param_3) {

          case 0x20:

            if ((*(int *)(param_1 + 0x1168) != 0) && (iVar3 = FUN_007f9c10(), iVar3 != 0)) {

              return 1;

            }

            break;

          case 0x100:

            piVar1 = *(int **)(param_1 + 0xf40);

            if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {

              (**(code **)(*(int *)*piVar1 + 0x358))(param_4,param_5);

            }

            break;

          case 0x101:

            piVar1 = *(int **)(param_1 + 0xf40);

            if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {

              (**(code **)(*(int *)*piVar1 + 0x35c))(param_4,param_5);

            }

            break;

          case 0x102:

            piVar1 = *(int **)(param_1 + 0xf40);

            if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {

              (**(code **)(*(int *)*piVar1 + 0x354))(param_4,param_5);

            }

          }

        }

        else if ((*(char *)(param_1 + 0x9cd) != '\0') && (*(char *)(param_1 + 0x9c1) == '\0')) {

          bVar6 = param_4 == 0x73;

          goto LAB_009459ec;

        }

      }

      else {

        switch(param_3) {

        case 0x112:

          if (param_4 < 0xf131) {

            if (param_4 != 0xf130) {

              switch(param_4) {

              case 0xf040:

              case 0xf050:

                break;

              default:

                goto switchD_00945924_caseD_21;

              case 0xf060:

                if ((*(int **)(param_1 + 0xf40) != (int *)0x0) &&

                   (**(int **)(param_1 + 0xf40) == *(int *)(param_1 + 0xf38))) {

                  uVar11 = 0;

                  uVar10 = 1;

                  uVar9 = 0x4e57;

                  uVar8 = 0xffffffff;

                  pcVar7 = "Are you sure you want to quit the game?";

                  FUN_007a69d0("Are you sure you want to quit the game?",0xffffffff,0x4e57,1,0);

                  uVar8 = FUN_007a6de0(pcVar7,uVar8);

                  FUN_007fdfb0(param_1,uVar8,uVar9,uVar10,uVar11);

                  return 0;

                }

                goto switchD_00945f04_caseD_2;

              case 0xf100:

                return 0;

              }

            }

          }

          else if (param_4 != 0xf140) {

            if (param_4 == 0xf150) {

              return 0;

            }

            if (param_4 != 0xf170) break;

          }

          bVar6 = *(char *)(param_1 + 0x9c1) == '\0';

LAB_009459ec:

          if (bVar6) {

            return 0;

          }

          break;

        case 0x200:

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x3034) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x302c);

          *(uint *)(param_1 + 0x302c) = param_5 & 0xffff;

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x3038) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x3030);

          *(uint *)(param_1 + 0x3030) = param_5 >> 0x10;

          if (*(int **)(param_1 + 0x1168) != (int *)0x0) {

            local_18 = *(int *)(param_1 + 0x302c);

            local_14 = param_5 >> 0x10;

            (**(code **)(**(int **)(param_1 + 0x1168) + 0x118))(&local_18);

          }

          piVar1 = *(int **)(param_1 + 0xf40);

          if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {

            if ((*(int *)(param_1 + 0x1ac) < *(int *)(param_1 + 0x302c)) &&

               (*(int *)(param_1 + 0x302c) < *(int *)(param_1 + 0x3198) - *(int *)(param_1 + 0x1ac))

               ) {

              (**(code **)(*(int *)*piVar1 + 0x458))();

            }

            if ((*(int *)(param_1 + 0x1ac) < *(int *)(param_1 + 0x3030)) &&

               (*(int *)(param_1 + 0x3030) < *(int *)(param_1 + 0x319c) - *(int *)(param_1 + 0x1ac))

               ) {

              (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0x45c))();

            }

            (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0x368))(param_4,param_5);

          }

          break;

        case 0x201:

          SetCapture(*(HWND *)(param_1 + 0x3188));

          piVar1 = *(int **)(param_1 + 0xf40);

          *(uint8_t *)(param_1 + 0x3024) = 1;

          if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&

             (cVar2 = (**(code **)(*(int *)*piVar1 + 0x378))(param_4,param_5), cVar2 == '\0')) {

            FUN_0092cfd0(param_1,0xf00,0xff);

          }

          break;

        case 0x202:

          *(uint8_t *)(param_1 + 0x3024) = 0;

          *(uint8_t *)(param_1 + 0x19) = 0;

          *(uint8_t *)(param_1 + 0x3027) = 0;

          ReleaseCapture();

          piVar1 = *(int **)(param_1 + 0xf40);

          if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {

            (**(code **)(*(int *)*piVar1 + 0x37c))(param_4,param_5);

          }

          FUN_0092cfd0(param_1,0xf00,0);

        }

      }

      goto switchD_00945924_caseD_21;

    }

    piVar1 = *(int **)(param_1 + 0xf40);

    *(uint8_t *)(param_1 + 0x3027) = 1;

    if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&

       (cVar2 = (**(code **)(*(int *)*piVar1 + 0x380))(param_4,param_5), cVar2 == '\0')) {

      *(uint8_t *)(param_1 + 0x3027) = 0;

      Named_Starting_ShutDown_on_Client_009458d0(param_2,0x201,param_4,param_5);

    }

  }

  else {

    if (param_3 < 0x313) {

      if (param_3 == 0x312) {

        if (*(char *)(param_1 + 0xa3) == '\0') {

          return 0;

        }

        goto LAB_00945c75;

      }

      switch(param_3) {

      case 0x204:

        SetCapture(*(HWND *)(param_1 + 0x3188));

        piVar1 = *(int **)(param_1 + 0xf40);

        *(uint8_t *)(param_1 + 0x3026) = 1;

        if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&

           (cVar2 = (**(code **)(*(int *)*piVar1 + 0x390))(param_4,param_5), cVar2 == '\0')) {

          FUN_0092cfd0(param_1,0xf01,0xff);

        }

        break;

      case 0x205:

        *(uint8_t *)(param_1 + 0x3026) = 0;

        *(uint8_t *)(param_1 + 0x3029) = 0;

        ReleaseCapture();

        if (*(int *)(param_1 + 0x1168) != 0) {

          FUN_007f9b20(*(int *)(param_1 + 0x1168));

        }

        piVar1 = *(int **)(param_1 + 0xf40);

        if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {

          (**(code **)(*(int *)*piVar1 + 0x394))(param_4,param_5);

        }

        FUN_0092cfd0(param_1,0xf01,0);

        break;

      case 0x206:

        *(uint8_t *)(param_1 + 0x3026) = 1;

        *(uint8_t *)(param_1 + 0x3029) = 1;

        piVar1 = *(int **)(param_1 + 0xf40);

        if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&

           (cVar2 = (**(code **)(*(int *)*piVar1 + 0x398))(param_4,param_5), cVar2 == '\0')) {

          *(uint8_t *)(param_1 + 0x3029) = 0;

          Named_Starting_ShutDown_on_Client_009458d0(param_2,0x204,param_4,param_5);

        }

        break;

      case 0x207:

        SetCapture(*(HWND *)(param_1 + 0x3188));

        piVar1 = *(int **)(param_1 + 0xf40);

        *(uint8_t *)(param_1 + 0x3025) = 1;

        if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&

           (cVar2 = (**(code **)(*(int *)*piVar1 + 900))(param_4,param_5), cVar2 == '\0')) {

          FUN_0092cfd0(param_1,0xf02,0xff);

        }

        break;

      case 0x208:

        *(uint8_t *)(param_1 + 0x3025) = 0;

        *(uint8_t *)(param_1 + 0x3028) = 0;

        ReleaseCapture();

        piVar1 = *(int **)(param_1 + 0xf40);

        if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {

          (**(code **)(*(int *)*piVar1 + 0x388))(param_4,param_5);

        }

        FUN_0092cfd0(param_1,0xf02,0);

        break;

      case 0x209:

        piVar1 = *(int **)(param_1 + 0xf40);

        *(uint8_t *)(param_1 + 0x3028) = 1;

        if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&

           (cVar2 = (**(code **)(*(int *)*piVar1 + 0x38c))(param_4,param_5), cVar2 == '\0')) {

          *(uint8_t *)(param_1 + 0x3028) = 0;

          Named_Starting_ShutDown_on_Client_009458d0(param_2,0x207,param_4,param_5);

        }

        break;

      case 0x20a:

        piVar1 = *(int **)(param_1 + 0xf40);

        if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {

          (**(code **)(*(int *)*piVar1 + 0x39c))(param_4,param_5);

        }

      }

    }

switchD_00945924_caseD_21:

    if (param_3 < 0x11) {

      if (param_3 == 0x10) {

        if (param_4 != 0) {

          FUN_007a4480(0xffffffff,"\n\n************ Starting ShutDown on Client\n\n");

          *(uint8_t *)(param_1 + 0x13) = 0;

          FUN_009339a0();

                    /* WARNING: Subroutine does not return */

          _exit(0);

        }

switchD_00945f04_caseD_2:

        FUN_009453e0();

        return 0;

      }

      switch(param_3) {

      case 2:

        goto switchD_00945f04_caseD_2;

      case 3:

        if (*(char *)(param_1 + 0x9c1) == '\0') {

          return 0;

        }

        RedrawWindow(param_2,(RECT *)0x0,(HRGN)0x0,5);

        return 0;

      case 5:

        if (*(char *)(param_1 + 0x9c1) == '\0') {

          return 0;

        }

        if (*(char *)(param_1 + 0x9c2) == '\0') {

          return 0;

        }

        BVar5 = IsIconic(param_2);

        if (BVar5 != 0) {

          return 0;

        }

        BVar5 = GetClientRect(param_2,&tStack_10);

        if (BVar5 == 0) {

          return 0;

        }

        local_18 = tStack_10.right - tStack_10.left;

        *(LONG *)(param_1 + 0x3190) = tStack_10.left;

        *(LONG *)(param_1 + 0x3194) = tStack_10.top;

        local_14 = tStack_10.bottom - tStack_10.top;

        *(LONG *)(param_1 + 0x3198) = tStack_10.right;

        *(LONG *)(param_1 + 0x319c) = tStack_10.bottom;

        *(int *)(param_1 + 0xa18) = local_18;

        *(uint *)(param_1 + 0xa1c) = local_14;

        FUN_00754090();

        return 0;

      case 0xf:

        if (*(char *)(param_1 + 0x9c1) == '\0') {

          ValidateRect(param_2,(RECT *)0x0);

          return 0;

        }

        ValidateRect(param_2,(RECT *)(param_1 + 0x3190));

        return 0;

      }

      goto switchD_00945f04_caseD_4;

    }

  }

LAB_00945c75:

  if (param_3 != 0x14) {

    if (param_3 == 0x85) {

      if (*(char *)(param_1 + 0x9c1) != '\0') {

        LVar4 = DefWindowProcA(param_2,0x85,param_4,param_5);

        return LVar4;

      }

    }

    else {

      if (param_3 != 0x801b) {

switchD_00945f04_caseD_4:

        LVar4 = DefWindowProcA(param_2,param_3,param_4,param_5);

        return LVar4;

      }

      if (*(int *)(param_1 + 0x1168) != 0) {

        FUN_007f9cc0();

        return 0;

      }

    }

  }

  return 0;

}
