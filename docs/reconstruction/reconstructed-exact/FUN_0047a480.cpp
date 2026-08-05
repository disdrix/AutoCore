// =============================================================================
// FUN_0047a480
// -----------------------------------------------------------------------------
// Stable ID: aa_0047a480
// Address:   0x0047a480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047a480 @ 0x0047a480
// Stable ID: aa_0047a480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, do×1, goto×1, while×1.
//  - Notable callees: FUN_0046d130, FUN_00476cc0, FUN_00476d60, FUN_00476db0, FUN_00476e50, FUN_0047a420, FUN_0047a480, FUN_0047a590.
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

uint32_t /* width from decompiler */ __fastcall FUN_0047a480(int param_1)



{

  uint uVar1;

  byte bVar2;

  uint in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  uVar1 = *(uint *)(param_1 + 0xb0);

  do {

    if (in_EAX <= uVar1) {

      if (in_EAX != 0) {

        FUN_0047a420();

      }

      iVar3 = FUN_0047a590();

      if (iVar3 != 0) {

        bVar2 = *(byte *)(param_1 + 0x11c) & 0x20;

        if (((bVar2 == 0) || ((*(byte *)(param_1 + 0x6d) & 2) != 0)) &&

           ((bVar2 != 0 || ((*(byte *)(param_1 + 0x6d) & 4) == 0)))) {

          uVar4 = FUN_00476e50();

          return uVar4;

        }

        FUN_00476db0(param_1);

        FUN_00476d60();

        return 1;

      }

      return 0;

    }

    iVar3 = *(int *)(param_1 + 0xac);

    if (*(code **)(param_1 + 0x50) == (code *)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0(param_1);

    }

    (**(code **)(param_1 + 0x50))(param_1,iVar3,*(uint32_t /* width from decompiler */ *)(param_1 + 0xb0));

    if ((*(byte *)(param_1 + 0x11c) & 0x20) == 0) {

      if ((*(byte *)(param_1 + 0x6d) & 8) == 0) goto LAB_0047a4df;

    }

    else if ((*(uint *)(param_1 + 0x6c) & 0x300) != 0x300) {

LAB_0047a4df:

      if (iVar3 == 0) {

        uVar4 = 0;

      }

      else {

        uVar4 = FUN_0046d130();

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = uVar4;

    }

    in_EAX = in_EAX - uVar1;

  } while( true );

}
