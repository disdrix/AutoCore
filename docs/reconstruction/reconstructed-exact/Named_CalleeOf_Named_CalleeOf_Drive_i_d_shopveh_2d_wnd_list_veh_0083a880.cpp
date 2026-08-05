// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0083a880
// -----------------------------------------------------------------------------
// Stable ID: aa_0083a880
// Callee of Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml
// Address:   0x0083a880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0076e5e0×2, FUN_0040d1a0, FUN_00833390, FUN_00833490, FUN_0083a880.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_vehicle_xml
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

void Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0083a880(char param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (in_EAX != 0) {

    local_10 = DAT_00aaa988;

    local_c = DAT_00aaa984;

    local_8 = DAT_00aaa980;

    local_4 = DAT_00aaa97c;

    FUN_0076e5e0(&local_10,&local_10);

    if (param_1 != '\0') {

      FUN_0040d1a0(&local_10);

      FUN_00833490();

      if (*(int **)(in_EAX + 0x508) != (int *)0x0) {

        (**(code **)(**(int **)(in_EAX + 0x508) + 0x44))();

      }

      FUN_00833390();

      return;

    }

    puVar1 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x5e0);

    *puVar1 = local_10;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x5e4) = local_c;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x5e8) = local_8;

    *(uint8_t *)(in_EAX + 0x5dc) = 1;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x5ec) = local_4;

    FUN_0076e5e0(puVar1,puVar1);

  }

  return;

}
