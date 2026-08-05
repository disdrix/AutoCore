// =============================================================================
// FUN_00927e70
// -----------------------------------------------------------------------------
// Stable ID: aa_00927e70
// Address:   0x00927e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00927e70 @ 0x00927e70
// Stable ID: aa_00927e70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: _BinkNextFrame_4×2, FUN_00927e70, _BinkCopyToBufferRect_44, _BinkDoFrame_4, _BinkShouldSkip_4.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00927e70(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t *puStack_38;

  int *piStack_30;

  int *piStack_2c;

  uint8_t *puStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  int iStack_20;

  uint8_t local_18 [24];

  

  iStack_20 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 300);

  *(int *)(unaff_ESI + 0x138) = *(int *)(unaff_ESI + 0x138) + 1;

  uStack_24 = 0x927e87;

  _BinkDoFrame_4();

  iStack_20 = *(int *)(unaff_ESI + 300);

  if (*(int *)(iStack_20 + 8) != *(int *)(unaff_ESI + 0x138)) {

    uStack_24 = 0x927ea3;

    iVar2 = _BinkShouldSkip_4();

    if (iVar2 != 0) {

      iStack_20 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 300);

      uStack_24 = 0x927eb4;

      _BinkNextFrame_4();

      return 1;

    }

    iStack_20 = 0;

    uStack_24 = 0;

    puStack_28 = local_18;

    piStack_2c = DAT_00d17750;

    piStack_30 = (int *)0x927ece;

    iVar2 = (**(code **)(*DAT_00d17750 + 0x34))();

    if (iVar2 == 0) {

      puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 300);

      puStack_38 = (uint8_t *)*puVar1;

      piStack_30 = (int *)0x80080003;

      _BinkCopyToBufferRect_44(puVar1,uStack_24,puStack_28,puVar1[1],0,0,0,0);

      piStack_30 = DAT_00d17750;

      iVar2 = (**(code **)(*DAT_00d17750 + 0x38))();

      if (-1 < iVar2) {

        uVar3 = 0;

        puStack_38 = (uint8_t *)&piStack_30;

        (**(code **)(*DAT_00d17748 + 0x48))(DAT_00d17748,0,0,0);

        puStack_38 = *(uint8_t **)(unaff_ESI + 0x124);

        piStack_30 = (int *)(puStack_38 + *(int *)(unaff_ESI + 0x11c));

        piStack_2c = (int *)(*(int *)(unaff_ESI + 0x120) + *(int *)(unaff_ESI + 0x128));

        iVar2 = (**(code **)(*DAT_00d17748 + 0x88))(DAT_00d17748,DAT_00d17750,0,uVar3,&puStack_38,2)

        ;

        if (DAT_00d1774c == (int *)0x0) {

          iVar2 = (**(code **)(*DAT_00d17748 + 0x44))(DAT_00d17748,0,0,0,0);

        }

        else {

          (**(code **)(*DAT_00d1774c + 0xc))(DAT_00d1774c,0,0,0,0,1);

        }

        if (iVar2 != -0x7789f798) {

          _BinkNextFrame_4(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 300));

          return 1;

        }

      }

    }

  }

  return 0;

}
