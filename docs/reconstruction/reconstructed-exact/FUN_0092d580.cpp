// =============================================================================
// FUN_0092d580
// -----------------------------------------------------------------------------
// Stable ID: aa_0092d580
// Address:   0x0092d580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092d580 @ 0x0092d580
// Stable ID: aa_0092d580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_0092d580.
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

void __fastcall FUN_0092d580(int param_1,uint param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  

  if ((int)param_2 < 7) {

    if ((int)param_2 < 5) {

      if ((int)param_2 < 3) {

        if ((int)param_2 < 1) {

          if ((int)param_2 < -4) {

            puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0xbe4);

          }

          else if ((int)param_2 < -2) {

            puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0xbf4);

          }

          else if (param_2 < 0x80000000) {

            puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0xc14);

          }

          else {

            puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0xc04);

          }

        }

        else {

          puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0xc24);

        }

      }

      else {

        puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0xc34);

      }

    }

    else {

      puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0xc44);

    }

  }

  else {

    puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0xc54);

  }

  *in_EAX = *puVar1;

  in_EAX[1] = puVar1[1];

  in_EAX[2] = puVar1[2];

  in_EAX[3] = puVar1[3];

  return;

}
