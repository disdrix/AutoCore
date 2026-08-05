// =============================================================================
// FUN_008a0690
// -----------------------------------------------------------------------------
// Stable ID: aa_008a0690
// Address:   0x008a0690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a0690 @ 0x008a0690
// Stable ID: aa_008a0690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00797d70, FUN_008a0690.
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

void FUN_008a0690(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  int *unaff_ESI;

  

  if (unaff_ESI != (int *)0x0) {

    (**(code **)(*unaff_ESI + 0x34c))();

    (**(code **)(*unaff_ESI + 0xd4))(param_1);

    if (unaff_ESI[0x151] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x151] + 0x15c))(0,&stack0x00000000);

    }

    if (unaff_ESI[0x152] != 0) {

      (**(code **)(*(int *)unaff_ESI[0x152] + 0x164))(1);

      (**(code **)(*(int *)unaff_ESI[0x152] + 0x15c))(1,&stack0xfffffffc);

      pvVar1 = *(void **)(unaff_ESI[0x152] + 0x28c);

      if (pvVar1 != (void *)0x0) {

        FUN_00797d70(pvVar1);

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(unaff_ESI[0x152] + 0x28c) = 0;

    }

  }

  return;

}
