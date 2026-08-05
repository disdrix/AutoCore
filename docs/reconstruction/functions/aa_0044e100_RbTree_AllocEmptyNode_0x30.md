# Function record: RbTree_AllocEmptyNode_0x30

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e100` |
| **Canonical name** | `RbTree_AllocEmptyNode_0x30` |
| **Ghidra name** | `FUN_0044e100` |
| **Address** | `0x0044e100` |
| **Body range** | `0x0044e100`–`0x0044e136` (Ghidra); epilogue bare `ret` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / RB-tree |
| **Completion status** | **partial** — dual A/B **accept**; CF + size + flags + EAX sealed; product type / OOM open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0044e100_RbTree_AllocEmptyNode_0x30.md`, `reviews/B_aa_0044e100_RbTree_AllocEmptyNode_0x30.md` |
| **Last reviewed** | `2026-07-29` (W21-O) |

## Alias

- `FUN_0044e100` (Ghidra)
- `Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0044e100` (auto parent-seed — incomplete; multi-caller map header factory)

## Purpose

Factory for a **0x30-byte** empty RB-tree node used as a **sentinel seed**: allocate, zero three link dwords, seed flag bytes (`+0x2c=1`, `+0x2d=0`), return pointer. Does **not** install self-links or map size — those are caller-side (Profiler_Zone_Ctor pattern; CNDAssetStringTable serialize).

## Signature

```c
// Machine: cdecl, 0 stack args, bare ret; EAX = node*
void *RbTree_AllocEmptyNode_0x30(void);
```

## Layout (this unit)

| Offset | Field | Role |
|---:|---|---|
| `+0x00` | left* | zeroed |
| `+0x04` | parent* | zeroed |
| `+0x08` | right* | zeroed |
| `+0x0c`..`+0x2b` | value region | untouched |
| `+0x2c` | color seed | **1** (black Probable) |
| `+0x2d` | isnil seed | **0** (header callers set **1**) |

## Algorithm

1. `p = operator_new(0x30)`
2. Conditionally zero `p[0]`, `p[1]`, `p[2]`
3. `p.byte[0x2c]=1; p.byte[0x2d]=0`
4. Return `p` in EAX

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0044e100_FUN_0044e100.md`
- Annotated: `docs/reconstruction/raw/aa_0044e100_FUN_0044e100.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/RbTree_AllocEmptyNode_0x30.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0044e100.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0074c9c0-0044e100-w21o-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `operator_new` (`0x00489892`) |
| **Callers (sample)** | `Profiler_Zone_Ctor` `0x00786280`; `FUN_005abfa0`; `FUN_00744a60`; `FUN_00492dd0`; `FUN_0055c870`; `FUN_0099b8e0`; CNDAssetStringTable serialize path |

## Confidence

| Claim | Level |
|---|---|
| Control flow size/flags/zeros | **High** |
| cdecl + EAX return | **High** |
| No self-link / no size in unit | **High** |
| Sentinel-factory role via callers | **High** |
| Flag English color/isnil | **Probable** |
| Product/PDB symbol | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_00439770` RbTree_AllocEmptyNode_Inferred (0x18 twin)
- `aa_00786280` Profiler_Zone_Ctor (header completion)
