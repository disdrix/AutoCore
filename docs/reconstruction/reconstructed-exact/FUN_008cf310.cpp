// =============================================================================
// FUN_008cf310
// -----------------------------------------------------------------------------
// Stable ID: aa_008cf310
// Address:   0x008cf310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cf310 @ 0x008cf310
// Stable ID: aa_008cf310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_008cf310.
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

void FUN_008cf310(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x72c);

  iVar1 = 2;

  do {

    (**(code **)(*(int *)puVar2[-2] + 0xd4))(param_1);

    (**(code **)(*(int *)puVar2[-2] + 0x34c))();

    (**(code **)(*(int *)*puVar2 + 0xd4))(param_1);

    (**(code **)(*(int *)*puVar2 + 0x34c))();

    puVar2 = puVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}
