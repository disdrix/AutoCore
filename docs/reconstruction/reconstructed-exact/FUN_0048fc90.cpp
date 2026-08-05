// =============================================================================
// FUN_0048fc90 — clean twin of PalantirEnv_InitPhases_Inferred
// Stable ID: aa_0048fc90 | W31-P
// =============================================================================

#include <cstdint>

extern "C" void  __thiscall FUN_00756320(void *self, void *flag);
extern "C" void  FUN_0048f370(void);
extern "C" void  FUN_0048ed00(void);
extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__thiscall FUN_005769c0(void *self, void *view);
extern "C" int   FUN_00576860(void);
extern "C" void *__thiscall FUN_00576ed0(void *self, void *view);
extern "C" int   FUN_00576d70(void);
extern "C" void *__thiscall FUN_005b35a0(void *self, void *parent);
extern "C" void  __thiscall FUN_005b39a0(void *self, uint32_t one);
extern "C" void *__thiscall FUN_0055c8c0(void *self, void *parent);
extern "C" void  __thiscall FUN_0055cc50(void *self, uint32_t one);
extern "C" void *__thiscall FUN_004c0640(void *self, void *parent);
extern "C" void  __thiscall FUN_004c2080(void *self, uint32_t one);
extern "C" void  FUN_004982d0(void);
extern "C" void  FUN_0096f530(void);
extern "C" void  FUN_00989e00(void *out, const char *name);
extern "C" void  FUN_009701d0(void *str);
extern "C" void  FUN_0096f510(void);
extern "C" void  vog_LogMessage(const char *file, int line, int level, const char *msg);

extern "C" int *DAT_00b04808;
extern "C" void *DAT_00b0480c;
extern "C" int *DAT_00b04818;
extern "C" void *DAT_00b0481c;

uint32_t __thiscall FUN_0048fc90(void *env, void *flag)
{
  auto *e = reinterpret_cast<uint8_t *>(env);
  void *view = *reinterpret_cast<void **>(e + 0xC0);
  void *parent = *reinterpret_cast<void **>(e + 0xB8);
  void *raw;
  void *obj;
  int hr;
  void *slot = flag;

  FUN_00756320(env, flag);
  FUN_0048f370();
  FUN_0048ed00();

  if (DAT_00b04808 == nullptr) {
    raw = operator_new(0x20);
    DAT_00b04808 = (raw == nullptr)
                       ? nullptr
                       : reinterpret_cast<int *>(FUN_005769c0(raw, view));
    DAT_00b0480c = env;
    {
      auto **vt = reinterpret_cast<void **>(*DAT_00b04808);
      using Vcall = void(__thiscall *)(void *);
      reinterpret_cast<Vcall>(vt[8])(DAT_00b04808);
    }
    hr = FUN_00576860();
    if (hr < 0) {
      vog_LogMessage(
          "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentSector.cpp",
          0xAD, 3, "Water phase initialization failed");
    }
  }

  if (DAT_00b04818 == nullptr) {
    raw = operator_new(0x18);
    DAT_00b04818 = (raw == nullptr)
                       ? nullptr
                       : reinterpret_cast<int *>(FUN_00576ed0(raw, view));
    DAT_00b0481c = env;
    {
      auto **vt = reinterpret_cast<void **>(*DAT_00b04818);
      using Vcall = void(__thiscall *)(void *);
      reinterpret_cast<Vcall>(vt[8])(DAT_00b04818);
    }
    hr = FUN_00576d70();
    if (hr < 0) {
      vog_LogMessage(
          "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentSector.cpp",
          0xBB, 3, "Distort phase initialization failed");
    }
  }

  raw = operator_new(0x170);
  obj = (raw == nullptr) ? nullptr : FUN_005b35a0(raw, parent);
  *reinterpret_cast<void **>(e + 0xC4) = obj;
  FUN_005b39a0(obj, 1);

  raw = operator_new(0xA0);
  obj = (raw == nullptr) ? nullptr : FUN_0055c8c0(raw, parent);
  *reinterpret_cast<void **>(e + 0xC8) = obj;
  FUN_0055cc50(obj, 1);

  raw = operator_new(0xC8);
  obj = (raw == nullptr) ? nullptr : FUN_004c0640(raw, parent);
  *reinterpret_cast<void **>(e + 0xCC) = obj;
  FUN_004c2080(obj, 1);

  FUN_004982d0();
  FUN_0096f530();
  FUN_00989e00(&slot, "NDRiver.fx");
  FUN_009701d0(&slot);
  *reinterpret_cast<uint32_t *>(e + 0x178) = 0;
  FUN_0096f510();
  return 0;
}
