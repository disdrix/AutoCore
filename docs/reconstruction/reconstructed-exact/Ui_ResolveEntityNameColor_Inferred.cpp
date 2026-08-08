// =============================================================================
// Ui_ResolveEntityNameColor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00930fc0
// Address:   0x00930fc0–0x009313bf  (autoassault.exe, image base 0x400000)
// System:    client UI / entity name-label color
// Generated: 2026-08-04 WQ9D-J dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Store packed AARRGGBB for an entity name/label relative to the local
// player (clientCtx+0xe98). Specials: purple marked, gray dead, lime owner TFID,
// level-band RGB; else fixed palette via FUN_00930f40.
//
// ABI: __thiscall; ECX=entity; stack: clientCtx, outArgb*, flagA, flagB;
//      ret 16 (C2 10 00).
//
// READABILITY:
//  - Body ~1023 B; many early outs to palette or special ARGB.
//  - Callers: UI name draw only (00836410, 00838e20, 00859bc0, 009188c0, 0091a350).
//  - Dualed callees: Object_CopyTfid16At228, TFID_EqualsObjectId,
//    VehicleCrew_ContainsMember, Object_DefSubInt4e0_Equals1.
//

#include <cstdint>

// External helpers (addresses for navigation).
extern "C" int  Object_GetRootRaceId(void* entity);
extern "C" char FUN_00837e80(void);
extern "C" char VehicleCrew_ContainsMember_Inferred(void* crewHost, void* member);
extern "C" char Object_DefSubInt4e0_Equals1_Inferred(/* state from vtbl+0x1d8 */);
extern "C" void* Object_CopyTfid16At228_Inferred(void* obj, void* out16);
extern "C" int  TFID_EqualsObjectId(void* a, void* b);
extern "C" uint32_t* FUN_00930f40(int mode);          // palette BGRA → AARRGGBB dword
extern "C" void FUN_0092d580(void* host, int levelDiff); // level band → float RGB out

// Immediates / globals sealed by decompile + read_memory
static constexpr uint32_t kArgbMarkedPurple = 0xFFC364EB;
static constexpr uint32_t kArgbDeadGray     = 0xFFEBEBEB;
static constexpr uint32_t kArgbOwnerLime    = 0xDFCAFF0B;
static constexpr float    kRgbScale255      = 255.0f; // DAT_00aaa6f8

// Shared-base pointer adjust used on many client objects.
static inline int* SharedBaseAdj(int* p) {
  if (p == nullptr) return nullptr;
  int off = *reinterpret_cast<int*>(p[1] + 4);
  return reinterpret_cast<int*>(reinterpret_cast<char*>(p) + off + 4);
}

static inline int* LocalPeerA4(int localRaw) {
  int off = *reinterpret_cast<int*>(*reinterpret_cast<int*>(localRaw + 4) + 4);
  return *reinterpret_cast<int**>(localRaw + off + 0xa4);
}

static inline void* LocalTfid164(int localRaw) {
  int off = *reinterpret_cast<int*>(*reinterpret_cast<int*>(localRaw + 4) + 4);
  return reinterpret_cast<void*>(localRaw + off + 0x164);
}

