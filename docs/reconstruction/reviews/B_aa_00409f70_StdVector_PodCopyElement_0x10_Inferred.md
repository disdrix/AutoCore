# Review B (skeptical / adversarial): `aa_00409f70` StdVector_PodCopyElement_0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409f70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R10-023) |
| **Counterpart** | `reviews/A_aa_00409f70_StdVector_PodCopyElement_0x10_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same ABI as PodCopy 0x28 (`00409f30` EAX/EDX) | **Falsified** — this leaf is **EAX dest / ECX src**; peer is EAX/EDX |
| 2 | 3-dword / 0x0C or 10-dword / 0x28 copy | **Falsified** — exactly **4** dword stores (0x10) |
| 3 | Stack thiscall ECX=this / PollBound input leaf | **Falsified** — ECX is **src**, not a vector/object this; no stack args; pure POD stores |
| 4 | ConstructN itself (loop / SEH) | **Falsified** — leaf only; ConstructN is `00409e20` |
| 5 | Always copies even on null dest | **Falsified** — `TEST EAX` / `JZ` skip |
| 6 | Non-POD ctor (vftable / deep copy) | **Falsified** — pure dword stores; no calls |
| 7 | Multi-arg stdcall / `ret N` | **Falsified** — bare `C3` |
| 8 | Merge with range worker `0040a670` | **Falsified** — range advances both cursors + returns end; this is single-element |
| 9 | Merge with Elem12 PodCopy `00409f50` | **Falsified** — same ABI family but **3** dwords / 0x0C vs **4** / 0x10 |
| 10 | Scaffold Named_CalleeOf_*PollB product role | **Falsified** — structural PodCopy only; parent chain is vector ConstructN |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 4-dword leaf copy | **Confirmed** | Wrong element size / stride mismatch |
| EAX/ECX ABI | **Confirmed** | Corrupt ConstructN Elem0x10 |
| Null dest no-op | **Confirmed** | Spurious write |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against ConstructN parent

```
// MEGA-044 sealed FUN_00409e20:
//   loop: PodCopy(EAX=dest, ECX=value); dest += 0x10
// This OWN unit is exactly that PodCopy leaf (4 dwords).
// Range twin FUN_0040a670: same call shape; advances both cursors +0x10; returns dest end.
// Do not share EAX/EDX ABI with PodCopy 0x28 (00409f30).
// Do not claim product PollBound / input binding role from scaffold name.
```

---

## 4. Surviving contract for AutoCore

```
// Port as shared POD element copy for stride 0x10:
//  - if (dest) memcpy(dest, src, 0x10) via 4 dwords
//  - ABI: EAX=dest, ECX=src, plain ret
//  - Pair with ConstructN 00409e20 / InsertN 00408640 / range 0040a670
// Do not merge with 0x28 PodCopy leaf 00409f30 (EDX src / 10 dwords).
// Do not merge with Elem12 PodCopy leaf 00409f50 (3 dwords / 0x0C).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/size. Product residual → **accept-with-gaps**.
