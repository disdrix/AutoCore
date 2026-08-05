// =============================================================================
// FUN_006ed8c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006ed8c0
// Address:   0x006ed8c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ed8c0 @ 0x006ed8c0
// Stable ID: aa_006ed8c0
// Embedded strings (evidence for future rename):
//   - "LthkBvAgent"
//   - "Stchild"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: rdtsc×3, FUN_006ed8c0.
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

void __thiscall

FUN_006ed8c0(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3,int *param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  uint64_t uVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  int local_58;

  uint32_t /* width from decompiler */ local_50;

  int local_4c;

  int local_48;

  int *local_44;

  undefined **local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint8_t local_38;

  uint32_t /* width from decompiler */ local_24;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LthkBvAgent";

    uVar2 = rdtsc();

    local_58 = (int)uVar2;

    DAT_00bc5644[1] = local_58;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_48 = param_2[2];

  iVar1 = *param_2;

  local_44 = param_2;

  local_4c = param_2[1];

  local_50 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

  local_40 = &PTR_LAB_00a0e9d8;

  local_38 = 0;

  local_24 = 0x7f7fffff;

  local_3c = 0x7f7fffff;

  (**(code **)(**(int **)(param_1 + 0xc) + 0xc))(&local_50,param_3,param_4,&local_40,&local_40);

  if ((char)local_4c == '\0') {

    if (*(int **)(param_1 + 0x10) != (int *)0x0) {

      (**(code **)(**(int **)(param_1 + 0x10) + 0x14))();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    }

  }

  else {

    if (DAT_00bc5644 < DAT_00bc5648) {

      *DAT_00bc5644 = "Stchild";

      uVar2 = rdtsc();

      DAT_00bc5644[1] = (int)uVar2;

      DAT_00bc5644 = DAT_00bc5644 + 3;

    }

    uStack_60 = *(uint32_t /* width from decompiler */ *)(local_58 + 4);

    piStack_64 = *(int **)(iVar1 + 0x10);

    if (*(int *)(param_1 + 0x10) == 0) {

      uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

      iVar1 = *param_4;

      iVar3 = (**(code **)(*piStack_64 + 0x14))();

      iVar4 = (**(code **)(*(int *)*param_3 + 0x14))();

      uVar5 = (**(code **)(iVar1 + 0x18c + (iVar3 * 0x20 + iVar4) * 4))

                        (&piStack_64,param_3,param_4,uVar5);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = uVar5;

    }

    (**(code **)(**(int **)(param_1 + 0x10) + 0xc))(&piStack_64,param_3,param_4,param_5,param_6);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar2 = rdtsc();

    DAT_00bc5644[1] = (int)uVar2;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
