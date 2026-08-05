// =============================================================================
// FUN_006e25e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e25e0
// Address:   0x006e25e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e25e0 @ 0x006e25e0
// Stable ID: aa_006e25e0
// Embedded strings (evidence for future rename):
//   - "TtSphereTriangle"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: rdtsc×2, FUN_006e25e0, FUN_006f7340, FUN_006f7820.
//  - Strings: "TtSphereTriangle".
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

void FUN_006e25e0(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint64_t uVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float local_50;

  float local_4c;

  float local_48;

  uint8_t local_40 [16];

  uint8_t local_30 [16];

  float local_20;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereTriangle";

    uVar6 = rdtsc();

    DAT_00bc5644[1] = (int)uVar6;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar2 = *param_2;

  iVar3 = *param_1;

  iVar1 = iVar2 + 0x10;

  FUN_006f7340(iVar1,local_40);

  iVar4 = param_1[2];

  iVar5 = param_2[2];

  fVar7 = *(float *)(iVar4 + 0x50) - *(float *)(iVar5 + 0x50);

  fVar9 = *(float *)(iVar4 + 0x54) - *(float *)(iVar5 + 0x54);

  fVar8 = *(float *)(iVar4 + 0x58) - *(float *)(iVar5 + 0x58);

  local_50 = fVar7 * *(float *)(iVar5 + 0x20) +

             fVar9 * *(float *)(iVar5 + 0x24) + fVar8 * *(float *)(iVar5 + 0x28);

  local_4c = fVar7 * *(float *)(iVar5 + 0x30) +

             fVar9 * *(float *)(iVar5 + 0x34) + fVar8 * *(float *)(iVar5 + 0x38);

  local_48 = fVar7 * *(float *)(iVar5 + 0x40) +

             fVar9 * *(float *)(iVar5 + 0x44) + fVar8 * *(float *)(iVar5 + 0x48);

  FUN_006f7820(&local_50,iVar1,local_40,local_30);

  if (local_20 < *(float *)(iVar2 + 0xc) + *(float *)(iVar3 + 0xc)) {

    (**(code **)(*param_4 + 4))(param_1,param_2);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar6 = rdtsc();

    DAT_00bc5644[1] = (int)uVar6;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
