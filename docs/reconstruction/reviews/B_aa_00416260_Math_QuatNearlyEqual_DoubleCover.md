# Review B (skeptical / adversarial): `aa_00416260` Math_QuatNearlyEqual_DoubleCover

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-A) |
| **Counterpart** | `reviews/A_aa_00416260_Math_QuatNearlyEqual_DoubleCover.md` |
| **Scratch** | `tmp/a_00416260.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Only compares q to q (no double cover) | **Falsified** — second block negates ESI components and retests all four |
| 2 | Negation is of EDI not ESI | **Falsified** — `SUBSS` from `[esi+off]`; EDI components stay positive leaf formals |
| 3 | This is a normalize / slerp helper | **Falsified** — pure predicate; no writes to a/b; only leaf nearness |
| 4 | Pure cdecl | **Falsified** — ESI/EDI + `RET 8` (same as vec3 sibling) |
| 5 | wxyz layout with w at [0] | **Falsified** — first load is `[esi+0xc]` / `[edi+0xc]` (index 3), then 0,1,2 |
| 6 | Product name is retail string | **Overstated** — inferred from double-cover math role |
| 7 | 0.002f is hardcoded inside function | **Falsified** — tols are stack formals; caller pushes `0x3B03126F` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Double-cover CF | **High** | Miss opposite-hemisphere quat equality |
| ESI/EDI + RET 8 ABI | **High** | Port ABI break |
| Component order w,x,y,z | **High** | Wrong axis mapping only if layout mislabeled |
| Product English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller

```
ESI=a, EDI=b
if all NearlyEqual(b[i], a[i]) for i in (3,0,1,2): return 1
if all NearlyEqual(b[i], -a[i]) for i in (3,0,1,2): return 1
return 0
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Caller `0x008335da`: stack quat copy from `+0x590`, EDI=`+0x5e0`, both tols **0.002f**; on true clears `+0x5dc`.

---

## 4. Surviving contract for AutoCore

```
// Prefer double-cover quat equality for client orientation parity:
near = Math_QuatNearlyEqual_DoubleCover(a, b, relTol, absTol)
// true if b≈a OR b≈-a under abs+rel per component
// observed client eps 0.002f (0x3B03126F) for both tols
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/double-cover semantics sealed; product name residual only → **accept**.
