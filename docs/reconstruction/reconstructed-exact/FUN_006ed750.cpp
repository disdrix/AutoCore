// =============================================================================
// FUN_006ed750
// -----------------------------------------------------------------------------
// Stable ID: aa_006ed750
// Address:   0x006ed750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ed750 @ 0x006ed750
// Stable ID: aa_006ed750
// Embedded strings (evidence for future rename):
//   - "LthkBvAgent"
//   - "Stchild"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: rdtsc×3, FUN_006ed750.
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

void __thiscall FUN_006ed750(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3,int *param_4)



{

  uint64_t uVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  char unaff_BP;

  uint32_t /* width from decompiler */ unaff_retaddr;

  undefined **local_18;

  uint local_14;

  uint32_t /* width from decompiler */ local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LthkBvAgent";

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_8 = param_2[2];

  iVar2 = *param_2;

  local_4 = param_2;

  local_c = param_2[1];

  local_10 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xc);

  local_18 = &PTR_LAB_00a0e9d0;

  local_14 = local_14 & 0xffffff00;

  (**(code **)(**(int **)(param_1 + 0xc) + 4))(&local_10,param_3,param_4,&local_18);

  if (unaff_BP == '\0') {

    if (*(int **)(param_1 + 0x10) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x10) + 0x14))();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    }

  }

  else {

    if (DAT_00bc5644 < DAT_00bc5648) {

      *DAT_00bc5644 = "Stchild";

      uVar1 = rdtsc();

      local_c = (int)uVar1;

      DAT_00bc5644[1] = local_c;

      DAT_00bc5644 = DAT_00bc5644 + 3;

    }

    if (*(int *)(param_1 + 0x10) == 0) {

      local_4 = *(int **)(param_1 + 8);

      local_c = *param_4;

      iVar2 = (**(code **)(**(int **)(iVar2 + 0x10) + 0x14))();

      iVar3 = (**(code **)(*(int *)*param_3 + 0x14))();

      uVar4 = (**(code **)(local_c + 0x18c + (iVar2 * 0x20 + iVar3) * 4))

                        (&stack0xffffffe0,param_3,param_4,local_4);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = uVar4;

    }

    (**(code **)(**(int **)(param_1 + 0x10) + 0x10))(&stack0xffffffe0,param_3,param_4,unaff_retaddr)

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
