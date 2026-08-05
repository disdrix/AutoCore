// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004085e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004085e0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004085e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: while×2, return×2, do×1, if×1.
//  - Notable callees: FUN_004085e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004085e0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EBX;

  uint uVar4;

  

  uVar4 = 0;

  do {

    puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(unaff_EBX + 0x10) + uVar4 * 4) + 4);

    while (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)puVar3[4];

      *puVar3 = &PTR_FUN_00a2c2bc;

      if ((void *)puVar3[3] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete((void *)puVar3[3]);

      }

      puVar3[3] = 0;

      *puVar3 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x20);

      *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x20) = puVar3;

      puVar3 = puVar2;

    }

    iVar1 = uVar4 * 4;

    uVar4 = uVar4 + 1;

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(unaff_EBX + 0x10) + iVar1) + 4) = 0;

  } while (uVar4 <= *(uint *)(unaff_EBX + 8));

  return;

}
