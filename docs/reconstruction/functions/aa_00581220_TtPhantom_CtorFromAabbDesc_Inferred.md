# Function record: TtPhantom_CtorFromAabbDesc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00581220` |
| **Canonical name** | `TtPhantom_CtorFromAabbDesc_Inferred` |
| **Ghidra name** | `FUN_00581220` |
| **Address** | `0x00581220`–`0x005812c6` (**167 B** / `0xA7`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation / physics (TtPhantom) |
| **Vtbl** | `PTR_FUN_009d45b0` |
| **Sibling dtor** | `FUN_005812d0` (same vtbl; frees overlap @ +0x80) |
| **ABI** | `__thiscall`; ECX=this; stack `AabbDesc*`; **EAX=this**; **`RET 4`** |
| **Dual** | MEGA-037 2026-08-05 — **accept-with-gaps** (A + B) |
| **Terminal / runtime Confirmed** | **false** / not claimed |

## Purpose

Retail **TtPhantom** constructor from an AABB box descriptor:

1. Refcount `+0x06 = 1`; type tag `+0x24 = 2`; self-link `+0x2c = this`.
2. Empty-vector capacity sentinels `0x80000000` at `+0x38`, `+0x44`, `+0x50`, `+0x88`.
3. Install vtbl `009d45b0`.
4. Zero overlap list `+0x80/+0x84` (walked by dualed **`TtPhantom_castRay`**).
5. Copy 8 dwords AABB from `src+0x20` → `this+0x60`; lead `*src` → `this+0x28`.

Parents allocate **0x90**, stamp size tag at `this+4`, construct, then typically **`FUN_0055ff20`** (world register) and iterate hits.

## Consumers

| Caller | Role |
|---|---|
| `CVOGPhysicsUtils_GetObjectsInArea` mode-1 | box/list broadphase path (partition hint) |
| `hkVehicleFramework_preUpdate` | vehicle phantom @ `+0x38` for wheel castRay |
| `FUN_004ca9f0` | creature phantom @ `+0x254` for terrain height |
| `FUN_005dd080` / `FUN_00932060` / factory ~`0x0058e080` | same alloc+ctor pattern |

## Not this function

| VA / name | Why different |
|---|---|
| `CVOGPhysicsUtils_GetObjectsInArea` `0x004ea350` | multi-mode **manager**; this is mode-1 leaf ctor |
| `TtPhantom_castRay` `0x00580ed0` | overlap list **raycast**; sibling method |
| Mode-2 ctors `FUN_006c7fa0` / `FUN_005ebec0` | size `0xd0` sphere-ish path |
| `FUN_0055ff20` | world **register** of already-built phantom |

## Port notes

- Port as **field-init ctor only** — no query loop here.
- Preserve **thiscall RET 4** and **EAX=this**.
- Pair with dtor `005812d0`, register `0055ff20`, castRay `00580ed0`, parent mode-1 `004ea350`.
- Keep class name **TtPhantom** (plate-sealed family); keep **`_Inferred`** on this method until ctor plate/RTTI appears.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00581220_FUN_00581220.md` |
| Annotated | `docs/reconstruction/raw/aa_00581220_FUN_00581220.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TtPhantom_CtorFromAabbDesc_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00581220.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00581220_TtPhantom_CtorFromAabbDesc_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00581220_TtPhantom_CtorFromAabbDesc_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00581220_FUN_00581220.md` |
| Report | `docs/agents/task-dual-ab-00581220-mega-037-report.md` |
