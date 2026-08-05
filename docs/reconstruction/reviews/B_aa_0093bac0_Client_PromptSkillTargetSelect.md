# Review B (skeptical / adversarial): `Client_PromptSkillTargetSelect` @ `0x0093bac0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093bac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual strengthen) |
| **Counterpart** | `reviews/A_aa_0093bac0_Client_PromptSkillTargetSelect.md` |
| **Residual scratch** | `reviews/a_0093bac0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Auto-casts without target | **Falsified** — body never calls RequestCast; only chrome + stores |
| 2 | Server-side target pick | **Falsified** — client UI string + local cursor fields |
| 3 | `+0x30c0` is **only** a skill id | **Narrowed** — skill path yes; also holds modes 0/2/3/4/5 and **-1** clear. Overclaim skill-only is wrong |
| 4 | `param_2` is skill id | **Falsified** — `param_2` is show-prompt char; skill/mode is **EAX** |
| 5 | ESC string always shown | **Falsified** — string only if `param_2≠0` and chat sink non-null; cancel sites pass 0 |
| 6 | Mode flag offset unknown | **Falsified residual** — `+0x30c0` store Confirmed; `+0x30c4` show flag Confirmed |
| 7 | No cast pipeline link | **Falsified residual** — CastSkill enter + `FUN_00941ac0` complete/clear |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Targeting chrome required before some casts | **High** | Cast without pick UX |
| `+0x30c0` skill-path pending skill | **Confirmed** | Wrong skill on complete cast |
| Multi-mode reuse of `+0x30c0` | **Confirmed** | Treat RE/tinker modes as skills |
| EAX register formal | **Confirmed** | Miss pending id entirely if only stack formals |
| Cursor mode numbers product meaning | Medium | Wrong cursor asset only |
| Cancel helper `FUN_007f9df0` name | Low name / High role | Doc only |

---

## 3. Cross-check against raw + asm

```
// skill enter (CastSkillFromQuickBarSlot):
MOV  EAX, skillId
PUSH 1
PUSH client
CALL PromptSkillTargetSelect   // stores skill → client+0x30c0; shows string

// cast complete (FUN_00941ac0):
RequestCastSkill(*(client+0x30c0), tfid…)
OR   EAX, -1
PUSH 0
PUSH client
CALL PromptSkillTargetSelect   // clears pending

// ESC (OnKeyDown when DAT_00d1d900 != -1):
OR   EAX, -1
PUSH 0
PUSH &DAT_00d1a840
CALL PromptSkillTargetSelect
```

Raw switch cases 0/2/3/4/5/-1/default match live decompile. `read_memory` on `DAT_00afa0ac` block yields small int sentinels used as “already this cursor” compares.

---

## 4. Surviving contract for AutoCore

```
// retail: client stack; showPrompt stack; modeOrSkill in EAX
PromptSkillTargetSelect(client, showPrompt):  // EAX = modeOrSkillId
  old = client.pendingSkillOrMode   // +0x30c0
  maybeRefresh = (EAX != old) && (old|EAX in {0,4,5})
  client.showSkillTargetPrompt = showPrompt   // +0x30c4
  client.pendingSkillOrMode = EAX             // +0x30c0  **SEALED**
  switch EAX:
    -1 → cancel cursor
    0,2,3,4,5 → special UI cursor modes
    default → skill target cursor (mode 5)    // skill ids land here
  if showPrompt && chatSink: toast select-or-ESC
  if maybeRefresh: RefreshOpenMissionUiWindows
```

**Do not** implement this as “cast skill”. **Do** persist pending skill at `+0x30c0` for the complete-cast path.

---

## 5. Open questions (post-strengthen)

1. Product names for cursor helpers `FUN_007f9cc0` / `FUN_007f9df0` / pre `FUN_007a69d0`.
2. Full English names for modes 0/2/3/4/5 beyond RE/tinker/gadget partial map.
3. Whether skill id **1** is unused intentionally (case 1 absent; default handles it).
4. Runtime coverage of all enter sites.

**Verdict:** Safe as client targeting-mode setter; **pending skill at `client+0x30c0` sealed for skill path** with multi-mode caveat. **accept-with-gaps.**
