// =============================================================================
// FUN_006f1a80
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1a80
// Address:   0x006f1a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1a80 @ 0x006f1a80
// Stable ID: aa_006f1a80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_006f19b0, FUN_006f1a80.
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

void __thiscall FUN_006f1a80(int param_1,int *param_2)



{

  short *psVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  

  iVar2 = param_2[1];

  iVar4 = 0;

  if (0 < iVar2) {

    do {

      psVar1 = (short *)(*(int *)(*param_2 + iVar4 * 4) + 6);

      *psVar1 = *psVar1 + 1;

      iVar4 = iVar4 + 1;

    } while (iVar4 < iVar2);

  }

  iVar2 = *(int *)(param_1 + 0x1c);

  iVar4 = 0;

  if (0 < iVar2) {

    do {

      puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x18) + iVar4 * 4);

      *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

      if (*(short *)((int)puVar3 + 6) == 0) {

        (**(code **)*puVar3)(1);

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < iVar2);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  FUN_006f19b0(0,param_2);

  return;

}
