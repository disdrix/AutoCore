# Dual A/B report — `aa_005081d0` CVOGHBBase_Stop

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x005081d0`. Dual A/B + three-rep upgrade. Seal dormant set + OnEnd-only contract.  
**Excluded:** Ledgers; Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005081d0` CVOGHBBase_Stop | **accept** — **16-byte CF + fDormant@+0x21 set + vtbl+0x10 tail OnEnd sealed** |

---

## Sealed facts

1. **ABI:** `void __fastcall CVOGHBBase_Stop(CVOGHBBase *this)` — **ECX = this**, **no stack args**, epilogue **`RET`** (not `RET n`). Body **`0x005081d0`–`0x005081df`**.

2. **`fDormant` is byte `this+0x21`:** gate `cmp [ecx+0x21],0`; set `mov byte [ecx+0x21],1`. Only acts when **armed** (dormant == 0).

3. **Algorithm:** if dormant == 0 → set dormant → **tail-call** `*( *this + 0x10 )` (OnEnd); else bare return. **Idempotent** when already dormant.

4. **OnEnd dispatch:** bytes **`FF 60 10`** = `jmp dword ptr [eax+0x10]` — **tail-call**, not `call`+`ret`. Decompiler “jumptable” warning is **noise**.

5. **Stop ≠ Dequeue / free / period / lastFire:** body has **no** list ops, period writes, or `+0x14` lastFire store.

6. **Inverse of Start (`0x005081c0`):**

| | Start | Stop |
|---|---|---|
| Branch | `74 09` jz (act if dormant) | `75 09` jnz (act if armed) |
| Write +0x21 | `00` | `01` |
| Tail | `FF 60 04` OnStart | `FF 60 10` OnEnd |

7. **Name:** `CVOGHBBase_Stop` — lifecycle inverse of sealed `CVOGHBBase_Start`. OnEnd English for `vtbl+0x10` is **INFERRED**.

---

## Gaps

1. Exhaustive static audit of 19+ Stop call sites for Remove/Dequeue pairing.  
2. Full subclass OnEnd side-effect catalog (separate units).  
3. Product/PDB English confirmation for vtbl slots.  
4. Runtime live confirmation; bit-exact / differential — open.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005081d0_CVOGHBBase_Stop.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005081d0_CVOGHBBase_Stop.md` |
| Function record | `docs/reconstruction/functions/aa_005081d0_CVOGHBBase_Stop.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_Stop.cpp` |
| Raw | `docs/reconstruction/raw/aa_005081d0_CVOGHBBase_Stop.md` |
| Annotated | `docs/reconstruction/raw/aa_005081d0_CVOGHBBase_Stop.annotated.md` |
| This report | `docs/agents/task-dual-ab-005081d0-cvoghbbase-stop-report.md` |
