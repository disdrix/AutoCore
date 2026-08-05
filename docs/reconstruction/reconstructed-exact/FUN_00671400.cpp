// =============================================================================
// FUN_00671400
// -----------------------------------------------------------------------------
// Stable ID: aa_00671400
// Address:   0x00671400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00671400 @ 0x00671400
// Stable ID: aa_00671400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0066f1b0, FUN_00670bb0, FUN_00670cd0, FUN_00670fc0, FUN_00671400, FUN_0067e030.
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

void __fastcall FUN_00671400(int param_1)



{

  char cVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a9124;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(char *)(param_1 + 0x59) != '\0') {

    ExceptionList = &pvStack_c;

    cVar1 = (**(code **)(**(int **)(param_1 + 0x3c) + 0xc))();

    if (cVar1 == '\0') {

      *(uint8_t *)(param_1 + 0x59) = 0;

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x3c) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x3c))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

      (**(code **)(**(int **)(param_1 + 0x54) + 0x10))();

    }

    else {

      cVar1 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x1c))();

      if (cVar1 != '\0') {

        *(uint8_t *)(param_1 + 0x59) = 0;

        pvVar2 = operator_new(0x2a48);

        uStack_4 = 0;

        if (pvVar2 == (void *)0x0) {

          uVar3 = 0;

        }

        else {

          uVar3 = FUN_0067e030(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c));

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = uVar3;

        *(uint8_t *)(param_1 + 0x58) = 1;

        *(uint8_t *)(param_1 + 0x5a) = 0;

        uStack_4 = 0xffffffff;

        (**(code **)(**(int **)(param_1 + 0x54) + 0xc))();

      }

    }

  }

  FUN_00670bb0();

  FUN_00670fc0();

  FUN_00670cd0();

  FUN_0066f1b0();

  ExceptionList = pvStack_c;

  return;

}
