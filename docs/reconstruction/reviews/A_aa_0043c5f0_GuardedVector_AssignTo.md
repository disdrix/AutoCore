# Review A (reconstruction fidelity): `aa_0043c5f0` GuardedVector_AssignTo

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c5f0` |
| **VA** | `0x0043c5f0`–`0x0043c650` |
| **Canonical name** | `GuardedVector_AssignTo` |
| **Prior scaffold** | `FUN_0043c5f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W25-R |
| **Counterpart** | `reviews/B_aa_0043c5f0_GuardedVector_AssignTo.md` |
| **System** | STL / guarded container |
| **Verdict** | **accept-with-gaps** — ABI, CS gate, enter/assign/leave order sealed; nested `FUN_0043c730` + product type name open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Snapshot/assign a guarded container into a caller-provided destination:

1. If `source+0x2c != 0`, `EnterCriticalSection(source+0x14)`.
2. Call `FUN_0043c730` with EAX=source, EDI=dest.
3. If locked, `LeaveCriticalSection(source+0x14)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c5f0_FUN_0043c5f0.md` (+ W25-R live seal) |
| Annotated | `docs/reconstruction/raw/aa_0043c5f0_FUN_0043c5f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_AssignTo.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043c5f0_GuardedVector_AssignTo.md` |
| Live decompile | Ghidra `decompile_function` `0x0043c5f0` — **≡** raw |
| Live bytes | `read_memory` entry + epilogue `C2 04 00` |
| Callers | NDResourceCache + 6 (Ghidra) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| `this` / source | **ECX** (`mov edi,ecx`) |
| dest | stack `[esp+4]` at entry → `[esp+0x1c]` after frame (`mov edi,[esp+0x1c]`) |
| Epilogue | **`RET 4`** (`C2 04 00`) |
| Return | void |

```c
void GuardedVector_AssignTo(
    /* ECX */ GuardedVector* source,
    /* stack */ void* dest);
```

### 3.2 Lock gate — **SEALED**

| Fact | Evidence |
|---|---|
| Flag | `cmp byte [edi+0x2c], 0` |
| CS | `lea esi, [edi+0x14]` → Enter/Leave |
| Order | Enter → assign → Leave |
| SEH | state `-1`→`0` around assign; handler `0x009be0c8` |

### 3.3 Nested work — **SHAPE ONLY**

`FUN_0043c730` not owned. Live decompile of callee shows vector-like assign using `+0x0c`/`+0x10` when dest≠src. Residual for element type and exact grow/copy path.

---

## 4. Gaps

- Product/PDB name for the guarded container class.
- Full dual seal of `FUN_0043c730`.
- Runtime verification.

---

## 5. Verdict rationale

Owned unit is a short, fully observed lock wrapper. Confidence on ABI and CS offsets is **High**. Nested assign remains a gap → **accept-with-gaps**.
