# Function record: Client_ApplyPairRelativeTransform

| Field | Value |
|---|---|
| **Stable ID** | `aa_00439a80` |
| **Canonical name** | `Client_ApplyPairRelativeTransform` |
| **Ghidra name** | `FUN_00439a80` |
| **Address** | `0x00439a80` |
| **Body range** | `0x00439a80`–`0x00439da3` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client gfx / special-event pair attach |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + EDI ABI + eps sealed; product English / sibling names open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00439a80_Client_ApplyPairRelativeTransform.md`, `reviews/B_aa_00439a80_Client_ApplyPairRelativeTransform.md` |
| **Last reviewed** | `2026-07-29` (W19-S) |

## Alias

- `FUN_00439a80` (Ghidra)
- `Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_00439a80` (auto parent-seed — **incomplete sole role**)

## Purpose

Apply a **relative transform bind** between a pair of client objects held in an **EDI 4-pointer context** (objA, optional helperA, objB, optional helperB). Pulls transforms via vtbl, builds / inverts a quaternion when `|q|^2` is not near zero, projects a point via `Math_Mat4TransformPoint3_Project`, writes results onto objB (mode `3` slots).

## Signature

```c
// Custom register ABI: EDI = PairXformCtx*; bare ret
void Client_ApplyPairRelativeTransform(void);
```

## Algorithm

1. Load optB=`[EDI+0xc]`, optA=`[EDI+4]`.
2. Ensure gfx work buffer (`FUN_00972cc0`).
3. Source side A: `objA->vtbl+8` with helper id or `-1`; optional copy from helper `+0x20`/`+0x10`.
4. Seed identity quat/pos on stack; `objB` vtbl `+0x14`/`+0x18`/`+0x34`.
5. Side B optional helper same pattern into second buffer.
6. `|q|^2`; if ≥ `1e-6` (or ≤ `-1e-6` dual gate): inverse-conjugate `(-x,-y,-z,w)/|q|^2`.
7. Rebuild + `Math_Mat4TransformPoint3_Project`; compose; `objB->vtbl+0x10(3,…)` twice + commit `+0x34`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00439a80_FUN_00439a80.md`
- Annotated: `docs/reconstruction/raw/aa_00439a80_FUN_00439a80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_ApplyPairRelativeTransform.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00439a80.cpp`
- Parent-seed plate: `reconstructed-exact/Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_00439a80.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00439a80-007b6e8d-w19s-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00972cc0`, `FUN_0040cf90`, `FUN_0040d1a0`, `FUN_00973030`, `FUN_00972e50`, `FUN_0076f6e0` |
| **Callers (8)** | `ClientSpecialEvent_TeleportIn_ctor`, `ClientSpecialEvent_Respawn_Update`, `FUN_0096dc80`, `FUN_0096dc50`, `FUN_00855ff0`, `FUN_009784f0`, `FUN_00764180`, `0x007644ba` |

## Confidence

| Claim | Level |
|---|---|
| EDI 4-slot pack layout from prologue | **High** |
| Bare ret, no stack-arg cleanup | **High** |
| Quaternion inverse-conjugate when \|q\|² not near 0 | **High** |
| eps constants 1e-6 / -1e-6 | **High** |
| Multi-caller (not TeleportIn-only) | **High** |
| Product English / vtbl slot names | Open / Inferred |
| Sibling callee product names | Open |

## Related

- `aa_0076f6e0` Math_Mat4TransformPoint3_Project
- `aa_0076f240` Math_Mat4MulVec4_AffineFast
- Client special-event TeleportIn / Respawn
