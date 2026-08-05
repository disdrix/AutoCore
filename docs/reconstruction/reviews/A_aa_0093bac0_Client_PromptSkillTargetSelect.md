# Review A (reconstruction fidelity): `aa_0093bac0` Client_PromptSkillTargetSelect

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093bac0` |
| **VA** | `0x0093bac0` |
| **Canonical name** | `Client_PromptSkillTargetSelect` |
| **Review date** | `2026-07-29` (dual strengthen; base 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0093bac0_Client_PromptSkillTargetSelect.md` |
| **Residual scratch** | `reviews/a_0093bac0.md` |
| **System tag** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0093bac0_FUN_0093bac0.md` |
| Annotated | `docs/reconstruction/raw/aa_0093bac0_FUN_0093bac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_PromptSkillTargetSelect.cpp` |
| Function record | `docs/reconstruction/functions/aa_0093bac0_Client_PromptSkillTargetSelect.md` |
| Live Ghidra decompile | `0x0093bac0` (2026-07-29) |
| Asm call-site context | 19 xrefs via `get_assembly_context` |
| Sibling cast enter | `Client_CastSkillFromQuickBarSlot` @ `0x009418e0` |
| Sibling cast complete | `FUN_00941ac0` @ `0x00941ac0` |
| Multi-mode consumer | `FUN_0093d110` / `Inv_Client_ReverseEngineerItem` |

**Purpose:** Enter/leave client cursor target-select chrome. Skill path stores pending skill id and optionally shows “Select a target for this skill, or press ESC to cancel.”

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Canonical name from prompt string | **High** | String literal in body |
| `*(client+0x30c0) = EAX` every entry | **Confirmed** | Store after pre-call |
| Skill path: EAX = skillId from CastSkillFromQuickBarSlot | **Confirmed** | `MOV EAX,[EBP+8]` @ `0x0094196d` |
| `FUN_00941ac0` casts `*(client+0x30c0)` then clears with EAX=-1 | **Confirmed** | decompile + asm `OR EAX,0xFFFFFFFF` |
| Cancel paths set EAX=-1, show=0 | **Confirmed** | ESC, teardown, bulk-clear sites |
| `client+0x30c4 = param_2` show-prompt | **Confirmed** | char store; gates string |
| String only if show≠0 and `client+0x109c≠0` | **Confirmed** | decompile |
| Switch modes 0/2/3/4/5/-1/default drive cursor at `client+0x1168` | **Confirmed** | CF |
| default arm = skill-cursor (mode 5) for non-special EAX | **High** | skill ids fall here |
| Mission UI refresh on transitions involving {0,4,5} | **Confirmed** | `bVar3` predicate |
| Live decompile ≡ frozen raw | **Confirmed** | 2026-07-29 re-decompile |
| Does **not** send cast packet alone | **Confirmed** | no RequestCast in body |

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Read old `+0x30c0`; compute refresh bool | **Yes** |
| `FUN_007a69d0`; store `+0x30c4` / `+0x30c0` | **Yes** |
| switch EAX → cursor fields / cancel | **Yes** |
| optional `FUN_007f9cc0` | **Yes** |
| optional select-target string via `FUN_008f8200` | **Yes** |
| optional `Client_RefreshOpenMissionUiWindows` | **Yes** |

Clean remains a scaffold twin of raw (param names still `param_1`/`param_2`/`in_EAX`); plate documents sealed semantics.

---

## 4. Gaps (post-strengthen)

1. ~~Mode flag offsets OPEN~~ **Closed** — `+0x30c0` / `+0x30c4` Confirmed.
2. ~~Link to RequestCast OPEN~~ **Closed** — enter via CastSkillFromQuickBarSlot; complete via `FUN_00941ac0`.
3. Product names for `FUN_007a69d0` / `FUN_007f9cc0` / `FUN_007f9df0` still open.
4. Full English enum for special modes 0/2/3/4/5 partial (RE/tinker/gadget High via consumer strings).
5. `client+0x1168` type name / cursor resource DAT_* product names open.
6. Runtime / bit-exact open.

**Verdict:** CF faithful; **`client+0x30c0` pending-skill (skill path) sealed**. Multi-mode reuse documented. **accept-with-gaps.**
