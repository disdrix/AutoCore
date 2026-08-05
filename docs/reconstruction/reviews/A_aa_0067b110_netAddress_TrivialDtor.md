# Review A (reconstruction fidelity): `aa_0067b110` netAddress_TrivialDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067b110` |
| **VA** | `0x0067b110` |
| **Body span** | `0067b110` only (`c3`) |
| **Canonical name** | `FUN_0067b110` |
| **Proposed name** | `netAddress_TrivialDtor` / `Address_Dtor` |
| **System** | network-nazgul-netAddress |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory`) |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_0067b110_netAddress_TrivialDtor.md` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** on CF / emptiness; **accept-with-gaps** on product name |

---

## 1. Purpose

**Trivial destructor** for the nazgul **16-byte Address / sockaddr POD**. Empty body — a single `ret` — used as MSVC SEH cleanup / scope-exit for stack Address objects.

No parameters consumed, no stores, no callees, no globals.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0067b110_FUN_0067b110.md` |
| Raw | `docs/reconstruction/raw/aa_0067b110_FUN_0067b110.md` (+ v2026-07-29) |
| Annotated | `docs/reconstruction/raw/aa_0067b110_FUN_0067b110.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0067b110.cpp` |

**Live tools (OWN VA only):**

- `decompile_function` @ `0x0067b110` → `void FUN_0067b110(void) { return; }`
- `read_memory` @ `0x0067b110` length 32 → `c3` then `cc` padding; next function `FUN_0067b120` @ `0x0067b120`
- Context (not owned): cluster with `0067b070` ctor / `0067b0e0` copy / `0067ba30` peer query calling this dtor
- **Not performed:** Launcher; ledgers; full xref dump

---

## 3. Assembly contract (from `read_memory`)

```
0067b110  c3              ret
0067b111  cc…             int3 padding to 0067b120
```

Hex (executed): **`c3`**

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Empty leaf / single `ret` | **Confirmed** | decompile + bytes |
| No formals / no side effects | **Confirmed** | body has no prologue/use of args |
| Role = trivial Address dtor | **High** | call sites after Address locals; cluster with ctor/copy |
| Product/PDB name | **Open** | no string on this VA |
| Decompiler args at some call sites are real | **Falsified** | body takes nothing |
| Clean ≡ raw ≡ live | **Confirmed** | identity |
| Runtime harness | **N/A / Open** | empty leaf |

---

## 5. Control-flow checklist

| Stage | Match |
|---|---|
| Enter | **Yes** |
| Return immediately | **Yes** |
| No branches / calls / stores | **Yes** |

### Recovered CF

```c
void FUN_0067b110(void)
{
    return;
}
```

---

## 6. Gaps

1. Product class spelling (`netAddress` vs `Address`).
2. Exhaustive caller inventory (SEH ubiquity) — not required for CF seal.
3. Whether any non-POD Address type incorrectly shares this symbol (no evidence in body).

**Verdict:** **accept** on emptiness/CF; product name **open** — dual seal complete for OWN VA.
