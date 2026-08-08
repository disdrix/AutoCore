# Review B (skeptical / adversarial): `aa_0040a590` StdVector_UninitializedCopy_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9K-J) |
| **Counterpart** | `reviews/A_aa_0040a590_StdVector_UninitializedCopy_Elem12_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | True `__thiscall` on vector object (ECX=this) | **Falsified** — ECX is **src_end**; no reads of vector begin/end/capacity fields |
| 2 | Element stride 0x28 / merge with `0040a520` | **Falsified** — both cursors `ADD …,0xC`; leaf is `00409f50` not `00409f30` |
| 3 | In-place assign / fill-n (not copy) | **Falsified** — two independent cursors src→dest; returns advanced dest |
| 4 | Destructors / non-POD construct | **Falsified** — sole callee is POD PodCopy leaf |
| 5 | `ret 0xC` / stdcall stack cleanup | **Falsified** — plain `C3`; callers `ADD ESP,0x10` |
| 6 | Same as ConstructN loop `00409db0` | **Falsified** — ConstructN is count-driven single-value fill; this is range-to-range |
| 7 | Merge with leaf PodCopy `00409f50` | **Falsified** — leaf is single-element; this advances both cursors |
| 8 | Merge with `StdUninitCopy_Pod28` (`0045f360`, elem 0x1c) | **Falsified** — different size/ABI/family |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x0C range uninit_copy CF | **Confirmed** | Wrong relocate on insert |
| ECX=end / stack begin,dest | **Confirmed** | Arg swap corruption |
| PodCopy leaf linkage | **Confirmed** | Wrong element size / ABI |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against PodCopy leaf + InsertN + twin

```
// WQ9J-A sealed FUN_00409f50: EAX dest, ECX src, 3 dwords / 0x0C
// This OWN unit sets EAX=EDI, ECX=ESI each iteration then CALL 00409f50.
// FUN_004082f0 uses return as new vector.end on tail-shift arm (@00408556).
// Twin FUN_0040a520: same skeleton; ADD 0x28 + leaf 00409f30 (EDX src) — keep distinct.
// Trampoline 00409b40: reorders args then CALL; RET 8 (not dualed here).
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared vector uninitialized_copy for stride 0x0C:
//  - while (begin != end) { PodCopyElem12(dest, begin); begin+=0x0C; dest+=0x0C; }
//  - ABI: ECX=end, stack begin+dest, EAX=dest_end, plain ret
//  - Pair with PodCopy 00409f50, ConstructN 00409db0, InsertN 004082f0
// Do not merge with Elem0x28 range 0040a520 or Pod28 UninitCopy 0045f360.
// PodCopy Elem12 uses ECX src — not EDX (0x28 leaf trap).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/leaf. Product + parent residual → **accept-with-gaps**.
