# Function record: HandlerTable58_FindById6c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508c50` |
| **Canonical name** | `HandlerTable58_FindById6c` (Inferred) |
| **Ghidra name** | `FUN_00508c50` |
| **Address** | `0x00508c50` |
| **Body range** | `0x00508c50`–`0x00508c91` exclusive (**65** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | status/hook handler tables (multi-slot family) |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; product name open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00508c50_HandlerTable58_FindById6c.md`, `reviews/B_aa_00508c50_HandlerTable58_FindById6c.md` (2026-07-29 W21-D) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00508c50`
- `Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508c50` (legacy xref scaffold — **misleading product claim**)
- Role: linear find-by-id on registry table at **`+0x58`** matching **`entry+0x6c`**

## Purpose

Scan `*(this+0x58)[0 .. DAT_00d02984)` for the first entry whose id field at `+0x6c` equals the requested id. Return that entry pointer, or null. Rejects id **`-1`** and empty/non-positive global counts.

## Signature

```c
void *__thiscall HandlerTable58_FindById6c(void *registry, int32_t id);
// ECX=registry, [esp+4]=id; RET 4
```

## Algorithm

1. If `id == -1` or `DAT_00d02984 <= 0` → return 0.
2. `table = *(void***)(registry + 0x58)`.
3. For `i = 0 .. DAT_00d02984-1`: if `*(int32_t*)(table[i] + 0x6c) == id` return `table[i]`.
4. Miss → 0.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00508c50_FUN_00508c50.md`
- Annotated: `docs/reconstruction/raw/aa_00508c50_FUN_00508c50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/HandlerTable58_FindById6c.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00508c50.cpp`
- Legacy alias: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508c50.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00508c50-0051e3d0-w21d-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers** | `FUN_004fe380` (Vehicle_ApplyItemStatusHooksOnEquip), `FUN_005092b0`, `FUN_00509410`, `FUN_00509550`, `FUN_00509680`, `FUN_005097b0`, `FUN_00509940`, `FUN_00513580` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| `__thiscall` + `ret 4` | **High** |
| Table at `+0x58`, id at `entry+0x6c` | **High** |
| Count = `DAT_00d02984` | **High** |
| Role = handler/def lookup for subtype 0xa path | **High** (caller dual) |
| Product English name | **Inferred** |
| Runtime / differential | Open |

## Related

- Twin slot **`+0x54`**: `HandlerTable54_FindById6c` / `FUN_00508c00` (equip subtype **0xb**)
- Family: `FUN_00508ac0` (+0x44), `FUN_00508bb0` (+0x50), …
- Parent dual: `A/B_aa_004fe380_Vehicle_ApplyItemStatusHooksOnEquip`
