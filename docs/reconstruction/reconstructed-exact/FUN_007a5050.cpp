// =============================================================================
// FUN_007a5050
// -----------------------------------------------------------------------------
// Stable ID: aa_007a5050
// Address:   0x007a5050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a5050 @ 0x007a5050
// Stable ID: aa_007a5050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, goto×1, while×1, return×1.
//  - Notable callees: strncpy×2, FUN_004406e0, FUN_007871c0, FUN_007a4e70, FUN_007a5050.
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

void __thiscall FUN_007a5050(int *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  ushort uVar2;

  int iVar3;

  void *pvVar4;

  

  if (*(char *)(param_2 + 4) != '\0') {

    (**(code **)(*param_1 + 0xc))();

    *(uint16_t *)(param_1 + 9) = *(uint16_t *)(param_2 + 6);

    *(uint16_t *)((int)param_1 + 0x26) = *(uint16_t *)(param_2 + 8);

  }

  uVar2 = 0;

  if (*(short *)(param_2 + 10) != 0) {

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)(param_2 + 0xc + (uint)uVar2 * 0x58);

      if (*(int *)(param_2 + 0x5c + (uint)uVar2 * 0x58) < 0) {

        if (*(char *)(param_2 + 4) == '\0') {

          (**(code **)(*param_1 + 8))(*puVar1,puVar1[1]);

        }

      }

      else {

        if (*(char *)(param_2 + 4) == '\0') {

          iVar3 = FUN_007a4e70(*puVar1,puVar1[1]);

          if (iVar3 == 0) goto LAB_007a51c2;

        }

        else {

          pvVar4 = operator_new(0x250);

          if (pvVar4 == (void *)0x0) {

            iVar3 = 0;

          }

          else {

            iVar3 = FUN_007871c0();

          }

          FUN_004406e0();

        }

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1f0) = puVar1[0x12];

        *(uint32_t /* width from decompiler */ *)(iVar3 + 500) = puVar1[0x13];

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x200) = *puVar1;

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x204) = puVar1[1];

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x238) = puVar1[0x10];

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x23c) = puVar1[0x11];

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x230) = puVar1[0xe];

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x234) = puVar1[0xf];

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1e8) = puVar1[0xc];

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1ec) = puVar1[0xd];

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x21c) = puVar1[0x14];

        *(char *)(iVar3 + 0x1c2) = '\0';

        if ((char *)(puVar1 + 2) != (char *)0x0) {

          strncpy((char *)(iVar3 + 0x1c2),(char *)(puVar1 + 2),0x10);

          *(uint8_t *)(iVar3 + 0x1d2) = 0;

        }

        *(char *)(iVar3 + 0x1d3) = '\0';

        if ((char *)((int)puVar1 + 0x19) != (char *)0x0) {

          strncpy((char *)(iVar3 + 0x1d3),(char *)((int)puVar1 + 0x19),0x10);

          *(uint8_t *)(iVar3 + 0x1e3) = 0;

        }

      }

LAB_007a51c2:

      uVar2 = uVar2 + 1;

    } while (uVar2 < *(ushort *)(param_2 + 10));

  }

  return;

}
