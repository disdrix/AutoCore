// =============================================================================
// FUN_0091f580
// -----------------------------------------------------------------------------
// Stable ID: aa_0091f580
// Address:   0x0091f580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091f580 @ 0x0091f580
// Stable ID: aa_0091f580
// Embedded strings (evidence for future rename):
//   - "You cannot afford the repair fee!"
//   - "Cannot process while frozen by GM!"
//   - "You cannot repair again for another %d minutes!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, while×1, for×1.
//  - Notable callees: FUN_007a6de0×2, FUN_008f8200×2, CONCAT44, FUN_0040ad20, FUN_0051f710, FUN_007a69d0, FUN_0091f1f0, FUN_0091f580.
//  - Strings: "You cannot afford the repair fee!"; "Cannot process while frozen by GM!"; "You cannot repair again for another %d minutes!".
//  - Return sites: 4.

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

/* WARNING: Removing unreachable block (ram,0x0091f62a) */



void FUN_0091f580(void)



{

  uint uVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  longlong lVar4;

  char local_100 [256];

  

  FUN_007a69d0();

  if (DAT_00d1b6d8 != 0) {

    uVar1 = FUN_0051f710();

    if (uVar1 == 0) {

      lVar4 = FUN_0040ad20();

      if (CONCAT44((*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                   (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728)),

                   *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728)) < lVar4) {

        pcVar2 = "You cannot afford the repair fee!";

      }

      else {

        if ((*(byte *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xb8 + DAT_00d1b6d8) & 1) == 0) {

          FUN_0091f1f0(1);

          return;

        }

        pcVar2 = "Cannot process while frozen by GM!";

      }

      uVar3 = FUN_007a6de0(pcVar2,0xffffffff);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar3,0);

        return;

      }

    }

    else {

      uVar1 = uVar1 / 60000;

      pcVar2 = (char *)FUN_007a6de0("You cannot repair again for another %d minutes!",0xffffffff);

      sprintf(local_100,pcVar2,uVar1);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,local_100,0);

        return;

      }

    }

  }

  return;

}
