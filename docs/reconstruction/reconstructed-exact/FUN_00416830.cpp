// =============================================================================
// FUN_00416830 — twin of Class_00a733ec_Factory_WithFreeCallback_Inferred
// Stable ID: aa_00416830  VA: 0x00416830  WQ9K-H 2026-08-05
// Prefer the named clean source for port notes.
// =============================================================================

// See: Class_00a733ec_Factory_WithFreeCallback_Inferred.cpp

struct Class_00a733ec;

extern "C" Class_00a733ec *Class_00a733ec_Factory_WithFreeCallback_Inferred(
    void *context);

extern "C" Class_00a733ec *FUN_00416830(void *context)
{
  return Class_00a733ec_Factory_WithFreeCallback_Inferred(context);
}
