# Function record: VOGPhysics_QueryCollect_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb790` |
| **Canonical name** | `VOGPhysics_QueryCollect_Ctor_Inferred` |
| **Ghidra name** | `FUN_005eb790` |
| **Address** | `0x005eb790`–`0x005eb7c0` inclusive (**49 B** / `0x31`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | R12-037 OWN-ONLY (parent dual `0x005eb210`) |
| **Completion status** | **Dual sealed** (A/B **accept**) |
| **Bit-for-bit / runtime / diff** | Open — terminal **false** |

## Purpose

Derived constructor for the **0xD0-byte physics query-collect** object:

```text
BaseQueryCtor(self, params)     // FUN_005eb210
self.vtbl = PTR_FUN_009dce20
self.collectBegin (+0xC0) = 0
self.collectCount (+0xC4) = 0
self.collectCap   (+0xC8) = 0x80000000
return self
```

Sibling of dualed `VOGPhysics_SphereQueryCollect_Ctor_Inferred` (`0x005ebec0`, vtbl `009dce90`) — same control-flow pattern, different derived vtbl. Used by placement/probe helpers (`FUN_004e9720`, `FUN_004e9aa0`), not by `GetObjectsInArea` sphere mode.

## Signature

```c
uint32_t * __thiscall VOGPhysics_QueryCollect_Ctor_Inferred(
    uint32_t *self /* ECX */,
    uint32_t params /* stack */);
```

| ABI | Evidence |
|---|---|
| ECX = self | `MOV ESI,ECX`; call sites load ECX from allocator return |
| Stack `params*` | `MOV EAX,[ESP+4]` / `PUSH EAX` before base call |
| RET 4 | `C2 04 00` @ `0x005eb7be` |
| EAX = self | `MOV EAX,ESI` |

## Layout writes

| Off | Value | Role |
|----:|-------|------|
| `+0x00` | `PTR_FUN_009dce20` | derived vtbl |
| `+0xC0` | `0` | collect begin |
| `+0xC4` | `0` | collect count |
| `+0xC8` | `0x80000000` | empty capacity sentinel |

## Callees

| VA | Role |
|---|---|
| `0x005eb210` `VOGPhysics_QueryObject_BaseCtor_Inferred` | base query-object ctor (dualed R11-008) |

## Callers (4 UNCONDITIONAL_CALL xrefs)

| Site | Enclosing | Notes |
|---|---|---|
| `0x004e97fb` | `FUN_004e9720` | after sphere-shape `006c7fa0`; alloc 0xD0/tag 0x2C |
| `0x004e9f93` | `FUN_004e9aa0` | placement/probe construct |
| `0x004ea0f2` | `FUN_004e9aa0` | second construct site |
| `0x005eb8bf` | factory near dtor cluster | alloc 0xD0/tag 0x2C then construct |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ R12-037 re-verify) | `docs/reconstruction/raw/aa_005eb790_FUN_005eb790.md` |
| Annotated | `docs/reconstruction/raw/aa_005eb790_FUN_005eb790.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGPhysics_QueryCollect_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005eb790.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_005eb790_VOGPhysics_QueryCollect_Ctor_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_005eb790_VOGPhysics_QueryCollect_Ctor_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_005eb790_FUN_005eb790.md` |
| Report | `docs/agents/task-dual-ab-005eb790-r12-report.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 4 / return this | **High** |
| Collect triad `+0xC0` init | **High** |
| Query-collect derived ctor role | **High** |
| Distinct from sphere collect / base / shape | **High** |
| Product class English | **Open** → `_Inferred` |
| Runtime Confirmed | **Open** |

## Retired scaffolds

- `Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature_005eb790` — do not use as identity.
