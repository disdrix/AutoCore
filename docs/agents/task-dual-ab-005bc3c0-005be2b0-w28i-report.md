# Dual A/B report — W28-I OWN-ONLY (`0x005bc3c0`, `0x005be2b0`)

**Date:** 2026-07-29  
**Agent:** W28-I OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005bc3c0`, `0x005be2b0`. Dual A/B + artifacts.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005bc3c0` Emitter_UpdateTick_Inferred | **accept-with-gaps** — full emitter frame update; `ret 0x0C`; keep 0\|1 for HostTick; interval child `0x005bc120`; pose-math port residual |
| `aa_005be2b0` ObjectMotion_SlotReleaseToFreelist_Inferred | **accept** — freelist push slot (+ child@+0x8); `ret 4`; global head `DAT_00b036c0`; empty dtor stub sealed |

---

## `aa_005bc3c0` — Emitter_UpdateTick_Inferred

### Sealed facts

1. **Body:** `0x005bc3c0`–`0x005bdce6` exclusive (**6438** B / `0x1926`). Final **`c2 0c 00`** (`ret 0x0C`); following `cc` pad.

2. **ABI:** `__thiscall` ECX=emitter; three stack args `(float *dt, int host_field_2c, int camera_or_world)`; clean **12** B; return **0**=remove / **1**=keep.

3. **Caller (1):** `NDSpecialFX_HostTick_Inferred` (`FUN_004b8ed0`) @ `0x004b90ef` — ECX = list `+0x1E0` payload; keep → `ObjectMotion_SlotListTick`; kill → unlink + `FUN_005be310`.

4. **Stages (CF):**
   ```
   counters++
   optional object-death pose snapshot (object+0x90e&1)
   if +0x7ff: clear; return 1
   countdown +0x810 -= *dt; if still >0: return 1
   early kill → return 0
   lifetime / flag gates
   pose refresh (object phys | skybox-UI | attachment)
   offset compose + motion
   if interval mode && *list==0: Emitter_SpawnOnIntervalTick
   clear +0x7fe; return 1
   ```

5. **Key child:** `Emitter_SpawnOnIntervalTick_Inferred` (`FUN_005bc120`) @ call `0x005bdcc1` (W26-I dualed).

6. **String:** `"Emitter found at 0,0,0: %d %I64d"` via `FUN_007a4480`.

7. **Constants (`read_memory`):** quat factor **2.0f** @ `DAT_00a10e74` (misnamed `g_flLevelUpUiBase_Inferred`); `DAT_00aaa668`=**-1.0f**; `DAT_00af3f70`=**-10.0f**.

8. **Name:** `Emitter_UpdateTick_Inferred`. Reject Input_PollB scaffold chain as product claim.

### Gaps

1. Product/PDB English.  
2. Full flag dictionary (`+0x989` family).  
3. Nested helpers not OWN.  
4. Staged clean is CF map — raw decompile is authority for bit-level pose math.  
5. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005bc3c0_Emitter_UpdateTick_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005bc3c0_Emitter_UpdateTick_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005bc3c0_Emitter_UpdateTick_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005bc3c0_Emitter_UpdateTick_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005bc3c0_Emitter_UpdateTick_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005bc3c0_FUN_005bc3c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Emitter_UpdateTick_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005bc3c0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005bc3c0_FUN_005bc3c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005bc3c0_FUN_005bc3c0.annotated.md` |

---

## `aa_005be2b0` — ObjectMotion_SlotReleaseToFreelist_Inferred

### Sealed facts

1. **Body:** `0x005be2b0`–`0x005be2e9` exclusive (**57** B / `0x39`). Final **`c2 04 00`** (`ret 4`); following `cc` pad.

2. **ABI:** `__thiscall` ECX=freelist head*; stack `(SlotNode *node)`; clean **4** B; void.

3. **Algorithm:**
   ```
   if node.child@+0x8:
     FUN_004b0bd0(this=child)   // empty
     freelist_push(child)
     node.child = 0
   FUN_004b0bd0(this=node)      // empty
   freelist_push(node)          // via dword0 next
   ```

4. **Global freelist:** both callers force **`mov ecx, 0x00B036C0`** (`DAT_00b036c0`) before call — not the motion host.

5. **Callee:** `FUN_004b0bd0` @ `0x004b0bd0` — **empty** body (thiscall stub).

6. **Callers (2):**
   - `ObjectMotion_SlotListTick_Inferred` (`FUN_005bb5e0`) @ `0x005bb624` — remove path after SlotTick returns 0  
   - `FUN_005bbc50` @ `0x005bbd0e` — host teardown walk of `+0xA24`

7. **Name:** `ObjectMotion_SlotReleaseToFreelist_Inferred`. Closes W27-D gap “dual of FUN_005be2b0”.

### Gaps

1. Product/PDB English.  
2. Why empty `FUN_004b0bd0` remains (stripped dtor vs intentional nop).  
3. Runtime freelist integrity under nested child — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005be2b0_ObjectMotion_SlotReleaseToFreelist_Inferred.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005be2b0_ObjectMotion_SlotReleaseToFreelist_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005be2b0_ObjectMotion_SlotReleaseToFreelist_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005be2b0_ObjectMotion_SlotReleaseToFreelist_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005be2b0_ObjectMotion_SlotReleaseToFreelist_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005be2b0_FUN_005be2b0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectMotion_SlotReleaseToFreelist_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005be2b0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005be2b0_FUN_005be2b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005be2b0_FUN_005be2b0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Emitter_UpdateTick_Inferred (`0x005bc3c0`)

- Port as **HostTick list worker** with keep polarity — not the interval-spawn-only child.
- Preserve **`ret 0x0C`** and countdown early-out (most ticks return keep without full pose work).
- Quat basis factor is **2.0f**, not a UI constant — ignore `g_flLevelUpUiBase_Inferred` name.
- Interval spawn remains **`Emitter_SpawnOnIntervalTick_Inferred`**; call only when interval mode and active list empty.
- On return 0, HostTick owns unlink/delete + `FUN_005be310` — do not free inside this unit.

### ObjectMotion_SlotReleaseToFreelist_Inferred (`0x005be2b0`)

- Port as **global freelist push** (`DAT_00b036c0`), not motion-host method state.
- **Must** freelist nested `+0x8` child before parent; clear child ptr.
- **Must not** `operator_delete` here — SlotListTick deletes the **list wrapper** after release.
- `FUN_004b0bd0` is empty — do not invent resource teardown inside it.

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004b8ed0` | `NDSpecialFX_HostTick_Inferred` — sole emitter-tick caller |
| `0x005bc120` | `Emitter_SpawnOnIntervalTick_Inferred` (W26-I) — late child |
| `0x005bb5e0` | `ObjectMotion_SlotListTick_Inferred` (W27-D) — freelist caller |
| `0x004b4620` | `ObjectMotion_SlotTick_Inferred` (W26-H) |
| `0x005bbc50` | motion host teardown — freelist caller |
| `0x004b0bd0` | empty thiscall stub |
| `0x00b036c0` | global slot freelist head |

---

## Process

- OWN-ONLY dual W28-I; tools limited to decompile + read_memory (+ meta/xrefs).  
- No Launcher; no parent ledger edits.  
- Scaffold raw bodies retained; W28-I appends on raw; named clean + dual A/B written.
