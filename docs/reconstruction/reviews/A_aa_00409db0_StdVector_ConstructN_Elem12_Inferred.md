# Review A (reconstruction fidelity): `aa_00409db0` StdVector_ConstructN_Elem12_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409db0` |
| **VA** | `0x00409db0` |
| **Body** | `0x00409db0`–`0x00409e12` (**99 B** / `0x63`) |
| **Canonical name** | `StdVector_ConstructN_Elem12_Inferred` |
| **Ghidra name** | `FUN_00409db0` |
| **Prior scaffold** | `FUN_00409db0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual **WQ9I-A**) |
| **Counterpart** | `reviews/B_aa_00409db0_StdVector_ConstructN_Elem12_Inferred.md` |
| **System** | util / container (`std::vector` construct-N, POD **elem 0xC**) |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Construct-N** core for 12-byte POD elements:

1. For each of `count` iterations: PodCopy 3 dwords from template `value` into `dest` (`FUN_00409f50`).
2. Advance `dest` by **0x0C** each iteration.

Parents: Ufill wrapper `FUN_00406ee0` (returns end after this) and push_back fast path `FUN_004062a0` (count=1 at end). Twin shape: ConstructN elem **0x28** at `0x00409d40` (WQ9H-B sealed).

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
void StdVector_ConstructN_Elem12(
    /*ECX*/ const T *value, T *dest, int count);
```

Decompiler drops ECX formal and shows phantom-empty `FUN_00409f50()` — **bytes override**.

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x00409db0` (2026-08-05) ≡ raw scaffold CF spine |
| Bytes | `read_memory` 120 B — `mov ebx,ecx`; loop `call 00409f50`; **`add esi,0x0C`**; **`C3`** |
| Bounds | `get_function_by_address` body `00409db0`–`00409e12` |
| Callee | `FUN_00409f50` — 3 dword copy; EAX=dst ECX=src |
| Callers | `FUN_00406ee0` @ `00406eec`; `FUN_004062a0` @ `004062ef` |
| Raw / annotated / clean | `aa_00409db0_*`, `StdVector_ConstructN_Elem12_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live (+ bytes)

```c
// SEH install
for (; count != 0; --count) {
  FUN_00409f50(dest /*EAX*/, value /*ECX*/); // 3 dwords
  dest = (T*)((char*)dest + 0x0C);
}
// SEH restore; ret
```

| Stage | Match |
|---|---|
| Count loop calling PodCopy | **Yes** (raw + live + bytes) |
| dest += 0x0C | **Yes** (bytes only — decomp omits) |
| ECX = value | **Yes** (`mov ebx,ecx`) |
| SEH frame | **Yes** |
| No grow / free | **Yes** |
| Plain ret | **Yes** (`C3`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Construct-N loop role | **Confirmed** | raw ≡ live ≡ bytes |
| Stride **0x0C** / 3 dwords | **Confirmed** | `add esi,0x0C` + callee |
| ECX value + stack dest/count | **Confirmed** | entry bytes + parents |
| Body **99 B** / plain ret | **Confirmed** | bounds + `C3` |
| Used by Ufill + push_back fast | **Confirmed** | 2 xrefs |
| Product name | **Open** | `_Inferred` |

---

## 6. Gaps / open

1. Product English for 0x0C-byte `T`.
2. Full dual of PodCopy `00409f50` (CF sealed).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
