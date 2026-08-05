// =============================================================================
// FUN_00578ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00578ac0
// Address:   0x00578ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00578ac0 @ 0x00578ac0
// Stable ID: aa_00578ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_004b99c0, FUN_00578ac0.
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

void __fastcall FUN_00578ac0(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x6b0);

  if (puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x6b4)) {

    do {

      pvVar1 = (void *)*puVar2;

      if (pvVar1 != (void *)0x0) {

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      puVar2 = puVar2 + 1;

    } while (puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x6b4));

  }

  if (*(void **)(param_1 + 0x6b0) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6b0) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6b4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6b8) = 0;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x6b0));

}
