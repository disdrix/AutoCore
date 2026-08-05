// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007bcb40
// -----------------------------------------------------------------------------
// Stable ID: aa_007bcb40
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x007bcb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper. Evidence string: "DBReader: %u against %s". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "DBReader: %u against %s"
//   - "InsertMapModule::MoveFirst"
//   - "InsertMapModule"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, goto×1.
//  - Notable callees: FUN_00422fb0×6, FUN_00423170×3, FUN_0041a990×2, FUN_007a4480×2, wcscpy×2, FUN_0041a3e0, FUN_0041a810, FUN_0041a9b0.
//  - Strings: "DBReader: %u against %s"; "InsertMapModule::MoveFirst"; "InsertMapModule".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_007bcb40(char *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  uint8_t local_18a;

  uint8_t local_189;

  uint32_t /* width from decompiler */ uStack_188;

  uint32_t /* width from decompiler */ local_184;

  uint32_t /* width from decompiler */ local_180;

  uint32_t /* width from decompiler */ *local_17c;

  uint32_t /* width from decompiler */ local_178;

  int local_174;

  uint32_t /* width from decompiler */ local_170;

  uint32_t /* width from decompiler */ *local_16c;

  uint32_t /* width from decompiler */ local_168;

  uint32_t /* width from decompiler */ local_164;

  uint32_t /* width from decompiler */ local_160;

  uint32_t /* width from decompiler */ local_15c;

  uint32_t /* width from decompiler */ local_158;

  uint32_t /* width from decompiler */ local_154;

  char *local_150;

  wchar_t local_14c [32];

  wchar_t local_10c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009adf65;

  local_c = ExceptionList;

  if (DAT_00d1793c != '\0') {

    return 0;

  }

  local_154 = param_2[1];

  local_18a = *(uint8_t *)(param_2 + 2);

  ExceptionList = &local_c;

  local_150 = param_1;

  wcscpy(local_14c,(wchar_t *)((int)param_2 + 10));

  local_189 = *(uint8_t *)(param_2 + 0x13);

  wcscpy(local_10c,(wchar_t *)((int)param_2 + 0x4e));

  local_158 = param_2[0x54];

  if (*param_1 == '\0') {

    ExceptionList = local_c;

    return 0x80004004;

  }

  local_16c = &local_184;

  local_184 = 0;

  local_180 = 0;

  local_17c = (uint32_t /* width from decompiler */ *)0x0;

  local_178 = 0;

  local_174 = 0;

  local_170 = 0;

  local_164 = 0;

  local_168 = 0;

  local_160 = 0;

  local_15c = 0;

  local_4 = 0;

  FUN_004230d0(local_16c,&local_18a);

  iVar1 = FUN_00422fb0(1,1,1);

  if (((((-1 < iVar1) && (iVar1 = FUN_00422fb0(1,2,4), -1 < iVar1)) &&

       (iVar1 = FUN_00422fb0(1,3,0x40), -1 < iVar1)) &&

      ((iVar1 = FUN_00422fb0(1,4,1), -1 < iVar1 && (iVar1 = FUN_00422fb0(1,5,0x100), -1 < iVar1))))

     && (iVar1 = FUN_00422fb0(1,6,4), -1 < iVar1)) {

    iVar1 = FUN_0041a810(&local_184,local_150 + 0x28,0,0,&DAT_00a140c8,0,0);

  }

  local_17c = &uStack_188;

  if ((-1 < iVar1) && (iVar1 = FUN_004231d0(&local_184,1,4), -1 < iVar1)) {

    if (local_174 != 0) {

      iVar1 = FUN_0041a9b0();

      if (iVar1 == 0) {

        *param_3 = uStack_188;

        *param_2 = uStack_188;

        FUN_0041a990();

        FUN_00423170();

      }

      else {

        FUN_0041a990();

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s",iVar1,"InsertMapModule::MoveFirst");

      }

      goto LAB_007bcdb6;

    }

    iVar1 = -0x7fffbffb;

  }

  FUN_00423170();

  FUN_007a4480(1,"DBReader: %u against %s",iVar1,"InsertMapModule");

LAB_007bcdb6:

  local_4 = 0xffffffff;

  FUN_0041a3e0(&local_184);

  ExceptionList = local_c;

  return 0;

}
