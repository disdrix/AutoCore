// =============================================================================
// FUN_006e4520
// -----------------------------------------------------------------------------
// Stable ID: aa_006e4520
// Address:   0x006e4520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e4520 @ 0x006e4520
// Stable ID: aa_006e4520
// Embedded strings (evidence for future rename):
//   - "TtBoxBox"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: rdtsc×2, FUN_006e4100, FUN_006e4520, FUN_006f8f00, FUN_006f91d0.
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

void FUN_006e4520(int *param_1,int *param_2,int param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  uint64_t uVar3;

  char local_145;

  uint32_t /* width from decompiler */ local_144;

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

    local_144 = (uint32_t /* width from decompiler */)uVar3;

    DAT_00bc5644[1] = local_144;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar1 = *param_1;

  local_124 = *(float *)(iVar1 + 0xc);

  iVar2 = *param_2;

  local_130 = local_124 + *(float *)(iVar1 + 0x10);

  local_12c = local_124 + *(float *)(iVar1 + 0x14);

  local_128 = local_124 + *(float *)(iVar1 + 0x18);

  local_124 = local_124 + *(float *)(iVar1 + 0x1c);

  local_134 = *(float *)(iVar2 + 0xc);

  local_140 = local_134 + *(float *)(iVar2 + 0x10);

  local_13c = local_134 + *(float *)(iVar2 + 0x14);

  local_138 = local_134 + *(float *)(iVar2 + 0x18);

  local_134 = local_134 + *(float *)(iVar2 + 0x1c);

  FUN_006e4100(param_1,param_2,0,0,0,param_1[2] + 0x20,&local_130,param_2[2] + 0x20,&local_140,

               *(uint32_t /* width from decompiler */ *)(param_3 + 8));

  FUN_006f8f00();

  FUN_006f91d0(&local_145);

  if (local_145 != '\0') {

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
