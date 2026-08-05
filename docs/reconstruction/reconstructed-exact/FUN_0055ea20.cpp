// =============================================================================
// FUN_0055ea20
// -----------------------------------------------------------------------------
// Stable ID: aa_0055ea20
// Address:   0x0055ea20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055ea20 @ 0x0055ea20
// Stable ID: aa_0055ea20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0055ea20, FUN_005b3370.
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

void __thiscall FUN_0055ea20(int param_1,uint8_t param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (*(char *)(param_1 + 0x23e) == '\0') {

    *(uint8_t *)(param_1 + 0x23e) = 1;

    *(uint8_t *)(param_1 + 0x23f) = param_2;

    puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))(0x14,4);

    *(uint16_t *)(puVar2 + 1) = 0x14;

    puVar1 = puVar2 + 2;

    *puVar1 = &PTR_LAB_009db440;

    *puVar2 = &PTR_LAB_009d27e8;

    *puVar1 = &PTR_LAB_009d27dc;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x254) = puVar2;

    if (*(char *)(param_1 + 0x23f) != '\0') {

      if (*(uint *)(param_1 + 0xb8) == (*(uint *)(param_1 + 0xbc) & 0x7fffffff)) {

        FUN_005b3370((int *)(param_1 + 0xb4),4);

      }

      *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xb4) + *(int *)(param_1 + 0xb8) * 4) = puVar1;

      *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + 1;

      *(uint8_t *)(param_1 + 0x240) = 1;

      return;

    }

    *(uint8_t *)(param_1 + 0x240) = 0;

  }

  return;

}
