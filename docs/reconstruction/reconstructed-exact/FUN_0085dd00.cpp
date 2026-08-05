// =============================================================================
// FUN_0085dd00
// -----------------------------------------------------------------------------
// Stable ID: aa_0085dd00
// Address:   0x0085dd00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085dd00 @ 0x0085dd00
// Stable ID: aa_0085dd00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00513e70, FUN_007b54f0, FUN_0085dd00, sprintf.
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

void __fastcall FUN_0085dd00(int *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t uStack_24;

  uint8_t uStack_23;

  uint8_t uStack_22;

  uint8_t uStack_21;

  uint32_t /* width from decompiler */ uStack_20;

  uint8_t uStack_1c;

  

  if (((param_1[0x123] != 0) && (*(int *)(*(int *)(param_1[0x123] + 0xa8) + 0x3c) != 0)) &&

     ((char)param_1[0x124] == '\0')) {

    uVar2 = (**(code **)(*(int *)param_1[0x123] + 0x25c))();

    cVar1 = FUN_00513e70();

    if ((cVar1 == '\0') && ((*(uint *)(param_1[0x123] + 0x17c) >> 0xf & 1) == 0)) {

      puVar3 = (uint32_t /* width from decompiler */ *)&DAT_00a1419b;

    }

    else {

      if ((*(uint *)(param_1[0x123] + 0x17c) >> 0xf & 1) == 0) {

        sprintf((char *)&uStack_20,"%i",uVar2);

      }

      else {

        uStack_1c = DAT_00a657f8;

        uStack_23 = 0xff;

        uStack_21 = 0xff;

        uStack_20 = DAT_00a657f4;

        uStack_22 = 0;

        uStack_24 = 0;

        (**(code **)(*param_1 + 0x15c))(1,&uStack_24);

      }

      puVar3 = &uStack_20;

    }

    (**(code **)(*param_1 + 0x1d8))(puVar3,1,1);

  }

  FUN_007b54f0();

  return;

}
