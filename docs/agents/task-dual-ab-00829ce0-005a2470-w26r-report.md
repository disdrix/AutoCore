# Dual A/B report — W26-R OWN `aa_00829ce0` + `aa_005a2470`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-R  
**Scope:** VAs `0x00829ce0`, `0x005a2470` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md` (W26-R).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00829ce0` UI_MissionJournal_BuildMSelectChrome_Inferred | **accept-with-gaps** — mselect chrome CF/offsets/XML + AL handoff sealed; product plate open |
| `aa_005a2470` TNL_NetClassRepInstance_Dtor | **accept** — free name @+0x20 + vtbl restore; atexit/scalar-delete callers sealed |

---

## VA `0x00829ce0` — sealed facts

1. **Body:** `0x00829ce0`–`0x00829e80` exclusive (**416** B / `0x1A0`); SEH; `add esp,0x10; ret`.
2. **ABI:** **thiscall** ECX=this → EDI; no stack formals; plain `ret`.
3. **Mode branch:** `byte [this+0x4FC] == 0` → mission chrome; else category title only.
4. **Widgets:** button `+0x504` (`0x4CC`/`FUN_0079c860`), status `+0x50C` (`0x488`/`FUN_007b5dd0`), title `+0x508` (`0x488`/`FUN_007b5dd0`).
5. **Complete label:** `mov al,[edi+0x4FD]; mov esi,edi; call FUN_00829ac0` — closes W25-G construct-AL residual.
6. **XML:** `btn_mission` / `wnd_status` / `wnd_title` / `wnd_title_cat` under `i_d_npc_2d_btn_mselect_*` (string VAs sealed).
7. **Callers:** DATA only @ `0x00a748c0` (indirect). **Callees:** `FUN_00792600`, `operator_new`, `FUN_0079c860`, `FUN_007b5dd0`, `FUN_00829ac0`, vtbl `+0xa8`/`+0x28`/`+0x74`/`+0x34c`.
8. **Name:** `UI_MissionJournal_BuildMSelectChrome_Inferred` (Ghidra `FUN_00829ce0`).
9. **Decompile ≡ bytes** for widget CF (live 2026-07-29 ≡ raw 2026-07-23); SEH teardown prefer bytes.

### Gaps

- Product English / plate spelling.  
- `vtbl+0x74(60000)` semantics.  
- Nested callees not OWN.  
- Who sets `+0x4FC`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00829ce0_UI_MissionJournal_BuildMSelectChrome_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00829ce0_UI_MissionJournal_BuildMSelectChrome_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00829ce0_FUN_00829ce0.md` |
| Annotated | `docs/reconstruction/raw/aa_00829ce0_FUN_00829ce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionJournal_BuildMSelectChrome_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00829ce0.cpp` |
| Function | `docs/reconstruction/functions/aa_00829ce0_FUN_00829ce0.md` |
| Function named | `docs/reconstruction/functions/aa_00829ce0_UI_MissionJournal_BuildMSelectChrome_Inferred.md` |

---

## VA `0x005a2470` — sealed facts

1. **Body:** `0x005a2470`–`0x005a248e` exclusive (**30** B); `CC` pad; next sibling @ `0x005a2490`.
2. **ABI:** **thiscall** ECX=this → ESI; plain `ret`; **void** (no object free).
3. **Semantics:** `name = this[+0x20]`; `*this = NetClassRepInstance_vtbl (0x009d7bf4)`; `free(name)` IAT `0x009c6524`; `*this = base_vtbl (0x009d7af4)`.
4. **Classification:** leaf wrapper (1 callee: `free`).
5. **Callers (2):** `FUN_009c3de0` atexit thunk (`mov ecx, DAT_00b04f40; jmp`); `FUN_005a2730` scalar deleting dtor.
6. **Sibling ctor:** `FUN_005a2410` / `TNL_NetClassRepInstance_Ctor` (W21-K dual) — same vtbl + name slot.
7. **Name:** `TNL_NetClassRepInstance_Dtor` (Ghidra `FUN_005a2470`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).
9. **Does not** unlink ClassList / `operator_delete` object.

### Gaps

- ClassList unlink policy for non-static instances (not this body).  
- Sibling ClassRep dtor catalog.  
- Runtime process-exit observation — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005a2470_TNL_NetClassRepInstance_Dtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005a2470_TNL_NetClassRepInstance_Dtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005a2470_FUN_005a2470.md` |
| Annotated | `docs/reconstruction/raw/aa_005a2470_FUN_005a2470.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TNL_NetClassRepInstance_Dtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005a2470.cpp` |
| Function | `docs/reconstruction/functions/aa_005a2470_FUN_005a2470.md` |
| Function named | `docs/reconstruction/functions/aa_005a2470_TNL_NetClassRepInstance_Dtor.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00829ce0` | Client mission-journal panel must create the same mselect widgets/XML and pass `+0x4FD` into status complete-label apply. Category mode skips button+status. Offsets `+0x504`/`+0x508`/`+0x50C` shared with SelectMission / ApplyStatusCompleteLabel duals. |
| `005a2470` | ClassRep teardown must free the strdup name and restore base vtbl. Pair with `TNL_NetClassRepInstance_Ctor`. atexit statics call dtor without `operator_delete`; heap instances use scalar deleting wrapper. Do not invent ClassList unlink in this body. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Avoid bare `undefined4` in clean (`uint32_t` / typed structs).  
- No invented product names without evidence (`_Inferred` where plate open; NetClassRepInstance name from sibling ctor/RTTI lineage).
