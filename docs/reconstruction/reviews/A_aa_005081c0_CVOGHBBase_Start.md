# Review A (reconstruction fidelity): `aa_005081c0` CVOGHBBase_Start

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081c0` |
| **VA** | `0x005081c0` |
| **Body** | `0x005081c0`–`0x005081cf` (16 bytes) |
| **Canonical name** | `CVOGHBBase_Start` |
| **Review date** | `2026-07-29` (byte residual seal; prior 2026-07-23 scaffold) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005081c0_CVOGHBBase_Start.md` |
| **System** | `heartbeat` / timed-actions |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Sibling cross-check: ctor `0x00508200`, Stop `0x005081d0`, TryFire `0x005082c0`, cast-again start `0x00519200`.

---

## 1. Purpose

Arm a heartbeat action that was constructed **dormant**: if `fDormant` (`this+0x21`) is non-zero, clear it and **tail-call** virtual **OnStart** at `vtbl+4`; if already armed, no-op. Does **not** Enqueue, AttachOwner, SetPeriod, or stamp lastFire.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005081c0_CVOGHBBase_Start.md` |
| Annotated | `docs/reconstruction/raw/aa_005081c0_CVOGHBBase_Start.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_Start.cpp` |
| Function record | `docs/reconstruction/functions/aa_005081c0_CVOGHBBase_Start.md` |

---

## 3. Byte seal (`read_memory` @ `0x005081c0`, 16 B)

```
80 79 21 00     cmp  byte ptr [ecx+0x21], 0
74 09           jz   short +0x09          ; already armed → ret
8B 01           mov  eax, [ecx]           ; pVTable
C6 41 21 00     mov  byte ptr [ecx+0x21], 0
FF 60 04        jmp  dword ptr [eax+4]    ; tail-call OnStart (slot 1)
C3              ret
```

| Claim | Confidence | Evidence |
|---|---|---|
| `this` in **ECX**, no stack args | **High** | `cmp/mov` via `ecx`; body ends `ret` (not `ret N`) |
| `fDormant` at **+0x21** (byte) | **High** | `cmp [ecx+0x21]`; ctor stores `1` same offset |
| Gate: only act when dormant ≠ 0 | **High** | `jz` skip path |
| Clear dormant before OnStart | **High** | `mov byte [ecx+0x21], 0` then jmp |
| OnStart = **vtbl+4**, **tail-call** | **High** | `FF 60 04` = `jmp [eax+4]` (not `call`) |
| No Enqueue / period / lastFire in body | **High** | 16-byte leaf; only +0x21 + indirect jmp |
| Idempotent second Start | **High** | second entry hits `jz` → bare `ret` |
| Decompiler “jumptable” warning | **noise** | single vtbl tail-jmp, not multi-branch table |

---

## 4. Lifecycle (siblings, owned only as context)

| Step | VA | Role |
|---|---|---|
| ctor | `0x00508200` | `*(this+0x21)=1` (dormant); lastFire `+0x14` = tick |
| **Start** | **`0x005081c0`** | clear dormant + OnStart |
| Stop (sibling) | `0x005081d0` | if not dormant: set +0x21=1; tail `vtbl+0x10` OnEnd |
| TryFire | `0x005082c0` | if period due **and** dormant → Inactive (2); else OnHeartBeat `vtbl+0xc` |

**Start ≠ Enqueue:** e.g. `Skill_StartCastAgainHeartbeat` (`0x00519200`) does `CVOGHBList_Enqueue(...+0xe4ec, pAction)` **then** `CVOGHBBase_Start(pAction)`.

---

## 5. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Dormant gate | **Yes** |
| Clear + OnStart | **Yes** |
| Idempotent early out | **Yes** |
| No list / schedule side effects | **Yes** |

Prior clean plate text claimed “enqueue into map HB list” / “optionally stamp time” — **falsified for this unit** (caller/subclass only). Clean plate corrected 2026-07-29.

---

## 6. Gaps / open

1. Product/PDB English for OnStart slot name (INFERRED OnStart from lifecycle).
2. Full catalog of subclass OnStart side effects (OKToCastAgain stamps cast flag — separate unit).
3. Exhaustive audit of every Start call site for Enqueue pairing (50+ static callers; not owned here).
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept**
