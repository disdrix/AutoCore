// =============================================================================
// FUN_006e4400
// -----------------------------------------------------------------------------
// Stable ID: aa_006e4400
// Address:   0x006e4400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e4400 @ 0x006e4400
// Stable ID: aa_006e4400
// Embedded strings (evidence for future rename):
//   - "TtBoxBox"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: rdtsc×2, FUN_006e4100, FUN_006e4400, FUN_006fae60.
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

void FUN_006e4400(int *param_1,int *param_2,int param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  uint64_t uVar3;

  char local_178 [4];

  uint32_t /* width from decompiler */ local_174;

  float local_170;

  float local_16c;

  float local_168;

  float local_164;

  float local_160;

  float local_15c;

  float local_158;

  float local_154;

  uint8_t local_150 [32];

  int *local_130;

  int *local_12c;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtBoxBox";

    uVar3 = rdtsc();

    local_174 = (uint32_t /* width from decompiler */)uVar3;

    DAT_00bc5644[1] = local_174;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar1 = *param_1;

  local_154 = *(float *)(iVar1 + 0xc);

  iVar2 = *param_2;

  local_160 = local_154 + *(float *)(iVar1 + 0x10);

  local_15c = local_154 + *(float *)(iVar1 + 0x14);

  local_158 = local_154 + *(float *)(iVar1 + 0x18);

  local_154 = local_154 + *(float *)(iVar1 + 0x1c);

  local_164 = *(float *)(iVar2 + 0xc);

  local_170 = local_164 + *(float *)(iVar2 + 0x10);

  local_16c = local_164 + *(float *)(iVar2 + 0x14);

  local_168 = local_164 + *(float *)(iVar2 + 0x18);

  local_164 = local_164 + *(float *)(iVar2 + 0x1c);

  FUN_006e4100(param_1,param_2,0,0,0,param_1[2] + 0x20,&local_160,param_2[2] + 0x20,&local_170,

               *(uint32_t /* width from decompiler */ *)(param_3 + 8));

  local_130 = param_1;

  local_12c = param_2;

  FUN_006fae60(local_178,local_150);

  if (local_178[0] != '\0') {

    (**(code **)(*param_4 + 4))(local_150);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
