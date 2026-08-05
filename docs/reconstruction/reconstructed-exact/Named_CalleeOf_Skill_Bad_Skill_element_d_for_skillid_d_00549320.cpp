// =============================================================================
// Named_CalleeOf_Skill_Bad_Skill_element_d_for_skillid_d_00549320
// -----------------------------------------------------------------------------
// Stable ID: aa_00549320
// Callee of Skill_Bad_Skill_element_d_for_skillid_d
// Address:   0x00549320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Bad_Skill_element_d_for_skillid_d: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_00549320.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Skill_Bad_Skill_element_d_for_skillid_d
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

void Named_CalleeOf_Skill_Bad_Skill_element_d_for_skillid_d_00549320(int param_1,int param_2,int param_3)



{

  uint uVar1;

  uint uVar2;

  uint *puVar3;

  

  uVar2 = *(uint *)(param_1 + 4);

  if ((uVar2 & 0x10000) == 0) {

    if ((uVar2 & 0x20000) == 0) {

      if ((uVar2 & 0x40000) == 0) {

        if ((uVar2 & 0x80000) == 0) {

          if ((uVar2 & 0x100000) == 0) {

            if ((uVar2 & 0x200000) == 0) {

              if ((uVar2 & 0x400000) == 0) {

                if ((uVar2 & 0x800000) == 0) {

                  return;

                }

                puVar3 = (uint *)(param_3 + 0x310 + param_2 * 0xc);

              }

              else {

                puVar3 = (uint *)(param_3 + 0x1a8 + param_2 * 0xc);

              }

            }

            else {

              puVar3 = (uint *)(param_3 + 0x2c8 + param_2 * 0xc);

            }

          }

          else {

            puVar3 = (uint *)(param_3 + 0x238 + param_2 * 0xc);

          }

        }

        else {

          puVar3 = (uint *)(param_3 + 0x280 + param_2 * 0xc);

        }

      }

      else {

        puVar3 = (uint *)(param_3 + 0x1f0 + param_2 * 0xc);

      }

    }

    else {

      puVar3 = (uint *)(param_3 + 0x160 + param_2 * 0xc);

    }

  }

  else {

    puVar3 = (uint *)(param_3 + 0x118 + param_2 * 0xc);

  }

  uVar2 = *(uint *)(param_1 + 0x10);

  uVar1 = *(uint *)(param_1 + 0xc);

  *puVar3 = (uint)*(byte *)(param_1 + 8);

  puVar3[1] = uVar2;

  puVar3[2] = uVar1;

  return;

}
