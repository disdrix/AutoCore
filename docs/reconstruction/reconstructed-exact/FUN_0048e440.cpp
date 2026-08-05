// =============================================================================
// FUN_0048e440
// -----------------------------------------------------------------------------
// Stable ID: aa_0048e440
// Address:   0x0048e440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048e440 @ 0x0048e440
// Stable ID: aa_0048e440
// Embedded strings (evidence for future rename):
//   - "<![CDATA["
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×14, while×5, do×4, goto×4, return×4.
//  - Notable callees: FUN_0048d970×2, CONCAT31, FUN_0048a940, FUN_0048aa20, FUN_0048af60, FUN_0048cca0, FUN_0048d0a0, FUN_0048e440.
//  - Strings: "<![CDATA["; "]]>".
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

int __thiscall FUN_0048e440(int param_1,char *param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  char *pcVar1;

  char *pcVar2;

  int iVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *extraout_ECX;

  uint32_t /* width from decompiler */ *puVar5;

  char *pcVar6;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0788;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0048a940(&DAT_00a1419b,0);

  FUN_0048af60();

  pcVar6 = param_2;

  puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  if (param_3 != 0) {

    FUN_0048cca0(param_2,param_4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *extraout_ECX;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = extraout_ECX[1];

    puVar5 = extraout_ECX;

  }

  if (*(char *)(param_1 + 0x2c) == '\0') {

    pcVar2 = "<![CDATA[";

    if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {

      do {

        if (*pcVar2 == '\0') goto LAB_0048e508;

      } while (((pcVar6 + -0x9c6ed8)[(int)pcVar2] == *pcVar2) &&

              (pcVar4 = pcVar6 + -0x9c6ed7 + (int)pcVar2, pcVar2 = pcVar2 + 1, *pcVar4 != '\0'));

      if (*pcVar2 == '\0') goto LAB_0048e508;

    }

    iVar3 = FUN_0048d970(pcVar6,param_1 + 0x20,1,&DAT_00a89e08,0,param_4);

    if (iVar3 != 0) {

      ExceptionList = local_c;

      return iVar3 + -1;

    }

  }

  else {

LAB_0048e508:

    *(uint8_t *)(param_1 + 0x2c) = 1;

    pcVar2 = "<![CDATA[";

    if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {

      do {

        if (*pcVar2 == '\0') goto LAB_0048e560;

      } while (((pcVar6 + -0x9c6ed8)[(int)pcVar2] == *pcVar2) &&

              (pcVar4 = pcVar6 + -0x9c6ed7 + (int)pcVar2, pcVar2 = pcVar2 + 1, *pcVar4 != '\0'));

      if (*pcVar2 == '\0') {

LAB_0048e560:

        pcVar2 = "<![CDATA[";

        do {

          pcVar4 = pcVar2;

          pcVar2 = pcVar4 + 1;

        } while (*pcVar4 != '\0');

        pcVar6 = pcVar6 + (int)(pcVar4 + -0x9c6ed8);

        if (pcVar6 != (char *)0x0) {

          pcVar2 = pcVar6 + -0x9c6ee4;

          while (*pcVar6 != '\0') {

            pcVar4 = "]]>";

            do {

              if (*pcVar4 == '\0') goto LAB_0048e5c1;

            } while ((pcVar2[(int)pcVar4] == *pcVar4) &&

                    (pcVar1 = pcVar2 + 1 + (int)pcVar4, pcVar4 = pcVar4 + 1, *pcVar1 != '\0'));

            if (*pcVar4 == '\0') break;

            param_3 = CONCAT31(param_3._1_3_,*pcVar6);

            FUN_0048aa20(&param_3,1);

            pcVar6 = pcVar6 + 1;

            pcVar2 = pcVar2 + 1;

            if (pcVar6 == (char *)0x0) break;

          }

        }

LAB_0048e5c1:

        param_2 = (char *)&DAT_00b03504;

        local_4 = 0;

        iVar3 = FUN_0048d970(pcVar6,&param_2,0,&DAT_009c6ee4,0,param_4);

        local_4 = 0xffffffff;

        if (param_2 == (char *)&DAT_00b03504) {

          ExceptionList = local_c;

          return iVar3;

        }

                    /* WARNING: Subroutine does not return */

        operator_delete(param_2);

      }

    }

    FUN_0048d0a0(0xf,pcVar6,puVar5,param_4);

  }

  ExceptionList = local_c;

  return 0;

}
