# Review B (skeptical / adversarial): `aa_0040a520` StdVector_UninitializedCopy_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040a520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9J-A) |
| **Counterpart** | `reviews/A_aa_0040a520_StdVector_UninitializedCopy_Elem0x28_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | True `__thiscall` on vector object (ECX=this) | **Falsified** — ECX is **src_end**; no reads of vector begin/end/capacity fields |
| 2 | Element stride 0x0C / Elem12 range | **Falsified** — both cursors `ADD …,0x28`; leaf is `00409f30` not `00409f50` |
| 3 | In-place assign / fill-n (not copy) | **Falsified** — two independent cursors src→dest; returns advanced dest |
| 4 | Destructors / non-POD construct | **Falsified** — sole callee is POD PodCopy leaf |
| 5 | `ret 0xC` / stdcall stack cleanup | **Falsified** — plain `C3`; callers `ADD ESP,0x10` |
| 6 | Same as ConstructN loop | **Falsified** — ConstructN is count-driven single-value fill; this is range-to-range |
| 7 | Merge with UiToast UninitCopy 0x98 | **Falsified** — different VA/stride/leaf |
| 8 | Merge with `StdUninitCopy_Pod28` (`0045f360`, elem 0x1c) | **Falsified** — different size/ABI/family |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x28 range uninit_copy CF | **Confirmed** | Wrong relocate on insert |
| ECX=end / stack begin,dest | **Confirmed** | Arg swap corruption |
| PodCopy leaf linkage | **Confirmed** | Wrong element size |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against PodCopy leaf + InsertN

```
// WQ9I-B sealed FUN_00409f30: EAX dest, EDX src, 10 dwords / 0x28
// This OWN unit sets EAX=EDI, EDX=ESI each iteration then CALL 00409f30.
// FUN_00408050 uses return as new vector.end on tail-shift arm (@004082bb).
// Twin FUN_0040a590 is Elem12 (+0x0C / leaf 00409f50) — keep distinct.
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared vector uninitialized_copy for stride 0x28:
//  - while (begin != end) { PodCopy0x28(dest, begin); begin+=0x28; dest+=0x28; }
//  - ABI: ECX=end, stack begin+dest, EAX=dest_end, plain ret
//  - Pair with PodCopy 00409f30, ConstructN 00409d40, InsertN 00408050
// Do not merge with Elem12 range 0040a590 or Pod28 UninitCopy 0045f360.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/leaf. Product + parent residual → **accept-with-gaps**.
