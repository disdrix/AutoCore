# Function record: VOGPhysics_SphereQueryCollect_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ebec0` |
| **Canonical name** | `VOGPhysics_SphereQueryCollect_Ctor_Inferred` |
| **Ghidra name** | `FUN_005ebec0` |
| **Address** | `0x005ebec0`–`0x005ebef0` inclusive (**49 B** / `0x31`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | MEGA-070 OWN-ONLY (parent dual context `0x004ea350` CVOGPhysicsUtils::GetObjectsInArea) |
| **Completion status** | **Dual sealed** (A/B **accept**) |
| **Bit-for-bit / runtime / diff** | Open — terminal **false** |

## Purpose

Derived constructor for the **0xD0-byte physics sphere-query collect** object:

```text
BaseQueryCtor(self, params)     // FUN_005eb210
self.vtbl = PTR_FUN_009dce90
self.collectBegin (+0xC0) = 0
self.collectCount (+0xC4) = 0
self.collectCap   (+0xC8) = 0x80000000
return self
```

Used on **sphere** branches of area queries (GetObjectsInArea `param_5==2` and peer). Not the sphere shape, not the collect loop.

## Signature

```c
uint32_t * __thiscall VOGPhysics_SphereQueryCollect_Ctor_Inferred(
    uint32_t *self /* ECX */,
    uint32_t params /* stack */);
```

| ABI | Evidence |
|---|---|
| ECX = self | `MOV ESI,ECX`; call sites load ECX from allocator return |
| Stack `params*` | `MOV EAX,[ESP+4]` / `PUSH EAX` before base call |
| RET 4 | `C2 04 00` @ `0x005ebeee` |
| EAX = self | `MOV EAX,ESI` |

## Layout writes

| Off | Value | Role |
|----:|-------|------|
| `+0x00` | `PTR_FUN_009dce90` | derived vtbl |
| `+0xC0` | `0` | collect begin |
| `+0xC4` | `0` | collect count |
| `+0xC8` | `0x80000000` | empty capacity sentinel |

## Callees

| VA | Role |
|---|---|
| `0x005eb210` `FUN_005eb210` | base query-object ctor (not dualled here) |

## Callers (3 UNCONDITIONAL_CALL xrefs)

| Site | Enclosing | Notes |
|---|---|---|
| `0x004ea770` | `FUN_004ea350` | GetObjectsInArea sphere mode (`param_5==2`) |
| `0x005dd368` | `FUN_005dd080` | sphere branch; store at `obj+0xD0` |
| `0x005ebfcf` | factory near dtor cluster | alloc 0xD0/tag 0x2C then construct |

## Strings / parent evidence

| VA | Content / role |
|---|---|
| `0x009ccbe8` | `CVOGPhysicsUtils::GetObjectsInArea::aabb` (parent family) |
| `0x009ccf60` | `sphere` (nearby physics-utils string table) |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ MEGA-070 re-verify) | `docs/reconstruction/raw/aa_005ebec0_FUN_005ebec0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ebec0_FUN_005ebec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_SphereQueryCollect_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005ebec0.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_005ebec0_VOGPhysics_SphereQueryCollect_Ctor_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005ebec0_VOGPhysics_SphereQueryCollect_Ctor_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_005ebec0_FUN_005ebec0.md` |
| Report | `docs/agents/task-dual-ab-005ebec0-mega-070-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 4 / return this | **High** |
| Collect triad `+0xC0` init | **High** |
| Sphere-query collect ctor role | **High** |
| Product class English | **Open** → `_Inferred` |
| Runtime Confirmed | **Open** |

## Retired scaffolds

- `Named_CalleeOf_Named_VOG_DEBUG_STOP_005ebec0` — do not use as identity.
