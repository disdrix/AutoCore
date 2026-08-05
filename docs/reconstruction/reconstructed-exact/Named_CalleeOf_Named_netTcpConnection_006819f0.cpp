// =============================================================================
// Named_CalleeOf_Named_netTcpConnection_006819f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006819f0
// Callee of Named_netTcpConnection
// Address:   0x006819f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_netTcpConnection: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×4, for×4, return×2.
//  - Notable callees: FUN_006819f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_netTcpConnection
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

void __thiscall Named_CalleeOf_Named_netTcpConnection_006819f0(int param_1,uint param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  uVar4 = *(uint *)(param_1 + 0x10);

  uVar5 = *(uint *)(param_1 + 0x14);

  if (((*(uint *)(param_1 + 0xc) - uVar4) - uVar5 < param_2) && (param_2 != 0)) {

    if ((uVar4 + param_2 <= *(uint *)(param_1 + 0xc)) && (uVar4 < uVar5)) {

      puVar2 = (uint32_t /* width from decompiler */ *)((int)*(uint32_t /* width from decompiler */ **)(param_1 + 8) + uVar5);

      puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

      for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

        *puVar6 = *puVar2;

        puVar2 = puVar2 + 1;

        puVar6 = puVar6 + 1;

      }

      for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar6 = *(uint8_t *)puVar2;

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

      return;

    }

    pvVar1 = *(void **)(param_1 + 8);

    puVar2 = operator_new__(uVar4 + param_2);

    uVar4 = *(uint *)(param_1 + 0x10);

    *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar2;

    *(uint *)(param_1 + 0xc) = uVar4 + param_2;

    if (pvVar1 != (void *)0x0) {

      if (uVar4 != 0) {

        puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + (int)pvVar1);

        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

          *puVar2 = *puVar6;

          puVar6 = puVar6 + 1;

          puVar2 = puVar2 + 1;

        }

        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

          *(uint8_t *)puVar2 = *(uint8_t *)puVar6;

          puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

          puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

        }

      }

      operator_delete__(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  }

  return;

}
