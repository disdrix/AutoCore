# Dual A/B report — W19-O OWN (`aa_006078e0`, `aa_00507290`)

**Date:** 2026-07-29  
**Agent:** W19-O OWN-ONLY  
**Scope:** OWN ONLY VAs `0x006078e0`, `0x00507290`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ analyze / xrefs / callees). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` (image base `0x400000`).  
**Dual A/B:** fidelity (A) vs adversarial (B) reviews — not two programs.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_006078e0` / `0x006078e0` | `Outpost_UpdateBeaconShareRatio` | **accept-with-gaps** |
| `aa_00507290` / `0x00507290` | `Host_ActionList_Push` | **accept** |

---

## Sealed facts — `0x006078e0` Outpost_UpdateBeaconShareRatio

1. **ABI:** MSVC **`__thiscall`** — **ECX = outpost**, **no stack args**, epilogue **`RET`**. Decompiler `__fastcall` is label noise. Body **`0x006078e0`–`0x006079e2`**.

2. **Ratio math:**  
   - `total = CVOGMap_LookupVariable(*(this+0x1d0), …)` seeded **`g_flOne`** (`0x00a0f2a0` = 1.0f)  
   - `factionB = CVOGMap_LookupVariable(*(this+0xf0 + faction*0x48), …)` seeded **0**  
   - `faction = *(int*)(this+0x234)`  
   - When `total > 0`: `*(float*)(this+0x24c) = factionB / total`

3. **Total ≤ 0:** log `"Total beacons was %f on map %s"` via `FUN_007a4480`; **do not** write `+0x24c`.

4. **On ratio change only:** `FUN_00606ff0(faction)` then `Outpost_CastSkillsForBeaconShare(faction)` (thiscall ECX=this). Unchanged ratio → store only, no recast.

5. **Callers:** direct from CaptureOutpost path `FUN_006082e0` @ `0x00608583` (after faction store). Second xref is MI **this-adjustor thunk** `0x006079f0`: `add ecx, -0x260; call; ret 4` (not owned).

6. **Name:** `Outpost_UpdateBeaconShareRatio` — descriptive from product string + ratio consumer dual (`aa_006070e0`). Former `FUN_006078e0`.

7. **Three-rep:** raw 2026-07-23 CF ≡ live decompile ≡ body bytes / call targets (`0x005b05f0`, `0x00606ff0`, `0x006070e0`, `0x007a4480`).

### Gaps (`006078e0`)

1. Product/PDB English for method + map-var field names.  
2. Full dual of `FUN_00606ff0` (pre-recast bank walk).  
3. Thunk `-0x260` secondary interface identity.  
4. Runtime / bit-exact / differential — open.

---

## Sealed facts — `0x00507290` Host_ActionList_Push

1. **ABI:** **`__thiscall`** — **ECX = host**, stack **`void* item`**, epilogue **`ret 4`**. Body **`0x00507290`–`0x005072c5`**.

2. **Vector @ host+0x94:**  
   | Off | Field |  
   |---:|---|  
   | +0x94 | `void**` data |  
   | +0x98 | `int` count |  
   | +0x9c | `uint` capacity (`& 0x7fffffff` for full test) |

3. **Algorithm:** if full → `FUN_005b3370(&vector, 4)` (cdecl grow, elem size **4**); `data[count] = item`; `count++`.

4. **Caller ECX = host (machine seal):**  
   - `Phys_ActionBase_ctor` `0x006363a1`  
   - `FUN_00636220` `0x00636246`  
   - `FUN_0066e660` `0x0066e698` / `0x0066e6ac` (dual host)  
   Decompiler display `FUN_00507290(action)` is **incomplete** — stack is the pointer stored; ECX is host.

5. **Not refcount:** body does not touch `+6`; callers addref host separately.

6. **Name:** `Host_ActionList_Push` (descriptive). Former `FUN_00507290` / bulk scaffold alias.

7. **Three-rep:** raw ≡ live decompile ≡ full body hex.

### Gaps (`00507290`)

1. Product C++ host type across callers.  
2. Capacity high-bit allocator semantics.  
3. Symmetric remove/dtor helper (not owned).  
4. Runtime / bit-exact — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x006078e0` | `reviews/A_aa_006078e0_Outpost_UpdateBeaconShareRatio.md` | `reviews/B_aa_006078e0_Outpost_UpdateBeaconShareRatio.md` | **accept-with-gaps** |
| `0x00507290` | `reviews/A_aa_00507290_Host_ActionList_Push.md` | `reviews/B_aa_00507290_Host_ActionList_Push.md` | **accept** |

---

## Files

### `aa_006078e0` / `Outpost_UpdateBeaconShareRatio`

| Kind | Absolute path |
|------|----------------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_006078e0_Outpost_UpdateBeaconShareRatio.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_006078e0_Outpost_UpdateBeaconShareRatio.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_006078e0_Outpost_UpdateBeaconShareRatio.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_006078e0_FUN_006078e0.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Outpost_UpdateBeaconShareRatio.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_006078e0.cpp` |
| Raw (+ re-verify append) | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_006078e0_FUN_006078e0.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_006078e0_FUN_006078e0.annotated.md` |

### `aa_00507290` / `Host_ActionList_Push`

| Kind | Absolute path |
|------|----------------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00507290_Host_ActionList_Push.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00507290_Host_ActionList_Push.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00507290_Host_ActionList_Push.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00507290_FUN_00507290.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Host_ActionList_Push.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_00507290.cpp` |
| Raw (+ re-verify append) | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00507290_FUN_00507290.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00507290_FUN_00507290.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w19o-006078e0-00507290-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x006070e0` | `Outpost_CastSkillsForBeaconShare` (ratio consumer; dual already) |
| `0x00606ff0` | Pre-recast bank walk on ratio change |
| `0x00606d70` | `Outpost_CastSkillsForFaction` |
| `0x006082e0` | CaptureOutpost path caller |
| `0x006079f0` | MI this-adjustor thunk → `006078e0` |
| `0x005b05f0` | `CVOGMap_LookupVariable` |
| `0x00636370` | `Phys_ActionBase_ctor` (primary push consumer) |
| `0x005b3370` | Vector grow helper for `Host_ActionList_Push` |
| `0x00636220` / `0x0066e660` | Other push callers |

---

## AutoCore impact

- **Outpost:** keep ratio recompute separate from BeaconShare cast; only recast when ratio changes; never store ratio when total beacons ≤ 0.  
- **Physics actions:** register actions with **host in ECX** and action pointer on stack; do not call push with action-as-this; addref host in ctor, not inside push.
