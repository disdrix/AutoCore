# Review A (reconstruction fidelity): `aa_009781d0` ClientSpecialEvent_TeleportOut_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_009781d0` |
| **VA** | `0x009781d0` |
| **Canonical name** | `ClientSpecialEvent_TeleportOut_ctor` |
| **Former name** | `FUN_009781d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (client INC airlift **leave** special-event ctor) |
| **Counterpart** | `reviews/B_aa_009781d0_ClientSpecialEvent_TeleportOut_ctor.md` |
| **System** | client special-event / teleport presentation |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Constructs the client **TeleportOut** special-event object (INC airlift **leave** animation). Sole production caller is `Client_RecvSpecialEvent` when packet type byte `packet+0x04 == 1`. Alloc size **`0x34`**.

Loads CBID **`0xadc`** presentation object, randomizes a unit orientation, attaches airlift anim set `obj_f_inc_mov_01_airlift_*.anm`, optionally hijacks local camera cookies, then starts the event via `FUN_009780c0`.

**Not** a network handler and **not** the per-frame Update — presentation setup only.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live Ghidra | `batch_decompile` / `decompile_function` `0x009781d0` |
| Prologue | `read_memory` @ `0x009781d0` (48 B) |
| Globals | `audit_globals_in_function` `0x009781d0` |
| Constants | `read_memory` `g_flOne` @ `0x00a0f2a0` = **1.0f**; `DAT_00aaaa84` @ `0x00aaaa84` = **≈2.39688e-5** (`a310c937`) |
| Xrefs | `get_function_xrefs` → sole **UNCONDITIONAL_CALL** from `Client_RecvSpecialEvent` `0x0080cd8a` |
| Three-rep | `raw/aa_009781d0_*`, `reconstructed-exact/FUN_009781d0.cpp` |
| Function record | `functions/aa_009781d0_FUN_009781d0.md` |
| Caller context (read-only) | `Client_RecvSpecialEvent` type 1 → `operator_new(0x34)` + this ctor |

---

## 3. Signature (ABI)

```c
// MSVC thiscall-style: ECX / first arg = event object (size 0x34)
// Stack / second arg = controlled entity*
// Returns this (event*)
undefined4 * ClientSpecialEvent_TeleportOut_ctor(undefined4 *this, int entity);
```

**Prologue sketch (`read_memory`):** stack frame / SEH (`LAB_009b0291`), `sub esp` locals, saves ESI; body writes vtables through `this`.

**Return:** `this` always (even on CBID-fail path after `FUN_007a4480`).

---

## 4. Control flow (sealed)

```
// Base + class vtable install
*this = PTR_LAB_00a766f8          // temporary base
this+0x04 = 0                     // byte
*this = PTR_FUN_00a76860          // TeleportOut vtable
this+0x08 = 0                     // cancel/inactive-style byte
this+0x10 = 0                     // gfx / anim root slot
this+0x14 = 0
this+0x24 = entity                // param_1[9]
this+0x28 = 0
this+0x2c = 0
this+0x30 = 0                     // byte
this+0x31 = 0                     // byte

obj = CVOGReaction_GiveItemByCbid(0xadc)
if obj == null:
  FUN_007a4480()                  // allocate/cbid fail stop
else:
  obj->vt+0x08()                  // addref / activate
  FUN_0092c760(); FUN_00512160(); FUN_004bc180(obj)
  this+0x10 = obj->vt+0x1cc()     // presentation child / graphics handle

  // Random yaw → unit quat-ish (sin scale + cos w)
  rng = CVOGReaction_RandomUnitScalar()
  // wrap counter at rng+0xc if > 0xfffff; ++counter
  FUN_0076f5f0() → float3 basis local_4c..local_44
  ang = (uint16)EDX * DAT_00aaaa84
  (x,y,z) = basis * sin(ang); w = cos(ang)   // local_40..local_34; w uses g_flOne init path

  // Entity pose extract (vt+0x19c) → pick +0x84 or nested +0xb0 block
  FUN_004e88e0(pose → local_30..local_28)

  // Drive presentation root
  (*this+0x10)->vt+0 (1)
  (*this+0x10)->vt+0x20()
  child chain vt+0x100()

  FUN_005828b0(1, "obj_f_inc_mov_01_airlift_at.anm", 0)
  FUN_005828b0(2, "obj_f_inc_mov_01_airlift_aut.anm", 0)
  FUN_005828b0(3, "obj_f_inc_mov_01_airlift_at2.anm", 0)
  FUN_005816a0(1, 0)

  // Local player camera hijack
  if entity->(MI+vt+0x210)(0) == DAT_00d1b6d8:
    this+0x0c = *(DAT_00d1b778 + 0x60c)     // save camera cookie
    *(DAT_00d1b778 + 0x60c) = 4
    FUN_0090dd50()
    write dest pose into DAT_00d1b778 + 0xce4..0xcfc  // pos + quat

  FUN_009780c0()                  // start / enqueue TeleportOut event tick path

