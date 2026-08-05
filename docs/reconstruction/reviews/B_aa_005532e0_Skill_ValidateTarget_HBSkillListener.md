# Review B (skeptical / adversarial): `aa_005532e0` Skill_ValidateTarget_HBSkillListener

| Field | Value |
|---|---|
| **Stable ID** | `aa_005532e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005532e0_Skill_ValidateTarget_HBSkillListener.md` |
| **Verdict** | **accept** on predicate contract + type tag/RTTI; **accept-with-gaps** only on handler/`vtbl+0x18` product names |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is free-standing / 2-arg / cdecl | **Falsified** — `ret 0x0C` on all exits; list util passes 3 args |
| 2 | `unaff_retaddr` is return address scribble | **Falsified** — third formal `stopFlag*`; list util `&local_5` |
| 3 | Type tag is optional / cosmetic | **Falsified** — hard `cmp +0x1c,1` before any cast |
| 4 | RTTI target is wrong class / inverted cast | **Falsified** — `read_memory` names + push order src Base → dst SkillBase |
| 5 | Code 1 means accept | **Falsified** — sets `ctx.result=0` (reject), mirrors parent gate |
| 6 | Accept always removes HB | **Falsified** — remove only when `rc==2` **and** `notifyHB!=0` |
| 7 | Always stops walk on any skill HB | **Falsified** — stop only on codes 1/2; other rc / skip flags fall through |
| 8 | Multiple callers | **Falsified** — single DATA xref from ValidateTarget |
| 9 | Decompiler alone sufficient for thin seal | **Partially true** — CF stable across force refresh, but ABI needs asm (`ret 0x0C`, stop formal) |
| 10 | Null after cast is handled | **Falsified** — no test; crash if cast fails |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type tag `+0x1c==1` | **Confirmed** | Wrong HBs polled / missed skill HBs |
| RTTI path Base→SkillBase | **Confirmed** | Cast fails or wrong vtbl |
| Handler codes 1/2 | **Confirmed** | Inverted ValidateTarget accept |
| Remove only on notify accept | **Confirmed** | Accidental HB destroy on NPC casts (notify=0) |
| Stop on 1 and 2 | **Confirmed** | List walks entire HB chain after decision |
| `+0x20` skip | **Confirmed** gate | May re-probe stopped HBs if inverted |
| `+0x20` product English | **High** (`cStopped`) | Naming only |
| `vtbl+0x18` meaning | Tentative | Wrong notify side-effect model |
| Handler class | Tentative | Wrong legality rules when porting |

---

## 3. Cross-check against three-rep

```
Rep A — decompile_function(0x005532e0):
  type tag; RTTI names; +0x20; handler 1/2; unaff_retaddr mis-id

Rep B — force_decompile(0x005532e0):
  identical pseudocode (no CF drift)

Rep C — read_memory body + RTTI + string + pcode constants:
  ret 0x0C ×3; RTTI 0xaf8cec / 0xaf8d98; string 0x9d254c;
  pcode PTRSUB to same descriptors; skillId +0x620
```

**Attack on “thin function needs three-rep”:** decomp alone misnames stop formal and return width — **asm/bytes required**. Three-rep closes ABI; RTTI sealed by memory not decompiler labels alone.

**Attack on dual-review of parent only:** parent dual already named this unit but left it “not full dual three-rep”. **This pass** seals the residual.

---

## 4. Surviving contract for AutoCore

```
Skill_ValidateTarget_HBSkillListener(hb, ctx, stop*) -> remove:
  if hb.typeTag(+0x1c) != 1: return keep
  hb = dynamic_cast<CVOGHBSkillBase*>(hb)   # from CVOGHBBase
  if hb.cStopped(+0x20) != 0: return keep
  handler = ctx.skill[+0x5F0]
  if !handler: log("Skill found with no base class: %d", hb[+0x620]); return keep
  rc = handler.vtbl+0x44(ctx.target, ctx.skill, hb)
  if rc == 1:
    ctx.result = 0; *stop = 1; return keep
  if rc == 2:
    ctx.result = 1; *stop = 1
    if ctx.notifyHB: hb.vtbl+0x18(1,0); return remove
    return keep
  return keep
```

### Notify polarity vs callers

| Parent call notify | Listener remove on accept? | Conf |
|---|---|---|
| `CVOGHBSkillBase_ctor` notify=**1** | **Yes** (can destroy matching node after notify) | **Confirmed** path exists |
| NPC / outpost / reaction notify=**0** | **No** remove; still can set result/stop | **Confirmed** |

---

## 5. Residual uncertainty (honest)

| # | Item | Blocks seal? |
|---|---|---|
| R1 | Handler class / vtbl+0x44 catalog | **No** (predicate glue sealed) |
| R2 | HB `vtbl+0x18` product name | **No** (call site sealed) |
| R3 | `+0x20` English beyond High `cStopped` | No |
| R4 | Cast-null behavior | No (matches binary; corrupt-input only) |
| R5 | Parent / list util duals | Already accept |

---

## 6. Falsification checklist

| Attempt | Result |
|---|---|
| Invert type tag test | Breaks all skill-HB recognition — rejects sealed ctor write |
| Invert RTTI direction | Memory strings disagree |
| Treat return as “valid target” bool | Conflicts with list util remove semantics + ValidateTarget using `ctx.result` |
| Assume always remove on match | Asm returns 1 only on notify path |
| Claim multiple xrefs | Ghidra `get_function_xrefs` count=1 |

**Verdict:** **accept** — adversarial checks failed to break type tag, RTTI, ABI, or code polarity.
