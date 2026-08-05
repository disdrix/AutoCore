// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007b7b70
// -----------------------------------------------------------------------------
// Stable ID: aa_007b7b70
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x007b7b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~152 non-empty decompiler lines.
//  - Control keywords: if×13, do×8, while×8, for×4, goto×4, return×3.
//  - Notable callees: PathFileExistsA×4, FUN_007b7420×3, FUN_007b6420×2, FUN_007b6a90×2, FUN_007b66c0, FUN_007b7b70, block.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007b7d4b) */



void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_007b7b70(int param_1,LPCSTR param_2,LPCSTR param_3,char *param_4)



{

  bool bVar1;

  bool bVar2;

  char cVar3;

  BOOL BVar4;

  char *pcVar5;

  char *pcVar6;

  uint uVar7;

  char *pcVar8;

  uint uVar9;

  char *pcVar10;

  char *pcVar11;

  longlong lVar12;

  longlong lVar13;

  uint32_t /* width from decompiler */ local_108;

  char local_104 [260];

  

  local_108 = param_1;

  cVar3 = FUN_007b66c0(param_1);

  if (cVar3 != '\0') {

    FUN_007b7420(param_3);

    return;

  }

  if ((*param_4 == '\0') || ((*(byte *)(param_1 + 4) & 1) == 0)) {

LAB_007b7c54:

    bVar2 = false;

  }

  else {

    BVar4 = PathFileExistsA(param_3);

    if (BVar4 == 0) {

      pcVar5 = (char *)FUN_007b6420();

      pcVar11 = (char *)&DAT_00d1e574;

      do {

        pcVar8 = pcVar11;

        if (0xf < *(uint *)(pcVar11 + 0x14)) {

          pcVar8 = *(char **)pcVar11;

        }

        pcVar10 = local_104;

        do {

          cVar3 = *pcVar8;

          *pcVar10 = cVar3;

          pcVar8 = pcVar8 + 1;

          pcVar10 = pcVar10 + 1;

          pcVar6 = pcVar5;

        } while (cVar3 != '\0');

        do {

          cVar3 = *pcVar6;

          pcVar6 = pcVar6 + 1;

        } while (cVar3 != '\0');

        uVar7 = (int)pcVar6 - (int)pcVar5;

        pcVar8 = (char *)((int)&local_108 + 3);

        do {

          pcVar10 = pcVar8 + 1;

          pcVar8 = pcVar8 + 1;

        } while (*pcVar10 != '\0');

        pcVar10 = pcVar5;

        for (uVar9 = uVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar10;

          pcVar10 = pcVar10 + 4;

          pcVar8 = pcVar8 + 4;

        }

        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

          *pcVar8 = *pcVar10;

          pcVar10 = pcVar10 + 1;

          pcVar8 = pcVar8 + 1;

        }

        BVar4 = PathFileExistsA(local_104);

        param_1 = local_108;

        if (BVar4 != 0) goto LAB_007b7c87;

        pcVar11 = pcVar11 + 0x1c;

      } while ((int)pcVar11 < 0xd1e7a4);

      goto LAB_007b7c54;

    }

LAB_007b7c87:

    bVar2 = true;

  }

  if ((*(byte *)(param_1 + 4) & 1) != 0) {

    BVar4 = PathFileExistsA(param_2);

    if (BVar4 != 0) {

      bVar1 = true;

      goto LAB_007b7d1d;

    }

    pcVar5 = (char *)FUN_007b6420();

    pcVar11 = (char *)&DAT_00d1e574;

    do {

      pcVar8 = pcVar11;

      if (0xf < *(uint *)(pcVar11 + 0x14)) {

        pcVar8 = *(char **)pcVar11;

      }

      pcVar10 = local_104;

      do {

        cVar3 = *pcVar8;

        *pcVar10 = cVar3;

        pcVar8 = pcVar8 + 1;

        pcVar10 = pcVar10 + 1;

        pcVar6 = pcVar5;

      } while (cVar3 != '\0');

      do {

        cVar3 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar3 != '\0');

      uVar7 = (int)pcVar6 - (int)pcVar5;

      pcVar8 = (char *)((int)&local_108 + 3);

      do {

        pcVar10 = pcVar8 + 1;

        pcVar8 = pcVar8 + 1;

      } while (*pcVar10 != '\0');

      pcVar10 = pcVar5;

      for (uVar9 = uVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar10;

        pcVar10 = pcVar10 + 4;

        pcVar8 = pcVar8 + 4;

      }

      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

        *pcVar8 = *pcVar10;

        pcVar10 = pcVar10 + 1;

        pcVar8 = pcVar8 + 1;

      }

      BVar4 = PathFileExistsA(local_104);

      param_1 = local_108;

      if (BVar4 != 0) {

        bVar1 = true;

        goto LAB_007b7d1d;

      }

      pcVar11 = pcVar11 + 0x1c;

    } while ((int)pcVar11 < 0xd1e7a4);

  }

  bVar1 = false;

LAB_007b7d1d:

  if (bVar2) {

    if (bVar1) {

      lVar12 = FUN_007b6a90(param_1,param_3);

      lVar13 = FUN_007b6a90(local_108,param_2);

      *param_4 = lVar13 <= lVar12;

    }

    cVar3 = *param_4;

  }

  else {

    if (bVar1) {

      *param_4 = '\0';

      FUN_007b7420(param_2);

      return;

    }

    cVar3 = *param_4;

  }

  if (cVar3 == '\0') {

    param_3 = param_2;

  }

  FUN_007b7420(param_3);

  return;

}
