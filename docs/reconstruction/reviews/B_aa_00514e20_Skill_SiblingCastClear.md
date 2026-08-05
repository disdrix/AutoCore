# Review B (skeptical / adversarial): `aa_00514e20` Skill_SiblingCastClear

| Field | Value |
|---|---|
| **Stable ID** | `aa_00514e20` |
| **Canonical name** | `Skill_SiblingCastClear` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00514e20_Skill_SiblingCastClear.md` |
| **Residual scratch** | `reviews/a_00514e20.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `Skill_ClearCastBindingAndMaybeRestartCd` | Binding map vs `host+0xB0` list | **Falsified** merge |
| 2 | Clears all HBs on host | Predicate requires skillId (+ TFID / type) | **Falsified** |
| 3 | Always clears OKToCastAgain | Type-8 arm requires `flag≠0` | **Falsified** as unconditional |
| 4 | Full 16-byte TFID equality | Asm compares 2 dwords + 1 byte only | **Falsified** full-TFID claim |
| 5 | Free-standing stdcall (no this) | `mov ecx,[ecx+0xB0]`; `ret 0x18` | **Falsified** — **thiscall** |
| 6 | Predicate is type-1 only | Type-8 RTTI arm present | **Falsified** exclusive type-1 |
| 7 | Decompiler 3-arg call is complete surface | Missing ECX list load | **Agree noise** with A |
| 8 | Removes without stopping HB | `vtbl+0x18(1,0)` before return 1 | **Attack fails** — stop then remove |
| 9 | Wire / server authority path | Client list bookkeeping only | **Falsified** server claim |
| 10 | Product name recovered from strings | No symbol / plate string on VA | **Holds open** — working title only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + `*(host+0xB0)` list | **Confirmed** | Wrong object / crash |
| Predicate dual RTTI arms | **Confirmed** | Wrong HB family removed |
| Flag = OKToCastAgain gate | **Confirmed** | Leftover cast-again HB or over-clear |
| Partial TFID match shape | **Confirmed** | Port over-matches / under-matches |
| skillId `@+0x620` embed math | **Confirmed** | Clear wrong skill |
| `nullPayloadFlag=0` ownership | **High** | Double-free if inverted |
| `vtbl+0x18` = Stop/End family | **High** not Confirmed name | Wrong lifecycle call |
| Working title as product symbol | **Tentative** | Registry churn only |
| FUN_0052db50 TFID base after adjust | **Open** | Wrong source identity on tree-delete |

---

## 3. Cross-check against raw / live

```
raw scaffold: pack locals → FUN_004e2600(&LAB_00512bb0, ctx, 0)
live asm:     thiscall; list=*(ecx+0xB0); pred=0x00512bb0; flag push 0; ret 0x18
predicate:    type1 SkillBase skillId+partial TFID; type8 OKToCastAgain if flag
live ≡ intended CF: Yes (decomp this-omission is noise)
```

### Sentinel / sibling traps

| Trap | B position |
|---|---|
| Merge with ClearCastBinding | **Reject** — different container (map vs list) |
| Merge with LookupActiveCastBinding | **Reject** — lookup is read-only map |
| Treat `FUN_00514e00` as same unit | **Reject** — counter decrement only |
| Assume full TFID16 equality | **Reject** — asm partial |
| Assume flag unused | **Reject** — gates type 8 |

---

## 4. Surviving contract for AutoCore

```
// Client-local cast HB cleanup on host list (+0xB0)
Skill_SiblingCastClear(host, skillId, sourceTfid16, alsoOkToCastAgain):
  InvokePredicateAndRemove(host.hbList@+0xB0, pred, ctx, nullPayload=0)

pred(hb, ctx):
  if hb.type==1 and RTTI CVOGHBSkillBase:
    if hb.skillId@+0x620 == ctx.skillId
       and hb.srcTfid@+0x658 matches ctx.tfid partially:
         hb.Stop(1,0); return REMOVE
  if ctx.alsoOkToCastAgain and hb.type==8 and RTTI CVOGHBOKToCastAgain:
    if hb.skill@+0x24->id@+0x5fc == ctx.skillId:
         hb.Stop(1,0); return REMOVE
  return KEEP

Callers:
  ApplyStatusEffectLocal  — flag 0; clear skill-cast HB when binding exists
  FUN_00514e70            — flag 0; skill+0x615 path
  FUN_0052db50            — flag 1; skill remove also kills OKToCastAgain
```

Port note: server must not depend on this client HB list; authority cast cancel is separate wire (`0x11` / Recv path).

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| thiscall + list `+0xB0` | **Agree Confirmed** |
| Predicate RTTI SkillBase / OKToCastAgain | **Agree Confirmed** |
| Partial TFID | **Agree Confirmed** |
| Flag gates type 8 | **Agree Confirmed** |
| Three callers | **Agree Confirmed** |
| Distinct from binding clear | **Agree** |
| accept-with-gaps | **Agree** |
| Working title as sealed product symbol | **Reject seal** — role High, symbol Open |

---

## 6. Open questions

1. Demangled / string product name.
2. Rationale for partial TFID (engine quirk vs intentional loose match).
3. Name `vtbl+0x18`.
4. Seal FUN_0052db50 this-adjust + TFID offsets.
5. Runtime capture matrix.

**Verdict:** **accept-with-gaps** — agree A seals on ABI/predicate/callers; block over-claims of full-TFID match, unconditional OKToCastAgain clear, and demangled product symbol.
