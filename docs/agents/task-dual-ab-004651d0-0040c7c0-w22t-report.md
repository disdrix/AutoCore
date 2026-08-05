# Dual A/B report — W22-T OWN-ONLY (`aa_004651d0`, `aa_0040c7c0`)

**Date:** 2026-07-29  
**Agent:** W22-T OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004651d0`, `0x0040c7c0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004651d0` Mem_FillDwordN_ReturnEnd | **accept** — **33 B** leaf fill-N (EDI/ESI/EDX) return end; bare `ret` sealed |
| `aa_0040c7c0` Mem_MoveDwordRange_ReturnEnd_EcxEax | **accept** — **35 B** memmove range + return end; ECX/EAX/stack `ret 4` sealed |

---

## Sealed facts — `0x004651d0`

1. **ABI:** custom registers — **EDI = dest**, **ESI = count**, **EDX = value\***; **no stack formals**; bare **`ret`** (`c3` @ `0x004651f0`). Body **`0x004651d0`–`0x004651f0`** (**33 bytes**).

2. **Algorithm:** for count iterations: `*dest_cursor = *value` (re-read `[edx]` each iter); advance cursor +4. Return **`lea eax,[edi+esi*4]`** (write end).

3. **Leaf:** no callees. Early-out when ESI==0 still returns dest end (= dest).

4. **Not** a range move — pure fill. Distinct from `StdFill_DwordRange` (`0x005739b0`, cdecl first/last/value, void).

5. **Callers (3 parents, 6 sites):** `FUN_00456960`, `FUN_00429970`, `FUN_00419880` — dword vector insert-N family (realloc fill + in-place fill).

6. **Name:** `Mem_FillDwordN_ReturnEnd` — role-sealed **INFERRED**. Ghidra: `FUN_004651d0`.

---

## Sealed facts — `0x0040c7c0`

1. **ABI:** custom — **ECX = srcBegin**, **EAX = srcEnd**, **stack dest**; epilogue **`ret 4`** (`c2 04 00` @ `0x0040c7e0`). Body **`0x0040c7c0`–`0x0040c7e2`** (**35 bytes**).

2. **Algorithm:** `size = ((srcEnd-srcBegin)>>2)*4`; `memmove(dest, srcBegin, size)`; return **dest+size**.

3. **Callee:** `memmove` via IAT `0x009c652c` (slot dword `0x006ea9d0`).

4. **Not** object thiscall — decompiler `__thiscall` is residual (ECX first pointer). Algorithm twin of **`Mem_MoveDwordRange_ReturnEnd`** (`0x004e2e80`, stdcall three args, `ret 0xC`).

5. **Callers:** `FUN_00456960` (×2), `FUN_00419880` (×4), `FUN_0043a090` (×2), `FUN_0043a1d0` (×2).

6. **Name:** `Mem_MoveDwordRange_ReturnEnd_EcxEax` — role-sealed **INFERRED**. Ghidra: `FUN_0040c7c0`. Prior scaffold (2026-07-23) raw body preserved; W22-T re-verify **appended**.

---

## Gaps

### `004651d0`
1. Product/PDB English (`_Fill_n` / `uninitialized_fill_n` POD).  
2. Full future xref taxonomy beyond three parents.  
3. Runtime / bit-exact / differential — open.  
4. Negative ESI reachability (bytes would loop huge; callers non-negative).

### `0040c7c0`
1. Product/PDB English.  
2. Why dual ABIs vs `004e2e80` (COMDAT residual).  
3. Runtime / bit-exact / differential — open.  
4. Partial-dword span policy at call sites (math floors; typically aligned).

---

## Files

### `aa_004651d0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004651d0_Mem_FillDwordN_ReturnEnd.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004651d0_Mem_FillDwordN_ReturnEnd.md` |
| Function record | `docs/reconstruction/functions/aa_004651d0_Mem_FillDwordN_ReturnEnd.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004651d0_FUN_004651d0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_FillDwordN_ReturnEnd.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004651d0.cpp` |
| Raw (authoritative body + re-verify) | `docs/reconstruction/raw/aa_004651d0_FUN_004651d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004651d0_FUN_004651d0.annotated.md` |
| Scratch | `tmp/a_004651d0.md` |

### `aa_0040c7c0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0040c7c0_Mem_MoveDwordRange_ReturnEnd_EcxEax.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0040c7c0_Mem_MoveDwordRange_ReturnEnd_EcxEax.md` |
| Function record | `docs/reconstruction/functions/aa_0040c7c0_Mem_MoveDwordRange_ReturnEnd_EcxEax.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0040c7c0_FUN_0040c7c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_MoveDwordRange_ReturnEnd_EcxEax.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0040c7c0.cpp` |
| Raw (scaffold body + re-verify append) | `docs/reconstruction/raw/aa_0040c7c0_FUN_0040c7c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040c7c0_FUN_0040c7c0.annotated.md` |
| Scratch | `tmp/a_0040c7c0.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004651d0-0040c7c0-w22t-report.md` |

---

## AutoCore impact

### `004651d0`
- Port as **fill N dwords from `*value`, return end**. Normal C++ args on server; EDI/ESI/EDX only if binary-hooking retail.
- Used under vector insert-N realloc/in-place — do **not** invent domain (mission/UI) logic here.
- Do not replace with byte `memset` for arbitrary fill values.

### `0040c7c0`
- Port as **memmove range + return end** (same math as `aa_004e2e80`). Prefer one shared C++ helper server-side; keep ABI distinction only for hooks.
- Overlap-safe — use memmove, not memcpy, on in-place insert shifts.
- Pair with fill unit on insert-N; keep relocate and fill separate.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ bounds/callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw for `0040c7c0` preserved; re-verify **appended** only.
