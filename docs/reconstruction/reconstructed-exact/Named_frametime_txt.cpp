// =============================================================================
// Named_frametime_txt
// -----------------------------------------------------------------------------
// Stable ID: aa_0094b520
// Address:   0x0094b520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_frametime_txt @ 0x0094b520
// Stable ID: aa_0094b520
// Embedded strings (evidence for future rename):
//   - "LoadQueue test, focus = %d"
//   - "..\\logs\\frametime.txt"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~145 non-empty decompiler lines.
//  - Control keywords: if×28, return×1.
//  - Notable callees: FUN_0079a120×10, FUN_0079a1c0×8, QueryPerformanceCounter×2, CVOGHBList_Tick, FUN_0040ace0, FUN_00495600, FUN_004bfe10, FUN_004cd7c0.
//  - Strings: "LoadQueue test, focus = %d"; "..\\logs\\frametime.txt".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "..\logs\frametime.txt"
 * Domain alias of FUN_0094b520 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



uint32_t /* width from decompiler */ __fastcall Named_frametime_txt(int param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uStack_186b0;

  char acStack_186ac [100000];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar2 = DAT_00d09874;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009bbf33;

  local_c = ExceptionList;

  if (*(char *)(param_1 + 0x13) != '\0') {

    ExceptionList = &local_c;

    if (*(char *)(DAT_00d09874 + 0x25) == '\0') {

      ExceptionList = &local_c;

      QueryPerformanceCounter((LARGE_INTEGER *)(DAT_00d09874 + 0x170));

    }

    *(char *)(iVar2 + 0x25) = *(char *)(iVar2 + 0x25) + '\x01';

    FUN_0094b3a0();

    FUN_0079a120(5);

    iVar2 = DAT_00d09874;

    if (*(int *)(param_1 + 0xf40) != 0) {

      if (*(char *)(DAT_00d09874 + 0x27) == '\0') {

        QueryPerformanceCounter((LARGE_INTEGER *)(DAT_00d09874 + 0x180));

      }

      *(char *)(iVar2 + 0x27) = *(char *)(iVar2 + 0x27) + '\x01';

      iVar2 = FUN_0093a5c0(0);

      if (iVar2 == 0) {

        FUN_0079a120(7);

        if (*(char *)(param_1 + 0xa1) == '\0') {

          FUN_0079a0d0();

        }

        if (*(char *)(param_1 + 0xb7) != '\0') {

          FUN_0079a1c0(9);

          FUN_00932c80(param_1);

          FUN_0079a120(9);

          if (*(char *)(param_1 + 0xb7) != '\0') {

            if (*(char *)(param_1 + 0xa1) == '\0') {

              FUN_0079a1c0(6);

              CVOGHBList_Tick(*(void **)(param_1 + 0xd38),0);

              FUN_0079a120(6);

            }

            if ((*(char *)(param_1 + 0xb7) != '\0') && (*(char *)(param_1 + 0xa1) == '\0')) {

              FUN_0093da30();

            }

          }

        }

        FUN_0079a1c0(8);

        FUN_00938380(param_1);

        FUN_0079a120(8);

        if (*(int *)(param_1 + 0xdec) != 0) {

          FUN_0079a1c0(10);

          (**(code **)(**(int **)(param_1 + 0xdec) + 8))();

          if (*(char *)(param_1 + 0xb7) != '\0') {

            FUN_00821650(*(uint32_t /* width from decompiler */ *)(param_1 + 0xdec));

          }

          FUN_0079a120(10);

        }

        if (*(char *)(param_1 + 0xb7) != '\0') {

          FUN_0079a1c0(0xb);

          if (*(int *)(param_1 + 0x4d0) != 0) {

            uStack_186b0 = *(uint32_t /* width from decompiler */ *)(DAT_00d09874 + 0x30);

            FUN_0092c640(uStack_186b0);

          }

          FUN_0079a120(0xb);

        }

        if (*(int *)(param_1 + 0xe04) != 0) {

          FUN_0079a1c0(0xc);

          FUN_00495600(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe04));

          if (*(char *)(param_1 + 0xb7) != '\0') {

            if ((*(char *)(*(int *)(param_1 + 0xde8) + 5) == '\0') &&

               (cVar1 = FUN_0040ace0(param_1), cVar1 == '\0')) {

              cVar1 = '\0';

            }

            else {

              cVar1 = '\x01';

            }

            if ((DAT_00d218dc & 1) == 0) {

              DAT_00d218dc = DAT_00d218dc | 1;

              DAT_00d218d8 = cVar1 == '\0';

              uStack_4 = 0xffffffff;

            }

            if (DAT_00d218d8 != cVar1) {

              FUN_007a4480(0,"LoadQueue test, focus = %d",cVar1);

            }

            DAT_00d218d8 = cVar1;

            if (cVar1 != '\0') {

              FUN_004bfe10(0x3b888889);

            }

          }

          FUN_0079a120(0xc);

        }

        if (*(int *)(param_1 + 0xe04) != 0) {

          FUN_00542e20(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe4e8));

        }

        if (*(char *)(param_1 + 0xb7) != '\0') {

          if (*(char *)(param_1 + 0xa1) == '\0') {

            FUN_004cd7c0(*(float *)(DAT_00d09874 + 0x30) / *(float *)(param_1 + 0x9b0));

          }

          if (((*(char *)(param_1 + 0xb7) != '\0') && (*(int **)(param_1 + 0xf40) != (int *)0x0)) &&

             (**(int **)(param_1 + 0xf40) == *(int *)(param_1 + 0xf38))) {

            uVar3 = 0;

            FUN_007b6a20(0);

            FUN_007b7000(uVar3);

          }

        }

        if (*(int *)(param_1 + 0xc80) != 0) {

          FUN_00933480();

        }

        FUN_0079a1c0(1);

        FUN_00942e20();

        FUN_0079a120(1);

        if (*(int *)(param_1 + 0x4f4) != 0) {

          FUN_00806b90(0,5);

        }

        if ((*(char *)(param_1 + 0xb7) != '\0') && (*(char *)(param_1 + 0xa1) == '\0')) {

          FUN_004d18a0(*(float *)(DAT_00d09874 + 0x30) / *(float *)(param_1 + 0x9b0));

        }

        FUN_00944770();

        FUN_00946c00();

        FUN_0079a120(0);

        if (((g_flZero < *(float *)(param_1 + 0xac)) &&

            (*(float *)(param_1 + 0xac) * g_flMsToSeconds_Inferred < *(float *)(DAT_00d09874 + 0x30)

            )) && ((DAT_00d1f07c != 0 ||

                   (DAT_00d1f07c = (int)fopen("..\\logs\\frametime.txt","wt"),

                   (FILE *)DAT_00d1f07c != (FILE *)0x0)))) {

          uStack_186b0 = 100000;

          FUN_0076ca60(acStack_186ac,&uStack_186b0,0);

          fputs(acStack_186ac,(FILE *)DAT_00d1f07c);

          fflush((FILE *)DAT_00d1f07c);

        }

        Sleep(0);

        FUN_0079a1c0(0);

        FUN_0079a9f0();

        FUN_0092cd20();

      }

    }

  }

  ExceptionList = local_c;

  return 1;

}
