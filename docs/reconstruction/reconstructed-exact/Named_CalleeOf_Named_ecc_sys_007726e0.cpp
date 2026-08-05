// =============================================================================
// Named_CalleeOf_Named_ecc_sys_007726e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007726e0
// Callee of Named_ecc_sys (+1 other named callers)
// Address:   0x007726e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_ecc_sys (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, return×2, goto×1, do×1, for×1.
//  - Notable callees: FUN_007707d0×4, FUN_00770440×2, FUN_00770650×2, FUN_007701a0, FUN_007726e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_CalleeOf_Named_ecc_sys_007726e0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint *puVar3;

  uint *puVar4;

  uint uVar5;

  uint uVar6;

  int local_20;

  uint8_t *local_14;

  

  iVar1 = FUN_00770440();

  if ((iVar1 == 0) && (iVar1 = FUN_00770650(), iVar1 == 0)) {

    iVar1 = 0;

    while (local_20 != 0) {

      *(uint8_t *)(iVar1 + param_2) = *local_14;

      iVar1 = iVar1 + 1;

      iVar2 = FUN_00770440();

      if (iVar2 != 0) {

LAB_007727f7:

        FUN_007707d0();

        return iVar2;

      }

      iVar2 = FUN_00770650();

      if (iVar2 != 0) {

        FUN_007707d0();

        goto LAB_007727f7;

      }

      puVar3 = (uint *)(local_14 + local_20 * 4 + -4);

      uVar5 = 0;

      puVar4 = puVar3;

      iVar2 = local_20;

      if (-1 < local_20 + -1) {

        do {

          uVar6 = uVar5 << 0x14;

          uVar5 = *puVar4 & 0xff;

          *puVar4 = *puVar4 >> 8 | uVar6;

          iVar2 = iVar2 + -1;

          puVar4 = puVar4 + -1;

        } while (iVar2 != 0);

      }

      for (; (0 < local_20 && (*puVar3 == 0)); puVar3 = puVar3 + -1) {

        local_20 = local_20 + -1;

      }

      FUN_007707d0();

    }

    FUN_007701a0();

    FUN_007707d0();

    iVar1 = 0;

  }

  return iVar1;

}
