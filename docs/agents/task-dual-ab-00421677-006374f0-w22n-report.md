# Dual A/B report — W22-N OWN-ONLY (`aa_00421677`, `aa_006374f0`)

**Date:** 2026-07-29  
**Agent:** W22-N OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00421677`, `0x006374f0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ bounds/callers/callees). No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00421677` OleDb_RowBufZeroAndCreateAccessor_Inferred | **accept-with-gaps** — null rowBuf → E_OUTOFMEMORY; zero-fill; CreateAccessor (`FUN_00422830`); ret 4 sealed |
| `aa_006374f0` TNL_GroupReactionCall_UnpackData | **accept-with-gaps** — opcode `0x206C` special-message unpack; stride `0x28`; size `count*0x28+1`; cdecl sealed |

---

## Sealed facts — `0x00421677`

1. **Body:** `0x00421677`–`0x00421732` (**187 B**). Ghidra worker fragment of OLE DB binding finalize path.

2. **ABI:** Shared parent EBP frame (`FUN_0042139b` builds bindings). Pre-entry `0x00421674`: `mov ebx,[ebp+8]`. Epilogue **`ret 4`**. Return **HRESULT** in EAX.

3. **Null path:** `ctx+8 == 0` → free temps, SEH=`-1`, COM Release `[ebp-0x18]`, **`mov eax,0x8007000E`** (**E_OUTOFMEMORY**).

4. **Success path:** zero-fill `ctx+8` for size `[ebp-0x24]` (`rep stosd`/`stosb`); call **`FUN_00422830`** (`OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred`); free temp bindings; on `hr < 0` free `ctx+0x10`.

5. **Callers:** `FUN_0042139b` only.

6. **Name:** `OleDb_RowBufZeroAndCreateAccessor_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_00421677`.

---

## Sealed facts — `0x006374f0`

1. **Body:** `0x006374f0`–`0x0063774d` (**605 B**). Large frame + `__chkstk` (`0x2934`).

2. **ABI:** **cdecl** `(out**, inRefBuf*)` → `out**`; epilogue **`add esp,0x2940; ret`**.

3. **Dispatch:** Sole caller `Client_UnpackSpecialMessage` when opcode **`0x206c`** (GroupReactionCall).

4. **Wire:** `count = readBits(8)`; per entry type `readBits(8)`; **type==1** → u16 + float32 (`movss`); **else** → `readInt(19)` + u64 + 2 inlined flags; entry stride **`0x28`**.

5. **Rebuild:** `operator_new(0x18)` + list ctor + vtbl **`PTR_LAB_009d7b00`** + `malloc(count*0x28+1)` + owns=1 + refcount++; release input buffer.

6. **Name:** `TNL_GroupReactionCall_UnpackData` — role-sealed **INFERRED**. Ghidra: `FUN_006374f0`.

---

## Gaps

### `00421677`
1. Product C++ type for ctx / exact CreateAccessor formal English.  
2. Possible Ghidra SEH merge with `FUN_0042139b` — out of owned scope.  
3. Runtime HRESULT / bit-exact — open.  
4. Full register map at CreateAccessor call site inherits `aa_00422830` gaps.

### `006374f0`
1. Product English for type-1 vs reaction entry fields.  
2. Exact stack-image layout vs apply-path `Client_RecvGroupReactionCall`.  
3. Rationale for size `count*0x28+1`.  
4. Runtime pack/unpack differential — open.  
5. Null-new then memcpy retail crash path.

---

## Files

### `aa_00421677`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00421677_OleDb_RowBufZeroAndCreateAccessor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00421677_OleDb_RowBufZeroAndCreateAccessor_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00421677_OleDb_RowBufZeroAndCreateAccessor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00421677_FUN_00421677.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OleDb_RowBufZeroAndCreateAccessor_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00421677.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00421677_FUN_00421677.md` |
| Annotated | `docs/reconstruction/raw/aa_00421677_FUN_00421677.annotated.md` |

### `aa_006374f0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_006374f0_TNL_GroupReactionCall_UnpackData.md` |
| Review B | `docs/reconstruction/reviews/B_aa_006374f0_TNL_GroupReactionCall_UnpackData.md` |
| Function record | `docs/reconstruction/functions/aa_006374f0_TNL_GroupReactionCall_UnpackData.md` |
| Scaffold record | `docs/reconstruction/functions/aa_006374f0_FUN_006374f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TNL_GroupReactionCall_UnpackData.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_006374f0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_006374f0_FUN_006374f0.md` |
| Annotated | `docs/reconstruction/raw/aa_006374f0_FUN_006374f0.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00421677-006374f0-w22n-report.md` |

---

## AutoCore impact

### `00421677`
- Client/tools OLE DB only: after binding build + row buffer alloc, zero buffer and CreateAccessor; treat null alloc as **E_OUTOFMEMORY** (`0x8007000E`).
- Do not invent CreateAccessor here — lives in `FUN_00422830`.
- Server AutoCore typically **omits** this path unless hosting client-parity DB tooling.

### `006374f0`
- Port as special-message unpack for **GroupReactionCall `0x206C`**: u8 count, type-discriminated entries stride `0x28`, ByteBuffer wrap.
- Keep distinct from apply-path `Client_RecvGroupReactionCall` (`0x008092a0`).
- Server pack must match **bit** layout; do not assume `size = count*0x28+1` equals a logical deep-copy length without capture.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ analyze/xrefs). No `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
