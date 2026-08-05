// =============================================================================
// FUN_006e41c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e41c0
// Address:   0x006e41c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e41c0 @ 0x006e41c0
// Stable ID: aa_006e41c0
// Embedded strings (evidence for future rename):
//   - "TtBoxBox"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: rdtsc×2, FUN_006e4100, FUN_006e41c0, FUN_006fafb0.
//  - Strings: "TtBoxBox".
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

void __thiscall FUN_006e41c0(int param_1,int *param_2,int *param_3,int param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  int iVar2;

  uint64_t uVar3;

  float local_140;

  float local_13c;

  float local_138;

  float local_134;

  float local_130;

  float local_12c;

  float local_128;

  float local_124;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtBoxBox";

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar1 = *param_2;

  local_124 = *(float *)(iVar1 + 0xc);

  iVar2 = *param_3;

  local_130 = local_124 + *(float *)(iVar1 + 0x10);

  local_12c = local_124 + *(float *)(iVar1 + 0x14);

  local_128 = local_124 + *(float *)(iVar1 + 0x18);

  local_124 = local_124 + *(float *)(iVar1 + 0x1c);

  local_134 = *(float *)(iVar2 + 0xc);

  local_140 = local_134 + *(float *)(iVar2 + 0x10);

  local_13c = local_134 + *(float *)(iVar2 + 0x14);

  local_138 = local_134 + *(float *)(iVar2 + 0x18);

  local_134 = local_134 + *(float *)(iVar2 + 0x1c);

  FUN_006e4100(param_2,param_3,param_4,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_5,param_2[2] + 0x20,

               &local_130,param_3[2] + 0x20,&local_140,*(uint32_t /* width from decompiler */ *)(param_4 + 8));

  FUN_006fafb0(param_1 + 0x10);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
