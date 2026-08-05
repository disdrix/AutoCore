// =============================================================================
// FUN_0057a350
// -----------------------------------------------------------------------------
// Stable ID: aa_0057a350
// Address:   0x0057a350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057a350 @ 0x0057a350
// Stable ID: aa_0057a350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, switch×1, while×1, return×1.
//  - Notable callees: FUN_00517be0×2, FUN_00518180×2, FUN_00517c40, FUN_0057a250, FUN_0057a290, FUN_0057a350.
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

void __thiscall FUN_0057a350(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  uint64_t uVar4;

  

  FUN_00517c40(param_2,param_3);

  FUN_00518180(param_1 + 0x1d4,param_2,param_3);

  FUN_00518180(param_1 + 0x1e4,param_2,param_3);

  switch(*(uint8_t *)(param_1 + 0x1d1)) {

  case 0x12:

    if ((*(char **)(param_1 + 600) != (char *)0x0) && (**(char **)(param_1 + 600) == '\0')) {

      iVar3 = 0;

      while( true ) {

        iVar2 = *(int *)(*(int *)(param_1 + 600) + 0x1c);

        if (iVar2 == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(*(int *)(param_1 + 600) + 0x20) - iVar2 >> 2;

        }

        if (iVar2 <= iVar3) break;

        uVar4 = FUN_0057a250(iVar3);

        uVar4 = FUN_00517be0(param_2,uVar4);

        FUN_0057a290(iVar3,uVar4);

        iVar3 = iVar3 + 1;

      }

    }

    break;

  case 0x2b:

  case 0x2d:

  case 0x34:

  case 0x4e:

    uVar1 = FUN_00517be0(param_2,*(int *)(param_1 + 0x25c),*(int *)(param_1 + 0x25c) >> 0x1f);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x25c) = uVar1;

  }

  return;

}
