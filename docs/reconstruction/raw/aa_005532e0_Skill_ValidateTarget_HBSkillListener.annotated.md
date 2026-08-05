# Annotated: aa_005532e0 Skill_ValidateTarget_HBSkillListener

| Field | Value |
|---|---|
| **Stable ID** | `aa_005532e0` |
| **Canonical name** | `Skill_ValidateTarget_HBSkillListener` |
| **VA** | `0x005532e0` |
| **System** | skills-abilities |
| **Convention** | MSVC `__stdcall` — `ret 0x0C` (3 stack args) |
| **Dual** | `reviews/A|B_aa_005532e0_Skill_ValidateTarget_HBSkillListener.md` |

---

## 1. Purpose

Match/remove predicate over a target’s HB list (`target+0xB0` via `CNDDoubleList_InvokePredicateAndRemove_Inferred`). Filters for skill-base heartbeats by **type tag `+0x1c == 1`** then RTTI-casts `CVOGHBBase` → `CVOGHBSkillBase`. When active (`+0x20 == 0`), re-invokes the casting skill’s handler (`skill+0x5F0` vtbl `+0x44`) with the HB as third arg. Handler code **1** forces ValidateTarget reject; code **2** accepts and optionally notifies/removes the HB when the ctor-style notify flag is set.

---

## 2. Signature (assembly-backed)

```c
// returns AL: 0 = keep list node; 1 = unlink+destroy node
uint8_t __stdcall Skill_ValidateTarget_HBSkillListener(
    void* hbPayload,              // list node payload (CVOGHBBase*)
    ValidateTargetCtx* ctx,       // {pTarget, pSkill, result, notifyHB}
    char* stopFlag);              // out: set 1 to stop list walk
```

---

## 3. Sealed control flow

```
if (hbPayload[+0x1c] != 1):
    return 0                            # not skill-type HB

hb = dynamic_cast<CVOGHBSkillBase*>(hbPayload)   # CVOGHBBase → CVOGHBSkillBase
# NO null check after cast (tag 1 expected to guarantee skill base)

if (hb[+0x20] != 0):
    return 0                            # cStopped / skip

handler = ctx.pSkill[+0x5F0]
if (handler == null):
    log(1, "Skill found with no base class: %d", hb[+0x620])
    return 0

rc = handler->vtbl[+0x44](target=ctx.pTarget, skill=ctx.pSkill, hb)
# ECX=handler thiscall/member; stack (target, skill, hb)

if (rc == 1):
    ctx.result = 0
    *stopFlag = 1
    return 0                            # stop walk; do NOT remove node

if (rc == 2):
    ctx.result = 1
    *stopFlag = 1
    if (ctx.notifyHB != 0):
        hb->vtbl[+0x18](1, 0)           # thiscall ECX=hb
        return 1                        # remove node
    return 0                            # keep node; walk already stopped

return 0                                # other rc: no ctx change from this node
```

---

## 4. Type tag + RTTI (sealed)

| Item | Evidence | Conf |
|---|---|---|
| Type tag offset `+0x1c` dword | `cmp [eax+0x1c], 1` @ entry | **Confirmed** |
| Tag value **1** = skill HB | `CVOGHBSkillBase_ctor` writes `self[7]=1` | **Confirmed** |
| RTTI src `CVOGHBBase` | type_info `0x00af8d98` → `".?AVCVOGHBBase@@"` | **Confirmed** |
| RTTI dst `CVOGHBSkillBase` | type_info `0x00af8cec` → `".?AVCVOGHBSkillBase@@"` | **Confirmed** |
| Cast order | push dst `af8cec`, src `af8d98` (MSVC R→L) | **Confirmed** |
| Gate `+0x20 == 0` | `cmp byte [edi+0x20],0` | **Confirmed** |
| Field name `cStopped` | ctor layout dual; product English | **High** |

---

## 5. Offsets

| Object | Off | Use | Conf |
|---|---:|---|---|
| HB | `+0x1c` | type tag must be 1 | **Confirmed** |
| HB | `+0x20` | skip if nonzero | **Confirmed** |
| HB | `+0x00` | vtbl for `+0x18` notify | **Confirmed** |
| HB | `+0x620` | skill id in log (`0x188` dwords) | **Confirmed** |
| Skill | `+0x5F0` | handler object pointer | **Confirmed** |
| Handler | vtbl `+0x44` | legality re-probe | **Confirmed** |
| HB | vtbl `+0x18` | notify `(1,0)` | **Confirmed** call; semantics open |
| Ctx | `+0` / `+4` / `+8` / `+9` | target / skill / result / notify | **Confirmed** |

---

## 6. Handler codes (listener path)

| EAX | Effect | Remove? | Stop? | Conf |
|---:|---|---|---|---|
| **1** | `ctx.result = 0` | No | Yes | **Confirmed** |
| **2** | `ctx.result = 1`; optional notify | Only if `notifyHB` | Yes | **Confirmed** |
| other | No writes | No | No | **Confirmed** |

---

## 7. Caller contract

Sole DATA xref `0x00553684` in `Skill_ValidateTargetForSkill`:

```
// after primary handler gate fails-open (rc != 1):
ctx = { pTarget, pSkill, result=1, notifyHB=flag }
CNDDoubleList_InvokePredicateAndRemove_Inferred(
    listMgr = *target[+0xB0],
    pred    = Skill_ValidateTarget_HBSkillListener,
    ctx,
    destroyPayloadFlag = 0);
return ctx.result;
```

List util invokes `pred(node.payload, ctx, &stop)`; nonzero AL → unlink + vtbl-destroy node.

---

## 8. Side effects

1. May set `ctx.result` and `*stopFlag`.
2. May call handler vtbl+0x44 with HB third arg (differs from wrapper’s third-arg `0`).
3. May call HB vtbl+0x18(1,0) when accept + notify.
4. May cause list node removal (return 1) — only accept+notify path.
5. Log path only when handler null (does not alter result).

---

## 9. Decompiler corrections

| Ghidra display | Correction | Conf |
|---|---|---|
| `unaff_retaddr` | Formal `char* stopFlag` | **Confirmed** (`ret 0x0C` + list util) |
| 2-arg prototype | 3-arg stdcall | **Confirmed** |
| Missing ECX on vcalls | Handler/HB this in ECX | **Confirmed** |
| Identical force_decompile | Same CF; no thin ambiguity after asm | **Confirmed** |

---

## 10. Open

1. Product English for HB `+0x20` beyond `cStopped` High.
2. HB `vtbl+0x18` method name / full semantics.
3. Handler class at `skill+0x5F0` and per-skill `+0x44` bodies.
4. Whether cast-null is ever reachable under non-corrupt type tag 1.
