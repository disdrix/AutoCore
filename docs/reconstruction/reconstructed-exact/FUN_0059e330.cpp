// =============================================================================
// FUN_0059e330
// -----------------------------------------------------------------------------
// Stable ID: aa_0059e330
// Address:   0x0059e330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059e330 @ 0x0059e330
// Stable ID: aa_0059e330
// Embedded strings (evidence for future rename):
//   - "CheckIncoming"
//   - "Process"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, while×2, do×1, return×1.
//  - Notable callees: FUN_00426760×2, FUN_0076cef0×2, FUN_0076cf00×2, FUN_004265f0, FUN_0042ca20, FUN_0042ccf0, FUN_0059e330.
//  - Strings: "CheckIncoming"; "Process".
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

void __fastcall FUN_0059e330(int param_1)



{

  char cVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5ce0;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0xb0) != 0) {

    ExceptionList = &local_c;

    FUN_0076cf00("CheckIncoming");

    local_4 = 0;

    FUN_0042ccf0();

    local_4 = 0xffffffff;

    FUN_0076cef0();

    FUN_0076cf00("Process");

    local_4 = 1;

    FUN_0042ca20();

    if ((*(char *)(param_1 + 0xa8) != '\0') &&

       (iVar2 = 0, 0 < *(int *)(*(int *)(param_1 + 0xb0) + 0xc))) {

      do {

        cVar1 = FUN_00426760(2);

        while ((cVar1 == '\0' &&

               (cVar1 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0xb0) + 0x14) +

                                               iVar2 * 4) + 0x54))(), cVar1 != '\0'))) {

          FUN_004265f0(1,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb0) + 0x78));

          cVar1 = FUN_00426760(2);

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < *(int *)(*(int *)(param_1 + 0xb0) + 0xc));

    }

    local_4 = 0xffffffff;

    FUN_0076cef0();

  }

  ExceptionList = local_c;

  return;

}
