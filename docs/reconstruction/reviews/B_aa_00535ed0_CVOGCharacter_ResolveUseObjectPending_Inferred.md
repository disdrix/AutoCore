# Review B (skeptical / adversarial): `aa_00535ed0` CVOGCharacter_ResolveUseObjectPending_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00535ed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00535ed0_CVOGCharacter_ResolveUseObjectPending_Inferred.md` |
| **Agent** | W25-A OWN-ONLY |
| **Verdict** | **accept** on CF/kind10/UI0x14; **needs-more-evidence** on secondary-object product type |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as near-object `00535c60` | Different entry, kind **10** not **9**, no 20.0f range | **Falsified** |
| 2 | Always EvaluatePending | Only valid-TFID + commit + resolve success | **Falsified** |
| 3 | Kind is 9 | Decomp passes `10` | **Falsified** |
| 4 | Dead / scaffold only | Four CODE callers incl. countdown `005360f0` | **Falsified** |
| 5 | Returns void | AL bool + early `xor al,al` path | **Falsified** |
| 6 | `Named_…RecordFirstTimeEvent…` is product | Scaffold callee-chain label only | **Falsified** |
| 7 | TFID null is zeros | `DAT_009cee98` lo/hi are `0xFFFFFFFF` | **Falsified** zeros claim |
| 8 | UI packet kind unknown | `local_11c = 0x14` sealed | **Survives** as 0x14; English open |
| 9 | Secondary path always runs | Requires `+0xc9c` non-null and commit/`+0xc7d` | **Falsified** always |
| 10 | Clean invents inventory grid | No FindByCoid in this body | **Falsified** invent claim |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Kind 10 vs 9 separation | **High** | Wrong objective class |
| UI 0x14 non-commit path | **High** | Missing cancel UX |
| Flag map `+0xc7c…` | **High** | Pending state desync |
| Bool thiscall ret 4 | **High** | ABI break |
| Secondary `+0xc9c` type | **Tentative** | Wrong cancel target |
| Product English | **Tentative** | Docs only |

---

## 3. Cross-check against raw / image

### Spine

```
if !vbase || !pending(+0xc7c): clear; return 0
if tfid_invalid:
  optional vtbl+0x2cc clear path
else if !commit:
  require +0xc7d; UI packet 0x14
else:
  resolve TFID → EvaluatePending(10, cbid_float, 0, 0)
clear all pending slots; return ok
```

### Image seals

| Fact | Pattern |
|---|---|
| Frame | `81 EC 44 01 00 00` |
| this | `8B F1` |
| Flag gate | `38 9E 7C 0C 00 00` |
| Epilogue | `81 C4 44 01 00 00 C2 04 00` |
| Fail early AL | `32 C0` before same epilogue |
| Null TFID | `read_memory 009cee98` → `ff×8 00×8` |

### Contrast sibling `FUN_00535c60`

Near-object / inventory → kind **9**. Do **not** alias. Do **not** import 20.0f.

Clean preserves spine. **No invented callers. No kind swap.**

---

## 4. Surviving contract for AutoCore

```
// Pending use-object resolve / clear
bool ResolveUseObjectPending(Character ch, bool commit):
  if !ch.HasVBase() or not ch.UsePendingActive(+0xc7c):
    ch.UsePendingActive = false
    return false
  ok = true
  if ch.PendingTfidIsNull():
    if sec = ch.SecondaryObj(+0xc9c):
      if commit or ch.UsePendingCancel(+0xc7d):
        sec.VCall_2CC(commit ? 1 : 0, ch)
        clear secondary + aux HB
        goto FINISH
  else:
    if not commit:
      if not ch.UsePendingCancel: return false
      SendLogicUiPacket(kind=0x14)
      goto FINISH
    obj = ResolveFromTFID(ch.PendingTfid)
    if obj:
      EvaluatePendingObjectives(ch, kind=10, (float)obj.CloneBaseId, 0, 0)
      goto FINISH
  ok = false
FINISH:
  clear pending flags/TFID/aux/timer
  return ok

// Do NOT use kind 9 (that is FUN_00535c60 near-object path).
// Do NOT treat DAT_009cee98 as zero TFID — lo/hi are 0xFFFFFFFF.
```

---

## 5. Open questions

1. Product names for kind 10 / UI 0x14.
2. Class of object at `+0xc9c`.
3. Full coupling with `FUN_0060b410` / `FUN_0060b440` (HB family).

**Verdict:** CF **accept**. Secondary type **needs-more-evidence**.
