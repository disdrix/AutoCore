# Review B (skeptical / adversarial): `aa_00576ed0` CVOGPhaseDistort_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00576ed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W32-T) |
| **Counterpart** | `reviews/A_aa_00576ed0_CVOGPhaseDistort_ctor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is NDRiver / Drive_NDRiver_fx method | **Falsified** — no FX string; factory log is **"Distort phase…"**; RTTI **PhaseDistort** |
| 2 | Is Water phase ctor (`005769c0`) | **Falsified** — different vtbl `009d3b04` vs `009d3bc0`; Water alloc **0x20** zeros two extra dwords |
| 3 | Multi-arg / non-ctor worker | **Falsified** — only view formal; `ret 4`; factory `new`+call pattern |
| 4 | Multiple callers / not singleton | **Falsified** — one CODE xref; gated on `DAT_00b04818==0` |
| 5 | RTTI ambiguous / adjacent string only | **Falsified** — COL@vtbl[-1] → type_info name **`.?AVCVOGPhaseDistort@@`** |
| 6 | Decompiler missing SEH ⇒ no SEH | **Falsified** — bytes `6a ff 68 4a519a00` … `c2 04 00` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Class = CVOGPhaseDistort | **Confirmed** | Wrong phase hierarchy in port |
| Singleton size 0x18 | **Confirmed** | Heap corruption if sized as Water 0x20 |
| Distinct from Water / owned fog host | **High** | Merge init paths incorrectly |
| Empty `+0x08` intentional | **High** residual | Over-zero could clobber later fill — leave untouched |

---

## 3. Cross-check

```
raw 2026-07-23: view@+4, vtbl 009d3bc0, zero three dwords
live 2026-07-29: identical CF
bytes: SEH + mov [eax+4],arg + mov [eax],vtbl + zero +c/+10/+14 + ret 4
factory 0048fc90: if !DAT_00b04818: new(0x18); FUN_00576ed0(view); owner=env; vcall+0x20; FUN_00576d70
sibling water 005769c0: same shape, vtbl 009d3b04, zeros through +0x1C (size 0x20)
RTTI: COL 00aaed0c → 00af31a0 ".?AVCVOGPhaseDistort@@"
```

---

## 4. Surviving contract for AutoCore

```
CVOGPhaseDistort_ctor(this, view):
  this.view = view
  this.vtbl = CVOGPhaseDistort_vtbl
  zero piece tails +0x0C..+0x14
  return this
```

Port as **process singleton** (create once when global null). Do **not** confuse with Water (`0x20`) or owned `CVOGEnvironmentReflect` (`0x170`). Reject NDRiver naming.

---

## 5. Open questions

None blocking Distort singleton construction. Piece-instance method dual residual.

**Verdict:** **accept**
