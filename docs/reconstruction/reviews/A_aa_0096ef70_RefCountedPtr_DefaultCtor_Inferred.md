# Review A (reconstruction fidelity): `aa_0096ef70` RefCountedPtr_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096ef70` |
| **VA** | `0x0096ef70`–`0x0096ef78` |
| **Body** | **9 bytes** |
| **Canonical name** | `RefCountedPtr_DefaultCtor_Inferred` |
| **Prior scaffold** | `FUN_0096ef70` |
| **Review date** | `2026-07-29` (W25-N dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0096ef70_RefCountedPtr_DefaultCtor_Inferred.md` |
| **System** | shared util — refcounted handle default ctor |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Trivial **default constructor** for a 4-byte handle:

| Step | Action | Role |
|---|---|---|
| 1 | `*this = 0` | null payload pointer |

Peer dtor `FUN_0096efd0` (context only) releases refcounted payload → confirms handle semantics.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0096ef70` |
| Bytes | `read_memory` 16 B — full body `8BC1 C70000000000 C3` |
| Peer dtor | `decompile_function` @ `0x0096efd0` (role only, not OWN dual) |
| Xrefs | ~62 unconditional calls |
| Sample callers | `CVOGTacArc_ctor`, paint, graphics loaders |
| Raw / clean | `aa_0096ef70_*`, `RefCountedPtr_DefaultCtor_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, dual of dtor.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body only zeros first dword | **Confirmed** | full 9 B read |
| ECX = handle address | **Confirmed** | `mov eax,ecx` |
| Return this in EAX | **Confirmed** | EAX left as this |
| No stack cleanup (`ret`) | **Confirmed** | `C3` |
| Refcounted-handle role | **High** | peer dtor refcount path |
| Product type English | **Inferred** | no RTTI on this helper |
| All 62 sites pure ctor (never re-null mid-life) | **Open** | pattern likely mixed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| mov eax,ecx | Yes |
| *eax = 0 | Yes |
| ret | Yes |

---

## 5. Gaps / open

1. Product/RTTI name of payload type.
2. Full dual of dtor `0096efd0`.
3. Distinction vs `FUN_0096f530` (dword + 3 flag bytes) — different type.
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
