// =============================================================================
// FUN_00744170
// -----------------------------------------------------------------------------
// Stable ID: aa_00744170
// Address:   0x00744170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00744170 @ 0x00744170
// Stable ID: aa_00744170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×6, while×5, return×1.
//  - Notable callees: FUN_00426f60×2, FUN_00744170×2, FUN_00436ef0, FUN_0043bfb0.
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

void __thiscall FUN_00744170(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint local_c;

  

  FUN_00426f60();

  puVar5 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 0x14))[1];

  cVar1 = *(char *)((int)puVar5 + 0x25);

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x14);

  while (cVar1 == '\0') {

    if ((uint)puVar5[3] < local_c) {

      puVar4 = (uint32_t /* width from decompiler */ *)puVar5[2];

      puVar5 = puVar3;

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)*puVar5;

    }

    puVar3 = puVar5;

    puVar5 = puVar4;

    cVar1 = *(char *)((int)puVar4 + 0x25);

  }

  FUN_00426f60();

  param_2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x14);

  cVar1 = *(char *)((int)param_2[1] + 0x25);

  puVar5 = (uint32_t /* width from decompiler */ *)param_2[1];

  while (cVar1 == '\0') {

    if (local_c < (uint)puVar5[3]) {

      puVar4 = (uint32_t /* width from decompiler */ *)*puVar5;

      param_2 = puVar5;

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)puVar5[2];

    }

    puVar5 = puVar4;

    cVar1 = *(char *)((int)puVar4 + 0x25);

  }

  while (puVar3 != param_2) {

    if ((char)param_4 == '\0') {

      FUN_00744170(puVar3 + 6,param_3,0);

    }

    iVar2 = *(int *)(param_3 + 4);

    if ((iVar2 == 0) ||

       ((uint)(*(int *)(param_3 + 0xc) - iVar2 >> 2) <= (uint)(*(int *)(param_3 + 8) - iVar2 >> 2)))

    {

      FUN_0043bfb0(*(uint32_t /* width from decompiler */ *)(param_3 + 8),1,puVar3 + 6);

    }

    else {

      iVar2 = *(int *)(param_3 + 8);

      FUN_00436ef0(param_4);

      *(int *)(param_3 + 8) = iVar2 + 4;

    }

    if (*(char *)((int)puVar3 + 0x25) == '\0') {

      puVar5 = (uint32_t /* width from decompiler */ *)puVar3[2];

      if (*(char *)((int)puVar5 + 0x25) == '\0') {

        cVar1 = *(char *)((int)*puVar5 + 0x25);

        puVar3 = puVar5;

        puVar5 = (uint32_t /* width from decompiler */ *)*puVar5;

        while (cVar1 == '\0') {

          cVar1 = *(char *)((int)*puVar5 + 0x25);

          puVar3 = puVar5;

          puVar5 = (uint32_t /* width from decompiler */ *)*puVar5;

        }

      }

      else {

        cVar1 = *(char *)((int)puVar3[1] + 0x25);

        puVar4 = (uint32_t /* width from decompiler */ *)puVar3[1];

        puVar5 = puVar3;

        while ((puVar3 = puVar4, cVar1 == '\0' && (puVar5 == (uint32_t /* width from decompiler */ *)puVar3[2]))) {

          cVar1 = *(char *)((int)puVar3[1] + 0x25);

          puVar4 = (uint32_t /* width from decompiler */ *)puVar3[1];

          puVar5 = puVar3;

        }

      }

    }

  }

  return;

}
