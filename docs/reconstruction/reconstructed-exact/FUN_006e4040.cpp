// =============================================================================
// FUN_006e4040
// -----------------------------------------------------------------------------
// Stable ID: aa_006e4040
// Address:   0x006e4040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e4040 @ 0x006e4040
// Stable ID: aa_006e4040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_006e4040.
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

void __fastcall FUN_006e4040(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  iVar2 = 0;

  if (0 < (int)param_1[0x19]) {

    puVar1 = param_1 + 0xd;

    do {

      (**(code **)(*(int *)param_1[2] + 8))(*(uint16_t *)puVar1);

      iVar2 = iVar2 + 1;

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 6);

    } while (iVar2 < (int)param_1[0x19]);

  }

  (**(code **)*param_1)(1);

  return;

}
