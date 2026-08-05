// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×13, return×8, do×1, while×1.
//  - Notable callees: FUN_00988710×2, CONCAT31, ExitProcess, FUN_00440ab0, FUN_00440c90, FUN_00440d20, FUN_00441960, FUN_00756be0.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp"; "Window deleted with children still attached!"; "c:\\VOGCRASH.txt"; "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n".
//  - Return sites: 8.

// =============================================================================
// Named_gfxUIWindow_00759de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00759de0
// Address:   0x00759de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxUIWindow"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_gfxUIWindow_00759de0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int *piVar2;

  void *pvVar3;

  int iVar4;

  FILE *_File;

  int *piStack_20;

  int *piStack_1c;

  uint32_t /* width from decompiler */ *local_18;

  uint32_t /* width from decompiler */ *puStack_14;

  uint32_t /* width from decompiler */ *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b3156;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a9f304;

  local_4 = 7;

  local_18 = param_1 + 4;

  local_10 = param_1;

  FUN_00440c90(*(uint32_t /* width from decompiler */ *)(param_1[5] + 4));

  *(uint32_t /* width from decompiler */ *)(param_1[5] + 4) = param_1[5];

  param_1[6] = 0;

  *(uint32_t /* width from decompiler */ *)param_1[5] = param_1[5];

  *(uint32_t /* width from decompiler */ *)(param_1[5] + 8) = param_1[5];

  piVar2 = (int *)param_1[0xd];

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    param_1[0xd] = 0;

  }

  if ((void *)param_1[0x17] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x17]);

  }

  puStack_14 = param_1 + 1;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  FUN_00440ab0(*(uint32_t /* width from decompiler */ *)(param_1[2] + 4));

  *(uint32_t /* width from decompiler */ *)(param_1[2] + 4) = param_1[2];

  param_1[3] = 0;

  *(uint32_t /* width from decompiler */ *)param_1[2] = param_1[2];

  *(uint32_t /* width from decompiler */ *)(param_1[2] + 8) = param_1[2];

  if ((void *)param_1[8] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[8]);

  }

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  if ((void *)param_1[0xf] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xf]);

  }

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  FUN_00440d20(*(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 4));

  *(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 4) = param_1[0x2a];

  param_1[0x2b] = 0;

  *(uint32_t /* width from decompiler */ *)param_1[0x2a] = param_1[0x2a];

  *(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 8) = param_1[0x2a];

  pvVar3 = (void *)param_1[0x2c];

  if (pvVar3 != (void *)0x0) {

    FUN_00988710();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

  param_1[0x2c] = 0;

  pvVar3 = (void *)param_1[0x2d];

  if (pvVar3 != (void *)0x0) {

    FUN_00988710();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

  param_1[0x2d] = 0;

  if (param_1[0x22] != 0) {

    FUN_00756be0(param_1);

  }

  piStack_20 = (int *)param_1[0x25];

  if ((piStack_20 != (int *)0x0) &&

     (piStack_1c = (int *)(param_1[0x26] - (int)piStack_20 >> 2), piStack_1c != (int *)0x0)) {

    piStack_1c = (int *)param_1[0x26];

    if (piStack_20 != piStack_1c) {

      do {

        iVar4 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp",0x73,

                             "Window deleted with children still attached!");

        if (iVar4 == 3) {

          _File = fopen("c:\\VOGCRASH.txt","w");

          if (_File != (FILE *)0x0) {

            fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                    "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp",0x73,1,

                    "Window deleted with children still attached!");

            fclose(_File);

          }

          raise(0x16);

                    /* WARNING: Subroutine does not return */

          ExitProcess(3);

        }

        iVar4 = *piStack_20;

        piStack_20 = piStack_20 + 1;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x88) = 0;

      } while (piStack_20 != piStack_1c);

    }

    if ((void *)param_1[0x25] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0x25]);

    }

    param_1[0x25] = 0;

    param_1[0x26] = 0;

    param_1[0x27] = 0;

  }

  local_4 = CONCAT31(local_4._1_3_,6);

  FUN_00441960(&piStack_1c,*(uint32_t /* width from decompiler */ *)param_1[0x2a],(uint32_t /* width from decompiler */ *)param_1[0x2a]);

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x2a]);

}
