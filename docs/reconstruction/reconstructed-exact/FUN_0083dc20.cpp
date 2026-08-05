// =============================================================================
// FUN_0083dc20
// -----------------------------------------------------------------------------
// Stable ID: aa_0083dc20
// Address:   0x0083dc20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083dc20 @ 0x0083dc20
// Stable ID: aa_0083dc20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_0083dae0×2, FUN_0083dc20.
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

void __fastcall FUN_0083dc20(int param_1)



{

  ushort uVar1;

  int in_EAX;

  int iVar2;

  uint uVar3;

  int iVar4;

  

  if (in_EAX < 1) {

    if ((in_EAX < 0) && (0 < *(int *)(param_1 + 0x4fc))) {

      *(int *)(param_1 + 0x4fc) = *(int *)(param_1 + 0x4fc) + -1;

    }

  }

  else {

    iVar4 = *(int *)(param_1 + 0x4fc) + in_EAX;

    iVar2 = (**(code **)(**(int **)(param_1 + 0x500) + 0x25c))();

    if (iVar4 <= iVar2) {

      iVar2 = *(int *)(*(int *)(param_1 + 0x500) + 0xa8);

      if (*(int *)(iVar2 + 0x38) == 4) {

        uVar3 = 999999;

      }

      else {

        uVar1 = *(ushort *)(*(int *)(iVar2 + 0x3c) + 0x4ba);

        uVar3 = (uint)uVar1;

        if (uVar1 == 0) {

          uVar3 = 200;

        }

      }

      if (iVar4 <= (int)(uVar3 & 0xffff)) {

        *(int *)(param_1 + 0x4fc) = *(int *)(param_1 + 0x4fc) + 1;

        FUN_0083dae0();

        return;

      }

    }

  }

  FUN_0083dae0();

  return;

}
