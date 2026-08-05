# Dual A/B report — W22-L OWN-ONLY (`aa_0099a8e0`, `aa_00419e20`)

**Date:** 2026-07-29  
**Agent:** W22-L OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0099a8e0`, `0x00419e20`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0099a8e0` gfxVertexBufferImpl_Allocate | **accept** — prep free + field store + device allocate + plate fail −1 + optional callback + stats; `ret 0x10` sealed |
| `aa_00419e20` Com_BstrHolder_Release | **accept** — ESI-this interlocked release of 0xC BSTR holder; BSTR / array / self free on zero sealed |

---

## Sealed facts — `0x0099a8e0`

1. **ABI:** `__thiscall` on **gfxVertexBufferImpl**; **four** stack args; epilogue **`ret 0x10`** (`c2 10 00`). Body **`0x0099a8e0`–`0x0099a9a4`** (**196 bytes**).

2. **Prep:** `FUN_0099a820` frees prior resources for this (ESI-this).

3. **Fields:** `this+0x18` = arg0 (count); `this+0x1c` = arg3 (callback*); `this+0x34`/`+0x38` = `[arg1+0x10]`/`[arg1+0x14]`.

4. **Device:** `FUN_00986a60(DAT_00d1f634, this, arg2)` with format object in EDX (byte path).

5. **Fail:** zero four fields; `FUN_0044c3c0(0,0)`; `vog_LogMessage` plate  
   `C:\vog\1_code\palantir\palantir\graphics\gfxVertexBufferImpl.cpp` line **0x66**,  
   `"Failed to Allocate Vertex Buffer"`; return **−1**.

6. **Success:** optional `callback->vtbl[0](callback, this)`; if `DAT_00d1f614`≠0 bump  
   `+0x388` (bytes), `+0x338` (vertices), `+0x334` (buffer count).

7. **Callers (2 only):** `GfxVBHolder_ReplaceAndAllocate` @ `0x00414c20`, `gfxVertexBufferImpl_Unserialize` @ `0x0099aa20`.

8. **Name:** `gfxVertexBufferImpl_Allocate` — role-sealed **INFERRED** from plate. Ghidra: `FUN_0099a8e0`.

---

## Sealed facts — `0x00419e20`

1. **ABI:** **ESI-this**; no stack formals; plain **`ret` (`c3`)**. Body **`0x00419e20`–`0x00419e60`** (**64 bytes**).

2. **Layout (0xC):** `+0` BSTR; `+4` secondary* (`operator_delete[]`); `+8` LONG refcount (`InterlockedDecrement`).

3. **Live path:** if dec ≠ 0 → return `*(LONG*)(esi+8)`.

4. **Final path:** if ESI≠0: `SysFreeString(+0)` if set; `operator_delete[](+4)` if set; `operator_delete(self)`; return **0**.  
   Decompiler “does not return” on `operator_delete` is **false** (bytes continue).

5. **Sibling:** create `FUN_00419ca0` (`Com_BstrHolder_CreateFromOleStr_Inferred`) — `operator_new(0xC)`, refcount init 1.

6. **Callers:** `FUN_00419db0` (slot release+null), `FUN_00419ed0`, `FUN_00419f60`, `FUN_007b87c0`…`FUN_007b8de0`.

7. **Name:** `Com_BstrHolder_Release` — role-sealed **INFERRED**. Ghidra: `FUN_00419e20`.

---

## Gaps

### `0099a8e0`
1. Product English for four stack formals / format-desc type.  
2. Device allocate internals (`FUN_00986a60`) — out of owned scope.  
3. Stats/device global identities.  
4. Runtime / bit-exact / differential — open.

### `00419e20`
1. Product C++ class name of holder.  
2. Who writes secondary buffer at `+4`.  
3. Runtime / differential — open.  
4. Full ownership map of `007b*` callers — out of owned scope.

---

## Files

### `aa_0099a8e0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0099a8e0_gfxVertexBufferImpl_Allocate.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0099a8e0_gfxVertexBufferImpl_Allocate.md` |
| Function record | `docs/reconstruction/functions/aa_0099a8e0_gfxVertexBufferImpl_Allocate.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0099a8e0_FUN_0099a8e0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/gfxVertexBufferImpl_Allocate.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0099a8e0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_0099a8e0_FUN_0099a8e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0099a8e0_FUN_0099a8e0.annotated.md` |

### `aa_00419e20`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00419e20_Com_BstrHolder_Release.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00419e20_Com_BstrHolder_Release.md` |
| Function record | `docs/reconstruction/functions/aa_00419e20_Com_BstrHolder_Release.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00419e20_FUN_00419e20.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Com_BstrHolder_Release.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00419e20.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00419e20_FUN_00419e20.md` |
| Annotated | `docs/reconstruction/raw/aa_00419e20_FUN_00419e20.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0099a8e0-00419e20-w22l-report.md` |

---

## AutoCore impact

### `0099a8e0`
- Client graphics only: allocate is **not** construct — parent holder replace owns pool/ctor/refcount.
- Ports must treat return as status (`< 0` fail) and honor plate fail → **−1**.
- Server AutoCore typically **omits** this path unless hosting client-parity mesh tooling.

### `00419e20`
- Port as interlocked BSTR-holder release (ESI-this / explicit holder*), not `IUnknown::Release`.
- Secondary field uses **array delete**.
- Skill/DB COM helpers on client; server skill load usually bypasses this holder family.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ bounds/callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
