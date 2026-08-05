// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_008904a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008904a0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x008904a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×2.
//  - Notable callees: FUN_008904a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_008904a0(void)



{

  char cVar1;

  char *pcVar2;

  int unaff_ESI;

  char *unaff_EDI;

  

  if (*(void **)(unaff_ESI + 0x514) != (void *)0x0) {

    operator_delete__(*(void **)(unaff_ESI + 0x514));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x514) = 0;

  pcVar2 = unaff_EDI;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(unaff_EDI + 1))));

  *(char **)(unaff_ESI + 0x514) = pcVar2;

  do {

    cVar1 = *unaff_EDI;

    *pcVar2 = cVar1;

    unaff_EDI = unaff_EDI + 1;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  if (*(int **)(unaff_ESI + 0x510) != (int *)0x0) {

    (**(code **)(**(int **)(unaff_ESI + 0x510) + 0x1d8))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x514),1,1);

                    /* WARNING: Could not recover jumptable at 0x00890516. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x510) + 0x34c))();

    return;

  }

  return;

}
