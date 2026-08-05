// =============================================================================
// FUN_0046f900
// -----------------------------------------------------------------------------
// Stable ID: aa_0046f900
// Address:   0x0046f900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046f900 @ 0x0046f900
// Stable ID: aa_0046f900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: ROUND×8, FUN_00476d60×2, FUN_0046f900.
//  - Return sites: 3.

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



void __thiscall

FUN_0046f900(int param_1,double param_2,double param_3,double param_4,double param_5,double param_6,

            double param_7,double param_8,double param_9)



{

  double dVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ local_c;

  

  if ((in_EAX != 0) && (param_1 != 0)) {

    if (((_DAT_00aaa608 <= param_2) &&

        (((_DAT_00aaa608 <= param_3 && (_DAT_00aaa608 <= param_4)) && (_DAT_00aaa608 <= param_5))))

       && ((((_DAT_00aaa608 <= param_6 && (_DAT_00aaa608 <= param_7)) && (_DAT_00aaa608 <= param_8))

           && (_DAT_00aaa608 <= param_9)))) {

      if (((param_2 <= _DAT_00aaa610) && (param_3 <= _DAT_00aaa610)) &&

         ((param_4 <= _DAT_00aaa610 &&

          ((((param_5 <= _DAT_00aaa610 && (param_6 <= _DAT_00aaa610)) && (param_7 <= _DAT_00aaa610))

           && ((param_8 <= _DAT_00aaa610 && (param_9 <= _DAT_00aaa610)))))))) {

        *(float *)(param_1 + 0x80) = (float)param_2;

        *(float *)(param_1 + 0x84) = (float)param_3;

        *(float *)(param_1 + 0x88) = (float)param_4;

        *(float *)(param_1 + 0x8c) = (float)param_5;

        *(float *)(param_1 + 0x90) = (float)param_6;

        *(float *)(param_1 + 0x94) = (float)param_7;

        *(float *)(param_1 + 0x98) = (float)param_8;

        *(float *)(param_1 + 0x9c) = (float)param_9;

        local_c = (uint32_t /* width from decompiler */)(longlong)ROUND(param_2 * _DAT_00aaa5e8 + _DAT_00aaa5e0);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x100) = local_c;

        local_c = (uint32_t /* width from decompiler */)(longlong)ROUND(param_3 * _DAT_00aaa5e8 + _DAT_00aaa5e0);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = local_c;

        local_c = (uint32_t /* width from decompiler */)(longlong)ROUND(param_4 * _DAT_00aaa5e8 + _DAT_00aaa5e0);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = local_c;

        local_c = (uint32_t /* width from decompiler */)(longlong)ROUND(param_5 * _DAT_00aaa5e8 + _DAT_00aaa5e0);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = local_c;

        local_c = (uint32_t /* width from decompiler */)(longlong)ROUND(param_6 * _DAT_00aaa5e8 + _DAT_00aaa5e0);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = local_c;

        local_c = (uint32_t /* width from decompiler */)(longlong)ROUND(param_7 * _DAT_00aaa5e8 + _DAT_00aaa5e0);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = local_c;

        local_c = (uint32_t /* width from decompiler */)(longlong)ROUND(param_8 * _DAT_00aaa5e8 + _DAT_00aaa5e0);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = local_c;

        dVar1 = param_9 * _DAT_00aaa5e8 + _DAT_00aaa5e0;

        *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;

        local_c = (uint32_t /* width from decompiler */)(longlong)ROUND(dVar1);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x11c) = local_c;

        return;

      }

      FUN_00476d60();

      return;

    }

    FUN_00476d60();

  }

  return;

}
