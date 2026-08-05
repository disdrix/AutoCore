// =============================================================================
// Named_CalleeOf_CVOGCreature_PostCreateFromPacket_004c49d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c49d0
// Callee of CVOGCreature_PostCreateFromPacket
// Address:   0x004c49d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCreature_PostCreateFromPacket: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_004c49d0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of CVOGCreature_PostCreateFromPacket
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

void __thiscall Named_CalleeOf_CVOGCreature_PostCreateFromPacket_004c49d0(int *param_1,int param_2)



{

  int iVar1;

  

  param_1[0x94] = param_2;

  if (param_2 == 0) {

    param_1[0x84] = -1;

    param_1[0x85] = -1;

    return;

  }

  iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);

  param_1[0x84] = *(int *)(iVar1 + 0x164 + param_2);

  param_1[0x85] = *(int *)(iVar1 + 0x168 + param_2);

  (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x158))

            (*(int *)(param_1[1] + 4) + 4 + (int)param_1);

  iVar1 = *(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1);

  if (iVar1 != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x218))(iVar1);

    (**(code **)(*param_1 + 0x5c))();

    iVar1 = *(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1);

    if ((iVar1 != 0) && (*(char *)(iVar1 + 0xf5) != '\0')) {

      *(uint8_t *)(param_1 + 0xc3) = 0;

      return;

    }

    *(uint8_t *)(param_1 + 0xc3) = 1;

  }

  return;

}
