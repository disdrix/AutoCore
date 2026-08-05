// =============================================================================
// FUN_00857ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00857ee0
// Address:   0x00857ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00857ee0 @ 0x00857ee0
// Stable ID: aa_00857ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×6, do×6, while×6, for×3, return×2, goto×2.
//  - Notable callees: PathFileExistsA×2, FUN_007b6420, FUN_007b66c0, FUN_007b6a20, FUN_00857ee0, strncat.
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

void __fastcall FUN_00857ee0(uint32_t /* width from decompiler */ param_1,char *param_2,int *param_3)



{

  char cVar1;

  char *pcVar2;

  BOOL BVar3;

  uint8_t auVar4 [4];

  uint uVar5;

  int iVar6;

  char *pcVar7;

  uint uVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint8_t local_20c [4];

  uint8_t local_208 [2];

  uint32_t /* width from decompiler */ uStack_206;

  char cStack_202;

  char cStack_201;

  char local_200 [4];

  char local_1fc [247];

  char cStack_105;

  char local_104 [260];

  

  if (param_2 == (char *)0x0) {

    (**(code **)(*param_3 + 0x58))();

    return;

  }

  _local_208 = _local_208 & 0xffff0000;

  puVar10 = (uint32_t /* width from decompiler */ *)(local_208 + 2);

  for (iVar6 = 0x40; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  *(uint16_t *)puVar10 = 0;

  pcVar2 = param_2;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  strncat(local_208,param_2,(size_t)(pcVar2 + (-4 - (int)(param_2 + 1))));

  puVar10 = (uint32_t /* width from decompiler */ *)(local_20c + 3);

  do {

    puVar11 = puVar10;

    puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

  } while (*(char *)((int)puVar11 + 1) != '\0');

  *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_00a2c53c;

  *(uint8_t *)((int)puVar11 + 5) = DAT_00a2c540;

  iVar6 = FUN_007b6a20();

  if ((*(byte *)(iVar6 + 4) & 1) != 0) {

    BVar3 = PathFileExistsA(local_208);

    if (BVar3 != 0) goto LAB_0085803c;

    local_20c = (uint8_t  [4])FUN_007b6420();

    pcVar2 = (char *)&DAT_00d1e574;

    do {

      pcVar7 = pcVar2;

      if (0xf < *(uint *)(pcVar2 + 0x14)) {

        pcVar7 = *(char **)pcVar2;

      }

      pcVar9 = local_104;

      do {

        cVar1 = *pcVar7;

        *pcVar9 = cVar1;

        pcVar7 = pcVar7 + 1;

        pcVar9 = pcVar9 + 1;

        auVar4 = local_20c;

      } while (cVar1 != '\0');

      do {

        cVar1 = *(char *)auVar4;

        auVar4 = (uint8_t  [4])((int)auVar4 + 1);

      } while (cVar1 != '\0');

      uVar5 = (int)auVar4 - (int)local_20c;

      pcVar7 = &cStack_105;

      do {

        pcVar9 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar9 != '\0');

      auVar4 = local_20c;

      for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)auVar4;

        auVar4 = (uint8_t  [4])((int)auVar4 + 4);

        pcVar7 = pcVar7 + 4;

      }

      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

        *pcVar7 = *(char *)auVar4;

        auVar4 = (uint8_t  [4])((int)auVar4 + 1);

        pcVar7 = pcVar7 + 1;

      }

      BVar3 = PathFileExistsA(local_104);

      if (BVar3 != 0) goto LAB_0085803c;

      pcVar2 = pcVar2 + 0x1c;

    } while ((int)pcVar2 < 0xd1e7a4);

  }

  cVar1 = FUN_007b66c0(iVar6);

  if (cVar1 == '\0') {

    local_208[0] = s_sec_unknown_dds_00a3970c[0];

    local_208[1] = s_sec_unknown_dds_00a3970c[1];

    uStack_206._0_1_ = s_sec_unknown_dds_00a3970c[2];

    uStack_206._1_1_ = s_sec_unknown_dds_00a3970c[3];

    uStack_206._2_1_ = s_sec_unknown_dds_00a3970c[4];

    uStack_206._3_1_ = s_sec_unknown_dds_00a3970c[5];

    cStack_202 = s_sec_unknown_dds_00a3970c[6];

    cStack_201 = s_sec_unknown_dds_00a3970c[7];

    local_200[0] = s_sec_unknown_dds_00a3970c[8];

    local_200[1] = s_sec_unknown_dds_00a3970c[9];

    local_200[2] = s_sec_unknown_dds_00a3970c[10];

    local_200[3] = s_sec_unknown_dds_00a3970c[0xb];

    local_1fc[0] = s_sec_unknown_dds_00a3970c[0xc];

    local_1fc[1] = s_sec_unknown_dds_00a3970c[0xd];

    local_1fc[2] = s_sec_unknown_dds_00a3970c[0xe];

    local_1fc[3] = s_sec_unknown_dds_00a3970c[0xf];

  }

LAB_0085803c:

  (**(code **)(*param_3 + 0x50))(local_208,1,0);

  return;

}
