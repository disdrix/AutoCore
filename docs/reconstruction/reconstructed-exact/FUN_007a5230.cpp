// =============================================================================
// FUN_007a5230
// -----------------------------------------------------------------------------
// Stable ID: aa_007a5230
// Address:   0x007a5230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a5230 @ 0x007a5230
// Stable ID: aa_007a5230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: strncpy×2, CONCAT31, FUN_00456960, FUN_007871c0, FUN_007a5230.
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

void __thiscall FUN_007a5230(int *param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *piVar3;

  ushort uVar4;

  void *pvVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  (**(code **)(*param_1 + 4))();

  uVar4 = 0;

  if (*(short *)(param_2 + 4) != 0) {

    do {

      puVar7 = (uint32_t /* width from decompiler */ *)((uint)uVar4 * 0x200 + param_2 + 8);

      pvVar5 = operator_new(0x250);

      if (pvVar5 == (void *)0x0) {

        iVar6 = 0;

      }

      else {

        iVar6 = FUN_007871c0();

      }

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x1f0) = puVar7[0x7a];

      *(uint32_t /* width from decompiler */ *)(iVar6 + 500) = puVar7[0x7b];

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x200) = *puVar7;

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x204) = puVar7[1];

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x1e8) = puVar7[0x78];

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x1ec) = puVar7[0x79];

      *(char *)(iVar6 + 0x32) = '\0';

      if ((char *)((int)puVar7 + 0x3a) != (char *)0x0) {

        strncpy((char *)(iVar6 + 0x32),(char *)((int)puVar7 + 0x3a),399);

        *(uint8_t *)(iVar6 + 0x1c1) = 0;

      }

      *(char *)(iVar6 + 0x1c2) = '\0';

      if ((char *)((int)puVar7 + 0x1ca) != (char *)0x0) {

        strncpy((char *)(iVar6 + 0x1c2),(char *)((int)puVar7 + 0x1ca),0x10);

        *(uint8_t *)(iVar6 + 0x1d2) = 0;

      }

      uVar1 = puVar7[0x7e];

      *(uint32_t /* width from decompiler */ *)(iVar6 + 0x21c) = uVar1;

      (**(code **)(*param_1 + 0x5c))

                (iVar6,puVar7 + 2,CONCAT31((int3)((uint)uVar1 >> 8),*(uint8_t *)(puVar7 + 0x7c)))

      ;

      iVar2 = param_1[2];

      if ((iVar2 == 0) || ((uint)(param_1[4] - iVar2 >> 2) <= (uint)(param_1[3] - iVar2 >> 2))) {

        FUN_00456960(param_1[3]);

      }

      else {

        piVar3 = (int *)param_1[3];

        *piVar3 = iVar6;

        param_1[3] = (int)(piVar3 + 1);

      }

      uVar4 = uVar4 + 1;

    } while (uVar4 < *(ushort *)(param_2 + 4));

  }

  return;

}
