// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_008060a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008060a0
// Callee of Named_Client_InitInstance
// Address:   0x008060a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0048a410, FUN_008060a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

void __fastcall Named_CalleeOf_Named_Client_InitInstance_008060a0(uint32_t /* width from decompiler */ param_1,byte param_2,byte param_3,byte param_4,byte param_5)



{

  int in_EAX;

  byte unaff_BL;

  

  if (*(int *)(in_EAX + 0x3c10) != 0) {

    if (param_2 != 0xffffffff) {

      *(byte *)(in_EAX + 0x3c14) = param_2;

    }

    if (unaff_BL != 0xffffffff) {

      *(byte *)(in_EAX + 0x3c15) = unaff_BL;

    }

    if (param_3 != 0xffffffff) {

      *(byte *)(in_EAX + 0x3c16) = param_3;

    }

    if (param_4 != 0xffffffff) {

      *(byte *)(in_EAX + 0x3c17) = param_4;

    }

    if (param_5 != 0xffffffff) {

      *(byte *)(in_EAX + 0x3c18) = param_5;

    }

    FUN_0048a410(in_EAX + 0x3c14,*(int *)(in_EAX + 0x3c10),0);

  }

  return;

}
