# Review A (reconstruction fidelity): `aa_00979730` ClientSpecialEvent_Respawn_Update

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979730` |
| **VA** | `0x00979730` |
| **Canonical name** | `ClientSpecialEvent_Respawn_Update` |
| **Former name** | (named in Ghidra) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (client INC airlift / respawn special-event tick) |
| **Counterpart** | `reviews/B_aa_00979730_ClientSpecialEvent_Respawn_Update.md` |
| **System** | client special-event / respawn presentation |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Per-frame **virtual Update** for the client **Respawn** special-event object (source path string `ClientSpecialEvent_Respawn.cpp`). Drives an **INC airlift** state machine: spawn `cptest.geo` ship, lift the controlled entity, teleport to packet dest pose, lower / cleanup camera, complete.

**Not** a network handler. Packet construction lives in `Client_RecvSpecialEvent` (type 0 → ctor); this unit only advances presentation state.

Return **1** = event finished (phase 6→7, or phase 2 short-circuit when `this+0x38 == 0`); return **0** = keep ticking.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live Ghidra | `decompile_function` `0x00979730`; body `00979730`–`00979c6c`; `read_memory` prologue + timing floats |
| Globals audit | `audit_globals_in_function` `0x00979730` |
| Xrefs | `get_function_xrefs` → sole **DATA** from vtable `PTR_…_00a76720` (virtual method, not direct call) |
| Context (read-only, not dual-owned) | ctor `0x00979650` decompile for layout init; string `"No 35 from INC provided"` / `"cptest.geo"` |
| Three-rep | `raw/aa_00979730_*`, `reconstructed-exact/ClientSpecialEvent_Respawn_Update.cpp` |
| Function record | `functions/aa_00979730_ClientSpecialEvent_Respawn_Update.md` |

---

## 3. Signature (ABI sealed from prologue)

```c
// __thiscall — ECX = ClientSpecialEvent_Respawn*
// Stack: float dt @ [ebp+8]
// Prologue (read_memory @ 0x00979730):
//   push ebp; mov ebp,esp; and esp,-0x10
//   SEH frame → LAB_009b296a
//   sub esp,0x38; push ebx,esi,edi
//   mov edi, ecx                    ; this
//   cmp byte ptr [edi+8], 0
//   mov [esp+0x20], edi             ; local_40 = this
//   jz  active_path
//   call FUN_00979310               ; cancel/teardown helper
//   jmp epilogue → return 0
// active_path:
//   movss xmm0, dword ptr [ebp+8]   ; dt
//   mov eax, DAT_00d09874
undefined4 __thiscall ClientSpecialEvent_Respawn_Update(int this, float dt);
```

**Return:** `undefined4` as **bool-ish** completion: **1** finished, **0** continue (or cancelled path after `FUN_00979310`).

---

## 4. Control flow (sealed)

```
if (this+0x08) != 0:                    // cancelled / inactive flag
  FUN_00979310()
  return 0

this+0x60 += dt                         // elapsed accumulator

// Per-frame visual tick (graphics objects at this+0x10)
(*(this+0x10)->vt+0x28)(*(DAT_00d09874 + 0x238))
(*( (this+0x10)+8 )->vt+0x34)()

entity = FUN_004bb010(this+0x28)        // resolve TFID at +0x28..

// Continuous lift follow while +0x6c set:
if (this+0x6c):
  shipPose = (*(this+0x14)->vt+0x0c)()   // airlift ship matrix/pos
  delta = shipPose.{x,y,z @ +0x90..} − this.{+0x18,+0x1c,+0x20}
  if entity:
    CVOGReaction_TeleportTarget(entity, FUN_004e9530(delta))

// ── Phase machine (phase byte this+0x6d; phaseTime this+0x64) ──
// Nested high→low so only one transition fires per tick.

// phase 6 → 7 COMPLETE
if elapsed >= phaseTime + 4.0f && phase == 6:
  phaseTime = phaseTime + 4.0f
  phase = 7
  return 1

// phase 5 → 6   (Δ = g_flLevelUpUiBase_Inferred = 2.0f)
if elapsed >= phaseTime + 2.0f && phase == 5:
  phase = 6; phaseTime += 2.0f
  FUN_005816a0(2, 0.1f)
  // fall to return 0

// phase 4 → 5   (Δ = g_flOne = 1.0f)
else if elapsed >= phaseTime + 1.0f && phase == 4:
  phaseTime += 1.0f; phase = 5
  this+0x6c = 0                         // stop lift-follow
  FUN_00979290()                        // destroy/detach airlift visual
  if entity is local player (vt+0x210(0) == DAT_00d1b6d8):
    *(DAT_00d1b778 + 0x60c) = *(this+0x0c)
    FUN_0090dd50()                      // camera restore

