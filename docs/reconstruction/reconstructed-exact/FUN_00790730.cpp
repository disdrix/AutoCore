// =============================================================================
// FUN_00790730
// -----------------------------------------------------------------------------
// Stable ID: aa_00790730
// Address:   0x00790730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00790730 @ 0x00790730
// Stable ID: aa_00790730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00790730.
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

uint8_t __thiscall FUN_00790730(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint8_t uVar2;

  uint32_t /* width from decompiler */ unaff_EBX;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    (**(code **)(*param_1 + 0x3bc))(param_1[0x12e]);

    (**(code **)(*param_1 + 0x42c))

              (param_1[0x12e],(int)(short)param_3,(int)(short)((uint)param_3 >> 0x10));

    if (param_1[0x12e] != 0) {

      uVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x378))(unaff_EBX,param_3);

      return uVar2;

    }

  }

  return *(uint8_t *)((int)param_1 + 0x496);

}
