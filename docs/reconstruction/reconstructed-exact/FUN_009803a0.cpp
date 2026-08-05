// =============================================================================
// FUN_009803a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009803a0
// Address:   0x009803a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009803a0 @ 0x009803a0
// Stable ID: aa_009803a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_00980250, FUN_009803a0.
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

void FUN_009803a0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if ((DAT_00d1b6d8 != 0) && (in_EAX != (uint32_t /* width from decompiler */ *)0x0)) {

    puVar1 = operator_new__(0xc0);

    puVar1[1] = param_2;

    *puVar1 = 0xd;

    puVar3 = puVar1 + 2;

    for (iVar2 = 0x2e; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = *in_EAX;

      in_EAX = in_EAX + 1;

      puVar3 = puVar3 + 1;

    }

    FUN_00980250(puVar1,0);

    operator_delete__(puVar1);

  }

  return;

}
