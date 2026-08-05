// =============================================================================
// FUN_0056ab40
// -----------------------------------------------------------------------------
// Stable ID: aa_0056ab40
// Address:   0x0056ab40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056ab40 @ 0x0056ab40
// Stable ID: aa_0056ab40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: CVOGTacArc_ctor, FUN_0056ab40.
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

void __fastcall FUN_0056ab40(int param_1)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a4d30;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0xc0) == 0) {

    iVar2 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

    iVar1 = *(int *)(iVar2 + 0xa8);

    if ((iVar1 != 0) && (*(char *)(iVar1 + 0xf5) == '\0')) {

      iVar2 = *(int *)(iVar2 + 0xac);

      if (iVar2 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(iVar2 + 0x3c);

      }

      if ((((*(byte *)(iVar2 + 0x536) & 4) == 0) &&

          (ExceptionList = &local_c,

          iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))

                            (0), iVar2 != 0)) &&

         (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe8a0) ==

          *(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2)) {

        pvVar3 = operator_new(100);

        uStack_4 = 0;

        if (pvVar3 == (void *)0x0) {

          uVar4 = 0;

        }

        else {

          uVar4 = CVOGTacArc_ctor();

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = uVar4;

        uStack_4 = 0xffffffff;

        CVOGTacArc_Initialize

                  (param_1,*(uint8_t *)

                            (*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) +

                                     0x3c) + 0x532));

      }

    }

  }

  ExceptionList = local_c;

  return;

}
