// =============================================================================
// FUN_0045e100
// -----------------------------------------------------------------------------
// Stable ID: aa_0045e100
// Address:   0x0045e100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0045e100 @ 0x0045e100
// Stable ID: aa_0045e100
// Embedded strings (evidence for future rename):
//   - "..\\palantir/animation/anmTrack_inl.h"
//   - "anmTrack::GetStateAtAnimTime called on object with invalid master pointer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: return×4, if×3, for×1.
//  - Notable callees: FUN_0045e100, FUN_0072f700, vog_LogMessage.
//  - Strings: "..\\palantir/animation/anmTrack_inl.h".
//  - Return sites: 4.

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

void __thiscall FUN_0045e100(int param_1,float param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  iVar1 = *(int *)(param_1 + 0xc);

  if (iVar1 == 0) {

    vog_LogMessage("..\\palantir/animation/anmTrack_inl.h",0x5b,2,

                   "anmTrack::GetStateAtAnimTime called on object with invalid master pointer");

    return;

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x20);

  if (param_2 <= (float)puVar2[7]) {

    *param_3 = *puVar2;

    param_3[1] = puVar2[1];

    param_3[2] = puVar2[2];

    param_3[3] = puVar2[3];

    param_3[4] = puVar2[4];

    param_3[5] = puVar2[5];

    param_3[6] = puVar2[6];

    return;

  }

  for (; (puVar2 != *(uint32_t /* width from decompiler */ **)(iVar1 + 0x24) && ((float)puVar2[7] <= param_2));

      puVar2 = puVar2 + 8) {

  }

  if ((*(char *)(*(int *)(param_1 + 4) + 0x55) == '\0') &&

     (puVar2 != *(uint32_t /* width from decompiler */ **)(iVar1 + 0x24))) {

    FUN_0072f700((param_2 - (float)puVar2[-1]) / ((float)puVar2[7] - (float)puVar2[-1]));

    return;

  }

  *param_3 = puVar2[-8];

  param_3[1] = puVar2[-7];

  param_3[2] = puVar2[-6];

  param_3[3] = puVar2[-5];

  param_3[4] = puVar2[-4];

  param_3[5] = puVar2[-3];

  param_3[6] = puVar2[-2];

  return;

}
