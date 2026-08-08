# Review A (reconstruction fidelity): `aa_00409e20` StdVector_ConstructN_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409e20` |
| **VA** | `0x00409e20` |
| **Body** | `0x00409e20`–`0x00409e82` inclusive (**99 B** / `0x63`) |
| **Canonical name** | `StdVector_ConstructN_Elem0x10_Inferred` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_00409e20` (**retired**) |
| **Ghidra** | `FUN_00409e20` |
| **Review date** | `2026-08-05` (MEGA-044 dual seal) |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00409e20_StdVector_ConstructN_Elem0x10_Inferred.md` |
| **System** | util / container (elem **0x10**); partition system interaction-activation via PollBoundActions nested SortTargetList |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `analyze_control_flow` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**ConstructN / uninitialized_fill_n** for **0x10-byte** POD elements from a **single fixed template**:

1. Install MSVC SEH (`LAB_009bc610`).
2. Loop `count` times: PodCopy 4 dwords (`FUN_00409f70`) from template → current dest; dest += `0x10`.
3. Teardown SEH; **`RET` (`C3`)** cdecl.

Parents:

- `FUN_00407000` (wrapper → returns `dest+count*0x10`) used by dualed insert-N `FUN_00408640`.
- `FUN_00930360` SortTargetListByViewAngle capacity-hit path (count=1 push).

Twin CF of ConstructN elem0x28 `00409d40` / elem12 `00409db0`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00409e20` |
| Complete analyze | `analyze_function_complete` (callers/xrefs/callees/vars/completeness) |
| Disassembly | `disassemble_function` full body (36 insns) |
| Call-site context | `get_assembly_context` @ `0040700c`, `009305a5` (+ parent wrapper sites) |
| Bytes | `read_memory` 80 B entry + 32 B teardown/`C3` + SEH `009bc610` |
| CF metrics | `analyze_control_flow` — size 99, CC 3, 1 loop, 1 call |
| Callee peek | `disassemble_function` / decompile `FUN_00409f70` (evidence only) |
| Raw / annotated / clean | `aa_00409e20_*`, `StdVector_ConstructN_Elem0x10_Inferred.cpp` |

**Not performed:** Launcher, runtime Confirmed, parent ledgers, dual of other VAs.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **99 B** / entry–RET bounds | **Confirmed** | CF size + `C3` @ `00409e82` + next fn @ `00409e83` |
| cdecl plain **RET** (caller `ADD ESP,0x10`) | **Confirmed** | both call sites clean 0x10 |
| **ECX** = fixed template; **[EBP+8]** dest; **[EBP+0xc]** count | **Confirmed** | disasm `MOV EBX,ECX` / load stack formals |
| Stride **0x10** | **Confirmed** | `ADD ESI,0x10` + PodCopy 4 dwords |
| Role = ConstructN fill-from-template (not range-copy) | **Confirmed** | source never advanced |
| Callee = PodCopy leaf `00409f70` | **Confirmed** | sole call; null-check dest |
| SEH frame `LAB_009bc610` | **Confirmed** | prologue + `read_memory` handler |
| Callers = `00407000` + `00930360` only | **Confirmed** | 2 UNCONDITIONAL_CALL xrefs |
| Decompile ≡ raw CF | **Confirmed** | loop + SEH + single callee |
| Decompiler signature complete | **Falsified** | hides ECX/dest advance — asm authoritative |
| Product POD English type | **Open** | INFERRED |
| Runtime / bit-exact | **Open** | Terminal false |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
// void ConstructN(const T* value /*ECX*/, T* dest, int count)  // |T|=0x10
// SEH …
for (; count != 0; --count, dest = (T*)((char*)dest + 0x10))
  PodCopy0x10(dest, value);
// SEH teardown; RET
```

| Stage | Match |
|---|---|
| SEH install / state 0 / teardown -1 | Yes |
| count==0 early exit | Yes (`TEST EDI,EDI` / `JBE`) |
| PodCopy via `00409f70` | Yes |
| dest += 0x10 each iter | Yes (asm; decompiler elides) |
| template fixed | Yes |
| no grow / free / return end | Yes (end-pointer is wrapper `00407000`) |
| RET cdecl | Yes |

---

## 5. Gaps / open

1. Product symbol / English type of 0x10 element (SortTargetList packs object* + score; insert-N path is generic triad slot).
2. Dual seal of PodCopy `00409f70` and end-returning wrapper `00407000` residual.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/stride/callers sealed; product demangle + helper duals open. Not reject.
