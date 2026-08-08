# Dual A/B report — MEGA-088 OWN-ONLY (`0x0092a3d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-088**  
**Scope:** VA `0x0092a3d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-088**.  
**Work item:** missions-progression residual dual seal — **Tracker clear/reset helper** (callee of `0x0092a590` Tracker_SetActiveMissionObjective).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0092a3d0` Tracker_ClearOwnedPtrVectorAt11c_Inferred | **accept-with-gaps** — CF/ABI/EDI/offsets/loop/callers sealed; product element type open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): full-dtor / buffer-free / single-delete / ECX-this / noreturn-delete / MissionDial-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0092a3d0` — sealed facts

1. **Body:** `0x0092a3d0`–`0x0092a43d` inclusive (**110 B** / `0x6E`); pad `CC` before `FUN_0092a440`.
2. **ABI:** **EDI** = MissionTracker host; no stack args; **AL = 1** always; bare **`RET`** (`C3`). **Not** ECX-thiscall.
3. **Semantics:** clear owned `vector<T*>` at `host+0x11c`:
   - Loop: for each `p` in `[begin, end)` → `operator_delete(*p)` (cdecl @ `0x00489822`).
   - Then if begin non-null and non-empty: `memmove(begin, end, 0)` → store `end = begin` (buffer kept).
   - Does **not** free buffer; does **not** free host.
4. **Layout:** `+0x11c` begin, `+0x120` end (written), `+0x124` capacity (sibling `FUN_0092a600` only).
5. **Callees:** `operator_delete` @ `0x00489822`; `memmove` IAT `[0x009c652c]`.
6. **Callers (5 UNCONDITIONAL_CALL):**
   - `FUN_0092a590` @ `0x0092a5a1` / `0x0092a5e8` — `MOV EDI,ECX` then call (clear / miss).
   - `FUN_0092a600` @ `0x0092a621` — `MOV EDI,[ESP+arg]` then call → free buffer + zero triple.
   - `FUN_0092bf60` @ `0x0092bf8b` — tracker refresh path.
   - `FUN_0092c080` @ `0x0092c090` — tracker bind/fill path (`MOV EDI,ESI` from EAX tracker).
7. **Decompile caveat:** live decompile collapses delete loop + false noreturn on `operator_delete`. **Bytes authority** restores full loop (hex sealed).
8. **Name:** `Tracker_ClearOwnedPtrVectorAt11c_Inferred` (Ghidra `FUN_0092a3d0`). Scaffold `Named_CalleeOf_*MissionDial*` **retired**. Product map of `T*` open → `_Inferred`.
9. **Decompile CF ⊆ bytes CF**; ABI/offsets sealed via `read_memory` + call-site context.

### Gaps

- Product English for element type `T*` in the vector.  
- Product field name at tracker `+0x11c`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0092a3d0_Tracker_ClearOwnedPtrVectorAt11c_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0092a3d0_Tracker_ClearOwnedPtrVectorAt11c_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0092a3d0_FUN_0092a3d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0092a3d0_FUN_0092a3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tracker_ClearOwnedPtrVectorAt11c_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092a3d0.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_MissionDial_0092a3d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0092a3d0_FUN_0092a3d0.md` |
| Function named | `docs/reconstruction/functions/aa_0092a3d0_Tracker_ClearOwnedPtrVectorAt11c_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_TryBindActiveMissionTracker  (0x0092fd00)  [dualed prior]
  └─ FUN_0092a590  Tracker_SetActiveMissionObjective  [MEGA-010 partition]
        ├─ MOV EDI,ECX
        ├─ FUN_0092a3d0  Tracker_ClearOwnedPtrVectorAt11c_Inferred  [OWN MEGA-088]
        └─ FUN_00929c00  (related reset helper)

FUN_0092a600  vector destroy sibling  [residual]
  ├─ FUN_0092a3d0  [OWN MEGA-088]
  └─ operator_delete(begin); zero +0x11c/120/124

FUN_0092bf60 / FUN_0092c080  tracker refresh/bind  [residual]
  └─ FUN_0092a3d0  [OWN MEGA-088]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0092a3d0-mega-088-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0092a3d0` | Port as **owned pointer-vector clear** at MissionTracker `+0x11c`. **EDI=host**, no stack args, **AL=1**, bare **RET**. Loop-delete every element then `end:=begin`. Do **not** free buffer here. Keep distinct from destroy sibling `0092a600`. Prefer bytes over decompiler (loop collapsed). |
| Pair with | binder `0092a590`; destroy `0092a600`; refresh `0092bf60` / `0092c080`; client bind `0092fd00`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable

**Terminal:** **false**
