// =============================================================================
// Math_RoundFloatToInt_MissionXpBias_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040dab0
// Address:   0x0040dab0–0x0040dad7  (autoassault.exe, image base 0x400000)
// System:    missions-progression (shared utility; primary dual parent reward toast)
// Generated: 2026-08-05 MEGA-119 dual seal (retire Mission_Bulk_0040dab0 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler + SSE body. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   Signed float → int conversion with half-away-from-zero rounding via
//   g_flMissionXpRoundBias (0.5001f @ 0x00aaa6d0). Leaf SSE helper.
//
// PRIMARY DUAL PARENT:
//   Client_ShowMissionRewardChatToast (0x008ac540) site 0x008ac624:
//     f = Mission_ComputeObjectiveXpAsFloat(obj);
//     i = Math_RoundFloatToInt_MissionXpBias_Inferred(f);  // "Awarded %d" + floater
//
// ABI (sealed):
//   - Stack: float value @ [ESP+4]
//   - Return: EAX = (int) rounded value
//   - Cleanup: plain RET (C3) — not thiscall; ECX unused
//   - Callees: none
//
// Rejected names:
//   - Mission_Bulk_0040dab0 (keyword bulk scaffold)
//   - "toast-only" / "grant XP" (also used by item cycle, conversion_percent, etc.)

// External image constant (do not invent alternate bias).
extern float g_flMissionXpRoundBias; // VA 0x00aaa6d0 = 0.5001f

int Math_RoundFloatToInt_MissionXpBias_Inferred(float value)
{
  // Retail SSE:
  //   XORPS XMM1,XMM1
  //   MOVSS XMM0,[ESP+4]
  //   COMISS XMM1,XMM0 ; JBE pos
  //   SUBSS XMM0,[g_flMissionXpRoundBias] ; CVTTSS2SI EAX,XMM0 ; RET
  // pos:
  //   ADDSS XMM0,[g_flMissionXpRoundBias] ; CVTTSS2SI EAX,XMM0 ; RET
  if (value < 0.0f) {
    return (int)(value - g_flMissionXpRoundBias);
  }
  return (int)(value + g_flMissionXpRoundBias);
}
