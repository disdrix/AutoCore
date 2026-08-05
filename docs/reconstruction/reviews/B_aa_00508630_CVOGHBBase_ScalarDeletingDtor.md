# Review B (skeptical / adversarial): `CVOGHBBase_ScalarDeletingDtor` / `FUN_00508630` @ `0x00508630`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00508630_CVOGHBBase_ScalarDeletingDtor.md` |
| **Verdict** | **accept** on CF/ABI/vtbl/unlink/free; **needs-more-evidence** only on product mangled symbol |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Same as complete dtor `0x00508390` | **Falsified** — this adds `(flags&1)` + `operator_delete` + `ret 4` |
| 2 | Bare `ret` / no stack arg | **Falsified** — `ret 4`; flags at `[esp+8]` after push |
| 3 | Always frees | **Falsified** — free only when bit0 set |
| 4 | Unlink is thiscall on HB | **Falsified** — machine sets **ECX = listMgr**, pushes HB |
| 5 | Vtbl restore skipped when owner null | **Falsified** — store is **before** owner jz |
| 6 | Different vtbl than ctor | **Falsified** — same imm `0x009cdab0` |
| 7 | Decompiler `param_1[6]` is wrong offset | **Falsified** — index 6 × 4 = **+0x18** ≡ `pOwnerObject` |
| 8 | Product mangled name sealed | **Open** |
| 9 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes / CF | **Confirmed** | Wrong teardown order |
| Base vtbl imm | **Confirmed** | Wrong vtbl family |
| listMgr ECX for unlink | **Confirmed** | Double-free / list corruption if ported as HB-this |
| Scalar free gate | **Confirmed** | Leak or free of stack HB |
| Class family CVOGHBBase | **High** | Mis-wire to unrelated scalar dtor |
| Product mangled | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// __thiscall  ret 4  → EAX = this
void* CVOGHBBase_ScalarDeletingDtor(CVOGHBBase* this, uint8_t flags):
  owner = this->pOwnerObject          // +0x18
  this->pVTable = &PTR_FUN_009cdab0   // ALWAYS
  if owner && listMgr = *(owner+0xB0):
    FUN_005085b0(listMgr, this)       // ECX=listMgr, stack=this
  if flags & 1:
    operator_delete(this)
  return this

// NOT the complete-body-only path (use CVOGHBBase_dtor @ 0x00508390).
// NOT a free-without-unlink helper.
// Virtual delete goes through vtbl[0] = this VA.
```

---

## 4. Falsification notes

### 4.1 Collapse with complete dtor

Ports that free inside `CVOGHBBase_dtor` invent scalar behavior on stack/member HB objects destroyed without `delete`. Keep the pair split.

### 4.2 Wrong callee this

Decompiler shows `FUN_005085b0(this)`. Machine is `listMgr` thiscall. Ports that call remove-by-key with HB as ECX will corrupt the wrong object (same trap sealed on complete dtor dual).

### 4.3 flags bit dictionary fantasy

Only **bit 0** is tested. Do not invent array-delete (`flags&2`) behavior — body has no array cookie / multi-element loop.

### 4.4 Order nit (owner load vs vtbl store)

Machine loads owner into EAX, tests, **then** stores vtbl, then jz. Decompiler lists vtbl store first. Observable single-thread result is identical; adversarial take: preserve machine order in assembly-faithful notes, either order OK for clean C.

---

## 5. Open questions

1. Product mangled name.
2. Runtime / bit-exact.

**Verdict:** **accept** on sealed CF, ABI, vtbl restore, list unlink (listMgr this), and scalar free. Reject complete-dtor collapse and HB-as-listMgr fantasies. Product mangled open only.
