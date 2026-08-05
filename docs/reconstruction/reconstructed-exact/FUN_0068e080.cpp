// =============================================================================
// FUN_0068e080
// -----------------------------------------------------------------------------
// Stable ID: aa_0068e080
// Address:   0x0068e080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068e080 @ 0x0068e080
// Stable ID: aa_0068e080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: return×16, if×15.
//  - Notable callees: FUN_0068cfe0×2, FUN_0068daa0, FUN_0068e080.
//  - Return sites: 16.

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

void __fastcall FUN_0068e080(int param_1)



{

  operator_delete__(*(void **)(param_1 + 0xc));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  FUN_0068daa0();

  if (*(void **)(param_1 + 0x104) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x104));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = 0;

  if (*(void **)(param_1 + 0xf4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0xf4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = 0;

  if (*(void **)(param_1 + 0xe4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0xe4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xec) = 0;

  if (*(void **)(param_1 + 0xd4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0xd4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = 0;

  if (*(void **)(param_1 + 0xc4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0xc4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 200) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc) = 0;

  if (*(void **)(param_1 + 0xb4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0xb4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0;

  if (*(void **)(param_1 + 0xa4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0xa4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = 0;

  if (*(void **)(param_1 + 0x94) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x94));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

  if (*(void **)(param_1 + 0x84) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x84));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = 0;

  if (*(void **)(param_1 + 0x74) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x74));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

  if (*(void **)(param_1 + 100) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 100));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  if (*(void **)(param_1 + 0x54) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x54));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  if (*(int *)(param_1 + 0x44) != 0) {

    FUN_0068cfe0(*(int *)(param_1 + 0x44),*(uint32_t /* width from decompiler */ *)(param_1 + 0x48),param_1 + 0x40,param_1);

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x44));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  if (*(int *)(param_1 + 0x34) != 0) {

    FUN_0068cfe0(*(int *)(param_1 + 0x34),*(uint32_t /* width from decompiler */ *)(param_1 + 0x38),param_1 + 0x30,param_1);

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x34));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  if (*(void **)(param_1 + 0x24) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x24));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  return;

}
