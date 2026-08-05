# Function record: StatusFlag_GetDisplayName

| Field | Value |
|---|---|
| **Stable ID** | `aa_00580a20` |
| **Canonical name** | `StatusFlag_GetDisplayName` |
| **Address** | `0x00580a20`–`0x00580ac0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` / status UI |
| **Completion status** | **Dual A/B sealed** (W19-T 2026-07-29) — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias history

| Name | Status |
|---|---|
| `FUN_00580a20` | Ghidra / scaffold |
| `Combat_Weapons_Disabled` | Scaffold plate-string misname (one case only) |
| `Named_CalleeOf_Named_CalleeOf_Client_CastSkillFromQuickBarSlot_00580a20` | Auto callee alias |
| `StatusFlag_GetDisplayName` | **Canonical** — status flag key → English name table |

## Purpose

Pure lookup: given a status-flag key (typically a single power-of-two), return a pointer to a static English display string. Used by cast-block feedback and status UI paths. Unknown keys return `"in a world of hurt"`.

## Signature (sealed)

```c
const char * StatusFlag_GetDisplayName(int flagValue);
// ABI: stack arg [esp+4]; return EAX; plain RET (C3). No this.
```

## Control flow (sealed)

Range ladder:

1. `flagValue < 0x41`: exact `0x40` → Afraid; switch `1/2/4/8/0x10/0x20`.
2. else `flagValue < 0x2001`: exact `0x2000/0x80/0x200/0x1000`.
3. else: exact `0x4000/0x10000`.
4. else: default `"in a world of hurt"`.

Live decompile ≡ 2026-07-23 raw (no CF delta). Body size **0xA1** bytes through terminal `C3`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00580a20_StatusFlag_GetDisplayName.md`
- Annotated: `docs/reconstruction/raw/aa_00580a20_StatusFlag_GetDisplayName.annotated.md`
- Scaffold raw: `docs/reconstruction/raw/aa_00580a20_FUN_00580a20.md` (+ annotated)
- Clean: `docs/reconstruction/reconstructed-exact/StatusFlag_GetDisplayName.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00580a20.cpp`, `Combat_Weapons_Disabled.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00580a20_StatusFlag_GetDisplayName.md`
- Review B: `docs/reconstruction/reviews/B_aa_00580a20_StatusFlag_GetDisplayName.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Callers | `Client_CastBlockFeedback` `0x0093b7f0` | 3 sites: keys `2`, `0x80`, `0x40` |
| Callers | `FUN_00618c80` | 11+ sites |
| Callees | **none** (leaf; string immediates only) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ bytes | **High** / **Confirmed** |
| Stack single-arg ABI + plain RET | **Confirmed** (`read_memory` prologue/epilogue) |
| Product English strings | **Confirmed** (literal returns + pool `read_memory`) |
| Role = status flag display name table | **High** (caller CastBlockFeedback) |
| Canonical name English | **Probable** (structural; no RTTI) |
| Types beyond `int`/`const char*` | N/A leaf |
