// =============================================================================
// FUN_007bd440
// -----------------------------------------------------------------------------
// Stable ID: aa_007bd440
// Address:   0x007bd440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007bd440 @ 0x007bd440
// Stable ID: aa_007bd440
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "UpdateContinentObject"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00422fb0×14, CONCAT22×3, FUN_00423170×2, wcscpy×2, FUN_0041a4b0, FUN_0041b670, FUN_004230d0, FUN_007a4480.
//  - Strings: "DBReader: %u against %s"; "UpdateContinentObject".
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

uint32_t /* width from decompiler */ __fastcall FUN_007bd440(char *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  wchar_t *pwVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_15c;

  uint32_t /* width from decompiler */ local_158;

  uint32_t /* width from decompiler */ local_154;

  uint32_t /* width from decompiler */ local_150;

  uint32_t /* width from decompiler */ local_14c;

  uint32_t /* width from decompiler */ local_148;

  uint32_t /* width from decompiler */ local_144;

  uint32_t /* width from decompiler */ local_140;

  uint32_t /* width from decompiler */ local_13c;

  uint32_t /* width from decompiler */ local_138;

  uint32_t /* width from decompiler */ local_134;

  uint32_t /* width from decompiler */ local_130;

  uint32_t /* width from decompiler */ local_12c;

  uint32_t /* width from decompiler */ local_128;

  uint32_t /* width from decompiler */ local_124;

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  wchar_t local_114 [66];

  wchar_t local_90 [66];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009adfe0;

  local_c = ExceptionList;

  if (*param_1 != '\0') {

    if (DAT_00d1793c == '\0') {

      local_144 = *param_3;

      local_120 = CONCAT22((short)((uint)param_2 >> 0x10),*(uint16_t *)(param_3 + 4));

      local_11c = param_3[3];

      local_124 = CONCAT22((short)((uint)local_144 >> 0x10),*(uint16_t *)(param_3 + 6));

      ExceptionList = &local_c;

      pwVar1 = wcscpy(local_114,(wchar_t *)(param_3 + 7));

      local_134 = CONCAT22((short)((uint)pwVar1 >> 0x10),*(uint16_t *)(param_3 + 0x28));

      local_118 = param_3[0x2a];

      local_13c = param_3[0x4e];

      local_12c = param_3[0x2b];

      local_138 = param_3[0x4f];

      local_140 = param_3[0x2c];

      wcscpy(local_90,(wchar_t *)(param_3 + 0x2d));

      local_130 = param_3[0x50];

      local_128 = param_3[0x51];

      local_15c = 0;

      local_158 = 0;

      local_154 = 0;

      local_150 = 0;

      local_14c = 0;

      local_148 = 0;

      local_4 = 0;

      FUN_004230d0(&local_15c,&local_144);

      iVar2 = FUN_00422fb0(1,1,4);

      if (((((iVar2 < 0) || (iVar2 = FUN_00422fb0(1,2,4), iVar2 < 0)) ||

           (iVar2 = FUN_00422fb0(1,3,2), iVar2 < 0)) ||

          (((iVar2 = FUN_00422fb0(1,4,2), iVar2 < 0 || (iVar2 = FUN_00422fb0(1,5,0x82), iVar2 < 0))

           || ((iVar2 = FUN_00422fb0(1,6,2), iVar2 < 0 ||

               ((iVar2 = FUN_00422fb0(1,7,4), iVar2 < 0 || (iVar2 = FUN_00422fb0(1,8,4), iVar2 < 0))

               )))))) ||

         ((iVar2 = FUN_00422fb0(1,9,4), iVar2 < 0 ||

          (((((iVar2 = FUN_00422fb0(1,10,0x82), iVar2 < 0 ||

              (iVar2 = FUN_00422fb0(1,0xb,4), iVar2 < 0)) ||

             (iVar2 = FUN_00422fb0(1,0xc,4), iVar2 < 0)) ||

            ((iVar2 = FUN_00422fb0(1,0xd,4), iVar2 < 0 || (iVar2 = FUN_00422fb0(1,0xe,4), iVar2 < 0)

             ))) || (iVar2 = FUN_0041b670(&local_15c,param_1 + 0x28,0,0,&DAT_00a140c8,0,0),

                    iVar2 < 0)))))) {

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s",iVar2,"UpdateContinentObject");

      }

      else {

        FUN_00423170();

      }

      local_4 = 0xffffffff;

      FUN_0041a4b0(&local_15c);

    }

    ExceptionList = local_c;

    return 0;

  }

  return 0x80004004;

}
