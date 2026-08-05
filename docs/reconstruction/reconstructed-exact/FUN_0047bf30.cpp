// =============================================================================
// FUN_0047bf30
// -----------------------------------------------------------------------------
// Stable ID: aa_0047bf30
// Address:   0x0047bf30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047bf30 @ 0x0047bf30
// Stable ID: aa_0047bf30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, do×1, while×1.
//  - Notable callees: FUN_0047a480×4, FUN_00476d60×3, FUN_0046ffb0, FUN_00476cc0, FUN_0047a420, FUN_0047bf30.
//  - Return sites: 5.

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

void __thiscall FUN_0047bf30(int param_1,int param_2)



{

  uint in_EAX;

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  ushort local_208;

  short local_200 [256];

  

  uVar1 = *(uint *)(param_1 + 0x68);

  if ((uVar1 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  if ((uVar1 & 4) == 0) {

    if ((uVar1 & 2) == 0) {

      FUN_00476d60();

      FUN_0047a480();

      return;

    }

    if ((((param_2 == 0) || ((*(byte *)(param_2 + 8) & 0x40) == 0)) &&

        (uVar1 = in_EAX >> 1, uVar1 == *(ushort *)(param_1 + 0x118))) && (uVar1 < 0x101)) {

      uVar3 = 0;

      if (uVar1 != 0) {

        do {

          FUN_0047a420();

          uVar4 = uVar3 + 1;

          local_200[uVar3] = local_208 * 0x100 + (local_208 >> 8);

          uVar3 = uVar4;

        } while (uVar4 < uVar1);

      }

      iVar2 = FUN_0047a480();

      if (iVar2 == 0) {

        FUN_0046ffb0(local_200);

        return;

      }

    }

    else {

      FUN_00476d60();

      FUN_0047a480();

    }

    return;

  }

  FUN_00476d60();

  FUN_0047a480();

  return;

}
