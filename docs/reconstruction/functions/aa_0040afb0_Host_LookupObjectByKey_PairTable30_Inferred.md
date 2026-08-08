# Function record: Host_LookupObjectByKey_PairTable30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040afb0` |
| **Canonical name** | `Host_LookupObjectByKey_PairTable30_Inferred` |
| **Ghidra name** | `FUN_0040afb0` |
| **Address** | `0x0040afb0`–`0x0040afed` (**62 B** / `0x3E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Work item** | MEGA-028 OWN-ONLY dual seal |
| **Completion status** | **Dual sealed** (A/B accept-with-gaps); runtime open |
| **Bit-for-bit / runtime / diff** | Open |
| **Name confidence** | **Inferred** (role High; product English open) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

Resolve a keyed **object\*** from a host-owned **pair table** (`{int key; void* value}` at **`host+0x30`**, count at **`host+0x34`**). Linear first-match; miss → NULL out. Primary interaction path: soft-cast hit host (key **1**). Also material keys **3/4** (drive collision) and GetObjectsInArea.

## Signature (sealed)

```c
// __thiscall; ECX=host; stack out**, key; EAX=out; RET 8
void* __thiscall Host_LookupObjectByKey_PairTable30_Inferred(
    void* host,
    void** outObject,
    int key);
```

## Layout

| Offset | Field | Notes |
|---|---|---|
| `host+0x30` | `Pair* pairs` | `struct { int key; void* value; }` stride 8 |
| `host+0x34` | `int count` | signed; `<=0` → miss |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040afb0_FUN_0040afb0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040afb0_FUN_0040afb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_LookupObjectByKey_PairTable30_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040afb0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0040afb0_Host_LookupObjectByKey_PairTable30_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0040afb0_Host_LookupObjectByKey_PairTable30_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_0040afb0_FUN_0040afb0.md` |
| Report | `docs/agents/task-dual-ab-0040afb0-mega-028-report.md` |

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_00925820` | soft-cast parent (partition); key 1 |
| Caller | `FUN_004ea350` | GetObjectsInArea ×3; key 1 |
| Caller | `FUN_005d9ea0` / `FUN_005da0a0` | collision material keys 3/4 |
| Caller | `FUN_005911b0`, `FUN_00642b70`, `FUN_00932c80`, `005dd*` | keys 1 or 3 |
| Callees | none | leaf |

## Confidence

| Claim | Level |
|---|---|
| Body 62 B / RET 8 / leaf | **High** |
| Pair table +0x30/+0x34 stride 8 | **High** |
| Out-param object\* + EAX=out | **High** |
| Keys 1/3/4 observed | **High** |
| Product host/type English | **Open** (Inferred) |
| Runtime / bit-exact | **Open** |

## Gaps

1. Product/PDB symbol.  
2. Host RTTI without caller cast.  
3. Full key catalog.  
4. Runtime / differential.
