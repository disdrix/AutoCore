// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00483580
// -----------------------------------------------------------------------------
// Stable ID: aa_00483580
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00483580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00483580.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00483580(void)



{

  int in_EAX;

  int iVar1;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x54) = 0;

  iVar1 = 0;

  do {

    if (*(char *)(in_EAX + 0x58 + iVar1) != '\0') {

      *(uint8_t *)(iVar1 + 0x158 + in_EAX) = *(uint8_t *)(in_EAX + 0x54);

      *(int *)(in_EAX + 0x54) = *(int *)(in_EAX + 0x54) + 1;

    }

    if (*(char *)(in_EAX + 0x59 + iVar1) != '\0') {

      *(uint8_t *)(iVar1 + 0x159 + in_EAX) = *(uint8_t *)(in_EAX + 0x54);

      *(int *)(in_EAX + 0x54) = *(int *)(in_EAX + 0x54) + 1;

    }

    if (*(char *)(in_EAX + 0x5a + iVar1) != '\0') {

      *(uint8_t *)(iVar1 + 0x15a + in_EAX) = *(uint8_t *)(in_EAX + 0x54);

      *(int *)(in_EAX + 0x54) = *(int *)(in_EAX + 0x54) + 1;

    }

    if (*(char *)(in_EAX + 0x5b + iVar1) != '\0') {

      *(uint8_t *)(iVar1 + 0x15b + in_EAX) = *(uint8_t *)(in_EAX + 0x54);

      *(int *)(in_EAX + 0x54) = *(int *)(in_EAX + 0x54) + 1;

    }

    iVar1 = iVar1 + 4;

  } while (iVar1 < 0x100);

  return;

}
