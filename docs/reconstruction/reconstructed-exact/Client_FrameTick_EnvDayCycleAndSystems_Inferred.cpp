// =============================================================================
// Client_FrameTick_EnvDayCycleAndSystems_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00942e20
// Address:   0x00942e20–0x009430f0 exclusive (720 B; autoassault.exe base 0x400000)
// System:    client frame / environment day-cycle parent
// Generated: 2026-08-04 WQ9H-G OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live decompile + sealed disasm.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_00942e20.cpp scaffold.
// Dual: reviews/A|B_aa_00942e20_Client_FrameTick_EnvDayCycleAndSystems_Inferred.md
// Calls: Env_DayCycle_ApplySkyBlendAndLight_Inferred (aa_004912c0, dualed WQ9G-F)
// =============================================================================
//
// PURPOSE:
//   Per-frame client tick (sole child of main frame FUN_0094b520 under profile
//   bucket 1): clamp dt, apply env day-cycle sky blend when world root present,
//   run post-load system helpers, optional fog material push, drain a pending
//   list, tick primary object, and one-shot log total load time.
//
// ABI: EDI = client/session host (register this); no stack args; bare RET;
//      returns 0 on success, 1 if gate FUN_0092e510 fails.
// =============================================================================

#include <cstdint>

extern "C" char FUN_0092e510(/* EAX = host */);
extern "C" void __thiscall Env_DayCycle_ApplySkyBlendAndLight_Inferred(
    void* env /*ECX*/, float dt /*stack, unread in child*/);
extern "C" void __thiscall FUN_00942840(void* host /*ECX*/);
extern "C" void FUN_00931a50(float dt /* + ESI=host */);
extern "C" void FUN_007a2e50(void* a, uint32_t b);
extern "C" void FUN_009307b0(void* host, float dt);
extern "C" void FUN_0092cef0(void);
extern "C" void FUN_0092ec60(/* EAX = host */);
extern "C" void FUN_0092f000(/* EAX = host */);
extern "C" void __thiscall FUN_00442640(void* matEntryPlus20 /*ECX*/,
                                        const char* name, float* value);
extern "C" void __thiscall FUN_00753a50(void* ecx);
extern "C" void FUN_007545c0(/* EAX */);
extern "C" void __thiscall FUN_004c0ce0(void* ecx);
extern "C" void FUN_007f9cc0(/* ESI set by caller */);
extern "C" void FUN_004040a0(/* EDX = list cursor* */);
extern "C" void FUN_00402850(void* listBase, char* scratch, void* node);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void OutputDebugStringA(const char* s);

extern "C" void* DAT_00d09874;  // time / engine singleton
extern "C" float DAT_00a0f70c;  // 0.2f  (bytes CD CC 4C 3E)
extern "C" float DAT_00af9120;  // 0.01f (bytes 0A D7 23 3C)
extern "C" float DAT_00af911c;  // 1.0f  fFogHeight value
extern "C" char DAT_00d1f06d;   // fog material loop enable
extern "C" char DAT_00d1f06c;   // one-shot load-time log flag

