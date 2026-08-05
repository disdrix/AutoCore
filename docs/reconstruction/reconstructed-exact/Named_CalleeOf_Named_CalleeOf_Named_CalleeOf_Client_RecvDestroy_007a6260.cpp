// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvDestroy_007a6260
// -----------------------------------------------------------------------------
// Stable ID: aa_007a6260
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvDestroyObject
// Address:   0x007a6260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvDestroyObject: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_007a6260.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvDestroyObject
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvDestroy_007a6260(void)



{

  int in_EAX;

  void *pvVar1;

  uint uVar2;

  uint uVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (*(int *)(unaff_ESI + 0x6c + *(int *)(unaff_ESI + 0xc0) * 4) < in_EAX) {

    operator_delete__(*(void **)(unaff_ESI + 4 + *(int *)(unaff_ESI + 0xc0) * 4));

    *(int *)(unaff_ESI + 0x6c + *(int *)(unaff_ESI + 0xc0) * 4) = in_EAX;

    pvVar1 = operator_new__(*(uint *)(unaff_ESI + 0x6c + *(int *)(unaff_ESI + 0xc0) * 4));

    *(void **)(unaff_ESI + 4 + *(int *)(unaff_ESI + 0xc0) * 4) = pvVar1;

  }

  uVar3 = *(uint *)(unaff_ESI + 0x6c + *(int *)(unaff_ESI + 0xc0) * 4);

  puVar4 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 4 + *(int *)(unaff_ESI + 0xc0) * 4);

  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint8_t *)puVar4 = 0;

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

  }

  return;

}
