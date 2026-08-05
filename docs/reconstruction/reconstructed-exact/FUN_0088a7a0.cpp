// =============================================================================
// FUN_0088a7a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0088a7a0
// Address:   0x0088a7a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088a7a0 @ 0x0088a7a0
// Stable ID: aa_0088a7a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, return×1.
//  - Notable callees: FUN_0088a7a0.
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

void FUN_0088a7a0(void)



{

  char cVar1;

  int unaff_EBX;

  int *piVar2;

  uint uVar3;

  int iVar4;

  

  uVar3 = 0;

  piVar2 = (int *)(unaff_EBX + 0x540);

  do {

    if (*piVar2 != 0) {

      if (DAT_00d1b251 == uVar3) {

        cVar1 = (**(code **)(*(int *)*piVar2 + 0x3bc))();

        if (cVar1 == '\0') {

          (**(code **)(*(int *)*piVar2 + 0x3c8))(1,0);

          (**(code **)(*(int *)*piVar2 + 0x34c))();

        }

      }

      else {

        cVar1 = (**(code **)(*(int *)*piVar2 + 0x3bc))();

        if (cVar1 != '\0') {

          (**(code **)(*(int *)*piVar2 + 0x3c8))(0,0);

          (**(code **)(*(int *)*piVar2 + 0x34c))();

        }

      }

    }

    uVar3 = uVar3 + 1;

    piVar2 = piVar2 + 1;

  } while ((int)uVar3 < 3);

  iVar4 = 0;

  piVar2 = (int *)(unaff_EBX + 0x54c);

  do {

    if (*piVar2 != 0) {

      if (iVar4 < (int)(uint)DAT_00d1b252) {

        cVar1 = (**(code **)(*(int *)*piVar2 + 0x3bc))();

        if (cVar1 != '\0') {

          (**(code **)(*(int *)*piVar2 + 0x3c8))(0,0);

          (**(code **)(*(int *)*piVar2 + 0x34c))();

        }

      }

      else {

        cVar1 = (**(code **)(*(int *)*piVar2 + 0x3bc))();

        if (cVar1 == '\0') {

          (**(code **)(*(int *)*piVar2 + 0x3c8))(1,0);

          (**(code **)(*(int *)*piVar2 + 0x34c))();

        }

      }

    }

    iVar4 = iVar4 + 1;

    piVar2 = piVar2 + 1;

  } while (iVar4 < 3);

  return;

}
