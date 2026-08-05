// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_SendInventoryAddItem_00405920
// -----------------------------------------------------------------------------
// Stable ID: aa_00405920
// Callee of Named_CalleeOf_Client_SendInventoryAddItem
// Address:   0x00405920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_SendInventoryAddItem: inventory/item helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, return×1, goto×1, while×1.
//  - Notable callees: EnterCriticalSection×2, LeaveCriticalSection×2, FUN_00405920, InterlockedDecrement.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_SendInventoryAddItem
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Client_SendInventoryAddItem_00405920(int param_1,code *param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char cVar4;

  

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  do {

    puVar1 = puVar3;

    if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

LAB_0040599d:

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));

      return;

    }

    cVar4 = (*param_2)(puVar1[1],param_3);

    if (cVar4 != '\0') {

      if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 4) = puVar1[2];

      }

      else {

        puVar2[2] = puVar1[2];

      }

      if (puVar1[2] == 0) {

        *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar2;

      }

      puVar1[1] = 0;

      (**(code **)*puVar1)(1);

      InterlockedDecrement((LONG *)(param_1 + 0xc));

      goto LAB_0040599d;

    }

    puVar3 = (uint32_t /* width from decompiler */ *)puVar1[2];

    puVar2 = puVar1;

  } while( true );

}
