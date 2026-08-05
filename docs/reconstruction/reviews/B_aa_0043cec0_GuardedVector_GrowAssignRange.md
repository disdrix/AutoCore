# Review B (skeptical / adversarial): `aa_0043cec0` GuardedVector_GrowAssignRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-C) |
| **Counterpart** | `reviews/A_aa_0043cec0_GuardedVector_GrowAssignRange.md` |
| **Scratch** | `tmp/a_0043cec0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Non-trivial grow logic in this VA | **Falsified** — single CALL + RET |
| 2 | Plain RET / cdecl | **Falsified** — `RET 0x1c` stdcall 7 args |
| 3 | Multiple callers | **Falsified** — sole xref from `FUN_0043c730` grow |
| 4 | 8th arg is unrelated | **Falsified** — bytes re-push `param_1` |
| 5 | Name is PDB-proven | **Overstated** — structural Inferred only |
| 6 | FUN_0043cf40 sealed by this dual | **Rejected** — not OWN; residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Trampoline CF / RET 0x1c | **High** | Stack imbalance |
| 8th-arg duplicate | **High** | Wrong dest self-ref in grow worker |
| Sole grow-path role | **High** | Mis-wire assign |
| Nested grow free | **Out of scope** | Element construct |
| Product English | **Inferred** | Naming only |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  FUN_0043cf40(p1,p2,p3,p4,p5,p6,p7,p1); return;

bytes (48 B):
  load p1/p7/p6 … push chain … CALL +0x53 → 0043cf40
  RET 0x1c
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Parent grow call:

```
FUN_0043cec0(dest, dest, dest.size+dest.begin,
             source, source.begin+dest.size,
             source, source.size+source.begin);
```

---

## 4. Surviving contract for AutoCore

```
// Grow path under GuardedVector_CopyAssign when source.size > dest.size:
//   GuardedVector_GrowAssignRange(dest, dest, dest_end,
//                                 source, src_mid, source, src_end)
//   ≡ FUN_0043cf40(..., dest)  // 8th = dest again
// Port may inline the trampoline; must preserve 8-arg worker contract.
```

---

## 5. Verdict

Adversarial pass **confirms** A: body is a pure trampoline with no CF residual → **accept**. Nested `0043cf40` remains a separate residual unit.
