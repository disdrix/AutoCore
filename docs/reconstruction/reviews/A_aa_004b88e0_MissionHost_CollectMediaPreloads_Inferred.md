# Review A (reconstruction fidelity): `aa_004b88e0` MissionHost_CollectMediaPreloads_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b88e0` |
| **VA** | `0x004b88e0`–`0x004b8db1` (**1233 B**) |
| **Canonical name** | `MissionHost_CollectMediaPreloads_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004b88e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-H) |
| **Counterpart** | `reviews/B_aa_004b88e0_MissionHost_CollectMediaPreloads_Inferred.md` |
| **System** | mission host media/audio preload path collection |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (prologue/epilogue) + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Flag-gated collection of media/audio path strings from three circular host lists; each path is wrapped (`FUN_00989e00`) and pushed via `GuardedVector_PushBack_Thiscall` (`0x0043d670`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-H append) | `docs/reconstruction/raw/aa_004b88e0_FUN_004b88e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004b88e0_FUN_004b88e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionHost_CollectMediaPreloads_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b88e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004b88e0_MissionHost_CollectMediaPreloads_Inferred.md` |
| PushBack dual | `aa_0043d670` GuardedVector_PushBack_Thiscall (W31-I **accept**) |
| Live | decompile ≡ raw CF; RET `C2 10 00`; 2 callers / 3 xrefs |

---

## 3. Signature (sealed)

```c
// ECX = mission host; stdcall-style cleanup 0x10 for 4 stack slots
void __thiscall MissionHost_CollectMediaPreloads_Inferred(
    void* self /*ECX*/,
    uint32_t unused,
    char flag_media_strings,
    char flag_mission_audio,
    char flag_obj_paths);
```

| Slot | Source | Conf |
|---|---|---|
| self | **ECX** (thiscall; `param_1` in decompiler) | **High** |
| unused | Stack formal present; **not read** in body | **High** |
| three flags | Stack chars `param_3/4/5` | **High** |
| cleanup | `RET 0x10` @ `0x004b8dae` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
if flag_obj_paths: walk list host+0x204
  bit (obj+0x90d)&4 → push cstr@obj+0x1d0
  bit (obj+0x90c)&0x80 → push (obj+0x2be + ".tk")
if flag_media_strings: walk list host+0x204 (strlen(obj+0x33d)>3)
  push +0x33d; walk nested +0x3bc via +0x2f4 (flag bits 0x10/0x8)
  walk list host+0x1e0: resource ids +0x1de/+0x1dc via FUN_004a05c0
if flag_mission_audio: walk list host+0x1ec
  skip if *(path+0x104)==0x50
  strtok "|" → Client_GetMissionCompleteAudioTable + FUN_00722790 + push
```

| Stage | Match | Conf |
|---|---|---|
| Three independent flag gates | **Yes** | **High** |
| List heads +0x204 / +0x1e0 / +0x1ec | **Yes** | **High** |
| Enqueue pair 00989e00 + 0043d670 | **Yes** | **High** |
| `.tk` constant `0x009cb318` | **Yes** (`2e746b00`) | **High** |
| Live decompile ≡ raw 2026-07-23 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry: SEH + `sub esp,0x458` family.  
Epilogue `0x004b8da0`: `pop ebx`; restore `FS:[0]`; `add esp,0x464`; **`C2 10 00`**. Pad `CC`.

Full body large (1233 B); CF sealed from decompile + epilogue/ABI bytes. No `disassemble_bytes`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_004a04f0` (1 xref); `FUN_00556b10` (2 xrefs) |
| Downstream of | `Object_CollectAllGraphicsPreloads` → `FUN_004a04f0` → this (media-strings flag path) |

---

## 7. Gaps

- Product host / list / nested-record English.  
- Preload vector **ECX** for `0043d670` (not local).  
- Caller tree-walk ECX wiring in `FUN_004a04f0` (not OWN).  
- Runtime / bit-exact / differential.

---

## 8. Verdict

ABI, flag CF, list offsets, constants, and enqueue pair sealed. Product residual + vector identity → **accept-with-gaps**.
