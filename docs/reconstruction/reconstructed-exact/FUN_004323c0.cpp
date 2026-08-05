// =============================================================================
// FUN_004323c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004323c0
// Address:   0x004323c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004323c0 @ 0x004323c0
// Stable ID: aa_004323c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_004323c0.
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

void __fastcall FUN_004323c0(int param_1)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (*(int *)(in_EAX + 4) == 0) {

    puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x30);

    puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x30);

    for (iVar1 = 0x5f; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar3 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar3 = puVar3 + 1;

    }

  }

  return;

}