return this
```

---

## 5. Layout / constants (sealed)

### Event object (`0x34` bytes) — fields touched here

| Offset | Role | Evidence |
|---:|---|---|
| `+0x00` | vtable → `PTR_FUN_00a76860` | dual install over base `PTR_LAB_00a766f8` |
| `+0x04` | byte init 0 | prologue |
| `+0x08` | byte init 0 | cancel/inactive style (family pattern) |
| `+0x0c` | camera cookie save | local branch only |
| `+0x10` | presentation object* | from CBID `0xadc` `vt+0x1cc` |
| `+0x14` | zeroed slot | |
| `+0x24` | entity* | ctor arg |
| `+0x28..+0x2c` | zeroed | |
| `+0x30 / +0x31` | phase/flag bytes 0 | |

### Constants

| Item | Value | Notes |
|---|---|---|
| Alloc size (caller) | **`0x34`** | `Client_RecvSpecialEvent` type 1 |
| CBID | **`0xadc`** (2780) | `CVOGReaction_GiveItemByCbid` |
| `g_flOne` | **1.0f** @ `0x00a0f2a0` | `read_memory` `0000803f` |
| `DAT_00aaaa84` | **≈2.39688e-5** @ `0x00aaaa84` | `a310c937`; ×65536 ≈ **π/2** (uint16→quarter-turn scale) |
| Anim slots 1/2/3 | `obj_f_inc_mov_01_airlift_at.anm` / `_aut.anm` / `_at2.anm` | string globals |
| Camera mode write | **4** → `DAT_00d1b778+0x60c` | local only |
| Event type | **1** | packet `+0x04` |

---

## 6. Callers / callees

| Direction | Symbol | VA / note |
|---|---|---|
| **Caller** | `Client_RecvSpecialEvent` | `0x0080cd8a` only |
| Callee | `CVOGReaction_GiveItemByCbid` | CBID `0xadc` |
| Callee | `FUN_007a4480` | fail / debug stop |
| Callee | `FUN_0092c760` / `FUN_00512160` / `FUN_004bc180` | object bind chain |
| Callee | `CVOGReaction_RandomUnitScalar` | RNG + counter |
| Callee | `FUN_0076f5f0` | basis floats |
| Callee | `FUN_004e88e0` | pose builder |
| Callee | `FUN_005828b0` ×3 | anim bind |
| Callee | `FUN_005816a0(1,0)` | mode 1, blend 0 |
| Callee | `FUN_0090dd50` | local camera |
| Callee | `FUN_009780c0` | event start/helper |

---

## 7. Decompiler hazards

1. **Stack junk temps** (`1.39140…e-38`) — return-address / SEH cookies mis-typed as float; ignore in ports.
2. **`extraout_EDX`** after `FUN_0076f5f0` / RNG path — angle low-16 from EDX; do not invent a separate API return without call-site proof.
3. **MI / vtable chains** (`param_2+4` adjustments, `vt+0x19c` / `+0x210`) — structure correct; product names for intermediate objects remain Tentative.
4. **`CVOGReaction_GiveItemByCbid` name** — symbol as used by decompiler; role is “allocate/lookup presentation by CBID,” not inventory give.
5. **Fail path still returns `this`** — object may be half-initialized if CBID fails after vtable install.

---

## 8. Confidence

| Area | Level |
|---|---|
| Name / role (TeleportOut leave ctor, type 1) | **High** (symbol + packet dispatch) |
| Alloc size `0x34`, sole caller | **High** |
| CBID `0xadc` + three airlift `.anm` strings | **High** |
| Entity at `+0x24`, presentation at `+0x10` | **High** |
| Local camera cookie `+0x0c` / `DAT_00d1b778+0x60c=4` | **High** structure |
| Angle scale float via `read_memory` | **High** value / **Medium** product intent |
| Helper product names (`FUN_009780c0`, anim binder) | **Medium** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps** — ctor contract, layout zeros, CBID/anims, and local-camera branch sealed for a presentation port; helper product names and full anim graph remain partial.
