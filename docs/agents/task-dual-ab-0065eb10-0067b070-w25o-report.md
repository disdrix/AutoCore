# Dual A/B report — W25-O OWN `aa_0065eb10` + `aa_0067b070`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W25-O  
**Scope:** VAs `0x0065eb10`, `0x0067b070` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` + callers/callees/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0065eb10` Phys_StackDesc_ResetFlag0_Float1000 | **accept** — 19 B leaf; flag0 + float 1000.0f sealed |
| `aa_0067b070` Net_SockaddrIn_InitZero | **accept** — 37 B zero sockaddr; htons(0); family 0 sealed |

---

## VA `0x0065eb10` — sealed facts

1. **Body:** `0x0065eb10`–`0x0065eb22` (19 B; leaf; plain `RET`).
2. **ABI:** **ECX**=desc*; no stack args; plain ret. Bytes leave **EAX=ECX** (`mov eax,ecx`); decompiler shows `void`.
3. **Semantics:** `*desc = 0`; `*(float*)(desc+4) = DAT_00a0f520` (**1000.0f**).
4. **Constant:** `read_memory` @ `0x00a0f520` → `00 00 7a 44` = **1000.0f**.
5. **Callers (2):** `FUN_0064fe40` (wheels stack-desc teardown); `hkDefaultChassis_vtbl_0x18` (optional CCS reset).
6. **Callees:** none.
7. **Name:** `Phys_StackDesc_ResetFlag0_Float1000` (Ghidra `FUN_0065eb10`; **Inferred**).
8. **Context:** Does **not** free heap wheels/chassis; shared DAT also used as torque clamp elsewhere — different role.
9. **Decompile ≡ bytes** for CF.

### Gaps

- Product/PDB symbol (Inferred name only).  
- Exact product typedef for the short descriptor.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0065eb10_Phys_StackDesc_ResetFlag0_Float1000.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0065eb10_Phys_StackDesc_ResetFlag0_Float1000.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0065eb10_FUN_0065eb10.md` |
| Annotated | `docs/reconstruction/raw/aa_0065eb10_FUN_0065eb10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phys_StackDesc_ResetFlag0_Float1000.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0065eb10.cpp` |
| Function | `docs/reconstruction/functions/aa_0065eb10_FUN_0065eb10.md` |
| Function named | `docs/reconstruction/functions/aa_0065eb10_Phys_StackDesc_ResetFlag0_Float1000.md` |
| Scratch | `docs/reconstruction/tmp/a_0065eb10.md` |

---

## VA `0x0067b070` — sealed facts

1. **Body:** `0x0067b070`–`0x0067b094` (37 B; plain `RET`; wrapper around `htons`).
2. **ABI:** **ECX**=16-byte out buffer; plain ret; returns buffer in **EAX**.
3. **Semantics:** Zero 16 B → family **0** → addr **0** → port **`htons(0)`** → return this.
4. **Callee:** `htons` via IAT **`0x009c6830`** (same as `Net_SockaddrIn_Init`).
5. **Callers:** 12 symbols / 13 call sites (net object ctors; getsockname/getpeername prep; login helpers).
6. **Name:** `Net_SockaddrIn_InitZero` (Ghidra `FUN_0067b070`; **Inferred** / structural).
7. **Twins:** `Net_SockaddrIn_Init` @ `0x0067b0a0` (AF_INET + args, `ret 8`); `Net_SockaddrIn_InitInvalid` @ `0x0046e280`.
8. **Supersedes:** auto-alias `Named_CalleeOf_Named_VOGChat_0067b070` (body is pure sockaddr zero-init).
9. **Decompile ≡ bytes** for CF.

### Gaps

- Product/TNL type name (shared residual with Init family).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0067b070_Net_SockaddrIn_InitZero.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0067b070_Net_SockaddrIn_InitZero.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0067b070_FUN_0067b070.md` |
| Annotated | `docs/reconstruction/raw/aa_0067b070_FUN_0067b070.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Net_SockaddrIn_InitZero.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0067b070.cpp` |
| Function | `docs/reconstruction/functions/aa_0067b070_FUN_0067b070.md` |
| Function named | `docs/reconstruction/functions/aa_0067b070_Net_SockaddrIn_InitZero.md` |
| Prior auto-named clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOGChat_0067b070.cpp` (superseded name; CF same) |
| Scratch | `docs/reconstruction/tmp/a_0067b070.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0065eb10` | After constructing Havok wheels/chassis components from stack descriptors, reset desc flag=0 and float@+4=1000.0f. Do not free heap. Do not confuse with calcWheelTorque clamp that only **reads** the same DAT. |
| `0067b070` | Default/empty `sockaddr_in` fill before getsockname/getpeername or field init. **Not** AF_INET Init; plain ret (no stack args). Pair with sealed `Net_SockaddrIn_Init` for real endpoints. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ meta/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- This report: `docs/agents/task-dual-ab-0065eb10-0067b070-w25o-report.md`
