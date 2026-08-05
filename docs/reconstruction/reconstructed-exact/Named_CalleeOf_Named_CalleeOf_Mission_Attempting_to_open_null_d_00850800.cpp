// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_00850800
// -----------------------------------------------------------------------------
// Stable ID: aa_00850800
// Callee of Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i (+1 other named callers)
// Address:   0x00850800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~130 non-empty decompiler lines.
//  - Control keywords: if×7, do×6, while×6, return×3, for×3, goto×3.
//  - Notable callees: PathFileExistsA×2, FUN_007b6420, FUN_007b66c0, FUN_007b6a20, FUN_00850490, FUN_00850800, strncat.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_00850800(uint32_t /* width from decompiler */ param_1,char *param_2,int *param_3)



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

  uint8_t local_310 [4];

  uint8_t local_30c [2];

  uint32_t /* width from decompiler */ uStack_30a;

  char cStack_306;

  char cStack_305;

  char local_304 [4];

  char local_300 [507];

  char cStack_105;

  char local_104 [252];

  int *piStack_8;

  int iStack_4;

  

  if (param_2 == (char *)0x0) {

    (**(code **)(*param_3 + 0x58))();

    return;

  }

  _local_30c = _local_30c & 0xffff0000;

  puVar10 = (uint32_t /* width from decompiler */ *)(local_30c + 2);

  for (iVar6 = 0x81; iVar6 != 0; iVar6 = iVar6 + -1) {

    *puVar10 = 0;

    puVar10 = puVar10 + 1;

  }

  *(uint16_t *)puVar10 = 0;

  pcVar2 = param_2;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  strncat(local_30c,param_2,(size_t)(pcVar2 + (-4 - (int)(param_2 + 1))));

  puVar10 = (uint32_t /* width from decompiler */ *)(local_310 + 3);

  do {

    puVar11 = puVar10;

    puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);

  } while (*(char *)((int)puVar11 + 1) != '\0');

  *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_00a2c53c;

  *(uint8_t *)((int)puVar11 + 5) = DAT_00a2c540;

  iVar6 = FUN_007b6a20();

  if ((*(byte *)(iVar6 + 4) & 1) == 0) {

LAB_00850927:

    cVar1 = FUN_007b66c0(iVar6);

    if (cVar1 == '\0') {

      local_30c[0] = s_sec_unknown_dds_00a3970c[0];

      local_30c[1] = s_sec_unknown_dds_00a3970c[1];

      uStack_30a._0_1_ = s_sec_unknown_dds_00a3970c[2];

      uStack_30a._1_1_ = s_sec_unknown_dds_00a3970c[3];

      local_304[0] = s_sec_unknown_dds_00a3970c[8];

      local_304[1] = s_sec_unknown_dds_00a3970c[9];

      local_304[2] = s_sec_unknown_dds_00a3970c[10];

      local_304[3] = s_sec_unknown_dds_00a3970c[0xb];

      local_300[0] = s_sec_unknown_dds_00a3970c[0xc];

      local_300[1] = s_sec_unknown_dds_00a3970c[0xd];

      local_300[2] = s_sec_unknown_dds_00a3970c[0xe];

      local_300[3] = s_sec_unknown_dds_00a3970c[0xf];

      uStack_30a._2_1_ = s_sec_unknown_dds_00a3970c[4];

      uStack_30a._3_1_ = s_sec_unknown_dds_00a3970c[5];

      cStack_306 = s_sec_unknown_dds_00a3970c[6];

      cStack_305 = s_sec_unknown_dds_00a3970c[7];

      (**(code **)(*param_3 + 0x50))(local_30c,1,0);

      param_3 = piStack_8;

      goto LAB_00850991;

    }

  }

  else {

    BVar3 = PathFileExistsA(local_30c);

    if (BVar3 == 0) {

      local_310 = (uint8_t  [4])FUN_007b6420();

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

          auVar4 = local_310;

        } while (cVar1 != '\0');

        do {

          cVar1 = *(char *)auVar4;

          auVar4 = (uint8_t  [4])((int)auVar4 + 1);

        } while (cVar1 != '\0');

        uVar5 = (int)auVar4 - (int)local_310;

        pcVar7 = &cStack_105;

        do {

          pcVar9 = pcVar7 + 1;

          pcVar7 = pcVar7 + 1;

        } while (*pcVar9 != '\0');

        auVar4 = local_310;

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

        if (BVar3 != 0) goto LAB_00850935;

        pcVar2 = pcVar2 + 0x1c;

      } while ((int)pcVar2 < 0xd1e7a4);

      goto LAB_00850927;

    }

  }

LAB_00850935:

  (**(code **)(*param_3 + 0x50))(local_30c,1,0);

LAB_00850991:

  if (iStack_4 == 0) {

    FUN_00850490();

    return;

  }

  param_3[0x167] = iStack_4;

  return;

}
