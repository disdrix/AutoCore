// =============================================================================
// FUN_00967710
// -----------------------------------------------------------------------------
// Stable ID: aa_00967710
// Address:   0x00967710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00967710 @ 0x00967710
// Stable ID: aa_00967710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00967710.
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

void __thiscall FUN_00967710(int param_1,int param_2,char param_3)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  piVar2 = DAT_00d1f62c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  iVar5 = 0;

  if (0 < *piVar2) {

    iVar6 = 0;

    iVar4 = 0x44;

    do {

      piVar2 = DAT_00d1f62c;

      iVar3 = 0;

      iVar1 = *(int *)(param_1 + 8);

      if (iVar1 != 0) {

        if ((param_3 == '\0') || (*(int *)(param_2 + -0x20 + iVar4) < 0)) {

          iVar3 = *(int *)(iVar1 + 8 + iVar6);

          if (iVar3 == 0) {

            iVar3 = 0;

          }

          else {

            iVar3 = *(int *)(iVar1 + 0xc + iVar6) - iVar3 >> 2;

          }

        }

        else {

          iVar3 = *(int *)(iVar4 + iVar1);

        }

      }

      *(int *)(param_1 + -0x1c + iVar4) = iVar3;

      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + iVar3;

      *(uint32_t /* width from decompiler */ *)(param_1 + -0xc + iVar4) = 0;

      iVar5 = iVar5 + 1;

      iVar4 = iVar4 + 4;

      iVar6 = iVar6 + 0x10;

    } while (iVar5 < *piVar2);

  }

  return;

}
