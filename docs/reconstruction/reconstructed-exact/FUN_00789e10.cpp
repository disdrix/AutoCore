// =============================================================================
// FUN_00789e10
// -----------------------------------------------------------------------------
// Stable ID: aa_00789e10
// Address:   0x00789e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00789e10 @ 0x00789e10
// Stable ID: aa_00789e10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_00423f40×2, LeaveCriticalSection×2, FUN_004294f0, FUN_00789e10.
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

uint64_t FUN_00789e10(uint64_t *param_1)



{

  uint64_t *puVar1;

  uint64_t *puVar2;

  int in_EAX;

  int iVar3;

  

  puVar2 = param_1;

  FUN_004294f0();

  iVar3 = FUN_00423f40(&param_1);

  puVar1 = param_1;

  while( true ) {

    param_1 = puVar1;

    if (iVar3 != 0) {

      if (*(char *)(in_EAX + 0x560) != '\0') {

        *(uint8_t *)(in_EAX + 0x560) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x53c));

      }

      return 0xffffffffffffffff;

    }

    if (((puVar1 != (uint64_t *)0x0) && (*(int *)((int)puVar1 + 0xc) != 0)) &&

       (*(uint64_t **)(*(int *)((int)puVar1 + 0xc) + 0xec) == puVar2)) break;

    iVar3 = FUN_00423f40(&param_1);

    puVar1 = param_1;

  }

  if (*(char *)(in_EAX + 0x560) != '\0') {

    *(uint8_t *)(in_EAX + 0x560) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x53c));

  }

  return *puVar1;

}
