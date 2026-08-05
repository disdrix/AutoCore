# Review B (skeptical / adversarial): `FUN_00637de0` @ `0x00637de0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637de0` |
| **Review type** | Skeptical / adversarial dual |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00637de0_Requirement_ProgressToastAction.md` |
| **System tag** | `missions-progression` |
| **Scope** | Dual A/B only — no WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---:|---|---|---|
| 1 | This is Collect/UseItem **event Action** (`vtbl+0x04`) | Event Action lives at `+0x04` (e.g. Collect `0x00611f20`, Kill Precheck `0x00613b50`). Body only builds string + toast. | **Falsified as event Action** |
| 2 | This is **Eval** (completion gate) | Eval at `+0x08`/`+0x10`; body has no compare, no return 0/1 status used by callers as complete. | **Falsified** |
| 3 | This is **SlotAction** journal text | SlotAction is `+0x18`. This unit **calls** `+0x1c` (→ often SlotAction) then toasts. | **Falsified as SlotAction itself** |
| 4 | Recv mask bit runs type-local complete path | Recv residual + 14 DATA xrefs all land on **this** shared function. | **Falsified** |
| 5 | Types 7/8 skip is a decompiler artifact | Asm `cmp eax,8` / `cmp eax,7` / `je` before any work. | **Falsified** |
| 6 | Body mutates progress slots | No stores to `stateNode` progress fields; only local toast buffer. | **Falsified** |
| 7 | Body completes objective / EvaluatePending | Sole named callee `FUN_0040c5c0` (queue push). No CompleteObjective / EvaluatePending. | **Falsified** |
| 8 | Color/scale globals are toast-specific unique constants | Color matches GiveMission toast path; `0xa10e74=2.0` and `0xaaa68c=1.5` are **shared** floats (physics also uses them — names are misnomers). Values still correct for this pack. | **Partially conceded** (shared constants; values sealed) |
| 9 | `FUN_0040c5c0` is audio / mission grant | GiveMission also calls it with same color/scale packing **before** separate audio calls; callee is classic growable array (`elem 0x98`). | **Falsified as audio/grant** |
| 10 | `+0x1c` is always the trampoline | Sampled classes use `0x00637dd0`; residual notes some classes install type-local `+0x1c`. Toast still shared at `+0x20`. | **Conceded nuance** — toast still shared |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Shared `vtbl+0x20` progress-toast Action | **High** | Server mask bits misinterpreted as complete/eval |
| Skip types 7 & 8 | **High** | Spurious toasts for Km/TimePlayed (or silent skip for wrong types) |
| Text via `+0x1c` / SlotAction chain | **High** | Wrong journal string source |
| Toast enqueue only (no CF side effects) | **High** | Incorrect server complete coupling |
| Constants 2.0 / 1.5 / `0xffeee3d8` | **High** (values) | Visual mismatch only |
| UI semantic of 2.0 vs 1.5 fields | **Open** | Wrong presentation scaling if reimplemented |
| Km/TimePlayed enum mapping | **Probable** | Skip wrong types if client codes differ |
| Toast queue object identity | **Open** (role High) | Wrong queue if porting UI |

---

## 3. Surviving contract (AutoCore)

```
// After S2C 0x2071 slot writes, for each mask bit i:
req = objectiveDef.requirements[i]
if req.type not in {7, 8}:          // Km, TimePlayed (Probable)
    text = req.FormatProgress(char, stateNode)   // vtbl+0x1c → often SlotAction +0x18
    EnqueueMissionToast(text, color=0xffeee3d8, f0=2.0f, f1=1.5f,
                        entityId = stateNode ? sign_extend(stateNode.obj+0x10) : -1)
// never complete; never EvaluatePending; never write slots
```

**Mask bit meaning:** show progress toast for requirement *i*, **not** run event Action / Eval / complete.

---

## 4. Cross-check against raw + memory

| Check | Result |
|---|---|
| Raw pseudocode CF | Matches live decompile 2026-07-29 |
| Body bytes type compare | `8B 41 0C` … `83 F8 08` / `83 F8 07` |
| Trampoline bytes | `8B 01 FF 60 18` @ `0x00637dd0` |
| `0x00a10e74` | `00 00 00 40` → **2.0f** |
| `0x00aaa68c` | `00 00 c0 3f` → **1.5f** |
| UseItem/Collect/Patrol/Kill `+0x20` | all `E0 7D 63 00` → `0x00637de0` |
| Callee `FUN_0040c5c0` capacity math | `diff / 0x98` |

---

## 5. Open (do not invent)

1. PDB / product symbol for Action and toast queue push.
2. Presentation meaning of the two floats (scale vs lifetime vs alpha).
3. Class behind `*( *(p+4) + char + 0xA8 ) + 0xE8C8`.
4. Undefined code caller `0x005aded2`.
5. Full RTTI map of all 14 DATA vtbl hosts.
6. Runtime capture of toast on multi-req mask.

**Verdict:** adversarial challenges to “this is complete/eval/event Action” **defeated**. Role sealed as shared progress toast. **accept-with-gaps.**
