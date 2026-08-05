// =============================================================================
// Client_DispatchUiEventQueue
// -----------------------------------------------------------------------------
// Stable ID: aa_00946c00
// Address:   0x00946c00  (autoassault.exe, image base 0x400000)
// System:    missions-progression / client UI tick
// Generated: 2026-07-29 W19-C dual seal
// Exactness: Behavior-preserving. Full case-arm body is byte/decompile-faithful in
//            reconstructed-exact/FUN_00946c00.cpp (same unit; scaffold symbol).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Client-frame dispatcher for the sector/session UI event queue:
//     session = *(client + 0xe04)
//     queue   = [*(session+0xe8bc), *(session+0xe8c0)) stride 0x138
//   Switch on type at entry+0x1c (int; Ghidra denormal float case labels = type ids).
//   Arms: mission chrome, tips, vehicle park inputs, sector packets, toasts,
//   vendor audio, TFID resolve, respawn, etc.
//
// ABI: __fastcall  ECX = client*
// SOLE CALLER: FUN_0094b520 @ 0x0094b520 (after FUN_00944770)
// Body span: 00946c00–009483e6 (~0x17E6 B), SEH + __chkstk
//
// EMBEDDED STRINGS:
//   "b_m_", "biomek_male_vendor_2", "%s %s.", "Working..", "%s %s!",
//   "%s %s %d!", "%s %+d %s.", "%s %d."
//
// KEY OFFSETS:
//   client+0xe04           session/sector object
//   session+0xe8bc/e8c0    event queue begin/end
//   entry+0x1c             event type (int)
//   entry+0x20/0x24        TFID pair vs vehicle entity ids
//   entry+0x28             TFID_16 for Object_ResolveFromTFID
//   entry+0x38             string payload
//
// See also: docs/reconstruction/raw/aa_00946c00_FUN_00946c00.md
//           docs/reconstruction/raw/aa_00946c00_FUN_00946c00.annotated.md
//           docs/reconstruction/reconstructed-exact/FUN_00946c00.cpp
//
// STRUCTURAL ENTRY (implementation body = FUN_00946c00):

// void __fastcall Client_DispatchUiEventQueue(void *client);
// Ghidra: void __fastcall FUN_00946c00(void *param_1);

extern "C" void __fastcall FUN_00946c00(void *param_1);

void __fastcall Client_DispatchUiEventQueue(void *client)
{
  FUN_00946c00(client);
}
