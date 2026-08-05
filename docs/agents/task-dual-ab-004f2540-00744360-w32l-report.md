# Dual A/B report — W32-L OWN `aa_004f2540` + `aa_00744360`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-L  
**Scope:** VAs `0x004f2540`, `0x00744360` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` + `get_function_by_address` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` (W32-L).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004f2540` FillPreloadList | **accept-with-gaps** — plate/ABI/offsets/CF sealed; host-class English residual |
| `aa_00744360` PreloadDep_CollectTransitiveKeys_Inferred | **accept-with-gaps** — RET8/tree/ring/recurse sealed; product edge English residual |

---

## VA `0x004f2540` — sealed facts

1. **Body:** `0x004f2540`–`0x004f26d5` inclusive of `C3` (**406 B** / `0x196`; pad `CC` after).
2. **ABI:** **ECX=`this`** (load host); bare **`RET`** (`C3`); return **`0|1`** in AL. SEH `LAB_009a2bbe`.
3. **Semantics:** **FillPreloadList** (profiler plate @ `0x009cd090`):
   - Clear primary `GuardedVector` @ **`this+0x124`** via `FUN_0043d650(0)` (ECX=that ring).
   - Fail if name @ **`+0x188`** is null/empty/space → return 0.
   - `FUN_004eb1c0` hashes name → key; **`FUN_00744360`** with ECX=`*(DAT_00d1f050+0x64)` fills dep ring @ **`+0x110`**.
   - If `*(DAT_00d1f050+0x6c)`: `FUN_004f1ff0` (CollectAllGraphicsPreloads) into `+0x124`.
   - If clonebase `*(this+0x3c)` short@`+0x3f4 == 3`: append **`.spt`** (`DAT_009cd088`), rehash, else use primary key; **`GuardedVector_PushFront_Thiscall(this+0x124, key)`**.
   - If gate: Anim@`+0x138`, Phy@`+0x14c`, Snd@`+0x160` collectors; return 1.
4. **Classification:** worker (multi static callees + SEH).
5. **Callers:** sole CALL — `CLoadNode__initPreload` (`FUN_005c72f0`) @ `0x005c73c1` when clonebase `+0x134==0`.
6. **Callees:** profiler pair; `FUN_0043d650`; `FUN_004eb1c0`; `FUN_00744360`; `FUN_004f1ff0`; `FUN_00989e00`; `GuardedVector_PushFront_Thiscall` (`0x0043e3d0`); Anim/Phy/Snd CollectAll*.
7. **Name:** `FillPreloadList` (Ghidra `FUN_004f2540`; **plate-backed**). **Reject** long scaffold `Named_CalleeOf_*`.
8. **Decompile ≡ raw CF**; **bytes supersede** decompiler for clear/push ECX (`+0x124`).  
   Full hex: raw W32-L append (406 B).

### Gaps

- Product/PDB load-host class English.  
- Nested duals for `FUN_004eb1c0` / `FUN_0043d650` / `FUN_004f1ff0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004f2540_FillPreloadList.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004f2540_FillPreloadList.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004f2540_FUN_004f2540.md` |
| Annotated | `docs/reconstruction/raw/aa_004f2540_FUN_004f2540.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FillPreloadList.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004f2540.cpp` |
| Function | `docs/reconstruction/functions/aa_004f2540_FUN_004f2540.md` |
| Function named | `docs/reconstruction/functions/aa_004f2540_FillPreloadList.md` |
| Scratch | `docs/reconstruction/tmp/a_004f2540.md` |

---

## VA `0x00744360` — sealed facts

1. **Body:** `0x00744360`–`0x0074445c` inclusive of `C2 08 00` (**253 B** / `0xFD`; pad `CC` after).
2. **ABI:** **ECX=dep-tree host** (`MOV ESI,ECX`); stack **`(const int* key, GuardedVectorHeader* ring)`**; epilogue **`ADD ESP,0x18; RET 8`**.
3. **Semantics:** **Transitive dependency key collection**:
   - `FUN_00426f60` + `FUN_0044d960(host+0x10)` → equal-range iterators (EAX-out; decompiler empty-call surface).
   - For each node in range: key at **`node+0x18`**; reverse-scan ring (GuardedVector page wrap) for membership.
   - If absent: **recurse** `(node_key, ring)` with ECX=host; then **`GuardedVector_PushFront_Thiscall(ring, node_key)`**.
   - Advance via MSVC map/set successor (nil flag **`node+0x25`**, L/R/P @ `+0/+4/+8`).
4. **Classification:** worker (self-recursive).
5. **Callers:** `FillPreloadList` @ `0x004f25d2`; AssPreloader family `FUN_009717a0` / `FUN_00971820` / `FUN_00971900` / `FUN_00971a20`; self @ `0x007443fc`.
6. **Callees:** `FUN_00426f60`, `FUN_0044d960`, self, `GuardedVector_PushFront_Thiscall` (`0x0043e3d0`).
7. **Name:** `PreloadDep_CollectTransitiveKeys_Inferred` (Ghidra `FUN_00744360`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_assManager_*`.
8. **Decompile ≡ raw CF**; **bytes supersede** ABI (RET 8) and PushFront ECX (ring, not host).  
   Full hex: raw W32-L append (253 B).

### Gaps

1. Product/PDB host class and dependency-edge English.  
2. Nested dual for equal-range helpers.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00744360_PreloadDep_CollectTransitiveKeys_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00744360_PreloadDep_CollectTransitiveKeys_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00744360_FUN_00744360.md` |
| Annotated | `docs/reconstruction/raw/aa_00744360_FUN_00744360.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PreloadDep_CollectTransitiveKeys_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00744360.cpp` |
| Function | `docs/reconstruction/functions/aa_00744360_FUN_00744360.md` |
| Function named | `docs/reconstruction/functions/aa_00744360_PreloadDep_CollectTransitiveKeys_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00744360.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004f2540` | Port as **FillPreloadList**: ECX load host; clear `+0x124`; fail empty name@`+0x188`; hash name; collect deps into `+0x110` via `00744360` with ECX=`*(resourceManager+0x64)`; optional graphics + domain collectors under gate `manager+0x6c`; push primary or `.spt` key to `+0x124` via thiscall PushFront. Sole path from `CLoadNode__initPreload` when clonebase `+0x134==0`. |
| `00744360` | Port as **transitive dep collector**: ECX tree host, stack `(key*, ring*)`, **ret 8**. equal_range → membership skip → recurse → PushFront. Shared by FillPreloadList and AssPreloader IsKeyTrackedRecursive family. |
| Pair with | W31-I `GuardedVector_PushFront_Thiscall` (`0x0043e3d0`); W31-K AssPreloader duals; `CLoadNode__initPreload` (`0x005c72f0`); Anim/Phy/Snd CollectAll* registry names. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + get_function_by_address + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `FillPreloadList` is plate-backed; dep collector is `_Inferred` structural.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Rejected assManager scaffold alias on `00744360`.

---

## Report path

`docs/agents/task-dual-ab-004f2540-00744360-w32l-report.md`  
Absolute: `C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-004f2540-00744360-w32l-report.md`
