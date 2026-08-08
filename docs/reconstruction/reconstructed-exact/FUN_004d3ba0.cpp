// =============================================================================
// FUN_004d3ba0  (machine twin of CVOGObject_EvalChildDeliverObjectiveInteract_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004d3ba0
// Address:   0x004d3ba0 - 0x004d3ee2  (autoassault.exe, image base 0x400000)
// Size:      835 bytes (0x343)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-069 OWN dual
// Exactness: Behavior-preserving; ABI corrected from assembly.
// Named clean: CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.cpp
// =============================================================================

// ABI: __thiscall ECX=host; stack child, character; RET 8; AL in {0,4,5,8}

char FUN_004d3ba0(void *this_host, int child_reaction, int character);

/* Full body: see CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.cpp
   and raw docs/reconstruction/raw/aa_004d3ba0_FUN_004d3ba0.md (MEGA-069 append).

   Decompiler defects corrected here by reference:
   - Missing ECX this (used as this+0xe4e8).
   - Fake `return uVar7 & 0xffffff00` → real `MOV AL, best; RET 8`.
   - operator_delete is not noreturn; list free then return.
   - FUN_00403430 is list dtor, not return source.
*/
