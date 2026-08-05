// =============================================================================
// FUN_0043e850
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e850
// Address:   0x0043e850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043e850 @ 0x0043e850
// Stable ID: aa_0043e850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_0043e850.
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

uint32_t /* width from decompiler */ FUN_0043e850(void)



{

  LPCRITICAL_SECTION lpCriticalSection;

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  int iVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  lpCriticalSection = (LPCRITICAL_SECTION)(unaff_ESI + 0x14);

  if (*(char *)(unaff_ESI + 0x2c) != '\0') {

    EnterCriticalSection(lpCriticalSection);

  }

  if (*(int *)(unaff_ESI + 0x10) != 0) {

    uVar2 = *(uint *)(unaff_ESI + 0xc) >> 1;

    iVar3 = uVar2 * -2;

    if (*(uint *)(unaff_ESI + 8) <= uVar2) {

      uVar2 = uVar2 - *(uint *)(unaff_ESI + 8);

    }

    puVar1 = (uint32_t /* width from decompiler */ *)

             (*(int *)(*(int *)(unaff_ESI + 4) + uVar2 * 4) +

             (*(uint *)(unaff_ESI + 0xc) + iVar3) * 8);

    if (unaff_EDI != puVar1) {

      *unaff_EDI = *puVar1;

    }

    *(uint8_t *)(unaff_EDI + 1) = *(uint8_t *)(puVar1 + 1);

    if (*(int *)(unaff_ESI + 0x10) != 0) {

      *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0xc) + 1;

      if ((uint)(*(int *)(unaff_ESI + 8) * 2) <= *(uint *)(unaff_ESI + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

      }

      iVar3 = *(int *)(unaff_ESI + 0x10) + -1;

      *(int *)(unaff_ESI + 0x10) = iVar3;

      if (iVar3 == 0) {

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

      }

    }

    if (*(char *)(unaff_ESI + 0x2c) != '\0') {

      LeaveCriticalSection(lpCriticalSection);

    }

    return 1;

  }

  if (*(char *)(unaff_ESI + 0x2c) != '\0') {

    LeaveCriticalSection(lpCriticalSection);

  }

  return 0;

}
