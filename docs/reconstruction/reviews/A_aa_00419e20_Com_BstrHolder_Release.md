# Review A (reconstruction fidelity): `aa_00419e20` Com_BstrHolder_Release

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419e20` |
| **VA** | `0x00419e20` |
| **Body** | `0x00419e20`–`0x00419e60` (64 bytes) |
| **Canonical name** | `Com_BstrHolder_Release` |
| **Prior scaffold** | `FUN_00419e20` |
| **Review date** | `2026-07-29` (W22-L dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00419e20_Com_BstrHolder_Release.md` |
| **System** | crt-com / MSVC BSTR smart-holder |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

**Interlocked-release** a **12-byte** BSTR holder (create sibling `Com_BstrHolder_CreateFromOleStr_Inferred` @ `0x00419ca0`). On final release: free BSTR, array-delete secondary buffer, delete holder, return 0. On non-final: return remaining refcount.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x00419e20` |
| Bytes | `read_memory` 80 B — body through dual `c3` |
| Bounds | `get_function_by_address` `00419e20`–`00419e60` |
| Callees | IAT InterlockedDecrement / SysFreeString; `operator_delete[]` / `operator_delete` |
| Callers | `00419db0`, `00419ed0`, `00419f60`, `007b87c0`…`007b8de0` |
| Sibling create | dual notes `aa_00419ca0` (size 0xC, +8 refcount=1) |
| Slot helper | `00419db0` bytes: ESI=`*[EDI]`, call, `*EDI=0` |
| Raw / clean | `aa_00419e20_*`, `Com_BstrHolder_Release.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **64 bytes** | **Confirmed** | bounds + hex |
| ESI-this | **Confirmed** | `lea edi,[esi+8]`; caller `00419db0` loads ESI |
| Layout +0 BSTR / +4 arr / +8 ref | **Confirmed** | create + free order |
| Interlocked dec | **Confirmed** | IAT call |
| Array-delete of +4 | **Confirmed** | `operator_delete[]` target |
| `operator_delete` returns | **Confirmed** | bytes after call → xor/ret |
| Product class English name | **Inferred** | holder role sealed |
| Who fills +4 secondary | open | callers out of scope |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Dec +8 | Yes |
| Nonzero → return [+8] | Yes |
| Free BSTR / secondary / self | Yes |
| Return 0 | Yes |
| Decompiler “no return” | **Reject residual** — bytes fix |

---

## 5. Gaps / open

1. Product C++ type name (custom vs `_bstr_t` variant).
2. Secondary-buffer producers (who writes `+4`).
3. Runtime / differential — open.
4. Full COM path ownership of callers `007b*` — out of owned scope.

**Verdict:** **accept**
