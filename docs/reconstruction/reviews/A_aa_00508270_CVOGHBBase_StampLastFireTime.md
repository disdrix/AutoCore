# Review A (reconstruction fidelity): `aa_00508270` CVOGHBBase_StampLastFireTime

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508270` |
| **VA** | `0x00508270` |
| **Canonical name** | `CVOGHBBase_StampLastFireTime` |
| **Review date** | `2026-07-29` (residual seal; prior accept 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00508270_CVOGHBBase_StampLastFireTime.md` |
| **System** | `heartbeat` / timed-actions |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** (sealed High) |

---

## 1. Purpose

Manual / shared stamp helper: write **`this+0x14` (`dwLastFireTickMs`) ← `g_dwClientTickMs` (`0x00b041cc`)**.  
Resets the HB elapsed clock to “now”. Used outside TryFire’s success path (e.g. cast-again OnStart, skill invalid-frequency paths) and also appears as a **vtable method** on many HB types. TryFire **inlines** the same store after successful OnHeartBeat (does **not** call this helper).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00508270_CVOGHBBase_StampLastFireTime.md` |
| Annotated | `docs/reconstruction/raw/aa_00508270_CVOGHBBase_StampLastFireTime.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_StampLastFireTime.cpp` |
| Function record | `docs/reconstruction/functions/aa_00508270_CVOGHBBase_StampLastFireTime.md` |

---

## 3. Seal: body bytes (High)

`read_memory` @ `0x00508270` (body `00508270`–`00508278`):

```
00508270  A1 CC41B000    mov  eax, dword [0x00b041cc]   ; g_dwClientTickMs
00508275  89 41 14       mov  dword [ecx+0x14], eax     ; this->dwLastFireTickMs
00508278  C3             ret
; 00508279..  CC padding to next function (GetRemainingSeconds @ 0x00508280)
```

Hex: `a1 cc 41 b0 00 89 41 14 c3`

| Claim | Evidence | Conf |
|---|---|---|
| Body size **9 bytes**; single basic block | `read_memory` + function range | **High** |
| `__fastcall` / `__thiscall`: **ECX = this**; **no stack args**; **void** | `mov [ecx+0x14],…` + bare `ret` | **High** |
| Global source **`0x00b041cc` = `g_dwClientTickMs`** | absolute load; named global | **High** |
| Store target **`this+0x14` only** | single `89 41 14` | **High** |
| **No** period / counter / dormant / owner mutation | no other stores | **High** |
| **No callees** | empty callee set; no CALL | **High** |
| Decompiler ≡ machine | `this->dwLastFireTickMs = g_dwClientTickMs` | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Single store `lastFire ← g_dwClientTickMs` | **High** | Body sealed |
| No other fields touched | **High** | One-liner |
| Code call sites include OKToCastAgain_OnStart (tail) | **High** | `jmp 0x00508270` @ `0x0051e3a6` |
| Code call sites include `FUN_00578b30` ×2 | **High** | unconditional CALL @ `0x00578c96`, `0x00578cd0` |
| Orphan code region `0x005cc54a` / `0x005cc55b` tail-jmps here | **High** (bytes); owner FUN open | jmp rel → `0x00508270` |
| Many DATA (vtable) slots hold this entry | **High** | 28 DATA xrefs |
| TryFire also stamps on fire | **High** (semantic); **not** a call site | TryFire inlines store @ `+0x14` |
| Field name `dwLastFireTickMs` | **High** | family plates + GetRemaining/TryFire consumers |

---

## 5. Control flow: clean ≡ raw ≡ machine

| Stage | Match |
|---|---|
| One store | **Yes** |
| No invented logic | **Yes** |
| No branches | **Yes** |
| No stack cleanup beyond bare `ret` | **Yes** |

---

## 6. Call / xref inventory (this unit)

### Code transfers → `0x00508270`

| Site | Kind | Owner (Ghidra) | Notes |
|---|---|---|---|
| `0x0051e3a6` | tail **JMP** | `CVOGHBOKToCastAgain_OnStart` | always after optional cast-flag set |
| `0x00578c96` | **CALL** | `FUN_00578b30` | skill invalid-frequency path |
| `0x00578cd0` | **CALL** | `FUN_00578b30` | second stamp in same fn |
| `0x005cc54a` | tail **JMP** | **no defined function** | in gap before `FUN_005cc560` |
| `0x005cc55b` | tail **JMP** | **no defined function** | sibling path in same gap |

`get_function_callers` only returns the two named functions (orphan sites lack a containing function).

### DATA (vtable / method-table) — address holds `0x00508270`

`0x009cda14`, `0x009cdab4`, `0x009cdfb4`, `0x009cdfd8`, `0x009d2680`, `0x009d5594`, `0x009d81bc`, `0x009d9580`, `0x009daeec`, `0x009db1ac`, `0x009db570`, `0x009dd2d4`, `0x009dd2f4`, `0x009dd440`, `0x009dde30`, `0x009de7b8`, `0x009df66c`, `0x009e316c`, `0x009e318c`, `0x009e3518`, `0x009e35b8`, `0x009e3b74`, `0x009e3c28`, `0x009e43c4`, `0x009e43e4`, `0x009e5260`, `0x009e52c8`, `0x009e52e8`  
(28 slots; verified sample dwords LE `70 82 50 00`.)

---

## 7. Gaps / open

1. **Owner of orphan tail-jmps** at `0x005cc54a` / `0x005cc55b` (function not defined in Ghidra; between `FUN_005cc460` end and `FUN_005cc560`).
2. **Per-class vtable slot index** for each of the 28 DATA sites (which virtual method is “stamp” / shared helper).
3. Whether stamp **alone** (without `SetPeriodAndCounter` / Start) can force immediate vs delayed TryFire — product of period field + list schedule, not this body.
4. Bit-for-bit / runtime / differential: **deferred**.

**Verdict:** **accept** (sealed High for body; call-site inventory High for named; orphan owner + vtbl slot index open)
