// =============================================================================
// FUN_004267c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004267c0
// Address:   0x004267c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004267c0 @ 0x004267c0
// Stable ID: aa_004267c0
// Embedded strings (evidence for future rename):
//   - "LogNetConnection"
//   - "NetConnection %s: SENDDROP - %d"
//   - "NetConnection %s: SEND - %d bytes"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×9, return×4.
//  - Notable callees: FUN_00783aa0×2, FUN_00783b60×2, FUN_007845c0×2, FUN_00976080×2, FUN_004256f0, FUN_004267c0, FUN_0042c390, FUN_0042c3d0.
//  - Strings: "LogNetConnection"; "NetConnection %s: SENDDROP - %d"; "NetConnection %s: SEND - %d bytes".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ FUN_004267c0(void)



{

  uint uVar1;

  double dVar2;

  int in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint uVar6;

  int unaff_ESI;

  

  if (*(float *)(in_EAX + 200) != g_flZero) {

    iVar3 = FUN_00976080();

    dVar2 = (double)iVar3;

    if (iVar3 < 0) {

      dVar2 = dVar2 + _DAT_00aaa728;

    }

    if (dVar2 * _DAT_00aaa9d0 < (double)*(float *)(in_EAX + 200)) {

      if ((_DAT_00d208b0 & 1) == 0) {

        _DAT_00d208b0 = _DAT_00d208b0 | 1;

        DAT_00d208ac = FUN_00783b60("LogNetConnection");

      }

      if (*(char *)(DAT_00d208ac + 4) != '\0') {

        DAT_00d179a0 = DAT_00d208ac;

        uVar4 = FUN_007845c0(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x94));

        FUN_00783aa0("NetConnection %s: SENDDROP - %d",uVar4);

        DAT_00d179a0 = 0;

      }

      return 0;

    }

  }

  if ((_DAT_00d208b0 & 2) == 0) {

    _DAT_00d208b0 = _DAT_00d208b0 | 2;

    DAT_00d208a8 = FUN_00783b60("LogNetConnection");

  }

  if (*(char *)(DAT_00d208a8 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d208a8;

    uVar4 = FUN_007845c0(*(int *)(unaff_ESI + 0x18) + 7U >> 3);

    FUN_00783aa0("NetConnection %s: SEND - %d bytes",uVar4);

    DAT_00d179a0 = 0;

  }

  if (*(int *)(in_EAX + 0x128) == 0) {

    if (*(int *)(in_EAX + 0xc4) == 0) {

      uVar4 = FUN_0042c390(in_EAX + 0xf8);

      return uVar4;

    }

    uVar1 = *(uint *)(in_EAX + 0xc4);

    uVar5 = uVar1 >> 1;

    uVar6 = FUN_00976080();

    FUN_0042c3d0(unaff_ESI,uVar6 % ((uVar1 * 2 - uVar5) + 1) + uVar5);

    return 0;

  }

  iVar3 = *(int *)(unaff_ESI + 0x18);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

  *(uint8_t *)(unaff_ESI + 0x1c) = 0;

  *(uint8_t *)(unaff_ESI + 0x1d) = 0;

  *(uint8_t *)(unaff_ESI + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34) = 0;

  *(uint *)(unaff_ESI + 0x2c) = iVar3 + 7U & 0xfffffff8;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30) = 0;

  FUN_004256f0(unaff_ESI);

  return 0;

}
