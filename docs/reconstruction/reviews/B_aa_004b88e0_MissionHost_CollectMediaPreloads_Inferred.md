# Review B (skeptical / adversarial): `aa_004b88e0` MissionHost_CollectMediaPreloads_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b88e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-H) |
| **Counterpart** | `reviews/A_aa_004b88e0_MissionHost_CollectMediaPreloads_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Only mission-complete audio helper | **Falsified** — three independent flags; audio is `param_4` only |
| 2 | `param_2` is a used path root | **Falsified** — unused in body; still cleaned by `RET 0x10` |
| 3 | cdecl / bare RET | **Falsified** — epilogue `C2 10 00` |
| 4 | Name must be `Mission_Uses_Client_GetMissionCompleteAudioTable_*` | **Rejected** — keyword contamination |
| 5 | Local vector push (`this` is queue) | **Overstated** — `0043d670` ECX not proven = host; residual global/TLS |
| 6 | Product plate retail | **Overstated** — structural `_Inferred` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX host + RET 0x10 | **High** | Stack corrupt / wrong object |
| Three flag gates | **High** | Miss preload classes |
| List offsets | **High** | Walk wrong containers |
| Enqueue via 0043d670 | **High** | Wrong push ABI |
| Preload vector identity | **Open** | Queue wrong list |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | strtok reentrancy / CS |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if param_5: list +0x204 → flags → push path / name+".tk"
  if param_3: list +0x204 nested + list +0x1e0 resource ids
  if param_4: list +0x1ec strtok "|" → mission audio table → push

bytes:
  SEH frame; large stack (0x464 restore)
  RET 0x10
  DAT_009cb318 = ".tk"
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Nested `FUN_004a04f0` ECX wiring not OWN — residual only.

---

## 4. Surviving contract for AutoCore

```
// MissionHost_CollectMediaPreloads_Inferred:
//   ECX = mission host with circular lists at +0x204 / +0x1e0 / +0x1ec
//   stack: unused_u32, flag_media_strings, flag_mission_audio, flag_obj_paths
//   RET 0x10; void
//   enqueue = make_string(path) + GuardedVector_PushBack_Thiscall
// Do not collapse to audio-only helper.
// Do not invent product list English.
// Preserve independent flag gating and strtok multi-token audio path.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/flags/lists/constants; product + vector-ECX residual → **accept-with-gaps**.
