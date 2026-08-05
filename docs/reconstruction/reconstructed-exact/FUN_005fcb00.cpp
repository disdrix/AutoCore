// =============================================================================
// FUN_005fcb00
// -----------------------------------------------------------------------------
// Stable ID: aa_005fcb00
// Address:   0x005fcb00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fcb00 @ 0x005fcb00
// Stable ID: aa_005fcb00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, return×1.
//  - Notable callees: FUN_004f5560×6, FUN_005b3300×3, FUN_005fcb00.
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

void FUN_005fcb00(int param_1,uint32_t /* width from decompiler */ param_2,uint8_t *param_3)



{

  int *piVar1;

  int *piVar2;

  char cVar3;

  uint8_t uVar4;

  int iVar5;

  byte bVar6;

  int iVar7;

  uint uVar8;

  int *piVar9;

  

  cVar3 = FUN_004f5560();

  iVar7 = (int)cVar3;

  piVar1 = (int *)(param_3 + 4);

  if ((int)(*(uint *)(param_3 + 0xc) & 0x7fffffff) < iVar7) {

    iVar5 = (*(uint *)(param_3 + 0xc) & 0x7fffffff) * 2;

    if (iVar5 <= iVar7) {

      iVar5 = iVar7;

    }

    FUN_005b3300(piVar1,iVar5,4);

  }

  *(int *)(param_3 + 8) = iVar7;

  cVar3 = FUN_004f5560();

  iVar7 = (int)cVar3;

  piVar2 = (int *)(param_3 + 0x10);

  if ((int)(*(uint *)(param_3 + 0x18) & 0x7fffffff) < iVar7) {

    iVar5 = (*(uint *)(param_3 + 0x18) & 0x7fffffff) * 2;

    if (iVar5 <= iVar7) {

      iVar5 = iVar7;

    }

    FUN_005b3300(piVar2,iVar5,4);

  }

  *(int *)(param_3 + 0x14) = iVar7;

  cVar3 = FUN_004f5560();

  iVar7 = (int)cVar3;

  piVar9 = (int *)(param_3 + 0x20);

  if ((int)(*(uint *)(param_3 + 0x28) & 0x7fffffff) < iVar7) {

    iVar5 = (*(uint *)(param_3 + 0x28) & 0x7fffffff) * 2;

    if (iVar5 <= iVar7) {

      iVar5 = iVar7;

    }

    FUN_005b3300(piVar9,iVar5,1);

  }

  *(int *)(param_3 + 0x24) = iVar7;

  uVar4 = FUN_004f5560();

  *param_3 = uVar4;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x1c) = 0;

  bVar6 = *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 600) + 4) + 4) + 0xac +

                                     *(int *)(param_1 + 600)) + 0x3c) + 0x4cc);

  uVar8 = 0;

  if ('\0' < (char)bVar6) {

    uVar8 = (uint)bVar6;

    iVar7 = 0;

    param_3 = (uint8_t *)uVar8;

    do {

      *(float *)(*piVar1 + iVar7 * 4) =

           *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c

                              ) + 0x57c) * *(float *)(param_1 + 0x200);

      *(byte *)(iVar7 + *piVar9) =

           *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)

                    + 0x5f0) & 1;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + iVar7 * 4) =

           *(uint32_t /* width from decompiler */ *)

            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x58c

            );

      iVar7 = iVar7 + 1;

      param_3 = (uint8_t *)((int)param_3 - 1);

    } while (param_3 != (uint8_t *)0x0);

  }

  cVar3 = FUN_004f5560();

  if ((char)uVar8 < cVar3) {

    do {

      iVar7 = (int)(char)uVar8;

      *(float *)(*piVar1 + iVar7 * 4) =

           *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c

                              ) + 0x580) * *(float *)(param_1 + 0x204);

      bVar6 = (char)uVar8 + 1;

      uVar8 = (uint)bVar6;

      *(byte *)(iVar7 + *piVar9) =

           *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)

                    + 0x5f0) >> 1 & 1;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + iVar7 * 4) =

           *(uint32_t /* width from decompiler */ *)

            (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x590

            );

      cVar3 = FUN_004f5560();

    } while ((char)bVar6 < cVar3);

  }

  return;

}
