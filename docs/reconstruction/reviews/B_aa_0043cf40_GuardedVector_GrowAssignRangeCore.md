# Review B (skeptical / adversarial): `aa_0043cf40` GuardedVector_GrowAssignRangeCore

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cf40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-B) |
| **Counterpart** | `reviews/A_aa_0043cf40_GuardedVector_GrowAssignRangeCore.md` |
| **Scratch** | `tmp/a_0043cf40.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | 7-arg stdcall only (decomp formals) | **Falsified** — `RET 0x20` + trampoline 8th push |
| 2 | Multiple external callers | **Falsified** — sole xref `0043cec0` |
| 3 | Flat memcpy assign | **Falsified** — 4-way tree + ce10/c830/d300/d390 |
| 4 | ce10/c830 are destroys only | **Overstated** — they construct/push (and may grow map via `0043c9b0`); used here for excess/residual element ops |
| 5 | Nested d300/d390 sealed by this dual | **Rejected** — not OWN free residual |
| 6 | Product name retail string | **Overstated** — inferred from `GuardedVector_*` + grow trampoline |
| 7 | No SEH | **Falsified** — SEH cookie `LAB_009be0b0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 0x20 / 8 args | **High** | Stack corrupt after grow assign |
| Sole caller | **High** | Missed alternate grow entry |
| prefix/suffix tree | **High** | Wrong residual elements |
| Nested move free | **Medium** | Element order wrong |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | SEH / allocator paths |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  prefix/suffix vs src_len; four arms; final d390

bytes:
  entry SEH 55 8B EC 6A FF 68 B0 E0 9B 00 …
  epilogue C2 20 00
  trampoline: … E8 53 00 00 00 C2 1C 00  → CALL this; parent cleans 7
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Parent W27-C seals 7→8 arg forward.

---

## 4. Surviving contract for AutoCore

```
// Grow-assign core (after GuardedVector_GrowAssignRange trampoline):
//   stdcall 8 args; RET 0x20; dest in p1 (and p8)
//   prefix = bound - begin; suffix = size - prefix; src_len = end - begin_src
//   shorter-side construct/destroy then ring move (d300/d390)
// Do not invent flat memcpy grow-assign; preserve 4-way policy.
// Nested move free remains residual until 0043d300/0043d390 owned.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/sole-caller; nested move + product residual → **accept-with-gaps**.
