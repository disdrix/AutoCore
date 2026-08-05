// =============================================================================
// FUN_007208d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007208d0
// Address:   0x007208d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007208d0 @ 0x007208d0
// Stable ID: aa_007208d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: EnterCriticalSection, FUN_004804d0, FUN_007208d0, LeaveCriticalSection.
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

void FUN_007208d0(void)



{

  int iVar1;

  int unaff_ESI;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abdae;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x170));

  local_4 = 0;

  if ((*(int *)(unaff_ESI + 0x74) != 0) &&

     ((*(int *)(unaff_ESI + 0x78) - *(int *)(unaff_ESI + 0x74)) / 200 != 0)) {

    iVar2 = *(int *)(unaff_ESI + 0x74);

    if (iVar2 != *(int *)(unaff_ESI + 0x78)) {

      do {

        iVar1 = *(int *)(iVar2 + 0xb8);

        if ((((iVar1 == 2) || (iVar1 == 1)) || (iVar1 == 5)) || (iVar1 == 4)) {

          FUN_004804d0(iVar2);

        }

        iVar2 = iVar2 + 200;

      } while (iVar2 != *(int *)(unaff_ESI + 0x78));

    }

    if (*(void **)(unaff_ESI + 0x74) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(unaff_ESI + 0x74));

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x74) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x78) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x7c) = 0;

  }

  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x170));

  ExceptionList = local_c;

  return;

}
