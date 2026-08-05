// =============================================================================
// FUN_00475070
// -----------------------------------------------------------------------------
// Stable ID: aa_00475070
// Address:   0x00475070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00475070 @ 0x00475070
// Stable ID: aa_00475070
// Embedded strings (evidence for future rename):
//   - "1.2.8"
//   - "Application was compiled with png.h from libpng-%.20s"
//   - "Application  is  running with png.c from libpng-%.20s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~118 non-empty decompiler lines.
//  - Control keywords: if×11, return×8, for×1, do×1, while×1, switch×1, goto×1.
//  - Notable callees: FUN_00476cc0×4, FUN_00476d60×4, setjmp3×2, sprintf×2, FUN_00475070, FUN_00477690, FUN_004776d0, FUN_00478d60.
//  - Strings: "1.2.8"; "Application was compiled with png.h from libpng-%.20s"; "Application  is  running with png.c from libpng-%.20s".
//  - Return sites: 8.

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

uint32_t /* width from decompiler */ *

FUN_00475070(char *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,code *param_6,uint32_t /* width from decompiler */ param_7)



{

  char cVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *extraout_EAX;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t local_2c4 [580];

  uint32_t /* width from decompiler */ local_80;

  char local_58 [80];

  uint32_t /* width from decompiler */ *local_8;

  

  if (param_6 == (code *)0x0) {

    local_8 = malloc(0x26c);

  }

  else {

    local_80 = param_5;

    local_8 = (uint32_t /* width from decompiler */ *)(*param_6)(local_2c4);

  }

  if (local_8 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = local_8;

    for (iVar4 = 0x9b; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

  }

  if (local_8 != (uint32_t /* width from decompiler */ *)0x0) {

    local_8[0x8f] = 0;

    *(uint8_t *)((int)local_8 + 0x239) = 0;

    *(uint8_t *)(local_8 + 0x90) = 0;

    local_8[0x99] = 1000000;

    local_8[0x9a] = 1000000;

    iVar4 = setjmp3(local_8,0);

    puVar5 = local_8;

    if (iVar4 == 0) {

      local_8[0x91] = param_5;

      local_8[0x92] = param_6;

      local_8[0x93] = param_7;

      local_8[0x12] = param_2;

      local_8[0x10] = param_3;

      pcVar2 = "1.2.8";

      local_8[0x11] = param_4;

      do {

        if ((param_1 + -0xa2657c)[(int)pcVar2] != *pcVar2) {

          local_8[0x1b] = local_8[0x1b] | 0x20000;

        }

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      if (((local_8[0x1b] & 0x20000) != 0) &&

         (((param_1 == (char *)0x0 || (*param_1 != '1')) || (param_1[2] != '2')))) {

        if (param_1 != (char *)0x0) {

          sprintf(local_58,"Application was compiled with png.h from libpng-%.20s",param_1);

          FUN_00476d60();

        }

        sprintf(local_58,"Application  is  running with png.c from libpng-%.20s",&DAT_00a2657c);

        FUN_00476d60();

        puVar5[0x1b] = 0;

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0(puVar5);

      }

      local_8[0x2c] = 0x2000;

      uVar3 = FUN_004776d0();

      puVar5[0x2b] = uVar3;

      puVar5[0x25] = FUN_004765c0;

      puVar5[0x26] = &LAB_00476640;

      puVar5[0x27] = puVar5;

      uVar3 = FUN_00478d60(0x38);

      switch(uVar3) {

      case 0:

        goto switchD_00475248_caseD_0;

      case 0xfffffffa:

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0(puVar5);

      default:

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0(puVar5);

      case 0xfffffffc:

      case 0xfffffffe:

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0(puVar5);

      }

    }

    if ((void *)local_8[0x2b] != (void *)0x0) {

      if ((code *)local_8[0x93] == (code *)0x0) {

        free((void *)local_8[0x2b]);

      }

      else {

        (*(code *)local_8[0x93])(local_8);

      }

    }

    puVar5[0x2b] = 0;

    FUN_00477690();

  }

  return (uint32_t /* width from decompiler */ *)0x0;

switchD_00475248_caseD_0:

  puVar5[0x20] = puVar5[0x2b];

  puVar5[0x21] = puVar5[0x2c];

  puVar5[0x15] = 0;

  puVar5[0x14] = &LAB_00477100;

  if (puVar5[0x13] != 0) {

    puVar5[0x13] = 0;

    FUN_00476d60();

    FUN_00476d60();

  }

  puVar5[0x53] = 0;

  iVar4 = setjmp3(puVar5,0);

  if (iVar4 != 0) {

                    /* WARNING: Could not recover jumptable at 0x004752a3. Too many branches */

                    /* WARNING: Subroutine does not return */

                    /* WARNING: Treating indirect jump as call */

    abort();

    return extraout_EAX;

  }

  return local_8;

}
