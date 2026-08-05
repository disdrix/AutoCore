// =============================================================================
// FUN_0040e340
// -----------------------------------------------------------------------------
// Stable ID: aa_0040e340
// Address:   0x0040e340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040e340 @ 0x0040e340
// Stable ID: aa_0040e340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_0040e340.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x0040e340; evidence only — no invented semantics):
//  - Entry: `undefined4 FUN_0040e340(void)`.
//  - Branches: if (*(in_EAX + 4) != 0).
//  - Returns (2 site(s)): `uVar1`; `0`.




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

uint32_t /* width from decompiler */ FUN_0040e340(void)



{

  LPCRITICAL_SECTION lpCriticalSection;

  uint32_t /* width from decompiler */ uVar1;

  int in_EAX;

  

  lpCriticalSection = (LPCRITICAL_SECTION)(in_EAX + 0x28);

  EnterCriticalSection(lpCriticalSection);

  if (*(int *)(in_EAX + 4) != 0) {

    uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 4) + 4);

    LeaveCriticalSection(lpCriticalSection);

    return uVar1;

  }

  LeaveCriticalSection(lpCriticalSection);

  return 0;

}
