// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response_00784bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00784bd0
// Callee of Named_CalleeOf_Named_Sending_Challenge_Response_8x
// Address:   0x00784bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Sending_Challenge_Response_8x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×10, return×4.
//  - Notable callees: FUN_00783e00×2, FUN_00783f10, FUN_00784000, FUN_00784bd0, send.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Sending_Challenge_Response_8x
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_Sending_Challenge_Response_00784bd0(void)



{

  uint *puVar1;

  char cVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  int iVar6;

  SOCKET *unaff_EDI;

  uint local_5d8;

  char local_5d4 [1492];

  

  puVar1 = (uint *)unaff_EDI[2];

  if (puVar1 != (uint *)0x0) {

    uVar3 = *puVar1;

    uVar5 = puVar1[1];

    if (uVar3 < uVar5) {

      iVar6 = -uVar3;

    }

    else {

      iVar6 = puVar1[3] - uVar3;

      if (((char)puVar1[4] == '\0') && (uVar3 == uVar5)) {

        return 0;

      }

    }

    if (uVar5 + iVar6 != 0) {

      uVar3 = *puVar1;

      uVar5 = puVar1[1];

      if (uVar3 < uVar5) {

        iVar6 = -uVar3;

      }

      else {

        iVar6 = puVar1[3] - uVar3;

        if (((char)puVar1[4] == '\0') && (uVar3 == uVar5)) {

          return 0;

        }

      }

      uVar5 = uVar5 + iVar6;

      if (uVar5 != 0) {

        if (0x5d2 < uVar5) {

          uVar5 = 0x5d2;

        }

        cVar2 = FUN_00784000(local_5d4,uVar5,&local_5d8);

        if (((cVar2 != '\0') && ((short)local_5d8 != 0)) &&

           (uVar3 = send(*unaff_EDI,local_5d4,local_5d8 & 0xffff,0),

           (short)uVar3 != (short)local_5d8)) {

          if ((uVar3 & 0xffff) == 0xffffffff) {

            FUN_00783e00(local_5d8);

            uVar4 = FUN_00783f10();

            return uVar4;

          }

          FUN_00783e00(local_5d8 - uVar3);

        }

      }

    }

  }

  return 0;

}
