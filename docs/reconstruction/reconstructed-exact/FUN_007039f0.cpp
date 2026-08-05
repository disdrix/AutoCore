// =============================================================================
// FUN_007039f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007039f0
// Address:   0x007039f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007039f0 @ 0x007039f0
// Stable ID: aa_007039f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_006a3db0, FUN_007039f0.
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



void __thiscall FUN_007039f0(int param_1,int param_2)



{

  float fVar1;

  uint16_t uVar2;

  float *in_EAX;

  int unaff_EBX;

  int iVar3;

  

  iVar3 = 0;

  if (0 < param_2) {

    param_1 = param_1 - (int)in_EAX;

    do {

      fVar1 = *(float *)(param_1 + (int)in_EAX) - *in_EAX;

      fVar1 = fVar1 + fVar1;

      if (fVar1 <= _DAT_00a0f164) {

        if (_DAT_00a0f160 <= fVar1) {

          uVar2 = FUN_006a3db0();

          *(uint16_t *)(unaff_EBX + iVar3 * 2) = uVar2;

        }

        else {

          *(uint16_t *)(unaff_EBX + iVar3 * 2) = 0x8001;

        }

      }

      else {

        *(uint16_t *)(unaff_EBX + iVar3 * 2) = 0x7fff;

      }

      iVar3 = iVar3 + 1;

      in_EAX = in_EAX + 1;

    } while (iVar3 < param_2);

  }

  return;

}
