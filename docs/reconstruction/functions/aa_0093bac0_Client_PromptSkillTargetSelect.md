# Function record: Client_PromptSkillTargetSelect

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093bac0` |
| **Canonical name** | `Client_PromptSkillTargetSelect` |
| **Address** | `0x0093bac0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human dual A/B strengthened 2026-07-29** — `client+0x30c0` pending skill sealed (skill path); multi-mode reuse documented |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0093bac0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_PromptSkillTargetSelect`

## Purpose

Enter or leave client skill/UI target-select chrome. On the skill path: store **pending skill id** at `client+0x30c0`, set show-prompt at `+0x30c4`, apply skill cursor, optionally toast “Select a target for this skill, or press ESC to cancel.” Does **not** send the cast.

## String evidence

`"Select a target for this skill, or press ESC to cancel."`

## Signature (decompiler + asm)

```c
// Stack: client*, showPrompt (char)
// Register: EAX = modeOrSkillId  (skill id on prompt path; -1 clear; 0/2/3/4/5 special modes)
void Client_PromptSkillTargetSelect(void* client, char showPrompt /* + EAX */);
```

## Sealed offsets (this unit)

| Offset | Size | Field | Confidence |
|--------|------|-------|------------|
| `client+0x30c0` | 4 | **pending skill id / interaction mode** | **Confirmed** (skill path = pending skill) |
| `client+0x30c4` | 1 | show target-select prompt | **Confirmed** |
| `client+0x109c` | 4 | chat/UI sink (null-checked) | High |
| `client+0x1168` | 4 | cursor controller object* | High role; type name open |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0093bac0_FUN_0093bac0.md`
- Annotated: `docs/reconstruction/raw/aa_0093bac0_FUN_0093bac0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_PromptSkillTargetSelect.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0093bac0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0093bac0_Client_PromptSkillTargetSelect.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0093bac0_Client_PromptSkillTargetSelect.md`
- Residual: `docs/reconstruction/reviews/a_0093bac0.md`

## Callers / callees

**Callees:** `FUN_007a69d0`, `FUN_007f9cc0`, `FUN_007f9df0`, `FUN_007a6de0`, `FUN_008f8200`, `Client_RefreshOpenMissionUiWindows`

**Callers (key):**

| Caller | Role |
|--------|------|
| `Client_CastSkillFromQuickBarSlot` | enter skill target-select (`EAX=skillId`, show=1) |
| `FUN_00941ac0` | after RequestCast from pending skill; clear (`EAX=-1`) |
| `Client_Input_OnKeyDown_MatchAction` | ESC cancel (`EAX=-1`) |
| `FUN_0093d110` / inventory UI | special modes 0/2/3/4/5 + clears |
| others | mostly clear (`EAX=-1`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **Confirmed** (≡ live) |
| Naming from string literals | **High** |
| `+0x30c0` pending skill (skill path) | **Confirmed** |
| `+0x30c4` show-prompt | **Confirmed** |
| EAX register formal | **Confirmed** |
| Special-mode English names | Partial / Tentative |
| Cursor helper product names | Tentative |
