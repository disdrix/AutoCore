// =============================================================================
// Env_DayCycle_ApplySkyBlendAndLight_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004912c0
// Address:   0x004912c0–0x0049146a exclusive (426 B; autoassault.exe base 0x400000)
// System:    environment / sky / day-cycle
// Generated: 2026-08-04 WQ9G-F OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live decompile + sealed bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_004912c0.cpp scaffold.
// Dual: reviews/A|B_aa_004912c0_Env_DayCycle_ApplySkyBlendAndLight_Inferred.md
// Consumes: WorldClock_GetSkyBlendAmount_Inferred (aa_00553cd0),
//           WorldClock_GetQuarterPhase01_Inferred (aa_00553dd0)
// =============================================================================
//
// PURPOSE:
//   Env host day-cycle tick: load stored sky blend from world clock, remap
//   quarter phase by clock mode (0..3) into a day phase, drive light helpers,
//   and when dirty apply fBlendAmount to SkyBox / SkyBoxCloud / SkyBoxForeground
//   materials (and texture bind when blend >= 1).
//
// ABI: __thiscall ECX = env host; one stack dword (caller dt — unread); ret 4.
// =============================================================================

// Forward decls for dualed / undualed callees (names sealed elsewhere where dualed).
extern "C" float __fastcall WorldClock_GetSkyBlendAmount_Inferred(void* clock /*ECX*/);
extern "C" float __fastcall WorldClock_GetQuarterPhase01_Inferred(void* clock /*ECX*/);
extern "C" void FUN_00490af0(float blend, char foreground, char cloud, char sky);
extern "C" void __thiscall FUN_00490820(void* env, char foreground, char cloud, char sky);
extern "C" float FUN_0079a110(/* light host via globals/ECX */);
extern "C" float FUN_0074e690(float t);
extern "C" void FUN_0074e910(float scaled, float t);

extern "C" float g_flOne;            // 0x00a0f2a0 = 1.0f
extern "C" float DAT_00aaa6c0;       // ~1/3  (bytes C3 F5 A8 3E)
extern "C" float DAT_00aaa684;       // ~2/3  (bytes C3 F5 28 3F)

void __thiscall Env_DayCycle_ApplySkyBlendAndLight_Inferred(void* env /*ECX*/,
                                                            float /*dt_unread*/)
{
  float skyBlend;
  float dayPhase = 0.0f;

  void* envObj = *reinterpret_cast<void**>(reinterpret_cast<char*>(env) + 0xb8);
  void* clock = *reinterpret_cast<void**>(reinterpret_cast<char*>(envObj) + 0x78);
  int lightHost = *reinterpret_cast<int*>(reinterpret_cast<char*>(env) + 0x180);

  if (clock == nullptr || lightHost == 0) {
    skyBlend = g_flOne;
  } else {
    skyBlend = WorldClock_GetSkyBlendAmount_Inferred(clock);

    float quarter = WorldClock_GetQuarterPhase01_Inferred(clock);
    unsigned mode =
        *reinterpret_cast<unsigned*>(reinterpret_cast<char*>(clock) + 0x154);

    switch (mode) {
    case 0:
      dayPhase = quarter * DAT_00aaa6c0;
      break;
    case 1:
      dayPhase = (quarter + g_flOne) * DAT_00aaa6c0;
      break;
    case 2:
      dayPhase = quarter * DAT_00aaa6c0 + DAT_00aaa684;
      break;
    case 3:
      dayPhase = g_flOne - quarter;
      break;
    default:
      break;
    }

    float t = FUN_0079a110();
    float s = FUN_0074e690(t);
    FUN_0074e910(s * dayPhase, t);
  }

  // Optional secondary float consumer at env+0x188 when flag env+0x87 set.
  void** secondary = *reinterpret_cast<void***>(reinterpret_cast<char*>(env) + 0x188);
  if (secondary != nullptr &&
      *reinterpret_cast<char*>(reinterpret_cast<char*>(env) + 0x87) != 0) {
    int* vtbl = *reinterpret_cast<int**>(secondary);
    float t1 = FUN_0079a110();
    reinterpret_cast<void(__thiscall*)(void*, float)>(vtbl[2])(secondary, t1);
  }

  // Material dirty path: shorts at +0x98/+0xa0/+0xa8 encode channel enables.
  char cloudFlag = 0;
  if (*reinterpret_cast<short*>(reinterpret_cast<char*>(env) + 0x98) < 0 &&
      *reinterpret_cast<short*>(reinterpret_cast<char*>(env) + 0xa0) < 0) {
    cloudFlag = 1;
  }
  char skyFlag =
      (*reinterpret_cast<short*>(reinterpret_cast<char*>(env) + 0xa8) < 0) ? 1 : 0;

  if (*reinterpret_cast<char*>(reinterpret_cast<char*>(env) + 0x90) != 0 &&
      *reinterpret_cast<int*>(reinterpret_cast<char*>(env) + 0x94) != 0) {
    FUN_00490af0(skyBlend, 1, cloudFlag, skyFlag);
    if (skyBlend >= g_flOne) {
      FUN_00490820(env, 1, cloudFlag, skyFlag);
      *reinterpret_cast<char*>(reinterpret_cast<char*>(env) + 0x90) = 0;
    }
  }
}
