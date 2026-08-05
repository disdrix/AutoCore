// =============================================================================
// FUN_004de350
// -----------------------------------------------------------------------------
// Stable ID: aa_004de350
// Address:   0x004de350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004de350 @ 0x004de350
// Stable ID: aa_004de350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×2, goto×1.
//  - Notable callees: FUN_004e2a90×2, FUN_004e2ae0×2, CONCAT31, CVOGReaction_RandomUnitScalar, FUN_004db820, FUN_004de350, FUN_004e53a0, FUN_00540550.
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

void __thiscall FUN_004de350(int param_1,int param_2)



{

  ushort uVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  byte *pbVar5;

  int iVar6;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  

  iVar4 = *(int *)(*(int *)(param_2 + 4) + 4);

  local_28 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164 + param_2);

  local_24 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168 + param_2);

  local_20 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe6d8);

  local_1c = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe6dc);

  if (*(int *)(param_2 + 0x7c) == 0) {

    iVar6 = 0;

    pbVar5 = (byte *)(param_2 + 0x80);

    iVar4 = 7;

    do {

      iVar6 = iVar6 + (uint)*pbVar5;

      pbVar5 = pbVar5 + 1;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

    iVar6 = iVar6 + (uint)*(byte *)(param_2 + 0x87);

    if (0 < iVar6) {

      iVar4 = CVOGReaction_RandomUnitScalar();

      if (0xfffff < *(int *)(iVar4 + 0xc)) {

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

      }

      uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

      *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

      iVar4 = 0;

      cVar3 = '\0';

      do {

        iVar4 = iVar4 + (uint)*(byte *)(cVar3 + 0x80 + param_2);

        if ((int)((longlong)(ulonglong)uVar1 % (longlong)iVar6) < iVar4) {

          if (cVar3 != -1) {

            iVar4 = FUN_00540550(*(uint8_t *)(*(int *)(param_1 + 0xe4f8) + 0x1c),(int)cVar3);

            goto LAB_004de49b;

          }

          break;

        }

        cVar3 = cVar3 + '\x01';

      } while (cVar3 < '\a');

    }

  }

  else if (*(int *)(param_2 + 0x7c) == 1) {

    iVar4 = FUN_004e53a0(*(uint32_t /* width from decompiler */ *)(param_2 + 0x88));

LAB_004de49b:

    if (iVar4 != 0) {

      FUN_004db820(param_2 + 0x8c,param_2);

      local_18 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x1c);

      iVar4 = *(int *)(param_1 + 0xe714);

      iVar6 = FUN_004e2a90(iVar4,*(uint32_t /* width from decompiler */ *)(iVar4 + 4),&local_28);

      FUN_004e2ae0(1);

      *(int *)(iVar4 + 4) = iVar6;

      piVar2 = *(int **)(iVar6 + 4);

      *piVar2 = iVar6;

      iVar4 = *(int *)(*(int *)(param_2 + 4) + 4);

      local_40 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x84 + param_2);

      iVar4 = iVar4 + 0x84 + param_2;

      local_3c = *(uint32_t /* width from decompiler */ *)(iVar4 + 4);

      local_38 = *(uint32_t /* width from decompiler */ *)(iVar4 + 8);

      local_34 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc);

      FUN_005ea300(param_1,&local_40,

                   CONCAT31((int3)((uint)piVar2 >> 8),

                            *(uint8_t *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0x17c + param_2)))

      ;

      return;

    }

  }

  iVar4 = *(int *)(param_1 + 0xe714);

  local_18 = 0xffffffff;

  iVar6 = FUN_004e2a90(iVar4,*(uint32_t /* width from decompiler */ *)(iVar4 + 4),&local_28);

  FUN_004e2ae0(1);

  *(int *)(iVar4 + 4) = iVar6;

  **(int **)(iVar6 + 4) = iVar6;

  return;

}
