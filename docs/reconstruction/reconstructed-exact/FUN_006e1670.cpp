// =============================================================================
// FUN_006e1670
// -----------------------------------------------------------------------------
// Stable ID: aa_006e1670
// Address:   0x006e1670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e1670 @ 0x006e1670
// Stable ID: aa_006e1670
// Embedded strings (evidence for future rename):
//   - "TtSphereBox"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: ABS×3, rdtsc×2, FUN_005d69a0, FUN_006e1670.
//  - Strings: "TtSphereBox".
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

void FUN_006e1670(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint64_t uVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereBox";

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar1 = param_1[2];

  iVar2 = *param_1;

  iVar3 = *param_2;

  FUN_005d69a0(param_2[2] + 0x20,(float *)(iVar1 + 0x50));

  local_40 = ABS(local_30);

  local_3c = ABS(local_2c);

  local_38 = ABS(local_28);

  if (*(float *)(iVar3 + 0x10) <= local_40) {

    local_40 = *(float *)(iVar3 + 0x10);

  }

  if (*(float *)(iVar3 + 0x14) <= local_3c) {

    local_3c = *(float *)(iVar3 + 0x14);

  }

  if (*(float *)(iVar3 + 0x18) <= local_38) {

    local_38 = *(float *)(iVar3 + 0x18);

  }

  local_40 = (float)((uint)local_40 ^ (uint)local_30 & 0x80000000);

  local_3c = (float)((uint)local_3c ^ (uint)local_2c & 0x80000000);

  local_38 = (float)((uint)local_38 ^ (uint)local_28 & 0x80000000);

  iVar4 = param_2[2];

  fVar6 = (local_40 * *(float *)(iVar4 + 0x20) +

           local_3c * *(float *)(iVar4 + 0x30) + local_38 * *(float *)(iVar4 + 0x40) +

          *(float *)(iVar4 + 0x50)) - *(float *)(iVar1 + 0x50);

  fVar7 = (local_40 * *(float *)(iVar4 + 0x24) +

           local_3c * *(float *)(iVar4 + 0x34) + local_38 * *(float *)(iVar4 + 0x44) +

          *(float *)(iVar4 + 0x54)) - *(float *)(iVar1 + 0x54);

  fVar9 = (local_40 * *(float *)(iVar4 + 0x28) +

           local_3c * *(float *)(iVar4 + 0x38) + local_38 * *(float *)(iVar4 + 0x48) +

          *(float *)(iVar4 + 0x58)) - *(float *)(iVar1 + 0x58);

  fVar8 = *(float *)(iVar3 + 0xc) + *(float *)(iVar2 + 0xc);

  if (fVar6 * fVar6 + fVar7 * fVar7 + fVar9 * fVar9 < fVar8 * fVar8) {

    (**(code **)(*param_4 + 4))(param_1,param_2);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
