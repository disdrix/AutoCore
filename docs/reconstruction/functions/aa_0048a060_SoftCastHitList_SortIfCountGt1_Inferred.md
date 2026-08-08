# Function record: SoftCastHitList_SortIfCountGt1_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048a060` |
| **Canonical name** | `SoftCastHitList_SortIfCountGt1_Inferred` |
| **Ghidra name** | `FUN_0048a060` |
| **Address** | `0x0048a060`–`0x0048a082` inclusive (**35 B** / `0x23`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | MEGA-116 (parent dual `0x00925820` Client_InteractWorldClickHub) |
| **Completion status** | **Dual A/B sealed 2026-08-05 (MEGA-116)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; terminal false) |

## Alias

- Ghidra / scaffold: `FUN_0048a060`
- No `Named_CalleeOf_*` scaffold present for this VA

## Purpose

When a soft-cast hit list has **more than one** hit, sort the array so subsequent interact-hub walk prefers ordered hits (float key @ elem+0x14, stride 0x30, implemented in callee `FUN_00489f20`). No-op for empty or singleton lists.

## Signature

```c
void __thiscall SoftCastHitList_SortIfCountGt1_Inferred(SoftCastHitList *this);
// this+0x10 = array base; this+0x14 = count
// RET bare (C3)
```

## Call chain (evidence only; callees not dualed here)

```text
Client_InteractWorldClickHub  (0x00925820)  [dualed W17-C]
  ├─ FUN_0040c410            init/clear hit container
  ├─ FUN_0055e1e0            soft-cast fill wrapper
  │    └─ FUN_006ca890       soft-cast hit-list core (MEGA residual)
  ├─ FUN_0048a060            SoftCastHitList_SortIfCountGt1_Inferred  [OWN MEGA-116]
  │    └─ FUN_00489f20       qsort 0x30 / key float+0x14  [MEGA-115 OWN]
  └─ walk hits → FUN_0040afb0 resolve object*  [MEGA-028 residual]
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0048a060_FUN_0048a060.md` |
| Annotated | `docs/reconstruction/raw/aa_0048a060_FUN_0048a060.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_SortIfCountGt1_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048a060.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0048a060_SoftCastHitList_SortIfCountGt1_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0048a060_SoftCastHitList_SortIfCountGt1_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_0048a060_FUN_0048a060.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / single caller | **Confirmed** |
| Soft-cast hit-list structural role | **High** |
| Product class / key English | **Inferred** |
| Runtime | **Open** |
