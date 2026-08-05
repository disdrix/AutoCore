// =============================================================================
// FUN_004bc530
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc530
// Address:   0x004bc530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bc530 @ 0x004bc530
// Stable ID: aa_004bc530
// Embedded strings (evidence for future rename):
//   - "HashError:TraverseToNext, not locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×1.
//  - Notable callees: FUN_007a4480×2, FUN_004bc530.
//  - Strings: "HashError:TraverseToNext, not locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall FUN_004bc530(int param_1,int *param_2)



{

  int iVar1;

  

  if (*(char *)(param_1 + 0x1d) == '\0') {

    FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  if (*param_2 == 0) {

    *param_2 = *(int *)(param_1 + 0x14);

    iVar1 = *(int *)(param_1 + 0x14);

  }

  else {

    iVar1 = *(int *)(*param_2 + 0x20);

    *param_2 = iVar1;

  }

  if (iVar1 != 0) {

    return *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

  }

  return 0;

}
