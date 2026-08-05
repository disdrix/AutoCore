# Review B (skeptical / adversarial): `aa_00512bb0` Skill_SiblingCastClearPredicate

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512bb0` |
| **Canonical name** | `Skill_SiblingCastClearPredicate` (**Inferred**) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00512bb0_Skill_SiblingCastClearPredicate.md` |
| **Residual scratch** | `reviews/a_00512bb0.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as binding-map clear predicate | Map node fields vs HB type/RTTI | **Falsified** merge |
| 2 | Full 16-byte TFID equality | Asm: 2 dwords + 1 byte; `+0x664` spill unused | **Falsified** full-TFID |
| 3 | Always considers OKToCastAgain | Flag gate + type==8 required | **Falsified** unconditional |
| 4 | Type-1 only | Type-8 RTTI arm present | **Falsified** exclusive type-1 |
| 5 | `cdecl` / free-standing 2-arg | `ret 0x0C` = 3 stack args stdcall | **Falsified** 2-arg ABI |
| 6 | Writes stop flag to halt after first match | Body never touches arg3 | **Falsified** — removes all matches |
| 7 | Removes without stopping HB | `vtbl+0x18(1,0)` before return 1 | **Attack fails** |
| 8 | Null-safe after failed RTTI | No null test; deref cast result | **Falsified** null-safe claim |
| 9 | Sole xref is `0x00514e20` | Second DATA site `FUN_00517400` | **Falsified** sole-xref |
| 10 | Product symbol recovered | No plate / demangle string on VA | **Holds open** |
| 11 | `piVar1[0x188]` is opaque | `0x188*4 = 0x620` skillId embed | **Attack fails** — math sealed |
| 12 | Type-8 compares TFID like type-1 | Only skillId via `+0x24→+0x5fc` | **Falsified** TFID-on-type8 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `stdcall` `ret 0x0C` / 3 formals | **Confirmed** | Wrong callback ABI → stack corruption |
| Dual RTTI arms + type tags 1/8 | **Confirmed** | Wrong HB family removed |
| Flag = OKToCastAgain gate only | **Confirmed** | Leftover type-8 or over-clear |
| Partial TFID shape | **Confirmed** | Port over-matches / under-matches |
| skillId `@+0x620` / `skill+0x5fc` | **Confirmed** | Clear wrong skill |
| `vtbl+0x18` = Stop/End family | **High** not Confirmed name | Wrong lifecycle call |
| Working title as product symbol | **Tentative** | Registry churn only |
| Inlined consumer `FUN_00517400` role | **High** CF; name **Open** | Miss alternate clear path |

---

## 3. Cross-check against raw / live

```
decomp: type==1 RTTI SkillBase skillId+TFID partial; else flag+type8 OKToCastAgain skillId
live:   ret 0x0C; type tag +0x1c; offsets 0x620/0x658/0x24/0x5fc; vtbl+0x18(1,0)
RTTI:   0x00af8d98 Base; 0x00af8cec SkillBase; 0x00b0015c OKToCastAgain (strings)
xrefs:  DATA 0x00514e5b (wrapper), DATA 0x00517520 (FUN_00517400 inline)
live ≡ intended CF: Yes
```

### Sentinel / sibling traps

| Trap | B position |
|---|---|
| Merge with ClearCastBinding map erase | **Reject** — HB list payload RTTI |
| Assume full TFID16 | **Reject** — asm partial |
| Assume flag unused | **Reject** — gates type 8 |
| Assume sole consumer is wrapper | **Reject** — `FUN_00517400` also |
| Assume stop-out halts walk | **Reject** — unused arg3 |
| Treat as free function (not callback) | **Reject** — DATA xrefs only |

---

## 4. Surviving contract for AutoCore

```
// Callback for CNDDoubleList_InvokePredicateAndRemove (nullPayloadFlag=0 at callers)
// __stdcall ret 0x0C
// return 1 → Stop HB then remove node; 0 → keep

pred(hb, ctx, stop_unused):
  if hb.type@+0x1c == 1 and RTTI CVOGHBSkillBase:
    if hb.skillId@+0x620 == ctx.skillId
       and hb.srcTfid@+0x658 matches ctx.tfid partially (2 dwords + 1 byte):
         hb.vtbl+0x18(1,0); return REMOVE
  if ctx.alsoOkToCastAgain and hb.type == 8 and RTTI CVOGHBOKToCastAgain:
    if hb.skill@+0x24->id@+0x5fc == ctx.skillId:
         hb.vtbl+0x18(1,0); return REMOVE
  return KEEP

Ctx pack (by Skill_SiblingCastClear / FUN_00517400):
  +0 skillId; +4 unset; +8..+14 tfid[4]; +18 flag

Consumers of this VA (address-taken):
  Skill_SiblingCastClear @ 0x00514e20  — host+0xB0 list; flag from caller
  FUN_00517400 @ 0x00517520          — same pred, flag 0, skill-tree refresh path
```

Port note: server authority must not depend on this client HB predicate; cast cancel on wire is separate.

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| `ret 0x0C` stdcall 3 args | **Agree Confirmed** |
| Dual RTTI SkillBase / OKToCastAgain | **Agree Confirmed** |
| Partial TFID (2+1) | **Agree Confirmed** |
| Flag gates type 8 only | **Agree Confirmed** |
| Stop then return 1 | **Agree Confirmed** |
| Two DATA xrefs | **Agree Confirmed** |
| accept-with-gaps | **Agree** |
| Working title as sealed product symbol | **Reject seal** — role Inferred, symbol Open |

---

## 6. Open questions

1. Demangled / string product name.
2. Rationale for partial TFID (engine quirk vs intentional loose match).
3. Name `vtbl+0x18`.
4. Product name for `FUN_00517400` inlined consumer.
5. Runtime capture matrix.

**Verdict:** **accept-with-gaps** — agree A seals on ABI/RTTI arms/partial TFID/flag/Stop-remove/xrefs; block over-claims of full-TFID, sole-xref-to-wrapper, null-safe RTTI, and demangled product symbol.
