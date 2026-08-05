// =============================================================================
// FUN_004a6670
// -----------------------------------------------------------------------------
// Stable ID: aa_004a6670
// Address:   0x004a6670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a6670 @ 0x004a6670
// Stable ID: aa_004a6670
// Embedded strings (evidence for future rename):
//   - "NDSpecialFX"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: for×3, do×3, while×3, if×2, return×2.
//  - Notable callees: FUN_00798990×2, FUN_004a4fa0, FUN_004a6670, FUN_00799900, NDXml_OpenTaggedDocument.
//  - Strings: "NDSpecialFX".
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

uint32_t /* width from decompiler */ FUN_004a6670(char *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char *pcVar3;

  int *piVar4;

  int iVar5;

  uint uVar6;

  char *pcVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint8_t local_115;

  uint8_t local_114 [4];

  char local_110 [2];

  uint32_t /* width from decompiler */ uStack_10e;

  char local_108 [260];

  

  pcVar3 = local_110 + 2;

  for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {

    pcVar3[0] = '\0';

    pcVar3[1] = '\0';

    pcVar3[2] = '\0';

    pcVar3[3] = '\0';

    pcVar3 = pcVar3 + 4;

  }

  pcVar3[0] = '\0';

  pcVar3[1] = '\0';

  _local_110 = s____scripts__00a96040._0_4_;

  local_108._0_4_ = s____scripts__00a96040._8_4_;

  stack0xfffffef4 = s____scripts__00a96040._4_4_;

  pcVar3 = param_1;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  pcVar8 = local_114 + 3;

  do {

    pcVar7 = pcVar8 + 1;

    pcVar8 = pcVar8 + 1;

  } while (*pcVar7 != '\0');

  pcVar7 = param_1;

  for (uVar6 = (uint)((int)pcVar3 - (int)param_1) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar7;

    pcVar7 = pcVar7 + 4;

    pcVar8 = pcVar8 + 4;

  }

  for (uVar6 = (int)pcVar3 - (int)param_1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

    *pcVar8 = *pcVar7;

    pcVar7 = pcVar7 + 1;

    pcVar8 = pcVar8 + 1;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(local_114 + 3);

  do {

    puVar9 = puVar2;

    puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

  } while (*(char *)((int)puVar9 + 1) != '\0');

  *(uint32_t /* width from decompiler */ *)((int)puVar9 + 1) = DAT_009ca184;

  *(uint32_t /* width from decompiler */ *)((int)puVar9 + 5) = DAT_009ca188;

  *(uint8_t *)((int)puVar9 + 9) = DAT_009ca18c;

  uVar10 = 0;

  iVar5 = NDXml_OpenTaggedDocument(local_110,"NDSpecialFX");

  if ((iVar5 == 0) && (0 < *(int *)(DAT_00b035fc + 0xc))) {

    piVar4 = (int *)FUN_00799900(0);

    if (piVar4 == (int *)0x0) {

      FUN_00798990();

      return 0;

    }

    local_114 = (uint8_t  [4])0x0;

    local_115 = 0;

    uVar10 = FUN_004a4fa0(piVar4,local_114,&local_115,param_1);

    (**(code **)(*piVar4 + 8))(piVar4);

  }

  FUN_00798990();

  return uVar10;

}
