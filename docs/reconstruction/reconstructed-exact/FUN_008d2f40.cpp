// =============================================================================
// FUN_008d2f40
// -----------------------------------------------------------------------------
// Stable ID: aa_008d2f40
// Address:   0x008d2f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d2f40 @ 0x008d2f40
// Stable ID: aa_008d2f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0051ffb0, FUN_00521b40, FUN_008d2f40, FUN_0096c450.
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

void FUN_008d2f40(int param_1)



{

  char cVar1;

  int *in_EAX;

  int iVar2;

  int *piVar3;

  uint8_t *puStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint8_t uStack_1c;

  uint8_t uStack_1b;

  uint8_t uStack_1a;

  uint8_t uStack_19;

  uint32_t /* width from decompiler */ uStack_14;

  uint8_t auStack_10 [16];

  

  if (in_EAX != (int *)0x0) {

    iVar2 = (**(code **)(*in_EAX + 700))();

    if ((iVar2 != 0) && (*(int *)(param_1 + 0x544) != 0)) {

      uStack_30 = 1;

      uStack_1a = 0xff;

      uStack_1b = 0xff;

      uStack_1c = 0xff;

      uStack_19 = 0xff;

      uStack_34 = 1;

      puStack_38 = auStack_10;

      (**(code **)(*in_EAX + 0x120))();

      (**(code **)(*in_EAX + 700))();

      (**(code **)(*in_EAX + 0x140))(&uStack_1c,1);

      (**(code **)(*in_EAX + 0x140))(&uStack_1c,1);

      piVar3 = (int *)(**(code **)(*in_EAX + 700))();

      if (*piVar3 != 0) {

        cVar1 = FUN_0096c450(&puStack_38);

        if (cVar1 != '\0') {

          FUN_0051ffb0(uStack_14,puStack_38);

          FUN_00521b40();

        }

      }

    }

  }

  return;

}
