// =============================================================================
// Named_CalleeOf_Client_RequestCastSkill_007fb690  (scaffold alias)
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb690
// Address:   0x007fb690  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / client-ui
// Generated: 2026-07-23 scaffold name; 2026-07-29 dual prefers claim name below.
// =============================================================================
//
// Prefer canonical clean:
//   docs/reconstruction/reconstructed-exact/FUN_007fb690.cpp
// Claim name: Client_ShowTimedProgressBar_Inferred
//
// RequestCast usage (caller 0x00941590 @ 0x00941817):
//   if charge skill+0x14 > 0 and active-cast binding == invalid TFID:
//     FUN_007fb690(
//       /*EAX=client*/
//       0.0f,                                      // startOrMode
//       (float)(int16)(skill+0x14) * 0.001f,       // durationSec (g_flMsToSeconds)
//       skill+0x184,                               // titleSrc
//       "...Activating Skill...",                  // statusText @ 0x00a2e004
//       *DAT_00afdf08,                             // colorCh1
//       0xFF400000,                                // colorCh0 (dark-red ARGB)
//       0, 0);                                     // colorCh2, extra
//
// Full body CF + vtbl map: FUN_007fb690.cpp / dual A/B reviews.
