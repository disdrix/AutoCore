# Review A (reconstruction fidelity): `aa_004fbec0` VehicleEntity_SetDriveAxes

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fbec0` |
| **VA** | `0x004fbec0` |
| **Body span** | `0x004fbec0` – `0x004fbeed` inclusive (**46** bytes; exclusive end `0x004fbeee` → `cc cc`) |
| **Canonical name** | `VehicleEntity_SetDriveAxes` |
| **Review date** | `2026-07-29` (dual residual **strengthen** — live Ghidra decompile + `read_memory`; supersedes thin 2026-07-23 scaffold) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ machine bytes) |
| **Counterpart** | `reviews/B_aa_004fbec0_VehicleEntity_SetDriveAxes.md` |
| **Scratch** | `reviews/a_004fbec0.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present and strengthened** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bulk-write the three drive-axis fields on a vehicle entity, then always push thr/HB into the input controller:

1. `*(f32*)(this+0x614) = thr` (ungated)
2. `*(f32*)(this+0x618) = steer` (ungated)
3. `*(u8*)(this+0x61c) = hb` (ungated)
4. `VehicleEntity_PushDriveAxesToController(this)` — **always**, no local gate

**Does NOT** apply the **0xC7** write-suppress gate used by single-axis `SetLongitudinalInput` / `SetSteerInput`. Always stores all three args as given.

**Machine proof (`read_memory` len 48 @ entry):**

```text
0x004fbec0:  f3 0f 10 44 24 04       movss xmm0, [esp+0x4]     ; thr
0x004fbec6:  8a 44 24 0c             mov   al,   [esp+0xc]     ; hb (u8)
0x004fbeca:  f3 0f 11 81 14 06 00 00 movss [ecx+0x614], xmm0
0x004fbed2:  f3 0f 10 44 24 08       movss xmm0, [esp+0x8]     ; steer
0x004fbed8:  f3 0f 11 81 18 06 00 00 movss [ecx+0x618], xmm0
0x004fbee0:  88 81 1c 06 00 00       mov   [ecx+0x61c], al
0x004fbee6:  e8 25 fd ff ff          call  0x004fbc10          ; PushDriveAxesToController
0x004fbeeb:  c2 0c 00                ret   0xc                  ; 3 stack dwords
0x004fbeee:  cc cc                   int3  padding (not body)
```

Call target check: `0x004fbee6 + 5 + (−0x2db) = 0x004fbc10` (**PushDriveAxesToController**).

**Calling convention:** MSVC `__thiscall` — entity in **ECX**; thr/steer/hb on stack; `ret 0xc`.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_004fbec0_VehicleEntity_SetDriveAxes.md` | Live ≡ frozen body |
| Annotated | `docs/reconstruction/raw/aa_004fbec0_VehicleEntity_SetDriveAxes.annotated.md` | Machine bytes + span + call target |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleEntity_SetDriveAxes.cpp` | Plate: floats, ungated, always-Push |
| Function record | `docs/reconstruction/functions/aa_004fbec0_VehicleEntity_SetDriveAxes.md` | Bytes + sole caller + Push contract |
| Live decompile | Ghidra MCP `0x004fbec0` | **≡ raw** (three stores + Push) |
| Live bytes | `read_memory` len 48 @ entry | **≡ movss/store/call/ret0xc** |
| Live xrefs | `get_function_xrefs` / `get_function_callers` / `get_bulk_xrefs` | **1** site only |
| Call site | `VehicleAction_airStabilization` `0x0059858a` | thr=0, steer=0, **hb=1** |
| Sibling gated | `SetLongitudinalInput` `0x004f5650`, `SetSteerInput` `0x004f5620` | Live decompile — **0xC7** gate |
| Sibling ungated HB | `SetHandbrake` `0x004f3620` | Store-only; no Push |
| Push dual | `aa_004fbc10` (strengthened) | thr/HB only; **no** steer copy |
| System / type | `systems/input-drive-control.md`, `types/VehicleEntity_drive_axes.md` | Cross-read |

