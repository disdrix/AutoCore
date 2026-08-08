# Review B (skeptical / adversarial): `CVOGHBSkillBase_ScalarDeletingDtor` / `FUN_00578de0` @ `0x00578de0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578de0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00578de0_CVOGHBSkillBase_ScalarDeletingDtor.md` |
| **Verdict** | **accept** on CF/ABI/vtbl/class/free; **needs-more-evidence** only on product mangled symbol |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Same as complete dtor `FUN_00578a60` | **Falsified** — this adds `(flags&1)` + `operator_delete` + `ret 4` |
| 2 | Bare `ret` / no stack arg | **Falsified** — `ret 4`; flags at `[esp+8]` after push |
| 3 | Always frees | **Falsified** — free only when bit0 set |
| 4 | Array deleting (`flags&2`) | **Falsified** — only bit0 tested; no cookie/loop |
| 5 | Direct CODE callers | **Falsified** — sole xref is **DATA** vtbl[0] |
| 6 | Class is generic / unknown | **Falsified** — vtbl `PTR_FUN_009d3fdc` is RTTI-sealed `CVOGHBSkillBase` |
| 7 | OnEnd parent `0x00578ce0` calls this | **Falsified** — parent body ends exclusive at this VA; adjacency only |
| 8 | Base `CVOGHBBase_ScalarDeletingDtor` is this VA | **Falsified** — base twin is `0x00508630` (different vtbl) |
| 9 | Product mangled name sealed | **Open** |
| 10 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes / CF | **Confirmed** | Wrong teardown / free order |
| ABI `ret 4` + flags bit0 | **Confirmed** | Stack imbalance / leak |
| Complete dtor callee | **Confirmed** | Skip skill-owned buffer free |
| Vtbl[0] identity | **Confirmed** | Mis-wire virtual delete |
| Class family CVOGHBSkillBase | **Confirmed** | Port to wrong HB subclass |
| Product mangled | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// __thiscall  ret 4  → EAX = this
void* CVOGHBSkillBase_ScalarDeletingDtor(CVOGHBSkillBase* this, uint8_t flags):
  FUN_00578a60(this)            // complete body (restores PTR_FUN_009d3fdc, …)
  if flags & 1:
    operator_delete(this)
  return this

// NOT the complete-body-only path (use FUN_00578a60).
// NOT CVOGHBBase_ScalarDeletingDtor @ 0x00508630 (base vtbl 0x009cdab0).
// NOT OnEnd / FireTail (those are vtbl+0x10 family).
// Virtual delete goes through vtbl[0] = this VA @ 0x009d3fdc.
```

---

## 4. Falsification notes

### 4.1 Collapse with complete dtor

Ports that free inside `FUN_00578a60` invent scalar behavior for stack/member skill-HB objects destroyed without `delete`. Keep the pair split.

### 4.2 flags bit dictionary fantasy

Only **bit 0** is tested. Do not invent array-delete (`flags&2`) behavior — body has no array cookie / multi-element loop.

### 4.3 Parent-as-caller fantasy

Partition parent `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` @ `0x00578ce0` ends exclusive at `0x00578de0`. Image adjacency ≠ call edge. Live entry is virtual via vtbl[0].

### 4.4 Decompiler "does not return"

Ghidra marks `operator_delete` as non-returning; machine has fall-through to `MOV EAX,ESI` / `RET 4`. Clean preserves return-this contract.

---

## 5. Open questions

1. Product mangled name.  
2. Dual seal of complete body `FUN_00578a60`.  
3. Runtime / bit-exact.

**Verdict:** **accept** on sealed CF, ABI, vtbl[0], class, and scalar free. Reject complete-dtor collapse, array-delete, and OnEnd-caller fantasies. Product mangled open only.
