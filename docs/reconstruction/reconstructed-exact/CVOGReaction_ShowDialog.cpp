// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: CVOGMap_LookupVariable, CVOGReaction_ShowDialog.
//  - Return sites: 1.

// =============================================================================
// CVOGReaction_ShowDialog
// -----------------------------------------------------------------------------
// Stable ID: aa_0057a190
// Address:   0x0057a190  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void __thiscall CVOGReaction_ShowDialog(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (param_2 != 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x160);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x164);

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10);

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x168);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x16c);

    for (; puVar3 != puVar1; puVar3 = puVar3 + 1) {

      pcVar2 = (char *)*puVar3;

      if (*pcVar2 == '\0') {

        CVOGMap_LookupVariable(*(uint32_t /* width from decompiler */ *)(pcVar2 + 4),pcVar2 + 8,param_2);

      }

    }

  }

  return;

}
