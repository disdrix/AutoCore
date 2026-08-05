// =============================================================================
// FUN_005fcce0
// -----------------------------------------------------------------------------
// Stable ID: aa_005fcce0
// Address:   0x005fcce0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fcce0 @ 0x005fcce0
// Stable ID: aa_005fcce0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~139 non-empty decompiler lines.
//  - Control keywords: if×18, do×1, while×1, return×1.
//  - Notable callees: FUN_004f5560×10, FUN_005b3300×8, CONCAT31, FUN_004f5550, FUN_005fcce0.
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

void FUN_005fcce0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int *piVar1;

  bool bVar2;

  char cVar3;

  char cVar4;

  uint uVar5;

  int iVar6;

  char cVar7;

  int iVar8;

  float10 fVar9;

  uint local_1c;

  

  cVar3 = FUN_004f5560();

  iVar8 = (int)cVar3;

  uVar5 = *(uint *)(param_3 + 0xc) & 0x7fffffff;

  if ((int)uVar5 < iVar8) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar8) {

      iVar6 = iVar8;

    }

    FUN_005b3300((int *)(param_3 + 4),iVar6,4);

  }

  *(int *)(param_3 + 8) = iVar8;

  cVar3 = FUN_004f5560();

  iVar8 = (int)cVar3;

  uVar5 = *(uint *)(param_3 + 0x18) & 0x7fffffff;

  if ((int)uVar5 < iVar8) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar8) {

      iVar6 = iVar8;

    }

    FUN_005b3300((int *)(param_3 + 0x10),iVar6,4);

  }

  *(int *)(param_3 + 0x14) = iVar8;

  cVar3 = FUN_004f5560();

  iVar8 = (int)cVar3;

  uVar5 = *(uint *)(param_3 + 0x24) & 0x7fffffff;

  if ((int)uVar5 < iVar8) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar8) {

      iVar6 = iVar8;

    }

    FUN_005b3300((int *)(param_3 + 0x1c),iVar6,4);

  }

  *(int *)(param_3 + 0x20) = iVar8;

  cVar3 = FUN_004f5560();

  iVar8 = (int)cVar3;

  piVar1 = (int *)(param_3 + 0x28);

  uVar5 = *(uint *)(param_3 + 0x30) & 0x7fffffff;

  if ((int)uVar5 < iVar8) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar8) {

      iVar6 = iVar8;

    }

    FUN_005b3300(piVar1,iVar6,4);

  }

  *(int *)(param_3 + 0x2c) = iVar8;

  cVar3 = FUN_004f5560();

  iVar8 = (int)cVar3;

  uVar5 = *(uint *)(param_3 + 0x3c) & 0x7fffffff;

  if ((int)uVar5 < iVar8) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar8) {

      iVar6 = iVar8;

    }

    FUN_005b3300((int *)(param_3 + 0x34),iVar6,4);

  }

  *(int *)(param_3 + 0x38) = iVar8;

  cVar3 = FUN_004f5560();

  iVar8 = (int)cVar3;

  uVar5 = *(uint *)(param_3 + 0x60) & 0x7fffffff;

  if ((int)uVar5 < iVar8) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar8) {

      iVar6 = iVar8;

    }

    FUN_005b3300((int *)(param_3 + 0x58),iVar6,4);

  }

  *(int *)(param_3 + 0x5c) = iVar8;

  cVar3 = FUN_004f5560();

  iVar8 = (int)cVar3;

  uVar5 = *(uint *)(param_3 + 0x48) & 0x7fffffff;

  if ((int)uVar5 < iVar8) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar8) {

      iVar6 = iVar8;

    }

    FUN_005b3300((int *)(param_3 + 0x40),iVar6,4);

  }

  *(int *)(param_3 + 0x44) = iVar8;

  cVar3 = FUN_004f5560();

  iVar8 = (int)cVar3;

  uVar5 = *(uint *)(param_3 + 0x54) & 0x7fffffff;

  if ((int)uVar5 < iVar8) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar8) {

      iVar6 = iVar8;

    }

    FUN_005b3300((int *)(param_3 + 0x4c),iVar6,4);

  }

  *(int *)(param_3 + 0x50) = iVar8;

  cVar3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 600) + 4) + 4) + 0xac +

                                     *(int *)(param_1 + 600)) + 0x3c) + 0x4cc);

  cVar7 = '\0';

  local_1c = local_1c & 0xffffff00;

  cVar4 = FUN_004f5560();

  if ('\0' < cVar4) {

    do {

      iVar6 = (int)cVar7;

      iVar8 = iVar6 * 4;

      *(uint32_t /* width from decompiler */ *)(iVar8 + *(int *)(param_3 + 0x58)) = DAT_00aaa7a4;

      *(uint32_t /* width from decompiler */ *)(iVar8 + *(int *)(param_3 + 0x10)) =

           *(uint32_t /* width from decompiler */ *)

            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x600

            + iVar6 * 4);

      *(uint32_t /* width from decompiler */ *)(iVar8 + *(int *)(param_3 + 0x1c)) =

           *(uint32_t /* width from decompiler */ *)

            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x618

            + iVar6 * 4);

      iVar6 = *piVar1;

      bVar2 = cVar7 < cVar3;

      fVar9 = (float10)FUN_004f5550(local_1c);

      *(float *)(iVar6 + iVar8) = (float)fVar9;

      if (!bVar2) {

        *(float *)(iVar8 + *piVar1) =

             *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                0x3c) + 0x740) * *(float *)(iVar8 + *piVar1);

      }

      *(float *)(iVar8 + *(int *)(param_3 + 0x40)) = *(float *)(iVar8 + *piVar1) * DAT_00aaa68c;

      *(uint32_t /* width from decompiler */ *)(iVar8 + *(int *)(param_3 + 0x4c)) = DAT_00a0f718;

      *(float *)(iVar8 + *(int *)(param_3 + 0x34)) = g_flMsToSeconds_Inferred;

      cVar7 = cVar7 + '\x01';

      local_1c = CONCAT31(local_1c._1_3_,cVar7);

      *(uint *)(iVar8 + *(int *)(param_3 + 4)) = (uint)bVar2;

      cVar4 = FUN_004f5560();

    } while (cVar7 < cVar4);

  }

  return;

}
