# Review B (skeptical / adversarial): `aa_0043d420` GuardedVector_AssignDwordIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d420` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-F) |
| **Counterpart** | `reviews/A_aa_0043d420_GuardedVector_AssignDwordIfNonNull.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall / ECX dst | **Falsified** — both args from stack; plain RET |
| 2 | Multi-dword / memcpy | **Falsified** — single `MOV EDX,[ECX]; MOV [EAX],EDX` |
| 3 | Always stores | **Falsified** — `TEST EAX,EAX / JE` null gate |
| 4 | Constructs / allocates | **Falsified** — pure assign; no callees |
| 5 | Product name retail | **Overstated** — inferred `GuardedVector_AssignDwordIfNonNull` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Cdecl 2-arg + plain RET | **High** | Stack imbalance at push sites |
| Null dst skip | **High** | Spurious write / crash |
| Single dword width | **High** | Truncate/widen element |
| Role as push store leaf | **High** | Wrong assign path in port |
| Product English | **Inferred** | Naming only |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if (param_1) *param_1 = *param_2;

bytes:
  MOV EAX,[ESP+4]; TEST EAX,EAX; JE skip
  MOV ECX,[ESP+8]; MOV EDX,[ECX]; MOV [EAX],EDX
  RET
```

Callers only W31-I thiscall push pair (after page resolve). Live ≡ raw. Full 17 B hex sealed.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector element assign leaf:
//   stack dst*, src*; plain RET (cdecl)
//   if dst: *dst = *src  (one dword)
// Do not invent thiscall, memcpy, or construct-on-null.
// Do not drop null check — bytes honor it even after page alloc.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/width/role; product residual only → **accept**.
