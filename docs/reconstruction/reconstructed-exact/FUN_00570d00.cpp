// =============================================================================
// FUN_00570d00
// -----------------------------------------------------------------------------
// Stable ID: aa_00570d00
// Address:   0x00570d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00570d00 @ 0x00570d00
// Stable ID: aa_00570d00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_00570d00, OutputDebugStringA.
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

void __fastcall FUN_00570d00(int param_1)



{

  LPCSTR lpOutputString;

  int iVar1;

  int iVar2;

  int iVar3;

  int local_c;

  

  lpOutputString = operator_new__(*(int *)(param_1 + 0xc) * *(int *)(param_1 + 8) * 2);

  iVar1 = 0;

  local_c = 0;

  if (0 < *(int *)(param_1 + 8)) {

    do {

      iVar3 = 0;

      if (0 < *(int *)(param_1 + 0xc)) {

        do {

          iVar2 = *(int *)(param_1 + 0xc) * local_c + iVar3;

          if ((*(uint *)(*(int *)(param_1 + 0x28) + iVar2 * 8) &

              *(uint *)(*(int *)(param_1 + 0x28) + 4 + iVar2 * 8)) == 0xffffffff) {

            lpOutputString[iVar1] = '0';

          }

          else {

            lpOutputString[iVar1] = '1';

          }

          lpOutputString[iVar1 + 1] = '\t';

          iVar3 = iVar3 + 1;

          iVar1 = iVar1 + 2;

        } while (iVar3 < *(int *)(param_1 + 0xc));

      }

      lpOutputString[iVar1] = '\n';

      local_c = local_c + 1;

      iVar1 = iVar1 + 1;

    } while (local_c < *(int *)(param_1 + 8));

  }

  lpOutputString[iVar1] = '-';

  lpOutputString[iVar1 + 1] = '\n';

  lpOutputString[iVar1 + 2] = '\0';

  OutputDebugStringA(lpOutputString);

  if (lpOutputString != (LPCSTR)0x0) {

    operator_delete__(lpOutputString);

  }

  return;

}
