// =============================================================================
// FUN_006e24c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e24c0
// Address:   0x006e24c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e24c0 @ 0x006e24c0
// Stable ID: aa_006e24c0
// Embedded strings (evidence for future rename):
//   - "TtSphereTriangle"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: rdtsc×2, FUN_006e24c0, FUN_006f7820.
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

void __thiscall FUN_006e24c0(int param_1,int *param_2,int *param_3,uint32_t /* width from decompiler */ param_4,int *param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint64_t uVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float local_40;

  float local_3c;

  float local_38;

  uint8_t local_30 [16];

  float local_20;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereTriangle";

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar1 = *param_2;

  iVar2 = param_3[2];

  iVar3 = param_2[2];

  fVar6 = *(float *)(iVar3 + 0x50) - *(float *)(iVar2 + 0x50);

  iVar4 = *param_3;

  fVar8 = *(float *)(iVar3 + 0x54) - *(float *)(iVar2 + 0x54);

  fVar7 = *(float *)(iVar3 + 0x58) - *(float *)(iVar2 + 0x58);

  local_40 = fVar6 * *(float *)(iVar2 + 0x20) +

             fVar8 * *(float *)(iVar2 + 0x24) + fVar7 * *(float *)(iVar2 + 0x28);

  local_3c = fVar6 * *(float *)(iVar2 + 0x30) +

             fVar8 * *(float *)(iVar2 + 0x34) + fVar7 * *(float *)(iVar2 + 0x38);

  local_38 = fVar6 * *(float *)(iVar2 + 0x40) +

             fVar8 * *(float *)(iVar2 + 0x44) + fVar7 * *(float *)(iVar2 + 0x48);

  FUN_006f7820(&local_40,iVar4 + 0x10,param_1 + 0x10,local_30);

  if (local_20 < *(float *)(iVar4 + 0xc) + *(float *)(iVar1 + 0xc)) {

    (**(code **)(*param_5 + 4))(param_2,param_3);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
