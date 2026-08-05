// =============================================================================
// Named_CalleeOf_CVOGReaction_GiveMission_00538a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00538a40
// Callee of CVOGReaction_GiveMission
// Address:   0x00538a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_GiveMission: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00538a40.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_GiveMission
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

void __thiscall Named_CalleeOf_CVOGReaction_GiveMission_00538a40(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)puVar3[1] + 0x49) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      if ((int)puVar1[4] < *param_3) {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

        puVar3 = puVar1;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x49) == '\0');

  }

  if ((puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 4)) && ((int)puVar3[4] <= *param_3)) {

    *param_2 = puVar3;

    return;

  }

  *param_2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  return;

}
