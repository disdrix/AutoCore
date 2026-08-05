// =============================================================================
// MissionHost_CollectMediaPreloads_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004b88e0
// Address:   0x004b88e0  (autoassault.exe, image base 0x400000)
// Body:      0x004b88e0–0x004b8db1 exclusive (1233 B / 0x4D1)
// System:    mission host media/audio preload path collection
// Wave:      W32-H dual (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// ABI (sealed):
//   thiscall  ECX = mission host*
//   stack:    unused_u32, flag_media_strings, flag_mission_audio, flag_obj_paths
//   cleanup:  RET 0x10
//   return:   void
//
// Rejected plate: Mission_Uses_Client_GetMissionCompleteAudioTable_004b88e0
//   (keyword contamination — only covers param_4 path).
//
// Enqueue pair: FUN_00989e00(tmp, cstr) then GuardedVector_PushBack_Thiscall (0x0043d670).
// Preload vector ECX identity residual (global/TLS — not OWN).
// =============================================================================

#include <cstdint>
#include <cstring>
#include <string>

// Forward decls of nested units (not OWN here).
void FUN_00989e00(void* dst_string_like, const char* cstr);
void GuardedVector_PushBack_Thiscall(void* container /*ECX*/, const void* value /*stack*/); // FUN_0043d670
void* FUN_004a05c0(void* out_string, int16_t resource_id);
void Client_GetMissionCompleteAudioTable(char* path_inout);
void FUN_00722790(char* path_inout);

// Host layout offsets used (sealed from decompile):
//   +0x204  circular list of object nodes (node[2] = object*)
//   +0x1e0  circular list (resource/entry nodes)
//   +0x1ec  circular list (mission-complete audio path hosts)
// Object offsets used: +0x90c/+0x90d/+0x90e flags; +0x1d0 path; +0x2be name;
//   +0x33d string; +0x3bc nested record head; record +0x2f4 next, +0x338/+0x379 paths, +0x3c9 flags.

struct ListNode {
    ListNode* next;   // [0]
    void*     unk1;   // [1]
    uint8_t*  payload; // [2] object* or entry*
};