**Not performed:** Launcher, runtime golden, bit-exact package diff, exhaustive image scan for other indirect callers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Writes `+0x614` / `+0x618` / `+0x61c` only | **High** | Bytes: three stores; no other mem ops |
| Thr/steer are **f32** (`movss`); HB is **u8** | **High** | Machine encoding |
| **No** `0xC7` suppress gate | **High** | No pointer walk; contrast gated siblings |
| Always calls `PushDriveAxesToController` | **High** | Unconditional `call` before `ret` |
| Call target is `0x004fbc10` | **High** | Rel32 decode + dual sealed |
| Body span 46 B / end `0x004fbeed` | **High** | `read_memory`; next `cc` then next fn |
| `ret 0xc` (3 stack args) | **High** | Bytes |
| Push copies thr `+0x614→ctrl+0x20` and HB `+0x61c→ctrl+0x24` | **High** | Push dual live |
| Push **never** reads/writes steer `+0x618` | **High** | Push dual; applyAction ramps steer |
| Hard-stop `entity+0x109` can force ctrl thr0/HB1 without reading entity HB | **High** | Push early-return (not this body) |
| Only static call site: airStab recovery | **High** (xrefs) | `0x0059858a` only |
| AirStab args = thr **0**, steer **0**, hb **1** (not all-zero) | **High** | Site bytes: `6a 01; 6a 00; 6a 00` |
| Docs saying `SetDriveAxes(0)` clears HB | **Falsified as call-site claim** | Recovery forces **HB=1** |
| Used as general AI/path bulk setter beyond airStab | **Open / Tentative** | No other static xrefs found |
| Runtime / package bit-exact | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| thr → `+0x614` (movss) | **Yes** |
| steer → `+0x618` (movss) | **Yes** |
| hb → `+0x61c` (byte) | **Yes** |
| unconditional Push | **Yes** |
| no invent 0xC7 gate | **Yes** |
| no invent clamp / multi-path | **Yes** |
| no invent steer-in-Push | **Yes** (Push dual) |
| `ret 0xc` | **Yes** |

### 4.1 Contrast: gated singles vs bulk

| API | Offset | Gate | Push? |
|---|---|---|---|
| `SetLongitudinalInput` `0x004f5650` | `+0x614` | skip if `(flags&0xC7)!=0` | **No** |
| `SetSteerInput` `0x004f5620` | `+0x618` | same 0xC7 | **No** |
| `SetHandbrake` `0x004f3620` | `+0x61c` | **ungated** | **No** |
| **`SetDriveAxes` `0x004fbec0`** | all three | **ungated** | **Always** |

Port note: bulk path can force thr/steer even when single setters would suppress under 0xC7. HB is ungated either way.

### 4.2 Sole sealed caller (air-stab recovery)

`VehicleAction_airStabilization` @ `0x00598320`, site `0x0059858a` (post-collision recovery after zero lin/ang vel):

```text
mov  ecx, [esi+0x44]   ; entity = VA+0x44
push 1                 ; handbrake
push 0                 ; steer
push 0                 ; thr
call VehicleEntity_SetDriveAxes
```

→ stores thr=0, steer=0, hb=1, then Push (so controller thr cleared and HB engaged on normal Push path, subject to Push gates).

---

## 5. Gaps / open

1. Runtime / live differential under recovery vs input tick (matrix policy).
2. Whether any **indirect** / computed call targets reach this VA (static xrefs show 1 only).
3. Product English names for any future non-airStab callers if discovered.
4. Package-level bit-exact beyond sealed 46-byte body.
5. Interaction documentation elsewhere still says “SetDriveAxes(0) clears all three” — call site sealed as **(0,0,1)**; external airStab docs are out of OWN scope for rewrite this pass.

**Verdict:** **accept-with-gaps** — dual residual **machine body + ungated three-field store + always-Push + sole caller args + Push thr/HB-not-steer** sealed; package **not complete** (runtime / image-wide indirect calls / out-of-scope airStab plate wording).
