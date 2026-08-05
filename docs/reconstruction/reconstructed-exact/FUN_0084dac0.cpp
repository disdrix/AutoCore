// =============================================================================
// FUN_0084dac0
// -----------------------------------------------------------------------------
// Stable ID: aa_0084dac0
// Address:   0x0084dac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084dac0 @ 0x0084dac0
// Stable ID: aa_0084dac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0084dac0.
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

void FUN_0084dac0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,char param_4)



{

  int iVar1;

  int *piVar2;

  int unaff_retaddr;

  uint8_t local_8 [4];

  int *piStack_4;

  

  piVar2 = (int *)(**(code **)(*param_1 + 0x140))(local_8,1);

  iVar1 = *piVar2;

  if (param_4 == '\0') {

    piVar2 = (int *)(**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&stack0x00000000,1);

    if (*piVar2 < iVar1 / 2 + unaff_retaddr) {

      (**(code **)(*(int *)*DAT_00d1b780 + 0x140))(&stack0x00000000,1);

    }

    if (DAT_00d1b25c / 2 < (int)param_1) {

      (**(code **)(*piStack_4 + 0x140))(&param_2,1);

    }

  }

  (**(code **)(*piStack_4 + 0x118))(&stack0xffffffe0);

  return;

}
