// =============================================================================
// Combat_ComputeBaseCritChance_FromHost
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4dd0
// Address:   0x004c4dd0–0x004c4e1d  (77 B; autoassault.exe, image base 0x400000)
// System:    combat-crit
// Ghidra:    FUN_004c4dd0
// Dual seal: W23-K 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving; not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Base critical-hit chance fraction for skill-host / bind path.
//   UI (FUN_008f97c0) labels this "Base Critical Hit Chance".
//   Consumer Combat_ComputeCritChance_Inferred uses this when attacker
//   vtbl+0x214 bind is non-null (else level*0.001*0.25+0.05).
//
// FORMULA (byte-exact FPU)
//   level = vcall(host_mi, +0x27c)
//   score = FUN_004c41c0(host)   // perception-capped
//   chance = (score + level) * 0.001f * 0.125f + 0.02f
//
// ABI (image-sealed)
//   __fastcall; ECX=host; no stack formals; return float in ST0
// =============================================================================

extern float g_flMsToSeconds_Inferred; // 0x00a0f72c = 0.001f
extern float DAT_00a110c0;             // 0x00a110c0 = 0.125f
extern float DAT_00aaa7b8;             // 0x00aaa7b8 = 0.02f

// Perception-capped score (shorts +0x142/+0x14a, vcall gate +0x1dc) — not owned.
extern int __fastcall FUN_004c41c0(void* host);

// Ghidra: FUN_004c4dd0
float Combat_ComputeBaseCritChance_FromHost(void* host)
{
  // MI dispatch: this' = host + *( *(host+4) + 4 ) + 4
  int* vb = *reinterpret_cast<int**>(reinterpret_cast<char*>(host) + 4);
  int vbOff = vb[1];
  void* mi = reinterpret_cast<char*>(host) + vbOff + 4;
  int* vt = *reinterpret_cast<int**>(mi);
  int level = reinterpret_cast<int(__thiscall*)(void*)>(vt[0x27c / 4])(mi);

  int score = FUN_004c41c0(host);

  // Image multiplies each term by 0.001 before add; algebraically identical.
  return (static_cast<float>(score) + static_cast<float>(level))
         * g_flMsToSeconds_Inferred * DAT_00a110c0 + DAT_00aaa7b8;
}

// Ghidra twin
float FUN_004c4dd0(void* param_1)
{
  return Combat_ComputeBaseCritChance_FromHost(param_1);
}
