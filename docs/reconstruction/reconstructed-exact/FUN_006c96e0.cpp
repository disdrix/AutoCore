// =============================================================================
// FUN_006c96e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c96e0
// Address:   0x006c96e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c96e0 @ 0x006c96e0
// Stable ID: aa_006c96e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300×2, FUN_006c96e0, FUN_006cde50.
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

void __thiscall FUN_006c96e0(int param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  

  FUN_006cde50(param_2);

  *(uint32_t /* width from decompiler */ *)(param_2 + 8) = 0;

  iVar1 = *(int *)(param_1 + 0x10);

  uVar2 = *(uint *)(param_2 + 0xc) & 0x7fffffff;

  if ((int)uVar2 < iVar1) {

    iVar3 = uVar2 * 2;

    if (iVar3 <= iVar1) {

      iVar3 = iVar1;

    }

    FUN_005b3300((int *)(param_2 + 4),iVar3,4);

  }

  *(int *)(param_2 + 8) = iVar1;

  uVar2 = *(uint *)(param_2 + 0x18) & 0x7fffffff;

  if ((int)uVar2 < iVar1) {

    iVar3 = uVar2 * 2;

    if (iVar3 <= iVar1) {

      iVar3 = iVar1;

    }

    FUN_005b3300((int *)(param_2 + 0x10),iVar3,4);

  }

  iVar3 = 0;

  *(int *)(param_2 + 0x14) = iVar1;

  if (0 < iVar1) {

    do {

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 4) + iVar3 * 4) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + iVar3 * 8);

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x10) + iVar3 * 4) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + 4 + iVar3 * 8);

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar1);

  }

  return;

}
