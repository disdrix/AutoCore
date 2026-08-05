// =============================================================================
// FUN_004f8b80
// -----------------------------------------------------------------------------
// Stable ID: aa_004f8b80
// Address:   0x004f8b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f8b80 @ 0x004f8b80
// Stable ID: aa_004f8b80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, return×2, do×1.
//  - Notable callees: FUN_004022a0×2, LeaveCriticalSection×2, FUN_004294f0, FUN_004f8b80.
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

uint32_t /* width from decompiler */ * __fastcall FUN_004f8b80(int param_1)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int iStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  int local_4;

  

  iVar5 = 0;

  local_4 = param_1;

  do {

    piVar1 = *(int **)(*(int *)(local_4 + 0x260) + iVar5);

    if ((((piVar1 != (int *)0x0) && (cVar3 = (**(code **)(*piVar1 + 0x40))(), cVar3 != '\0')) &&

        (iVar2 = piVar1[0x4f], iVar2 != 0)) && (*(int *)(iVar2 + 0x24) != 0)) {

      uStack_8 = 0;

      iStack_c = 0;

      FUN_004294f0();

      iVar4 = FUN_004022a0(&uStack_8,&iStack_c);

      while (iVar4 == 0) {

        iVar4 = *(int *)(iStack_c + 4);

        if (iVar4 != 0) {

          if (*(char *)(iVar2 + 0x28) != '\0') {

            *(uint8_t *)(iVar2 + 0x28) = 0;

            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 4));

          }

          return (uint32_t /* width from decompiler */ *)(iVar4 + 0x160);

        }

        iVar4 = FUN_004022a0(&uStack_8,&iStack_c);

      }

      if (*(char *)(iVar2 + 0x28) != '\0') {

        *(uint8_t *)(iVar2 + 0x28) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 4));

      }

    }

    iVar5 = iVar5 + 4;

  } while (iVar5 < 0xc);

  return &DAT_009cd0f8;

}
