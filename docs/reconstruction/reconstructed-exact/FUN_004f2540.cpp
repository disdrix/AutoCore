// =============================================================================
// FUN_004f2540  (Ghidra twin of FillPreloadList)
// -----------------------------------------------------------------------------
// Stable ID: aa_004f2540
// Address:   0x004f2540–0x004f26d5  (autoassault.exe, image base 0x400000)
// Dual:      W32-L 2026-07-29
// Canonical: docs/reconstruction/reconstructed-exact/FillPreloadList.cpp
// =============================================================================

// Behavior-identical alias: keep Ghidra name for coverage/tooling that keys on FUN_*.
// Implementation lives in FillPreloadList.cpp (plate-backed product name).

extern "C" unsigned char __fastcall FillPreloadList(void* self);

extern "C" unsigned char __fastcall FUN_004f2540(void* self)
{
  return FillPreloadList(self);
}
