// =============================================================================
// FUN_007ac940
// -----------------------------------------------------------------------------
// Stable ID: aa_007ac940
// Address:   0x007ac940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ac940 @ 0x007ac940
// Stable ID: aa_007ac940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, do×1, while×1, return×1.
//  - Notable callees: block×56, FUN_00403450, FUN_00798bb0, FUN_007ac940, SysFreeString, free.
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

/* WARNING: Removing unreachable block (ram,0x007aca2c) */

/* WARNING: Removing unreachable block (ram,0x007aca47) */

/* WARNING: Removing unreachable block (ram,0x007aca54) */

/* WARNING: Removing unreachable block (ram,0x007aca6c) */

/* WARNING: Removing unreachable block (ram,0x007aca9a) */

/* WARNING: Removing unreachable block (ram,0x007acb06) */

/* WARNING: Removing unreachable block (ram,0x007acb66) */

/* WARNING: Removing unreachable block (ram,0x007acbdd) */

/* WARNING: Removing unreachable block (ram,0x007acc54) */

/* WARNING: Removing unreachable block (ram,0x007acc87) */

/* WARNING: Removing unreachable block (ram,0x007accc4) */

/* WARNING: Removing unreachable block (ram,0x007accdb) */

/* WARNING: Removing unreachable block (ram,0x007accf6) */

/* WARNING: Removing unreachable block (ram,0x007acd0d) */

/* WARNING: Removing unreachable block (ram,0x007acd10) */

/* WARNING: Removing unreachable block (ram,0x007acd28) */

/* WARNING: Removing unreachable block (ram,0x007acdb5) */

/* WARNING: Removing unreachable block (ram,0x007ace2a) */

/* WARNING: Removing unreachable block (ram,0x007ace9c) */

/* WARNING: Removing unreachable block (ram,0x007aceaf) */

/* WARNING: Removing unreachable block (ram,0x007acee1) */

/* WARNING: Removing unreachable block (ram,0x007acef7) */

/* WARNING: Removing unreachable block (ram,0x007ace3d) */

/* WARNING: Removing unreachable block (ram,0x007ace6f) */

/* WARNING: Removing unreachable block (ram,0x007ace85) */

/* WARNING: Removing unreachable block (ram,0x007acdc8) */

/* WARNING: Removing unreachable block (ram,0x007acdfa) */

/* WARNING: Removing unreachable block (ram,0x007ace10) */

/* WARNING: Removing unreachable block (ram,0x007acd53) */

/* WARNING: Removing unreachable block (ram,0x007acd85) */

/* WARNING: Removing unreachable block (ram,0x007acd9b) */

/* WARNING: Removing unreachable block (ram,0x007acf0c) */

/* WARNING: Removing unreachable block (ram,0x007acf16) */

/* WARNING: Removing unreachable block (ram,0x007acf23) */

/* WARNING: Removing unreachable block (ram,0x007acc9a) */

/* WARNING: Removing unreachable block (ram,0x007acc63) */

/* WARNING: Removing unreachable block (ram,0x007acbf4) */

/* WARNING: Removing unreachable block (ram,0x007acc24) */

/* WARNING: Removing unreachable block (ram,0x007acc3a) */

/* WARNING: Removing unreachable block (ram,0x007acb79) */

/* WARNING: Removing unreachable block (ram,0x007acbad) */

/* WARNING: Removing unreachable block (ram,0x007acbc3) */

/* WARNING: Removing unreachable block (ram,0x007acb15) */

/* WARNING: Removing unreachable block (ram,0x007acb58) */

/* WARNING: Removing unreachable block (ram,0x007acb49) */

/* WARNING: Removing unreachable block (ram,0x007acaad) */

/* WARNING: Removing unreachable block (ram,0x007acadd) */

/* WARNING: Removing unreachable block (ram,0x007acaed) */

/* WARNING: Removing unreachable block (ram,0x007acf2d) */

/* WARNING: Removing unreachable block (ram,0x007acf37) */

/* WARNING: Removing unreachable block (ram,0x007acf4c) */

/* WARNING: Removing unreachable block (ram,0x007acf4d) */

/* WARNING: Removing unreachable block (ram,0x007acf61) */

/* WARNING: Removing unreachable block (ram,0x007acf6a) */

/* WARNING: Removing unreachable block (ram,0x007acf72) */

/* WARNING: Removing unreachable block (ram,0x007acf86) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_007ac940(int *param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piStack_ca8;

  OLECHAR local_ca0 [4];

  char *pcStack_c98;

  char acStack_c94 [128];

  char acStack_c14 [8];

  uint16_t local_c0c;

  uint32_t /* width from decompiler */ local_c0a [763];

  void *pvStack_1c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ac3fe;

  pvStack_c = ExceptionList;

  local_4 = 0;

  local_c0c = 0;

  puVar4 = local_c0a;

  for (iVar3 = 0xff; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  ExceptionList = &pvStack_c;

  iVar3 = (**(code **)(*param_1 + 0x44))();

  if ((iVar3 == 0) && (piStack_ca8 != (int *)0x0)) {

    cVar1 = FUN_00798bb0();

    if (cVar1 != '\0') {

      pcStack_c98 = acStack_c94;

      (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450();

      pcVar2 = pcStack_c98;

      do {

        cVar1 = *pcVar2;

        pcVar2[(int)(acStack_c14 + -(int)pcStack_c98)] = cVar1;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      if (pcStack_c98 != acStack_c94) {

        free(pcStack_c98);

      }

    }

    (**(code **)(*piStack_ca8 + 8))();

  }

  (**(code **)(*param_1 + 0x30))();

  SysFreeString(local_ca0);

  ExceptionList = pvStack_1c;

  return;

}
