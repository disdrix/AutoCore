# Function record: MedalUI_CountDisplayableEntries_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090c810` |
| **Canonical name** | `MedalUI_CountDisplayableEntries_Inferred` |
| **Ghidra name** | `FUN_0090c810` |
| **Address** | `0x0090c810`–`0x0090c8c9` (**186 B** / `0xBA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Partition** | MEGA-103 — Medal UI query/count (parent `0x0090cbc0`) |
| **Completion status** | **Dual sealed** (A/B **accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Naming rationale

| Evidence | Weight |
|---|---|
| Parent `FUN_0090cbc0` calls this immediately after prep clear; uses EAX for page math (`(count-0x19)/3+1`, threshold `0x18`) | High |
| Callee `FUN_0051a0e0` dualed as **MedalDef_LookupById** | High |
| Hash/vector offsets match parent medal rebuild walk (`+0x540` hash, `+0x574` vector) | High |
| Sibling `FUN_0090c9a0` binds `"i_d_a_2d_btn_achievement.xml"` into host slots | High |
| Partition map hint: **Medal UI query/alloc** (this unit is query only; alloc is `0090c9a0`) | Medium |
| No product symbol inside body → **`_Inferred`** suffix | Required |

Retired: `Named_VOG_DEBUG_STOP_0090c810`.

## Purpose

Query total displayable medal/achievement entries on the character object:

1. If `EBX == 0` → return 0.
2. Seed count from owned-id **vector size** at `+0x574/+0x578` (dword count via `(end-begin)>>2`; null begin → 0).
3. Lock hash at `*(EBX+0x540)+0x1d`, walk chain (`hash+0x14` / `node+0x14`), for each payload at `node+8` call `MedalDef_LookupById(*(payload+0x100))` and increment on hit.
4. Unlock; return count in EAX.

## Signature

```c
// Retail ABI: EBX = character / medal-state*; void stack; EAX = int; bare RET
int MedalUI_CountDisplayableEntries_Inferred(void);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0090c810_FUN_0090c810.md` |
| Annotated | `docs/reconstruction/raw/aa_0090c810_FUN_0090c810.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUI_CountDisplayableEntries_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0090c810.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0090c810_FUN_0090c810.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0090c810_MedalUI_CountDisplayableEntries_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0090c810_MedalUI_CountDisplayableEntries_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0090c810-mega-103-report.md` |

## Callers / callees

| Direction | Value |
|---|---|
| Callers | `FUN_0090cbc0` @ `0x0090cbfa`; `FUN_0090c920` @ `0x0090c938`; gap twin @ `0x0090c8ed` |
| Callees | `FUN_0051a0e0` MedalDef_LookupById; `FUN_007a4480` ×4 |

## Gaps

- Product English for character class behind `DAT_00d1b6d8`.
- Whether owned vector is always pre-validated (raw size, no lookup).
- Product hash container class English.
- Runtime / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets | **High** |
| Medal UI count-query role | **High** |
| Product type names | **Low** |
