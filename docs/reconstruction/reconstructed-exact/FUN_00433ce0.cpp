// =============================================================================
// FUN_00433ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00433ce0
// Address:   0x00433ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00433ce0 @ 0x00433ce0
// Stable ID: aa_00433ce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00433ce0, FUN_009746a0.
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

void FUN_00433ce0(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0x3ff8;

  puVar1 = operator_new(0xc);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    pvVar2 = operator_new__(0x3ff8);

    puVar1[1] = pvVar2;

  }

  *(uint32_t /* width from decompiler */ **)(in_EAX + 8) = puVar1;

  *puVar1 = 0;

  *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 8) + 8) = 0;

  FUN_009746a0();

  return;

}
