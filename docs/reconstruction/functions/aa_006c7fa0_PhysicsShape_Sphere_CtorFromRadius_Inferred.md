# Function record: PhysicsShape_Sphere_CtorFromRadius_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c7fa0` |
| **Canonical name** | `PhysicsShape_Sphere_CtorFromRadius_Inferred` (**Inferred** — product demangle open) |
| **Ghidra name** | `FUN_006c7fa0` |
| **Prior scaffold** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_006c7fa0` (**retired**) |
| **Address** | `0x006c7fa0`–`0x006c7fbc` inclusive end of RET (**29 B** / `0x1D`); pad `CC` @ `0x006c7fbd` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation / physics sphere shape setup |
| **Agent** | MEGA-071 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Leaf **thiscall** constructor for a **sphere shape** object of size **0x10**:

```text
refcount@+0x06 = 1
field@+0x08    = 0
radius@+0x0c   = stack float
*this          = PTR_FUN_00a0d610
RET 4; EAX = this
```

Used by dualed `CVOGPhysicsUtils_GetObjectsInArea` **mode-2** (sphere broadphase) and 16 other physics/query setup callers. Allocators request `(0x10, 0x22)` and pre-tag `word[+4]=0x10`.

Sphere role sealed by vtbl methods (evidence only; not OWN dualled):

| Vtbl idx | VA | Role |
|---|---|---|
| 0 | `006c6490` | dtor/release |
| 6 | `006c7f20` | AABB expand by radius@+0xc |
| 7 | `006c7c30` | support / max projection + radius |
| 8 | `006c7fc0` | ray-sphere (r² @ +0xc) |

## Signature

```c
// __thiscall: ECX = this; stack float radius; RET 4; EAX = this
PhysicsShape_Sphere_Inferred *__thiscall
PhysicsShape_Sphere_CtorFromRadius_Inferred(
    PhysicsShape_Sphere_Inferred *self,
    float radius);
```

## Layout (object size 0x10)

| Offset | Field |
|---|---|
| +0x00 | vtbl → `0x00a0d610` |
| +0x04 | u16 size tag (parent writes `0x10`) |
| +0x06 | u16 refcount (=1) |
| +0x08 | u32 field (=0) |
| +0x0c | float radius |

## Call graph

| Role | Target |
|---|---|
| **Callers (17 / 18 sites)** | `FUN_004ea350` GetObjectsInArea mode-2 @ `004ea6ce`; `FUN_004e9720` @ `004e976e`; `FUN_004e9aa0` @ `004ea07d`; `FUN_004ed470` @ `004edfb6`; `FUN_004ee080` @ `004ee322`/`004ee93d`; `FUN_005dd080`; `FUN_005f1ec0`; `FUN_005f3e10` @ `005f3e5d`; `FUN_006ca1d0`; `FUN_006ec530`/`690`/`7f0`/`970`/`ad0`/`c50`/`db0`/`d0d0` cluster |
| Callees | **none** (leaf) |
| Parent product | dualed `CVOGPhysicsUtils_GetObjectsInArea` `0x004ea350` |
| Peer modes | mode-1 box-ish (`FUN_00581220`); default AABB string path |

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/PhysicsShape_Sphere_CtorFromRadius_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_006c7fa0.cpp`
- Retired: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_006c7fa0.cpp`
- Raw: `docs/reconstruction/raw/aa_006c7fa0_FUN_006c7fa0.md`
- Annotated: `docs/reconstruction/raw/aa_006c7fa0_FUN_006c7fa0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred.md`
- Report: `docs/agents/task-dual-ab-006c7fa0-mega-071-report.md`

## Confidence

| Claim | Level |
|---|---|
| Leaf ctor CF / stores | **Confirmed** |
| thiscall + RET 4; EAX=this | **Confirmed** |
| radius float @+0x0c | **Confirmed** |
| Sphere via vtbl methods | **Confirmed** |
| Caller set (18) | **Confirmed** |
| Product class English | **Inferred** / open |
| field@+0x08 English | **Tentative** |
