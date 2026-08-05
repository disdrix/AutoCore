// =============================================================================
// FUN_0046e390
// -----------------------------------------------------------------------------
// Stable ID: aa_0046e390
// Address:   0x0046e390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046e390 @ 0x0046e390
// Stable ID: aa_0046e390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0046e390, FUN_0046e410, FUN_0046eb90.
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

uint32_t /* width from decompiler */ __fastcall FUN_0046e390(int param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_0046e410(param_1,in_EAX);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    if (param_2 != 0) {

      puVar1[2] = param_2;

    }

    FUN_0046eb90();

    if (param_1 != *(int *)(param_3 + 0x10)) {

      uVar2 = (**(code **)(param_1 + 0x10))(puVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

      (**(code **)*puVar1)(1);

      return uVar2;

    }

    (**(code **)*puVar1)(1);

  }

  return 0xffffffff;

}
