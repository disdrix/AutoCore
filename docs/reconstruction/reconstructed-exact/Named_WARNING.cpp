// =============================================================================
// Named_WARNING
// -----------------------------------------------------------------------------
// Stable ID: aa_00805140
// Address:   0x00805140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_WARNING @ 0x00805140
// Stable ID: aa_00805140
// Embedded strings (evidence for future rename):
//   - "WARNING: lgLcdInit failed\n"
//   - "My App"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_0048a083, FUN_007a4480, Named_WARNING, FUN_00805460, InterlockedDecrement, InterlockedIncrement.
//  - Strings: "WARNING: lgLcdInit failed\n"; "My App".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "WARNING: lgLcdInit failed
"
 * Domain alias of FUN_00805140 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_WARNING(void)



{

  LONG LVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *unaff_EBX;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar3;

  

  FUN_00805460();

  puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x78);

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x7c)) {

    do {

      (**(code **)(*(int *)*puVar3 + 4))();

      puVar3 = puVar3 + 1;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x7c));

  }

  LVar1 = InterlockedIncrement((LONG *)&DAT_00d17938);

  if (LVar1 == 1) {

    iVar2 = FUN_0048a083();

    if (iVar2 != 0) {

      InterlockedDecrement((LONG *)&DAT_00d17938);

      FUN_007a4480(0xffffffff,&DAT_00a2c2a4,"WARNING: lgLcdInit failed\n");

      return 0x80004005;

    }

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x9c) = "My App";

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa0) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xb0) = 0xffffffff;

  if (unaff_EBX != (uint32_t /* width from decompiler */ *)0x0) {

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x9c) = *unaff_EBX;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa0) = unaff_EBX[1];

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa4) = unaff_EBX[2];

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xa8) = unaff_EBX[3];

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xac) = unaff_EBX[4];

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xb0) = unaff_EBX[5];

  }

  return 0;

}
