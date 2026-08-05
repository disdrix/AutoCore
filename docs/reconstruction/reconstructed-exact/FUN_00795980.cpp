// =============================================================================
// FUN_00795980
// -----------------------------------------------------------------------------
// Stable ID: aa_00795980
// Address:   0x00795980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00795980 @ 0x00795980
// Stable ID: aa_00795980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00758460×2, CONCAT12, CONCAT13, CONCAT21, CONCAT31, FUN_00795980.
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

void __fastcall FUN_00795980(int *param_1)



{

  uint uVar1;

  byte *pbVar2;

  uint uVar3;

  byte bVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ local_10;

  

  uVar1 = param_1[0x8a];

  local_10 = uVar1;

  if (param_1[0x89] != 0) {

    pbVar2 = (byte *)param_1[0x89];

    local_10._3_1_ = (byte)(uVar1 >> 0x18);

    bVar4 = local_10._3_1_;

    local_10._0_3_ =

         CONCAT12((char)(((uint)pbVar2[2] * (uVar1 >> 0x10 & 0xff)) / 0xff),(short)uVar1);

    uVar3 = (uint)(uint3)local_10;

    uVar1 = (uint)(uint3)local_10;

    local_10 = CONCAT31(CONCAT21(local_10._2_2_,

                                 (char)(((uint)pbVar2[1] * ((uVar3 & 0xff00) >> 8)) / 0xff)),

                        (char)(((uVar1 & 0xff) * (uint)*pbVar2) / 0xff));

    local_10 = CONCAT13((char)(((uint)pbVar2[3] * (uint)bVar4) / 0xff),(uint3)local_10);

  }

  uVar1 = local_10;

  if (param_1[0xa5] == 0) {

    iVar5 = (**(code **)(*param_1 + 0x140))(&local_10,1);

    iVar5 = *(int *)(iVar5 + 4);

    piVar6 = (int *)(**(code **)(*param_1 + 0x140))(&local_10,1);

    FUN_00758460(0,0,(float)*piVar6,(float)iVar5,&DAT_00d1ec78,0,uVar1,1,0,0,&DAT_00d1ecac);

  }

  else {

    FUN_00758460(0,0,(float)param_1[0x5e],(float)param_1[0x5f],param_1[0xa5],param_1[0x86],local_10,

                 1,0,0,&DAT_00d1ecac);

  }

  if (((char)param_1[0x77] != '\0') && (0 < param_1[0x78])) {

    (**(code **)(*param_1 + 0x198))();

  }

  return;

}
