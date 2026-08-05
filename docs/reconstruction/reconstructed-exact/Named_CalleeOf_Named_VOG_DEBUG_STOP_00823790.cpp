// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00823790
// -----------------------------------------------------------------------------
// Stable ID: aa_00823790
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00823790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00823790.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_00823790(void)



{

  int in_EAX;

  int iVar1;

  int *unaff_ESI;

  

  unaff_ESI[0x182] = in_EAX;

  if (in_EAX == 0) {

    unaff_ESI[0x183] = 0;

    *(uint8_t *)(unaff_ESI + 0x13f) = 0;

    unaff_ESI[0x185] = -1;

    unaff_ESI[0x186] = DAT_00a1e820;

    unaff_ESI[0x187] = DAT_00a1e824;

    unaff_ESI[0x188] = DAT_00a1e828;

    iVar1 = DAT_00a1e82c;

  }

  else {

    unaff_ESI[0x183] = in_EAX + 0x24;

    *(uint8_t *)(unaff_ESI + 0x13f) = 1;

    unaff_ESI[0x185] = *(int *)(in_EAX + 0x620);

    unaff_ESI[0x186] = *(int *)(in_EAX + 0x658);

    unaff_ESI[0x187] = *(int *)(in_EAX + 0x65c);

    unaff_ESI[0x188] = *(int *)(in_EAX + 0x660);

    iVar1 = *(int *)(in_EAX + 0x664);

  }

  unaff_ESI[0x189] = iVar1;

  (**(code **)(*unaff_ESI + 0x444))();

                    /* WARNING: Could not recover jumptable at 0x00823823. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_ESI + 0x34c))();

  return;

}
