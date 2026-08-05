// =============================================================================
// FUN_0074f200
// -----------------------------------------------------------------------------
// Stable ID: aa_0074f200
// Address:   0x0074f200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074f200 @ 0x0074f200
// Stable ID: aa_0074f200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1, for×1.
//  - Notable callees: FUN_0074f200.
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

uint32_t /* width from decompiler */ __thiscall FUN_0074f200(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  if (*(int *)(param_1 + 0xc) == 0) {

    return 0xffffffff;

  }

  iVar2 = *(int *)(param_1 + 0x28);

  if (*(int *)(&DAT_00afe014 + iVar2 * 0xc) != param_2) {

    if (*(int *)(param_1 + 0x20) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(*(int *)(param_1 + 0x20) + 0x38);

    }

    iVar5 = 0;

    if (0 < iVar4) {

      do {

        iVar3 = *(int *)(*(int *)(param_1 + 0x20) + 0x34);

        puVar1 = (uint32_t /* width from decompiler */ *)(iVar3 + iVar5 * 8);

        (**(code **)(**(int **)(param_1 + 0xc) + 0x50))

                  (*(int **)(param_1 + 0xc),*puVar1,(uint)*(ushort *)(puVar1 + 1) + param_2,

                   *(uint16_t *)(iVar3 + 6 + iVar5 * 8));

        iVar5 = iVar5 + 1;

      } while (iVar5 < iVar4);

    }

    iVar4 = *(int *)(*(int *)(param_1 + 0x20) + 0x3c);

    for (; iVar5 < iVar4; iVar5 = iVar5 + 1) {

      iVar3 = *(int *)(*(int *)(param_1 + 0x20) + 0x34);

      (**(code **)(**(int **)(param_1 + 0xc) + 0xd0))

                (*(int **)(param_1 + 0xc),*(uint32_t /* width from decompiler */ *)(iVar3 + iVar5 * 8),

                 *(uint32_t /* width from decompiler */ *)((uint)*(ushort *)(iVar3 + 4 + iVar5 * 8) + param_2));

    }

    *(int *)(&DAT_00afe014 + iVar2 * 0xc) = param_2;

  }

  return 0;

}
