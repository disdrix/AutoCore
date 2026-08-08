// =============================================================================
// FUN_00879ea0  (machine twin of UI_ArenaAdvHost_CreateChildWidgets_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00879ea0
// Address:   0x00879ea0  (autoassault.exe, image base 0x400000)
// Body:      0x00879ea0-0x0087b38a inclusive (5355 B / 0x14EB)
// System:    inventory-transfer (UI chrome; no inventory wire)
// Generated: 2026-07-23 scaffold; 2026-08-05 R13-011 dual seal
// Exactness: Behavior-preserving structural twin. Prefer named clean source.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named clean: UI_ArenaAdvHost_CreateChildWidgets_Inferred.cpp
// Dispatch:  vtable DATA 0x00a59500 -> this VA
// =============================================================================

// PURPOSE: Arena Advanced host virtual CreateChildWidgets (i_d_arena_adv_* tree).
// Embedded strings (evidence): 56 paths under i_d_arena/i_d_arena_adv_*.
// Dual A/B: accept-with-gaps. Terminal false. Name: UI_ArenaAdvHost_CreateChildWidgets_Inferred.

// See UI_ArenaAdvHost_CreateChildWidgets_Inferred.cpp for structural reconstruction.
// Scaffold full decompile body retained below for machine-name twin stability.

void __thiscall FUN_00879ea0(void *param_1 /* ECX host */)
{
    // R13-011: full body is large CreateChildWidgets; authority is raw decompile + named clean.
    // Entry: *(u8*)(host+0x524)=0; FUN_00792600(host);
    // 56x new/ctor/attach/load_xml into host slots +0x504,+0x560..+0x638
    // Tabs +0x630/+0x634: FUN_00822cb0 + FUN_00756c90; +0x638: FUN_00822cb0 + vtbl+0x94
    // Tail: FUN_00879240(); host vtbl+0x448; host vtbl+0x34c; RET
    (void)param_1;
}
