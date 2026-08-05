// =============================================================================
// Named_dcTrick_Insert_Open
// -----------------------------------------------------------------------------
// Stable ID: aa_007bf560
// Address:   0x007bf560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_dcTrick_Insert_Open @ 0x007bf560
// Stable ID: aa_007bf560
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "dcTrick_Insert::Open"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_00422fb0×7, wcscpy×3, FUN_0041a3e0×2, FUN_00423170×2, FUN_0041a810, FUN_0041a9b0, FUN_0041bf70, FUN_00422de0.
//  - Strings: "DBReader: %u against %s"; "dcTrick_Insert::Open".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "dcTrick_Insert::Open"
 * Domain alias of FUN_007bf560 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall Named_dcTrick_Insert_Open(uint32_t /* width from decompiler */ *param_1,char *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_150;

  uint32_t /* width from decompiler */ local_14c;

  uint32_t /* width from decompiler */ local_148;

  uint32_t /* width from decompiler */ local_144;

  uint32_t /* width from decompiler */ *local_140;

  uint32_t /* width from decompiler */ local_13c;

  int local_138;

  uint32_t /* width from decompiler */ local_134;

  uint32_t /* width from decompiler */ *local_130;

  uint32_t /* width from decompiler */ local_12c;

  uint32_t /* width from decompiler */ local_128;

  uint32_t /* width from decompiler */ local_124;

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  wchar_t local_118 [34];

  wchar_t local_d4 [34];

  wchar_t local_90 [66];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ae168;

  local_c = ExceptionList;

  if (*param_2 == '\0') {

    iVar1 = -0x7fffbffc;

  }

  else if (DAT_00d1793c == '\0') {

    local_11c = param_1[1];

    local_14c = *param_1;

    local_150 = 0xffffffff;

    ExceptionList = &local_c;

    wcscpy(local_90,(wchar_t *)((int)param_1 + 10));

    wcscpy(local_d4,(wchar_t *)(param_1 + 0x23));

    wcscpy(local_118,(wchar_t *)((int)param_1 + 0xce));

    local_130 = &local_148;

    local_148 = 0;

    local_144 = 0;

    local_140 = (uint32_t /* width from decompiler */ *)0x0;

    local_13c = 0;

    local_138 = 0;

    local_134 = 0;

    local_128 = 0;

    local_12c = 0;

    local_124 = 0;

    local_120 = 0;

    local_4 = 0;

    FUN_004230d0(local_130,&local_14c);

    iVar1 = FUN_00422fb0(1,1,4);

    if (((((-1 < iVar1) && (iVar1 = FUN_00422fb0(1,2,4), -1 < iVar1)) &&

         (iVar1 = FUN_00422fb0(1,3,1), -1 < iVar1)) &&

        ((iVar1 = FUN_00422fb0(1,4,0x82), -1 < iVar1 && (iVar1 = FUN_00422fb0(1,5,0x42), -1 < iVar1)

         ))) && ((iVar1 = FUN_00422fb0(1,6,1), -1 < iVar1 &&

                 (iVar1 = FUN_00422fb0(1,7,0x42), -1 < iVar1)))) {

      iVar1 = FUN_0041a810(&local_148,param_2 + 0x28,0,0,&DAT_00a140c8,0,0);

    }

    local_140 = &local_150;

    if ((-1 < iVar1) && (iVar1 = FUN_004231d0(&local_148,1,4), -1 < iVar1)) {

      if (local_138 != 0) {

        iVar1 = FUN_0041a9b0();

        if (iVar1 == 0) {

          *param_1 = local_150;

        }

        if (local_138 != 0) {

          FUN_00422de0();

          FUN_0041bf70();

        }

        FUN_00423170();

        local_4 = 0xffffffff;

        FUN_0041a3e0(&local_148);

        ExceptionList = local_c;

        return iVar1;

      }

      iVar1 = -0x7fffbffb;

    }

    FUN_00423170();

    FUN_007a4480(1,"DBReader: %u against %s",iVar1,"dcTrick_Insert::Open");

    local_4 = 0xffffffff;

    FUN_0041a3e0(&local_148);

    iVar1 = 0;

  }

  else {

    iVar1 = 0;

  }

  ExceptionList = local_c;

  return iVar1;

}
