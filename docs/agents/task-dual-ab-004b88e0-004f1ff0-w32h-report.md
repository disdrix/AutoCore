# Dual A/B report — W32-H OWN `aa_004b88e0` + `aa_004f1ff0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-H  
**Scope:** VAs `0x004b88e0`, `0x004f1ff0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-H).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004b88e0` MissionHost_CollectMediaPreloads_Inferred | **accept-with-gaps** — ABI/CF/three flags/list offsets/`.tk`/enqueue pair sealed; product English + preload-vector ECX residual |
| `aa_004f1ff0` Object_CollectAllGraphicsPreloads | **accept-with-gaps** — ABI/plate/suffixes/type-kind gates/tail walk sealed; nested residual collectors product open |

---

## VA `0x004b88e0` — sealed facts

1. **Body:** `0x004b88e0`–`0x004b8db1` exclusive (**1233 B** / `0x4D1`); final **`C2 10 00`**; pad `CC`.
2. **ABI:** **thiscall** ECX=`this` (mission host); stack **unused_u32 + 3 char flags**; void; **`RET 0x10`**.
3. **Semantics:** Flag-gated media/audio preload path collect + enqueue (`FUN_00989e00` + `GuardedVector_PushBack_Thiscall` / `0x0043d670`):
   - **`param_5`:** list `host+0x204` — path@`obj+0x1d0` if `(+0x90d)&4`; name@`+0x2be`+`".tk"` if `(+0x90c)&0x80`.
   - **`param_3`:** same list for `strlen(+0x33d)>3` + nested records from `+0x3bc` (`next@+0x2f4`); list `host+0x1e0` resource ids via `FUN_004a05c0`.
   - **`param_4`:** list `host+0x1ec` — skip `*(+0x104)==0x50`; `strtok("|")` → `Client_GetMissionCompleteAudioTable` + `FUN_00722790` + enqueue.
4. **Classification:** worker.
5. **Callers (2 fn / 3 xrefs):** `FUN_004a04f0` @ `0x004a051b`; `FUN_00556b10` @ `0x00556c95`, `0x00556cce`.
6. **Callees:** `FUN_00989e00`, `FUN_0043d670` (W31-I), `FUN_004a05c0`, `Client_GetMissionCompleteAudioTable`, `FUN_00722790`, `strtok`, `std::string` helpers.
7. **Name:** `MissionHost_CollectMediaPreloads_Inferred` (Ghidra `FUN_004b88e0`). **Reject** keyword plate `Mission_Uses_Client_GetMissionCompleteAudioTable_*`.
8. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); prologue/epilogue + `.tk` sealed via `read_memory`.

### Gaps

- Product host / list / nested-record English.  
- Preload vector ECX identity for `0043d670`.  
- `FUN_004a04f0` tree-walk ECX wiring (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004b88e0_MissionHost_CollectMediaPreloads_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004b88e0_MissionHost_CollectMediaPreloads_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004b88e0_FUN_004b88e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004b88e0_FUN_004b88e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MissionHost_CollectMediaPreloads_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b88e0.cpp` |
| Function | `docs/reconstruction/functions/aa_004b88e0_FUN_004b88e0.md` |
| Function named | `docs/reconstruction/functions/aa_004b88e0_MissionHost_CollectMediaPreloads_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004b88e0.md` |

---

## VA `0x004f1ff0` — sealed facts

1. **Body:** `0x004f1ff0`–`0x004f2531` exclusive (**1345 B** / `0x541`); final **`C2 04 00`**; pad `CC`.
2. **ABI:** **thiscall** ECX=`this` (object host; entry **`MOV EBP,ECX`**); stack **`param_2`**; void; **`RET 0x4`**.
3. **Semantics:** Plate `"CollectAllGraphicsPreloads"`:
   - Stem `this+0x188`; optional `_tint.dds` / `_tur.geo` under flag/type gates.
   - Type `0x0e` only: `GameData_LookupCloneBaseByCbid` on cbid@`clonebase+0x6f4`; kind@`+0x4ce` selects fork (`_frkt/_frkb`) or dual-tread geo+anm packs; then `FUN_004eb010`.
   - Tail: `FUN_004eb3b0`; if `this+0x88≠0` → `FUN_004a04f0(param_2,1,0,0)`; timer end.
   - Exists-gate: `FUN_007b6a20` + `FUN_007b6730` before enqueue.
4. **Classification:** worker.
5. **Callers (2 / 2 xrefs):** `FUN_004f2540` @ `0x004f25e6`; `FUN_004f26e0` @ `0x004f273e`.
6. **Callees:** timer pair, exists pair, enqueue pair, `FUN_00404d70`, `FUN_004f1e20`, `FUN_004eb010`, `FUN_004eb3b0`, `FUN_004a04f0`.
7. **Name:** `Object_CollectAllGraphicsPreloads` (plate-backed). **Reject** scaffold `Named_CalleeOf_*` chain.
8. **Decompile ≡ raw CF**; suffix constants sealed via `read_memory`.

### Gaps

- Product English for type `0x0e`/`0x12` and kind `2`/`4`.  
- Nested residual collectors (`004eb010` / `004eb3b0` / `004f1e20`) not OWN.  
- Preload vector ECX identity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004f1ff0_Object_CollectAllGraphicsPreloads.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004f1ff0_Object_CollectAllGraphicsPreloads.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004f1ff0_FUN_004f1ff0.md` |
| Annotated | `docs/reconstruction/raw/aa_004f1ff0_FUN_004f1ff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CollectAllGraphicsPreloads.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004f1ff0.cpp` |
| Function | `docs/reconstruction/functions/aa_004f1ff0_FUN_004f1ff0.md` |
| Function named | `docs/reconstruction/functions/aa_004f1ff0_Object_CollectAllGraphicsPreloads.md` |
| Scratch | `docs/reconstruction/tmp/a_004f1ff0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004b88e0` | Port as **flag-gated mission-host preload collect**. Preserve three independent flags, list heads `+0x204/+0x1e0/+0x1ec`, `.tk` append, strtok multi-token audio path, and `RET 0x10`. Do **not** collapse to audio-only helper. Enqueue via make-string + GuardedVector push_back (thiscall). |
| `004f1ff0` | Port as **Object_CollectAllGraphicsPreloads**: plate timer, stem+suffix with exists-gate, type/kind packs, tail residual collectors, optional `004a04f0(param_2,1,0,0)`. Preserve **`RET 0x4`**. Do not skip type `0x0e` gate on fork/tread packs. |
| Pair with | `GuardedVector_PushBack_Thiscall` (`0x0043d670`, W31-I); `GameData_LookupCloneBaseByCbid` (`0x00404d70`); map walk `FUN_004a04f0` (not OWN). |
| Closes | W31-I residual callers list includes both VAs; graphics→mission-media link via `004a04f0`. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0043d670` | GuardedVector_PushBack_Thiscall (W31-I) — enqueue target ABI |
| `0x004a04f0` | Mission-map walk that calls `004b88e0` per node |
| `0x00404d70` | GameData_LookupCloneBaseByCbid |
| `0x004f2540` / `0x004f26e0` | Callers of graphics preload collect (W32-L owns `004f2540`) |
| `0x00556b10` | Second caller of `004b88e0` (W32-I) |
| `0x004eb010` / `0x004eb3b0` / `0x004f1e20` | Residual graphics collect helpers |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; plate-backed name only where binary string exists; else structural `_Inferred`.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Rejected keyword / scaffold aliases.

---

## This report

`docs/agents/task-dual-ab-004b88e0-004f1ff0-w32h-report.md`
