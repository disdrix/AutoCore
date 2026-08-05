# Review B (skeptical / adversarial): `aa_00513e70` Item_IsStackEligible

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513e70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00513e70_Item_IsStackEligible.md` |
| **Residual scratch** | `reviews/a_00513e70.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept-with-gaps** on CF + eligibility role; **reject** “stack capacity” and inverted Broken logic |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is **stack capacity** (qty room) | **Falsified** — no qty, no max (`0x4ba` / 200 / 999999). Capacity is `0x0040abf0` |
| 2 | Wave map “Stack capacity helper” is accurate | **Falsified** — mislabel; eligibility only |
| 3 | Returns 1 when Broken is set (OR with flag) | **Falsified** — asm: flag set path returns 1 only if Broken **clear** (`test bit19; jz ret1`) |
| 4 | Returns 1 only when type==4 | **Falsified** — type4 is alternate success; non-type4 can succeed with flag & !broken |
| 5 | `a_008151a0` note: “(flag **or** broken) **and** type==4” | **Falsified** — closed form is `type4 \|\| (flag && !broken)` |
| 6 | Dedicated `IsBroken()` callee exists here | **Falsified** — inline bit test; no call |
| 7 | Broken setter `0x00513de0` is part of this function | **Falsified** — separate sibling; not in body |
| 8 | Function places / merges stacks | **Falsified** — pure predicate; callers do scan/merge |
| 9 | Type 4 “is currency” | **Unproven** — only CF `==4` → 1; name interpretive |
| 10 | Blob bit `0x40` alone means stackable | **Overstated** — necessary for non-type4 but Broken still blocks; type4 ignores it |
| 11 | Ready for bit-exact seal | **Fail** — runtime/diff open |

---

## 2. Decisive dataflow — sealed contract

```
// ECX = Item*
// ret (no imm)

holder = item->typeHolder           // +0xa8
blob   = holder->cloneblob          // +0x3c
if (blob->flagsByte[+0x3f2] & 0x40):
  if !(item->flags[+0x17c] & (1<<19)):   // ItemFlag_Broken
    return 1
if holder->typeClass[+0x38] == 4:
  return 1
return 0
```

**Byte-backed (not decompiler-only):**

- Entry uses `ECX` for item; clobbers `ECX` only after holder saved in `EAX`.
- Stack flag via `shr 6` / `test 1` on `blob+0x3f2` (≡ `& 0x40`).
- Broken via `shr 0x13` / `test 1` on `item+0x17c`.
- Fail path: `xor eax,eax; ret`. Success: `mov eax,1; ret`.
- Function ends at `0x00513ea3`; `CC` padding follows — **no** hidden tail capacity logic.

---

## 3. Relation attack: “is this capacity / is this broken helper?”

### Capacity (`0x0040abf0`)

```
if type==4: max = 999999
else: max = blob+0x4ba; if 0 then 200
return (qty_vfunc + delta) <= max
```

Completely different unit. Callers of FindFreeForItem / SerializeAddItem call **both**: eligibility first (`0x00513e70`), then peer find, then capacity (`0x0040abf0`).

### Broken helper

| Kind | Exists? | Where |
|------|---------|-------|
| Read helper function | **No** dedicated callee in this path | Inline in `0x00513e70` and other sites |
| Write helper | **Yes** | `0x00513de0` (`ItemFlag_Broken` setter) |
| This unit as “broken helper” | **No** | Eligibility combines stack flag + broken + type4 |

---

## 4. Prior residual correction (adversarial)

`a_008151a0` helper note claiming return-1 when “(flag or broken) and type==4” must be treated as **stale/wrong**. Loot `xN` gate still correctly uses non-zero of this function + qty≥2 — that **call-site** claim stands; the **internal formula** in that note does not.

---

## 5. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Eligibility not capacity | **High** | Server stack math wrong if reused as room check |
| Broken blocks stack path | **High** | Broken items wrongly merge |
| Type4 always eligible | **High** CF | Footprint-less / special type mishandled |
| No callees / pure read | **High** | Phantom side effects |
| Name `Item_IsStackEligible` | **Probable** | Original symbol unknown |
| Type4 product taxonomy | **Low** | Mislabel currency/quest/etc. |

---

## 6. Verdict

### **accept-with-gaps**

Accept sealed CF, ABI, eligibility-vs-capacity split, and rejection of inverted Broken / wave capacity labels. Gaps: type-4 naming, PDB name, runtime verification.
