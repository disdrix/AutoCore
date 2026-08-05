// =============================================================================
// FUN_006e3bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e3bf0
// Address:   0x006e3bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e3bf0 @ 0x006e3bf0
// Stable ID: aa_006e3bf0
// Embedded strings (evidence for future rename):
//   - "TtSphereSphere"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: rdtsc×2, FUN_006e3bf0.
//  - Strings: "TtSphereSphere".
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

void FUN_006e3bf0(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  uint64_t uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereSphere";

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar1 = param_2[2];

  iVar2 = param_1[2];

  fVar4 = *(float *)(iVar1 + 0x50) - *(float *)(iVar2 + 0x50);

  fVar7 = *(float *)(iVar1 + 0x54) - *(float *)(iVar2 + 0x54);

  fVar6 = *(float *)(iVar1 + 0x58) - *(float *)(iVar2 + 0x58);

  fVar5 = *(float *)(*param_1 + 0xc) + *(float *)(*param_2 + 0xc);

  if (fVar4 * fVar4 + fVar7 * fVar7 + fVar6 * fVar6 < fVar5 * fVar5) {

    (**(code **)(*param_4 + 4))(param_1,param_2);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
