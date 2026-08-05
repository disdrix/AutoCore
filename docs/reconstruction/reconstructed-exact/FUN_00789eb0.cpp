// =============================================================================
// FUN_00789eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00789eb0
// Address:   0x00789eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00789eb0 @ 0x00789eb0
// Stable ID: aa_00789eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_00423f40×2, LeaveCriticalSection×2, FUN_004294f0, FUN_00789eb0.
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

int * FUN_00789eb0(int param_1,int param_2)



{

  int in_EAX;

  int iVar1;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_004294f0();

  local_4 = 0;

  iVar1 = FUN_00423f40(&local_8);

  while( true ) {

    if (iVar1 != 0) {

      if (*(char *)(in_EAX + 0x534) != '\0') {

        *(uint8_t *)(in_EAX + 0x534) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x510));

      }

      return (int *)0x0;

    }

    if (((local_8 != (int *)0x0) && (*local_8 == param_1)) && (local_8[1] == param_2)) break;

    iVar1 = FUN_00423f40(&local_8);

  }

  if (*(char *)(in_EAX + 0x534) != '\0') {

    *(uint8_t *)(in_EAX + 0x534) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x510));

  }

  return local_8;

}
