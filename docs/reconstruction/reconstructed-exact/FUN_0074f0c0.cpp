// Twin of Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred (aa_0074f0c0).
// See: docs/reconstruction/reconstructed-exact/Gfx_NotifyResHolders_GlobalsVtbl10c_HostVtbl114_Inferred.cpp

#include <cstdint>

extern "C" uint8_t* DAT_00afe034;
extern "C" uint8_t* DAT_00afe01c;
extern "C" uint8_t* DAT_00afe010;

using Vcall0 = void(__thiscall*)(void* self);

// ESI host; bare RET; void. Sealed W38-X.
void FUN_0074f0c0(void)
{
  uint8_t* host;
  __asm { mov host, esi }

  auto notify_10c = [](uint8_t* holder) {
    if (holder == nullptr) {
      return;
    }
    void* iface = *reinterpret_cast<void**>(holder + 0xc);
    if (iface == nullptr) {
      return;
    }
    auto** vtbl = *reinterpret_cast<Vcall0***>(iface);
    vtbl[0x10c / 4](iface);
  };

  notify_10c(DAT_00afe034);
  notify_10c(DAT_00afe01c);
  notify_10c(DAT_00afe010);

  void* iface = *reinterpret_cast<void**>(host + 0xc);
  if (iface != nullptr) {
    auto** vtbl = *reinterpret_cast<Vcall0***>(iface);
    vtbl[0x114 / 4](iface);
  }
}
