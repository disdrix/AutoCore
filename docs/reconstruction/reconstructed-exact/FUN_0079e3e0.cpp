// =============================================================================
// FUN_0079e3e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079e3e0
// Address:   0x0079e3e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079e3e0 @ 0x0079e3e0
// Stable ID: aa_0079e3e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×15, return×2.
//  - Notable callees: FUN_0079e3e0, FUN_0096f510.
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

void FUN_0079e3e0(void)



{

  void *pvVar1;

  int unaff_ESI;

  

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x198) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x198))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x198) = 0;

  if (*(void **)(unaff_ESI + 0x194) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0x194));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x194) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x1c0) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x1c0))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c0) = 0;

  if (*(void **)(unaff_ESI + 0x1bc) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0x1bc));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1bc) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x1ac) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x1ac))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1ac) = 0;

  if (*(void **)(unaff_ESI + 0x1a8) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0x1a8));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1a8) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x184) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x184))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x184) = 0;

  if (*(void **)(unaff_ESI + 0x180) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0x180));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x180) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x170) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x170))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x170) = 0;

  if (*(void **)(unaff_ESI + 0x16c) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0x16c));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x16c) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x1d4) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x1d4))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1d4) = 0;

  if (*(void **)(unaff_ESI + 0x1d0) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0x1d0));

  }

  pvVar1 = *(void **)(unaff_ESI + 0x1e0);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1d0) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096f510();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1e0) = 0;

  if (*(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x1f0) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x1f0))(1);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1f0) = 0;

  if (*(void **)(unaff_ESI + 0x1ec) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0x1ec));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1ec) = 0;

  return;

}
