// =============================================================================
// FUN_007b6a90
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6a90
// Address:   0x007b6a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b6a90 @ 0x007b6a90
// Stable ID: aa_007b6a90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×10, do×8, while×8, for×4, return×3, goto×2.
//  - Notable callees: PathFileExistsA×2, strrchr×2, FUN_007b6420, FUN_007b66c0, FUN_007b6a90, FUN_00989e00, stat.
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

ulonglong FUN_007b6a90(int param_1,char *param_2)



{

  char cVar1;

  BOOL BVar2;

  char *pcVar3;

  uint uVar4;

  int iVar5;

  char *pcVar6;

  uint uVar7;

  char *pcVar8;

  char *pcVar9;

  char *local_12c;

  uint8_t local_128 [28];

  int local_10c;

  char cStack_105;

  char local_104 [260];

  

  if ((*(byte *)(param_1 + 4) & 1) != 0) {

    BVar2 = PathFileExistsA(param_2);

    if (BVar2 == 0) {

      local_12c = (char *)FUN_007b6420();

      pcVar9 = (char *)&DAT_00d1e574;

      do {

        pcVar6 = pcVar9;

        if (0xf < *(uint *)(pcVar9 + 0x14)) {

          pcVar6 = *(char **)pcVar9;

        }

        pcVar8 = local_104;

        do {

          cVar1 = *pcVar6;

          *pcVar8 = cVar1;

          pcVar6 = pcVar6 + 1;

          pcVar8 = pcVar8 + 1;

          pcVar3 = local_12c;

        } while (cVar1 != '\0');

        do {

          cVar1 = *pcVar3;

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

        uVar4 = (int)pcVar3 - (int)local_12c;

        pcVar6 = &cStack_105;

        do {

          pcVar8 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

        } while (*pcVar8 != '\0');

        pcVar8 = local_12c;

        for (uVar7 = uVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar8;

          pcVar8 = pcVar8 + 4;

          pcVar6 = pcVar6 + 4;

        }

        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

          *pcVar6 = *pcVar8;

          pcVar8 = pcVar8 + 1;

          pcVar6 = pcVar6 + 1;

        }

        BVar2 = PathFileExistsA(local_104);

        if (BVar2 != 0) goto LAB_007b6b80;

        pcVar9 = pcVar9 + 0x1c;

      } while ((int)pcVar9 < 0xd1e7a4);

    }

    else {

LAB_007b6b80:

      pcVar9 = (char *)&DAT_00d1e574;

      do {

        pcVar6 = pcVar9;

        if (0xf < *(uint *)(pcVar9 + 0x14)) {

          pcVar6 = *(char **)pcVar9;

        }

        pcVar8 = local_104;

        do {

          cVar1 = *pcVar6;

          *pcVar8 = cVar1;

          pcVar6 = pcVar6 + 1;

          pcVar8 = pcVar8 + 1;

          pcVar3 = param_2;

        } while (cVar1 != '\0');

        do {

          cVar1 = *pcVar3;

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

        uVar4 = (int)pcVar3 - (int)param_2;

        pcVar6 = &cStack_105;

        do {

          pcVar8 = pcVar6 + 1;

          pcVar6 = pcVar6 + 1;

        } while (*pcVar8 != '\0');

        pcVar8 = param_2;

        for (uVar7 = uVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar8;

          pcVar8 = pcVar8 + 4;

          pcVar6 = pcVar6 + 4;

        }

        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

          *pcVar6 = *pcVar8;

          pcVar8 = pcVar8 + 1;

          pcVar6 = pcVar6 + 1;

        }

        iVar5 = stat(local_104,local_128);

        if (iVar5 == 0) {

          return (longlong)local_10c;

        }

        pcVar9 = pcVar9 + 0x1c;

      } while ((int)pcVar9 < 0xd1e7a4);

    }

  }

  cVar1 = FUN_007b66c0(param_1);

  if (cVar1 == '\0') {

    return 0;

  }

  pcVar6 = strrchr(param_2,0x5c);

  pcVar9 = strrchr(param_2,0x2f);

  if (pcVar6 == (char *)0x0) {

    if (pcVar9 == (char *)0x0) goto LAB_007b6c28;

  }

  else if (pcVar9 < pcVar6) {

    pcVar9 = pcVar6;

  }

  param_2 = pcVar9 + 1;

LAB_007b6c28:

  FUN_00989e00(&local_12c,param_2);

  uVar4 = (**(code **)(**(int **)(param_1 + 0xc) + 0x10))(&local_12c);

  return (ulonglong)uVar4;

}
