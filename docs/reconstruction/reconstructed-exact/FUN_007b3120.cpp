// =============================================================================
// FUN_007b3120
// -----------------------------------------------------------------------------
// Stable ID: aa_007b3120
// Address:   0x007b3120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b3120 @ 0x007b3120
// Stable ID: aa_007b3120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×2, for×1.
//  - Notable callees: FUN_00755ab0×2, CONCAT22, CONCAT31, FUN_00755890, FUN_007b3120.
//  - Return sites: 2.

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

void __fastcall FUN_007b3120(int *param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  char *pcVar5;

  int iVar6;

  void *pvVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  uint8_t local_8 [8];

  

  if ((((char *)param_1[0x9d] != (char *)0x0) && (*(char *)param_1[0x9d] != '\0')) &&

     (param_1[0xa4] != 0)) {

    piVar4 = (int *)FUN_00755ab0(local_8);

    iVar8 = *piVar4;

    piVar4 = (int *)(**(code **)(*param_1 + 0x140))(local_8,1);

    iVar3 = *piVar4;

    if (iVar3 < iVar8) {

      pcVar5 = (char *)param_1[0x9d];

      pcVar1 = pcVar5 + 1;

      do {

        cVar2 = *pcVar5;

        pcVar5 = pcVar5 + 1;

      } while (cVar2 != '\0');

      iVar6 = (int)pcVar5 - (int)pcVar1;

      pvVar7 = operator_new__(iVar6 + 4);

      piVar4 = (int *)FUN_00755ab0(&stack0xffffffe4);

      iVar8 = *piVar4;

      iVar10 = 0;

      iVar9 = iVar8;

      if (0 < iVar6) {

        do {

          iVar8 = FUN_00755890(CONCAT22((short)((uint)iVar8 >> 0x10),

                                        (short)*(char *)(iVar10 + param_1[0x9d])));

          iVar9 = *(int *)(iVar8 + 0x18) + iVar9;

          if (iVar3 <= iVar9) break;

          iVar8 = CONCAT31((int3)((uint)iVar9 >> 8),*(uint8_t *)(iVar10 + param_1[0x9d]));

          *(uint8_t *)(iVar10 + (int)pvVar7) = *(uint8_t *)(iVar10 + param_1[0x9d]);

          iVar10 = iVar10 + 1;

        } while (iVar10 < iVar6);

        for (; (0 < iVar10 && (*(char *)(iVar10 + -1 + (int)pvVar7) == ' ')); iVar10 = iVar10 + -1)

        {

        }

      }

      *(uint8_t *)(iVar10 + (int)pvVar7) = 0x2e;

      *(uint8_t *)(iVar10 + 1 + (int)pvVar7) = 0x2e;

      *(uint8_t *)(iVar10 + 2 + (int)pvVar7) = 0x2e;

      *(uint8_t *)(iVar10 + 3 + (int)pvVar7) = 0;

      if ((void *)param_1[0x9d] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)param_1[0x9d]);

      }

      param_1[0x9d] = (int)pvVar7;

    }

  }

  return;

}
