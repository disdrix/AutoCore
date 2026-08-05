// =============================================================================
// FUN_00731130  (clean twin of PalToolNoMap_Host0x44_DualChannelInit_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00731130
// Address:   0x00731130  (autoassault.exe, image base 0x400000)
// Body:      0x00731130–0x007313fd (718 B / 0x2CE)
// System:    palantir graphics / PalTool material (no-map)
// Generated: 2026-07-29 W36-J dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Named twin: PalToolNoMap_Host0x44_DualChannelInit_Inferred.cpp
// =============================================================================

#include <cstdint>

extern void FUN_00989e00(void *name_shell, const char *path);
extern uint32_t FUN_009701d0(void *name_shell);
extern int *FUN_00752370(void *out_handle, const char *param_name);
extern uint32_t FUN_0096fff0(int *mat_slot, int handle);
extern uint32_t FUN_004246a0(void);
extern int *FUN_0073d940(int mat_holder);
extern uint32_t FUN_00730b50(void *host, int channel);

// stdcall; RET 4. Prefer named twin for documented factoring.
extern "C" uint32_t FUN_00731130(void *host /* stack param_1 */) {
  int local_4;
  int *mat;
  uint32_t acc = 0;
  uint32_t st;
  int *hp;
  int *neu;
  int *old;

  // ---- channel 0 @ host+0x34 ----
  FUN_00989e00(&local_4, "PalToolMaterialNoMap.fx");
  mat = reinterpret_cast<int *>(reinterpret_cast<char *>(host) + 0x34);
  acc |= FUN_009701d0(&local_4);

  auto bind = [&](const char *name) -> uint32_t {
    if (*mat == 0) {
      local_4 = -1;
      hp = &local_4;
    } else {
      hp = FUN_00752370(&local_4, name);
    }
    if (*hp < 0) {
      return 0xFFFFFFFFu;
    }
    return FUN_0096fff0(mat, *hp);
  };

  acc |= bind("MatDiffuse");
  acc |= bind("MatAmbient");
  acc |= bind("MatSpecular");
  {
    uint32_t emis = 0xFFFFFFFFu;
    if (*mat == 0) {
      local_4 = -1;
      hp = &local_4;
    } else {
      hp = FUN_00752370(&local_4, "MatEmissive");
    }
    if (*hp >= 0) {
      emis = FUN_0096fff0(mat, *hp);
    }
    acc |= emis;
  }
  acc |= FUN_004246a0();
  neu = FUN_0073d940(*mat);
  if (neu != nullptr) {
    neu[1] += 1;
    if (neu[1] == 1) {
      reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(neu))[1]();
    }
    old = reinterpret_cast<int *>(*mat);
    if (old != nullptr) {
      old[1] -= 1;
      if (old[1] == 0) {
        reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(old))[2]();
      }
    }
    *mat = reinterpret_cast<int>(neu);
  }
  acc |= FUN_00730b50(host, 0);

  // ---- channel 1 @ host+0x3c ----
  FUN_00989e00(&local_4, "PalToolMaterialNoMap.fx");
  mat = reinterpret_cast<int *>(reinterpret_cast<char *>(host) + 0x3c);
  acc |= FUN_009701d0(&local_4);
  acc |= bind("MatDiffuse");
  acc |= bind("MatAmbient");
  acc |= bind("MatSpecular");
  {
    uint32_t emis = 0xFFFFFFFFu;
    if (*mat == 0) {
      local_4 = -1;
      hp = &local_4;
    } else {
      hp = FUN_00752370(&local_4, "MatEmissive");
    }
    if (*hp >= 0) {
      emis = FUN_0096fff0(mat, *hp);
    }
    acc |= emis;
  }
  acc |= FUN_004246a0();
  neu = FUN_0073d940(*mat);
  if (neu != nullptr) {
    neu[1] += 1;
    if (neu[1] == 1) {
      reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(neu))[1]();
    }
    old = reinterpret_cast<int *>(*mat);
    if (old != nullptr) {
      old[1] -= 1;
      if (old[1] == 0) {
        reinterpret_cast<void (**)()>(*reinterpret_cast<void **>(old))[2]();
      }
    }
    *mat = reinterpret_cast<int>(neu);
  }
  acc |= FUN_00730b50(host, 1);

  return acc;
}
