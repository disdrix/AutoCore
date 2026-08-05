// =============================================================================
// FUN_007b3340
// -----------------------------------------------------------------------------
// Stable ID: aa_007b3340
// Address:   0x007b3340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b3340 @ 0x007b3340
// Stable ID: aa_007b3340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CONCAT12, CONCAT13, CONCAT21, CONCAT31, FUN_00758460, FUN_007b3340.
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

void __fastcall FUN_007b3340(int *param_1)



{

  byte *pbVar1;

  byte bVar2;

  int *piVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  uint uVar8;

  int iVar9;

  uint uVar10;

  uint32_t /* width from decompiler */ uVar11;

  int *piVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint32_t /* width from decompiler */ *puVar14;

  uint32_t /* width from decompiler */ local_10;

  

  if (*(char *)((int)param_1 + 0x22b) != '\0') {

    if ((char)param_1[0xb2] == '\x01') {

      (**(code **)(*param_1 + 0x18c))();

    }

    else {

      uVar8 = param_1[0x8a];

      pbVar1 = (byte *)param_1[0x89];

      local_10 = uVar8;

      if (pbVar1 != (byte *)0x0) {

        local_10._3_1_ = (byte)(uVar8 >> 0x18);

        bVar2 = local_10._3_1_;

        local_10._0_3_ =

             CONCAT12((char)(((uint)pbVar1[2] * (uVar8 >> 0x10 & 0xff)) / 0xff),(short)uVar8);

        uVar10 = (uint)(uint3)local_10;

        uVar8 = (uint)(uint3)local_10;

        local_10 = CONCAT31(CONCAT21(local_10._2_2_,

                                     (char)(((uint)pbVar1[1] * ((uVar10 & 0xff00) >> 8)) / 0xff)),

                            (char)(((uint)*pbVar1 * (uVar8 & 0xff)) / 0xff));

        local_10 = CONCAT13((char)(((uint)pbVar1[3] * (uint)bVar2) / 0xff),(uint3)local_10);

      }

      uVar8 = local_10;

      if (param_1[0xa5] == 0) {

        puVar14 = (uint32_t /* width from decompiler */ *)0x1;

        puVar13 = &local_10;

        piVar3 = (int *)(**(code **)(*param_1 + 0x140))(puVar13,1);

        piVar12 = &DAT_00d1ecac;

        uVar11 = 0;

        uVar10 = 0;

        iVar9 = 1;

        iVar4 = (**(code **)(*param_1 + 0x140))

                          (&local_10,1,&DAT_00d1ec78,0,uVar8,1,0,0,&DAT_00d1ecac);

        fVar5 = (float)*(int *)(iVar4 + 4) + (float)param_1[0x9c] + (float)param_1[0x9a];

        iVar7 = param_1[0x9a];

        iVar4 = param_1[0x99];

        fVar6 = (float)*piVar3 + (float)param_1[0x9b] + (float)param_1[0x99];

      }

      else {

        iVar9 = param_1[0x86];

        fVar5 = (float)param_1[0x5f] + (float)param_1[0x9c] + (float)param_1[0x9a];

        puVar14 = &DAT_00d1ecac;

        puVar13 = (uint32_t /* width from decompiler */ *)0x0;

        if (*(char *)((int)param_1 + 0xd7) == '\0') {

          piVar12 = (int *)0x0;

        }

        else {

          piVar12 = param_1 + 0x60;

        }

        iVar4 = param_1[0x99];

        uVar11 = 1;

        iVar7 = param_1[0x9a];

        fVar6 = (float)param_1[0x5e] + (float)param_1[0x9b] + (float)param_1[0x99];

        uVar8 = param_1[0xa5];

        uVar10 = local_10;

      }

      FUN_00758460(iVar4,iVar7,fVar6,fVar5,uVar8,iVar9,uVar10,uVar11,piVar12,puVar13,puVar14);

    }

    if (((char)param_1[0x77] != '\0') && (0 < param_1[0x78])) {

      (**(code **)(*param_1 + 0x198))();

    }

  }

  return;

}
