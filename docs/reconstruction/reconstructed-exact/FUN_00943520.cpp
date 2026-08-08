// =============================================================================
// FUN_00943520 — scaffold alias
// Canonical: Client_SelectNearestHostileInRange_Inferred
// Stable ID: aa_00943520  |  VA: 0x00943520–0x009436bb
// Sealed 2026-08-04 dual A/B WQ9R-D — see Client_SelectNearestHostileInRange_Inferred.cpp
// =============================================================================

// Forward declaration of canonical unit.
extern "C" void Client_SelectNearestHostileInRange_Inferred(void *client /*EAX*/, float rangeArg);

// Scaffold name kept for path stability. Callers must pass client in EAX.
extern "C" void FUN_00943520(float rangeArg)
{
  // Image uses EAX-this; pure C++ cannot express that without MSVC-specific
  // register annotations. Prefer the canonical clean for ports.
  Client_SelectNearestHostileInRange_Inferred(/*client via EAX*/ nullptr, rangeArg);
}
