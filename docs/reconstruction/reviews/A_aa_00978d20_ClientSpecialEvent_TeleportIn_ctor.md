# Review A (reconstruction fidelity): `aa_00978d20` ClientSpecialEvent_TeleportIn_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00978d20` |
| **VA** | `0x00978d20` |
| **Canonical name** | `ClientSpecialEvent_TeleportIn_ctor` |
| **Former name** | `FUN_00978d20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (client INC airlift **arrive** special-event ctor) |
| **Counterpart** | `reviews/B_aa_00978d20_ClientSpecialEvent_TeleportIn_ctor.md` |
| **System** | client special-event / teleport presentation |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Constructs the client **TeleportIn** special-event object (INC airlift **arrive** animation). Sole production caller is `Client_RecvSpecialEvent` when packet type byte `packet+0x04 == 2`. Alloc size **`0x50`**.

Pairs with TeleportOut (type 1): same CBID **`0xadc`**, same three airlift `.anm` binds, plus **`cptest.geo`** ship spawn + hardpoint **35** attach (shared string family with Respawn Update). Ends in `FUN_00978990`.

Source path string: `…\appClient\ClientSpecialEvent_TeleportIn.cpp` (log line **0x36**).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live Ghidra | `batch_decompile` `0x00978d20` |
| Prologue | `read_memory` @ `0x00978d20` (48 B): SEH `LAB_009b294a`, `sub esp,0x38`, **`mov esi, ecx`**, object via stack pointer |
| Globals | `audit_globals_in_function` `0x00978d20` |
| Constants | `g_flOne` 1.0f; `DAT_00aaaa84` ≈2.39688e-5 (shared with TeleportOut) |
| Xrefs | sole call `Client_RecvSpecialEvent` `0x0080cdad` |
| Three-rep | `raw/aa_00978d20_*`, `reconstructed-exact/FUN_00978d20.cpp`, `Named_ClientSpecialEvent_TeleportIn_00978d20.cpp` |
| Function record | `functions/aa_00978d20_FUN_00978d20.md` |
| Sibling context (read-only) | Respawn Update dual for hardpoint-35 / `cptest.geo` pattern |

---

## 3. Signature (ABI — decompiler hazard)

```c
// Ghidra labels: __thiscall ClientSpecialEvent_TeleportIn_ctor(int param_1, undefined4 *param_2)
// Assembly reality:
//   ECX = entity*          (stored at event+0x38; compared to DAT_00d1b6d8)
//   stack = event* this    (receives vtables; returned)
// Caller decompile may show only TeleportIn_ctor(event) — entity lives in ECX from surrounding iVar5.
// Alloc size 0x50.

undefined4 * ClientSpecialEvent_TeleportIn_ctor(/*ecx*/ int entity, /*stack*/ undefined4 *event);
// returns event
```

**Do not** trust Ghidra param order as MSVC member-this without re-checking call site registers.

---

## 4. Control flow (sealed)

```
// event = param_2 in decomp; entity = param_1 / ECX
*event = PTR_LAB_00a766f8
event+0x04 = 0
*event = PTR_FUN_00a76800              // TeleportIn vtable
event+0x08 = 0
event+0x24 = 0                         // param_2[9] presentation later
event+0x28 = 0                         // param_2[10] ship slot
event+0x38 = entity                    // param_2[0xe]
event+0x3c = 0
event+0x44 = 0
event+0x48 = 0                         // byte
event+0x49 = 0                         // byte

obj = CVOGReaction_GiveItemByCbid(0xadc)
if !obj:
  FUN_007a4480()
else:
  // same bind chain as TeleportOut
  obj->vt+8(); FUN_0092c760(); FUN_00512160(); FUN_004bc180(obj)
  event+0x24 = obj->vt+0x1cc()         // presentation root

  // random orientation (same DAT_00aaaa84 path)
  RandomUnitScalar + FUN_0076f5f0 + sin/cos → quat temps

  // entity pose via vt+0x1a0 (note: TeleportOut used +0x19c)
  copy float4 into event+0x10..+0x1c   // param_2[4..7]
  FUN_004e88e0(…)

  drive presentation root (vt+0(1), +0x20, child +0x100)
  FUN_005828b0(1..3, airlift_*.anm, 0)
  FUN_005816a0(1, 0)
  event+0x48 = 1                       // param_2[0x12] = 1  (armed / has-ship path flag)

  // Spawn airlift ship 0x14c
  ship = operator_new(0x14c) ? FUN_00764030() : 0
  event+0x28 = ship                    // param_2[10]
  FUN_00989e00(&name, "cptest.geo")
  ship->vt+0x5c(&name)                 // load geo

  // Hardpoint probes (same family as Respawn Update)
  if !FUN_0040d4b0() || !FUN_0040d4b0():   // fail either probe
    log "No 35 from INC provided" @ ClientSpecialEvent_TeleportIn.cpp:0x36
    VOG_DEBUG_STOP via FUN_007a4480
    destroy ship; event+0x28 = 0
  else:
    // attach glue: operator_new(0x10), FUN_004406e0, FUN_0044af00×2,
    // FUN_0044adc0 / operator_delete hazard, vt+0x30/+0x34, FUN_00439a80, FUN_0074c9c0

  // Local camera (entity pointer compared directly to DAT_00d1b6d8 — no vt+0x210)
  if event+0x38 == DAT_00d1b6d8:
    event+0x20 = *(DAT_00d1b778+0x60c)  // param_2[8] cookie
    *(DAT_00d1b778+0x60c) = 4
    FUN_0090dd50()
    write pose into +0xce4..+0xcfc

  FUN_00978990()                       // start TeleportIn sequence

