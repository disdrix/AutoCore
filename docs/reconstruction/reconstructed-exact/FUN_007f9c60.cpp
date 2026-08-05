// =============================================================================
// FUN_007f9c60
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9c60
// Address:   0x007f9c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007f9c60 @ 0x007f9c60
// Stable ID: aa_007f9c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_0096efd0×2, FUN_007f9c60.
//  - Return sites: 3.

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

void FUN_007f9c60(void)



{

  void *pvVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x514);

  iVar2 = 8;

  while( true ) {

    pvVar1 = (void *)puVar3[-8];

    if (pvVar1 != (void *)0x0) {

      FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    pvVar1 = (void *)*puVar3;

    if (pvVar1 != (void *)0x0) break;

    puVar3 = puVar3 + 1;

    iVar2 = iVar2 + -1;

    if (iVar2 == 0) {

      return;

    }

  }

  FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
