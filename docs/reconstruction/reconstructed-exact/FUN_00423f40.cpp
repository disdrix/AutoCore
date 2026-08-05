// =============================================================================
// FUN_00423f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00423f40
// Address:   0x00423f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00423f40 @ 0x00423f40
// Stable ID: aa_00423f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: LeaveCriticalSection×3, FUN_00423f40, TryEnterCriticalSection.
//  - Return sites: 4.

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

uint FUN_00423f40(uint32_t /* width from decompiler */ *param_1)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int iVar1;

  BOOL BVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  int *unaff_EDI;

  

  iVar1 = *unaff_EDI;

  if (*(char *)(unaff_ESI + 0x28) != '\0') {

    lpCriticalSection = (LPCRITICAL_SECTION)(unaff_ESI + 4);

    BVar2 = TryEnterCriticalSection(lpCriticalSection);

    if (BVar2 != 0) {

      if (*unaff_EDI == 0) {

        if (*(int *)(unaff_ESI + 0x1c) == 0) {

          uVar3 = 0;

        }

        else {

          uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x1c) + 4);

        }

        *param_1 = uVar3;

        *unaff_EDI = *(int *)(unaff_ESI + 0x1c);

        LeaveCriticalSection(lpCriticalSection);

        return (uint)(*(int *)(unaff_ESI + 0x1c) == 0);

      }

      if (*(int *)(iVar1 + 8) != 0) {

        *unaff_EDI = *(int *)(iVar1 + 8);

        *param_1 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 8) + 4);

        LeaveCriticalSection(lpCriticalSection);

        return 0;

      }

      *unaff_EDI = 0;

      *param_1 = 0;

      LeaveCriticalSection(lpCriticalSection);

      return 1;

    }

  }

  return 0x80070005;

}
