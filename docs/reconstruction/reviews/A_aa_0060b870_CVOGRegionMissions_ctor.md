# Review A (reconstruction fidelity): `aa_0060b870` CVOGRegionMissions_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060b870` |
| **VA** | `0x0060b870` |
| **Body** | `0x0060b870`–`0x0060bb77` (0x308 bytes) |
| **Canonical name** | `CVOGRegionMissions_ctor` |
| **Review date** | `2026-07-29` (W17-B dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060b870_CVOGRegionMissions_ctor.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Context: sibling Ensure dual `aa_0053fff0`.

---

## 1. Purpose

Construct the **0x10** `CVOGRegionMissions` wrapper: four hash tables + populate from preload mission-def vector or DB cold load. Product path `VOGRegionMissions.cpp`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0060b870_FUN_0060b870.md` |
| Annotated | `docs/reconstruction/raw/aa_0060b870_FUN_0060b870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGRegionMissions_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_0060b870_FUN_0060b870.md` |

---

## 3. Byte / decompile seal

### 3.1 ABI + SEH

```
6A FF  68 27 83 9A 00  64 A1 00 00 00 00  50  64 89 25 ...
83 EC 10  53 55 56 57  33 FF  8B E9   ; this → EBP
8B 0D 4C 43 B0 00                   ; DAT_00b0434c
```

| Claim | Confidence | Evidence |
|---|---|---|
| ECX = this | **High** | `mov ebp, ecx` |
| Returns this | **High** | epilogue `mov eax, ebp` |
| SEH frame | **High** | standard MSVC prolog bytes |
| Preload vector `DAT_00b0434c`/`DAT_00b04350` | **High** | entry load + decompile count |

### 3.2 Four hashes

| Slot | Size | Ctor | Conf |
|---|---|---|---|
| `this[0]` | `0x34` | `FUN_0053b0b0(8)` | **High** |
| `this[1]` | `0x34` | `FUN_0053b1b0(8)` | **High** |
| `this[2]` | `0x38` | base + vtbl `009df688` + `[0xd]=0` | **High** |
| `this[3]` | `0x38` | same as `[2]` | **High** |

OOM log path + `"Out-o-memory... missions!"` → product class **High**.

### 3.3 Insert this-ptrs (residual closed)

Population site bytes:

| Call | `ECX` (this hash) | Key | Value |
|---|---|---|---|
| `FUN_0053c360` | `[ebp]` = `this[0]` | `*def` | def |
| `FUN_0060c010` | `[ebp+8]` = `this[2]` | `def[+0x88]` if ≠ -1 | def |
| `FUN_0060c010` | `[ebp+0xC]` = `this[3]` | byte `def[+0x86]` | def |
| `FUN_0053c460` | `[ebp+4]` = `this[1]` | `obj[+0x10]` | obj |

Prior Ensure dual listed “this-ptr residual” for `FUN_0060c010` — **sealed here**.

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Preload vs DB cold gate | **Yes** |
| Four hash constructions | **Yes** |
| OOM log | **Yes** |
| Per-def insert order | **Yes** |
| Cold-path COM free | **Yes** |
| Return this | **Yes** |

---

## 5. Gaps

1. Product English for keys `+0x86` / `+0x88`.
2. Full product names of hash ctor/insert callees.
3. Runtime / differential.
4. Whether hash OOM continues after `VOG_DEBUG_STOP` (no throw on that path).

**Verdict:** **accept**
