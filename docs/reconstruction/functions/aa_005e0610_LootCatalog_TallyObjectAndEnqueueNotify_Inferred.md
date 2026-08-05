# Function record: LootCatalog_TallyObjectAndEnqueueNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0610` |
| **Canonical name** | `LootCatalog_TallyObjectAndEnqueueNotify_Inferred` |
| **Ghidra name** | `FUN_005e0610` |
| **Address** | `0x005e0610`–`0x005e07c5` exclusive (**437 B** / `0x1B5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | loot catalog / CloneBase load |
| **Completion status** | **Dual-reviewed** (W37-AA) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |
| **Terminal coverage** | false |

## Alias

- Ghidra: `FUN_005e0610`
- **Reject** scaffold `Named_CalleeOf_Mission_after_CVOGRegionMissions_005e0610`
- Role inferred from sealed callees `LootCatalog_TypeCodeToRowIndex_Inferred`, `StdMap_InsertOrFindByIntKey_Val12`, `CVOGReaction_FailMissionNotify` + sole caller CloneBase load `FUN_00541e70`

## Purpose

During CloneBase object load: remap type (including clonebase kind overrides), optionally insert a Val12 map entry for type `0xC`, map type→row, bump four manager counter banks (vfunc-bucket / band / row / race), and when `notifyPath∈{0,1}` push the object id onto a path-selected reaction vector.

## Signature (sealed)

```c
// __thiscall; RET 0x0C
void __thiscall LootCatalog_TallyObjectAndEnqueueNotify_Inferred(
    LootCatalogManagerOpaque* mgr, /* ECX */
    GameObjectOpaque* obj,
    int bandIndex,
    int notifyPath);
```

## Artifacts

- Raw (+ W37-AA append): `docs/reconstruction/raw/aa_005e0610_FUN_005e0610.md`
- Annotated: `docs/reconstruction/raw/aa_005e0610_FUN_005e0610.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LootCatalog_TallyObjectAndEnqueueNotify_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005e0610.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005e0610_FUN_005e0610.md`
- Dual A: `docs/reconstruction/reviews/A_aa_005e0610_LootCatalog_TallyObjectAndEnqueueNotify_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005e0610_LootCatalog_TallyObjectAndEnqueueNotify_Inferred.md`

## Callers / callees

| Dir | Symbol | Role |
|---|---|---|
| Caller | `FUN_00541e70` @ `00542341`, `0054236d`, `0054239c` | CloneBase load (3 sites) |
| Callee | vfunc `+0x14` on clonebase | category return |
| Callee | `FUN_004f1e20` | null clonebase ensure |
| Callee | `FUN_00418b80` | type-0xC key path |
| Callee | `FUN_005e18d0` / Val12 insert-or-find | W30-L |
| Callee | `FUN_005e0480` / type→row | W16-C |
| Callee | `CVOGReaction_FailMissionNotify` | dword vector push |

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall + RET 0x0C + 3 stack args | **High** |
| Type remap 0xA/0xB → 0x44/0x46 | **High** |
| Gate `(v==-1 && type==0xE)` skip | **High** |
| Vfunc bucket map 0/1/2/else→3 | **High** (bytes; decompile miss) |
| Four counter bases + indices M/P/R/S | **High** (bytes) |
| Notify path bases 0xC vs 0x8700C + formula | **High** (bytes) |
| Product English for banks / grid | **Low** / open |
| Type-0xC Val12 payload field layout | **Med** (packed from flags; map op sealed) |
| Runtime / bit-exact | **Open** |
