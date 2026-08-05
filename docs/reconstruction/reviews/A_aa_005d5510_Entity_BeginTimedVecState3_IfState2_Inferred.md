# Review A (reconstruction fidelity): `aa_005d5510` Entity_BeginTimedVecState3_IfState2_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d5510` |
| **VA** | `0x005d5510` |
| **Canonical name** | `Entity_BeginTimedVecState3_IfState2_Inferred` (structural) |
| **Ghidra name** | `FUN_005d5510` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_005d5510_Entity_BeginTimedVecState3_IfState2_Inferred.md` |
| **System** | npc-ai / spawn / timed entity motion residual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Conditional state transition** on an entity/controller: if phase byte `this+0x50 == 2`, enter phase **3** with a 16-byte vector payload and optional deadline from `g_dwClientTickMs + delayMs`.

Sole static caller: `CVOGSpawnPoint_SetObjectActiveState` (`0x00564700`) on NPC deactivate/wander arm — after sampling random position offsets into a 4-float stack blob, calls:

```
FUN_005d5510(&fStack_30, 5000);  // this=entity, vec=4 floats, delay=5000 ms
```

Recovered CF:

1. If `*(char*)(this+0x50) != 2`: **no-op return**.
2. Clear handles: `*(this+0x40/0x44/0x48) = -1`.
3. `*(this+0x50) = 3`; `*(this+0x51) = 0`.
4. Zero `this+0x20..+0x2c` (4 dwords) — bytes use `xorps`/`movups` style clears.
5. Deadline: if `delayMs != 0` then `g_dwClientTickMs + delayMs` else `0`; store at `this+0x54`.
6. Copy `param_2[0..3]` → `this+0x20..+0x2c` (16-byte / 4-float payload).

**ABI:** `__thiscall` entity; `param_2` = `uint32_t[4]` / float4; `param_3` = delay ms.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_005d5510_*`, `reconstructed-exact/FUN_005d5510.cpp` |
| Function record | `functions/aa_005d5510_FUN_005d5510.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x005d5510` (2026-07-29) ≡ clean |
| Bytes | `read_memory` 80 B — `cmp byte [ecx+0x50],2`; `jne`; `-1` fills; `mov byte [ecx+0x50],3`; SSE clears; add `g_dwClientTickMs` |
| Parent dual | `A_aa_00564700_CVOGSpawnPoint_SetObjectActiveState.md` |
| Parent clean call site | `CVOGSpawnPoint_SetObjectActiveState.cpp` — wander offset + `5000` |
| Callers | sole: `CVOGSpawnPoint_SetObjectActiveState` @ `005649e0` |

**Not performed:** disassemble_bytes, Launcher, runtime, consumer of phase 3.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gate only when `+0x50 == 2` | **Confirmed** | body + bytes |
| Sets phase to **3**; clears `+0x51` | **Confirmed** | body |
| Invalidates `+0x40/44/48` to -1 | **Confirmed** | body |
| Deadline `+0x54` = tick+delay or 0 | **Confirmed** | uses `g_dwClientTickMs` |
| Payload 16 B at `+0x20` from `param_2` | **Confirmed** | 4 dwords |
| Parent passes ~position float4 + 5000 ms | **High** | clean parent |
| Product English for phase 2/3 | **Open** | structural |
| Who ticks phase 3 / uses deadline | **Open** | no consumer dual here |
| clean ≡ raw | **High** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| State!=2 early out | Yes |
| Handles -1; state 3 | Yes |
| Zero then copy vec; set deadline | Yes |

### Recovered CF

```c
// void __thiscall Entity_BeginTimedVecState3_IfState2(Entity* e, uint32_t vec4[4], int delayMs)
if (e->state_50 != 2) return;
e->h40 = e->h44 = e->h48 = -1;
e->state_50 = 3;
e->byte_51 = 0;
// zero e->blob20[4]
e->deadline_54 = delayMs ? (g_dwClientTickMs + delayMs) : 0;
memcpy(e->blob20, vec4, 16);
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `CVOGSpawnPoint_SetObjectActiveState` | NPC wander timed relocate |
| Callee | none (leaf) | reads global `g_dwClientTickMs` |

---

## 6. Gaps / open

1. Product names for phase enum and handle slots.
2. Consumer tick that advances state 3 → done (who reads `+0x54` / `+0x20`).
3. Whether payload is world position, offset, or TFID-like (parent builds float XYZ+W from entity pose + random — **Probable position**).
4. Runtime capture of 5s wander.

**Verdict:** **accept-with-gaps** — state2→3 + deadline + vec copy sealed; consumer Open.
