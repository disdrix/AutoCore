# Review B (skeptical / adversarial): `aa_00409f50` StdVector_PodCopyElement_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409f50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9J-A) |
| **Counterpart** | `reviews/A_aa_00409f50_StdVector_PodCopyElement_Elem12_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same ABI as PodCopy 0x28 (`00409f30` EAX/EDX) | **Falsified** — this leaf is **EAX dest / ECX src**; peer is EAX/EDX |
| 2 | 10-dword / 0x28 copy | **Falsified** — exactly **3** dword stores (0x0C) |
| 3 | Stack thiscall ECX=this | **Falsified** — ECX is **src**, not a vector object; no stack args |
| 4 | ConstructN itself (loop) | **Falsified** — leaf only; ConstructN is `00409db0` |
| 5 | Always copies even on null dest | **Falsified** — `TEST EAX` / `JZ` skip |
| 6 | Non-POD ctor (vftable / deep copy) | **Falsified** — pure dword stores |
| 7 | Multi-arg stdcall / `ret N` | **Falsified** — bare `C3` |
| 8 | Merge with range worker `0040a590` | **Falsified** — range advances both cursors; this is single-element |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 3-dword leaf copy | **Confirmed** | Wrong element size |
| EAX/ECX ABI | **Confirmed** | Corrupt ConstructN Elem12 |
| Null dest no-op | **Confirmed** | Spurious write |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against ConstructN parent

```
// WQ9I-A sealed FUN_00409db0:
//   loop: PodCopy(EAX=dest, ECX=value); dest += 0x0C
// This OWN unit is exactly that PodCopy leaf (3 dwords).
// Range twin FUN_0040a590: same call shape; advances both cursors +0x0C.
// ADV_wq9i F2: do not share EAX/EDX ABI with PodCopy 0x28.
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared POD element copy for stride 0x0C:
//  - if (dest) memcpy(dest, src, 0x0C) via 3 dwords
//  - ABI: EAX=dest, ECX=src, plain ret
//  - Pair with ConstructN 00409db0 / Ufill 00406ee0 / push_back 004062a0
// Do not merge with 0x28 PodCopy leaf 00409f30 (EDX src / 10 dwords).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/size. Product residual → **accept-with-gaps**.
