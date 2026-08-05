// =============================================================================
// FUN_00476670
// -----------------------------------------------------------------------------
// Stable ID: aa_00476670
// Address:   0x00476670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00476670 @ 0x00476670
// Stable ID: aa_00476670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×2.
//  - Notable callees: FUN_00476670, malloc.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00476670(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t local_26c [580];

  uint32_t /* width from decompiler */ local_28;

  

  if (param_1 == 0) {

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  if (*(code **)(param_1 + 0x248) == (code *)0x0) {

    puVar1 = malloc(0x120);

  }

  else {

    local_28 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x244);

    puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(param_1 + 0x248))(local_26c);

  }

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = puVar1;

    for (iVar2 = 0x48; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    puVar3 = puVar1;

    for (iVar2 = 0x48; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

  }

  return puVar1;

}
