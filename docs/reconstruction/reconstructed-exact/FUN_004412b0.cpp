// =============================================================================
// FUN_004412b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004412b0
// Address:   0x004412b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004412b0 @ 0x004412b0
// Stable ID: aa_004412b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×11, goto×3, return×2, do×1, while×1.
//  - Notable callees: FUN_004412b0, FUN_00441480, FUN_00441a20.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ * FUN_004412b0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint uVar1;

  uint uVar2;

  char cVar3;

  uint *in_EAX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  cVar3 = '\x01';

  if (*(char *)((int)puVar4[1] + 0x3d) == '\0') {

    puVar5 = (uint32_t /* width from decompiler */ *)puVar4[1];

    do {

      puVar4 = puVar5;

      uVar1 = puVar4[3];

      if (*(uint *)(*in_EAX + 8) < *(uint *)(uVar1 + 8)) {

        cVar3 = '\x01';

      }

      else if (*(uint *)(uVar1 + 8) < *(uint *)(*in_EAX + 8)) {

LAB_00441310:

        cVar3 = '\0';

      }

      else if (*in_EAX < uVar1) {

        cVar3 = '\x01';

      }

      else {

        if (uVar1 < *in_EAX) goto LAB_00441310;

        if (in_EAX[2] < (uint)puVar4[5]) {

          cVar3 = '\x01';

        }

        else {

          if (((uint)puVar4[5] < in_EAX[2]) || ((int)puVar4[6] <= (int)in_EAX[3]))

          goto LAB_00441310;

          cVar3 = '\x01';

        }

      }

      if (cVar3 == '\0') {

        puVar5 = (uint32_t /* width from decompiler */ *)puVar4[2];

      }

      else {

        puVar5 = (uint32_t /* width from decompiler */ *)*puVar4;

      }

    } while (*(char *)((int)puVar5 + 0x3d) == '\0');

  }

  if (cVar3 != '\0') {

    if (puVar4 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      cVar3 = '\x01';

      goto LAB_0044133f;

    }

    FUN_00441a20();

  }

  uVar1 = puVar4[3];

  uVar2 = *in_EAX;

  if ((*(uint *)(uVar2 + 8) <= *(uint *)(uVar1 + 8)) &&

     ((*(uint *)(uVar1 + 8) != *(uint *)(uVar2 + 8) ||

      ((uVar2 <= uVar1 &&

       ((uVar1 != uVar2 ||

        ((in_EAX[2] <= (uint)puVar4[5] &&

         ((puVar4[5] != in_EAX[2] || ((int)in_EAX[3] <= (int)puVar4[6])))))))))))) {

    *param_2 = puVar4;

    *(uint8_t *)(param_2 + 1) = 0;

    return param_2;

  }

LAB_0044133f:

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_00441480(&param_1,cVar3,in_EAX);

  *param_2 = *puVar4;

  *(uint8_t *)(param_2 + 1) = 1;

  return param_2;

}
