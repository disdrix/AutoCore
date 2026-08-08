# Function record: CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c6c50` |
| **Canonical name** | `CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred` (**Inferred** — product English for this-object / high-16 gate / bit meanings open) |
| **Ghidra name** | `FUN_006c6c50` |
| **Prior scaffold** | `FUN_006c6c50` / `Named_CalleeOf_Named_VOG_DEBUG_STOP_006c6c50` (**retired**) |
| **Address** | `0x006c6c50`–`0x006c6c98` inclusive (**73 B** / `0x49`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation / CVOGPhysicsUtils area-query filter gate |
| **Agent** | MEGA-039 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Classic **filter bit-matrix probe** used by dualed `CVOGPhysicsUtils_GetObjectsInArea` (`0x004ea350`) on every default-AABB broadphase hit. Rejects hits whose type/category fails the query filter flags before object resolve / list append.

```text
if same non-zero high-16(object_type, filter_flags):
  *out = 0
else:
  *out = (this->bit_rows[object_type & 31] & (1 << (filter_flags & 31))) != 0
```

## Signature

```c
// __thiscall: ECX = filter bit-matrix; stack out*, object_type, filter_flags;
// RET 0xC; result in *out (EAX left as out*)
void __thiscall CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred(
    AreaQueryFilterBitMatrix_Inferred *this,
    uint8_t *out,
    uint32_t object_type,
    uint32_t filter_flags);
```

## Layout (this — minimum sealed)

| Offset | Field |
|---|---|
| +0x00..+0x18 | unknown (not touched here) |
| +0x1C | `uint32_t bit_rows[32]` — row = `object_type & 0x1F`; bit = `filter_flags & 0x1F` |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | dualed `CVOGPhysicsUtils_GetObjectsInArea` `0x004ea350` @ `0x004ea560` |
| Callees | **none** (leaf) |
| Parent modes (context only) | mode 1 / mode 2 paths of GetObjectsInArea do **not** call this leaf (AABB default only) |
| Consumer flags (parent dual) | gather `1` / `0x11` / `0x0a` |

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_006c6c50.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_006c6c50.cpp`
- Raw: `docs/reconstruction/raw/aa_006c6c50_FUN_006c6c50.md`
- Annotated: `docs/reconstruction/raw/aa_006c6c50_FUN_006c6c50.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_006c6c50_CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_006c6c50_CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred.md`
- Report: `docs/agents/task-dual-ab-006c6c50-mega-039-report.md`

## Confidence

| Claim | Level |
|---|---|
| Filter bit-test CF | **Confirmed** |
| thiscall + RET 0xC; out-param result | **Confirmed** |
| Matrix @ +0x1c; indices & 0x1f | **Confirmed** |
| Sole caller GetObjectsInArea AABB loop | **Confirmed** |
| Product this-object / bit English | **Inferred** / open |
| High-16 early-out product rule | **Inferred** / open (CF sealed as reject) |