void __thiscall MissionHost_CollectMediaPreloads_Inferred(
    void* self /*ECX*/,
    uint32_t /*unused_stack*/,
    char flag_media_strings,   // param_3
    char flag_mission_audio,   // param_4
    char flag_obj_paths)       // param_5
{
    auto* host = reinterpret_cast<uint8_t*>(self);
    char path_buf[260];
    char path_buf2[260];
    char audio_buf[512];
    uint8_t str_tmp_a[4];
    uint8_t str_tmp_b[4];
    uint8_t str_tmp_c[4];
    std::string tmp_string_a;
    std::string tmp_string_b;

    // ----- param_5: object list @ host+0x204 -----
    if (flag_obj_paths != 0) {
        auto* head = *reinterpret_cast<ListNode**>(host + 0x204);
        auto* node = reinterpret_cast<ListNode*>(*reinterpret_cast<void**>(head));
        if (node != head) {
            do {
                uint8_t* obj = node->payload;
                if ((obj[0x90d] & 4) != 0) {
                    FUN_00989e00(str_tmp_a, reinterpret_cast<char*>(obj + 0x1d0));
                    GuardedVector_PushBack_Thiscall(/*ECX residual*/, str_tmp_a);
                }
                if ((obj[0x90c] & 0x80) != 0) {
                    // copy name @ +0x2be into path_buf and append ".tk" (DAT_009cb318)
                    std::strcpy(path_buf, reinterpret_cast<char*>(obj + 0x2be));
                    std::strcat(path_buf, ".tk");
                    FUN_00989e00(str_tmp_c, path_buf);
                    GuardedVector_PushBack_Thiscall(/*ECX residual*/, str_tmp_c);
                }
                node = node->next;
            } while (node != head);
        }
    }

    // ----- param_3: media strings from objects + resource list -----
    if (flag_media_strings != 0) {
        auto* head = *reinterpret_cast<ListNode**>(host + 0x204);
        auto* node = reinterpret_cast<ListNode*>(*reinterpret_cast<void**>(head));
        if (node != head) {
            do {
                uint8_t* obj = node->payload;
                char* s = reinterpret_cast<char*>(obj + 0x33d);
                size_t n = std::strlen(s);
                if (n > 3) {
                    FUN_00989e00(str_tmp_c, s);
                    GuardedVector_PushBack_Thiscall(/*ECX residual*/, str_tmp_c);

                    // Nested record ring starting at obj+0x3bc, next @ +0x2f4
                    uint8_t* rec = obj + 0x3bc;
                    uint8_t* rec_head = rec;
                    while (rec != nullptr) {
                        if ((rec[0x3c9] & 0x10) != 0) {
                            if ((obj[0x90e] & 0x20) == 0) {
                                std::strcpy(path_buf, reinterpret_cast<char*>(rec + 0x379));
                            } else {
                                // concat obj+0x33d || rec+0x379
                                std::strcpy(path_buf, reinterpret_cast<char*>(obj + 0x33d));
                                std::strcat(path_buf, reinterpret_cast<char*>(rec + 0x379));
                            }
                            FUN_00989e00(str_tmp_b, path_buf);
                            GuardedVector_PushBack_Thiscall(/*ECX residual*/, str_tmp_b);
                        }
                        if ((rec[0x3c9] & 8) != 0) {
                            FUN_00989e00(str_tmp_a, reinterpret_cast<char*>(rec + 0x338));
                            GuardedVector_PushBack_Thiscall(/*ECX residual*/, str_tmp_a);
                        }
                        rec = *reinterpret_cast<uint8_t**>(rec + 0x2f4);
                        if (rec == nullptr || rec == rec_head)
                            break;
                    }
                }
                node = node->next;
            } while (node != *reinterpret_cast<ListNode**>(host + 0x204));
        }

        // Resource list @ host+0x1e0
        head = *reinterpret_cast<ListNode**>(host + 0x1e0);
        node = reinterpret_cast<ListNode*>(*reinterpret_cast<void**>(head));
        if (node != head) {
            do {
                uint8_t* entry = node->payload;
                if (*(char*)(entry + 0x7fc) != 0) {
                    uint8_t* rec = entry + 0x3f8;
                    uint8_t* rec_head = rec;
                    while (rec != nullptr) {
                        int16_t id_a = *reinterpret_cast<int16_t*>(rec + 0x1de);
                        if (id_a > 0) {
                            auto* pb = reinterpret_cast<std::string*>(
                                FUN_004a05c0(&tmp_string_a, id_a));
                            FUN_00989e00(str_tmp_a, pb->c_str());
                            GuardedVector_PushBack_Thiscall(/*ECX residual*/, str_tmp_a);
                            tmp_string_a.~basic_string();
                        }
                        int16_t id_b = *reinterpret_cast<int16_t*>(rec + 0x1dc);
                        if (id_b > 0) {
                            auto* pb = reinterpret_cast<std::string*>(
                                FUN_004a05c0(&tmp_string_b, id_b));
                            FUN_00989e00(str_tmp_b, pb->c_str());
                            GuardedVector_PushBack_Thiscall(/*ECX residual*/, str_tmp_b);
                            tmp_string_b.~basic_string();
                        }
                        rec = *reinterpret_cast<uint8_t**>(rec + 0x2f4);
                        if (rec == nullptr || rec == rec_head)
                            break;
                    }
                }
                node = node->next;
            } while (node != *reinterpret_cast<ListNode**>(host + 0x1e0));
        }
    }

    // ----- param_4: mission-complete audio paths @ host+0x1ec -----
    if (flag_mission_audio != 0) {
        auto* head = *reinterpret_cast<ListNode**>(host + 0x1ec);
        auto* node = reinterpret_cast<ListNode*>(*reinterpret_cast<void**>(head));
        if (node != head) {
            do {
                char* path_host = reinterpret_cast<char*>(node->payload);
                if (*reinterpret_cast<int32_t*>(path_host + 0x104) != 0x50) {
                    std::strcpy(audio_buf, path_host);
                    char* tok = std::strtok(audio_buf, "|");
                    if (tok == nullptr) {
                        // raw decompile: when strtok returns null, still processes audio_buf
                        char* p = audio_buf;
                        Client_GetMissionCompleteAudioTable(p);
                        FUN_00722790(p);
                        FUN_00989e00(str_tmp_a, audio_buf);
                        GuardedVector_PushBack_Thiscall(/*ECX residual*/, str_tmp_a);
                    } else {
                        do {
                            std::strcpy(path_buf2, tok);
                            Client_GetMissionCompleteAudioTable(path_buf2);
                            FUN_00722790(path_buf2);
                            FUN_00989e00(&str_tmp_b, path_buf2);
                            GuardedVector_PushBack_Thiscall(/*ECX residual*/, &str_tmp_b);
                            tok = std::strtok(nullptr, "|");
                        } while (tok != nullptr);
                    }
                }
                node = node->next;
            } while (node != *reinterpret_cast<ListNode**>(host + 0x1ec));
        }
    }
}