return event
```

---

## 5. Layout / constants (sealed)

### Event object (`0x50` bytes) — fields touched here

| Offset | Role | Evidence |
|---:|---|---|
| `+0x00` | vtable `PTR_FUN_00a76800` | over base `PTR_LAB_00a766f8` |
| `+0x04 / +0x08` | bytes 0 | |
| `+0x10..+0x1c` | dest/entity pose float4 | from entity `vt+0x1a0` |
| `+0x20` | camera cookie | local branch |
| `+0x24` | presentation root* | CBID path `vt+0x1cc` |
| `+0x28` | airlift ship* | `0x14c` + `cptest.geo` |
| `+0x38` | entity* / local token | ctor ECX |
| `+0x3c / +0x44` | zeroed | |
| `+0x48` | byte **1** after anim bind | armed flag |
| `+0x49` | byte 0 | |

### Constants / strings

| Item | Value |
|---|---|
| Alloc size | **`0x50`** |
| CBID | **`0xadc`** |
| Geo | `"cptest.geo"` |
| Fail string | `"No 35 from INC provided"` |
| Source | `ClientSpecialEvent_TeleportIn.cpp` line **0x36** |
| Anims | same three `obj_f_inc_mov_01_airlift_*.anm` as TeleportOut |
| Event type | **2** |
| Ship ctor size | **`0x14c`** → `FUN_00764030` |

---

## 6. Callers / callees

| Direction | Symbol | Note |
|---|---|---|
| **Caller** | `Client_RecvSpecialEvent` `0x0080cdad` | only |
| Callee | `CVOGReaction_GiveItemByCbid(0xadc)` | presentation |
| Callee | `FUN_00764030` / `operator_new(0x14c)` | ship |
| Callee | `FUN_00989e00` | geo name wrapper |
| Callee | `FUN_0040d4b0` ×2 | hardpoint probes (35 family) |
| Callee | `FUN_004406e0` / `FUN_0044af00` / `FUN_0044adc0` / `FUN_00439a80` / `FUN_0074c9c0` | attach glue (Tentative names) |
| Callee | `FUN_005828b0` ×3 / `FUN_005816a0(1,0)` | anims |
| Callee | `FUN_0090dd50` | local camera |
| Callee | `FUN_00978990` | start arrive sequence |
| Callee | `vog_LogMessage` / `FUN_0076cec0` / `FUN_007a4480` | hardpoint fail |

---

## 7. Decompiler hazards

1. **ABI / thiscall param order** — assembly: ECX=entity, stack=event; Ghidra names inverted vs normal member ctor.
2. **Caller shows one arg** — entity is register-passed; dual must not drop entity.
3. **Local gate differs from TeleportOut** — direct `entity == DAT_00d1b6d8` vs `vt+0x210(0)` compare. Do not unify blindly.
4. **Pose fetch slot `vt+0x1a0` vs Out `+0x19c`** — distinct vtable offsets; not a typo without proof.
5. **`operator_delete` noreturn** on attach assert — Ghidra false-noreturn class; fail path still nulls ship on hardpoint fail.
6. **Stack float garbage** — same SEH/cookie mis-types as TeleportOut.

---

## 8. Confidence

| Area | Level |
|---|---|
| Name / type-2 arrive ctor | **High** (symbol + source path + dispatch) |
| Size `0x50`, ship `+0x28`, presentation `+0x24`, entity `+0x38` | **High** |
| `cptest.geo` + hardpoint-35 fail string | **High** |
| Shared CBID/anims with TeleportOut | **High** |
| ABI ECX=entity / stack=event | **High** (prologue) / **Medium** if caller re-annotated |
| Attach glue product names | **Medium–Low** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — arrive ctor layout, geo/hardpoint fail path, and start helper sealed; ABI annotation and attach glue remain the main residuals.
