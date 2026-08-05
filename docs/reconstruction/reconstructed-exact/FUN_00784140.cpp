// =============================================================================
// FUN_00784140
// -----------------------------------------------------------------------------
// Stable ID: aa_00784140
// Address:   0x00784140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00784140 @ 0x00784140
// Stable ID: aa_00784140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, goto×1.
//  - Notable callees: FUN_00784000×3, FUN_00784140.
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

uint FUN_00784140(uint32_t /* width from decompiler */ param_1,short *param_2,uint32_t /* width from decompiler */ param_3)



{

  uint *puVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint unaff_EBX;

  uint *unaff_ESI;

  uint uVar5;

  

  uVar4 = *unaff_ESI;

  uVar2 = unaff_ESI[1];

  if (uVar4 < uVar2) {

    uVar2 = uVar2 - uVar4;

    uVar4 = uVar2;

  }

  else {

    if (((char)unaff_ESI[4] == '\0') && (uVar4 == uVar2)) goto LAB_00784172;

    uVar4 = uVar2 + (unaff_ESI[3] - uVar4);

  }

  if (uVar4 != 0) {

    if ((char)param_3 == '\0') {

      if (unaff_EBX < uVar4) {

        uVar4 = unaff_EBX;

      }

      uVar4 = FUN_00784000(param_1,uVar4,param_2);

      return uVar4;

    }

    if (1 < uVar4) {

      puVar1 = unaff_ESI + 2;

      if ((ushort)unaff_ESI[2] == 0) {

        param_3 = 0;

        FUN_00784000(puVar1,2,&param_3);

        uVar3 = (uint)(ushort)*puVar1;

        uVar2 = unaff_EBX;

        if (uVar3 <= unaff_EBX) {

          uVar2 = uVar3;

        }

        uVar5 = uVar4;

        if ((uVar2 < uVar4) && (uVar5 = uVar3, unaff_EBX < uVar3)) {

          uVar5 = unaff_EBX;

        }

      }

      else {

        uVar3 = (uint)(ushort)unaff_ESI[2];

        uVar2 = unaff_EBX;

        if (uVar3 <= unaff_EBX) {

          uVar2 = uVar3;

        }

        if ((uVar4 <= uVar2) || (uVar4 = uVar3, uVar5 = unaff_EBX, uVar3 <= unaff_EBX)) {

          uVar5 = uVar4;

        }

      }

      uVar4 = FUN_00784000(param_1,uVar5,param_2);

      if ((char)uVar4 != '\0') {

        *(ushort *)puVar1 = (ushort)*puVar1 - *param_2;

      }

      return uVar4;

    }

  }

LAB_00784172:

  return uVar2 & 0xffffff00;

}
