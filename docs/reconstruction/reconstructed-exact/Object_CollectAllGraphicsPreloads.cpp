// =============================================================================
// Object_CollectAllGraphicsPreloads
// -----------------------------------------------------------------------------
// Stable ID: aa_004f1ff0
// Address:   0x004f1ff0  (autoassault.exe, image base 0x400000)
// Body:      0x004f1ff0–0x004f2531 exclusive (1345 B / 0x541)
// System:    object graphics preload collection
// Wave:      W32-H dual (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// ABI (sealed):
//   thiscall  ECX = object host*  (entry MOV EBP,ECX)
//   stack:    param_2 (forwarded to FUN_004a04f0 as this/container root)
//   cleanup:  RET 0x4
//   return:   void
//
// Product plate (binary): "CollectAllGraphicsPreloads" via FUN_0076cf00 / FUN_0076cef0.
// Rejected plate: Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004f1ff0
//
// Path stem: this+0x188 (C string). Suffixes sealed via read_memory.
// Enqueue: FUN_00989e00 + GuardedVector_PushBack_Thiscall (0x0043d670) after exists gate.
// =============================================================================

#include <cstdint>
#include <cstring>

void FUN_0076cf00(const char* name);
void FUN_0076cef0(void);
void FUN_007b6a20(char* path, uint32_t flags /* -1 */);
char FUN_007b6730(char* path, uint32_t flags /* -1 */);
void FUN_00989e00(void* dst_string_like, const char* cstr);
void GuardedVector_PushBack_Thiscall(void* container /*ECX*/, const void* value /*stack*/); // FUN_0043d670
void* GameData_LookupCloneBaseByCbid(uint32_t cbid); // FUN_00404d70
void FUN_004f1e20(void* self /*ECX*/, char a, char b);
void FUN_004eb010(void* self /*ECX*/);
void FUN_004eb3b0(void* self /*ECX*/);
void FUN_004a04f0(void* container /*ECX*/, uint32_t a, uint32_t b, uint32_t c /*, ... */);

// Suffix constants (image):
//   0x009cd060 "_tint.dds"
//   0x00a67574 "_tur.geo"
//   0x009cd010 "_frkt.geo"
//   0x009cd004 "_frkb.geo"
//   0x009cd050 "_trdleft.geo"
//   0x009cd040 "_trdleft_ai.anm"
//   0x009cd030 "_trdright.geo"
//   0x009cd01c "_trdright_ai.anm"

static bool try_enqueue_if_exists(char* path_buf)
{
    FUN_007b6a20(path_buf, 0xffffffffu);
    if (FUN_007b6730(path_buf, 0xffffffffu) == 0)
        return false;
    uint8_t str_tmp[4];
    FUN_00989e00(str_tmp, path_buf);
    GuardedVector_PushBack_Thiscall(/*ECX residual*/, str_tmp);
    return true;
}

static void build_stem_suffix(char* out, const char* stem, const char* suffix)
{
    std::strcpy(out, stem);
    std::strcat(out, suffix);
}

void __thiscall Object_CollectAllGraphicsPreloads(void* self /*ECX*/, uint32_t param_2)
{
    auto* obj = reinterpret_cast<uint8_t*>(self);
    char path_buf[260];
    const char* stem = reinterpret_cast<char*>(obj + 0x188);
    int32_t type = *reinterpret_cast<int32_t*>(obj + 0x38);
    uint8_t* clonebase = *reinterpret_cast<uint8_t**>(obj + 0x3c);

    FUN_0076cf00("CollectAllGraphicsPreloads");

    // Optional tint texture
    if ((clonebase[0x3f2] & 0x10) != 0) {
        build_stem_suffix(path_buf, stem, "_tint.dds");
        try_enqueue_if_exists(path_buf);
    }

    // Turret geo for type 0x0e, or type 0x12 with clonebase+0x4e8 == 1
    if (type == 0x0e ||
        (type == 0x12 && *reinterpret_cast<int32_t*>(clonebase + 0x4e8) == 1)) {
        build_stem_suffix(path_buf, stem, "_tur.geo");
        try_enqueue_if_exists(path_buf);
    }

    // Type-0x0e vehicle part forks / side treads
    if (type == 0x0e) {
        uint32_t cbid = *reinterpret_cast<uint32_t*>(clonebase + 0x6f4);
        void* clone = GameData_LookupCloneBaseByCbid(cbid);
        if (clone != nullptr) {
            FUN_004f1e20(self, 1, 1);
            auto* clone_u = reinterpret_cast<uint8_t*>(clone);
            uint8_t* clone_cb = *reinterpret_cast<uint8_t**>(clone_u + 0x3c);
            char kind = *reinterpret_cast<char*>(clone_cb + 0x4ce);

            if (kind == 2) {
                build_stem_suffix(path_buf, stem, "_frkt.geo");
                try_enqueue_if_exists(path_buf);
                build_stem_suffix(path_buf, stem, "_frkb.geo");
                try_enqueue_if_exists(path_buf);
            } else if (kind == 4) {
                build_stem_suffix(path_buf, stem, "_trdleft.geo");
                try_enqueue_if_exists(path_buf);
                build_stem_suffix(path_buf, stem, "_trdleft_ai.anm");
                try_enqueue_if_exists(path_buf);
                build_stem_suffix(path_buf, stem, "_trdright.geo");
                try_enqueue_if_exists(path_buf);
                build_stem_suffix(path_buf, stem, "_trdright_ai.anm");
                try_enqueue_if_exists(path_buf);
            }

            FUN_004eb010(self);
        }
    }

    FUN_004eb3b0(self);

    if (*reinterpret_cast<int32_t*>(obj + 0x88) != 0) {
        // Flags (1,0,0) → MissionHost_CollectMediaPreloads media-strings only path
        // when routed through FUN_004a04f0 tree walk (not OWN).
        FUN_004a04f0(reinterpret_cast<void*>(param_2), 1, 0, 0);
    }

    FUN_0076cef0();
}
