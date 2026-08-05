// =============================================================================
// FUN_004510e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004510e0
// Address:   0x004510e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004510e0 @ 0x004510e0
// Stable ID: aa_004510e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×11, return×8.
//  - Notable callees: FUN_00480c80×2, FUN_004510e0, FUN_004523a0, FUN_00455b60, FUN_00455b80, FUN_0057fb40.
//  - Return sites: 8.

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

void __fastcall FUN_004510e0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  void *pvVar2;

  char cVar3;

  uint uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint uVar8;

  int unaff_EBX;

  int unaff_ESI;

  

  if (unaff_ESI == unaff_EBX) {

    return;

  }

  iVar1 = *(int *)(unaff_EBX + 4);

  if (iVar1 != 0) {

    iVar7 = *(int *)(unaff_EBX + 8) - iVar1;

    iVar5 = iVar7 >> 0x1f;

    iVar7 = iVar7 / 0xc + iVar5;

    uVar8 = iVar7 - iVar5;

    if (iVar7 != iVar5) {

      pvVar2 = *(void **)(unaff_ESI + 4);

      if (pvVar2 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = (*(int *)(unaff_ESI + 8) - (int)pvVar2) / 0xc;

      }

      if (uVar8 <= uVar4) {

        FUN_0057fb40(iVar1,*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),pvVar2,param_1);

        if (*(int *)(unaff_EBX + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4);

          return;

        }

        *(int *)(unaff_ESI + 8) =

             *(int *)(unaff_ESI + 4) +

             ((*(int *)(unaff_EBX + 8) - *(int *)(unaff_EBX + 4)) / 0xc) * 0xc;

        return;

      }

      if (pvVar2 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = (*(int *)(unaff_ESI + 0xc) - (int)pvVar2) / 0xc;

      }

      if (uVar4 < uVar8) {

        if (pvVar2 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar2);

        }

        uVar6 = FUN_00480c80();

        cVar3 = FUN_004523a0(uVar6);

        if (cVar3 == '\0') {

          return;

        }

        uVar6 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4);

        iVar5 = *(int *)(unaff_EBX + 4);

      }

      else {

        iVar5 = FUN_00480c80();

        iVar5 = iVar1 + iVar5 * 0xc;

        FUN_00455b60(iVar1,iVar5,pvVar2);

        uVar6 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8);

      }

      uVar6 = FUN_00455b80(iVar5,*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),uVar6);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar6;

      return;

    }

  }

  if (*(void **)(unaff_ESI + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 4));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  return;

}