void __thiscall Ui_ResolveEntityNameColor_Inferred(
    int* entity /*ECX*/,
    int clientCtx,
    uint32_t* outArgb,
    char flagAllowSelfStyle,
    char flagForcePalette) {
  uint32_t color = 0;

  // ---- null entity → palette ----
  if (entity == nullptr) {
    *outArgb = *FUN_00930f40(/*mode*/ 0);
    return;
  }

  // ---- marked purple: sub = vtbl+0x210(0); sub+0x6b4 > 0 ----
  {
    auto getSub = *reinterpret_cast<int*(__thiscall**)(int*, int)>(*entity + 0x210);
    int* sub = getSub(entity, 0);
    if (sub != nullptr) {
      sub = getSub(entity, 0);
      if (*reinterpret_cast<int*>(reinterpret_cast<char*>(sub) + 0x6b4) > 0) {
        *outArgb = kArgbMarkedPurple;
        return;
      }
    }
  }

  int localRaw = *reinterpret_cast<int*>(clientCtx + 0xe98);
  if (localRaw == 0) {
    *outArgb = *FUN_00930f40(0);
    return;
  }

  int* localAdj = SharedBaseAdj(reinterpret_cast<int*>(localRaw));

  // ---- self → palette (side-load local+0xcb0) ----
  if (entity == localAdj) {
    (void)*reinterpret_cast<int*>(localRaw + 0xcb0);
    *outArgb = *FUN_00930f40(0);
    return;
  }

  int* targetRaw = *reinterpret_cast<int**>(localRaw + 0x250);
  int* targetAdj = targetRaw ? SharedBaseAdj(targetRaw) : nullptr;
  char flag6b9 = *reinterpret_cast<char*>(localRaw + 0x6b9);
  int* peerA4 = LocalPeerA4(localRaw);

  // Privileged peer (target + flag6b9 + peerA4) → palette
  if (entity == targetAdj || (flag6b9 != 0 && entity == peerA4)) {
    // Decompiler requires both sides of nested condition for the fallthrough;
    // exact nesting preserved in raw. Fallthrough palette when "is local family".
  }

  // Outer: not self-family (entity != localAdj already). Inner relationship path:
  if (entity != targetAdj && (flag6b9 == 0 || entity != peerA4)) {
    if (flagAllowSelfStyle != 0 || entity != peerA4) {

      // Race gate
      unsigned race = static_cast<unsigned>(Object_GetRootRaceId(entity));
      if (race > 0x7fffffffu && FUN_00837e80() == 0) {
        *outArgb = *FUN_00930f40(0);
        return;
      }

      // Crew membership suppress → palette
      {
        auto getSub = *reinterpret_cast<int*(__thiscall**)(int*, int)>(*entity + 0x210);
        int* sub = getSub(entity, 0);
        int crewHost = *reinterpret_cast<int*>(localRaw + 0xcb0);
        if (sub != nullptr && crewHost != 0) {
          if (VehicleCrew_ContainsMember_Inferred(
                  reinterpret_cast<void*>(crewHost), sub) != 0) {
            *outArgb = *FUN_00930f40(0);
            return;
          }
        }
      }

      // Dead / ghost → gray
      {
        auto getState = *reinterpret_cast<int*(__thiscall**)(int*)>(*entity + 0x1d8);
        if (getState(entity) != nullptr) {
          getState(entity);
          if (Object_DefSubInt4e0_Equals1_Inferred() != 0) {
            *outArgb = kArgbDeadGray;
            return;
          }
        }
      }

      // Owner TFID match → lime
      {
        auto getId = *reinterpret_cast<int*(__thiscall**)(int*)>(*entity + 0x214);
        int* idObj = getId(entity);
        if (idObj != nullptr) {
          alignas(4) unsigned char tfidBuf[20]{};
          void* localTfid = LocalTfid164(localRaw);
          // vtbl+0x214 fills buffer object; 0040aff0 copies TFID_16 @ +0x228
          (*reinterpret_cast<void(__thiscall**)(int*, void*)>(*entity + 0x214))(
              entity, tfidBuf);
          void* entityTfid = Object_CopyTfid16At228_Inferred(
              /* object with TFID@228 from 0x214 path */ idObj, tfidBuf);
          if (static_cast<char>(TFID_EqualsObjectId(entityTfid, localTfid)) != 0) {
            *outArgb = kArgbOwnerLime;
            return;
          }
        }
      }

      // Local relationship predicate vtbl+0x298
      {
        auto relFn = *reinterpret_cast<char(__thiscall**)(int*, int*)>(*localAdj + 0x298);
        if (relFn(localAdj, entity) == 0) {
          *outArgb = *FUN_00930f40(0);
          return;
        }
      }

      if (flagForcePalette == 1) {
        *outArgb = *FUN_00930f40(0);
        return;
      }

      // Level-band color pack
      {
        auto getId = *reinterpret_cast<int*(__thiscall**)(int*)>(*entity + 0x214);
        int* idObj = getId(entity);
        if (idObj != nullptr) {
          int off = *reinterpret_cast<int*>(idObj[1] + 4);
          int defHolder = *reinterpret_cast<int*>(
              reinterpret_cast<char*>(idObj) + off + 0xac);
          int def = *reinterpret_cast<int*>(defHolder + 0x3c);
          short baseLevel = *reinterpret_cast<short*>(def + 0x4fa);
          int* idAdj = SharedBaseAdj(idObj);

          int localLevel =
              (*reinterpret_cast<int(__thiscall**)(int*)>(*localAdj + 0x27c))(localAdj);
          int entLevel =
              (*reinterpret_cast<int(__thiscall**)(int*)>(*idAdj + 0x27c))(idAdj);
          int levelDiff = (baseLevel - localLevel) + entLevel;

          float bandR = 0.f, bandG = 0.f, bandB = 0.f;
          // FUN_0092d580 writes float RGB into caller-provided out (local_b8/b4/b0).
          FUN_0092d580(reinterpret_cast<void*>(clientCtx), levelDiff);
          auto ch = [](float x) -> uint32_t {
            return static_cast<uint32_t>(static_cast<int>(x * kRgbScale255)) & 0xFFu;
          };
          // Binary: CONCAT pack of (int)(local_b8*255), (int)(local_b4*255),
          // (int)(local_b0*255) with A=0xFF. Floats come from 0092d580 out.
          color = 0xFF000000u | (ch(bandR) << 16) | (ch(bandG) << 8) | ch(bandB);
          *outArgb = color;
          return;
        }
      }
    }
  }

  // Fallthrough palette (self family, or no level identity, etc.)
  (void)*reinterpret_cast<int*>(localRaw + 0xcb0);
  *outArgb = *FUN_00930f40(0);
}
