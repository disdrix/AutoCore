# Review B (skeptical / adversarial): `aa_0043e080` GuardedVector_InsertN_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e080` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-F) |
| **Counterpart** | `reviews/A_aa_0043e080_GuardedVector_InsertN_Thiscall.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same ABI as W29-A InsertN (ECX=N) | **Falsified** — entry `MOV ESI,ECX` container; N from `[ebp+0x10]` |
| 2 | Uses EAX push pair (ce10/c830) | **Falsified** — calls thiscall `0043e3d0` / `0043d670` |
| 3 | Flat `vector::insert` | **Falsified** — page map walks + ring absolute indices |
| 4 | Always push_back only | **Falsified** — 4-arm shorter-side; front arms present |
| 5 | Decompiler thiscall on e080 is wrong | **Falsified** — bytes + sole-caller preserve ECX container |
| 6 | Product name retail | **Overstated** — inferred `GuardedVector_InsertN_Thiscall` |
| 7 | Nested e910/ebb0/ec50 fully sealed | **Overstated** — residual free (gap) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX container + RET 0x10 | **High** | Wrong object / stack corrupt |
| N on stack (not ECX) | **High** | Count/object swap with W29-A twin |
| Shorter-side polarity | **High** | Corrupts ring order |
| Thiscall push callees | **High** | Wrong grow/page ABI |
| Nested range helpers | **Medium** | Mid-insert mis-move |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Alloc / SEH races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  prefix = insert_at - begin; suffix = size - prefix
  front: e3d0 (PushFront_Thiscall) ± ec50/e910
  back:  d670 (PushBack_Thiscall) ± ebb0/e910

bytes:
  MOV ESI, ECX
  … RET 0x10 (multiple)
  CALL 0043e3d0 / 0043d670 with MOV ECX,ESI
```

Sole caller `0043d940` grow: `insert_at = begin+size` → back-biased excess-push arm.

Polarity vs W29-A twin: same 4-arm algorithm; **ABI and push family differ** (thiscall container + thiscall push vs ECX=N + EAX push).

---

## 4. Surviving contract for AutoCore

```
// GuardedVector insert-N (thiscall body):
//   ECX = container
//   stack = seed, insert_at, N, fill*; RET 0x10
//   shorter-side: PushFront_Thiscall / PushBack_Thiscall
//   then e910 fill or ebb0/ec50 move + fill
// Do NOT reuse W29-A InsertN ABI (ECX=N) on thiscall sites.
// Do NOT invent flat vector::insert without page map + absolute index.
// Nested e910/ebb0/ec50 remain free until owned duals seal them.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/push polarity; nested range residual keeps **accept-with-gaps**.
