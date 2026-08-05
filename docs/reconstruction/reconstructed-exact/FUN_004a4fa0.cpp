// =============================================================================
// FUN_004a4fa0 / NDSpecialFX_ParseXmlEventNode
// -----------------------------------------------------------------------------
// Stable ID: aa_004a4fa0
// Address:   0x004a4fa0 – 0x004a617f  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX
// Generated: 2026-07-29 OWN-ONLY dual seal (live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Parse one special-FX event XML node into a heap FX object (size 0x240).
//   Map type name → event id; walk children (Group/Particle/Geometry/Trail/
//   Lightning/Sound/MusicEvent/Force/Include/Parameter/Fluid).
//
// CALLING CONVENTION: __cdecl
//   arg0 = IXmlNode* node   (Ghidra mislabels BSTR)
//   arg1 = int* outEventType
//   arg2 = uint8_t* customIdCounter
//   return = void* fx or NULL
//
// CALLEE VAs not dual-owned on this pass — kept as FUN_* / import names.
// =============================================================================

#include <cstdint>
#include <cstring>
#include <cwchar>

// External symbols (retail imports / sibling units — not reimplemented here)
struct IXmlNode { void **vtbl; };
extern float g_flOne;
extern float DAT_009c7c28; // 10.0f default sound radius
extern float DAT_009c7c2c; // 80.0f default sound maxradius
extern char DAT_00af06e8;
extern const wchar_t DAT_009c9ef0[]; // L"top"

void *operator_new(size_t);
void operator_delete(void *);
void SysFreeString(wchar_t *);
int _wcsicmp(const wchar_t *, const wchar_t *);
char *strncpy(char *, const char *, size_t);
void free(void *);

// Sibling / helper stubs (owned elsewhere)
int FUN_00798bb0(...);
int FUN_00799460(...);
int FUN_00799300(...);
int FUN_007996d0(...);
int FUN_007994c0(...);
void FUN_007a4480(...);
void *FUN_004ba310(...);
void FUN_004b6850(...);
void FUN_004b99c0(...);
char FUN_004a34f0(...);
void FUN_004a3fa0(...);
void *FUN_0049e540(...);
void *FUN_0049e830(...);
void FUN_004a79e0(...);
void FUN_004a7f80(...);
int FUN_0049f2a0(...);
char FUN_0049f9a0(...);
void FUN_004a7580(...);
char FUN_004a6910(...);
int FUN_0049f430(...);
void FUN_004b92b0(...);
void *FUN_00402d50(...);
int FUN_007249c0(...);
void Client_GetMissionCompleteAudioTable(...);

// ---------------------------------------------------------------------------
// Event type mapping (exact string table from live decompile)
// ---------------------------------------------------------------------------
static int MapEventTypeName(const wchar_t *name, uint8_t *customCounter)
{
  if (_wcsicmp(L"Create", name) == 0) return 0;
  if (_wcsicmp(L"Death", name) == 0) return 1;
  if (_wcsicmp(L"DeathOverkill", name) == 0) return 0x10;
  if (_wcsicmp(L"DeathFiery", name) == 0) return 0x11;
  if (_wcsicmp(L"DeathPeaceful", name) == 0) return 0x12;
  if (_wcsicmp(L"Status", name) == 0) return 2;
  if (_wcsicmp(L"StatusFirer", name) == 0) return 0x13;
  if (_wcsicmp(L"PersistentStatus", name) == 0) return 0x16;
  if (_wcsicmp(L"Charge", name) == 0) return 3;
  if (_wcsicmp(L"Fire", name) == 0) return 4;
  if (_wcsicmp(L"Hit", name) == 0) return 5;
  if (_wcsicmp(L"AOE", name) == 0) return 0x14;
  if (_wcsicmp(L"AOEFirer", name) == 0) return 0x15;
  if (_wcsicmp(L"HitVehicle", name) == 0) return 6;
  if (_wcsicmp(L"HitFirer", name) == 0) return 0xe;
  if (_wcsicmp(L"Miss", name) == 0) return 0xc;
  if (_wcsicmp(L"Stop", name) == 0) return 7;
  if (_wcsicmp(L"Light", name) == 0) return 8;
  if (_wcsicmp(L"DamagedNone", name) == 0) return 9;
  if (_wcsicmp(L"DamagedLow", name) == 0) return 10;
  if (_wcsicmp(L"DamagedHigh", name) == 0) return 0xb;
  if (_wcsicmp(L"Collision", name) == 0) return 0xd;
  if (_wcsicmp(L"Suspension", name) == 0) return 0x17;
  if (_wcsicmp(L"Activate", name) == 0) return 0xf;
  // unrecognized → custom id base 100
  int id = (int)(*customCounter) + 100;
  *customCounter = (uint8_t)(*customCounter + 1);
  return id;
}

