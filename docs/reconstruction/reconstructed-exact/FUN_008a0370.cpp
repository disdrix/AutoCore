// =============================================================================
// FUN_008a0370
// -----------------------------------------------------------------------------
// Stable ID: aa_008a0370
// Address:   0x008a0370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a0370 @ 0x008a0370
// Stable ID: aa_008a0370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_008a0370.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_008a0370(void)



{

  int *piVar1;

  int *piVar2;

  int in_EAX;

  int iVar3;

  int iVar4;

  int iVar5;

  uint8_t *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  float fVar8;

  uint8_t *puStack_50;

  int iStack_4c;

  uint8_t *puStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  int iStack_40;

  uint8_t auStack_24 [4];

  uint8_t local_20 [4];

  uint8_t auStack_1c [20];

  uint8_t local_8 [8];

  

  if (*(int *)(in_EAX + 0x684) != 0) {

    if ((*(char *)(in_EAX + 0x520) == '\0') || (*(int *)(in_EAX + 0x664) == 0)) {

      if (*(int *)(in_EAX + 0x624) == 0) {

        return;

      }

      fVar8 = (float)DAT_00d1e81c * DAT_00aaa7b8;

      piVar1 = *(int **)(in_EAX + 0x684);

      iStack_40 = 0;

      uStack_44 = 1;

      puStack_48 = local_8;

      iStack_4c = 0x8a0453;

      iVar3 = (**(code **)(**(int **)(in_EAX + 0x624) + 0x120))();

      iStack_4c = 1;

      puStack_50 = auStack_1c;

      iVar5 = (**(code **)(*piVar1 + 0x140))();

      puVar6 = &stack0xffffffcc;

      iVar3 = (*(int *)(iVar3 + 4) - *(int *)(iVar5 + 4)) + (int)fVar8;

    }

    else {

      fVar8 = (float)DAT_00d1e81c * _DAT_00aaa7e0;

      piVar1 = *(int **)(in_EAX + 0x664);

      piVar2 = *(int **)(in_EAX + 0x684);

      iStack_40 = 0;

      uStack_44 = 1;

      puStack_48 = local_20;

      iStack_4c = 0x8a03d3;

      (**(code **)(**(int **)(in_EAX + 0x624) + 0x120))();

      iStack_4c = 1;

      puStack_50 = auStack_24;

      iVar3 = (**(code **)(*piVar1 + 0x140))();

      iVar3 = *(int *)(iVar3 + 4);

      iVar5 = *(int *)(iStack_40 + 4);

      iVar4 = (**(code **)(*piVar2 + 0x140))(auStack_24,1);

      puVar6 = auStack_24;

      iVar3 = ((iVar5 - iVar3 / 2) - *(int *)(iVar4 + 4)) + (int)fVar8;

    }

    puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(in_EAX + 0x684) + 0x120))(puVar6,1,0);

    puStack_50 = (uint8_t *)*puVar7;

    iStack_4c = iVar3;

    (**(code **)(**(int **)(in_EAX + 0x684) + 0x118))(&puStack_50);

  }

  return;

}
