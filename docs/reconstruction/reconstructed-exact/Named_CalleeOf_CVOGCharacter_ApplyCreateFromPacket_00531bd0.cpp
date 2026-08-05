// =============================================================================
// Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_00531bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00531bd0
// Callee of CVOGCharacter_ApplyCreateFromPacket
// Address:   0x00531bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCharacter_ApplyCreateFromPacket: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CNDHash_LookupByKey, FUN_00531bd0, FUN_0053c760.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGCharacter_ApplyCreateFromPacket
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

void __thiscall Named_CalleeOf_CVOGCharacter_ApplyCreateFromPacket_00531bd0(int param_1,int param_2,int *param_3)



{

  bool bVar1;

  int *piVar2;

  

  if (((param_2 != 0) && (*(int *)(param_2 + 0x158) != 0)) &&

     (*(int *)(param_2 + 0x15c) - *(int *)(param_2 + 0x158) >> 2 != 0)) {

    piVar2 = CNDHash_LookupByKey(*(void **)(param_1 + 0x55c),*(uint *)(param_2 + 0x10));

    bVar1 = false;

    if (piVar2 == (int *)0x0) {

      piVar2 = operator_new(0x14);

      if (piVar2 == (int *)0x0) {

        piVar2 = (int *)0x0;

      }

      else {

        *piVar2 = 0;

        piVar2[1] = 0;

        piVar2[2] = 0;

        piVar2[3] = 0;

        piVar2[4] = 0;

      }

      bVar1 = true;

    }

    *piVar2 = param_2;

    piVar2[1] = *param_3;

    piVar2[2] = param_3[1];

    piVar2[3] = param_3[2];

    piVar2[4] = param_3[3];

    if (bVar1) {

      FUN_0053c760(*(uint32_t /* width from decompiler */ *)(param_2 + 0x10),piVar2,0);

    }

  }

  return;

}
