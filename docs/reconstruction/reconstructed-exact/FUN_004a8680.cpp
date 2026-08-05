// =============================================================================
// FUN_004a8680
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8680
// Address:   0x004a8680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a8680 @ 0x004a8680
// Stable ID: aa_004a8680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_004a8680.
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

void __fastcall FUN_004a8680(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x3a8);

  iVar1 = 8;

  do {

    if ((void *)*puVar2 != (void *)0x0) {

      operator_delete__((void *)*puVar2);

    }

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  if (*(void **)(param_1 + 0x3e0) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x3e0));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3e0) = 0;

  if (*(void **)(param_1 + 0x3dc) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x3dc));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3dc) = 0;

  return;

}