// phase 3 → 4   (Δ = DAT_00aaa8b0 ≈ 3.433f)
else if elapsed >= phaseTime + 3.433f && phase == 3:
  phaseTime += 3.433f; phase = 4
  FUN_005816a0(0, 0.1f)

// phase 2 → 3   (Δ = DAT_00aaa690 = 4.0f)
else if elapsed >= phaseTime + 4.0f && phase == 2:
  phase = 3; phaseTime += 4.0f
  if (this+0x38) == 0:
    return 1                            // short complete (no full sequence)
  // set entity/child orientation from dest pose builder FUN_004e88e0(this+0x40)
  // if local: attach camera FUN_00417e40(DAT_00d1b778)
  FUN_005816a0(1, 0.1f)
  if entity:
    CVOGReaction_TeleportTarget(entity, this+0x40)
    FUN_00404dc0(this+0x50)             // apply dest quat / orientation slot

// phase 1 → 2   (Δ = DAT_00aaab48 ≈ 0.566f)
else if elapsed >= phaseTime + 0.566f && phase == 1:
  phase = 2; phaseTime += 0.566f
  FUN_005816a0(2, 0.1f)

// phase 0 → 1   (gate: absolute elapsed >= 3.433f, phase==0)
else if elapsed >= 3.433f && phase == 0:
  phase = 1
  phaseTime = phaseTime + 3.433f        // fVar8 still holds phaseTime+DAT_00aaa8b0
  FUN_005816a0(3, 0.1f)
  this+0x6c = 1                         // enable lift-follow
  // allocate airlift ship 0x14c → FUN_00764030 ctor
  // load geo "cptest.geo" via vt+0x5c
  // require FUN_0040d4b0(0x23) AND FUN_0040d4b0(0)  // hardpoint 35 + 0
  //   else: log "No 35 from INC provided" @ ClientSpecialEvent_Respawn.cpp:0xb4
  //         VOG_DEBUG_STOP; destroy ship; this+0x14 = 0
  //   else: attach to vehicle graphics child (this+0x10)+8, link hardpoints,
  //         vt+0x30(3)/+0x34, FUN_00439a80 / FUN_0074c9c0 glue

