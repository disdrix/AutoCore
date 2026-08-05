# Review B (skeptical / adversarial): `aa_004294f0` List_TraversalLock

| Field | Value |
|---|---|
| **Stable ID** | `aa_004294f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004294f0_List_TraversalLock.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Double lock **throws** `0x80070005` | Confuse with Clear/Insert | **Falsified** — double lock **logs + returns**; no throw |
| 2 | Unlocks CS on exit | Symmetric unlock in same body | **Falsified** — Enter only; caller LeaveCS |
| 3 | Is the iterator (`IterateNext`) | Name conflation | **Falsified** — only flag+CS; no node walk |
| 4 | Sets flag **before** EnterCS | Race ordering | **Falsified** — Enter then `mov byte [esi+0x28],1` |
| 5 | Fatal stop on re-lock (process halt) | VOG_DEBUG_STOP string | **Overstated** — logs via `FUN_007a4480`; continues return |
| 6 | Inventory-only helper | Domain skim | **Falsified** — broad xrefs beyond inventory UI |
| 7 | Registry name is invent | Symbol inflation | **Falsified as invent** — string contains `TraversalLock` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag + CS contract | **High** | Deadlock / missed lock |
| Soft re-lock | **High** | Port that throws breaks nested walkers |
| Caller must unlock | **High** | CS leak |
| Product class name | **Low–Med** | Doc only |
| Stack dump helpers exact identity | **Med** | Debug path only |

---

## 3. Cross-check against raw ≡ force

```text
if (*(list+0x28) != 0) {
  log VOG_DEBUG_STOP;
  // optional call-stack fill when DAT_00d0dfb0
  log "List Error!  TraversalLock Call Stack:\n%s\n";
  return;  // CS not re-entered
}
EnterCriticalSection(list+4);
*(list+0x28) = 1;
// CS held
```

Sibling contrast:

* `List_ClearDestroy` (`0x0040dc40`): if locked → **throw** `0x80070005`.
* `List_Insert_u64` (`0x00573040`): if locked → **throw** after Enter (debug).

---

## 4. Surviving contract for AutoCore

```
List_TraversalLock(list):
  if list.traversalFlag (+0x28):
      debug_log_call_stack(); return
  EnterCS(list.cs @ +4)
  list.traversalFlag = 1
  // caller must: flag=0; LeaveCS when done iterating
```

**Port tests:** re-lock must not second-Enter; success must leave CS held; never free nodes here.

**Verdict:** **accept-with-gaps** — adversarial throw/unlock/iterator confusions **fail**.
