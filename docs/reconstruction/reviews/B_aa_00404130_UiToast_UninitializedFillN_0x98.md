# Review B (skeptical / adversarial): `aa_00404130` UiToast_UninitializedFillN_0x98

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404130` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W20-G) |
| **Counterpart** | `reviews/A_aa_00404130_UiToast_UninitializedFillN_0x98.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Relocates existing range | **Falsified** — calls ConstructN (template fill), not UninitializedCopy / `00404510` |
| 2 | Stride 0x38 / floater | **Falsified** — `* 0x98` return (toast width) |
| 3 | Returns count | **Falsified** — returns pointer end (`lea eax,[edi+edx*8]`) |
| 4 | Grows capacity | **Falsified** — no new/delete |
| 5 | True thiscall with meaningful `this` result | **Falsified** — `ret 0x0C`; ECX only phantom-pushed |
| 6 | ConstructN uses all five pushed dwords | **Falsified** — sealed ConstructN uses `(dst,count,src)` only |
| 7 | Mission/XP/craft logic | **Falsified** — POD placement only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ConstructN + end return | **High** | Wrong insert hole end |
| 0x98 stride | **High** | Misaligned toast buffer |
| Distinct from move/assign helpers | **High** | Merge wrong helpers (`00404510` / `00404530`) |
| Free 3-arg ABI | **High** | Wrong calling convention in port |

---

## 3. Cross-check

```
raw: FUN_00404670(...); return param_2 + param_3 * 0x98;
live: identical.
bytes: call 00404670; lea end via *0x98; ret 0x0C
Parent InsertN lists this as fill-n helper.
Twin 00402ea0 same pattern at stride 0x38.
```

---

## 4. Surviving contract for AutoCore

```
UiToast_UninitializedFillN_0x98(dst, n, template) → end:
  ConstructN(dst, n, template)   // N × PodCopy 0x98
  return dst + n*0x98
```

Port as span fill of toast records; do **not** allocate or free here.

---

## 5. Open questions

None blocking for insert path.

**Verdict:** **accept**