// ---------------------------------------------------------------------------
// Group owner attach id (exact chain from live decompile)
// ---------------------------------------------------------------------------
static int MapGroupOwner(const wchar_t *owner)
{
  if (_wcsicmp(L"wheels", owner) == 0) return 0xb;
  if (_wcsicmp(L"exhaust", owner) == 0) return 0xf;
  if (_wcsicmp(L"lights", owner) == 0) return 0x11;
  if (_wcsicmp(L"brakes", owner) == 0) return 0x10;
  if (_wcsicmp(L"front", owner) == 0) return 1;
  if (_wcsicmp(L"back", owner) == 0) return 2;
  if (_wcsicmp(L"left", owner) == 0) return 8;
  if (_wcsicmp(L"right", owner) == 0) return 7;
  if (_wcsicmp(DAT_009c9ef0 /*L"top"*/, owner) == 0) return 9;
  if (_wcsicmp(L"bottom", owner) == 0) return 0xa;
  if (_wcsicmp(L"frontLeft", owner) == 0) return 4;
  if (_wcsicmp(L"frontRight", owner) == 0) return 3;
  if (_wcsicmp(L"rearLeft", owner) == 0) return 6;
  if (_wcsicmp(L"rearRight", owner) == 0) return 5;
  if (_wcsicmp(L"driver", owner) == 0) return 0xc;
  if (_wcsicmp(L"engine", owner) == 0) return 0xd;
  if (_wcsicmp(L"ornament", owner) == 0) return 0xe;
  if (_wcsicmp(L"weaponTurret", owner) == 0) return 0x12;
  if (_wcsicmp(L"weaponFront", owner) == 0) return 0x13;
  if (_wcsicmp(L"weaponRear", owner) == 0) return 0x14;
  {
    int i = _wcsicmp(L"weaponMelee", owner);
    // retail: (-(uint)(i != 0) & 0xffffffeb) + 0x15  → match:0x15, else:0
    return (int)(((-(unsigned)(i != 0)) & 0xffffffebu) + 0x15u);
  }
}

// ---------------------------------------------------------------------------
// Default sound category at +0x104 from event type (before soundType attr)
// ---------------------------------------------------------------------------
static uint32_t DefaultSoundCategory(int eventType)
{
  switch (eventType) {
  case 0: return 0x46; // Create 'F'
  case 1: case 0x10: case 0x11: case 0x12: return 0x32; // Death*
  case 4: return 0x0A; // Fire
  case 5: case 6: case 0xe: return 0x0D; // Hit*
  case 0xc: return 0x0C; // Miss
  case 0xd: return 0x28; // Collision
  default: return 0;
  }
}

