// =============================================================================
// FUN_00970e50  (clean twin of AssPreloader_RetireStaleNeverLoaded_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00970e50
// Address:   0x00970e50–0x00970fb8
// Dual:      W33-O 2026-07-29
// See:       AssPreloader_RetireStaleNeverLoaded_Inferred.cpp for named surface.
// =============================================================================

#include <cstdint>

extern "C" float FUN_0076c330(void);
extern "C" void FUN_00457cc0(void* it);
extern "C" void FUN_0096a630(void);
extern "C" void* FUN_0076cec0(void);
extern "C" void vog_LogMessage(const char* file, int line, int level, void* msg);
extern "C" void FUN_0043e8f0(void);
extern "C" void FUN_0043e7f0(void);
extern "C" void FUN_00447350(void* map);

void FUN_00970e50(void* self /*stack*/, float maxAge /*stack*/)
{
  float now = FUN_0076c330();
  int retired = 0;
  auto* base = reinterpret_cast<uint8_t*>(self);
  int* end = *reinterpret_cast<int**>(base + 0x14);
  int* node = reinterpret_cast<int*>(*end);

  while (node != end) {
    float stamp = *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(node) + 0x14);
    if ((now - stamp) <= maxAge) {
      FUN_00457cc0(&node);
    } else {
      void** obj = *reinterpret_cast<void***>(reinterpret_cast<uint8_t*>(node) + 0x10);
      if (obj != nullptr) {
        (**reinterpret_cast<void(***)(void*, int)>(obj))(obj, 1);
      }
      FUN_0096a630();
      void* msg = FUN_0076cec0();
      vog_LogMessage(
          "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp", 0x2A8, 2,
          msg);
      FUN_0043e8f0();
      FUN_0043e7f0(); // EDI = self+0xAC
      FUN_00457cc0(&node);
      FUN_00447350(base + 0x10);
      ++retired;
    }
    end = *reinterpret_cast<int**>(base + 0x14);
  }

  void* summary = FUN_0076cec0();
  vog_LogMessage(
      "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp", 0x2B7, 2,
      summary);
  (void)retired;
  (void)maxAge;
}
