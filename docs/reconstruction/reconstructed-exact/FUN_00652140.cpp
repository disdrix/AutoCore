// =============================================================================
// FUN_00652140
// -----------------------------------------------------------------------------
// Stable ID: aa_00652140
// Address:   0x00652140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00652140 @ 0x00652140
// Stable ID: aa_00652140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: CONCAT44×3, QueryPerformanceCounter×2, FUN_00652140, FUN_006a3db0, QueryPerformanceFrequency.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_00652140(int *param_1)



{

  double dVar1;

  int iVar2;

  uint uVar3;

  uint64_t uVar4;

  longlong lVar5;

  int local_4c;

  double local_48;

  LARGE_INTEGER LStack_30;

  LARGE_INTEGER LStack_28;

  int iStack_20;

  uint uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint uStack_14;

  int iStack_c;

  

  uVar4 = CONCAT44(DAT_00d034ec,DAT_00d034e8);

  if (DAT_00d034e8 == 0 && DAT_00d034ec == 0) {

    local_4c = 10;

    local_48 = _DAT_009e5b10;

    do {

      uVar4 = (**(code **)(*param_1 + 4))();

      iStack_c = (int)((ulonglong)uVar4 >> 0x20);

      QueryPerformanceCounter(&LStack_28);

      iVar2 = 5000;

      do {

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

      lVar5 = (**(code **)(*param_1 + 4))();

      QueryPerformanceCounter(&LStack_30);

      QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_00d034e8);

      iStack_20 = LStack_30.s.LowPart - LStack_28._0_4_;

      uVar3 = (LStack_30.s.HighPart - LStack_28._4_4_) -

              (uint)(LStack_30.s.LowPart < LStack_28.s.LowPart);

      uStack_1c = uVar3 & 0x7fffffff;

      uStack_14 = uVar3 & 0x80000000;

      uStack_18 = 0;

      dVar1 = (-(double)(longlong)

                        (((ulonglong)

                          (((int)((ulonglong)lVar5 >> 0x20) - iStack_c) -

                          (uint)((uint)lVar5 < (uint)uVar4)) & 0x80000000) << 0x20) +

              (double)(lVar5 - CONCAT44(iStack_c,(uint)uVar4) & 0x7fffffffffffffff)) /

              (-(double)(longlong)(((ulonglong)uVar3 & 0x80000000) << 0x20) +

              (double)(CONCAT44(uVar3,iStack_20) & 0x7fffffffffffffff));

      if (dVar1 < local_48) {

        local_48 = dVar1;

      }

      local_4c = local_4c + -1;

    } while (local_4c != 0);

    uStack_14 = DAT_00d034ec & 0x80000000;

    uStack_18 = 0;

    uVar4 = FUN_006a3db0();

  }

  DAT_00d034ec = (uint)((ulonglong)uVar4 >> 0x20);

  DAT_00d034e8 = (int)uVar4;

  return;

}
