// =============================================================================
// FUN_004eb3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004eb3b0
// Address:   0x004eb3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004eb3b0 @ 0x004eb3b0
// Stable ID: aa_004eb3b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00402d50, FUN_004a1620, FUN_004a6390, FUN_004eb3b0, free.
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

void __fastcall FUN_004eb3b0(int param_1)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t *local_90;

  uint8_t local_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2770;

  local_c = ExceptionList;

  if ((((*(int *)(param_1 + 0x88) == 0) && (iVar1 = *(int *)(param_1 + 0x3c), iVar1 != 0)) &&

      (iVar1 != -0x316)) && ((*(short *)(iVar1 + 0x316) != 0 && (*(short *)(iVar1 + 0x318) != 0))))

  {

    ExceptionList = &local_c;

    pvVar2 = operator_new(8);

    local_4 = 0;

    if (pvVar2 == (void *)0x0) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_004a1620();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = uVar3;

    local_4 = 0xffffffff;

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00402d50(*(int *)(param_1 + 0x3c) + 0x316);

    local_4 = 1;

    FUN_004a6390(*puVar4);

    if (local_90 != local_8c) {

      free(local_90);

    }

  }

  ExceptionList = local_c;

  return;

}
