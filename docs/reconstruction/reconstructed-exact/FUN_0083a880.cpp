// =============================================================================
// FUN_0083a880  (twin of ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0083a880
// Address:   0x0083a880 – 0x0083a94d inclusive (206 B / 0xCE)
// Dual:      WQ9L-J 2026-08-05 — accept-with-gaps
// Note:      Ghidra-style twin. Product entry is EAX=obj + stack flag + RET 4.
//            Named clean is authoritative for porting.
// =============================================================================

#include <cstdint>

extern "C" float *FUN_0076e5e0(float *out, float *in); // Math_QuatNormalize
extern "C" void __thiscall FUN_0040d1a0(void *self, const float *quat4);
extern "C" void FUN_00833490(void);
extern "C" void FUN_00833390(void);

extern "C" uint32_t DAT_00aaa97c;
extern "C" uint32_t DAT_00aaa980;
extern "C" uint32_t DAT_00aaa984;
extern "C" uint32_t DAT_00aaa988;

// Modeled with explicit obj; retail: EAX=obj, stack char flag, RET 4.
extern "C" void FUN_0083a880(void *in_EAX_obj, char param_1)
{
  if (in_EAX_obj == nullptr) {
    return;
  }

  auto *obj = reinterpret_cast<uint8_t *>(in_EAX_obj);

  uint32_t local_10 = DAT_00aaa988;
  uint32_t local_c = DAT_00aaa984;
  uint32_t local_8 = DAT_00aaa980;
  uint32_t local_4 = DAT_00aaa97c;
  float *local = reinterpret_cast<float *>(&local_10);
  FUN_0076e5e0(local, local);

  if (param_1 != '\0') {
    FUN_0040d1a0(obj + 0x510, local);
    FUN_00833490();
    int *nested = *reinterpret_cast<int **>(obj + 0x508);
    if (nested != nullptr) {
      auto **vtbl = *reinterpret_cast<void ***>(nested);
      using VFn = void(__thiscall *)(void *);
      reinterpret_cast<VFn>(vtbl[0x44 / 4])(nested);
    }
    FUN_00833390();
    return;
  }

  uint32_t *puVar1 = reinterpret_cast<uint32_t *>(obj + 0x5e0);
  *puVar1 = local_10;
  *reinterpret_cast<uint32_t *>(obj + 0x5e4) = local_c;
  *reinterpret_cast<uint32_t *>(obj + 0x5e8) = local_8;
  obj[0x5dc] = 1;
  *reinterpret_cast<uint32_t *>(obj + 0x5ec) = local_4;
  FUN_0076e5e0(reinterpret_cast<float *>(puVar1), reinterpret_cast<float *>(puVar1));
}
