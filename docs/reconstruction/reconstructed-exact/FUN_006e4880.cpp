// =============================================================================
// FUN_006e4880
// -----------------------------------------------------------------------------
// Stable ID: aa_006e4880
// Address:   0x006e4880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e4880 @ 0x006e4880
// Stable ID: aa_006e4880
// Embedded strings (evidence for future rename):
//   - "TtGsk"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: rdtsc×2, FUN_0063a3f0, FUN_006e4880, FUN_006fde40.
//  - Strings: "TtGsk".
//  - Return sites: 2.

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

void __thiscall FUN_006e4880(int param_1,int *param_2,int *param_3,uint32_t /* width from decompiler */ param_4,int *param_5)



{

  int iVar1;

  int iVar2;

  uint64_t uVar3;

  int iVar4;

  uint8_t local_1d0 [12];

  float local_1c4;

  uint8_t local_1c0 [76];

  uint8_t local_174;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtGsk";

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar1 = *param_3;

  iVar2 = *param_2;

  FUN_0063a3f0(param_2[2] + 0x20,param_3[2] + 0x20);

  local_174 = 1;

  iVar4 = FUN_006fde40(iVar2,iVar1,local_1c0,param_1 + 0xc,local_1d0);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  if (iVar4 == 0) {

    if ((local_1c4 - *(float *)(iVar2 + 0xc)) - *(float *)(iVar1 + 0xc) < g_flZero) {

      (**(code **)(*param_5 + 4))(param_2,param_3);

      return;

    }

  }

  else {

    (**(code **)(*param_5 + 4))(param_2,param_3);

  }

  return;

}
