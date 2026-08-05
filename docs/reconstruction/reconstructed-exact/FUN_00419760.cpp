// =============================================================================
// FUN_00419760
// -----------------------------------------------------------------------------
// Stable ID: aa_00419760
// Address:   0x00419760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00419760 @ 0x00419760
// Stable ID: aa_00419760
// Embedded strings (evidence for future rename):
//   - "HashError:Destroy, already locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_007a4480×2, FUN_00419760, FUN_004197b0.
//  - Strings: "HashError:Destroy, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 1.

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

int FUN_00419760(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  int in_EAX;

  int iVar1;

  

  if (*(char *)(in_EAX + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:Destroy, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  iVar1 = FUN_004197b0(param_1,param_2,&param_1);

  if (-1 < iVar1) {

    if (param_1 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*param_1)(1);

    }

    iVar1 = 0;

  }

  return iVar1;

}
