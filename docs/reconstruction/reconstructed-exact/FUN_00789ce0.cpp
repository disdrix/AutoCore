// =============================================================================
// FUN_00789ce0
// -----------------------------------------------------------------------------
// Stable ID: aa_00789ce0
// Address:   0x00789ce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00789ce0 @ 0x00789ce0
// Stable ID: aa_00789ce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, while×1.
//  - Notable callees: FUN_00423f40×2, LeaveCriticalSection×2, FUN_004294f0, FUN_00789ce0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00789ce0(int param_1)



{

  int in_EAX;

  int iVar1;

  int local_4;

  

  FUN_004294f0();

  iVar1 = FUN_00423f40(&local_4);

  while( true ) {

    if (iVar1 != 0) {

      if (*(char *)(in_EAX + 0x560) != '\0') {

        *(uint8_t *)(in_EAX + 0x560) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x53c));

      }

      return 0;

    }

    if (param_1 == 0) break;

    param_1 = param_1 + -1;

    iVar1 = FUN_00423f40(&local_4);

  }

  if (*(char *)(in_EAX + 0x560) != '\0') {

    *(uint8_t *)(in_EAX + 0x560) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x53c));

  }

  if (local_4 == 0) {

    return 0;

  }

  return *(uint32_t /* width from decompiler */ *)(local_4 + 0xc);

}
