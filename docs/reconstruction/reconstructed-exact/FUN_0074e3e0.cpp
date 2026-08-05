// =============================================================================
// FUN_0074e3e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e3e0
// Address:   0x0074e3e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074e3e0 @ 0x0074e3e0
// Stable ID: aa_0074e3e0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightManager.cpp"
//   - "Lights still allocated at shutdown."
//   - "c:\\VOGCRASH.txt"
//   - ");

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, for×2, do×2, while×2.
//  - Notable callees: ExitProcess, FUN_0040ae90, FUN_00463e30, FUN_0074e3e0, FUN_0076d1b0, FUN_00968080, block, fclose.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightManager.cpp"; "Lights still allocated at shutdown."; "c:\\VOGCRASH.txt"; "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n".
//  - Return sites: 4.

      if (_File != (FILE *)0x0) {

        fprintf(_File,"
//   - ",

                "
//   - ",0x5d,2,

                "
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

/* WARNING: Removing unreachable block (ram,0x0074e461) */



void FUN_0074e3e0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  int *piVar4;

  int iVar5;

  int in_EAX;

  int iVar6;

  FILE *_File;

  int *piVar7;

  int *piVar8;

  int *piStack_4;

  

  piVar7 = *(int **)(in_EAX + 0x3c);

  if (piVar7 != (int *)0x0) {

    piVar8 = piVar7 + 1;

    *piVar8 = *piVar8 + -1;

    if (*piVar8 == 0) {

      (**(code **)(*piVar7 + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x3c) = 0;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x1c);

  for (puVar2 = (uint32_t /* width from decompiler */ *)*puVar1; puVar2 != puVar1; puVar2 = (uint32_t /* width from decompiler */ *)*puVar2) {

    *(uint32_t /* width from decompiler */ *)puVar2[2] = 0;

    FUN_00968080();

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x1c);

  pvVar3 = (void *)*puVar1;

  *puVar1 = puVar1;

  *(int *)(*(int *)(in_EAX + 0x1c) + 4) = *(int *)(in_EAX + 0x1c);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20) = 0;

  if (pvVar3 != *(void **)(in_EAX + 0x1c)) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

  piStack_4 = *(int **)(in_EAX + 0x1c);

  if (*(int *)(in_EAX + 0x28) != *(int *)(in_EAX + 0x2c)) {

    *(int *)(in_EAX + 0x2c) = *(int *)(in_EAX + 0x28);

  }

  FUN_00463e30(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x28),9,&piStack_4);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x34) = 1;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x38) = 1;

  if ((*(int *)(in_EAX + 8) != 0) &&

     (piStack_4 = (int *)(*(int *)(in_EAX + 0xc) - *(int *)(in_EAX + 8) >> 2),

     piStack_4 != (int *)0x0)) {

    iVar6 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightManager.cpp",0x5d,

                         "Lights still allocated at shutdown.");

    if (iVar6 == 3) {

      _File = fopen("c:\\VOGCRASH.txt","w");

      if (_File != (FILE *)0x0) {

        fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",

                "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightManager.cpp",0x5d,2,

                "Lights still allocated at shutdown.");

        fclose(_File);

      }

      raise(0x16);

                    /* WARNING: Subroutine does not return */

      ExitProcess(3);

    }

    piVar7 = *(int **)(in_EAX + 0xc);

    piVar8 = *(int **)(in_EAX + 8);

    piStack_4 = piVar7;

    if (piVar8 != piVar7) {

      do {

        piVar4 = (int *)*piVar8;

        iVar6 = piVar4[1];

        if (1 < iVar6) {

          iVar6 = iVar6 + -1;

          do {

            (**(code **)(*piVar4 + 0x44))();

            iVar6 = iVar6 + -1;

            piVar7 = piStack_4;

          } while (iVar6 != 0);

        }

        piVar8 = piVar8 + 1;

      } while (piVar8 != piVar7);

    }

    iVar6 = *(int *)(in_EAX + 8);

    if (iVar6 != 0) {

      iVar5 = *(int *)(in_EAX + 0xc);

      for (; iVar6 != iVar5; iVar6 = iVar6 + 4) {

        FUN_0040ae90();

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(in_EAX + 8));

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

  }

  return;

}
