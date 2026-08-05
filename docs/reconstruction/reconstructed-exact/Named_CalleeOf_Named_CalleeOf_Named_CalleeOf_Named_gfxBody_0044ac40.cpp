// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_0044ac40
// -----------------------------------------------------------------------------
// Stable ID: aa_0044ac40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
// Address:   0x0044ac40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×10, return×8.
//  - Notable callees: FUN_00439670×2, FUN_0043a760×2, FUN_0043ab60×2, FUN_0045c230×2, FUN_0044ac40, FUN_0044ae60, FUN_0044aeb0.
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxBody
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody_0044ac40(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  uint uVar7;

  int unaff_ESI;

  

  if (unaff_ESI == in_EAX) {

    return;

  }

  iVar1 = *(int *)(in_EAX + 4);

  if (iVar1 != 0) {

    iVar6 = *(int *)(in_EAX + 8) - iVar1;

    iVar5 = iVar6 >> 0x1f;

    iVar6 = iVar6 / 0x14 + iVar5;

    uVar7 = iVar6 - iVar5;

    if (iVar6 != iVar5) {

      iVar5 = *(int *)(unaff_ESI + 4);

      if (iVar5 == 0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)(unaff_ESI + 8) - iVar5) / 0x14;

      }

      if (uVar7 <= uVar3) {

        uVar4 = FUN_0043a760(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),param_1);

        FUN_00439670(uVar4,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

        if (*(int *)(in_EAX + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4);

          return;

        }

        *(int *)(unaff_ESI + 8) =

             *(int *)(unaff_ESI + 4) + ((*(int *)(in_EAX + 8) - *(int *)(in_EAX + 4)) / 0x14) * 0x14

        ;

        return;

      }

      if (iVar5 == 0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)(unaff_ESI + 0xc) - iVar5) / 0x14;

      }

      if (uVar3 < uVar7) {

        if (iVar5 != 0) {

          FUN_00439670(iVar5,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)(unaff_ESI + 4));

        }

        uVar4 = FUN_0045c230();

        cVar2 = FUN_0044ae60(uVar4);

        if (cVar2 == '\0') {

          return;

        }

        uVar4 = FUN_0043ab60(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 4),param_1);

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar4;

        return;

      }

      iVar5 = FUN_0045c230();

      iVar1 = iVar1 + iVar5 * 0x14;

      FUN_0043a760(iVar1,iVar1);

      uVar4 = FUN_0043ab60(*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),iVar1);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar4;

      return;

    }

  }

  FUN_0044aeb0();

  return;

}
