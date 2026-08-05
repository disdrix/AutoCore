# Function record: HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073cb70` |
| **Canonical name** | `HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred` |
| **Address** | `0x0073cb70` |
| **Body** | `0x0073cb70`–`0x0073cd69` (**506 B** / `0x1FA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | EDI host vector / PalDiffMap.fx material |
| **Completion status** | **Dual A/B complete** (2026-07-29 W36-G) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_0073cb70` |

## Purpose

**Get-or-create** factory for **0x14c** objects owned by an **EDI** host:

| Path | Behavior |
|---|---|
| Hit | `cursor(+0x44) < count(vec +0x4c/+0x50)` → return `vec[cursor++]` |
| Miss | `new(0x14c)+FUN_00764030`, `new(0xC4)+FUN_00748960`, load **PalDiffMap.fx**, resolve **DiffuseMap**, optional 16×16 tex (fmt **0x16**), material local + vcall **+0x5c**, **`FUN_007647c0`**, grow via **`FUN_004367f0` on +0x48**, store, `cursor++`, return new host |

## Signature

```c
void *HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred(void /* EDI = host* */);
```

| Slot | Source | Conf |
|---|---|---|
| EDI host | `unaff_EDI` / all `EDI+disp` accesses; no EDI push in prologue | **High** |
| return | EAX = cached or new 0x14c pointer | **High** |
| stack formals | none | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0073cb70_FUN_0073cb70.md`
- Annotated: `docs/reconstruction/raw/aa_0073cb70_FUN_0073cb70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0073cb70.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0073cb70_FUN_0073cb70.md`
- Dual A: `docs/reconstruction/reviews/A_aa_0073cb70_HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0073cb70_HostEDI_VecCursor44_GetOrCreate_PalDiffMap14c_Inferred.md`

## Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_0073d020` @ `0x0073d025` | get + DiffuseMap + vcall +0x18 |
| Caller | `FUN_0073d0a0` @ `0x0073d0a5` | twin wrapper (alt tex path) |
| Callee | `FUN_00764030` | 0x14c ctor |
| Callee | `FUN_00748960` | 0xC4 material ctor |
| Callee | `FUN_007647c0` | wire host←material |
| Callee | `FUN_004367f0` | vector capacity ensure |
| Data | `0x00a2ddcc` `"PalDiffMap.fx"` | product |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** |
| Vector layout + get-or-create | **High** |
| PalDiffMap.fx / DiffuseMap | **High** |
| Product host class English | Open |
| Unowned material pipeline callees | Open |
| Dual review | Present |
