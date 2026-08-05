// =============================================================================
// FUN_006ebed0
// -----------------------------------------------------------------------------
// Stable ID: aa_006ebed0
// Address:   0x006ebed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ebed0 @ 0x006ebed0
// Stable ID: aa_006ebed0
// Embedded strings (evidence for future rename):
//   - "LtBvTree"
//   - "StNarrowPhase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×6, for×1, return×1.
//  - Notable callees: FUN_00404cf0×5, FUN_00404d00×3, rdtsc×3, FUN_0040ab80, FUN_00428050, FUN_005edf20, FUN_006e7740, FUN_006ea340.
//  - Strings: "LtBvTree"; "StNarrowPhase".
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

void FUN_006ebed0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint64_t uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  char cVar4;

  int *piVar5;

  uint8_t local_3a1;

  code *local_3a0;

  int local_39c;

  uint32_t /* width from decompiler */ local_398;

  int *local_394;

  uint8_t local_390 [259];

  uint8_t local_28d;

  int *local_28c;

  int *local_288;

  uint32_t /* width from decompiler */ local_284;

  uint32_t /* width from decompiler */ local_280;

  uint32_t /* width from decompiler */ *local_27c;

  uint32_t /* width from decompiler */ *local_278;

  uint32_t /* width from decompiler */ *local_274;

  int local_270;

  int *local_26c;

  uint32_t /* width from decompiler */ local_264;

  uint32_t /* width from decompiler */ *local_260;

  uint32_t /* width from decompiler */ *local_258;

  int local_254;

  uint local_250;

  uint32_t /* width from decompiler */ local_24c [130];

  int *local_44;

  uint8_t local_40 [36];

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ *local_18;

  

  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);

  cVar4 = FUN_00404cf0();

  if (cVar4 != '\0') {

    local_18 = DAT_00bc5644;

    *DAT_00bc5644 = "LtBvTree";

    uVar1 = rdtsc();

    local_1c = (uint32_t /* width from decompiler */)uVar1;

    DAT_00bc5644[1] = local_1c;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  FUN_005edf20();

  FUN_006ea340(param_1,param_2,param_3,local_40);

  local_44 = (int *)*param_2;

  local_258 = local_24c;

  local_254 = 0;

  local_250 = 0x80000080;

  (**(code **)(*local_44 + 0x30))(local_40,&local_258);

  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);

  cVar4 = FUN_00404cf0();

  if (cVar4 != '\0') {

    local_260 = DAT_00bc5644;

    *DAT_00bc5644 = "StNarrowPhase";

    uVar1 = rdtsc();

    local_264 = (uint32_t /* width from decompiler */)uVar1;

    DAT_00bc5644[1] = local_264;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_26c = (int *)*param_1;

  local_270 = (**(code **)(*local_26c + 0x14))();

  local_274 = local_258;

  local_278 = local_258 + local_254;

  local_27c = param_2;

  local_280 = param_2[2];

  local_28c = (int *)FUN_00428050();

  for (; local_274 != local_278; local_274 = local_274 + 1) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_3[1])(&local_28d,param_3,param_1,param_2,local_28c,*local_274);

    cVar4 = FUN_00404cf0();

    if (cVar4 != '\0') {

      local_394 = (int *)(**(code **)(*local_28c + 0x34))(*local_274,local_390);

      local_398 = *local_274;

      local_288 = local_394;

      local_284 = local_398;

      local_39c = (**(code **)(*local_394 + 0x14))();

      local_3a0 = *(code **)(*param_3 + 0x118c + local_270 * 0x80 + local_39c * 4);

      (*local_3a0)(param_1,&local_288,param_3,param_4);

      FUN_006e7740(&local_3a1);

      cVar4 = FUN_00404cf0();

      if (cVar4 != '\0') break;

    }

  }

  FUN_00404d00(DAT_00bc5644 < DAT_00bc5648);

  cVar4 = FUN_00404cf0();

  uVar3 = local_250;

  puVar2 = local_258;

  if (cVar4 != '\0') {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  if ((local_250 & 0x80000000) == 0) {

    piVar5 = (int *)FUN_0040ab80();

    (**(code **)(*piVar5 + 0x14))(puVar2,uVar3 << 2,0x12);

  }

  return;

}
