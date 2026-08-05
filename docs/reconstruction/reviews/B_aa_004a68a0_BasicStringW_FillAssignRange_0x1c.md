# Review B (skeptical / adversarial): `aa_004a68a0` BasicStringW_FillAssignRange_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a68a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-T) |
| **Counterpart** | `reviews/A_aa_004a68a0_BasicStringW_FillAssignRange_0x1c.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Uninitialized fill / ctor loop | **Falsified** — `operator=` only; no placement new |
| 2 | Count-N `fill_n` | **Falsified** — end pointer compare, not count register |
| 3 | Range-to-range copy | **Falsified** — fixed `value*` in EBX reused every iter |
| 4 | POD dword fill | **Falsified** — IAT string assign, not raw stores |
| 5 | thiscall / member of vector | **Falsified** — plain cdecl; ECX only for nested assign |
| 6 | Char `basic_string` not wstring | **Falsified** — parent is `InsertN_BasicStringW`; IAT `[0x009c63bc]` ≠ char IAT `[0x009c63c4]` |
| 7 | Product plate retail | **Overstated** — structural `_Inferred` name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fill-by-assign + stride 0x1c | **High** | Hole fill corruption |
| cdecl 3-arg plain RET | **High** | Stack imbalance |
| IAT wstring operator= | **High** | Wrong string semantics |
| Parent-only callers | **High** | Missed other uses (none found) |
| Product English | **Inferred** | Naming only |
| Runtime golden | **Open** | Edge empty-range only residual |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  for (; param_1 != param_2; param_1 += 0x1c)
    operator=(param_1, param_3);

bytes:
  CMP ESI,EDI / JZ done
  PUSH EBX (value); MOV ECX,ESI; CALL [IAT]
  ADD ESI,1C; CMP ESI,EDI / JNZ
  RET (C3)
```

Sole parent `004a7ad0` (W34-R) @ `0x004a7d67` (hole arm) and `0x004a7dcc` (after mid-shift). Live decompile 2026-07-29 ≡ raw 2026-07-23. Body 39 B ≡ char twin size.

---

## 4. Surviving contract for AutoCore

```
// BasicStringW_FillAssignRange_0x1c(first, last, value):
//   for each live wstring slot in [first, last): operator=(slot, *value)
//   stride 0x1c; cdecl; void
// Used by vector<wstring>::insert in-place hole fill.
// Do not substitute POD fill, uninit fill, or char string twin.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/stride/IAT; rejects uninit/count-N/POD/char misreads → **accept**.
