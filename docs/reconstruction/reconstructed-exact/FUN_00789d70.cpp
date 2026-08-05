// =============================================================================
// FUN_00789d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00789d70
// Address:   0x00789d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00789d70 @ 0x00789d70
// Stable ID: aa_00789d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_00423f40×2, LeaveCriticalSection×2, FUN_004294f0, FUN_00789d70.
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

int FUN_00789d70(int param_1)



{

  int in_EAX;

  int iVar1;

  int iVar2;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar2 = 0;

  FUN_004294f0();

  local_4 = 0;

  iVar1 = FUN_00423f40(&local_8);

  while( true ) {

    if (iVar1 != 0) {

      if (*(char *)(in_EAX + 0x560) != '\0') {

        *(uint8_t *)(in_EAX + 0x560) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x53c));

      }

      return -1;

    }

    if (((local_8 != 0) && (*(int *)(local_8 + 0xc) != 0)) &&

       (*(int *)(*(int *)(local_8 + 0xc) + 0xec) == param_1)) break;

    iVar2 = iVar2 + 1;

    iVar1 = FUN_00423f40(&local_8);

  }

  if (*(char *)(in_EAX + 0x560) != '\0') {

    *(uint8_t *)(in_EAX + 0x560) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x53c));

  }

  return iVar2;

}
