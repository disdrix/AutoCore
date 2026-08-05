# Review B (skeptical / adversarial): `aa_00996bc0` Host54_NestedHash0xC_At28_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00996bc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-S) |
| **Counterpart** | `reviews/A_aa_00996bc0_Host54_NestedHash0xC_At28_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — stack self; `RET 4` |
| 2 | Decompiler void signature full ABI | **Falsified** — stack this*, returns this |
| 3 | NestedHash at object base like `0096eec0` | **Falsified** — NestedHash at **`+0x28`** only |
| 4 | Writes all prefix through +0x24 | **Partial** — **`+0x18` never written** (sealed gap) |
| 5 | Size is NestedHash 0x28 only | **Falsified** — host span **0x54** from caller CS placement |
| 6 | Has singleton / atexit / map register like sibling | **Falsified** — only NestedHash + prefix zeros |
| 7 | Capacity 8 is NestedHash bucket count | **Falsified** — NestedHash uses count **9** (W34-F); **8** is prefix field `+0x10` |
| 8 | `param_1[0x14]` in decompile is byte offset 0x14 flag | **Careful** — decompiler `param_1 + 0x14` as **dword*** → byte **`+0x50`**; sealed by `C6 46 50 01` |
| 9 | Multiple exclusive hosts | **Falsified** — single code xref `FUN_00989cf0` |
| 10 | Product English for “pool/list header” | **Low** — structural zeros+capacity only; `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong convention |
| NestedHash @ +0x28 | **High** | Overlap |
| Span 0x54 | **High** | Outer host layout |
| Prefix + capacity 8 | **High** | Field meaning wrong (not layout) |
| Unwritten +0x18 | **High** as fact | Later writer assumes zeroed |
| Product prefix English | **Low** | Naming |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_00989cf0:
//   zero host+4..+0xc
//   FUN_00996bc0(host + 0x14)
//   InitializeCriticalSection(host + 0x68)
//   *(host + 0x80) = 1
// span: 0x68 - 0x14 = 0x54
```

Full **94 B** hex: prefix stores, `LEA EAX,[ESI+0x28]; PUSH; CALL FUN_0043fdf0`, `MOV byte [ESI+0x50],1`, `RET 4`.

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
Host54* ctor(Host54* self) {
  zero_prefix_except_0x18(self);  // +0x10 = 8
  NestedHash_Ctor_Sentinel0xC(self + 0x28);
  self->flag50 = 1;
  return self;
}
// RET 4; embed at outer+0x14; do not assume +0x18 was zeroed here.
// Do not invent product English; do not place NestedHash at +0.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/NestedHash-at-+0x28/span/flag. Residual product plate + unwritten +0x18 intent → **accept-with-gaps**.
