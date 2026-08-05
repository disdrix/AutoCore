# Review A (reconstruction fidelity): `aa_00979650` ClientSpecialEvent_Respawn_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979650` |
| **VA** | `0x00979650` |
| **Canonical name** | `ClientSpecialEvent_Respawn_ctor` |
| **Former name** | `FUN_00979650` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (client Respawn special-event ctor) |
| **Counterpart** | `reviews/B_aa_00979650_ClientSpecialEvent_Respawn_ctor.md` |
| **System** | client special-event / respawn presentation |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Constructs the client **Respawn** special-event object. Sole production caller is `Client_RecvSpecialEvent` when packet type byte `packet+0x04 == 0`. Alloc size **`0x70`**.

Installs vtable whose Update slot is `ClientSpecialEvent_Respawn_Update` (`0x00979730` / `PTR_…_00a76720`). Copies controlled-entity **TFID16** from entity layout `+0x164`, stores full-sequence **flag** at `this+0x38`, copies **dest position** and **dest quaternion** from packet-derived args, zeros phase timers, then calls init helper `FUN_00979310`.

**Not** the phase machine (that is Update). **Not** network parse (that is `Client_RecvSpecialEvent`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live Ghidra | `batch_decompile` `0x00979650` |
| Prologue | `read_memory` @ `0x00979650`: SEH `LAB_009b02a3`; **`mov esi, edx`** (entity); stack-held `this`; ECX used as dest source |
| Xrefs | sole call `Client_RecvSpecialEvent` `0x0080cde2` |
| Three-rep | `raw/aa_00979650_*`, `reconstructed-exact/FUN_00979650.cpp` |
| Function record | `functions/aa_00979650_FUN_00979650.md` |
| Sibling dual (read-only) | `A/B_aa_00979730_ClientSpecialEvent_Respawn_Update.md` field map consistency |

---

## 3. Signature (ABI)

```c
// __fastcall-style (Ghidra):
//   ECX = dest position float4*   (param_1)
//   EDX = entity*                 (param_2)  — used for TFID at entity MI +0x164
//   stack: Event* this (param_3), bool/byte flag (param_4), float4* quat (param_5)
// Returns this (event*).

undefined4 * __fastcall
ClientSpecialEvent_Respawn_ctor(
    undefined4 *destPos,   // ecx
    int entity,            // edx
    undefined4 *this,      // stack
    undefined1 flag,       // stack — packet+0x40 != 0 at caller
    undefined4 *destQuat); // stack
```

**Caller note:** clean `Client_RecvSpecialEvent` decompile is **incomplete** (shows `Respawn_ctor(event, flag, &quat)` only). Live body + prologue require **ECX=dest**, **EDX=entity**. Packet sources: dest `@packet+0x08`, quat `@packet+0x14`, flag `@packet+0x40`.

---

## 4. Control flow (sealed)

```
*this = PTR_LAB_00a766f8
this+0x04 = 0
*this = PTR_ClientSpecialEvent_Respawn_Update_00a76720
this+0x08 = 0
this+0x10 = 0                 // gfx root (filled later in Update)
this+0x14 = 0                 // airlift ship slot

// TFID16 from entity at (MI adjust)+0x164
tfid* = entity_MI_base + 0x164
this+0x28..+0x34 = *tfid     // four dwords  (param_3[10..13])

this+0x38 = flag              // full-sequence / packet+0x40 nonzero  (param_3[0xe] as byte)

this+0x40..+0x4c = *destPos   // param_3[0x10..0x13]
this+0x50..+0x5c = *destQuat  // param_3[0x14..0x17]

this+0x60 = 0                 // elapsed
this+0x64 = 0                 // phaseTime
this+0x6c = 0                 // lift-follow byte
this+0x6d = 0                 // phase byte

FUN_00979310()                // shared cancel/init helper (also used by Update cancel path)

return this
```

---

## 5. Layout (sealed — aligns with Respawn Update dual)

| Offset | Role | Init here |
|---:|---|---|
| `+0x00` | vtable → Update `0x00979730` | **Yes** |
| `+0x04` | byte | 0 |
| `+0x08` | cancel/inactive | 0 |
| `+0x10 / +0x14` | gfx / ship | 0 (Update fills) |
| `+0x28..+0x34` | TFID16 | from entity `+0x164` |
| `+0x38` | full-sequence flag | packet flag |
| `+0x40..+0x4c` | dest pos | ctor arg |
| `+0x50..+0x5c` | dest quat | ctor arg |
| `+0x60 / +0x64` | elapsed / phaseTime | 0 |
| `+0x6c / +0x6d` | liftFollow / phase | 0 |

**Object size:** **`0x70`** (caller `operator_new`).

---

## 6. Callers / callees

| Direction | Symbol | Note |
|---|---|---|
| **Caller** | `Client_RecvSpecialEvent` | type 0; requires `entity+0x250 != 0` before construct |
| Callee | `FUN_00979310` | init/cancel helper only |

No anim/CBID/camera work in this VA — pure field install + helper.

---

## 7. Decompiler hazards

1. **Caller decompile drops ECX/EDX** — ports must still pass dest + entity.
2. **Flag is byte** stored at `+0x38`; caller passes `*(packet+0x40) != 0` (booleanized). Update uses `+0x38 == 0` for early complete.
3. **TFID copy uses MI adjustment** `*(entity+4)+4 + 0x164 + entity` — standard object-layout pattern; do not treat `entity+0x164` as raw without MI.
4. **Plate comment “EDX=entity+0x250 child”** is **wrong** relative to body (EDX is entity; `+0x250` is only a **caller gate**). Prefer body evidence.

---

## 8. Confidence

| Area | Level |
|---|---|
| Name / type-0 Respawn ctor | **High** |
| Size `0x70`, vtable → Update `0x00979730` | **High** |
| Field map `+0x28` TFID / `+0x38` flag / dest / phase zeros | **High** |
| ABI ECX=dest EDX=entity stack=(this,flag,quat) | **High** (prologue + body) |
| Caller clean completeness | **Low** (incomplete listing) |
| `FUN_00979310` product body | **Medium** (out of own VA) |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — ctor is a tight field initializer; layout sealed against Update dual; residual is caller-side ABI documentation and helper body.
