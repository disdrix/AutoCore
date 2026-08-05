// =============================================================================
// FUN_005832b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005832b0
// Address:   0x005832b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005832b0 @ 0x005832b0
// Stable ID: aa_005832b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00972cc0×3, FUN_0040cf90×2, FUN_0040d1a0×2, FUN_00973030×2, FUN_005832b0, FUN_0076e6b0, FUN_00972970, FUN_00972e50.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall

FUN_005832b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  int *piVar1;

  uint8_t *puVar2;

  float fStack_264;

  float fStack_260;

  float fStack_25c;

  uint8_t auStack_258 [128];

  uint8_t auStack_1d8 [52];

  int iStack_1a4;

  uint uStack_19c;

  uint8_t local_190 [120];

  uint32_t /* width from decompiler */ uStack_118;

  uint32_t /* width from decompiler */ uStack_114;

  uint32_t /* width from decompiler */ uStack_110;

  uint32_t /* width from decompiler */ uStack_10c;

  uint32_t /* width from decompiler */ uStack_108;

  uint32_t /* width from decompiler */ uStack_104;

  uint32_t /* width from decompiler */ uStack_100;

  uint8_t auStack_d8 [128];

  uint8_t auStack_58 [16];

  float fStack_48;

  float fStack_44;

  float fStack_40;

  

  if (*(int *)(param_1 + 8) != 0) {

    if ((_DAT_00b04cb0 & 1) == 0) {

      _DAT_00b04cb0 = _DAT_00b04cb0 | 1;

      _DAT_00b04ca0 = DAT_009d46d0;

      _DAT_00b04ca4 = 0;

      _DAT_00b04ca8 = 0;

      _DAT_00b04cac = DAT_009d46cc;

    }

    if (*(int *)(*(int *)(param_1 + 8) + 100) != 0) {

      piVar1 = (int *)FUN_00989270(param_2);

      if (piVar1 != (int *)0x0) {

        FUN_00972cc0();

        (**(code **)(**(int **)(param_1 + 8) + 0x34))();

        (**(code **)(**(int **)(param_1 + 8) + 8))(*(uint32_t /* width from decompiler */ *)(*piVar1 + 0xc),local_190);

        FUN_00972cc0();

        FUN_0040cf90(*piVar1 + 0x20);

        FUN_0040d1a0(*piVar1 + 0x10);

        FUN_00973030(auStack_d8);

        fStack_264 = 0.0;

        fStack_260 = 0.0;

        fStack_25c = 0.0;

        FUN_0040cf90(&fStack_264);

        FUN_0040d1a0(&DAT_00b04ca0);

        FUN_00972cc0();

        iStack_1a4 = iStack_1a4 + 1;

        uStack_19c = 0xffffffff;

        FUN_0076e6b0(auStack_1d8,auStack_58);

        fStack_264 = 0.0 - fStack_48;

        fStack_260 = 0.0 - fStack_44;

        fStack_25c = 0.0 - fStack_40;

        if ((uStack_19c & 1) == 0) {

          puVar2 = auStack_258;

        }

        else {

          puVar2 = (uint8_t *)FUN_00972e50();

        }

        iStack_1a4 = iStack_1a4 + 1;

        uStack_19c = 0xffffffff;

        FUN_00972970(puVar2,&fStack_264);

        FUN_00973030(auStack_258);

        *param_3 = uStack_108;

        param_3[1] = uStack_104;

        param_3[2] = uStack_100;

        *param_4 = uStack_118;

        param_4[1] = uStack_114;

        param_4[2] = uStack_110;

        param_4[3] = uStack_10c;

        return 1;

      }

    }

  }

  return 0;

}
