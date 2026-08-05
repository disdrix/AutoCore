# Review B (skeptical / adversarial): `Object_DefSubInt4e0_Equals1_Inferred` / `FUN_0040b1b0` @ `0x0040b1b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b1b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040b1b0_Object_DefSubInt4e0_Equals1_Inferred.md` |
| **Verdict** | **accept-with-gaps** — reject overclaims on English field meaning and “always player” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Returns full 32-bit object pointer / status code | **Falsified** — `SETE AL` boolean only |
| 2 | Mutates object or definition | **Falsified** — load/compare/`ret` only |
| 3 | `+0x4e0` product name sealed | **Open** — numeric compare only |
| 4 | Predicate means “is player” exclusively | **Overstated** — used as tip *negative* gate and type-0x12 *positive* filter; English not sealed |
| 5 | Direct field at `obj+0x4e0` | **Falsified** — walk `adj → +0xac → +0x3c → +0x4e0` |
| 6 | Has callees / heap traffic | **Falsified** — leaf |
| 7 | `__stdcall` / stack args | **Falsified** — `__fastcall` ECX object |
| 8 | Clean invents logic beyond raw | **Falsified** — scaffold ≡ live body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Offset chain + compare-to-1 | **Confirmed** | Wrong gate in select/interact ports |
| Bool-only return | **Confirmed** | Mis-typed as int status |
| Shared multi-caller helper | **High** | Treating as interact-only |
| Field English | **Open** | Docs / naming only |
| NULL-safety of holder/sub | **Open** | Retail assumes well-formed objects; port crash if null |

---

## 3. Surviving contract for AutoCore

```
// Leaf predicate — no side effects
bool DefSubInt4e0_Equals1(Object* obj):
  adj = *(*(obj + 4) + 4)
  holder = *(Object**)( (uint8_t*)obj + adj + 0xAC )
  sub = *(void**)(holder + 0x3C)
  return *(int32_t*)(sub + 0x4E0) == 1

// Ports MUST:
//  - preserve full walk (not obj+0x4e0)
//  - return bool (0/1)
//  - not invent English meaning of 0x4e0 without evidence
```

---

## 4. Falsification notes

### 4.1 Tip polarity

Parent select path shows tips when this returns **false**. Ports that invert the sense will spam or suppress tutorial tips incorrectly.

### 4.2 Not the select API

Does **not** select, send packets, or walk UI. Only a definition-field test.

### 4.3 `CONCAT31` noise

Decompiler packing is not a multi-field return — ignore high bytes; only AL matters.

---

## 5. Open questions

1. Retail name / data schema for `sub+0x4e0`.
2. Whether all callers share one semantic category or overload the flag.
3. Runtime null behavior on broken objects.

**Verdict:** **accept-with-gaps**. Sealed leaf bool predicate; reject field-English and player-only overclaims.
