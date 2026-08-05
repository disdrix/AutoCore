// =============================================================================
// FUN_007b6770
// -----------------------------------------------------------------------------
// Stable ID: aa_007b6770
// Address:   0x007b6770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b6770 @ 0x007b6770
// Stable ID: aa_007b6770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~159 non-empty decompiler lines.
//  - Control keywords: if×12, do×8, while×8, goto×4, for×4, return×2.
//  - Notable callees: PathFileExistsA×4, FUN_0040d9c0×2, FUN_007b6420×2, FUN_0043c5f0, FUN_007b66c0, FUN_007b6770, FUN_00989e00.
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

bool __thiscall FUN_007b6770(int param_1,LPCSTR param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  char cVar3;

  uint uVar4;

  BOOL BVar5;

  char *pcVar6;

  char *pcVar7;

  uint uVar8;

  char *pcVar9;

  char *pcVar10;

  bool bVar11;

  char *local_134;

  int local_130;

  uint8_t local_12c [4];

  int local_128;

  uint local_124;

  uint local_120;

  int local_11c;

  LPCSTR local_118;

  uint32_t /* width from decompiler */ uStack_114;

  char local_110 [260];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b00b4;

  local_c = ExceptionList;

  local_128 = 0;

  local_124 = 0;

  local_120 = 0;

  local_11c = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  local_130 = param_1;

  FUN_0043c5f0(local_12c);

  if (local_11c == 0) {

    FUN_0040d9c0();

    ExceptionList = local_c;

    return false;

  }

  uVar4 = local_120 >> 2;

  iVar2 = uVar4 * -4;

  if (local_124 <= uVar4) {

    uVar4 = uVar4 - local_124;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(local_128 + uVar4 * 4) + (local_120 + iVar2) * 4) + 4)

  ;

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    if ((*(byte *)(param_1 + 4) & 1) != 0) {

      BVar5 = PathFileExistsA(param_2);

      if (BVar5 != 0) {

LAB_007b68b6:

        bVar11 = true;

        goto LAB_007b69ab;

      }

      local_134 = (char *)FUN_007b6420();

      pcVar10 = (char *)&DAT_00d1e574;

      do {

        pcVar7 = pcVar10;

        if (0xf < *(uint *)(pcVar10 + 0x14)) {

          pcVar7 = *(char **)pcVar10;

        }

        pcVar9 = local_110;

        do {

          cVar3 = *pcVar7;

          *pcVar9 = cVar3;

          pcVar7 = pcVar7 + 1;

          pcVar9 = pcVar9 + 1;

          pcVar6 = local_134;

        } while (cVar3 != '\0');

        do {

          cVar3 = *pcVar6;

          pcVar6 = pcVar6 + 1;

        } while (cVar3 != '\0');

        uVar4 = (int)pcVar6 - (int)local_134;

        pcVar7 = (char *)((int)&uStack_114 + 3);

        do {

          pcVar9 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

        } while (*pcVar9 != '\0');

        pcVar9 = local_134;

        for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar9;

          pcVar9 = pcVar9 + 4;

          pcVar7 = pcVar7 + 4;

        }

        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

          *pcVar7 = *pcVar9;

          pcVar9 = pcVar9 + 1;

          pcVar7 = pcVar7 + 1;

        }

        BVar5 = PathFileExistsA(local_110);

        if (BVar5 != 0) goto LAB_007b68b6;

        pcVar10 = pcVar10 + 0x1c;

        param_1 = local_130;

      } while ((int)pcVar10 < 0xd1e7a4);

    }

  }

  else {

    FUN_00989e00(&local_134,param_2);

    (**(code **)*puVar1)(&local_118,&local_134);

    local_134 = PTR_DAT_00afa2bc;

    if (local_118 != (LPCSTR)0x0) {

      local_134 = local_118;

    }

    if ((*(byte *)(param_1 + 4) & 1) != 0) {

      BVar5 = PathFileExistsA(local_134);

      if (BVar5 != 0) goto LAB_007b68b6;

      uStack_114 = (char *)FUN_007b6420();

      pcVar10 = (char *)&DAT_00d1e574;

      do {

        pcVar7 = pcVar10;

        if (0xf < *(uint *)(pcVar10 + 0x14)) {

          pcVar7 = *(char **)pcVar10;

        }

        pcVar9 = local_110;

        do {

          cVar3 = *pcVar7;

          *pcVar9 = cVar3;

          pcVar7 = pcVar7 + 1;

          pcVar9 = pcVar9 + 1;

          pcVar6 = uStack_114;

        } while (cVar3 != '\0');

        do {

          cVar3 = *pcVar6;

          pcVar6 = pcVar6 + 1;

        } while (cVar3 != '\0');

        uVar4 = (int)pcVar6 - (int)uStack_114;

        pcVar7 = (char *)((int)&uStack_114 + 3);

        do {

          pcVar9 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

        } while (*pcVar9 != '\0');

        pcVar9 = uStack_114;

        for (uVar8 = uVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar9;

          pcVar9 = pcVar9 + 4;

          pcVar7 = pcVar7 + 4;

        }

        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

          *pcVar7 = *pcVar9;

          pcVar9 = pcVar9 + 1;

          pcVar7 = pcVar7 + 1;

        }

        BVar5 = PathFileExistsA(local_110);

        if (BVar5 != 0) goto LAB_007b68b6;

        pcVar10 = pcVar10 + 0x1c;

        param_1 = local_130;

      } while ((int)pcVar10 < 0xd1e7a4);

    }

  }

  cVar3 = FUN_007b66c0(param_1);

  bVar11 = cVar3 != '\0';

LAB_007b69ab:

  FUN_0040d9c0();

  ExceptionList = local_c;

  return bVar11;

}
