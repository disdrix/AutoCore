# Function record: CVOGReaction_GiveMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_005327c0` |
| **Canonical name** | `CVOGReaction_GiveMission` |
| **Address** | `0x005327c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` (character + missionId) |
| **Completion status** | **Human-refined + dual residual (2026-07-29)** — grant CF High; insert helper roles sealed; product names for `+0x544`/`+0x530` open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Grant a mission: validate def, reject active/completed per repeat rules, `AddActiveObjective`, `UnlockContinentObject`, insert active state, optional toast `"Received Mission"` + `gen_give_quest` audio.

## Signature

```c
uint32_t __thiscall CVOGReaction_GiveMission(void* thisCharacter, unsigned missionId);
```

Returns 1 on grant / already-had log path, 0 on reject.

## Behavioral summary

1. Lookup mission def (`FUN_0053fff0` + `CNDHash_LookupByKey`); require **byte `def+0x130` (obj count) ≥ 1**.
2. `FUN_00547920` ensure mission XML loaded (ECX=def; stack 0/1).
3. Skip if already in active hash `+0x540` → **return 0**.
4. If `word def+0xAC != -1`: block on completed `+0x538` or instance `+0x53c` via mode gate on entity `+0xa8` object (`WeaponAllowsKillXpBonus`).
5. Ensure first objective (`def+0x13c` list) in `+0x548` via `AddActiveObjective(char, objDef)`.
6. `UnlockContinentObject(char, firstObj+0x120)`.
7. `CNDHash_Insert` (`FUN_0053c360`) into `+0x540`; optional second insert into **`+0x544`** under mode + (`word+0xF8==0` \| `dword+0x100!=-1`).
8. Strip completed via `FUN_00538b20` if `word+0xAC==-1`; alloc 0x30 blob; bind via `FUN_0053c660` on **`+0x530`**; `FUN_0052d8b0` notify.
9. Toast only when `word def+0xF8 == 0`.

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | High | Named; central grant path |
| Control flow | High | Raw plate + nested returns + residual asm |
| Hash offsets 538/53c/540/**544**/548/**530** | High | missionState + residual call-site ECX |
| Toast / audio strings | High | literal evidence |
| `FUN_0053c360` / `0053c660` / `00538b20` roles | High | hash insert/remove strings + asm |
| Def byte fields (`+0x130`, `+0xAC`, `+0xF8`, `+0x100`, `+0x168`) | High as gates | product English partial |
| Overall | **High (static)** | Dual residual 2026-07-29 |

## Open questions

- Product English for `char+0x544` (paired active) and `char+0x530` (state-blob hash).
- Mode object at entity `+0xa8` identity / `mode==2` / `+0x100` flag.
- Runtime toast path coverage for non-zero `+0xF8` missions.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_005327c0_CVOGReaction_GiveMission.md` |
| Annotated | `raw/aa_005327c0_CVOGReaction_GiveMission.annotated.md` |
| Clean | `reconstructed-exact/CVOGReaction_GiveMission.cpp` |
| Dual residual scratch | `reviews/a_005327c0.md` |
| Dual A/B | `reviews/A_aa_005327c0_*` / `B_aa_005327c0_*` |
