// =============================================================================
// Named_CalleeOf_CVOGHBBase_AttachOwnerObject_005085b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005085b0
// Callee of CVOGHBBase_AttachOwnerObject
// Address:   0x005085b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGHBBase_AttachOwnerObject: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: EnterCriticalSection, FUN_005085b0, LeaveCriticalSection.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGHBBase_AttachOwnerObject
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_CVOGHBBase_AttachOwnerObject_005085b0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  uVar2 = 0;

  if (*(char *)(param_1 + 0x28) != '\0') {

    return 0;

  }

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    do {

      if (puVar1[1] == param_2) break;

      puVar1 = (uint32_t /* width from decompiler */ *)puVar1[2];

    } while (puVar1 != (uint32_t /* width from decompiler */ *)0x0);

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar1[1] = 0;

      if (puVar1[2] == 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = puVar1[3];

      }

      else {

        *(uint32_t /* width from decompiler */ *)(puVar1[2] + 0xc) = puVar1[3];

      }

      if (puVar1[3] == 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = puVar1[2];

      }

      else {

        *(uint32_t /* width from decompiler */ *)(puVar1[3] + 8) = puVar1[2];

      }

      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;

      (**(code **)*puVar1)(1);

      uVar2 = 1;

    }

  }

  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  return uVar2;

}