return 0
```

---

## 5. Layout / constants (sealed)

### Event object fields used in this unit

| Offset | Type / role | Evidence |
|---:|---|---|
| `+0x00` | vtable → Update @ `0x00979730` | ctor writes `PTR_…_00a76720` |
| `+0x08` | `char` cancel/inactive | prologue branch; else `FUN_00979310` |
| `+0x0c` | camera restore cookie | written to `DAT_00d1b778+0x60c` on local phase 4→5 |
| `+0x10` | graphics root (pair + child @ `+8`) | vt ticks every frame |
| `+0x14` | airlift ship object* | allocated phase 0; pose for lift delta |
| `+0x18..+0x20` | float3 lift origin | subtracted from ship pose `+0x90..` |
| `+0x28..+0x34` | TFID16 controlled entity | ctor from entity `+0x164`; `FUN_004bb010` |
| `+0x38` | `char` full-sequence flag | phase 2: 0 → early `return 1` |
| `+0x40..+0x4c` | dest pose (pos) | `CVOGReaction_TeleportTarget` / `FUN_004e88e0` |
| `+0x50..+0x5c` | dest orientation (quat-ish) | `FUN_00404dc0` after teleport |
| `+0x60` | `float` elapsed | `+= dt` each active tick |
| `+0x64` | `float` phaseTime base | advanced on each phase enter |
| `+0x6c` | `char` lift-follow enable | set phase 0; cleared phase 4→5 |
| `+0x6d` | `char` phase `0..7` | state machine |

Ctor also zeros `+0x10/+0x14`, TFID, dest, elapsed, phaseTime, `+0x6c/+0x6d`, and calls `FUN_00979310` once at construct.

### Timing constants (`read_memory`)

| Symbol | VA | Hex | Float | Role |
|---|---|---|---:|---|
| `DAT_00aaa690` | `0x00aaa690` | `00008040` | **4.0** | phase 2→3 and 6→7 Δ |
| `DAT_00aaa8b0` | `0x00aaa8b0` | `46b65b40` | **≈3.433** | phase 0 gate (absolute) + 0→1 / 3→4 Δ |
| `DAT_00aaab48` | `0x00aaab48` | `60e5103f` | **≈0.566** | phase 1→2 Δ |
| `g_flOne` | `0x00a0f2a0` | `0000803f` | **1.0** | phase 4→5 Δ |
| `g_flLevelUpUiBase_Inferred` | `0x00a10e74` | `00000040` | **2.0** | phase 5→6 Δ (shared float pool; name is cross-system) |
| imm `0x3dcccccd` | — | — | **0.1** | second arg to all `FUN_005816a0` calls |

### Named / string evidence

| Item | Value |
|---|---|
| Source file | `…\appClient\ClientSpecialEvent_Respawn.cpp` line **0xb4** (180) |
| Geo asset | `"cptest.geo"` |
| Hardpoint fail | `"No 35 from INC provided"` — matches `FUN_0040d4b0(0x23)` (**35**) |
| Debug stop | `"VOG_DEBUG_STOP"` via `FUN_007a4480(0, …)` |

### Local-player gate

```
entity → MI adjust → vt+0x210(0)  compared to  DAT_00d1b6d8
```

Used only for camera attach (`FUN_00417e40`) at phase 2 and camera restore (`FUN_0090dd50` + write `+0x60c`) at phase 4→5.

---

## 6. Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| **Caller** | vtable dispatch only | DATA xref `0x00a76720` (Update slot) |
| Callee | `FUN_00979310` | cancel path + ctor init |
| Callee | `FUN_004bb010` | TFID → entity* |
| Callee | `CVOGReaction_TeleportTarget` | lift follow + dest snap |
| Callee | `FUN_004e9530` | build transform from float3 delta |
| Callee | `FUN_004e88e0` | dest pose builder for orientation write |
| Callee | `FUN_005816a0` | mode `0|1|2|3` + blend `0.1f` (camera/anim helper) |
| Callee | `FUN_00979290` | airlift teardown mid-sequence |
| Callee | `FUN_0090dd50` | local camera restore |
| Callee | `FUN_00417e40` | local camera attach to airlift path |
| Callee | `FUN_00404ba0` | resolve `"cptest.geo"` |
| Callee | `FUN_00764030` | ship object ctor (`operator_new(0x14c)`) |
| Callee | `FUN_0040d4b0` | hardpoint/probe **0x23** and **0** |
| Callee | `vog_LogMessage` / `FUN_0076cec0` / `FUN_007a4480` | fail path |
| Callee | `FUN_00439a80` / `FUN_0074c9c0` / `FUN_004406e0` / `FUN_0044af00` / `FUN_0044adc0` | attach/link glue (names Tentative) |

---

## 7. Decompiler hazards (fidelity notes)

1. **`fVar8` / `fVar9` SSA reuse** — thresholds for several phases share decompiler temps. Port must recompute `phaseTime + Δ` per transition; do not reuse a single SSA across phases blindly.
2. **Phase 0 absolute vs relative** — enter uses `elapsed >= DAT_00aaa8b0` (absolute), but then writes `phaseTime = phaseTime + DAT_00aaa8b0` from the outer nested `fVar8`. Correct if ctor left `phaseTime==0`.
3. **`g_flLevelUpUiBase_Inferred` name** — global is a shared **2.0f** pool also used by level-up UI; **not** respawn-specific semantics. Prefer numeric **2.0f** or a respawn-local alias in ports.
4. **`FUN_005816a0` / hardpoint / camera helpers** — roles inferred from call sites + strings; exact product names remain open (own-VA only).
5. **`operator_delete` noreturn** on hardpoint assert path — same Ghidra false-noreturn class; fail path continues to null `this+0x14`.
6. **Clean scaffold CF** matches live decompile (phase nesting, returns, strings). Parameter names still generic (`param_1`/`param_2`).

---

## 8. Confidence

| Area | Level |
|---|---|
| Name / role (client Respawn special-event Update) | **High** (symbol + source path string) |
| ABI thiscall + `float dt` | **High** (prologue) |
| Cancel flag `+0x08` → `FUN_00979310` | **High** |
| Elapsed `+0x60` / phaseTime `+0x64` / phase `+0x6d` / lift `+0x6c` | **High** |
| Timing floats 4.0 / ≈3.433 / ≈0.566 / 1.0 / 2.0 / 0.1 | **High** (`read_memory`) |
| Phase order 0→1→2→3→4→5→6→7 and return-1 complete | **High** |
| `cptest.geo` spawn + hardpoint 35 fail string | **High** |
| Dest teleport `+0x40` + local camera branches | **High** (structure) |
| Exact product meaning of `FUN_005816a0` modes 0–3 | **Medium** |
| Exact layouts of ship/graphics children / hardpoint API | **Medium / Tentative** |
| Runtime / bit-exact vs retail | **Open** |

**Verdict:** **accept-with-gaps** — state machine, fields, and timing constants sealed for a client presentation port; helper product names and hardpoint attach glue remain partial.
