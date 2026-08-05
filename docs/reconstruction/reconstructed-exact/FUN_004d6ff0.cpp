// =============================================================================
// FUN_004d6ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d6ff0
// Address:   0x004d6ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d6ff0 @ 0x004d6ff0
// Stable ID: aa_004d6ff0
// Embedded strings (evidence for future rename):
//   - "ReadMusicRegions"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, for×1, while×1, return×1.
//  - Notable callees: FUN_004804d0, FUN_004d6ff0, FUN_0071f4d0, FUN_007a4390, FUN_007a4400.
//  - Strings: "ReadMusicRegions".
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

void __thiscall FUN_004d6ff0(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar3;

  uint8_t local_2f4 [4];

  uint32_t /* width from decompiler */ auStack_2f0 [181];

  void *pvStack_1c;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a214f;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  FUN_007a4400("ReadMusicRegions");

  iVar2 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe7cc) = 0;

  local_c = 0;

  (**(code **)(*param_2 + 0x14))(local_2f4,4);

  if (0 < unaff_ESI) {

    do {

      (**(code **)(*param_2 + 0x14))(local_2f4,4);

      puVar3 = auStack_2f0;

      for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      FUN_0071f4d0(param_2,param_3);

      FUN_004804d0(auStack_2f0);

      iVar2 = iVar2 + 1;

    } while (iVar2 < unaff_ESI);

  }

  pvStack_14 = (void *)0xffffffff;

  FUN_007a4390();

  ExceptionList = pvStack_1c;

  return;

}
