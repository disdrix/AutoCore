# Review B (skeptical / adversarial): `aa_007a4170` Rng_SampleUnitFloat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4170` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_007a4170_Rng_SampleUnitFloat_Inferred.md` |
| **Agent** | WQ9D-F OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on behavior/ABI; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function returns void / integer only | **Falsified** — `fild`/`fmul`/`ret 4`; decomp `float10` |
| 2 | Always advances cursor | **Falsified** — indexed arm no store to `+0xC` |
| 3 | Scale is exactly `1/65536` (`0x37800000`) | **Falsified** — bytes `80 00 80 37` = `0x37800080` ≈ 1/65535 |
| 4 | Same function as CopyUnitTableWindow | **Falsified** — no movs window; float out; ret 4 not 8 |
| 5 | Table stride is dword (`*4`) | **Falsified** — `*2` ushort indexing |
| 6 | Wrap threshold `0x80000` | **Falsified** — compare imm `0x100000` |
| 7 | Is `CVOGReaction_RandomUnitScalar` | **Falsified** — getter is `0x007a4330`; this is sample method |
| 8 | Product name known | **Unproven** — `_Inferred` |
| 9 | Runtime Confirmed without Launcher | **Rejected** |
| 10 | Only used from skill FireTail | **Falsified** — callers `FUN_00508a00` + `0x0057ed44` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sequential vs indexed split | **Confirmed** | Wrong cursor churn |
| Scale constant | **Confirmed** | Systematic RNG bias in ports |
| Host `+0x08/+0x0C` | **Confirmed** | OOB / wrong object |
| `ret 4` | **Confirmed** | Stack imbalance |
| Product name | Inferred | Cosmetic |
| All call-site index literals | Open | Port default `-1` may miss indexed uses |

---

## 3. Cross-check

```
007a4170:  index<0 → wrap cursor; load u16; cursor++; fmul scale; ret 4
           index>=0 → mask 0x800fffff; maybe signed wrap; load u16; fmul; ret 4
0051b720:  copy nWords u16; cursor+1; EAX=old cursor; ret 8
007a4330:  lazy-init; return &DAT_00d20c1c
00508a31:  call getter; mov ecx,eax; call 007a4170; fmul base float
DAT_00aaa638: 80 00 80 37 → ~1.525902e-05 ≈ 1/65535
```

**Attack on “scale is 1/65536”:** IEEE bits are not `0x37800000`. Sibling docs sometimes approximate 1/65536 — seal exact float here.

**Attack on “indexed wrap is dead”:** bytes present both arms; even if live callers mostly use sequential, keep the mask path for bit-faithful ports.

---

## 4. Surviving contract for AutoCore

```
// RngHost (DAT_00d20c1c): +0x08 tableBase, +0x0C cursor
float Rng_SampleUnitFloat_Inferred(RngHost* rng, uint32_t index) {
  if ((int)index < 0) {
    if (rng->cursor > 0xFFFFF) rng->cursor = 0;
    uint16_t w = *(uint16_t*)(rng->tableBase + rng->cursor * 2);
    rng->cursor++;
    return w * DAT_00aaa638; // ≈ 1/65535
  }
  index &= 0x800FFFFF;
  if ((int)index < 0) index = (index - 1 | 0xFFF00000) + 1;
  return *(uint16_t*)(rng->tableBase + index * 2) * DAT_00aaa638;
}
```

Port notes:
- Prefer sequential (`index = (uint32_t)-1`) for “next unit float”.
- Keep distinct from CopyWindow / CloneSeededTable.
- Bind scale to exact `0x37800080` bits when matching retail rolls.

---

## 5. Gaps

1. Product English / MSVC demangle.
2. Exhaustive call-site index modes.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
