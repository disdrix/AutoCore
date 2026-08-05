// =============================================================================
// FUN_008cf7f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008cf7f0
// Address:   0x008cf7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cf7f0 @ 0x008cf7f0
// Stable ID: aa_008cf7f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: do×1, if×1, while×1, return×1.
//  - Notable callees: FUN_008cf7f0.
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

void FUN_008cf7f0(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  

  puVar2 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x794);

  iVar3 = 3;

  do {

    cVar1 = (**(code **)(*(int *)*puVar2 + 0xd8))();

    if (cVar1 != (char)param_1) {

      (**(code **)(*(int *)*puVar2 + 0xd4))(param_1);

      (**(code **)(*(int *)*puVar2 + 0x34c))();

    }

    puVar2 = puVar2 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}