// Host is live in EDI for the whole body (entry: MOV EAX,EDI).
extern "C" uint32_t Client_FrameTick_EnvDayCycleAndSystems_Inferred(void)
{
  void* host /*EDI*/;

  if (FUN_0092e510() == 0) {
    return 1;
  }

  float dt = *reinterpret_cast<float*>(
      reinterpret_cast<char*>(DAT_00d09874) + 0x30);
  if (dt > DAT_00a0f70c) {
    dt = DAT_00a0f70c;
  }

  void* worldRoot =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0xe04);
  if (worldRoot != nullptr) {
    // Disasm: MOV ECX,[EAX+0xe894]; PUSH dt; CALL 004912c0
    void* env =
        *reinterpret_cast<void**>(reinterpret_cast<char*>(worldRoot) + 0xe894);
    Env_DayCycle_ApplySkyBlendAndLight_Inferred(env, dt);
  }

  FUN_00942840(host); // ECX=EDI
  FUN_00931a50(dt);   // ESI=EDI
  FUN_007a2e50(
      *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0xde8),
      *reinterpret_cast<uint32_t*>(
          reinterpret_cast<char*>(DAT_00d09874) + 0x238));
  FUN_009307b0(host, dt);
  FUN_0092cef0();
  FUN_0092ec60(); // EAX=EDI
  FUN_0092f000(); // EAX=EDI

  // --- Fog material push ---
  worldRoot =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0xe04);
  void* envShell =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(worldRoot) + 0xe894);
  int* matBank =
      *reinterpret_cast<int**>(reinterpret_cast<char*>(envShell) + 0x94);
  if (matBank != nullptr) {
    void* fogSrcParent =
        *reinterpret_cast<void**>(reinterpret_cast<char*>(worldRoot) + 0xe890);
    char* fogBase =
        *reinterpret_cast<char**>(reinterpret_cast<char*>(fogSrcParent) + 8);
    float x = *reinterpret_cast<float*>(fogBase + 0x90);
    float y = *reinterpret_cast<float*>(fogBase + 0x94);
    float z = *reinterpret_cast<float*>(fogBase + 0x98);
    float yScaled = y - DAT_00af9120 * y;

    int* vtbl = *reinterpret_cast<int**>(matBank);
    auto makeMat =
        reinterpret_cast<int*(__thiscall*)(void*, int)>(vtbl[0x10 / 4]);
    int* mat = makeMat(matBank, 3);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(mat) + 0xbc) =
        0xffffffffu;
    (*reinterpret_cast<int*>(reinterpret_cast<char*>(mat) + 0xb4))++;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(mat) + 0x90) = x;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(mat) + 0x94) = yScaled;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(mat) + 0x98) = z;

    if (DAT_00d1f06d != 0) {
      int* begin =
          *reinterpret_cast<int**>(reinterpret_cast<char*>(matBank) + 0xc0);
      int* endp =
          *reinterpret_cast<int**>(reinterpret_cast<char*>(matBank) + 0xc4);
      int n = (begin == nullptr)
                  ? 0
                  : static_cast<int>((reinterpret_cast<char*>(endp) -
                                      reinterpret_cast<char*>(begin)) >>
                                     2);
      for (int i = 0; i < n; ++i) {
        void* entry = reinterpret_cast<void*>(begin[i]);
        FUN_00442640(reinterpret_cast<char*>(entry) + 0x20, "fFogHeight",
                     &DAT_00af911c);
      }
    }
  }

  void* de8 =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0xde8);
  void* p128 =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(de8) + 0x128);
  if (p128 != nullptr) {
    FUN_00753a50(p128);
  }
  FUN_007545c0(); // EAX = de8

  worldRoot =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0xe04);
  envShell =
      *reinterpret_cast<void**>(reinterpret_cast<char*>(worldRoot) + 0xe894);
  if (envShell != nullptr) {
    void* sink =
        *reinterpret_cast<void**>(reinterpret_cast<char*>(envShell) + 0xcc);
    if (sink != nullptr) {
      FUN_004c0ce0(sink);
    }
  }

  de8 = *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0xde8);
  if (*reinterpret_cast<char*>(reinterpret_cast<char*>(de8) + 0x12c) != 0) {
    *reinterpret_cast<char*>(reinterpret_cast<char*>(de8) + 0x12c) = 0;
    void* p1168 =
        *reinterpret_cast<void**>(reinterpret_cast<char*>(host) + 0x1168);
    if (p1168 != nullptr) {
      FUN_007f9cc0(); // ESI from [p1168+0x4f0] in asm
    }
  }

  // Pending list: sentinel at host+0xd28; node payload at node+0x20.
  // On tick success: delete object (vtbl+4,1), erase node via FUN_00402850.
  void** sentinel =
      *reinterpret_cast<void***>(reinterpret_cast<char*>(host) + 0xd28);
  void* node = *sentinel;
  while (node != sentinel) {
    void* obj =
        *reinterpret_cast<void**>(reinterpret_cast<char*>(node) + 0x20);
    int* ov = *reinterpret_cast<int**>(obj);
    char ok =
        reinterpret_cast<char(__thiscall*)(void*, float)>(ov[0])(obj, dt);
    if (ok == 0) {
      FUN_004040a0(); // advance cursor only
    } else {
      if (obj != nullptr) {
        reinterpret_cast<void(__thiscall*)(void*, int)>(
            (*reinterpret_cast<int**>(obj))[1])(obj, 1);
      }
      FUN_004040a0();
      char scratch[260];
      FUN_00402850(reinterpret_cast<char*>(host) + 0xd24, scratch, node);
    }
    // disasm reloads node from stack cursor and compares to [host+0xd28]
    sentinel =
        *reinterpret_cast<void***>(reinterpret_cast<char*>(host) + 0xd28);
    node = /* stack cursor after 004040a0 */ node;
  }

  void** primaryHolder =
      *reinterpret_cast<void***>(reinterpret_cast<char*>(host) + 0xf40);
  void* primary = *primaryHolder;
  int* pvt = *reinterpret_cast<int**>(primary);
  reinterpret_cast<void(__thiscall*)(void*, float)>(pvt[0x344 / 4])(primary,
                                                                   dt);

  if (DAT_00d1f06c == 0) {
    float tEnd = *reinterpret_cast<float*>(
        reinterpret_cast<char*>(DAT_00d09874) + 0x238);
    DAT_00d1f06c = 1;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(host) + 0x9ac) = tEnd;
    char buf[260];
    float t0 =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(host) + 0x9a8);
    sprintf(buf, "%%%%%%%%%%%%%%%%%% All load time (%f)\n",
            static_cast<double>(tEnd - t0));
    OutputDebugStringA(buf);
  }

  return 0;
}
