# Review B (skeptical / adversarial): `aa_0055c250` StdVector_Resize_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055c250` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-AA) |
| **Counterpart** | `reviews/A_aa_0055c250_StdVector_Resize_Elem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler signature `(vec, new_size)` only | **Falsified as complete ABI** — `RET 0x20` requires **0x1c value blob** + 4-byte size |
| 2 | Same ABI as `StdVector_Resize_Pod28` `0045c4b0` | **Falsified identity** — peer uses EBX=vec, ECX=size, **RET 0x1C**; this unit is thiscall ECX=vec, **RET 0x20** |
| 3 | Shrink destroys elements | **Falsified** — POD family; empty-range move + end rebind only |
| 4 | Grow is raw `operator_new` | **Falsified** — delegates to sealed InsertN `0055be00` |
| 5 | Scaffold VOG_DEBUG / Named_CalleeOf plate | **Reject** — structural `StdVector_Resize_Elem28` |
| 6 | Insert-one wrapper | **Falsified** — general resize; insert-one is sibling `FUN_0055c310` |
| 7 | `FUN_0055b470` four meaningful args | **Partially** — caller pushes 4 dwords / `ADD ESP,0x10`, but helper body only loads 3; 4th unused |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Resize shape | **High** | Wrong container port |
| ABI RET 0x20 + value by value | **High** | Stack corruption |
| Stride 0x1c POD | **High** | Wrong layout |
| Grow InsertN wiring | **High** | Missed reallocation policy |
| Shrink end publish | **High** | Stale end pointer |
| Product Elem28 type | **Low** | Domain labeling only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// sole caller FUN_0055a5f0 @ 0055a684:
//   resize dest vector (at cloned object) to source element count
// grow site 0055c2ae → FUN_0055be00(end, need, &value)
// shrink site → FUN_0055b470; mov [edi+8], eax
```

Live decompile 2026-08-04 ≡ scaffold raw CF. Bytes seal **RET 0x20** and value stack slot. Shrink helper entry leaves **EAX=dest** on empty range — matches end store.

---

## 4. Surviving contract for AutoCore

```
// Port as vector<Elem28>::resize(n, value) with trivial T:
// thiscall; clean 0x20 stack bytes (size + 0x1c value).
// grow: InsertN at end (W34-R policy: 1.5×, no destroy on realloc).
// shrink: end = begin + n*0x1c (no dtor loop).
// Do not merge register ABI with Resize_Pod28 @ 0045c4b0.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/grow/shrink. Residual product type + unowned neighbors → **accept-with-gaps**.
