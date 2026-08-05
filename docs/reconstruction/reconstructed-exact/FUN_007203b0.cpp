// =============================================================================
// FUN_007203b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007203b0
// Address:   0x007203b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007203b0 @ 0x007203b0
// Stable ID: aa_007203b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: _stricmp×2, EnterCriticalSection, FUN_0071ffc0, FUN_007203b0, LeaveCriticalSection.
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

void __thiscall FUN_007203b0(int param_1,char *param_2,char param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  if (*(char *)(param_1 + 0x10) != '\0') {

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x158));

    if (param_3 != '\0') {

      FUN_0071ffc0(param_2);

    }

    piVar3 = (int *)(param_1 + 0x80);

    iVar2 = 2;

    do {

      if (piVar3[2] != 0) {

        iVar1 = _stricmp((char *)(piVar3[2] + 0x48),param_2);

        if (iVar1 == 0) {

          *(uint8_t *)(piVar3[2] + 0x38) = 1;

          *(uint32_t /* width from decompiler */ *)(piVar3[2] + 0x1b0) = 0;

        }

      }

      if (*piVar3 != 0) {

        iVar1 = _stricmp((char *)(*piVar3 + 0x48),param_2);

        if (iVar1 == 0) {

          *(uint8_t *)(*piVar3 + 0x38) = 1;

          *(uint32_t /* width from decompiler */ *)(*piVar3 + 0x1b0) = 0;

        }

      }

      piVar3 = piVar3 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x158));

  }

  return;

}
