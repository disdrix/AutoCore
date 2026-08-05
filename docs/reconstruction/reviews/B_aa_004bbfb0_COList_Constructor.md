# Review B (skeptical / adversarial): `aa_004bbfb0` COList_Constructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbfb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bbfb0_COList_Constructor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Object size unknown / not 0x58 | InitInstance `push 0x58` immediately before ctor | **Falsified** — sizeof **0x58** |
| 2 | Stack args are floats / other | Call site `push 10; push 5`; stores as int caps | **Falsified** — ints |
| 3 | Always creates both hashes | Flags + null path when cap==0 | **Falsified** — optional |
| 4 | Third table uses same ctor as hashA/B | `FUN_004bce90` vs `FUN_004bcf90`; different vtbls | **Confirmed difference** — do not merge helpers |
| 5 | Member lists are dual-CS ThreadSafeObjectList (`009cb368`) | Members final vtbl `009cb378`, size **0x2C**, single ICS at +4 | **Falsified** — distinct layout from dtor stack list |
| 6 | bare `ret` / void return | Exit `C2 08 00`; returns this | **Falsified** — ret 8 + this* |
| 7 | Multiple production callers | xrefs single CALL from InitInstance | **Confirmed** sole code caller |
| 8 | Class is generic “unknown” | vtbl rdata `COList::Insert` + dtor twins | **Falsified** — COList |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| sizeof 0x58 + ret 8 | **High** | Heap overrun / ABI crash |
| Optional hash polarity | **High** | Null deref or leak |
| Fixed `FUN_004bce90(5)` | **High** | Wrong third-table capacity |
| Triple 0x2C construct | **High** | Leak / missing lists |
| Nested product English | **Partial** | Doc only |

---

## 3. Cross-check against raw / bytes

```
raw:   vtbl 009cb448; clamp; flags; bcf90×2 optional; bce90(5); 0x2C list×3; ret this
bytes: 6AFF 6842179A00 … C70648B49C00 … 83C410 C20800
call:  6A58 new; 6A0A 6A05 thiscall 004bbfb0; DAT_00b04830 / +0xD34
vtbl:  [0]=004bd1b0 scalar; rdata COList::Insert
```

---

## 4. Surviving contract for AutoCore

```csharp
// Client_InitInstance production path
var list = Alloc(0x58);
COList_Constructor(list, capA: 5, capB: 10);
DAT_00b04830 = list;
client.Field_0xD34 = list;

void COList_Constructor(COList self, int capA, int capB)
{
    self.Vtbl = COListVtbl; // 0x009cb448
    capA = Math.Max(capA, 0);
    capB = Math.Max(capB, 0);
    // store caps + has flags
    self.HashA = capA != 0 ? HashCtor_bcf90(New(0x34), capA) : null;
    self.HashB = capB != 0 ? HashCtor_bcf90(New(0x34), capB) : null;
    self.TableC = HashCtor_bce90(New(0x34), 5); // always
    self.List0 = self.List1 = self.List2 = CsList0x2c_New(); // vtbl 009cb378
    self.Flag0E = 0;
}
```

**Port traps to reject:**

- Using dual-CS `ThreadSafeObjectList` (`009cb368`) layout for member slots +0x1C/+0x20/+0x24.
- Calling `FUN_004bcf90` for the third table (must be `FUN_004bce90(5)`).
- Omitting negative clamp.
- Forgetting `ret 8` / two int formals.
- Assuming capA/capB are table element counts rather than bit-sizes (`1<<cap` inside nested ctors).

---

## 5. Residual gaps (do not block outer seal)

1. Nested hash / 0x2C list product English (OWN-separate VAs).
2. SEH unwind path fidelity.
3. Runtime / image diff.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break host ABI/layout/InitInstance contract. Gaps are nested naming only.
