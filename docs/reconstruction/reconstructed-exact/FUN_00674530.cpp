// =============================================================================
// FUN_00674530
// -----------------------------------------------------------------------------
// Stable ID: aa_00674530
// Address:   0x00674530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00674530 @ 0x00674530
// Stable ID: aa_00674530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31, FUN_00674530, FUN_00675fc0.
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

void __thiscall FUN_00674530(int param_1,uint8_t *param_2)



{

  uint8_t *puVar1;

  int local_4;

  

  puVar1 = param_2;

  local_4 = param_1;

  if (*(int *)(param_1 + 0x158) != 0) {

    param_2 = (uint8_t *)CONCAT31(param_2._1_3_,*param_2);

    FUN_00675fc0(&local_4,&param_2);

    if ((local_4 != *(int *)(param_1 + 0x164)) && (local_4 != -0x10)) {

      *(uint32_t /* width from decompiler */ *)(local_4 + 0x14) = *(uint32_t /* width from decompiler */ *)(puVar1 + 4);

      *(uint32_t /* width from decompiler */ *)(local_4 + 0x18) = *(uint32_t /* width from decompiler */ *)(puVar1 + 8);

      *(uint32_t /* width from decompiler */ *)(local_4 + 0x1c) = *(uint32_t /* width from decompiler */ *)(puVar1 + 0xc);

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar1);

}
