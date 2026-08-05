// =============================================================================
// FUN_008174b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008174b0
// Address:   0x008174b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008174b0 @ 0x008174b0
// Stable ID: aa_008174b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_00817420, FUN_008174b0.
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

uint32_t /* width from decompiler */ __thiscall FUN_008174b0(int *param_1,int param_2,int param_3)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if ((param_3 == 40000) && (param_2 == 8)) {

    FUN_00817420();

    if (param_1[0xac] != 0) {

      iVar1 = *(int *)param_1[0xac];

      uVar3 = (**(code **)(*param_1 + 0x78))();

      uVar3 = (**(code **)(iVar1 + 0x338))(8,uVar3);

      return uVar3;

    }

    return 1;

  }

  cVar2 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar2 != '\0') && (param_1[0xac] != 0)) {

    uVar3 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar3;

  }

  return 0;

}
