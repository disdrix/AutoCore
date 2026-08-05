# Review B (skeptical / adversarial): `aa_007dbce0` Mission_tContinentObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_007dbce0` |
| **VA** | `0x007dbce0` |
| **Canonical name** | `Mission_tContinentObject` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007dbce0_Mission_tContinentObject.md` |
| **System** | missions-progression / DB table load |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same table as `tContinentExploredAreas` | Different BSTR / different VA `007dd5e0` | **Falsified** merge |
| 2 | Row size 0x100 / generic node | Copy **0x55 dwords**; caller `/0x154` | **Falsified** wrong size |
| 3 | Only COM XML path exists | `DAT_00d1793c==0` binary/column path first | **Falsified** XML-only |
| 4 | Only binary path exists | Mode B SysAllocString present | **Falsified** binary-only |
| 5 | Inserts into CNDHash itself | Insert is caller `00541950` → `00545a90` | **Falsified** — loader only |
| 6 | Decompiler “unreachable” means dead product code | SEH / EH cleanup noise common | **Attack weak** — treat as residual, not delete |
| 7 | Multi-caller shared util | Only `00541950` caller | **Agree** narrow |
| 8 | Full column schema sealed in this dual | Args to `004231d0` collapsed | **Agree Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Plate string tContinentObject | **Confirmed** | Wrong table model |
| Row 0x154 | **Confirmed** | Buffer over/underrun |
| Dual mode flag | **Confirmed** | Missing load path |
| Loader ≠ hasher | **Confirmed** | Wrong ownership |
| Column field map | **Open** | Wrong AutoCore struct |
| SEH arms | **Tentative** | Incomplete error ports |
| Runtime | **Open** | |

---

## 3. Cross-check against raw / live / caller

```
batch_decompile ≡ annotated scaffold (large).
Caller FUN_00541950:
  FUN_007dbce0(&vec);
  n = (end - begin) / 0x154;
  alloc n*0x154 @ obj+0xf20;
  for i in 0..n:
    FUN_00545a90(key=*(row), value=row, soft=0);  // this=hash lost in decomp
```

### Stride trap

Do **not** reuse explored-areas row size. Continent **object** rows are **0x154**.

### Ownership trap

This VA **loads + copies**. Hash insert / unlock logic is **`00545a90` / reaction duals**, not here.

### Mode trap

Shipping may use either `DAT_00d1793c` arm. Ports that only implement SysAllocString XML will break binary-mode clients (and vice versa).

---

## 4. Surviving contract for AutoCore

```
Mission_tContinentObject(src, outVec):
  load all //tContinentObject/row into staging
  emit tightly packed records of 0x154 bytes each into outVec

Consumer FUN_00541950:
  store blob @ +0xf20
  CNDHash_Insert each row (FUN_00545a90, vtbl 009d01ac family)

AutoCore must NOT:
  - merge with tContinentExploredAreas loader
  - assume row size != 0x154
  - put hash insert inside this VA
  - drop either DAT_00d1793c mode without evidence
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| tContinentObject plate | **Agree Confirmed** |
| 0x154 / 0x55 dword copy | **Agree Confirmed** |
| Dual mode | **Agree Confirmed** |
| Column map Open | **Agree** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Column-by-column dual (or data-driven schema dump).
2. `DAT_00d1793c` init site / retail value.
3. Runtime row inventory.

**Verdict:** **accept-with-gaps** — agree with A; block table merge, wrong stride, and insert ownership mistakes.
