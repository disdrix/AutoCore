// =============================================================================
// FUN_00862e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00862e90
// Address:   0x00862e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00862e90 @ 0x00862e90
// Stable ID: aa_00862e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~139 non-empty decompiler lines.
//  - Control keywords: if×12, return×1.
//  - Notable callees: CONCAT12×5, CONCAT13×4, CONCAT11×3, FUN_00758460×3, CONCAT21×2, CONCAT31×2, CONCAT22, FUN_006a3db0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_00862e90(int *param_1)



{

  byte *pbVar1;

  uint uVar2;

  byte bVar3;

  char cVar4;

  uint8_t uVar5;

  int iVar6;

  int *piVar7;

  uint *puVar8;

  int iVar9;

  int iVar10;

  byte bVar11;

  int iVar12;

  uint32_t /* width from decompiler */ unaff_ESI;

  int iVar13;

  uint unaff_EDI;

  float fVar14;

  float fVar15;

  undefined *puVar16;

  uint uVar17;

  uint32_t /* width from decompiler */ local_18;

  uint8_t local_14;

  uint8_t local_10 [8];

  uint8_t local_8 [8];

  

  uVar17 = param_1[0x8a];

  pbVar1 = (byte *)param_1[0x89];

  local_14 = param_1[0x148] == 1;

  local_18._2_1_ = (byte)(uVar17 >> 0x10);

  local_18._3_1_ = (byte)(uVar17 >> 0x18);

  bVar3 = local_18._3_1_;

  local_18._0_2_ = (uint16_t)uVar17;

  if (param_1[0xa5] == 0) {

    bVar11 = local_18._2_1_;

    if (pbVar1 != (byte *)0x0) {

      bVar11 = (byte)(((uint)pbVar1[2] * (uVar17 >> 0x10 & 0xff)) / 0xff);

      local_18._0_3_ = CONCAT12(bVar11,(uint16_t)local_18);

      uVar2 = (uint)(uint3)local_18;

      uVar17 = (uint)(uint3)local_18;

      local_18 = CONCAT31(CONCAT21(local_18._2_2_,

                                   (char)(((uint)pbVar1[1] * ((uVar2 & 0xff00) >> 8)) / 0xff)),

                          (char)(((uVar17 & 0xff) * (uint)*pbVar1) / 0xff));

      local_18 = CONCAT13((char)(((uint)pbVar1[3] * (uint)bVar3) / 0xff),(uint3)local_18);

      uVar17 = local_18;

    }

    local_18 = uVar17;

    if ((bool)local_14) {

      local_18._0_3_ = CONCAT12(bVar11 >> 1,CONCAT11(local_18._1_1_ >> 1,(byte)local_18 >> 1));

    }

    iVar6 = (**(code **)(*param_1 + 0x140))(local_8,1);

    iVar10 = *(int *)(iVar6 + 4);

    piVar7 = (int *)(**(code **)(*param_1 + 0x140))(&local_18,1);

    iVar9 = *piVar7;

    iVar6 = 0;

    puVar16 = &DAT_00d1ec78;

    fVar14 = 0.0;

    fVar15 = 0.0;

  }

  else {

    bVar11 = local_18._2_1_;

    if (pbVar1 != (byte *)0x0) {

      bVar11 = (byte)(((uint)pbVar1[2] * (uVar17 >> 0x10 & 0xff)) / 0xff);

      local_18._0_3_ = CONCAT12(bVar11,(uint16_t)local_18);

      uVar2 = (uint)(uint3)local_18;

      uVar17 = (uint)(uint3)local_18;

      local_18 = CONCAT31(CONCAT21(local_18._2_2_,

                                   (char)(((uint)pbVar1[1] * ((uVar2 & 0xff00) >> 8)) / 0xff)),

                          (char)(((uint)*pbVar1 * (uVar17 & 0xff)) / 0xff));

      local_18 = CONCAT13((char)(((uint)pbVar1[3] * (uint)bVar3) / 0xff),(uint3)local_18);

      uVar17 = local_18;

    }

    local_18 = uVar17;

    if ((bool)local_14) {

      local_18._0_3_ = CONCAT12(bVar11 >> 1,CONCAT11(local_18._1_1_ >> 1,(byte)local_18 >> 1));

    }

    iVar6 = (**(code **)(*param_1 + 0x140))(local_10,1);

    iVar6 = *(int *)(iVar6 + 4);

    piVar7 = (int *)(**(code **)(*param_1 + 0x140))(local_10,1);

    FUN_00758460(0,0,(float)*piVar7,(float)iVar6,&DAT_00d1ec78,0,unaff_EDI,1,0,0,&DAT_00d1ecac);

    param_1[0x1a] = param_1[0x1a] + 1;

    iVar6 = param_1[0x1a];

    param_1[0x1d] = (int)(float)-iVar6;

    if (param_1[0x1c] < iVar6) {

      param_1[0x1c] = iVar6;

    }

    if ((param_1[0x144] != 0) && (*(char *)((int)param_1 + 0x492) != '\0')) {

      iVar6 = (**(code **)(*param_1 + 0x140))(&local_18,1);

      iVar6 = *(int *)(iVar6 + 4);

      piVar7 = (int *)(**(code **)(*param_1 + 0x140))(&stack0xffffffd8,1);

      FUN_00758460(0,0,(float)*piVar7,(float)iVar6,param_1[0x144],0,param_1[0x8c],1,0,0,

                   &DAT_00d1ecac);

      param_1[0x1a] = param_1[0x1a] + 1;

      iVar6 = param_1[0x1a];

      param_1[0x1d] = (int)(float)-iVar6;

      if (param_1[0x1c] < iVar6) {

        param_1[0x1c] = iVar6;

      }

    }

    iVar13 = ((int)((float)DAT_00d1e818 * (float)_DAT_00d1e50c * DAT_00aaa67c) * param_1[0x145] -

             param_1[0x12a]) / 2;

    puVar8 = (uint *)param_1[0x89];

    iVar12 = ((int)((float)DAT_00d1e81c * (float)_DAT_00d1e510 * DAT_00aaa678) * param_1[0x146] -

             param_1[299]) / 2;

    if (puVar8 == (uint *)0x0) {

      puVar8 = &DAT_00afdf0c;

    }

    unaff_EDI = *puVar8;

    if ((char)unaff_ESI == '\x01') {

      uVar17 = CONCAT13((char)(unaff_EDI >> 0x18),

                        CONCAT12((char)(unaff_EDI >> 0x11),(short)unaff_EDI)) & 0xff7fffff;

      unaff_EDI = CONCAT22((short)(uVar17 >> 0x10),CONCAT11((char)(uVar17 >> 9),(byte)uVar17 >> 1))

                  & 0xffff7fff;

    }

    cVar4 = (**(code **)(*param_1 + 0xf8))();

    if (cVar4 != '\0') {

      uVar5 = FUN_006a3db0();

      unaff_EDI = CONCAT13(uVar5,(int3)unaff_EDI);

    }

    iVar6 = param_1[0x86];

    puVar16 = (undefined *)param_1[0xa5];

    iVar9 = param_1[0x5e] + iVar13;

    iVar10 = param_1[0x5f] + iVar12;

    fVar14 = (float)iVar12;

    fVar15 = (float)iVar13;

  }

  FUN_00758460(fVar15,fVar14,(float)iVar9,(float)iVar10,puVar16,iVar6,unaff_EDI,1,0,0,&DAT_00d1ecac)

  ;

  param_1[0x1a] = param_1[0x1a] + 1;

  iVar6 = param_1[0x1a];

  param_1[0x1d] = (int)(float)-iVar6;

  if (param_1[0x1c] < iVar6) {

    param_1[0x1c] = iVar6;

  }

  FUN_0085df40(param_1,unaff_ESI);

  (**(code **)(*param_1 + 0x3ac))(unaff_ESI);

  FUN_0085de00(param_1);

  return;

}
