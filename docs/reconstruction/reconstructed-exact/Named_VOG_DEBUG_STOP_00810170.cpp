// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00571d80×2, FUN_007a4480×2, Client_RefreshOpenMissionUiWindows, FUN_00513e70, FUN_00810170, FUN_0092ce90, FUN_00933310.
//  - Strings: "VOG_DEBUG_STOP"; "Error: Had more than 1 of a non-stackable item: COID:%I64d".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00810170
// -----------------------------------------------------------------------------
// Stable ID: aa_00810170
// Address:   0x00810170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_VOG_DEBUG_STOP_00810170(void)



{

  char cVar1;

  int in_EAX;

  int *piVar2;

  int iVar3;

  int unaff_ESI;

  

  if (((*(int *)(in_EAX + 0xe98) != 0) && (*(int *)(*(int *)(in_EAX + 0xe98) + 0x250) != 0)) &&

     (piVar2 = (int *)CVOGReaction_ResolveObjectTarget

                                (1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc)),

     piVar2 != (int *)0x0)) {

    if (*(char *)(unaff_ESI + 0x14) == '\0') {

      cVar1 = FUN_00513e70();

      if (cVar1 == '\0') {

        FUN_007a4480(0,"VOG_DEBUG_STOP");

        FUN_007a4480(1,"Error: Had more than 1 of a non-stackable item: COID:%I64d",

                     *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc));

      }

      else {

        (**(code **)(*piVar2 + 0x260))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10));

      }

    }

    else {

      iVar3 = FUN_00571d80(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc),1);

      if ((iVar3 != 0) ||

         (iVar3 = FUN_00571d80(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc),1),

         iVar3 != 0)) {

        FUN_00933310(in_EAX,1,0,0xffffffff,0xffffffff);

      }

    }

    Client_RefreshOpenMissionUiWindows(in_EAX);

    FUN_0092ce90();

    if (*(int *)(in_EAX + 0x309c) != 0) {

      (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);

    }

  }

  return;

}
