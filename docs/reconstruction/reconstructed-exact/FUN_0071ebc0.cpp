// =============================================================================
// FUN_0071ebc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071ebc0
// Address:   0x0071ebc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071ebc0 @ 0x0071ebc0
// Stable ID: aa_0071ebc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, do×2, while×2, for×1.
//  - Notable callees: ov_read×2, FUN_0071ebc0.
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

uint32_t /* width from decompiler */ FUN_0071ebc0(uint param_1,uint *param_2)



{

  uint uVar1;

  uint16_t *in_EAX;

  int iVar2;

  uint16_t *puVar3;

  int iVar4;

  int unaff_EBX;

  uint uVar5;

  uint32_t /* width from decompiler */ local_4;

  

  uVar5 = 0;

  local_4 = 0;

  if (*(int *)(unaff_EBX + 0x40) == 0) {

    return 0x80004005;

  }

  if ((*(int *)(unaff_EBX + 4) == 0) ||

     (uVar1 = param_1, *(int *)(*(int *)(unaff_EBX + 4) + 4) != 6)) {

    do {

      if (param_1 <= uVar5) break;

      iVar2 = ov_read(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40),uVar5 + (int)in_EAX,param_1 - uVar5,0,2,1,

                      &local_4);

      uVar5 = uVar5 + iVar2;

    } while (iVar2 != 0);

    *param_2 = uVar5;

    return 0;

  }

  for (; 0xb < (int)uVar1; uVar1 = uVar1 - iVar2) {

    uVar5 = uVar1;

    if (0x2fff < uVar1) {

      uVar5 = 0x3000;

    }

    iVar2 = ov_read(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x40),&DAT_00d0e658,uVar5,0,2,1,&local_4);

    if (iVar2 == 0) break;

    iVar4 = iVar2 / 0xc;

    if (0 < iVar4) {

      puVar3 = &DAT_00d0e65c;

      do {

        *in_EAX = puVar3[-2];

        in_EAX[1] = *puVar3;

        in_EAX[2] = puVar3[-1];

        in_EAX[3] = puVar3[3];

        in_EAX[4] = puVar3[1];

        in_EAX[5] = puVar3[2];

        in_EAX = in_EAX + 6;

        puVar3 = puVar3 + 6;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

    }

  }

  *param_2 = param_1 - uVar1;

  return 0;

}
