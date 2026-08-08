# Function record: StdVector_DwordSize_EaxVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401c30` |
| **Canonical name** | `StdVector_DwordSize_EaxVec_Inferred` |
| **Prior scaffold** | `FUN_00401c30` |
| **Rejected misname** | `Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_00401c30` (xref-seed false) |
| **Address** | `0x00401c30`–`0x00401c42` inclusive (**19 B** / `0x13`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / shared dword-vector size |
| **Agent** | MEGA-082 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept** — CF/ABI/formula sealed) |
| **Terminal** | **false** (runtime open) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC-style **null-safe** size query for a `std::vector`-like container of **4-byte** elements. Reads `begin` at `+4` and `end` at `+8`; returns `0` if begin is null, else `(end - begin) >> 2`.

```text
StdVector_DwordSize_EaxVec_Inferred(vec /*EAX*/) → n
  begin = vec->begin (+4)
  if begin == 0: return 0
  end   = vec->end   (+8)
  return (end - begin) / 4
```

Shared multi-domain leaf (UI list scroll, char-create vehicle panel path under plate parent `FUN_008d4910`, pointer-table loops). **Not** a vehicle-name product method — plate string lives only in parent `FUN_008d4910` / `"Your Vehicle Name Is Invalid!  Please Choose Another!"` @ `0x00a3fba4`.

## Signature (decompiler + bytes)

```c
// EAX = vec; bare RET (C3); size in EAX
// Distinct from dualed StdVector_DwordSize @ 0x004024b0 (ECX = vec)
int StdVector_DwordSize_EaxVec_Inferred(void *vec /*EAX*/);
```

| Item | Value |
|---|---|
| Body | `8B 48 04 85 C9 75 03 33 C0 C3 8B 40 08 2B C1 C1 F8 02 C3` |
| Pad | `CC` after `0x00401c42` |
| Twin | `StdVector_DwordSize` `0x004024b0` (ECX ABI) |
| Classification | leaf |

## Artifacts

- Raw scaffold + re-verify: `docs/reconstruction/raw/aa_00401c30_FUN_00401c30.md`
- Annotated: `docs/reconstruction/raw/aa_00401c30_FUN_00401c30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_DwordSize_EaxVec_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00401c30.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00401c30_StdVector_DwordSize_EaxVec_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00401c30_StdVector_DwordSize_EaxVec_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_00401c30_FUN_00401c30.md`
- Report: `docs/agents/task-dual-ab-00401c30-mega-082-report.md`

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Callees | **none** | leaf |
| Xrefs | **11** UNCONDITIONAL_CALL | all `MOV EAX,<vec>` before CALL |
| `FUN_008b6eb0` | `008b6f5e`, `008b6f7b` | size vs host `+0x520` scroll index |
| `FUN_008d4910` | `008d516f`, `008d518a` | case `0x9c45`; vec @ host+`0x8dc` |
| Orphans | `0090593e` family; `008a463c` family | assembly context sealed |
| Twin | dualed `StdVector_DwordSize` `0x004024b0` | same formula, **ECX** |

## Confidence

| Claim | Level |
|---|---|
| Control flow | **Confirmed** |
| EAX ABI + bare RET | **Confirmed** |
| Size formula / null begin | **Confirmed** |
| Role vs plate Named_CalleeOf misname | **Confirmed reject misname** |
| Distinct from ECX twin | **Confirmed** |
| Product element / host English | **Tentative** (`_Inferred`) |
