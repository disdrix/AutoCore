// =============================================================================
// FUN_00462390
// -----------------------------------------------------------------------------
// Stable ID: aa_00462390
// Address:   0x00462390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00462390 @ 0x00462390
// Stable ID: aa_00462390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_004627e0×2, FUN_00462390, FUN_00462640, FUN_00462be0.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00462390(uint32_t /* width from decompiler */ param_1,uint *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EDI;

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009bef40;

  local_c = ExceptionList;

  puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 4);

  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      if ((uint)puVar1[3] < *param_2) {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

        puVar3 = puVar1;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x21) == '\0');

  }

  if ((puVar3 == *(uint32_t /* width from decompiler */ **)(unaff_EDI + 4)) || (*param_2 < (uint)puVar3[3])) {

    local_4 = 0;

    ExceptionList = &local_c;

    FUN_00462be0(local_1c);

    local_4._0_1_ = 1;

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00462640(puVar3);

    puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

    local_4 = (uint)local_4._1_3_ << 8;

    FUN_004627e0();

    local_4 = 0xffffffff;

    FUN_004627e0();

  }

  ExceptionList = local_c;

  return puVar3 + 4;

}
