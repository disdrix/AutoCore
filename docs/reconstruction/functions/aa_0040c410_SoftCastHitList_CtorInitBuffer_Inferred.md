# Function record: SoftCastHitList_CtorInitBuffer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c410` |
| **Canonical name** | `SoftCastHitList_CtorInitBuffer_Inferred` |
| **Ghidra name** | `FUN_0040c410` |
| **Address** | `0x0040c410`–`0x0040c4df` inclusive (**208 B** / `0xD0`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | MEGA-111 (parent dual `0x00925820` Client_InteractWorldClickHub) |
| **Completion status** | **Dual A/B sealed 2026-08-05 (MEGA-111)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; terminal false) |

## Alias

- Ghidra / scaffold: `FUN_0040c410`
- No `Named_CalleeOf_*` scaffold present for this VA

## Purpose

**Ctor / buffer init** for the soft-cast hit-list used by world-click interaction. Installs final vtbl `PTR_LAB_00a2f538`, zeros count, points array begin at inline `this+0x20`, marks capacity 8 with inline high-bit (`0x80000008`), and seeds eight `0x30`-byte hit slots (float key `1.0f` @ `+0x14`, null object @ `+0x20`).

## Signature

```c
void __stdcall SoftCastHitList_CtorInitBuffer_Inferred(SoftCastHitList *self);
// self on stack; void; RET 4
// +0x10 array_base; +0x14 count; +0x18 capacity_word; +0x20 inline[8]
```

## Call chain (evidence only; siblings dualed separately)

```text
Client_InteractWorldClickHub  (0x00925820)  [dualed W17-C]
  ├─ FUN_0040c410  SoftCastHitList_CtorInitBuffer_Inferred  [OWN MEGA-111]
  ├─ FUN_0055e1e0  soft-cast fill wrapper
  │    └─ FUN_006ca890  soft-cast hit-list core
  ├─ FUN_0048a060  SoftCastHitList_SortIfCountGt1_Inferred  [MEGA-116]
  │    └─ FUN_00489f20  qsort 0x30 / key float+0x14  [MEGA-115]
  ├─ walk hits → FUN_0040afb0 resolve object*
  └─ FUN_0040c510  SoftCastHitList dtor
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040c410_FUN_0040c410.md` |
| Annotated | `docs/reconstruction/raw/aa_0040c410_FUN_0040c410.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_CtorInitBuffer_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040c410.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0040c410_SoftCastHitList_CtorInitBuffer_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0040c410_SoftCastHitList_CtorInitBuffer_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_0040c410_FUN_0040c410.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / single caller / leaf | **Confirmed** |
| Soft-cast hit-list structural role | **High** |
| Product class / field English | **Inferred** |
| Runtime | **Open** |
