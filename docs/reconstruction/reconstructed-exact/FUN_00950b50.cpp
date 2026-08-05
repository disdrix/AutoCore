// =============================================================================
// FUN_00950b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00950b50
// Address:   0x00950b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00950b50 @ 0x00950b50
// Stable ID: aa_00950b50
// Embedded strings (evidence for future rename):
//   - "Checking heap..."
//   - "done.\n"
//   - "VALIDATE_OBJECT_LIST starting...\n"
//   - "VALIDATION FAILURE!!! - at 0x%X, Name =<%s> MangledName = <%s>"
//   - "validated - %s<%s>"
//   - "VALIDATE_OBJECT_LIST ...complete\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, while×2, return×2, do×1.
//  - Notable callees: OutputDebugStringA×4, FUN_004022a0×2, FUN_004badf0×2, FUN_007a4480×2, FUN_004294f0, FUN_004bade0, FUN_00950b50, LeaveCriticalSection.
//  - Strings: "Checking heap..."; "done.\n"; "VALIDATE_OBJECT_LIST starting...\n"; "validated - %s<%s>".
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

uint32_t /* width from decompiler */ __fastcall FUN_00950b50(int param_1)



{

  int *piVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  OutputDebugStringA("Checking heap...");

  OutputDebugStringA("done.\n");

  FUN_004bade0();

  iVar4 = *(int *)(*(int *)(param_1 + 0xd34) + 0x18);

  iVar4 = *(int *)(*(int *)(*(int *)(iVar4 + 0x10) + (*(uint *)(iVar4 + 8) & 1) * 4) + 4);

  if (iVar4 == 0) {

LAB_00950bab:

    iVar4 = 0;

  }

  else {

    do {

      if (*(int *)(iVar4 + 0x10) == 1) {

        if (iVar4 == 0) goto LAB_00950bab;

        iVar4 = *(int *)(iVar4 + 8);

        goto LAB_00950bb2;

      }

      iVar4 = *(int *)(iVar4 + 0xc);

    } while (iVar4 != 0);

    iVar4 = 0;

  }

LAB_00950bb2:

  if (iVar4 != 0) {

    local_4 = 0;

    local_8 = (int *)0x0;

    FUN_004294f0();

    FUN_004022a0(&local_4,&local_8);

    OutputDebugStringA("VALIDATE_OBJECT_LIST starting...\n");

    piVar1 = local_8;

    while (local_8 = piVar1, piVar1 != (int *)0x0) {

      cVar2 = (**(code **)(*piVar1 + 0x128))();

      if (cVar2 == '\0') {

        uVar3 = (**(code **)(*piVar1 + 0x15c))();

        uVar3 = (**(code **)(*piVar1 + 0x160))(uVar3);

        FUN_007a4480(0,"VALIDATION FAILURE!!! - at 0x%X, Name =<%s> MangledName = <%s>",piVar1,uVar3

                    );

      }

      else {

        uVar3 = (**(code **)(*piVar1 + 0x160))();

        uVar3 = (**(code **)(*piVar1 + 0x15c))(uVar3);

        FUN_007a4480(0,"validated - %s<%s>",uVar3);

      }

      FUN_004022a0(&local_4,&local_8);

      piVar1 = local_8;

    }

    if (*(char *)(iVar4 + 0x28) != '\0') {

      *(uint8_t *)(iVar4 + 0x28) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 4));

    }

    FUN_004badf0();

    OutputDebugStringA("VALIDATE_OBJECT_LIST ...complete\n");

    return 0;

  }

  FUN_004badf0();

  return 1;

}
