# Review A (reconstruction fidelity): `aa_00767600` stoChunk_ConvertToInteger

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767600` |
| **VA** | `0x00767600`–`0x007677f6` |
| **Canonical name** | `stoChunk_ConvertToInteger` |
| **Prior scaffold** | `FUN_00767600` / `Named_stoChunk_00767600` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W25-R |
| **Counterpart** | `reviews/B_aa_00767600_stoChunk_ConvertToInteger.md` |
| **System** | storage / arda2 stoChunk |
| **Verdict** | **accept** — full CF, ABI, SSO access, range tables, log lines sealed; runtime open only |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + strings). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Convert decimal text token → integer bytes:

1. Resolve SSO C-string from MSVC `std::string` in **EAX**.
2. Optional leading `-` when `signedMode==1`.
3. Digit-only parse with 64-bit accumulate (`*10` via `__allmul`).
4. Range-check by `(byteLen, signedMode)`.
5. Optional two's-complement negate; copy `byteLen` bytes to `out`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767600_FUN_00767600.md` (+ W25-R live seal) |
| Annotated | `docs/reconstruction/raw/aa_00767600_FUN_00767600.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoChunk_ConvertToInteger.cpp` |
| Function record | `docs/reconstruction/functions/aa_00767600_stoChunk_ConvertToInteger.md` |
| Live decompile | Ghidra `decompile_function` `0x00767600` — **≡** raw |
| Live bytes | entry SSO/`'-'`/`RET 12`; strings at `0x00a9d440`, `0x00a9d738` |
| Callers | 9 text readers including `stoChunkReader_TextReadU32` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| text | **EAX** (`cmp [eax+0x18],0x10`) |
| out / len / signed | 3 stack dwords |
| Epilogue | **`RET 12`** (`C2 0C 00`) all exits |
| Return | **0** / **−1** (`or eax,-1` / `xor eax,eax`) |

### 3.2 Parse — **SEALED**

- Empty → −1
- `-` + unsigned → −1
- non-digit → −1
- decimal only (no `0x`)

### 3.3 Range tables — **SEALED**

Unsigned masks `0xffffff00` / `0xffff0000` / hi≠0 / free; signed abs masks `0xffffff80` / `0xffff8000` / `0x80000000` / signbit63; invalid length log `0x3ab` / `0x3c3`.

### 3.4 Name — **SEALED High**

`"Invalid integer length in ConvertToInteger()"` + `stoChunk.cpp`.

---

## 4. Gaps (minor)

- Runtime / differential vs crafted tokens.
- `signedMode ∉ {0,1}` skips range checks (sealed behavior, unusual caller).

---

## 5. Verdict rationale

Self-contained pure conversion with product plate string and complete CF under own VA → **accept**.
