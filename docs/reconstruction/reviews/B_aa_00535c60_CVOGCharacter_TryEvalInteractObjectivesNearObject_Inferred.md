# Review B (skeptical / adversarial): `aa_00535c60` CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00535c60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00535c60_CVOGCharacter_TryEvalInteractObjectivesNearObject_Inferred.md` |
| **Agent** | W24-K OWN-ONLY |
| **Verdict** | **accept** on CF; **needs-more-evidence** on entry points + English enums |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Dead code (no xrefs) | Body complete; EvaluatePending dual lists kind 9 from this VA; sibling `00535ed0` live | **Survives refined** — CF live, entry residual |
| 2 | `VOG_DEBUG_STOP` is product purpose | Only hash-lock assert path | **Falsified** |
| 3 | Always runs distance check | Inventory FindByCoid hit jumps over range block | **Falsified** |
| 4 | Threshold is 25.0f use-object range | Image loads `0x00aaa6e8` = 20.0f not `0x00aaa6fc` | **Falsified** |
| 5 | Kind 10 like sibling | Image `push 9` not 10 | **Falsified** |
| 6 | Type filter is weapon 0xC | Mission evaluator `vtbl+0x50` in active-hash def walk | **Survives refined** — objective evaluator type, not equip |
| 7 | Walks pending hash `+0x55c` | Image `mov … [esi+0x548]` | **Falsified** — active path hash |
| 8 | Returns void | `mov al,1` / `xor al,al` + `ret 4` | **Falsified** — bool |
| 9 | Clean invented inventory grid path | Prologue matches FindByCoid dual | **Falsified** |
| 10 | `g_nInferredThreatDefault` name proves threat AI | Same float used as range here; plate English open | **Survives** as naming gap only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Inventory-or-range gate order | **High** | Wrong interact completion |
| 20.0f constant | **High** | Wrong range port |
| Active hash `+0x548` | **High** | Pending vs active confusion |
| Type 0xC + kind 9 | **High** | Wrong objective class / telemetry |
| Bool thiscall ret 4 | **High** | ABI break |
| Static callers | **Open** | May miss live wire-up |
| Product English | **Tentative** | Docs only |

---

## 3. Cross-check against raw / image

### Spine

```
if !FindByCoid(char.inventoryGrid, object.coid):
  if distance(char, object) > 20.0: return 0
lock(char+0x548)
for def in hash:
  for eval in def.evals:
    if eval.type==0xC and eval.match(char, object):
      unlock; EvaluatePending(char, 9, cbid_float, 0, 0); return 1
unlock; return 0
```

### Image seals

| Fact | Pattern |
|---|---|
| FindByCoid setup | `mov ecx,[esi+0x250]; mov ecx,[ecx+0x2b0]; push hi/lo; call` |
| Range cmp | `comiss xmm0, [0x00aaa6e8]`; `ja return0` |
| Kind 9 | `6A 09` before EvaluatePending call |
| Success | `B0 01` … `C2 04 00` |
| Fail empty | `32 C0` … `C2 04 00` |

### Contrast (not owned) `FUN_00535ed0`

Use-object TFID resolve path → EvaluatePending **kind 10**. Different entry, different kind. Do not alias.

Clean preserves spine. **No invented callers. No 25.0f swap.**

---

## 4. Surviving contract for AutoCore

```
// Near-object / inventory-held interact → pending eval kind 9
bool TryEvalInteractObjectivesNearObject(Character ch, Object obj):
  if !InventoryContainsCoid(ch, obj.Coid):
    if Distance(ch, obj) - Radius > 20.0: return false
  for each active mission/objective def on ch.ActiveHash(+0x548):
    for each evaluator with Type==0xC:
      if evaluator.Matches(ch, obj):
        EvaluatePendingObjectives(ch, kind=9, (float)obj.CloneBaseId, 0, 0)
        return true
  return false

// Do NOT use DAT_00aaa6fc (25.0f click UseObject range) here.
// Do NOT use kind 10 (that is FUN_00535ed0 use-object path).
// Entry wiring: OPEN — confirm before assuming static call graph completeness.
```

---

## 5. Open questions

1. Dynamic registration site for this function pointer.
2. Objective type 0xC retail name (Interact/Use/Proximity/…).
3. Context kind 9 product enum name.
4. Runtime: inventory-held object completion vs world-prop completion.

**Verdict:** Adversarial review **accepts** inventory skip, 20.0f range, active-hash type-0xC match, and kind-9 EvaluatePending. Residual = **entry xrefs** + naming.
