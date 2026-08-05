// =============================================================================
// FUN_00907c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00907c30
// Address:   0x00907c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00907c30 @ 0x00907c30
// Stable ID: aa_00907c30
// Embedded strings (evidence for future rename):
//   - "%d - %d (/%d)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_00907bb0, FUN_00907be0, FUN_00907c30, d, sprintf.
//  - Strings: "%d - %d (/%d)".
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

void FUN_00907c30(char param_1)



{

  int iVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  int *unaff_ESI;

  char acStack_80 [128];

  

  cVar2 = (**(code **)(*unaff_ESI + 0x3d8))();

  if ((cVar2 != '\0') && (unaff_ESI[0x145] == 0)) {

    if ((param_1 != '\0') && (unaff_ESI[0x1a6] != 0)) {

      uVar3 = (uint)*(ushort *)(DAT_00d1ad2c + 0x24);

      iVar1 = (uint)*(ushort *)(DAT_00d1ad2c + 0x26) * 0x32;

      uVar5 = iVar1 + 0x32;

      if (uVar3 <= uVar5) {

        uVar5 = uVar3;

      }

      uVar4 = iVar1 + 1;

      if (uVar3 <= uVar4) {

        uVar4 = uVar3;

      }

      sprintf(acStack_80,"%d - %d (/%d)",uVar4,uVar5,uVar3);

      (**(code **)(*(int *)unaff_ESI[0x1a6] + 0x1d8))(acStack_80,1,1);

      (**(code **)(*(int *)unaff_ESI[0x1a6] + 0x34c))();

    }

    if (unaff_ESI[0x1a4] != 0) {

      cVar2 = FUN_00907be0(unaff_ESI);

      if (cVar2 == '\0') {

        cVar2 = (**(code **)(*(int *)unaff_ESI[0x1a4] + 0xd8))();

        if (cVar2 == '\x01') {

          (**(code **)(*(int *)unaff_ESI[0x1a4] + 0xd4))(0);

          (**(code **)(*(int *)unaff_ESI[0x1a4] + 0x34c))();

        }

      }

      else {

        cVar2 = (**(code **)(*(int *)unaff_ESI[0x1a4] + 0xd8))();

        if (cVar2 == '\0') {

          (**(code **)(*(int *)unaff_ESI[0x1a4] + 0xd4))(1);

          (**(code **)(*(int *)unaff_ESI[0x1a4] + 0x34c))();

        }

      }

    }

    if (unaff_ESI[0x1a5] != 0) {

      cVar2 = FUN_00907bb0(unaff_ESI);

      if (cVar2 == '\0') {

        cVar2 = (**(code **)(*(int *)unaff_ESI[0x1a5] + 0xd8))();

        if (cVar2 == '\x01') {

          (**(code **)(*(int *)unaff_ESI[0x1a5] + 0xd4))(0);

          (**(code **)(*(int *)unaff_ESI[0x1a5] + 0x34c))();

        }

      }

      else {

        cVar2 = (**(code **)(*(int *)unaff_ESI[0x1a5] + 0xd8))();

        if (cVar2 == '\0') {

          (**(code **)(*(int *)unaff_ESI[0x1a5] + 0xd4))(1);

          (**(code **)(*(int *)unaff_ESI[0x1a5] + 0x34c))();

          return;

        }

      }

    }

  }

  return;

}
