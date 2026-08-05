// =============================================================================
// FUN_007ae4f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ae4f0
// Address:   0x007ae4f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ae4f0 @ 0x007ae4f0
// Stable ID: aa_007ae4f0
// Embedded strings (evidence for future rename):
//   - "[$/l]"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×12, while×7, do×6, return×3, goto×1.
//  - Notable callees: strncat×3, FUN_00423f40×2, sprintf×2, FUN_004294f0, FUN_007ae4f0, LeaveCriticalSection, strncpy.
//  - Strings: "[$/l]".
//  - Return sites: 3.

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

void __thiscall FUN_007ae4f0(int param_1,char *param_2,char *param_3)



{

  char cVar1;

  byte *pbVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  size_t _Count;

  size_t sVar6;

  int *local_70;

  uint32_t /* width from decompiler */ local_6c;

  int local_68;

  char local_64 [100];

  

  if (param_2 != (char *)0x0) {

    *param_2 = '\0';

    if (*(int *)(param_1 + 0x20c) == 0) {

      pcVar5 = *(char **)(param_1 + 0x274);

      if (pcVar5 != (char *)0x0) {

        pcVar4 = pcVar5;

        do {

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        if ((int)(pcVar4 + (1 - (int)(pcVar5 + 1))) < (int)param_3) {

          param_3 = pcVar5;

          do {

            cVar1 = *param_3;

            param_3 = param_3 + 1;

          } while (cVar1 != '\0');

          param_3 = param_3 + (1 - (int)(pcVar5 + 1));

        }

        strncpy(param_2,pcVar5,(size_t)param_3);

        return;

      }

      *param_2 = '\0';

    }

    else {

      param_1 = param_1 + 0x1e8;

      local_6c = 0;

      local_70 = (int *)0x0;

      local_68 = param_1;

      FUN_004294f0();

      iVar3 = FUN_00423f40(&local_70);

      while (iVar3 == 0) {

        if (local_70 != (int *)0x0) {

          if (((*local_70 == 1) && (pcVar5 = (char *)local_70[1], pcVar5 != (char *)0x0)) &&

             (*pcVar5 != '\0')) {

            pcVar4 = pcVar5;

            do {

              cVar1 = *pcVar4;

              pcVar4 = pcVar4 + 1;

            } while (cVar1 != '\0');

            iVar3 = (int)pcVar4 - (int)(pcVar5 + 1);

            pcVar4 = (char *)(iVar3 + 1);

            if ((int)param_3 <= iVar3 + 1) {

              pcVar4 = param_3;

            }

          }

          else {

            if (((*local_70 != 0xc) || (pbVar2 = (byte *)local_70[1], pbVar2 == (byte *)0x0)) ||

               (*(int *)(pbVar2 + 0x1c) == 0)) goto LAB_007ae684;

            sprintf(local_64,&DAT_00a96c40,(uint)*pbVar2,*(uint32_t /* width from decompiler */ *)(pbVar2 + 8),

                    *(uint32_t /* width from decompiler */ *)(pbVar2 + 0xc),*(uint32_t /* width from decompiler */ *)(pbVar2 + 0x10),

                    *(uint32_t /* width from decompiler */ *)(pbVar2 + 0x14));

            pcVar5 = local_64;

            do {

              cVar1 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar1 != '\0');

            pcVar4 = (char *)(((int)pcVar5 - (int)(local_64 + 1)) + 1);

            if ((int)param_3 <= (int)pcVar4) {

              pcVar4 = param_3;

            }

            strncat(param_2,local_64,(size_t)pcVar4);

            pcVar4 = *(char **)(pbVar2 + 0x1c);

            sVar6 = (int)param_3 - ((int)pcVar5 - (int)(local_64 + 1));

            pcVar5 = pcVar4;

            do {

              cVar1 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar1 != '\0');

            _Count = ((int)pcVar5 - (int)(pcVar4 + 1)) + 1;

            if ((int)sVar6 <= (int)_Count) {

              _Count = sVar6;

            }

            strncat(param_2,pcVar4,_Count);

            param_3 = (char *)(sVar6 - ((int)pcVar5 - (int)(pcVar4 + 1)));

            sprintf(local_64,"[$/l]");

            pcVar5 = local_64;

            do {

              cVar1 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar1 != '\0');

            iVar3 = (int)pcVar5 - (int)(local_64 + 1);

            pcVar4 = (char *)(iVar3 + 1);

            if ((int)param_3 <= iVar3 + 1) {

              pcVar4 = param_3;

            }

            pcVar5 = local_64;

          }

          strncat(param_2,pcVar5,(size_t)pcVar4);

          param_3 = param_3 + -iVar3;

        }

LAB_007ae684:

        param_1 = local_68;

        iVar3 = FUN_00423f40(&local_70);

      }

      if (*(char *)(param_1 + 0x28) != '\0') {

        *(uint8_t *)(param_1 + 0x28) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

        return;

      }

    }

  }

  return;

}
