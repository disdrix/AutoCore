// =============================================================================
// Named_CalleeOf_Client_RecvSkillStatusEffect_007fb640  (ALIAS / parent-seed)
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb640
// Canonical: Client_DismissProgressBar_Inferred  (see FUN_007fb640.cpp)
// Address:   0x007fb640  (autoassault.exe, image base 0x400000)
// Note:      Parent-seed name only. Multi-caller dismiss leaf — not status-effect exclusive.
//            Prefer Client_DismissProgressBar_Inferred / FUN_007fb640.cpp for body.
// Dual A/B:  2026-07-29
// =============================================================================

// Forward to canonical clean unit — keep this file as alias plate for xref scans.
// Implementation lives in FUN_007fb640.cpp.

// ESI = Client*
void Named_CalleeOf_Client_RecvSkillStatusEffect_007fb640(void);

// See: Client_DismissProgressBar_Inferred in FUN_007fb640.cpp
// CF: gate client+0x1120; probe vtbl+0x3d8; optional detach client+0xf38/+0xb0;
//     tail JMP bar.vtbl+0x440.
