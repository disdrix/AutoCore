# Review B (skeptical / adversarial): `aa_009c3de0` atexit_NetClassRep_rpcMsgGuaranteedOrdered

| Field | Value |
|---|---|
| **Stable ID** | `aa_009c3de0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-I) |
| **Counterpart** | `reviews/A_aa_009c3de0_atexit_NetClassRep_rpcMsgGuaranteedOrdered.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only on own VA (+ minimal CRT/dtor context bytes).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Body is a normal `call dtor; ret` with undefined ECX | **Falsified** — `mov ecx, imm; jmp` (tail) |
| 2 | Targets a random / wrong dtor | **Falsified** — rel32 seals `0x005a2470`; dtor free name + vtbl restore matches ClassRep |
| 3 | `this` is heap / dynamic | **Falsified** — imm `0x00b04f40` BSS; same as getClassRep return |
| 4 | This is RPC execute / pack path | **Falsified** — 10-byte thunk; no string ops; atexit xref only |
| 5 | Multiple code callers | **Falsified** — single DATA xref from CRT init push |
| 6 | Storage is not GuaranteedOrdered ClassRep | **Falsified** — CRT name `RPC_TNLConnection_rpcMsgGuaranteedOrdered` + sibling Method1 dual |
| 7 | Needs stack cleanup `ret n` | **Falsified** — atexit void callback; dtor returns to atexit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| mov/jmp thunk shape | **High** | Wrong port of CRT exit |
| ClassRep `this` identity | **High** | Free wrong object / skip free |
| atexit-only role | **High** | Invented RPC side effects |
| No product logic in body | **High** | Over-port |

---

## 3. Cross-check against raw + bytes

```
ECX = &DAT_00b04f40
goto FUN_005a2470   // free(this[8]); restore base vtbl
```

Clean must **not** invent call+ret without this, stack args, or RPC work.

---

## 4. Surviving contract for AutoCore

```c
// Port of atexit thunk (or skip if ClassReps not statically registered)
void atexit_NetClassRep_rpcMsgGuaranteedOrdered(void) {
  NetClassRepInstance_Dtor(&g_rpcMsgGuaranteedOrdered_ClassRep); // 0x00b04f40
}
// Registration: after static ctor, atexit(this).
```

Server AutoCore may not need this CRT path if ClassRep lifecycle differs; identity of storage/name remains useful for RPC class-rep parity.

---

## 5. Verdict

Adversarial pass **confirms** A: thunk bytes, baked this, dtor target, atexit registration, ClassRep identity sealed → **accept**.
