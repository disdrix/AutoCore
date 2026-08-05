// =============================================================================
// FUN_0080b7f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080b7f0
// Address:   0x0080b7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080b7f0 @ 0x0080b7f0
// Stable ID: aa_0080b7f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: FUN_00402dd0, FUN_00404840, FUN_00418700, FUN_00574730, FUN_0080b7f0.
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

void FUN_0080b7f0(int param_1)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  ushort uVar4;

  int in_EAX;

  int iVar5;

  int iVar6;

  int *piVar7;

  uint64_t uVar8;

  uint local_8;

  int *local_4;

  

  *(int *)(param_1 + 0x14) = param_1 + 0x18;

  if ((*(int *)(in_EAX + 0xe98) != 0) &&

     (iVar1 = *(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0), iVar1 != 0)) {

    iVar6 = 0;

    if (*(char *)(iVar1 + 0x1d8) != '\0') {

      do {

        uVar8 = FUN_00574730(iVar6);

        if (((int)uVar8 == *(int *)(param_1 + 8)) &&

           ((int)((ulonglong)uVar8 >> 0x20) == *(int *)(param_1 + 0xc))) break;

        iVar6 = iVar6 + 1;

      } while (iVar6 < (int)(uint)*(byte *)(iVar1 + 0x1d8));

    }

    if ((iVar6 < (int)(uint)*(byte *)(iVar1 + 0x1d8)) &&

       (piVar2 = *(int **)(in_EAX + 0x107c), piVar2 != (int *)0x0)) {

      local_4 = piVar2;

      FUN_00402dd0(0);

      uVar4 = 0;

      piVar7 = piVar2;

      if (*(short *)(param_1 + 0x10) != 0) {

        do {

          local_8 = (uint)*(ushort *)(*(int *)(param_1 + 0x14) + (uint)uVar4 * 2);

          iVar1 = piVar2[iVar6 * 3 + 0x174];

          iVar5 = FUN_00418700(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&local_8);

          FUN_00404840(1);

          *(int *)(iVar1 + 4) = iVar5;

          **(int **)(iVar5 + 4) = iVar5;

          uVar4 = uVar4 + 1;

          piVar7 = local_4;

        } while (uVar4 < *(ushort *)(param_1 + 0x10));

      }

      cVar3 = (**(code **)(*piVar7 + 0x3d8))();

      if (cVar3 != '\0') {

        (**(code **)(*piVar7 + 0x448))();

      }

    }

  }

  return;

}
