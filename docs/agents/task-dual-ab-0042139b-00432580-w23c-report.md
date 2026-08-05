# Dual A/B report — W23-C OWN-ONLY (`aa_0042139b`, `aa_00432580`)

**Date:** 2026-07-29  
**Agent:** W23-C OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0042139b`, `0x00432580`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ analyze/xrefs). No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0042139b` OleDb_BuildBindingsAllocRow_Inferred | **accept-with-gaps** — null +0x10 → E_OUTOFMEMORY; DBTYPE binding loop (stride 0x34 / col 0x30); row alloc; **jmp** into `FUN_00421677`; ret 4 sealed |
| `aa_00432580` NDAssetImage_TransferFields_Inferred | **accept-with-gaps** — dest pre-clear; 10 / 0x5F dword moves; scalar ownership; zero src; ret 4; AL 0/1 sealed |

---

## Sealed facts — `0x0042139b`

1. **Body:** `0x0042139b`–`0x0042166d` (**722 B** Ghidra span). Ghidra SEH-split worker fragment of OLE DB accessor setup.

2. **ABI:** Shared parent EBP frame with `FUN_00421362` + `FUN_00421677`. Pre-entry `0x00421390`: `mov ebx,[ebp+8]`. Fail paths **`ret 4`**. Success **`jmp 0x00421674`** into finalize (not a portable call+ret). Return **HRESULT** in EAX.

3. **Null path:** `ctx+0x10 == 0` → free temps, SEH=`-1`, COM Release `[ebp-0x18]`, **`mov eax,0x8007000E`** (**E_OUTOFMEMORY**).

4. **Binding loop:** count `ctx+0x0C`; DBTYPE@col+0x14 switch → size; oversize/0xd → wType `0x4082`, cb=4; else cb=`size*2+2`, wType `0x82`. Binding cursor step **0x34**; column-side step **0x30**. Align via `FUN_00422900`.

5. **Gate:** if `*ctx==0` call `FUN_00422880`; fail cleanup+return hr; success sets flag byte at `*ctx+4`.

6. **Alloc:** `operator_new[]([ebp-0x24])` → `ctx+0x08`; SEH level 6; continue into `OleDb_RowBufZeroAndCreateAccessor_Inferred`.

7. **Callers:** `FUN_00421362` only.

8. **Name:** `OleDb_BuildBindingsAllocRow_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_0042139b`.

---

## Sealed facts — `0x00432580`

1. **Body:** `0x00432580`–`0x00432625` (**165 B**).

2. **ABI:** **stdcall** dest* on stack; **EBX** = src*; epilogue **`ret 4`**. Return **0** (pre-clear fail) or **1** (success) in AL.

3. **Pre-clear:** ESI=dest; `FUN_004321b0()`; if AL==0 return 0.

4. **Transfer:** `rep movsd` **10** dwords `src+8→dest+8`; **0x5F** dwords `src+0x30→dest+0x30`; scalars `+4`, `+0x1ac`, `+0x1b0`, `+0x1b4`.

5. **Zero src:** same blocks so temp dtor does not double-free (move/steal, not deep-copy).

6. **Callers:** `FUN_00432cb0`, `FUN_0098acc0`, `FUN_0098ae80` (4 xrefs). Used on decode success and flip paths.

7. **Name:** `NDAssetImage_TransferFields_Inferred` — role-sealed **INFERRED** (matches sibling annotations). Ghidra: `FUN_00432580`.

---

## Gaps

### `0042139b`
1. Product C++ type for ctx / exact DBBINDING member English.  
2. Possible Ghidra merge with `FUN_00421362` + `FUN_00421677` — out of sole ownership for merge.  
3. `FUN_00422880` / `FUN_00422900` product meaning — not OWN.  
4. Runtime HRESULT / bit-exact — open.  
5. Post-`FUN_00422880` `*ctx` non-null assumption residual.

### `00432580`
1. Product English for 40 B / 380 B field blocks.  
2. Full `FUN_004321b0` gate (`+0x38`) — not OWN.  
3. Object size / fields beyond +0x1b4.  
4. Runtime transfer differential — open.

---

## Files

### `aa_0042139b`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0042139b_OleDb_BuildBindingsAllocRow_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0042139b_OleDb_BuildBindingsAllocRow_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0042139b_OleDb_BuildBindingsAllocRow_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0042139b_FUN_0042139b.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OleDb_BuildBindingsAllocRow_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0042139b.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_0042139b_FUN_0042139b.md` |
| Annotated | `docs/reconstruction/raw/aa_0042139b_FUN_0042139b.annotated.md` |

### `aa_00432580`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00432580_NDAssetImage_TransferFields_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00432580_NDAssetImage_TransferFields_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00432580_NDAssetImage_TransferFields_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00432580_FUN_00432580.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_TransferFields_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00432580.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00432580_FUN_00432580.md` |
| Annotated | `docs/reconstruction/raw/aa_00432580_FUN_00432580.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0042139b-00432580-w23c-report.md` |

---

## AutoCore impact

### `0042139b`
- Client/tools OLE DB only: after parent allocates aux/status + temp bindings, map DBTYPEs, build bindings (0x34 stride), alloc row buffer, finalize CreateAccessor in sibling fragment.
- Treat null `ctx+0x10` as **E_OUTOFMEMORY** (`0x8007000E`).
- Do not invent a second portable `ret` after finalize — image **jmps** into `FUN_00421677`.
- Server AutoCore typically **omits** this path unless hosting client-parity DB tooling.

### `00432580`
- Port as **move** of NDAssetImage owned fields: pre-clear dest, copy blocks, **zero src**.
- Keep distinct from deep-copy; vtbl at +0 is not transferred.
- Used after decode and after flip temp processing — preserve call-site EBX=src contract.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ analyze/xrefs). No `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
