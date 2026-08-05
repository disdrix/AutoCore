// =============================================================================
// Gfx_Can_save_image_WBMP
// -----------------------------------------------------------------------------
// Stable ID: aa_0098b4d0
// Address:   0x0098b4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_Can_save_image_WBMP @ 0x0098b4d0
// Stable ID: aa_0098b4d0
// Embedded strings (evidence for future rename):
//   - "Can\'t save this image as WBMP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1, for×1.
//  - Notable callees: FUN_00432b60, FUN_00433d30, FUN_00435240, Gfx_Can_save_image_WBMP.
//  - Strings: "Can\'t save this image as WBMP".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Can't save this image as WBMP"
 * Domain alias of FUN_0098b4d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Gfx_Can_save_image_WBMP(int param_1)



{

  uint uVar1;

  char cVar2;

  int *in_EAX;

  uint unaff_EBX;

  int iVar3;

  int unaff_ESI;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t local_1c;

  uint8_t local_1b;

  uint8_t local_1a;

  uint8_t local_19;

  int iStack_14;

  int iStack_10;

  

  cVar2 = FUN_00432b60(in_EAX);

  if (cVar2 == '\0') {

    if (((*(int *)(param_1 + 0xc) < 0x100) && (*(int *)(param_1 + 0x10) < 0x100)) &&

       (*(short *)(param_1 + 0x16) == 1)) {

      local_1a = *(uint8_t *)(param_1 + 0xc);

      local_19 = *(uint8_t *)(param_1 + 0x10);

      iVar3 = 0;

      local_1c = 0;

      local_1b = 0;

      (**(code **)(*in_EAX + 0xc))(&local_1c,4,1);

      uVar1 = unaff_EBX >> 0x10;

      FUN_00433d30();

      FUN_00435240();

      if ((char)(unaff_EBX >> 0x18) != '\0') {

        do {

          (**(code **)(*in_EAX + 0xc))(iStack_14,(int)((uVar1 & 0xff) + 7) >> 3,1);

          unaff_ESI = unaff_ESI + -1;

          if (-1 < unaff_ESI) {

            iStack_14 = iStack_14 - *(int *)(iStack_10 + 0x30);

          }

          iVar3 = iVar3 + 1;

        } while (iVar3 < (int)(unaff_EBX >> 0x18));

      }

      return 1;

    }

    pcVar4 = "Can\'t save this image as WBMP";

    puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x44);

    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *(uint32_t /* width from decompiler */ *)pcVar4;

      pcVar4 = pcVar4 + 4;

      puVar5 = puVar5 + 1;

    }

    *(uint16_t *)puVar5 = *(uint16_t *)pcVar4;

  }

  return 0;

}
