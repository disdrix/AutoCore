# Review A (reconstruction fidelity): `aa_005081d0` CVOGHBBase_Stop

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081d0` |
| **VA** | `0x005081d0` |
| **Body** | `0x005081d0`–`0x005081df` (16 bytes) |
| **Canonical name** | `CVOGHBBase_Stop` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005081d0_CVOGHBBase_Stop.md` |
| **System** | `heartbeat` / timed-actions |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Sibling context only: Start `0x005081c0`, ctor `0x00508200`, TryFire `0x005082c0`.

---

## 1. Purpose

Disarm an **armed** heartbeat: if `fDormant` (`this+0x21`) is **zero**, set it to **1** and **tail-call** virtual **OnEnd** at `vtbl+0x10`; if already dormant, no-op. Does **not** Dequeue from `CVOGHBList`, clear owner, touch period/counter, or stamp lastFire.

Inverse of `CVOGHBBase_Start` (`0x005081c0`): Start clears dormant + `vtbl+4` OnStart; Stop sets dormant + `vtbl+0x10` OnEnd.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005081d0_CVOGHBBase_Stop.md` |
| Annotated | `docs/reconstruction/raw/aa_005081d0_CVOGHBBase_Stop.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_Stop.cpp` |
| Function record | `docs/reconstruction/functions/aa_005081d0_CVOGHBBase_Stop.md` |

---

## 3. Byte seal (`read_memory` @ `0x005081d0`, 16 B)

```
80 79 21 00     cmp  byte ptr [ecx+0x21], 0
75 09           jnz  short +0x09          ; already dormant → ret
8B 01           mov  eax, [ecx]           ; pVTable
C6 41 21 01     mov  byte ptr [ecx+0x21], 1
FF 60 10        jmp  dword ptr [eax+0x10] ; tail-call OnEnd (slot 4)
C3              ret
```

Hex: `8079210075098b01c6412101ff6010c3`

| Claim | Confidence | Evidence |
|---|---|---|
| `this` in **ECX**, no stack args | **High** | `cmp/mov` via `ecx`; body ends `ret` (not `ret N`) |
| `fDormant` at **+0x21** (byte) | **High** | `cmp [ecx+0x21]`; Start/ctor use same offset |
| Gate: only act when dormant **== 0** (armed) | **High** | `jnz` skip path (inverse of Start's `jz`) |
| Set dormant **before** OnEnd | **High** | `mov byte [ecx+0x21], 1` then jmp |
| OnEnd = **vtbl+0x10**, **tail-call** | **High** | `FF 60 10` = `jmp [eax+0x10]` (not `call`) |
| No Dequeue / period / lastFire in body | **High** | 16-byte leaf; only +0x21 + indirect jmp |
| Idempotent second Stop | **High** | second entry hits `jnz` → bare `ret` |
| Decompiler “jumptable” warning | **noise** | single vtbl tail-jmp, not multi-branch table |
| Symmetric to Start | **High** | Start: `74`/`00`/`FF 60 04`; Stop: `75`/`01`/`FF 60 10` |

---

## 4. Lifecycle (siblings, owned only as context)

| Step | VA | Role |
|---|---|---|
| ctor | `0x00508200` | `*(this+0x21)=1` (dormant) |
| Start | `0x005081c0` | if dormant: clear +0x21; tail `vtbl+4` OnStart |
| **Stop** | **`0x005081d0`** | if not dormant: set +0x21=1; tail `vtbl+0x10` OnEnd |
| TryFire | `0x005082c0` | period due **and** dormant → Inactive (2); else OnHeartBeat |

**Stop ≠ Dequeue:** body has no list ops. Callers may Remove/Dequeue separately (e.g. list tick / skill cancel paths).

---

## 5. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Armed gate (dormant == 0) | **Yes** |
| Set dormant + OnEnd | **Yes** |
| Idempotent early out | **Yes** |
| No list / schedule side effects | **Yes** |

Prior scaffold named `FUN_005081d0` / mis-aliased DriveControlTick callee; product role is base HB **Stop**.

---

## 6. Gaps / open

1. Product/PDB English for OnEnd slot name (INFERRED OnEnd from lifecycle vs Start/OnStart).
2. Full catalog of subclass OnEnd side effects (separate units).
3. Exhaustive audit of every Stop call site for Dequeue pairing (19+ static xrefs; not owned here).
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept**
