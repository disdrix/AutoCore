# Review B (skeptical / adversarial): `aa_00469db0` AssResolverCore_HeadBag_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469db0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-E) |
| **Counterpart** | `reviews/A_aa_00469db0_AssResolverCore_HeadBag_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall | **Falsified** — stack self; `RET 4` (`C2 04 00`) |
| 2 | Installs AssResolverCore vtbl | **Falsified** — no vtbl store; parent/shell owns outer vtbl |
| 3 | Same object layout start as Resolver-A whole object | **Falsified** — twin of **member** `FUN_00423cf0`, but invoked on AssResolverCore **base** |
| 4 | Scalar-deleting dtor | **Falsified** — returns self; no free |
| 5 | Capacity 9 is byte count | **Falsified** — `FUN_004646e0` does `count*4` alloc → 9 pointer slots |
| 6 | Product PDB name sealed | **Careful** — `_Inferred` only; reject assManager scaffold alias plate |
| 7 | Multiple callers | **Falsified** — sole `FUN_00983940` @ `0x0098395d` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong CC / stack pop |
| Offsets +0x08..+0x24 | **High** | Corrupt core head |
| Vector capacity 9 | **High** | Underrun reserve |
| Nested fill semantics | **Med** | Wrong initial slot contents |
| Product English | **Low** | Wrong subsystem label |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_00983940 @ 0x0098395d:
//   push self; call FUN_00469db0   // only static xref
// Twin FUN_00423cf0: same decompile shape (00423d60 + 004646e0(...,9,...))
// Bytes: 6A 09 ... 8D 56 10 ... E8 (004646e0); B8 01 ... 89 46 20 / 24; C2 04 00
```

---

## 4. Surviving contract for AutoCore

```
// Port as stack placement ctor, RET 4:
HeadBag* ctor(HeadBag* self) {
  void* head = SentinelNode_New28_Circular(); // FUN_00423d60
  self->list_head = head;  // +0x08
  self->list_aux  = 0;     // +0x0c
  PtrVec_ReserveFill(self+0x10, /*count=*/9, &head); // FUN_004646e0
  self->flag_20 = 1;
  self->flag_24 = 1;
  return self;
}
// Do not call as ECX-thiscall. Do not invent vtbl write. Do not claim PDB English.
// Pair with AssResolverCore_Ctor_Inferred (W31-G) which calls this first.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/caller/twin. Nested product + flag meaning residual → **accept-with-gaps**.
