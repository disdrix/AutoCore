// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×5, for×2, while×2, do×1, return×1.
//  - Notable callees: fwrite×6, FUN_007a4480×4, FUN_004d0410.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_004d0410
// -----------------------------------------------------------------------------
// Stable ID: aa_004d0410
// Address:   0x004d0410  (autoassault.exe, image base 0x400000)
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

void __thiscall Named_VOG_DEBUG_STOP_004d0410(int param_1,FILE *param_2)



{

  char *pcVar1;

  char cVar2;

  FILE *_File;

  char *pcVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ local_4;

  

  _File = param_2;

  local_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe5c8) + 0xc);

  iVar4 = 0;

  fwrite(&local_4,4,1,param_2);

  iVar5 = *(int *)(param_1 + 0xe5c8);

  if (*(char *)(iVar5 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar5 + 0x1d) = 1;

  while( true ) {

    iVar5 = *(int *)(param_1 + 0xe5c8);

    if (*(char *)(iVar5 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar5 + 0x14);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

    }

    if (iVar4 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(iVar4 + 8);

    }

    if (iVar5 == 0) break;

    fwrite((void *)(iVar5 + 4),4,1,_File);

    fwrite((void *)(iVar5 + 8),4,1,_File);

    fwrite((void *)(iVar5 + 0xc),1,1,_File);

    pcVar3 = *(char **)(iVar5 + 0x10);

    pcVar1 = pcVar3 + 1;

    do {

      cVar2 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar2 != '\0');

    param_2 = (FILE *)(pcVar3 + -(int)pcVar1);

    fwrite(&param_2,4,1,_File);

    fwrite(*(void **)(iVar5 + 0x10),1,(size_t)param_2,_File);

  }

  *(uint8_t *)(*(int *)(param_1 + 0xe5c8) + 0x1d) = 0;

  return;

}
