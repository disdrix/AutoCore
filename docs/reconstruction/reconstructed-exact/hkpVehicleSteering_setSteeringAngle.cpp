// =============================================================================
// hkpVehicleSteering_setSteeringAngle
// -----------------------------------------------------------------------------
// Stable ID: aa_00636410
// Address:   0x00636410  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* Trivial __thiscall setter: *(this+0x50) = param_2 (float). Called from
   VehicleAction_applyAction (0x598ad2) and FUN_00597ec0. Purpose NOT confirmed — a plausible
   candidate for a target-speed/speed-limiter value given the call site, but this was not
   verified by tracing how +0x50 is subsequently read. Do not treat as confirmed; see the
   correction note on VehicleAction_tickSubsystems (0x636a60). */

void __thiscall hkpVehicleSteering_setSteeringAngle(int param_1,uint32_t /* width from decompiler */ param_2)

{
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = param_2;
  return;
}
