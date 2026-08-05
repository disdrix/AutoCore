// =============================================================================
// FUN_00860020
// -----------------------------------------------------------------------------
// Stable ID: aa_00860020
// Address:   0x00860020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00860020 @ 0x00860020
// Stable ID: aa_00860020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×1.
//  - Notable callees: FUN_00757970×12, CONCAT11×3, CONCAT13×3, CONCAT12×2, CONCAT21, CONCAT22, CONCAT31, FUN_007b3340.
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

void __fastcall FUN_00860020(int *param_1)



{

  byte *pbVar1;

  uint *puVar2;

  int iVar3;

  byte bVar4;

  uint uVar5;

  uint uVar6;

  uint3 uVar7;

  uint uVar9;

  uint32_t /* width from decompiler */ uStack_38;

  float fStack_34;

  uint32_t /* width from decompiler */ local_30;

  int iStack_28;

  float fStack_24;

  uint32_t /* width from decompiler */ uVar8;

  

  FUN_007b3340();

  if (((char)param_1[0x13f] != '\0') && (param_1[0x15b] != 0)) {

    param_1[0x1a] = param_1[0x1a] + 1;

    iVar3 = param_1[0x1a];

    param_1[0x1d] = (int)(float)-iVar3;

    if (param_1[0x1c] < iVar3) {

      param_1[0x1c] = iVar3;

    }

    puVar2 = (uint *)(**(code **)(*param_1 + 0x164))(1);

    pbVar1 = (byte *)param_1[0x89];

    uVar9 = *puVar2;

    bVar4 = (byte)(uVar9 >> 0x18);

    if (pbVar1 == (byte *)0x0) {

      uVar5 = uVar9 >> 0x10 & 0xff;

    }

    else {

      uVar5 = ((uint)pbVar1[2] * (uVar9 >> 0x10 & 0xff)) / 0xff;

      uVar7 = CONCAT12((char)uVar5,(short)uVar9);

      uVar8 = CONCAT13(bVar4,uVar7);

      bVar4 = (byte)(((uint)pbVar1[3] * (uint)bVar4) / 0xff);

      uVar9 = CONCAT13(bVar4,(int3)CONCAT31(CONCAT21((short)((uint)uVar8 >> 0x10),

                                                     (char)(((uint)pbVar1[1] *

                                                            ((uVar7 & 0xff00) >> 8)) / 0xff)),

                                            (char)(((uint)*pbVar1 * (uVar7 & 0xff)) / 0xff)));

    }

    uVar6 = uVar9 >> 8 & 0xff;

    local_30._0_2_ = CONCAT11((char)((uVar6 * 7) / 10),(char)(((uVar9 & 0xff) * 7) / 10));

    local_30 = CONCAT13(bVar4,CONCAT12((char)(((uVar5 & 0xff) * 7) / 10),(uint16_t)local_30));

    uStack_38 = CONCAT22(CONCAT11(bVar4,(char)(((uVar5 & 0xff) * 2) / 5)),

                         CONCAT11((char)((uVar6 * 2) / 5),(char)(((uVar9 & 0xff) * 2) / 5)));

    iStack_28 = 0;

    if (0 < (int)fStack_24) {

      do {

        iVar3 = 0;

        if (0 < (int)fStack_34) {

          do {

            iVar3 = iVar3 + 1;

            FUN_00757970(param_1,uVar9,&DAT_00d1ecac);

            FUN_00757970(param_1,uVar9,&DAT_00d1ecac);

            FUN_00757970(param_1,local_30,&DAT_00d1ecac);

            FUN_00757970(param_1,local_30,&DAT_00d1ecac);

            FUN_00757970(param_1,uStack_38,&DAT_00d1ecac);

            FUN_00757970(param_1,uStack_38,&DAT_00d1ecac);

          } while (iVar3 < (int)fStack_34);

        }

        iStack_28 = iStack_28 + 1;

      } while (iStack_28 < (int)fStack_24);

    }

    FUN_00757970(param_1,uVar9,&DAT_00d1ecac);

    FUN_00757970(param_1,uVar9,&DAT_00d1ecac);

    FUN_00757970(param_1,local_30,&DAT_00d1ecac);

    FUN_00757970(param_1,local_30,&DAT_00d1ecac);

    FUN_00757970(param_1,uStack_38,&DAT_00d1ecac);

    FUN_00757970(param_1,uStack_38,&DAT_00d1ecac);

  }

  return;

}
