// =============================================================================
// CLoadNode__recalculateInitAI
// -----------------------------------------------------------------------------
// Stable ID: aa_005c67b0
// Address:   0x005c67b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for CLoadNode__recalculateInitAI @ 0x005c67b0
// Stable ID: aa_005c67b0
// Embedded strings (evidence for future rename):
//   - "CLoadNode::_recalculateInitAI"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004bb070, CLoadNode__recalculateInitAI, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CLoadNode::_recalculateInitAI".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CLoadNode::_recalculateInitAI"
 * Domain alias of FUN_005c67b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall CLoadNode__recalculateInitAI(int param_1,int param_2)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6da8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CLoadNode::_recalculateInitAI");

  local_4 = 0;

  if (*(int *)(*(int *)(param_1 + 0x6c) + 4) == 2) {

    iVar1 = FUN_004bb070(param_1 + 0x18);

    if (iVar1 != 0) {

      if ((*(uint *)(param_2 + 0xf8) & *(uint *)(param_2 + 0xfc)) == 0xffffffff) {

        if (*(float *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x3c) +

                      0x4c0) == DAT_00aaa668) {

          *(uint8_t *)(param_1 + 100) = 0;

        }

        else {

          *(uint8_t *)(param_1 + 100) = 1;

        }

      }

      else {

        *(uint8_t *)(param_1 + 100) = 0;

      }

    }

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
