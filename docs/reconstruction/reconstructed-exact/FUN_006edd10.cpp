// =============================================================================
// FUN_006edd10
// -----------------------------------------------------------------------------
// Stable ID: aa_006edd10
// Address:   0x006edd10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006edd10 @ 0x006edd10
// Stable ID: aa_006edd10
// Embedded strings (evidence for future rename):
//   - "LthkBvAgent"
//   - "Stchild"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: rdtsc×3, FUN_006edd10.
//  - Strings: "LthkBvAgent"; "Stchild".
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

void FUN_006edd10(int *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint64_t uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined **local_18;

  char cStack_14;

  int *local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LthkBvAgent";

    uVar1 = rdtsc();

    local_18 = (undefined **)uVar1;

    DAT_00bc5644[1] = local_18;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_8 = param_1[2];

  iVar4 = *param_1;

  local_4 = param_1;

  local_10 = *(int **)(iVar4 + 0xc);

  local_c = param_1[1];

  iVar2 = (**(code **)(*local_10 + 0x14))();

  iVar3 = (**(code **)(*(int *)*param_2 + 0x14))();

  local_18 = &PTR_LAB_00a0e9d0;

  cStack_14 = '\0';

  (**(code **)(*param_3 + 0x118c + (iVar2 * 0x20 + iVar3) * 4))(&local_10,param_2,param_3,&local_18)

  ;

  if (cStack_14 != '\0') {

    if (DAT_00bc5644 < DAT_00bc5648) {

      *DAT_00bc5644 = "Stchild";

      uVar1 = rdtsc();

      DAT_00bc5644[1] = (int)uVar1;

      DAT_00bc5644 = DAT_00bc5644 + 3;

    }

    local_10 = *(int **)(iVar4 + 0x10);

    local_c = local_4[1];

    iVar4 = (**(code **)(*local_10 + 0x14))();

    (**(code **)(*param_3 + 0x218c + (iVar4 * 0x20 + iVar3) * 4))(&local_10,param_2,param_3,param_4)

    ;

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
