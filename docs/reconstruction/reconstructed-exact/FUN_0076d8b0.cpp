// =============================================================================
// FUN_0076d8b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d8b0
// Address:   0x0076d8b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076d8b0 @ 0x0076d8b0
// Stable ID: aa_0076d8b0
// Embedded strings (evidence for future rename):
//   - "<Unknown> \r\n"
//   - "%s(%d) : %s\r\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: _snprintf×2, FUN_0076d490, FUN_0076d8b0, s.
//  - Strings: "<Unknown> \r\n"; "%s(%d) : %s\r\n".
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

uint32_t /* width from decompiler */ FUN_0076d8b0(int param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar2;

  int local_7c;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  int local_68;

  uint32_t /* width from decompiler */ local_64;

  uint8_t auStack_60 [96];

  

  if (DAT_00d0dfb0 != (code *)0x0) {

    iVar2 = 0;

    local_7c = 0;

    if (0 < param_2) {

      do {

        local_70 = 0;

        local_6c = 0;

        local_68 = 0;

        local_64 = 0;

        local_78 = 0;

        local_74 = 0x14;

        iVar1 = (*DAT_00d0dfb0)(*(uint32_t /* width from decompiler */ *)(param_1 + 4),*(uint32_t /* width from decompiler */ *)(param_3 + local_7c * 4)

                                ,&local_78,&local_74);

        if ((iVar1 == 0) || (local_68 == 0)) {

          iVar1 = _snprintf((char *)(iVar2 + param_4),param_5 - iVar2,"<Unknown> \r\n");

        }

        else {

          auStack_60[0] = 0;

          FUN_0076d490(0x60);

          iVar1 = _snprintf((char *)(iVar2 + param_4),param_5 - iVar2,"%s(%d) : %s\r\n",local_68,

                            local_6c,auStack_60);

        }

        local_7c = local_7c + 1;

        iVar2 = iVar2 + iVar1;

      } while (local_7c < param_2);

    }

    return 1;

  }

  return 0;

}
