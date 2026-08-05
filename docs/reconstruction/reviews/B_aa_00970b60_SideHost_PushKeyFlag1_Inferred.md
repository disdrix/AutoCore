# Review B (skeptical / adversarial): `aa_00970b60` SideHost_PushKeyFlag1_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970b60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-N) |
| **Counterpart** | `reviews/A_aa_00970b60_SideHost_PushKeyFlag1_Inferred.md` |
| **Scratch** | `tmp/a_00970b60.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Distinct large function vs `00970b20` | **Falsified** — 54 B bit-twin; only flag imm + rel32 |
| 2 | Decompiler void signature complete | **Falsified** — same RET 4 / ECX / stack host as twin |
| 3 | Multi-caller general helper | **Nuanced** — **1** xref only; still same ABI as multi-caller twin |
| 4 | “Log string” on miss | **Falsified** — U32U8 locked vector push, not string I/O |
| 5 | Flag always 1 at runtime from host field | **Falsified** — imm **`6A 01`** |
| 6 | Product name sealed | **Overstated** — inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Twin of flag0 with imm=1 | **High** | Event kind swap |
| Sole NDResource miss site | **High** | Miss other xrefs (none found) |
| host+0xAC push | **High** | Wrong field |
| Product “miss log” English | **Inferred** | Naming only |
| Runtime | **Open** | CS races nested |

---

## 3. Cross-check against raw + bytes

```
bytes (54 B):
  … 6A 01 … E8 75 DD AC FF … 81 C7 AC 00 00 00 E8 62 DC AC FF …
  … C2 04 00

vs 00970b20:
  … 6A 00 … E8 B5 DD AC FF … 81 C7 AC 00 00 00 E8 A2 DC AC FF …

call site 0075dceb:
  8B 56 6C  52  8B CD  E8 70 2E 21 00   ; push [esi+0x6c]; ecx=ebp; call 00970b60
```

Rel32 targets resolve to same `0043e8f0` / `0043e7f0` as twin (entry +0x40).

---

## 4. Residual attacks left open

- Whether flag 1 uniquely means “alt miss” product-wide.
- Whether EBP at call site is always a key holder with key at +0.

None overturn structural seal → **accept-with-gaps**.
