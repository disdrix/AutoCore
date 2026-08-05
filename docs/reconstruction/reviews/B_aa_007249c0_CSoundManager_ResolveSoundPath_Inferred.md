# Review B (skeptical / adversarial): `aa_007249c0` CSoundManager_ResolveSoundPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007249c0` |
| **VA** | `0x007249c0` |
| **Canonical name** | `CSoundManager_ResolveSoundPath_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007249c0_CSoundManager_ResolveSoundPath_Inferred.md` |
| **System** | client audio / `CSoundManager` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always returns input pointer | Copies to **static** `DAT_00d20d98`; may null | **Falsified** |
| 2 | Plays audio itself | Resolve only; no mixer call | **Falsified** player |
| 3 | Pipe means concatenation path | `strtok` alternates + random pick | **Falsified** join claim |
| 4 | Missing file always silent | `param_3` gates log | **Partial** — log optional |
| 5 | Thread-safe reentrant | Static buffer + strtok | **Falsified** reentrancy |
| 6 | First alternate always wins | RandomUnitScalar path | **Falsified** first-only |
| 7 | Mission FailMission helper | Sound-file plate string | **Falsified** mission |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Static buffer + string evidence | **Confirmed** | Wrong return lifetime |
| `\|` alternate + random | **High** | Always-first port bug |
| Existence via 00724870 | **Confirmed** | Skip search roots |
| Optional log | **Confirmed** | Spam / silence wrong |
| Not the player | **Confirmed** | Wrong layer |
| `param_1` owner type | **Open** | Wrong +0x308 |
| strtok token lifetime | **Open** | dangling if static overwritten |

---

## 3. Cross-check

```
raw ≡ live.
Plate: "Sound file doesn't exist: %s"
strchr('|') / strtok("|")
FUN_00724870 → PathFileExistsA + root walk (callee decompile)
6 callers across proximity, UI, drive.
```

### Static buffer trap

Return value is **not** a heap string owned by caller. Concurrent resolves or delayed use after second call → overwrite.

### strtok trap

`strtok` **mutates** `DAT_00d20d98`. Token pointers into that buffer are only valid until next resolve.

### Random trap

Do not port as “first existing file wins” without the RandomUnitScalar arm.

---

## 4. Surviving contract for AutoCore

```
const char* ResolveSoundPath(ctx, pathOrList, logMissing):
  // copies into process-static DAT_00d20d98
  // '|' → filter existing → random one
  // no '|': single existence check
  // miss → optional log → null

AutoCore must NOT:
  - free the returned pointer
  - assume reentrancy / multi-thread safety
  - treat as immediate Play()
  - invent mission fail coupling
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Static resolve + `\|` alternates | **Agree Confirmed** |
| Random among hits High | **Agree** |
| Log string Confirmed | **Agree** |
| param_1 / DAT_00d1a614 Medium | **Agree Open** |
| accept-with-gaps | **Agree** |
