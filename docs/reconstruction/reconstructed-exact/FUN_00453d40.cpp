// =============================================================================
// FUN_00453d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00453d40
// Address:   0x00453d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00453d40 @ 0x00453d40
// Stable ID: aa_00453d40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00453d40.
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

uint32_t /* width from decompiler */ * __fastcall FUN_00453d40(uint32_t /* width from decompiler */ param_1,float *param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar3 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(in_EAX + 4))[1];

  cVar1 = *(char *)((int)puVar3 + 0x39);

  puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

  while (cVar1 == '\0') {

    if (((float)puVar3[3] <= *param_2 && *param_2 != (float)puVar3[3]) ||

       (((float)puVar3[3] < *param_2 || (float)puVar3[3] == *param_2 &&

        (((float)puVar3[4] <= param_2[1] && param_2[1] != (float)puVar3[4] ||

         (((float)puVar3[4] < param_2[1] || (float)puVar3[4] == param_2[1] &&

          (((float)puVar3[5] <= param_2[2] && param_2[2] != (float)puVar3[5] ||

           (((float)puVar3[5] < param_2[2] || (float)puVar3[5] == param_2[2] &&

            (((float)puVar3[6] <= param_2[3] && param_2[3] != (float)puVar3[6] ||

             (((float)puVar3[6] < param_2[3] || (float)puVar3[6] == param_2[3] &&

              (((float)puVar3[7] <= param_2[4] && param_2[4] != (float)puVar3[7] ||

               (((float)puVar3[7] < param_2[4] || (float)puVar3[7] == param_2[4] &&

                ((float)puVar3[8] <= param_2[5] && param_2[5] != (float)puVar3[8])))))))))))))))))))

       ) {

      puVar4 = (uint32_t /* width from decompiler */ *)puVar3[2];

      puVar3 = puVar2;

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)*puVar3;

    }

    puVar2 = puVar3;

    puVar3 = puVar4;

    cVar1 = *(char *)((int)puVar4 + 0x39);

  }

  return puVar2;

}
