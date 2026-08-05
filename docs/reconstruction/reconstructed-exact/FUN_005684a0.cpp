// =============================================================================
// FUN_005684a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005684a0
// Address:   0x005684a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005684a0 @ 0x005684a0
// Stable ID: aa_005684a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, return×2.
//  - Notable callees: FUN_005684a0, FUN_00569030.
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

int __thiscall FUN_005684a0(int *param_1,int param_2)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *local_4;

  

  local_4 = param_1;

  FUN_00569030(&local_4,&param_2);

  if (local_4 != (int *)param_1[9]) {

    iVar4 = 1;

    while( true ) {

      if (*(char *)((int)local_4 + 0x49) == '\0') {

        piVar2 = (int *)local_4[2];

        if (*(char *)((int)piVar2 + 0x49) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x49);

          local_4 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x49);

            local_4 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(local_4[1] + 0x49);

          piVar3 = (int *)local_4[1];

          piVar2 = local_4;

          while ((local_4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)local_4[2]))) {

            cVar1 = *(char *)(local_4[1] + 0x49);

            piVar3 = (int *)local_4[1];

            piVar2 = local_4;

          }

        }

      }

      if ((local_4 == (int *)param_1[9]) || (local_4[3] != param_2)) break;

      iVar4 = iVar4 + 1;

    }

    return iVar4;

  }

  return 0;

}
