# Review A (reconstruction fidelity): `aa_0055e530` MapCollisionCtx_CastRay

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055e530` |
| **VA** | `0x0055e530` |
| **Canonical name** | `MapCollisionCtx_CastRay` (structural; map collision cast wrapper) |
| **Ghidra name** | `FUN_0055e530` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0055e530_MapCollisionCtx_CastRay.md` |
| **System** | world / terrain collision (via `CVOGMap_CastTerrainHeight`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **`__thiscall`** wrapper: collision **context** → stack cast-collector object → `FUN_006cad80` world cast (vtbl **+0x30**).

```
void __thiscall MapCollisionCtx_CastRay(Ctx* this, Ray* ray, Result* result);
// RET 8  (two stack args)
```

Body (bytes):

1. Load `world = *(this + 0xC4)`, `filterOrShape = *(this + 0xD0)`.
2. Build **stack object** with vtable **`0x009D27D4`**.
3. `FUN_006cad80(stackObj /*ECX*/, world, ray, filterOrShape, 0, result)`:
   - Stores ray @ collector+4, result @ +0xC, optional shape offset @ +8/+0x34.
   - Invokes `(**(world->vtbl + 0x30))(rayPacket, collector, 0)`.

Used by **`CVOGMap_CastTerrainHeight`** (`0x004CFE60`) with `this = *(map + 0xE4A4)` after packing a vertical ray. Also two other client paths (`FUN_00916090`, `FUN_00925820`).

**Not** vehicle wheel phantom cast (`TtPhantom::castRay` / `0x00580ed0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_0055e530_*` |
| Fresh decompile | Ghidra @ `0x0055e530` + `0x006cad80` |
| Bytes | ends **`C2 08 00`** (`ret 8`); vtable imm `0x009D27D4`; fields `+0xC4`, `+0xD0` |
| Verified parent | `docs/reconstruction/physics/verified/fn_004cfe60_castTerrain.md` |
| Callers | `CVOGMap_CastTerrainHeight`, `FUN_00916090`, `FUN_00925820` (3 xrefs) |

### Context offsets

| Offset | Role |
|---|---|
| `ctx + 0xC4` | World / broadphase object with cast vtbl |
| `ctx + 0xD0` | Filter / shape-related pointer into `6cad80` |

Parent map: `ctx = *(CVOGMap* + 0xE4A4)`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`ret 8`** | **Confirmed** | `C2 08 00` |
| Args = `(ray*, result*)` | **Confirmed** | parent verified + stack `[ebp+8]/[ebp+0xc]` |
| Forwards via `FUN_006cad80` + vtbl+0x30 | **Confirmed** | callee body |
| Stack collector vtbl `0x009D27D4` | **Confirmed** | immediate in bytes |
| Map terrain height path uses this | **Confirmed** | `CastTerrainHeight` @ `0x004cff11` |
| Not wheel Havok cast | **High** | different VA / verified contrast |
| Product name / collector type English | **Open** | structural |
| Full ray/result POD layout | **High** from parent; not owned solely here | parent dual |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Read +0xC4 / +0xD0 | Yes |
| Stack object + vtbl | Yes (bytes; decompiler simplified) |
| Call `6cad80` | Yes |
| `ret 8` | Yes |

### Recovered CF

```c
// void __thiscall MapCollisionCtx_CastRay(Ctx* this, void* ray, void* result)
// RET 8
Collector local; local.vtbl = 0x009D27D4;
FUN_006cad80(&local, *(this+0xC4), ray, *(this+0xD0), /*param_shape*/0, result);
```

Decompiler plate collapses stack collector into a direct call shape — **bytes are authority** for the collector thiscall.

---

## 5. Callers

| Caller | Role |
|---|---|
| `CVOGMap_CastTerrainHeight` | Vertical terrain height cast |
| `FUN_00916090` | Client collision helper |
| `FUN_00925820` | Client collision helper |

---

## 6. Gaps

1. Product names for Ctx / Collector / world cast vfunc.
2. Full ray and hit-result field map (partially in parent verified doc).
3. Dual of `FUN_006cad80` internals beyond sealed vtbl+0x30 dispatch.
4. Runtime hit capture.

**Verdict:** wrapper CF + ABI + offsets sealed. **accept-with-gaps.**
