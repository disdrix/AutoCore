// =============================================================================
// FUN_0047af00
// -----------------------------------------------------------------------------
// Stable ID: aa_0047af00
// Address:   0x0047af00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047af00 @ 0x0047af00
// Stable ID: aa_0047af00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×8, return×6.
//  - Notable callees: FUN_00476d60×4, FUN_0047a480×4, FUN_00470550×2, FUN_00476cc0, FUN_0047a420, FUN_0047af00.
//  - Return sites: 6.

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

void __thiscall FUN_0047af00(int param_1,int param_2)



{

  uint in_EAX;

  int iVar1;

  uint uVar2;

  

  uVar2 = *(uint *)(param_1 + 0x68);

  if ((uVar2 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0(param_1);

  }

  if ((uVar2 & 4) != 0) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if ((uVar2 & 2) != 0) {

    FUN_00476d60();

  }

  if ((param_2 != 0) && ((*(byte *)(param_2 + 8) & 2) != 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  uVar2 = 3;

  if (*(char *)(param_1 + 0x126) != '\x03') {

    uVar2 = (uint)*(byte *)(param_1 + 0x12a);

  }

  if ((in_EAX == uVar2) && (in_EAX < 5)) {

    FUN_0047a420();

    iVar1 = FUN_0047a480();

    if (iVar1 == 0) {

      if ((*(byte *)(param_1 + 0x126) & 2) != 0) {

        *(uint8_t *)(param_1 + 0x17c) = 0;

        *(uint8_t *)(param_1 + 0x17d) = 0;

        *(uint8_t *)(param_1 + 0x17e) = 0;

        *(uint8_t *)(param_1 + 0x180) = 0;

        FUN_00470550(param_1);

        return;

      }

      *(uint8_t *)(param_1 + 0x17f) = 0;

      *(uint8_t *)(param_1 + 0x17c) = 0;

      *(uint8_t *)(param_1 + 0x17d) = 0;

      *(uint8_t *)(param_1 + 0x17e) = 0;

      *(uint8_t *)(param_1 + 0x180) = 0;

      FUN_00470550(param_1);

      return;

    }

  }

  else {

    FUN_00476d60();

    FUN_0047a480();

  }

  return;

}
