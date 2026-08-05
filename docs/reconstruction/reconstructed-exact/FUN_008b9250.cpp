// =============================================================================
// FUN_008b9250
// -----------------------------------------------------------------------------
// Stable ID: aa_008b9250
// Address:   0x008b9250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b9250 @ 0x008b9250
// Stable ID: aa_008b9250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0082ad00, FUN_0082ad70, FUN_008b9250.
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

void __fastcall FUN_008b9250(int *param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puStack_4;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    param_1 = param_1 + 0x15a;

    puStack_4 = &DAT_00d177c8;

    do {

      if (*param_1 != 0) {

        iVar2 = 0;

        do {

          FUN_0082ad70();

          iVar2 = iVar2 + 1;

        } while (iVar2 < 5);

        FUN_0082ad00();

        (**(code **)(*(int *)*param_1 + 0x34c))();

      }

      puStack_4 = puStack_4 + 5;

      param_1 = param_1 + 1;

    } while ((int)puStack_4 < 0xd178f4);

  }

  return;

}
