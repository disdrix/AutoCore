# Function record: Client_PromptSkillTargetSelect

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093bac0` |
| **Canonical name** | `Client_PromptSkillTargetSelect` |
| **Address** | `0x0093bac0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Alias of canonical** — see `aa_0093bac0_Client_PromptSkillTargetSelect.md` (dual A/B strengthened 2026-07-29; `+0x30c0` pending skill sealed) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0093bac0`
- Prior auto-slug names (if any): leave on disk; canonical is `Client_PromptSkillTargetSelect`

## Purpose

UI prompt to pick a skill target or ESC to cancel targeting mode.

## String evidence

`"Select a target for this skill, or press ESC to cancel."`

## Signature (decompiler-derived)

```c
void Client_PromptSkillTargetSelect(int param_1,char param_2)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0093bac0_FUN_0093bac0.md`
- Annotated: `docs/reconstruction/raw/aa_0093bac0_FUN_0093bac0.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Client_PromptSkillTargetSelect.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0093bac0.cpp`

## Callers / callees

(Populate from Ghidra xrefs in follow-up.)

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Naming from string literals | High |
| Parameter semantic names | Probable / Tentative |
| Types | Tentative |
