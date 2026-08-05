// =============================================================================
// FUN_00653500
// -----------------------------------------------------------------------------
// Stable ID: aa_00653500
// Address:   0x00653500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00653500 @ 0x00653500
// Stable ID: aa_00653500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_0055e280, FUN_0055e370, FUN_0055e8e0, FUN_0055e970, FUN_00652320, FUN_00653500, block.
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

/* WARNING: Removing unreachable block (ram,0x00653561) */



void __thiscall FUN_00653500(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  if (param_2 != *(int *)(param_1 + 0xc)) {

    if (*(int *)(param_1 + 0xc) != 0) {

      FUN_0055e280(param_1 + 0x14);

      FUN_0055e370(param_1 + 0x18);

      iVar2 = 0;

      if (0 < *(int *)(param_1 + 0x20)) {

        do {

          puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x1c) + iVar2 * 4);

          *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

          if (*(short *)((int)puVar1 + 6) == 0) {

            (**(code **)*puVar1)(1);

          }

          iVar2 = iVar2 + 1;

        } while (iVar2 < *(int *)(param_1 + 0x20));

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

    }

    FUN_00652320(param_2);

    if (*(int *)(param_1 + 0xc) != 0) {

      FUN_0055e8e0(param_1 + 0x14);

      FUN_0055e970(param_1 + 0x18);

    }

  }

  return;

}
