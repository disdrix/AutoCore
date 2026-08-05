# Function record: GetModifierSkillID

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509940` |
| **Canonical name** | `GetModifierSkillID` (**High** — product format string) |
| **Ghidra name** | `FUN_00509940` |
| **Address** | `0x00509940` |
| **Body range** | `0x00509940`–`0x00509a78` exclusive (**312** / `0x138` B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills / modifier ID resolution |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + product name sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00509940_GetModifierSkillID.md`, `reviews/B_aa_00509940_GetModifierSkillID.md` |
| **Last reviewed** | `2026-07-29` (W23-P) |

## Alias

- `FUN_00509940`
- `Skill_GetModifierSkillID_passed_an_invalid_IDPrefix_i_00509940` (string-scaffold name)
- Product plate: `"GetModifierSkillID() passed an invalid IDPrefix: %i\n"` @ `0x009cdc88`

## Purpose

Map an **IDPrefix** through global map `DAT_00b041dc` to a **type**, then look up the matching handler-table entry on `this` (registry) and return the modifier skill id at **`entry+0x9c`**. Total failure logs and returns **`-1`**.

## Signature

```c
int32_t __thiscall GetModifierSkillID(void *registry, int32_t idPrefix);
// ECX=registry, [esp+4]=idPrefix; RET 4
// return: skill id, or -1
```

## Algorithm

1. `Map_LowerBoundFindByIntKey(&DAT_00b041dc, …, &idPrefix)`.
2. If iterator at end (`DAT_00b041e0`): optional GetTypeFromIDPrefix miss log if prefix≠0; `type=0`.
3. Else `type = *(node+0x10)`.
4. `switch(type)` → `FUN_00508ac0` / `b10` / `b60` / `bb0` / `c00` / `c50` (thiscall registry).
5. On hit: `return *(entry+0x9c)`.
6. On miss: **fall through** next cases; default → GetModifierSkillID log + `-1`.

## Type dispatch

| Type | Helper | Table (known) |
|---|---|---|
| `0x0C` | `FUN_00508ac0` | `+0x44` / `DAT_00d02974` |
| `0x1C` | `FUN_00508b10` | family |
| `0x0A` | `FUN_00508b60` | `+0x4c` / `DAT_00d0297c` |
| `0x0E` | `FUN_00508bb0` | family |
| `0x46` | `HandlerTable54_FindById6c` | `+0x54` |
| `0x44` | `HandlerTable58_FindById6c` | `+0x58` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00509940_FUN_00509940.md` (+ W23-P append)
- Annotated: `docs/reconstruction/raw/aa_00509940_FUN_00509940.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GetModifierSkillID.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00509940.cpp`
- String alias: `docs/reconstruction/reconstructed-exact/Skill_GetModifierSkillID_passed_an_invalid_IDPrefix_i_00509940.cpp`
- Review A/B: as above
- Scaffold record: `docs/reconstruction/functions/aa_00509940_FUN_00509940.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `Map_LowerBoundFindByIntKey` @ `0x0050f940`; `FUN_00508ac0`/`b10`/`b60`/`bb0`/`c00`/`c50`; `FUN_007a4480` |
| **Callers** | `FUN_004fdcb0` (×2), `FUN_005cb8f0`, `FUN_005cbb20`, `FUN_005cc070`, `FUN_005cc2a0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body range | **High** |
| Product name GetModifierSkillID | **High** (string) |
| `__thiscall` + `ret 4` + ECX=registry | **High** (bytes) |
| Map type @ node+0x10; skill @ entry+0x9c | **High** |
| Fallthrough on table miss | **High** (decomp + case layout) |
| Type English labels | **Open** |
| Runtime / differential | Open |

## Related

- Handler duals: `HandlerTable54_FindById6c` (`00508c00`), `HandlerTable58_FindById6c` (`00508c50`)
- Loot family `CVOGLootGenerator_GetTypeFromIDPrefix_*` shares map-miss string only
