// =============================================================================
// FUN_00580c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00580c00
// Address:   0x00580c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00580c00 @ 0x00580c00
// Stable ID: aa_00580c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: ABS×6, FUN_00580c00, FUN_005f5690, FUN_00634450.
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

void __thiscall FUN_00580c00(int param_1,int param_2)



{

  FUN_005f5690(param_2);

  if (((DAT_00aaa664 < ABS(*(float *)(param_1 + 0x68) - *(float *)(param_2 + 0x28)) ||

       DAT_00aaa664 < ABS(*(float *)(param_1 + 100) - *(float *)(param_2 + 0x24))) ||

       DAT_00aaa664 < ABS(*(float *)(param_1 + 0x60) - *(float *)(param_2 + 0x20))) ||

     ((DAT_00aaa664 < ABS(*(float *)(param_1 + 0x78) - *(float *)(param_2 + 0x38)) ||

      DAT_00aaa664 < ABS(*(float *)(param_1 + 0x74) - *(float *)(param_2 + 0x34))) ||

      DAT_00aaa664 < ABS(*(float *)(param_1 + 0x70) - *(float *)(param_2 + 0x30)))) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 100) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x30);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x34);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x38);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c);

    FUN_00634450((uint32_t /* width from decompiler */ *)(param_1 + 0x60));

  }

  return;

}
