// =============================================================================
// FUN_005778c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005778c0
// Address:   0x005778c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005778c0 @ 0x005778c0
// Stable ID: aa_005778c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_007a0120×4, CONCAT13×2, FUN_005774a0, FUN_005778c0.
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

void __thiscall FUN_005778c0(int param_1,uint32_t /* width from decompiler */ param_2,float param_3)



{

  float fVar1;

  float fVar2;

  uint32_t /* width from decompiler */ local_18;

  float local_14;

  uint32_t /* width from decompiler */ local_10;

  

  if (*(char *)(param_1 + 0x197) == '\0') {

    fVar1 = param_3 * g_flMultiKillCountBlend * *(float *)(param_1 + 0x1b8) +

            *(float *)(param_1 + 0x1bc);

    *(float *)(param_1 + 0x1bc) = fVar1;

    fVar2 = 0.0;

    if (*(float *)(param_1 + 0x1b8) < fVar1) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x1bc) = 0;

    }

    FUN_005774a0(&param_3,*(uint32_t /* width from decompiler */ *)(param_1 + 400));

    fVar1 = param_3;

    local_18 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e4);

    local_14 = *(float *)(param_1 + 0x1e8);

    local_10 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ec);

    if (*(int *)(param_1 + 8) == 0) {

      FUN_007a0120(0,2,4,0x17,0,0,0x3f800000,0,0x3fc00000,0x3fc00000,0,param_3,param_3,local_18,

                   local_14,local_10,local_18,local_14,local_10,DAT_00afdfc8,DAT_00afdfcc,

                   DAT_00afdfd0,DAT_00afdfd4,DAT_00afdfd8,DAT_00afdfdc,DAT_00d1a6c0,DAT_00d1a6c4,

                   DAT_00d1a6c8,1);

      fVar2 = 0.0;

    }

    if (*(char *)(param_1 + 0x194) != '\0') {

      local_14 = *(float *)(param_1 + 0x1ac) * DAT_00a0f298 + local_14;

      FUN_007a0120(1,0,4,0x58,0,0,0x3f800000,0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1b0),

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ac),0,fVar1,fVar1,local_18,local_14,local_10,

                   local_18,local_14,local_10,fVar2,g_flOne,fVar2,DAT_00afdfd4,DAT_00afdfd8,

                   DAT_00afdfdc,DAT_00d1a6c0,DAT_00d1a6c4,DAT_00d1a6c8,1);

      fVar2 = 0.0;

    }

    if (*(char *)(param_1 + 0x195) != '\0') {

      local_18 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1e4);

      local_14 = *(float *)(param_1 + 0x1e8);

      local_10 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ec);

      param_3 = (float)CONCAT13(200,param_3._0_3_);

      FUN_007a0120(2,(-(uint)(*(int *)(param_1 + 8) != 0) & 0xfffffffe) + 2,4,0x16,0,0,0x3f800000,0,

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b4),*(uint32_t /* width from decompiler */ *)(param_1 + 0x1b4),0,param_3,

                   param_3,local_18,local_14,local_10,local_18,local_14,local_10,fVar2,g_flOne,fVar2

                   ,DAT_00afdfd4,DAT_00afdfd8,DAT_00afdfdc,DAT_00d1a6c0,DAT_00d1a6c4,DAT_00d1a6c8,1)

      ;

      fVar2 = 0.0;

    }

    if ((*(char *)(param_1 + 0x196) != '\0') && (fVar2 < *(float *)(param_1 + 0x1b8))) {

      param_3 = (float)CONCAT13((char)(int)((g_flOne -

                                            *(float *)(param_1 + 0x1bc) /

                                            *(float *)(param_1 + 0x1b8)) * DAT_00aaaca8),

                                param_3._0_3_);

      FUN_007a0120(2,2,4,0x16,0,0,0x3f800000,0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1bc),

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0x1bc),0,param_3,param_3,local_18,local_14,local_10,

                   local_18,local_14,local_10,fVar2,g_flOne,fVar2,DAT_00afdfd4,DAT_00afdfd8,

                   DAT_00afdfdc,DAT_00d1a6c0,DAT_00d1a6c4,DAT_00d1a6c8,1);

    }

  }

  return;

}