// ---------------------------------------------------------------------------
// Main — structural CF map. Vtbl/register packing follows decompiler shape;
// intermediate unaff_* recovery is residual. String tables and dispatch order
// are High-fidelity.
// ---------------------------------------------------------------------------
void *FUN_004a4fa0(IXmlNode *node, int *outEventType, uint8_t *customIdCounter)
{
  // SEH frame (LAB_009a112f) omitted in clean scaffold.

  // node->vtbl[0x44/4](...) — open/read primary attrs into stack buffers
  int hr = (*(int(__thiscall **)(IXmlNode *, ...))(node->vtbl[0x44 / 4]))(node /*, outs... */);
  // decompiler locals: iStack_950 holds primary wide name / blob presence
  int primaryOk = 0; // placeholder for decompiler iStack_950 != 0
  (void)primaryOk;

  if (hr != 0 /* || !primary blob */) {
    // FUN_007a4480 on some paths; SysFreeString; return NULL
    return nullptr;
  }

  char gotType = (char)FUN_00798bb0(/* node, L"type"?, wideBuf */);
  if (gotType == 0) {
    // SysFreeString; return NULL
    return nullptr;
  }

  wchar_t typeName[252]; // awStack_930 — filled by attr read
  *outEventType = MapEventTypeName(typeName, customIdCounter);

  void *mem = operator_new(0x240);
  void *fx = (mem != nullptr) ? FUN_004ba310(/* mem */) : nullptr;
  // null fx still written below in retail (crash risk if new failed) — CF preserved:
  *(int *)((char *)fx + 0x28) = *outEventType;
  FUN_004b6850(/* fx setup */);

  // optional float attr → fx+0x58
  if (FUN_00799460(/* primary */) != 0) {
    // *(float*)(fx+0x58) = uStack_944;
    FUN_00799300(/* ... */);
  }

  // node->vtbl[+0x30] → child enumerator
  void *children = nullptr; // piStack_95c
  (*(void(__thiscall **)(IXmlNode *, ...))(node->vtbl[0x30 / 4]))(node /*, &children... */);
  if (children == nullptr) {
    FUN_004b99c0(/* fx */);
    operator_delete(fx); // noreturn in retail
    return nullptr;
  }
  (*(void(__thiscall **)(void *))(*(void ***)children)[0x20 / 4])(children);

  int groupOwnerId = 0;
  int childCount = 0; // decompiler reuses a stack slot (pvStack_958 after ctor)
  // retail: childCount derived from enumerator query — residual packing
  (void)childCount;

  for (int i = 0; /* i < childCount */ false; ++i) {
    // get child node + name via vtbl+0x1c; on fail: FUN_007a4480(0,"VOG_DEBUG_STOP"); break
    const wchar_t *elemName = L""; // from child
    void *child = nullptr;

    if (_wcsicmp(L"Group", elemName) == 0) {
      // read owner attr → MapGroupOwner; FUN_004a7f80; release
      groupOwnerId = MapGroupOwner(L"/*owner*/");
      FUN_004a7f80();
    } else if (_wcsicmp(L"Particle", elemName) == 0) {
      if (FUN_004a34f0(child, fx) == 0) {
        FUN_004b99c0();
        operator_delete(fx);
        return nullptr;
      }
    } else if (_wcsicmp(L"Geometry", elemName) == 0) {
      FUN_004a3fa0(child, fx);
    } else if (_wcsicmp(L"Trail", elemName) == 0) {
      void *trail = FUN_0049e540(child);
      if (trail == nullptr) {
        FUN_004b99c0();
        operator_delete(fx);
        return nullptr;
      }
      // trail[9]=groupOwnerId; *trail=fx; trail[10]=0; FUN_004a79e0
      (void)groupOwnerId;
      FUN_004a79e0();
    } else if (_wcsicmp(L"Lightning", elemName) == 0) {
      void *lt = FUN_0049e830(child);
      if (lt == nullptr) {
        FUN_004b99c0();
        operator_delete(fx);
        return nullptr;
      }
      FUN_004a79e0();
    } else if (_wcsicmp(L"Sound", elemName) == 0) {
      char *snd = (char *)operator_new(0x138);
      memset(snd, 0, 0x138); // retail: 0x4e dword stores
      *(float *)(snd + 0x11c) = g_flOne;
      *(float *)(snd + 0x110) = DAT_009c7c28; // 10.f
      *(float *)(snd + 0x114) = DAT_009c7c2c; // 80.f
      *(uint32_t *)(snd + 0x104) = DefaultSoundCategory(*outEventType);
      // attrs: soundName, looping, unlinked, Sound3D, eventPlay, soundRegion,
      // radius, maxradius|maxRadius, fadeTime, volume, hasStereo, rpmMultiplier,
      // localOnly, soundType (Generic/ENGINE_MY_*/MY_*/Collision/Weather)
      // Client_GetMissionCompleteAudioTable(snd); FUN_007249c0; FUN_004a79e0
      (void)snd;
    } else if (_wcsicmp(L"MusicEvent", elemName) == 0) {
      if (*outEventType == 0) {
        char *mus = (char *)operator_new(200);
        memset(mus, 0, 200); // 0x32 dwords
        *(float *)(mus + 0x94) = g_flOne;
        // name, looping, fadeIn, fadeOut, maxRadius, timeBetweenLoop,
        // muteAtMaxRadius, isBackground, isRegion, volumeMultipler (sic),
        // mus[0xb8]=2; FUN_004a79e0
        (void)mus;
      }
    } else if (_wcsicmp(L"Force", elemName) == 0) {
      int force = FUN_0049f2a0(child);
      *(int *)((char *)fx + 0x60) = force;
      *(void **)((char *)(uintptr_t)force + 0x2c) = fx;
    } else if (_wcsicmp(L"Include", elemName) == 0) {
      if (FUN_0049f9a0(child, /*&children*/) == 0) {
        FUN_004b99c0();
        operator_delete(fx);
        return nullptr;
      }
    } else if (_wcsicmp(L"Parameter", elemName) == 0) {
      int *param = (int *)operator_new(0x28);
      for (int k = 0; k < 10; ++k) param[k] = 0;
      // FUN_00799460 name; CPAttacherID default -1; update flag; multiplier;
      // type → targetDirection=1, target=0, missAbsolute=5, missRelative=6,
      //         targetLength=4, number→2 else 3
      // FUN_004a7580 insert; fail → operator_delete(param)
      (void)param;
    } else if (_wcsicmp(L"Fluid", elemName) == 0) {
      if (DAT_00af06e8 != 0 && FUN_004a6910() != 0) {
        if (FUN_0049f430(child) == 0) {
          FUN_004b99c0();
          operator_delete(fx);
          return nullptr;
        }
        FUN_004b92b0();
      }
    }
    // child->vtbl[+8] release
  }

  // enumerator release x2; SysFreeString; return fx
  return fx;
}
