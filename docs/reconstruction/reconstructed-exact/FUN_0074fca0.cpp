// =============================================================================
// FUN_0074fca0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074fca0
// Address:   0x0074fca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074fca0 @ 0x0074fca0
// Stable ID: aa_0074fca0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp"
//   - "effDeviceEffect::Begin() called on an effect that is already active."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_0074f360, FUN_0074fca0, effDeviceEffect::Begin, vog_LogMessage.
//  - Strings: ",

                   0xce,1,".
//  - Return sites: 3.

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

int __thiscall FUN_0074fca0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = DAT_00d1f614;

  iVar2 = *(int *)(param_1 + 0x28);

  if (DAT_00d1f614 != 0) {

    piVar1 = (int *)(DAT_00d1f614 + 0xd0 + *(int *)(DAT_00d1f614 + 0xc4) * 0x4c);

    *piVar1 = *piVar1 + 1;

  }

  if ((&DAT_00afe010)[iVar2 * 3] == param_1) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp",

                   0xce,1,"effDeviceEffect::Begin() called on an effect that is already active.");

  }

  else {

    if ((&DAT_00afe010)[iVar2 * 3] != 0) {

      FUN_0074f360();

      iVar3 = DAT_00d1f614;

    }

    if (*(int *)(param_1 + 0xc) != 0) {

      (**(code **)(**(int **)(param_1 + 0xc) + 0xfc))(*(int **)(param_1 + 0xc),0,param_2);

      iVar3 = DAT_00d1f614;

    }

    (&DAT_00afe010)[iVar2 * 3] = param_1;

    if (iVar3 != 0) {

      piVar1 = (int *)(iVar3 + 0xcc + *(int *)(iVar3 + 0xc4) * 0x4c);

      *piVar1 = *piVar1 + 1;

    }

    iVar2 = *(int *)(param_1 + 0x20);

    if (iVar2 == 0) {

      return 1;

    }

    if (*(int *)(iVar2 + 200) != 0) {

      return (*(int *)(iVar2 + 0xcc) - *(int *)(iVar2 + 200)) / 0x24;

    }

  }

  return 0;

}
