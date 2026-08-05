// =============================================================================
// FUN_0079cbb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079cbb0
// Address:   0x0079cbb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079cbb0 @ 0x0079cbb0
// Stable ID: aa_0079cbb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_0079cbb0.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



int __thiscall FUN_0079cbb0(int *param_1,int *param_2,uint param_3)



{

  int iVar1;

  uint uVar2;

  uint8_t local_2710 [9996];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x79cbba;

  iVar1 = 0;

  for (; param_3 != 0; param_3 = param_3 - uVar2) {

    uVar2 = 10000;

    if (param_3 < 0x2711) {

      uVar2 = param_3;

    }

    (**(code **)(*param_2 + 4))(local_2710,uVar2);

    (**(code **)(*param_1 + 8))(&stack0xffffd8e8,uVar2);

    iVar1 = iVar1 + uVar2;

  }

  return iVar1;

}
