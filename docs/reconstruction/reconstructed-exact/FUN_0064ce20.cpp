// =============================================================================
// FUN_0064ce20
// -----------------------------------------------------------------------------
// Stable ID: aa_0064ce20
// Address:   0x0064ce20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064ce20 @ 0x0064ce20
// Stable ID: aa_0064ce20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_00560020, FUN_00634350, FUN_006369b0, FUN_0064ce20.
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

void __fastcall FUN_0064ce20(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  iVar2 = param_1[0xe];

  *param_1 = &PTR_FUN_009e4a40;

  if (iVar2 != 0) {

    if (*(int *)(iVar2 + 8) != 0) {

      FUN_00560020(iVar2);

    }

    FUN_00634350(param_1 + 0x7c);

    puVar1 = (uint32_t /* width from decompiler */ *)param_1[0xe];

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

  }

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[0xc];

  *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

  if (*(short *)((int)puVar1 + 6) == 0) {

    (**(code **)*puVar1)(1);

  }

  if ((param_1[0xcd] != 0) && (iVar2 = 0, 0 < (int)param_1[0xcd])) {

    do {

      puVar1 = *(uint32_t /* width from decompiler */ **)(param_1[0xcc] + iVar2 * 4);

      *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

      if (*(short *)((int)puVar1 + 6) == 0) {

        (**(code **)*puVar1)(1);

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)param_1[0xcd]);

  }

  if (-1 < (int)param_1[0xce]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0xcc],param_1[0xce] * 4,0x12);

  }

  FUN_006369b0();

  return;

}
