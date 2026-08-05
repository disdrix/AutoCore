# Function record: Object_IsLevelLessThan6

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc460` |
| **Canonical name** | `Object_IsLevelLessThan6` |
| **Ghidra name** | `FUN_005cc460` |
| **Address** | `0x005cc460` |
| **Body range** | `0x005cc460`–`0x005cc488` (40 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `npc-ai` / vehicle pursue gate |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + ABI + GetLevel slot sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005cc460_Object_IsLevelLessThan6.md`, `reviews/B_aa_005cc460_Object_IsLevelLessThan6.md` (2026-07-29 W23-R) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005cc460`
- Scaffold: `Named_CalleeOf_CVOGHBAICreatureBase_DoVehiclePursue_005cc460`

## Purpose

Null-safe **level &lt; 6** predicate: resolve MI-adjusted this, call **vtbl+0x27c** (GetLevel), return 1 if level &lt; 6 else 0. Used by `CVOGHBAICreatureBase_DoVehiclePursue` to pick the low-level pursue path — **not** a heading helper.

## Signature

```c
uint8_t __stdcall Object_IsLevelLessThan6(void *obj);
// ret 4; AL = 0/1
```

## Algorithm

1. If `obj == null` → return 0.
2. `inner = obj + *(*(obj+4)+4) + 4`.
3. `level = inner->vtbl[0x27c/4](inner)`.
4. Return `level < 6`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005cc460_FUN_005cc460.md`
- Annotated: `docs/reconstruction/raw/aa_005cc460_FUN_005cc460.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_IsLevelLessThan6.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_005cc460.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005cc460_FUN_005cc460.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005cc460-00578550-w23r-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | vtbl+`0x27c` | GetLevel (indirect) |
| Caller | `0x005cfb60` | `CVOGHBAICreatureBase_DoVehiclePursue` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| stdcall `ret 4` | **High** |
| vtbl+0x27c = GetLevel | **High** (cross-dual project convention) |
| Threshold 6 exclusive | **High** |
| Product name | **Open** |
| Runtime / differential | Open |
