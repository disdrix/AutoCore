// =============================================================================
// FUN_005701f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005701f0
// Address:   0x005701f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005701f0 @ 0x005701f0
// Stable ID: aa_005701f0
// Embedded strings (evidence for future rename):
//   - "HashError:Destructor, already locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_007a4480×2, FUN_005701f0, FUN_00570260, FUN_0059c8a0.
//  - Strings: "HashError:Destructor, already locked for traversal"; "VOG_DEBUG_STOP".
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

void __fastcall FUN_005701f0(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a4eeb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009d3350;

  local_4 = 0;

  if (*(char *)((int)param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:Destructor, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  FUN_00570260();

  FUN_0059c8a0();

  ExceptionList = local_c;

  return;

}
