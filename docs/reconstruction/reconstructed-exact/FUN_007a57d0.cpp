// =============================================================================
// FUN_007a57d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a57d0
// Address:   0x007a57d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a57d0 @ 0x007a57d0
// Stable ID: aa_007a57d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, goto×1, return×1.
//  - Notable callees: block×10, FUN_00456960, FUN_007a57d0, memmove.
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

/* WARNING: Removing unreachable block (ram,0x007a5888) */

/* WARNING: Removing unreachable block (ram,0x007a589c) */

/* WARNING: Removing unreachable block (ram,0x007a593b) */

/* WARNING: Removing unreachable block (ram,0x007a58fc) */

/* WARNING: Removing unreachable block (ram,0x007a5900) */

/* WARNING: Removing unreachable block (ram,0x007a590b) */

/* WARNING: Removing unreachable block (ram,0x007a590d) */

/* WARNING: Removing unreachable block (ram,0x007a5920) */

/* WARNING: Removing unreachable block (ram,0x007a5916) */

/* WARNING: Removing unreachable block (ram,0x007a5928) */



void __fastcall FUN_007a57d0(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *_Dst;

  int *local_24;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac376;

  pvStack_c = ExceptionList;

  local_4 = 0;

  _Dst = *(int **)(param_1 + 0x18);

  piVar4 = *(int **)(param_1 + 0x1c);

  if (_Dst != piVar4) {

    local_24 = _Dst + 1;

    ExceptionList = &pvStack_c;

    do {

      iVar1 = *_Dst;

      if ((*(uint *)(iVar1 + 0x1f0) & *(uint *)(iVar1 + 500)) == 0xffffffff) {

        piVar3 = *(int **)(param_1 + 0x18);

        if (piVar3 != piVar4) {

          do {

            iVar2 = *piVar3;

            if ((((*(uint *)(iVar2 + 0x1f0) & *(uint *)(iVar2 + 500)) != 0xffffffff) &&

                (*(int *)(iVar2 + 0x200) == *(int *)(iVar1 + 0x240))) &&

               (*(int *)(iVar2 + 0x204) == *(int *)(iVar1 + 0x244))) break;

            piVar3 = piVar3 + 1;

          } while (piVar3 != piVar4);

          if (piVar3 != piVar4) goto LAB_007a58e1;

        }

        FUN_00456960(0);

        memmove(_Dst,local_24,(*(int *)(param_1 + 0x1c) - (int)local_24 >> 2) * 4);

        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -4;

      }

      else {

LAB_007a58e1:

        _Dst = _Dst + 1;

        local_24 = local_24 + 1;

      }

      piVar4 = *(int **)(param_1 + 0x1c);

    } while (_Dst != piVar4);

  }

  ExceptionList = pvStack_c;

  return;

}
