// =============================================================================
// Named_CalleeOf_Named_Invalid_packet_0077fe70
// -----------------------------------------------------------------------------
// Stable ID: aa_0077fe70
// Callee of Named_Invalid_packet (+1 other named callers)
// Address:   0x0077fe70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Invalid_packet: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Invalid_packet (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0077fe70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Invalid_packet (+1 other named callers)
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

int Named_CalleeOf_Named_Invalid_packet_0077fe70(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  int *piVar3;

  void *pvVar4;

  int *unaff_ESI;

  

  if ((*unaff_ESI == 0) || (unaff_ESI[1] < *(int *)(*unaff_ESI + 8) + in_EAX)) {

    piVar3 = operator_new(0xc);

    if (piVar3 == (int *)0x0) {

      piVar3 = (int *)0x0;

    }

    else {

      pvVar4 = operator_new__(unaff_ESI[1]);

      piVar3[1] = (int)pvVar4;

    }

    *piVar3 = *unaff_ESI;

    piVar3[2] = 0;

    *unaff_ESI = (int)piVar3;

  }

  iVar1 = *unaff_ESI;

  iVar2 = *(int *)(iVar1 + 8);

  *(uint *)(iVar1 + 8) = (in_EAX + 3U & 0xfffffffc) + iVar2;

  return *(int *)(iVar1 + 4) + iVar2;

}
