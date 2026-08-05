// =============================================================================
// FUN_008279b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008279b0
// Address:   0x008279b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008279b0 @ 0x008279b0
// Stable ID: aa_008279b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×1.
//  - Notable callees: FUN_00826f90, FUN_008279b0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_008279b0(char param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  int iVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char acStack_104 [8];

  uint8_t auStack_fc [252];

  

  if (((*(int *)(in_EAX + 0x564) != 0) &&

      (iVar3 = (**(code **)(**(int **)(in_EAX + 0x564) + 700))(), iVar3 != 0)) &&

     (*(int *)(in_EAX + 0x548) == 1)) {

    (**(code **)(**(int **)(in_EAX + 0x564) + 0x58))();

    pcVar4 = (char *)(in_EAX + 0x580);

    iVar3 = -(int)pcVar4;

    do {

      cVar1 = *pcVar4;

      pcVar4[(int)(acStack_104 + iVar3)] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    puVar2 = (uint32_t /* width from decompiler */ *)&stack0xfffffefb;

    if (param_1 == '\0') {

      do {

        puVar6 = puVar2;

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      } while (*(char *)((int)puVar6 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar6 + 1) = DAT_00a74e8c;

      *(uint32_t /* width from decompiler */ *)((int)puVar6 + 5) = DAT_00a74e90;

      *(uint8_t *)((int)puVar6 + 9) = DAT_00a74e94;

    }

    else {

      do {

        puVar6 = puVar2;

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      } while (*(char *)((int)puVar6 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar6 + 1) = DAT_00a74e98;

      *(uint32_t /* width from decompiler */ *)((int)puVar6 + 5) = _DAT_00a74e9c;

    }

    iVar3 = **(int **)(in_EAX + 0x564);

    uVar5 = (**(code **)(**(int **)(in_EAX + 0x564) + 0x2c8))(0);

    (**(code **)(iVar3 + 0x50))(acStack_104,uVar5);

    FUN_00826f90();

    (**(code **)(**(int **)(in_EAX + 0x564) + 0x34c))();

  }

  return;

}
