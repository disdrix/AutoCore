// =============================================================================
// FUN_0059a200
// -----------------------------------------------------------------------------
// Stable ID: aa_0059a200
// Address:   0x0059a200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059a200 @ 0x0059a200
// Stable ID: aa_0059a200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×7, while×4, do×2, return×1.
//  - Notable callees: fwrite×7, FUN_0059a200, wcslen.
//  - Return sites: 1.

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

void __thiscall FUN_0059a200(int param_1,FILE *param_2)



{

  char cVar1;

  int *piVar2;

  FILE *_File;

  int *piVar3;

  int iVar4;

  code *pcVar5;

  int *piVar6;

  int iVar7;

  size_t local_c;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  _File = param_2;

  pcVar5 = fwrite_exref;

  local_4 = param_1;

  fwrite((void *)(param_1 + 4),0x3b4,1,param_2);

  fwrite((void *)(param_1 + 0x3b8),0x108,1,_File);

  fwrite((void *)(param_1 + 0x4c0),0x5c,1,_File);

  local_c = 0;

  if (*(wchar_t **)(param_1 + 0x518) != (wchar_t *)0x0) {

    local_c = wcslen(*(wchar_t **)(param_1 + 0x518));

  }

  fwrite(&local_c,4,1,_File);

  if (0 < (int)local_c) {

    fwrite(*(void **)(param_1 + 0x518),2,local_c,_File);

  }

  local_8 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x524);

  fwrite(&local_8,4,1,_File);

  piVar6 = (int *)**(int **)(param_1 + 0x520);

  if (piVar6 != *(int **)(param_1 + 0x520)) {

    do {

      (*pcVar5)(piVar6 + 3,1,1,_File);

      iVar7 = 0;

      if (piVar6[5] == 0) {

        param_2 = (FILE *)0x0;

      }

      else {

        param_2 = (FILE *)((piVar6[6] - piVar6[5]) / 0x18);

      }

      (*pcVar5)(&param_2,4,1,_File);

      if (0 < (int)param_2) {

        iVar4 = 0;

        do {

          fwrite((void *)(piVar6[5] + iVar4),0x18,1,_File);

          iVar7 = iVar7 + 1;

          iVar4 = iVar4 + 0x18;

          pcVar5 = fwrite_exref;

        } while (iVar7 < (int)param_2);

      }

      if (*(char *)((int)piVar6 + 0x21) == '\0') {

        piVar2 = (int *)piVar6[2];

        if (*(char *)((int)piVar2 + 0x21) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x21);

          piVar6 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x21);

            piVar6 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar6[1] + 0x21);

          piVar3 = (int *)piVar6[1];

          piVar2 = piVar6;

          while ((piVar6 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {

            cVar1 = *(char *)(piVar6[1] + 0x21);

            piVar3 = (int *)piVar6[1];

            piVar2 = piVar6;

          }

        }

      }

    } while (piVar6 != *(int **)(local_4 + 0x520));

  }

  return;

}
