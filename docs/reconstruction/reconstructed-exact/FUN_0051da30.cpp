// =============================================================================
// FUN_0051da30  (scaffold alias — prefer Map_Tidy_FreeHead.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051da30
// Address:   0x0051da30–0x0051da5d inclusive (46 B)
// Canonical: Map_Tidy_FreeHead
// Wave:      2026-08-04 WQ9E-J OWN dual
// Note:      Decompiler truncates after operator_delete; full CF in named clean.
// =============================================================================

struct MapFacade;

extern "C" void __fastcall Map_Tidy_FreeHead(MapFacade* map);

extern "C" void __fastcall FUN_0051da30(MapFacade* map)
{
  Map_Tidy_FreeHead(map);
}
