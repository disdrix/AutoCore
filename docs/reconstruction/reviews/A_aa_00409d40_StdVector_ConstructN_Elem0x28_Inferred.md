# Review A (reconstruction fidelity): `aa_00409d40` StdVector_ConstructN_Elem0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409d40` |
| **VA** | `0x00409d40` |
| **Body** | `0x00409d40`–`0x00409da2` (**98 B** / `0x62`) |
| **Canonical name** | `StdVector_ConstructN_Elem0x28_Inferred` |
| **Ghidra name** | `FUN_00409d40` |
| **Prior scaffold** | `FUN_00409d40` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual **WQ9H-B**) |
| **Counterpart** | `reviews/B_aa_00409d40_StdVector_ConstructN_Elem0x28_Inferred.md` |
| **System** | util / container (`std::vector` construct-N, POD **elem 0x28**) |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Construct-N** core for 0x28-byte POD elements:

1. For each of `count` iterations: PodCopy 10 dwords from template `value` into `dest` (`FUN_00409f30`).
2. Advance `dest` by **0x28** each iteration.

Parents: Ufill wrapper `FUN_00406e50` (returns end after this) and push_back fast path `FUN_00406220` (count=1 at end). Twin shape: ConstructN elem **0xC** at `0x00409db0`.

**Not** grow, free, insert-N policy, or domain logic.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **ECX** | `const T*` value (template) |
| stack0 | `T*` dest |
| stack1 | `int` count |
| return | void; plain **`ret`** (`C3`) |

```c
void StdVector_ConstructN_Elem0x28(
    /*ECX*/ const T *value, T *dest, int count);
```

Decompiler drops ECX formal and shows phantom-empty `FUN_00409f30()` — **bytes override**.

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x00409d40` (2026-08-04) ≡ raw scaffold CF spine |
| Bytes | `read_memory` 80+ B — `mov ebx,ecx`; loop `call 00409f30`; **`add esi,0x28`**; **`C3`** |
| Bounds | `get_function_by_address` body `00409d40`–`00409da2` |
| Callee | `FUN_00409f30` — 10 dword copy; EAX=dst EDX=src |
| Callers | `FUN_00406e50` @ `00406e5c`; `FUN_00406220` @ `00406271` |
| Raw / annotated / clean | `aa_00409d40_*`, `StdVector_ConstructN_Elem0x28_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live (+ bytes)

```c
// SEH install
for (; count != 0; --count) {
  FUN_00409f30(dest /*EAX*/, value /*EDX*/); // 10 dwords
  dest = (T*)((char*)dest + 0x28);
}
// SEH restore; ret
```

| Stage | Match |
|---|---|
| Count loop calling PodCopy | **Yes** (raw + live + bytes) |
| dest += 0x28 | **Yes** (bytes only — decomp omits) |
| ECX = value | **Yes** (`mov ebx,ecx`) |
| SEH frame | **Yes** |
| No grow / free | **Yes** |
| Plain ret | **Yes** (`C3`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Construct-N loop role | **Confirmed** | raw ≡ live ≡ bytes |
| Stride **0x28** / 10 dwords | **Confirmed** | `add esi,0x28` + callee loop 10 |
| ECX value + stack dest/count | **Confirmed** | entry bytes + parents |
| Body **98 B** / plain ret | **Confirmed** | bounds + `C3` |
| Used by Ufill + push_back fast | **Confirmed** | 2 xrefs |
| Product name | **Open** | `_Inferred` |

---

## 6. Gaps / open

1. Product English for 0x28-byte `T`.
2. Full dual of PodCopy `00409f30` (CF sealed).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
