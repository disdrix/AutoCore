# Review B (skeptical / adversarial): `aa_00466df0` StdVector_Resize_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00466df0` |
| **VA** | `0x00466df0` |
| **Canonical name** | `StdVector_Resize_Elem28_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial (OWN-ONLY W36-P) |
| **Counterpart** | `reviews/A_aa_00466df0_StdVector_Resize_Elem28_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + xrefs only. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Is this InsertN itself? | **No** — thin resize shell; grow calls sealed `00466ea0` |
| 2 | ABI is ECX=vec thiscall like BasicString | **No** — **EBX=vec**, **ECX=new_size**, **RET 0x1C** |
| 3 | Value is a pointer on stack | **No** — `RET 0x1C` + `LEA` into stack blob; **by value** |
| 4 | This is `reserve` / capacity only | **No** — shrink erases; grow inserts at end with fill |
| 5 | Stride is not 0x1c | **No** — magic `0x92492493` + `new_size*0x1c` lea sealed |
| 6 | Same drop-in as Pod28 resize `0045c4b0` | **Structural twin, different grow callee** — CountEcx InsertN (`00466ea0`) vs Pod28 InsertN (`0045cd30`) |
| 7 | Decompiler shows full InsertN formals | Incomplete — **bytes win**: ECX=count, EDX=vec, stack where+value* |
| 8 | Scaffold `Named_CalleeOf_*anmAnimMaster*` is product | **Rejected** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX/ECX/stack RET 1C ABI | **High** | Wrong port linkage / stack smash |
| Grow InsertN CountEcx wiring | **High** | Silent wrong insert path |
| Shrink erase via `0045cce0` | **High** (call formals); helper dual open | Truncation semantics residual |
| Product demangle / T English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against Pod28 twin + sealed InsertN

```
// Structural twin StdVector_Resize_Pod28 (0x0045c4b0, W35-M):
//   same EBX/ECX/RET 1C / magic / grow-or-shrink CF
//   grow callee = 0045cd30 (Pod28 InsertN)
// This unit grow callee = 00466ea0 (Elem28 CountEcx InsertN, W34-Q)
// Sole parent of 00466ea0 was listed as FUN_00466df0 — now owned.
```

Full 162 B hex matches length of Pod28 resize twin; both epilogues `C2 1C 00`.

---

## 4. Surviving contract for AutoCore

```
// Retail ABI helper — do not invent thiscall/RET C:
void resize(VectorElem28* vec /*EBX*/, uint32_t n /*ECX*/, Elem28 value /*stack 0x1c*/) {
  size = begin ? (end-begin)/0x1c : 0;
  if (size < n) InsertN_CountEcx(n-size, vec, end, &value); // RET 1C after
  else if (begin && n < size) erase(vec, begin+n*0x1c, end);
  // RET 1C
}
// Pair with sealed InsertN CountEcx; do not conflate with Pod28 or BasicString resize.
```

---

## 5. Verdict

Adversarial pass confirms A on resize contract and distinguishes Pod28 twin by grow callee. Residual product English / erase dual / parent dual do not block → **accept-with-gaps**.
