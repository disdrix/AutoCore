# Function record: SoftCastHitList_CoreFillAndRegister_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ca890` |
| **Canonical name** | `SoftCastHitList_CoreFillAndRegister_Inferred` |
| **Ghidra name** | `FUN_006ca890` |
| **Address** | `0x006ca890`–`0x006ca93b` inclusive (**172 B** / `0xAC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Partition** | MEGA-062 (parent dual `0x00925820` Client_InteractWorldClickHub) |
| **Completion status** | **Dual A/B sealed 2026-08-05 (MEGA-062)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; terminal false) |

## Alias

- Ghidra / scaffold: `FUN_006ca890`
- No `Named_CalleeOf_*` scaffold for this VA

## Purpose

Initialize one soft-cast **hit-entry** from a soft-cast descriptor (header + flag@+0x20 + field@+0x24) and an optional related object, then **register** it through the manager interface at **vtbl+0x30** with a packed query packet (`flag=1`, `size=0x10`, payload dword).

Sole retail path:

```text
Client_InteractWorldClickHub  (0x00925820)  [dualed W17-C]
  ├─ FUN_0040c410            init/clear hit container
  ├─ FUN_0055e1e0            soft-cast fill wrapper (local entry + vtbl 0x009d27a8)
  │    └─ FUN_006ca890       SoftCastHitList_CoreFillAndRegister_Inferred  [OWN MEGA-062]
  ├─ FUN_0048a060            SoftCastHitList_SortIfCountGt1_Inferred  [dualed MEGA-116]
  │    └─ FUN_00489f20       qsort 0x30 / key float+0x14
  └─ walk hits → FUN_0040afb0 resolve object*  [MEGA-028 residual]
```

## Signature

```c
void __thiscall SoftCastHitList_CoreFillAndRegister_Inferred(
    SoftCastHitEntry *this,   // ECX
    void *manager,            // stack0 — vtbl+0x30
    uint32_t *soft_desc,      // stack1
    int related_obj_or_null,  // stack2
    uint32_t query_payload,   // stack3 (wrapper: always 0)
    uint32_t hit_list_backref // stack4
);
// RET 0x14
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006ca890_FUN_006ca890.md` |
| Annotated | `docs/reconstruction/raw/aa_006ca890_FUN_006ca890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_CoreFillAndRegister_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006ca890.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_006ca890_SoftCastHitList_CoreFillAndRegister_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_006ca890_SoftCastHitList_CoreFillAndRegister_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_006ca890_FUN_006ca890.md` |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / single caller | **Confirmed** |
| Soft-cast hit-list structural role | **High** |
| Product class / vcall English | **Inferred** |
| Runtime | **Open** |
