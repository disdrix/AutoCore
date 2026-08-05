// =============================================================================
// FUN_007a3cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a3cb0
// Address:   0x007a3cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a3cb0 @ 0x007a3cb0
// Stable ID: aa_007a3cb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: DeleteCriticalSection, FUN_007544f0, FUN_0079e3e0, FUN_007a3cb0, FUN_00970a90.
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

void FUN_007a3cb0(void)



{

  int in_EAX;

  

  if (*(int *)(in_EAX + 0xd4) != 0) {

    FUN_00970a90();

    if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0xd4) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xd4))(1);

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xd4) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xd4) = 0;

  }

  DeleteCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x2b8));

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x128) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x128))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x128) = 0;

  FUN_0079e3e0();

  FUN_007544f0(in_EAX);

  return;

}
