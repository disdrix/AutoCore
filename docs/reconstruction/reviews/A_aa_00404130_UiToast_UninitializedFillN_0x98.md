# Review A (reconstruction fidelity): `aa_00404130` UiToast_UninitializedFillN_0x98

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404130` |
| **VA** | `0x00404130` |
| **Body** | `0x00404130`–`0x0040415f` (48 bytes) |
| **Canonical name** | `UiToast_UninitializedFillN_0x98` |
| **Prior scaffold** | `FUN_00404130` |
| **Review date** | `2026-07-29` (W20-G dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00404130_UiToast_UninitializedFillN_0x98.md` |
| **System** | `missions-progression` / shared UI toast vector helpers |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

**Fill-N / uninitialized_fill_n** for UI-toast POD (**0x98**):

1. Call `UiToast_ConstructN_0x98` (`FUN_00404670`) with dest / count / template payload.
2. Return **`dst + count * 0x98`** (end of just-constructed range).

Sole caller: `UiToastVector_InsertN` (`0x00403980`) when constructing N template copies into a hole (realloc or in-place insert). Twin of floater `CombatFloater_UninitializedFillN_0x38` (`0x00402ea0`).

ABI: **`ret 0x0C`** (3 stack args); ECX thiscall formals in decompiler are noise / phantom-push only for a free helper.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00404130` |
| Bytes | `read_memory` 48 B — ConstructN call, lea end = `dst + n*0x98`, `C2 0C 00` |
| Bounds | `get_function_by_address` body `00404130`–`0040415f` |
| Callers | only `FUN_00403980` (`get_function_callers`) |
| Callee dual | `A_aa_00404670_UiToast_ConstructN_0x98` |
| Parent dual | `A_aa_00403980_UiToastVector_InsertN` |
| Raw / clean | `aa_00404130_*`, `UiToast_UninitializedFillN_0x98.cpp` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Calls `FUN_00404670` then returns end | **Confirmed** | raw ≡ live ≡ bytes |
| End = `dst + count * 0x98` | **Confirmed** | decompile + lea/shift chain |
| Stride **0x98** | **Confirmed** | return arithmetic |
| Body **48 bytes** / `ret 0x0C` | **Confirmed** | `read_memory` |
| ConstructN = loop PodCopy 0x26 dwords | **High** | sealed callee dual |
| Phantom extra pushes into ConstructN | **Confirmed** | 5 dwords pushed, `add esp,0x14` |
| Used as insert fill-n | **High** | sole parent insert |
| Product name | **Open** | INFERRED |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
// void *FillN(dst, count, template)
UiToast_ConstructN_0x98(dst, count, template);
return dst + count * 0x98;
```

| Stage | Match |
|---|---|
| Single construct-N call | Yes |
| Return advanced pointer | Yes |
| No grow / no free | Yes |
| ret 0x0C | Yes |

---

## 5. Gaps / open

1. Exact stack formal names at call sites (parent dual owns insert ABI).
2. Product symbol.
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
