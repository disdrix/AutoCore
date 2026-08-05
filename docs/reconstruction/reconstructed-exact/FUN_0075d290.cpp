// =============================================================================
// FUN_0075d290
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d290
// Address:   0x0075d290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075d290 @ 0x0075d290
// Stable ID: aa_0075d290
// Embedded strings (evidence for future rename):
//   - "%s\tProxy%u\tPtr0x%x\n"
//   - "%s\tProxy%u\tPtr0x%x\tBlock%u\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: _snprintf×2, FUN_00745df0, FUN_0075d290, OutputDebugStringA.
//  - Strings: "%s\tProxy%u\tPtr0x%x\n"; "%s\tProxy%u\tPtr0x%x\tBlock%u\n".
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

void FUN_0075d290(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar5;

  undefined *puVar6;

  char local_208 [520];

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 8);

  for (puVar2 = (uint32_t /* width from decompiler */ *)*puVar1; puVar2 != puVar1; puVar2 = (uint32_t /* width from decompiler */ *)*puVar2) {

    iVar3 = puVar2[3];

    puVar6 = (undefined *)puVar2[2];

    if (iVar3 == 0) {

      if (puVar6 == (undefined *)0x0) {

        puVar6 = PTR_DAT_00afa2bc;

      }

      _snprintf(local_208,0x208,"%s\tProxy%u\tPtr0x%x\n",puVar6,puVar2[4],0);

    }

    else {

      uVar4 = puVar2[4];

      if (puVar6 == (undefined *)0x0) {

        puVar6 = PTR_DAT_00afa2bc;

      }

      uVar5 = FUN_00745df0();

      _snprintf(local_208,0x208,"%s\tProxy%u\tPtr0x%x\tBlock%u\n",puVar6,uVar4,iVar3,uVar5);

    }

    OutputDebugStringA(local_208);

  }

  return;

}
