// =============================================================================
// FUN_009189b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009189b0
// Address:   0x009189b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009189b0 @ 0x009189b0
// Stable ID: aa_009189b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_009189b0.
//  - Return sites: 3.

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

int * FUN_009189b0(void)



{

  char *pcVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  uint8_t local_58 [84];

  uint8_t local_4;

  uint8_t local_3;

  uint8_t local_2;

  uint8_t local_1;

  

  local_2 = 0xff;

  local_3 = 0xff;

  local_4 = 0xff;

  local_1 = 0xff;

  iVar3 = (**(code **)(**(int **)(*(int *)(DAT_00d1b644 + 0xe894) + 0xc0) + 0x10))

                    (&stack0x00000004,3,local_58,0);

  if ((iVar3 != 0) &&

     ((DAT_00d1b644 == 0 || (*(int *)(*(int *)(DAT_00d1b644 + 0xe4f8) + 0x390) != iVar3)))) {

    pcVar1 = *(char **)(iVar3 + 0x78);

    piVar4 = (int *)0x0;

    if (((pcVar1 != (char *)0x0) && (*pcVar1 == '\x01')) &&

       (piVar4 = *(int **)(pcVar1 + 4), piVar4 != (int *)0x0)) {

      if (*(int *)(piVar4[0x2a] + 0x38) == 0xc) {

        iVar3 = (**(code **)(*piVar4 + 0x1e0))();

      }

      else {

        if (*(int *)(piVar4[0x2a] + 0x38) != 0x10) {

          return piVar4;

        }

        iVar3 = (**(code **)(*piVar4 + 0x1f0))();

      }

      piVar2 = *(int **)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb0 + iVar3);

      if (piVar2 != (int *)0x0) {

        piVar4 = piVar2;

      }

    }

    return piVar4;

  }

  return (int *)0x0;

}
