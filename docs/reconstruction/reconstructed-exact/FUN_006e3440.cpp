// =============================================================================
// FUN_006e3440
// -----------------------------------------------------------------------------
// Stable ID: aa_006e3440
// Address:   0x006e3440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e3440 @ 0x006e3440
// Stable ID: aa_006e3440
// Embedded strings (evidence for future rename):
//   - "TtSphereCapsule"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: rdtsc×2, FUN_006e3440, FUN_006f71e0.
//  - Strings: "TtSphereCapsule".
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

void FUN_006e3440(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint64_t uVar8;

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereCapsule";

    uVar8 = rdtsc();

    DAT_00bc5644[1] = (int)uVar8;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar4 = *param_2;

  fVar1 = *(float *)(iVar4 + 0x10);

  fVar2 = *(float *)(iVar4 + 0x14);

  iVar5 = param_1[2];

  fVar3 = *(float *)(iVar4 + 0x18);

  iVar6 = param_2[2];

  iVar7 = *param_1;

  local_30 = fVar1 * *(float *)(iVar6 + 0x20) +

             fVar2 * *(float *)(iVar6 + 0x30) + fVar3 * *(float *)(iVar6 + 0x40) +

             *(float *)(iVar6 + 0x50);

  local_2c = fVar2 * *(float *)(iVar6 + 0x34) +

             fVar3 * *(float *)(iVar6 + 0x44) + fVar1 * *(float *)(iVar6 + 0x24) +

             *(float *)(iVar6 + 0x54);

  local_28 = fVar2 * *(float *)(iVar6 + 0x38) +

             fVar3 * *(float *)(iVar6 + 0x48) + fVar1 * *(float *)(iVar6 + 0x28) +

             *(float *)(iVar6 + 0x58);

  local_24 = 0;

  fVar1 = *(float *)(iVar4 + 0x20);

  fVar2 = *(float *)(iVar4 + 0x24);

  fVar3 = *(float *)(iVar4 + 0x28);

  local_20 = fVar1 * *(float *)(iVar6 + 0x20) +

             fVar2 * *(float *)(iVar6 + 0x30) + fVar3 * *(float *)(iVar6 + 0x40) +

             *(float *)(iVar6 + 0x50);

  local_1c = fVar2 * *(float *)(iVar6 + 0x34) +

             fVar3 * *(float *)(iVar6 + 0x44) + fVar1 * *(float *)(iVar6 + 0x24) +

             *(float *)(iVar6 + 0x54);

  local_18 = fVar2 * *(float *)(iVar6 + 0x38) +

             fVar3 * *(float *)(iVar6 + 0x48) + fVar1 * *(float *)(iVar6 + 0x28) +

             *(float *)(iVar6 + 0x58);

  local_14 = 0;

  FUN_006f71e0((float *)(iVar5 + 0x50),&local_30,&local_20,&local_40);

  local_40 = local_40 - *(float *)(iVar5 + 0x50);

  local_3c = local_3c - *(float *)(iVar5 + 0x54);

  local_38 = local_38 - *(float *)(iVar5 + 0x58);

  fVar1 = *(float *)(iVar4 + 0xc) + *(float *)(iVar7 + 0xc);

  if (local_40 * local_40 + local_3c * local_3c + local_38 * local_38 < fVar1 * fVar1) {

    (**(code **)(*param_4 + 4))(param_1,param_2);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar8 = rdtsc();

    DAT_00bc5644[1] = (int)uVar8;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
