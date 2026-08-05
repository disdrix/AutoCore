# Review B (skeptical / adversarial): `aa_004501d0` AnimEventVec_InsertN_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004501d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-O) |
| **Counterpart** | `reviews/A_aa_004501d0_AnimEventVec_InsertN_Inferred.md` |
| **Scratch** | `tmp/a_004501d0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as `StdVector_InsertN_BasicString` (`004306b0`) | **Falsified** — different VA, different element helpers, different ABI (stack×4/`RET 0x10` vs thiscall/`RET 0x0C`) |
| 2 | ECX=vec thiscall | **Falsified** — bytes load `esi=[ebp+8]`; epilogue `C2 10 00` |
| 3 | Stride 4 / 0x18 / string-only | **Falsified** — magic `0x92492493` ÷28; construct uses `PTR_FUN_009d4828` not basic_string IAT |
| 4 | Push-back only | **Falsified** — general insert-n with `where`; resize calls with `where=end` |
| 5 | Product name retail string in body | **Overstated** — domain from scaffold `anmAnimEvent` chain + vtbl; `_Inferred` structural |
| 6 | Multiple direct callers | **Falsified** — single xref from `FUN_00450050` |
| 7 | Capacity uses SAR 2 | **Falsified** — uses signed magic ÷0x1c |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI 4-stack / `RET 0x10` | **High** | Stack imbalance / wrong this |
| Stride 0x1c / max / 1.5× | **High** | Buffer OOB / throw miss |
| Grow vs in-place CF | **High** | Corrupted iterators |
| Anim-event domain label | **Medium** | Over-specific name if shared POD |
| Nested helper ownership | **Low** | Wrong dtor/copy semantics |
| Runtime | **Open** | EH edge cases |

---

## 3. Cross-check against raw + bytes

```
bytes prologue: push ebp; mov ebp,esp; ... mov esi,[ebp+8]; mov edi,[ebp+10]
bytes epilogue: ... pop ebx; mov esp,ebp; pop ebp; ret 0x10
raw ≡ live CF; element stride 0x1c throughout
size helper call FUN_00469c50 (StdVector_Elem28_Size) on grow floor path
caller 00450050: insert(vec, end, newSize-oldSize, &value)
```

Contrast W32-B string insert deliberately uses different construct/destroy IAT and thiscall entry — do **not** unify ports.

---

## 4. Surviving contract for AutoCore

```
AnimEventVec_InsertN(vec, where, count, value):
  // 4 stack args; RET 0x10
  // elem 0x1c; vtbl 009d4828; nested range copy/assign/destroy
  // max 0x9249249; grow 1.5x; in-place shift otherwise
  // sole known caller: resize grow path FUN_00450050
```

Do **not** use string-vector thiscall ABI. Do **not** treat as POD memcpy insert. Nested helpers stay free until owned.

---

## 5. Open questions

- Exact product type behind `PTR_FUN_009d4828` / `anmAnimEvent`.
- Whether resize is the only production path forever (1 xref today).
- Bit-exact EH state numbers vs MSVC version.

**Verdict:** **accept-with-gaps**
