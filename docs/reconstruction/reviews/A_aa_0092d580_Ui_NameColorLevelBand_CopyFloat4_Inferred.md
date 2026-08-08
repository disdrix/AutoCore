# Review A (reconstruction fidelity): `aa_0092d580` Ui_NameColorLevelBand_CopyFloat4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092d580` |
| **VA** | `0x0092d580`–`0x0092d5fb` |
| **Canonical name (Ghidra)** | `FUN_0092d580` |
| **Proposed name** | `Ui_NameColorLevelBand_CopyFloat4_Inferred` |
| **Review date** | `2026-08-04` (WQ9E-C OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0092d580_Ui_NameColorLevelBand_CopyFloat4_Inferred.md` |
| **System** | client UI / entity name-label color |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **signed level-difference → float4 color band copy** from host tables at **`+0xBE4..+0xC54`**. Feeds name-color pack (×255 → AARRGGBB) and mission UI tinting. Not fixed palette (`00930f40`), not full resolver (`00930fc0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x0092d580` |
| Bytes | `read_memory` 160 B @ entry (band ladder + 16 B copy) |
| Meta | body `0092d580`–`0092d5fb` (**123 B**) |
| Callers | `FUN_00930fc0`, `Client_NpcDialog_PrepareResponseOpcode`, `FUN_00829b20`, `FUN_0082a050` |
| Parent dual | `aa_00930fc0` level-pack path; mission dialog opcode dual |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0092d580` |

**Not performed:** Launcher, runtime host-table float dump, bit-exact, parent ledgers.

---

## 3. Signature

```c
float* Ui_NameColorLevelBand_CopyFloat4_Inferred(
    void* host /*ECX*/, int levelDiff /*EDX*/, float out[4] /*EAX*/);
// bare ret; EAX = out
```

| Item | Evidence |
|---|---|
| Host ECX | `add ecx, imm` offsets |
| levelDiff EDX | `cmp edx, imm` ladder |
| Out EAX | four dword stores; `mov edx,eax` copy loop |
| 16 B | four dwords |
| Leaf | no CALL |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| ≥7 → +0xC54 | Yes |
| ≥5 → +0xC44 | Yes |
| ≥3 → +0xC34 | Yes |
| ≥1 → +0xC24 | Yes |
| ≤−5 → +0xBE4 | Yes |
| −4..−3 → +0xBF4 | Yes |
| −2..−1 → +0xC04 | Yes |
| 0 → +0xC14 | Yes |
| 4×dword copy | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Level-band table copy role | **High** | parent multiplies floats ×255 for name ARGB |
| Eight band offsets / thresholds | **High** | bytes ≡ decompile |
| ABI ECX/EDX/EAX | **High** | call site @ `009312e2` |
| Out is float RGB(+?) | **High** RGB role / **Probable** 4th component |
| Product English name | **Tentative** | `_Inferred` |
| Host RTTI / table init values | **Open** | need live host |

---

## 6. Gaps / open

1. Product/PDB symbol + host class name.  
2. Actual float RGB values per band (initialized data).  
3. Fourth dword semantics.  
4. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/band map High; product English Inferred; table contents residual.
