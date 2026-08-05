// =============================================================================
// FUN_0084f140
// -----------------------------------------------------------------------------
// Stable ID: aa_0084f140
// Address:   0x0084f140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084f140 @ 0x0084f140
// Stable ID: aa_0084f140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0084f140, NDUIWindow_ReloadInterface.
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

void __thiscall FUN_0084f140(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t local_8 [8];

  

  NDUIWindow_ReloadInterface(param_2);

  if (param_1[0x144] != 0) {

    iVar1 = *(int *)param_1[0x144];

    uVar2 = (**(code **)(*param_1 + 0x140))(local_8,1);

    (**(code **)(iVar1 + 0x138))(uVar2);

  }

  (**(code **)(*param_1 + 0x34c))();

  return;

}
