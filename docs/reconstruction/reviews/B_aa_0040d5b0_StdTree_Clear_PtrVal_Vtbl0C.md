# Review B (skeptical / adversarial): `aa_0040d5b0` StdTree_Clear_PtrVal_Vtbl0C

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d5b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-P) |
| **Counterpart** | `reviews/A_aa_0040d5b0_StdTree_Clear_PtrVal_Vtbl0C.md` |
| **Scratch** | `tmp/a_0040d5b0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only iterator++ | **Falsified** — Inc is callee; body also destroys values and frees nodes |
| 2 | Decompiler free path is complete | **Falsified** — false noreturn on `operator_delete`; bytes show left-walk loop + `FUN_0040d630(right)` |
| 3 | Value is inline object (LEA this) | **Falsified** — `MOV ECX,[node+0x14]` loads pointer, then `MOV EAX,[ECX]; CALL [EAX+0x0C]` |
| 4 | This frees `T*` after vtbl call | **Falsified** — no `operator_delete` on value pointer; only node frees |
| 5 | cdecl / stack this | **Falsified** — `MOV ESI,ECX`; bare `C3` |
| 6 | Not Val12 family | **Falsified** — isnil@+0x19; Inc = sealed `StdTree_Inc_Val12` |
| 7 | Scalar-deleting dtor of host | **Falsified** — no flags arg; host free is parent `FUN_0040d590`/`FUN_0040d820` chain |
| 8 | Name claims product plate | **Careful** — structural only; no PDB English sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clear vs erase-one | **High** | Wrong container teardown |
| Pointer value + vtbl[+0xc] | **High** | Missed destroy / wrong call |
| Free loop shape | **High** | Leak / double free |
| Head@+8 size@+0xc | **High** | Corrupt wrong fields |
| Product T / method name | **Low** | Naming only |
| Nested `FUN_0040d630` full body | **Med** | Partial free residual |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Complete dtor parent FUN_0040d820:
*this = PTR_FUN_009c7938;
FUN_0040d5b0(this);   // clear tree@+8
FUN_0040d7c0(this);   // other member teardown

// vtbl[2] @ 0x009c7940 also points here (virtual clear path)
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 for value loop. Full 123 B hex seals free loop decompiler missed.

---

## 4. Surviving contract for AutoCore

```
// Port as tree CLEAR (not single erase):
void StdTree_Clear_PtrVal_Vtbl0C(Tree* t) {
  for (it = begin; it != end; ++it)
    it.value_ptr->vtbl[3]();   // no delete T*
  free all nodes (right-subtree helper + left walk)
  reset sentinel; size = 0
}
// Pair with sealed StdTree_Inc_Val12. Do not invent product map type.
// Do not trust Ghidra noreturn after first operator_delete.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout/free-loop. Residual product types + nested free helper → **accept-with-gaps**.
