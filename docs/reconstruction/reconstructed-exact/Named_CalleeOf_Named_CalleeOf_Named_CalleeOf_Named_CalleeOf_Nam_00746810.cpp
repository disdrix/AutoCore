// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00746810
// -----------------------------------------------------------------------------
// Stable ID: aa_00746810
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x00746810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: switch×1, return×1.
//  - Notable callees: FUN_00746810.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00746810(uint32_t /* width from decompiler */ param_1,ushort *param_2)



{

  int iVar1;

  

  switch((char)param_2[3]) {

  case '\0':

    iVar1 = 0;

    break;

  case '\x01':

    iVar1 = 2;

    break;

  case '\x02':

    iVar1 = 3;

    break;

  case '\x03':

    iVar1 = 4;

    break;

  case '\x04':

    iVar1 = 6;

    break;

  case '\x05':

    iVar1 = 7;

    break;

  case '\x06':

    iVar1 = 8;

    break;

  case '\a':

    iVar1 = 9;

    break;

  default:

    iVar1 = 10;

    break;

  case '\t':

    iVar1 = 1;

    break;

  case '\n':

    iVar1 = 5;

  }

  return (uint)*(byte *)((int)param_2 + 7) + (uint)*param_2 * 100 + iVar1 * 8;

}
