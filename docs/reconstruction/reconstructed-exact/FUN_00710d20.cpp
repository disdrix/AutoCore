// =============================================================================
// FUN_00710d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00710d20
// Address:   0x00710d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00710d20 @ 0x00710d20
// Stable ID: aa_00710d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×6, if×5.
//  - Notable callees: printf×2, FUN_00710d20, FUN_00710dd0, FUN_00711da0, FUN_00712280.
//  - Return sites: 6.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ FUN_00710d20(uint32_t /* width from decompiler */ *param_1)



{

  short sVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (param_1 == (uint32_t /* width from decompiler */ *)0x0) {

    return 0x181a;

  }

  *param_1 = 0;

  iVar2 = FUN_00711da0(0);

  if (iVar2 == 1) {

    printf(s_Evaluation_period_has_expired__E_00af8a08);

    return 0x1965;

  }

  if (iVar2 == -1) {

    printf(s_Clock_incorrectly_set__Please_ad_00af89b8);

    return 0x1965;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)(*(code *)PTR_calloc_00af8a48)(1,0x2c);

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    return 6000;

  }

  *param_1 = puVar3;

  *(uint8_t *)(puVar3 + 3) = 0xb;

  *puVar3 = 0xface;

  sVar1 = FUN_00712280(puVar3 + 4);

  if (sVar1 != 0) {

    FUN_00710dd0(param_1);

    return 6000;

  }

  _DAT_00d09848 = _DAT_00d09848 + 1;

  return 0;

}
