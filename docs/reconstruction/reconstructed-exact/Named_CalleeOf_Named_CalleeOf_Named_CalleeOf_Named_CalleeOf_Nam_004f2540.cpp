// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004f2540
// -----------------------------------------------------------------------------
// Stable ID: aa_004f2540
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004f2540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "FillPreloadList". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "FillPreloadList"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_0076cef0×2, FUN_0043d650, FUN_0043e3d0, FUN_004eb1c0, FUN_004ebf50, FUN_004ec430, FUN_004ec7b0, FUN_004f1ff0.
//  - Strings: "FillPreloadList".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004f2540(int param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t *puVar7;

  uint8_t local_11c [4];

  uint8_t local_118 [4];

  uint8_t local_114 [4];

  char local_110 [4];

  uint8_t local_10c [256];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2bbe;

  local_c = ExceptionList;

  local_114 = (uint8_t  [4])DAT_00d1f040;

  ExceptionList = &local_c;

  FUN_0076cf00("FillPreloadList");

  local_4 = 0;

  FUN_0043d650(0);

  pcVar4 = (char *)(param_1 + 0x188);

  if (((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) || (*pcVar4 == ' ')) {

    local_4 = 0xffffffff;

    FUN_0076cef0();

    uVar5 = 0;

  }

  else {

    FUN_004eb1c0(local_11c);

    FUN_00744360(local_11c,param_1 + 0x110);

    if (*(int *)(DAT_00d1f050 + 0x6c) != 0) {

      FUN_004f1ff0(param_1 + 0x124);

    }

    if (*(short *)(*(int *)(param_1 + 0x3c) + 0x3f4) == 3) {

      iVar2 = -(int)pcVar4;

      do {

        cVar1 = *pcVar4;

        pcVar4[(int)(local_110 + iVar2)] = cVar1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      puVar3 = (uint32_t /* width from decompiler */ *)(local_114 + 3);

      do {

        puVar6 = puVar3;

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      } while (*(char *)((int)puVar6 + 1) != '\0');

      *(uint32_t /* width from decompiler */ *)((int)puVar6 + 1) = DAT_009cd088;

      *(uint8_t *)((int)puVar6 + 5) = DAT_009cd08c;

      FUN_00989e00(local_118,local_110);

      puVar7 = local_118;

    }

    else {

      puVar7 = local_11c;

    }

    FUN_0043e3d0(puVar7);

    if (*(int *)(DAT_00d1f050 + 0x6c) != 0) {

      FUN_004ec430(param_1 + 0x138);

      FUN_004ec7b0(param_1 + 0x14c);

      FUN_004ebf50(param_1 + 0x160);

    }

    local_4 = 0xffffffff;

    FUN_0076cef0();

    uVar5 = 1;

  }

  ExceptionList = local_c;

  return uVar5;

}
