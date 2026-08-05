// =============================================================================
// FUN_006ebcb0
// -----------------------------------------------------------------------------
// Stable ID: aa_006ebcb0
// Address:   0x006ebcb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ebcb0 @ 0x006ebcb0
// Stable ID: aa_006ebcb0
// Embedded strings (evidence for future rename):
//   - "LtBvTree"
//   - "StNarrowPhase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_00404cf0×4, FUN_00404d00×3, rdtsc×3, FUN_00428050, FUN_006e7740, FUN_006ea6f0, FUN_006ebcb0.
//  - Strings: "LtBvTree"; "StNarrowPhase".
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

void FUN_006ebcb0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint64_t uVar1;

  char cVar2;

  uint8_t local_159;

  uint32_t /* width from decompiler */ local_158;

  uint32_t /* width from decompiler */ local_154;

  uint8_t local_150 [256];

  int *local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ *local_3c;

  uint32_t /* width from decompiler */ *local_38;

  int *local_34;

  uint32_t /* width from decompiler */ *local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ *local_28;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ *local_1c;

  int local_14;

  

  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);

  cVar2 = FUN_00404cf0();

  if (cVar2 != '\0') {

    local_1c = DAT_00bc5644;

    *DAT_00bc5644 = "LtBvTree";

    uVar1 = rdtsc();

    local_20 = (uint32_t /* width from decompiler */)uVar1;

    DAT_00bc5644[1] = local_20;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  FUN_006ea6f0(param_1,param_2,param_3,&LAB_006ea160);

  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);

  cVar2 = FUN_00404cf0();

  if (cVar2 != '\0') {

    local_28 = DAT_00bc5644;

    *DAT_00bc5644 = "StNarrowPhase";

    uVar1 = rdtsc();

    local_2c = (uint32_t /* width from decompiler */)uVar1;

    DAT_00bc5644[1] = local_2c;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_30 = *(uint32_t /* width from decompiler */ **)(local_14 + 0xc);

  local_34 = (int *)(local_14 + 0xc);

  local_38 = (uint32_t /* width from decompiler */ *)(*(int *)(local_14 + 0x10) * 0xc + *local_34);

  local_3c = param_2;

  local_40 = param_2[2];

  local_4c = *param_2;

  local_50 = (int *)FUN_00428050();

  for (; local_30 != local_38; local_30 = local_30 + 3) {

    local_154 = (**(code **)(*local_50 + 0x34))(*local_30,local_150);

    local_158 = *local_30;

    local_48 = local_154;

    local_44 = local_158;

    (**(code **)(*(int *)local_30[2] + 4))(param_1,&local_48,param_3,param_4);

    FUN_006e7740(&local_159);

    cVar2 = FUN_00404cf0();

    if (cVar2 != '\0') break;

  }

  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);

  cVar2 = FUN_00404cf0();

  if (cVar2 != '\0') {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
