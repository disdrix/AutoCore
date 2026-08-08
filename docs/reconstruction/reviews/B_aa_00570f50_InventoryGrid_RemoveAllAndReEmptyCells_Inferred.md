# Review B (skeptical / adversarial): `aa_00570f50` InventoryGrid_RemoveAllAndReEmptyCells_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570f50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00570f50_InventoryGrid_RemoveAllAndReEmptyCells_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (R10-013 OWN-ONLY) |
| **Verdict** | **accept-with-gaps** on CF + ABI + list@+0x2c + callees; **reject** free-only / list-as-ECX / twin-collapse / retail-name / “never destroys items” overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Body is free-only of cell buffer `+0x28` | **Falsified** — no direct free; tails to Allocate which free+realloc+empty-fills |
| 2 | ECX is the List host, not the grid | **Falsified** — `MOV ESI,ECX`; `LEA ECX,[ESI+0x2c]` only for RemoveAll; Allocate gets ESI |
| 3 | Same as twin `00570f70` (full clear) | **Falsified** — no TraversalLock, iterate, detach, or `004d4790` |
| 4 | `FUN_004bc580` is called with grid this | **Falsified** — LEA shifts ECX to `+0x2c` |
| 5 | Never destroys items | **Overstated** — unit has no item walk, but `List_RemoveAll` still scalar-deletes residual list nodes |
| 6 | Decompiler `return` means bare RET | **Falsified** — last insn is `JMP 00570720` (tail) |
| 7 | Scaffold name `Named_CalleeOf_CVOGCharacter_*` is primary | **Fail** — multi-caller inventory helper; create packet is one of many |
| 8 | Name is sealed retail | **Fail** — `_Inferred` only |
| 9 | Ready for bit-exact / complete | **Fail** — runtime/diff open |
| 10 | Parent dual `00570720` owns this VA | **Fail** — parent is callee only; this dual OWN-ONLY on `00570f50` |

---

## 2. Decisive dataflow (raw + live 2026-08-05)

```text
ESI = ECX                       // InventoryGrid* grid
ECX = ESI + 0x2c                // ListHost*
CALL List_RemoveAll             // 0x004bc580
ECX = ESI                       // grid*
JMP  InventoryGrid_AllocateCellArray_Inferred  // 0x00570720
```

Body hex (19 B):

```
56 8B F1 8D 4E 2C E8 25 B6 F4 FF 8B CE 5E E9 BD F7 FF FF
```

Relative targets verified:

| Insn | Next-IP | Rel32 | Target |
|------|---------|-------|--------|
| CALL | `0x00570f5b` | `0xfff4b625` | `0x004bc580` |
| JMP  | `0x00570f63` | `0xfffff7bd` | `0x00570720` |

Live decompile CF order matches 2026-07-23 raw; assembly fills decompiler gaps.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RemoveAll then Allocate order | **High** | Wrong clear policy |
| list @ `grid+0x2c` | **High** | Wrong object drain / crash |
| ECX grid ABI | **High** | Caller mis-port |
| Thin ≠ full twin | **High** | Missing detach on create/clear |
| Residual nodes still dtor’d in RemoveAll | **High** (callee dual) | Leak if assumed no-op on empty-only |
| Product reason for thin path | **Probable** | Wrong port of create vs UI clear |
| Runtime golden | **Open** | Residual parity |
| Retail name | **Open** | Cosmetic |

---

## 4. Twin / partition attacks

| Attack | Result |
|--------|--------|
| Collapse into FreeCellArray | **Reject** — Allocate re-creates empty cells; list drain first |
| Collapse into `00570f70` | **Reject** — 19 B vs 158 B; no item walk |
| Claim only character-create helper | **Reject** — Vehicle, cargo UI, multi-grid helpers also call |
| Claim Allocate not dualed | **Reject** — parent dual present; used as sealed callee |

---

## 5. Gaps that remain after attack

1. Product English for thin vs full clear selection.
2. Runtime / differential / bit-exact.
3. Retail symbol.
4. Clean source uses call form vs retail tail-JMP (document only).

None falsify the sealed CF/ABI/list offset.

---

## 6. Verdict

### **accept-with-gaps**

Adversarial checks **reject** free-only, list-as-ECX, twin-collapse, and retail-name claims. Accept reconstruction of the **thin re-empty** unit with list@`+0x2c` and dualed callees. Gaps do not reopen CF.

### Checklist

| Check | Result |
|---|---|
| Free-only claim | **Rejected** |
| list-as-ECX claim | **Rejected** |
| Twin-collapse | **Rejected** |
| list@+0x2c | **Sealed** |
| Tail to Allocate | **Sealed** |
| Runtime | **Open** |
| Verdict | **accept-with-gaps** |
