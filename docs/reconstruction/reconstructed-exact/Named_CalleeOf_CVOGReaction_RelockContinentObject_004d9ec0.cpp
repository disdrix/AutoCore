// =============================================================================
// Named_CalleeOf_CVOGReaction_RelockContinentObject_004d9ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d9ec0
// Callee of CVOGReaction_RelockContinentObject (+1 other named callers)
// Address:   0x004d9ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_RelockContinentObject: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGReaction_RelockContinentObject (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: Client_SendLogicUiPacket, FUN_004d9ec0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_RelockContinentObject (+1 other named callers)
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

void __thiscall Named_CalleeOf_CVOGReaction_RelockContinentObject_004d9ec0(int param_1,int param_2,char param_3)



{

  int iVar1;

  

  if (param_3 != '\0') {

    iVar1 = *(int *)(param_1 + 0xe8bc);

    if (iVar1 != *(int *)(param_1 + 0xe8c0)) {

      do {

        if (*(int *)(param_2 + 0x1c) == *(int *)(iVar1 + 0x1c)) {

          return;

        }

        iVar1 = iVar1 + 0x138;

      } while (iVar1 != *(int *)(param_1 + 0xe8c0));

    }

  }

  Client_SendLogicUiPacket(param_2);

  return;

}
