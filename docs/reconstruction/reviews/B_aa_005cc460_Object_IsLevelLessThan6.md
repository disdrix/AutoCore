# Review B (skeptical / adversarial): `Object_IsLevelLessThan6` / `FUN_005cc460` @ `0x005cc460`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc460` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005cc460_Object_IsLevelLessThan6.md` |
| **Verdict** | **accept** on CF/ABI/threshold/GetLevel slot; **needs-more-evidence** only on product symbol + design of “6” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function computes heading / facing angle | **Falsified** — integer GetLevel compare only; no float/math |
| 2 | cdecl plain `ret` | **Falsified** — both exits `ret 4` (`C2 04 00`) |
| 3 | thiscall with ECX = object | **Falsified** — object is stack `[esp+4]`; ECX built for vcall only |
| 4 | Threshold is `<= 6` (inclusive) | **Falsified** — `cmp eax,6; jge` ⇒ return 1 only when **&lt; 6** |
| 5 | Null object crashes | **Falsified** — explicit null → 0 |
| 6 | Direct field load for level | **Falsified** — full MI adjust + vcall |
| 7 | Product name sealed | **Open** |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall ret 4 | **Confirmed** | Stack imbalance in port |
| Null-safe | **Confirmed** | Crash fantasy |
| vtbl+0x27c GetLevel | **High** | Wrong semantic if slot is not level (contradicts multi-dual corpus) |
| Threshold 6 exclusive | **Confirmed** | Off-by-one in pursue branch |
| “Heading helper” label in pursue plate | **Rejected** | Misports AI steer logic |
| Product C++ name | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// stdcall
uint8_t Object_IsLevelLessThan6(void* obj):
  if obj == null: return 0
  inner = MI_adjust(obj)   // obj + *(*(obj+4)+4) + 4
  level = vcall(inner, +0x27c)
  return level < 6

// NOT heading. NOT float. NOT thiscall on obj.
// Pursue path: if true → special low-level branch; else other path.
```

---

## 4. Falsification notes

### 4.1 “Heading” mislabel

`CVOGHBAICreatureBase_DoVehiclePursue` clean plate comments still say “heading via FUN_005cc460”. Body of this VA has **zero** trigonometry — pure level gate. Ports that treat return as angle invent behavior.

### 4.2 Off-by-one

`jge` after `cmp eax,6` means level **6 returns 0**. Any port using `<= 6` expands the low-level set incorrectly.

### 4.3 stdcall trap

Epilogue is `C2 04 00`, not `C3`. cdecl would leave 4 bytes on stack.

---

## 5. Open questions

1. Retail symbol.
2. Why **6** specifically.
3. Whether other (unnamed) xrefs exist beyond pursue — analyze reports one named caller.

**Verdict:** **accept** on sealed CF, stdcall ABI, GetLevel+threshold. Reject heading/cdecl/thiscall-on-obj overclaims.