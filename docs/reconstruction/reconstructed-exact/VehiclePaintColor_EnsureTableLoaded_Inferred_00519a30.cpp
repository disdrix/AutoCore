// =============================================================================
// VehiclePaintColor_EnsureTableLoaded_Inferred  (named alias of FUN_00519a30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00519a30
// Address:   0x00519a30 – 0x00519d1a  (autoassault.exe, image base 0x400000)
// System:    vehicle paint / tint
// Generated: 2026-07-29 (W16-D dual seal)
// Exactness: Behavior-preserving control-flow notes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Full line-faithful body: FUN_00519a30.cpp
//
// Contract summary:
//   void VehiclePaintColor_EnsureTableLoaded_Inferred(void);  // __cdecl
//
//   1. CNDHash_Recreate(&DAT_00b042ac, power=4)
//   2. DBReader enter (*DAT_00b0469c) → FUN_007c9230 three vColor* vectors → leave
//   3. Phase1: always-insert rows (payload +0 RGB, +4 Worth)
//   4. Phase2: merge by IDColor (payload +8 Worth insert/update)
//   5. Phase3: merge by IDColor (payload +0xC Worth insert/update)
//   6. Free temp vectors; SEH unwind
//
// Consumers:
//   VehiclePaintColor_LookupById_Inferred (0x00519d20) when DAT_00b042b8 < 1
//   Paint setters 004faaf0 / 004fab40 (clamp against table count)
//
// Loader plate (FUN_007c9230):
//   //vColorBiomek/row, //vColorHuman/row, //vColorMutant/row
//   IDColor, intRGBColor, intWorth

void VehiclePaintColor_EnsureTableLoaded_Inferred(void);
/* implementation: see FUN_00519a30.cpp — same VA entry */
