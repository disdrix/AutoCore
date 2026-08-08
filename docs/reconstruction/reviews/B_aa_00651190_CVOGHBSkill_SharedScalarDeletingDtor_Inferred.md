# Review B (skeptical / adversarial): `CVOGHBSkill_SharedScalarDeletingDtor_Inferred` / `FUN_00651190` @ `0x00651190`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00651190` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-001 OWN dual) |
| **Counterpart** | `reviews/A_aa_00651190_CVOGHBSkill_SharedScalarDeletingDtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role/shared-vtbl; product mangled + runtime open |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Same function as complete dtor `FUN_00578a60` | **Falsified** — this adds `(flags&1)` + `operator_delete` + `ret 4` |
| 2 | Same VA as base scalar `0x00578de0` | **Falsified** — different body; base vtbl[0] is `0x00578de0` |
| 3 | Bare `ret` / no stack arg | **Falsified** — `ret 4`; flags at `[esp+8]` after push |
| 4 | Always frees | **Falsified** — free only when bit0 set |
| 5 | Array-delete (`flags&2`) present | **Falsified** — only bit0 tested; no cookie/loop |
| 6 | Class-specific Master-only dtor | **Falsified** — DATA xrefs span many skill vtbls (Master, XPAdder, …) |
| 7 | Class-specific XPAdder-only dtor | **Falsified** — same shared body |
| 8 | Direct call to `FUN_00578a60` (no thunk) | **Partially false as machine fact** — this VA calls **`0x00548f90`** JMP thunk; effective body is still `FUN_00578a60` |
| 9 | Decompiler “delete does not return” | **Noise** — epilogue returns this |
| 10 | Product mangled sealed | **Open** |
| 11 | Runtime / bit-exact Confirmed | **Open** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes / CF / `ret 4` | **Confirmed** | Wrong teardown / stack imbalance |
| Complete path via thunk → `FUN_00578a60` | **Confirmed** | Miss skill-owned field free |
| Scalar free gate bit0 | **Confirmed** | Leak or free of non-heap HB |
| Shared multi-vtbl[0] | **Confirmed** | Invent per-class dtor bodies that do not exist |
| Distinct from `0x00578de0` | **Confirmed** | Merge base/subclass scalar slots incorrectly |
| Name “Shared…_Inferred” | **High** | Docs only; role sealed, class singular open |
| Product mangled | **Open** | Docs only |
| Runtime | **Open** | Port without live check |

---

## 3. Surviving contract for AutoCore

```
// __thiscall  ret 4  → EAX = this
void* CVOGHBSkill_SharedScalarDeletingDtor_Inferred(void* thisHb, uint8_t flags):
  FUN_00578a60(thisHb)          // via thunk 0x00548f90; complete SkillBase body
  if flags & 1:
    operator_delete(thisHb)
  return thisHb

// NOT the complete-body-only path (use FUN_00578a60).
// NOT CVOGHBSkillBase_ScalarDeletingDtor @ 0x00578de0 (base vtbl 0x009d3fdc only).
// NOT CVOGHBBase_ScalarDeletingDtor @ 0x00508630.
// Virtual delete: vtbl[0](this, 1) on many CVOGHBSkill_* subclass tables.
// Owner-null factory paths push 1 then call [vtbl+0] — free expected.
```

---

## 4. Falsification notes

### 4.1 Collapse with complete dtor

Ports that free inside `FUN_00578a60` invent scalar behavior on stack/member skill HBs destroyed without `delete`. Keep the pair split (same rule as base scalar dual).

### 4.2 Collapse with base scalar `0x00578de0`

Functionally twin pattern, **different VA** and **different vtbl hosts**. Base installs `PTR_FUN_009d3fdc[0]=0x00578de0`. Subclasses that stamp their own vtbl point slot 0 here. Do not rewrite one into the other in docs or ports.

### 4.3 “Master_ScalarDeletingDtor” singular name

RTTI on Master vtbl proves Master *uses* this slot; many other vtbls do too. Singular class name overclaims ownership. Shared + `_Inferred` survives.

### 4.4 flags bit dictionary fantasy

Only **bit 0** is tested. Do not invent array-delete behavior.

### 4.5 Thunk vs direct

Adversarial seal: document **`CALL 0x00548f90`** (JMP to `0x00578a60`), not a fictional direct CALL to `0x00578a60` in this body. Effective semantics identical to base scalar’s direct call.

---

## 5. Open questions

1. Product mangled name(s) for the COMDAT-merged scalar dtor.  
2. Full inventory of every subclass vtbl DATA xref (partial sealed).  
3. Dual residual for complete `FUN_00578a60` (not OWN).  
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** on sealed CF, ABI, shared vtbl[0] role, and complete-body path. Reject complete-dtor collapse, base-scalar VA merge, singular-class ownership, and array-delete fantasies. Product mangled + runtime open only.
