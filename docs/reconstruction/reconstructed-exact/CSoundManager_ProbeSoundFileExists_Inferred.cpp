// =============================================================================
// CSoundManager_ProbeSoundFileExists_Inferred  (was FUN_00724870)
// -----------------------------------------------------------------------------
// Stable ID: aa_00724870
// Address:   0x00724870  (autoassault.exe, image base 0x400000)
// Body:      0x00724870–0x007249b0 (0x140 / 320 bytes)
// System:    client audio / CSoundManager path probe
//
// Customcc (call-site Confirmed):
//   EAX = const char* path
//   Stack: CSoundManager* this, char* outPath (opt), int* outKind (opt)
//   RET 0x0C (stdcall 3 stack args); AL = bool
//
// Steps: copy path → append .ogg/_lxx.ogg (FUN_00722790) → PathFileExistsA →
//   walk DAT_00d1e574..00d1e7a4 (std::string roots, stride 0x1c) + basename →
//   FUN_007b66c0 fallback → on success *outKind=2 and optional strcpy outPath.
//
// Name INFERRED — parent logs "Sound file doesn't exist"; product symbol open.
// Dual: reviews/A|B_aa_00724870_CSoundManager_ProbeSoundFileExists_Inferred.md
// Exactness: CF mirrors decompile + bytes + callees; not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>
#include <cstring>

struct CSoundManager;
struct PathConfig;

// Callees (retail symbols unresolved)
extern "C" void __thiscall FUN_00722790(CSoundManager* self, char* pathBuf);
extern "C" PathConfig* FUN_007b6a20(void);
extern "C" char* FUN_007b6420(void); // basename; path in EDI
extern "C" char FUN_007b66c0(PathConfig* cfg); // path in EAX/buffer
// PathFileExistsA — Win32

// Search-root table (runtime-filled BSS)
extern "C" char DAT_00d1e574[]; // [20] x 0x1c MSVC strings; end 0x00d1e7a4

// Modeled with explicit args; retail binds path in EAX.
bool CSoundManager_ProbeSoundFileExists_Inferred(
    CSoundManager* self,
    char* outPath,
    int* outKind,
    const char* path)
{
    char local_208[0x103];
    char local_104[260];

    // strcpy path → local_208 (byte loop in asm)
    std::strcpy(local_208, path);
    FUN_00722790(self, local_208);

    PathConfig* cfg = FUN_007b6a20();
    const auto* cfgBytes = reinterpret_cast<const std::uint8_t*>(cfg);
    if ((cfgBytes[4] & 1) != 0) {
        if (PathFileExistsA(local_208)) {
            goto ok;
        }
        // EDI = local_208 for basename helper
        char* base = FUN_007b6420();
        for (char* root = DAT_00d1e574; root < reinterpret_cast<char*>(0x00d1e7a4);
             root += 0x1c) {
            const char* rootStr = root;
            // MSVC string: if size > 0xF, pointer at +0
            if (*reinterpret_cast<std::uint32_t*>(root + 0x14) > 0xF) {
                rootStr = *reinterpret_cast<char**>(root);
            }
            std::strcpy(local_104, rootStr);
            std::strcat(local_104, base);
            if (PathFileExistsA(local_104)) {
                goto ok;
            }
        }
    }
    if (FUN_007b66c0(cfg) == 0) {
        return false;
    }
ok:
    if (outPath != nullptr) {
        std::strcpy(outPath, local_208);
    }
    if (outKind != nullptr) {
        *outKind = 2;
    }
    return true;
}

// Win32 import (declaration only for clean compile in isolation)
extern "C" int __stdcall PathFileExistsA(const char* path);
